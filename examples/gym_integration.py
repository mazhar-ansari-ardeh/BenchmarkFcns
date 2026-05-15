"""
Example: Integrating BenchmarkFcns with Gymnasium (OpenAI Gym).

This example demonstrates how to use benchmark functions as reinforcement learning
environments for training agents.
"""

import gymnasium as gym
import benchmarkfcns.environments
import numpy as np


def run_random_agent(env_id="BenchmarkFcns/Ackley-v0", steps=10):
    print(f"\n--- Running Random Agent on {env_id} ---")

    # Create the environment
    # You can also use: env = benchmarkfcns.environments.make('ackley', dimensions=5)
    env = gym.make(env_id, dimensions=5)

    observation, info = env.reset()
    print(f"Initial State: {observation}")
    print(f"Initial Value: {info['value']}")

    total_reward = 0
    for i in range(steps):
        # Sample a random action (next point)
        action = env.action_space.sample()

        # Take a step
        observation, reward, terminated, truncated, info = env.step(action)

        total_reward += reward
        print(f"Step {i+1}: Value = {info['value']:.4f}, Reward = {reward:.4f}")

        if terminated or truncated:
            break

    print(f"Total Improvement: {total_reward:.4f}")
    env.close()


def run_relative_agent(steps=10):
    print("\n--- Running Local Search Agent (Relative Actions) ---")

    # Create environment with relative actions (displacement dx)
    env = benchmarkfcns.environments.make(
        "rastrigin", dimensions=2, relative_actions=True, step_size=0.5
    )

    observation, info = env.reset()
    print(f"Start Point: {observation}, Value: {info['value']}")

    for i in range(steps):
        # Action is a small delta
        action = np.random.uniform(-0.1, 0.1, size=2)
        observation, reward, terminated, truncated, info = env.step(action)
        print(f"Step {i+1}: Value = {info['value']:.4f}")

    env.close()


if __name__ == "__main__":
    try:
        run_random_agent()
        run_relative_agent()
    except Exception as e:
        print(f"Error: {e}")
        print("\nNote: You may need to install gymnasium: pip install gymnasium")
