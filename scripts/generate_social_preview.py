import os
import numpy as np
import matplotlib.pyplot as plt
import matplotlib
import benchmarkfcns
from benchmarkfcns.plotting import meshgrid

# Style settings
matplotlib.rcParams["mathtext.fontset"] = "cm"
matplotlib.rcParams["font.family"] = "STIXGeneral"


def generate_social_preview():
    # GitHub recommended size: 1280 x 640
    # At 100 DPI, this is 12.8 x 6.4 inches
    fig = plt.figure(figsize=(12.8, 6.4), dpi=100)
    fig.patch.set_facecolor("white")

    # --- Part 1: Function Visualization (Left Side) ---
    # Create a 3D axis on the left
    ax = fig.add_axes([0.05, 0.1, 0.5, 0.8], projection="3d")

    # Use Ackley as the signature function
    f = benchmarkfcns.ackley
    x = np.linspace(-32, 32, 100)
    y = np.linspace(-32, 32, 100)
    X, Y, Z = meshgrid(x, y, f)

    # Plot surface with a nice colormap
    ax.plot_surface(
        X, Y, Z, cmap="viridis", antialiased=True, alpha=0.9, linewidth=0, shade=True
    )

    # Add contour at the bottom
    ax.contour(X, Y, Z, zdir="z", offset=np.min(Z), cmap="coolwarm", alpha=0.5)

    # Clean up the 3D axis
    ax.set_axis_off()
    ax.view_init(elev=20, azim=135)

    # --- Part 2: Branding (Right Side) ---
    # Create a text axis on the right
    text_ax = fig.add_axes([0.55, 0.1, 0.4, 0.8])
    text_ax.set_axis_off()

    # Project Title
    text_ax.text(
        0.0,
        0.7,
        "BenchmarkFcns",
        fontsize=48,
        fontweight="bold",
        color="#24292e",
        fontfamily="sans-serif",
    )

    # Subtitle / Tagline
    text_ax.text(
        0.0,
        0.58,
        "High-Performance Optimization Engine",
        fontsize=18,
        color="#586069",
        style="italic",
    )

    # Feature Bullet Points
    features = [
        "• 310+ Mathematical Benchmarks",
        "• C++ Core / SIMD / OpenMP",
        "• Full CEC 2005-2022 Support",
        "• AI-Ready Gymnasium Wrappers",
        "• SciPy / Nevergrad / PyMOO Ready",
    ]

    for i, feature in enumerate(features):
        text_ax.text(0.0, 0.45 - (i * 0.08), feature, fontsize=16, color="#24292e")

    # URL
    text_ax.text(
        0.0, 0.05, "benchmarkfcns.info", fontsize=16, color="#0366d6", fontweight="bold"
    )

    # Save the output
    output_path = "assets/social-preview.png"
    os.makedirs("assets", exist_ok=True)
    plt.savefig(output_path, bbox_inches="tight", pad_inches=0.5)
    print(f"Social preview generated at: {output_path}")
    plt.close()


if __name__ == "__main__":
    generate_social_preview()
