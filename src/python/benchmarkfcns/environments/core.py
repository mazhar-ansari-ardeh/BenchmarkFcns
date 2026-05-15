from __future__ import annotations
import numpy as np
import gymnasium as gym
from gymnasium import spaces
from typing import Callable, Any


class BenchmarkEnv(gym.Env):
    """
    A Gymnasium environment wrapper for optimization benchmark functions.

    This environment treats the optimization problem as a reinforcement learning task
    where the agent's goal is to find the global minimum of the function.
    """

    metadata = {"render_modes": ["human"]}

    def __init__(
        self,
        func: Callable[[np.ndarray], np.ndarray],
        low: float | np.ndarray,
        high: float | np.ndarray,
        dimensions: int,
        max_steps: int = 100,
        target_value: float | None = None,
        relative_actions: bool = False,
        step_size: float = 0.1,
    ):
        """
        Initialize the environment.

        Args:
            func: The benchmark function to minimize. Should accept (M, N) array and return (M,) array.
            low: Lower bound of the search space.
            high: Upper bound of the search space.
            dimensions: Dimensionality of the problem.
            max_steps: Maximum number of steps per episode.
            target_value: Optional target value. If reached, the episode terminates.
            relative_actions: If True, actions are interpreted as displacements (dx).
                              If False, actions are interpreted as absolute coordinates (x).
            step_size: Scaling factor for relative actions.
        """
        super().__init__()
        self.func = func
        self.dimensions = dimensions
        self.max_steps = max_steps
        self.target_value = target_value
        self.relative_actions = relative_actions
        self.step_size = step_size

        if isinstance(low, (int, float)):
            self.low = np.full(dimensions, low, dtype=np.float64)
        else:
            self.low = np.array(low, dtype=np.float64)

        if isinstance(high, (int, float)):
            self.high = np.full(dimensions, high, dtype=np.float64)
        else:
            self.high = np.array(high, dtype=np.float64)

        # Observation space is the current point x
        self.observation_space = spaces.Box(
            low=self.low, high=self.high, dtype=np.float64
        )

        if self.relative_actions:
            # Action is a displacement dx within [-step_size, step_size]
            self.action_space = spaces.Box(
                low=-self.step_size,
                high=self.step_size,
                shape=(dimensions,),
                dtype=np.float64,
            )
        else:
            # Action is the next absolute point
            self.action_space = spaces.Box(
                low=self.low, high=self.high, dtype=np.float64
            )

        self.state = None
        self.current_step = 0
        self.last_value = None

    def reset(
        self, seed: int | None = None, options: dict[str, Any] | None = None
    ) -> tuple[np.ndarray, dict[str, Any]]:
        super().reset(seed=seed)

        # Start at a random point
        self.state = self.np_random.uniform(low=self.low, high=self.high).astype(
            np.float64
        )
        self.current_step = 0
        self.last_value = float(self.func(self.state.reshape(1, -1))[0])

        return self.state, {"value": self.last_value}

    def step(
        self, action: np.ndarray
    ) -> tuple[np.ndarray, float, bool, bool, dict[str, Any]]:
        self.current_step += 1

        if self.relative_actions:
            self.state = np.clip(self.state + action, self.low, self.high)
        else:
            self.state = np.clip(action, self.low, self.high)

        current_value = float(self.func(self.state.reshape(1, -1))[0])

        # Reward is the improvement (positive if value decreased)
        reward = self.last_value - current_value
        self.last_value = current_value

        terminated = False
        if self.target_value is not None and current_value <= self.target_value:
            terminated = True

        truncated = self.current_step >= self.max_steps

        return self.state, reward, terminated, truncated, {"value": current_value}

    def render(self):
        # Basic print rendering, could be expanded to 2D plotting
        print(
            f"Step: {self.current_step}, State: {self.state}, Value: {self.last_value}"
        )
