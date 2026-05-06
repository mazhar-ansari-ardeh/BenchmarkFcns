#include "multifidelity.h"
#include "benchmarkfcns.h"
#include "utils.h"

namespace BenchmarkFcns::MultiFidelity {

    MatrixXd booth(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        if (x.cols() != 2)
            throw std::invalid_argument("The multi-fidelity Booth function is only defined on a 2D space.");

        return apply_parallel(x, [](const auto& a) {
            const auto X = a.col(0);
            const auto Y = a.col(1);

            MatrixXd res(a.rows(), 2);
            res.col(0) = (X + 2 * Y - 7).square() + (2 * X + Y - 5).square();
            res.col(1) = (0.4 * X + 2 * Y - 7).square() + (2 * 0.4 * X + Y - 5).square() + 1.7 * X * Y - X + 2 * Y;
            return res;
        });
    }

    MatrixXd forrester(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        if (x.cols() != 1)
            throw std::invalid_argument("The multi-fidelity Forrester function is only defined on a 1D space.");

        return apply_parallel(x, [](const auto& a) {
            const auto X = a.col(0);
            const auto f1 = (6 * X - 2).square() * (12 * X - 4).sin();

            MatrixXd res(a.rows(), 4);
            res.col(0) = f1;
            res.col(1) = (5.5 * X - 2.5).square() * (12 * X - 4).sin();
            res.col(2) = (0.75 * f1) + (5 * (X - 0.5)) - 2;
            res.col(3) = (0.5 * f1) + (10 * (X - 0.5)) - 5;
            return res;
        });
    }

    MatrixXd rosenbrock(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        return apply_parallel(x, [n](const auto& a) {
            const int m = a.rows();
            const auto xi = a.block(0, 0, m, n - 1);
            const auto xi_plus_1 = a.block(0, 1, m, n - 1);

            const VectorXd f1 = (100 * (xi_plus_1 - xi.square()).square() + (xi - 1).square()).rowwise().sum();

            const double a2 = -2;
            const double b2 = 50;
            const double d2 = 0.5;

            const VectorXd f2 = (b2 * (xi_plus_1 - xi.square()).square() + (a2 - xi).square()).rowwise().sum() - (d2 * xi).rowwise().sum();

            MatrixXd res(m, 2);
            res.col(0) = f1;
            res.col(1) = f2;
            return res;
        });
    }
}
