#ifndef UTILS_H
#define UTILS_H

#include <Eigen/Dense>
#include <algorithm>
#include <functional>

namespace BenchmarkFcns {
using namespace Eigen;

/**
 * A high-level utility that applies a mathematical "kernel" to a matrix in parallel.
 * It handles row-splitting, memory allocation, and result merging automatically.
 *
 * @param x The input matrix (M-by-N)
 * @param kernel A lambda that takes an Eigen::ArrayXXd and returns a VectorXd or MatrixXd
 * @return The results of the kernel application
 */
template <typename Derived, typename F>
auto apply_parallel(const MatrixBase<Derived> &x, F &&kernel) {
    using ExpressionType = std::invoke_result_t<F, ArrayXXd>;
    using ReturnType = typename std::decay_t<ExpressionType>::PlainObject;
    const int m = x.rows();
    const int n = x.cols();

    const int chunk_size = 1000;

    // Small workload: run sequentially
    if (m <= chunk_size) {
        return ReturnType(kernel(x.array()));
    }

    // Run once to get the number of columns in the output
    ReturnType first_chunk = kernel(x.block(0, 0, std::min(chunk_size, m), n).array());
    const int out_cols = first_chunk.cols();

    ReturnType scores(m, out_cols);
    scores.block(0, 0, first_chunk.rows(), out_cols) = first_chunk;

#pragma omp parallel for schedule(static)
    for (int i = chunk_size; i < m; i += chunk_size) {
        int actual_chunk = std::min(chunk_size, m - i);
        scores.block(i, 0, actual_chunk, out_cols) = kernel(x.block(i, 0, actual_chunk, n).array());
    }

    return scores;
}

/**
 * Oscillatory Transformation (T_osz) used in CEC benchmark functions.
 * Introduced to break the regularity of the landscape.
 */
inline ArrayXXd t_osz(const ArrayXXd &x) {
    ArrayXXd res = x;
    for (int j = 0; j < x.cols(); ++j) {
        auto col = x.col(j);
        // hat_x = log(|x|) if x != 0, else 0
        auto hat_x = col.abs().log().unaryExpr([](double v) { return std::isinf(v) ? 0.0 : v; });

        // Constants c1, c2 depend on sign
        // We use .select with scalars by providing one scalar as a reference if possible,
        // or just use Constant arrays.
        ArrayXd c1 = (col > 0).select(ArrayXd::Constant(col.rows(), 10.0),
                                      ArrayXd::Constant(col.rows(), 5.5));
        ArrayXd c2 = (col > 0).select(ArrayXd::Constant(col.rows(), 7.9),
                                      ArrayXd::Constant(col.rows(), 3.1));

        res.col(j) = col.sign() * (hat_x + 0.049 * ((c1 * hat_x).sin() + (c2 * hat_x).sin())).exp();
    }
    // Handle zeros explicitly to avoid exp(0) logic issues if any
    return (x == 0.0).select(0.0, res);
}

/**
 * Asymmetric Transformation (T_asy) used in CEC benchmark functions.
 * Applied to unimodal/multimodal functions to break symmetry.
 */
inline ArrayXXd t_asy(const ArrayXXd &x, double beta = 0.2) {
    const int n = x.cols();
    if (n <= 1)
        return x;
    ArrayXXd res = x;
    for (int j = 0; j < n; ++j) {
        auto col = x.col(j);
        auto exponent = 1.0 + beta * ((double)j / (n - 1.0)) * col.abs().sqrt();
        res.col(j) = (col > 0).select(col.pow(exponent), col);
    }
    return res;
}
} // namespace BenchmarkFcns

#endif // UTILS_H
// format trigger
