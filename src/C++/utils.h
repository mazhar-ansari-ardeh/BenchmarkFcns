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
} // namespace BenchmarkFcns

#endif // UTILS_H
// format trigger
