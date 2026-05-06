#include <Eigen/Dense>
#include <chrono>
#include <cmath>
#include <iostream>
#include <omp.h> // Include OpenMP header
#include <vector>

/**
 * Hartmann 3-Dimensional Function
 * @param x: An (M x 3) matrix where each row is a point in 3D space.
 * @return: An (M x 1) vector of scores.
 */
Eigen::VectorXd hartmann3fcn(const Eigen::MatrixXd &x) {
    int M = x.rows();

    // Constants based on the Hartmann 3 definition
    Eigen::Vector4d alpha;
    alpha << 1.0, 1.2, 3.0, 3.2;

    Eigen::Matrix<double, 4, 3> A;
    A << 3.0, 10, 30, 0.1, 10, 35, 3.0, 10, 30, 0.1, 10, 35;

    Eigen::Matrix<double, 4, 3> P;
    P << 0.3689, 0.1170, 0.2673, 0.4699, 0.4387, 0.7470, 0.1091, 0.8732, 0.5547, 0.0381, 0.5743,
        0.8828;

    Eigen::VectorXd scores = Eigen::VectorXd::Zero(M);

    for (int i = 0; i < 4; ++i) {
        // We use .array() to perform element-wise subtraction and squaring
        // This calculates the exponent for all rows (M) simultaneously
        Eigen::ArrayXd exponent = A(i, 0) * (x.col(0).array() - P(i, 0)).square() +
                                  A(i, 1) * (x.col(1).array() - P(i, 1)).square() +
                                  A(i, 2) * (x.col(2).array() - P(i, 2)).square();

        // Update scores: scores = scores - alpha_i * exp(-exponent)
        scores.array() -= alpha(i) * (-exponent).exp();
    }

    return scores;
}

/**
 * Hartmann 3-Dimensional Function (OpenMP Optimized)
 */
Eigen::VectorXd hartmann3fcn_parallel(const Eigen::MatrixXd &x) {
    const int M = x.rows();

    // Constants (Fixed size for efficiency)
    const Eigen::Vector4d alpha(1.0, 1.2, 3.0, 3.2);

    Eigen::Matrix<double, 4, 3> A;
    A << 3.0, 10.0, 30.0, 0.1, 10.0, 35.0, 3.0, 10.0, 30.0, 0.1, 10.0, 35.0;

    Eigen::Matrix<double, 4, 3> P;
    P << 0.3689, 0.1170, 0.2673, 0.4699, 0.4387, 0.7470, 0.1091, 0.8732, 0.5547, 0.0381, 0.5743,
        0.8828;

    Eigen::VectorXd scores(M);

// Parallelize the loop over rows (data points)
#pragma omp parallel for schedule(static)
    for (int j = 0; j < M; ++j) {
        double total_val = 0.0;

        // Loop over the 4 terms of the Hartmann sum
        for (int i = 0; i < 4; ++i) {
            double exponent = 0.0;
            // Explicitly unroll the 3 dimensions for maximum speed
            exponent += A(i, 0) * std::pow(x(j, 0) - P(i, 0), 2);
            exponent += A(i, 1) * std::pow(x(j, 1) - P(i, 1), 2);
            exponent += A(i, 2) * std::pow(x(j, 2) - P(i, 2), 2);

            total_val -= alpha(i) * std::exp(-exponent);
        }
        scores(j) = total_val;
    }

    return scores;
}

// ... (Paste the hartmann3fcn and hartmann3fcn_parallel functions here) ...

int main() {
    const int M = 100000; // 1 Million points
    Eigen::MatrixXd points = Eigen::MatrixXd::Random(M, 3);

    // 1. Benchmark Standard Eigen (Vectorized)
    auto start = std::chrono::high_resolution_clock::now();
    Eigen::VectorXd res1 = hartmann3fcn(points);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff_eigen = end - start;

    // 2. Benchmark OpenMP
    start = std::chrono::high_resolution_clock::now();
    Eigen::VectorXd res2 = hartmann3fcn_parallel(points);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff_omp = end - start;

    std::cout << "M = " << M << " points" << std::endl;
    std::cout << "Eigen Vectorized Time: " << diff_eigen.count() << "s" << std::endl;
    std::cout << "OpenMP Parallel Time:  " << diff_omp.count() << "s" << std::endl;
    std::cout << "Speedup:               " << diff_eigen.count() / diff_omp.count() << "x"
              << std::endl;

    return 0;
}
