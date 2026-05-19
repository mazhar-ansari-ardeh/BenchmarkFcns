"""
Example: Training a Reinforcement Learning agent to solve BenchmarkFcns.

This script demonstrates how to use the high-performance C++ backend of BenchmarkFcns
as a training environment for Reinforcement Learning agents.

We use Stable Baselines3 (PPO) to find the global minimum of the Ackley function.
"""

import gymnasium as gym

try:
    from stable_baselines3 import PPO
    from stable_baselines3.common.evaluation import evaluate_policy
except ImportError:
    print("This example requires Stable Baselines3.")
    print("Install it with: pip install 'benchmarkfcns[ai]'")
    exit(1)


def main():
    # 1. Create the environment
    # We use a 5-dimensional Ackley function.
    # relative_actions=True: The agent outputs a displacement (dx) instead of absolute coordinates.
    # This turns the optimization into a 'local search' task for the agent.
    env_id = "BenchmarkFcns/Ackley-v0"
    dimensions = 5

    print(f"--- Initializing Environment: {env_id} ({dimensions}D) ---")
    env = gym.make(env_id, dimensions=dimensions, relative_actions=True, max_steps=100)

    # 2. Instantiate the RL Agent
    # PPO (Proximal Policy Optimization) is a state-of-the-art algorithm for continuous control.
    # We use an 'MlpPolicy' (Multi-Layer Perceptron) as the brain.
    model = PPO("MlpPolicy", env, verbose=1, learning_rate=3e-4, seed=42)

    # 3. Train the agent
    # The agent will explore the function landscape and learn to move towards the global minimum.
    total_timesteps = 30000
    print(f"\n--- Training agent for {total_timesteps} steps ---")
    model.learn(total_timesteps=total_timesteps)

    # 4. Evaluate the trained agent
    print("\n--- Evaluating Trained Agent ---")
    mean_reward, std_reward = evaluate_policy(model, env, n_eval_episodes=10)
    print(
        f"Mean Reward (Improvement per Episode): {mean_reward:.4f} +/- {std_reward:.4f}"
    )

    # 5. Run a final demonstration episode
    obs, info = env.reset()
    initial_val = info["value"]
    print("\nDemonstration Run:")
    print(f"  Starting Objective Value: {initial_val:.6f}")

    current_obs = obs
    for step in range(100):
        # The model predicts the best displacement to take
        action, _states = model.predict(current_obs, deterministic=True)
        current_obs, reward, terminated, truncated, info = env.step(action)

        if terminated or truncated:
            break

    final_val = info["value"]
    print(f"  Final Objective Value:    {final_val:.6f}")
    print(f"  Total Improvement:        {initial_val - final_val:.6f}")

    if final_val < 1.0:
        print(
            "\nSuccess! The RL agent successfully converged towards the global minimum."
        )
    else:
        print(
            "\nNote: RL agents may require more training steps for complex high-D landscapes."
        )


if __name__ == "__main__":
    main()
