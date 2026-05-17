import os
import numpy as np
import matplotlib.pyplot as plt
import benchmarkfcns
from benchmarkfcns.plotting import meshgrid
import matplotlib
from tqdm import tqdm

# Style settings to match academic/modern look
matplotlib.rcParams["mathtext.fontset"] = "cm"
matplotlib.rcParams["font.family"] = "STIXGeneral"


def generate_plots():
    output_dir = "assets/plots"
    os.makedirs(output_dir, exist_ok=True)

    all_fcns = benchmarkfcns.__all__

    # Filter out non-functions
    exclude = [
        "__doc__",
        "__version__",
        "Composition",
        "cec",
        "multiobjective",
        "multifidelity",
        "plotting",
    ]
    functions_to_plot = [
        f for f in all_fcns if f not in exclude and not f.startswith("cec2005_")
    ]

    # Known bounds for common functions
    bounds_map = {
        "ackley": (-32, 32),
        "rastrigin": (-5.12, 5.12),
        "rosenbrock": (-5, 5),
        "sphere": (-5.12, 5.12),
        "griewank": (-600, 600),
        "schwefel": (-500, 500),
        "bukinn6": (-15, -5, -3, 3),  # x1, x2 bounds
        "matyas": (-10, 10),
        "himmelblau": (-5, 5),
        "beale": (-4.5, 4.5),
        "booth": (-10, 10),
        "goldsteinprice": (-2, 2),
        "styblinskitank": (-5, 5),
    }

    print(f"Generating plots for {len(functions_to_plot)} functions...")

    for f_name in tqdm(functions_to_plot):
        plot_path = os.path.join(output_dir, f"{f_name}fcn.png")

        # Skip if already exists
        if os.path.exists(plot_path):
            continue

        try:
            f = getattr(benchmarkfcns, f_name)

            # Determine bounds
            b = bounds_map.get(f_name, (-5, 5))
            if len(b) == 2:
                x_min, x_max = b
                y_min, y_max = b
            else:
                x_min, x_max, y_min, y_max = b

            x = np.linspace(x_min, x_max, 100)
            y = np.linspace(y_min, y_max, 100)

            # Evaluate
            X, Y, Z = meshgrid(x, y, f)

            # Create Plot
            fig = plt.figure(figsize=(10, 8))
            ax = fig.add_subplot(111, projection="3d")

            ax.plot_surface(X, Y, Z, cmap="viridis", alpha=0.8, antialiased=True)
            ax.contour(X, Y, Z, zdir="z", offset=np.min(Z), cmap="coolwarm")

            ax.set_title(f"{f_name.capitalize()} Function", fontsize=15)
            ax.set_xlabel("x1")
            ax.set_ylabel("x2")

            plt.savefig(plot_path, dpi=100, bbox_inches="tight")
            plt.close(fig)

        except Exception as e:
            print(f"Failed to plot {f_name}: {e}")


if __name__ == "__main__":
    generate_plots()
