#ifndef CEC_H
#define CEC_H

#include <Eigen/Dense>

namespace BenchmarkFcns::CEC {
using namespace Eigen;

/**
 * Evaluates a CEC 2014 benchmark function.
 * @param x Input matrix M-by-D
 * @param fid Function ID (1-30)
 * @return Vector of M results
 */
VectorXd evaluate_2014(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, int fid);

/**
 * Evaluates a CEC 2017 benchmark function.
 * @param x Input matrix M-by-D
 * @param fid Function ID (1-30)
 * @return Vector of M results
 */
VectorXd evaluate_2017(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, int fid);

/**
 * Evaluates a CEC 2019 benchmark function (100-Digit Challenge).
 * @param x Input matrix M-by-D
 * @param fid Function ID (1-10)
 * @return Vector of M results
 */
VectorXd evaluate_2019(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, int fid);

/**
 * Evaluates a CEC 2020 benchmark function.
 * @param x Input matrix M-by-D
 * @param fid Function ID (1-10)
 * @return Vector of M results
 */
VectorXd evaluate_2020(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, int fid);

/**
 * Evaluates a CEC 2022 benchmark function.
 * @param x Input matrix M-by-D
 * @param fid Function ID (1-12)
 * @return Vector of M results
 */
VectorXd evaluate_2022(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, int fid);
} // namespace BenchmarkFcns::CEC

#endif
