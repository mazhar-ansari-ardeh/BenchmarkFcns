#ifndef MULTIFIDELITY_H
#define MULTIFIDELITY_H

#include <Eigen/Dense>

namespace BenchmarkFcns::MultiFidelity {
    using namespace Eigen;

    MatrixXd booth(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    MatrixXd forrester(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    MatrixXd rosenbrock(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);
}

#endif // MULTIFIDELITY_H
