#include "multifidelity.h"
#include "benchmarkfcns.h"

namespace BenchmarkFcns::MultiFidelity {
    MatrixXd forrester(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int n = x.cols();
        if (n != 1)
            throw std::invalid_argument("The multi-fidelity Forrester function is only defined on a 1D space.");

        auto X = x.col(0).array();
        auto f2 = [&X]() -> VectorXd {return (5.5 * X - 2.5).square() * sin(12 * X - 4);};
        auto f3 = [&X]() -> VectorXd {return (0.75 * ((6 * X - 2).square() * sin(12 * X - 4))) + (5 * (X - 0.5)) - 2;};
        auto f4 = [&X]() -> VectorXd {return (0.5 * ((6 * X - 2).square() * sin(12 * X - 4))) + (10 * (X - 0.5)) - 5;};

        MatrixXd scores(x.rows(), 4);
        scores.col(0) = BenchmarkFcns::forrester(x);
        scores.col(1) = f2();
        scores.col(2) = f3();
        scores.col(3) = f4();

        return scores;
    }

    MatrixXd rosenbrock(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        auto f2 = [&x]() -> VectorXd {
            const double a = -2;
            const double b = 50;
            const double d = 0.5;

            MatrixXd x_2 = x.array().square();
            int ncols = x.cols();
            int nrows = x.rows();

            MatrixXd term1 = b * (x.block(0, 1, nrows, ncols - 1).array() - x_2.block(0, 0, nrows, ncols - 1).array()).square();
            MatrixXd term2 = (a - x.block(0, 0, nrows, ncols - 1).array()).square();
            MatrixXd term3 = d * x.block(0, 0, nrows, ncols-1).array();

            VectorXd scores = (term1 + term2).rowwise().sum() - term3.rowwise().sum();
            return scores;
        };

        MatrixXd scores(x.rows(), 2);
        scores.col(0) = BenchmarkFcns::rosenbrock(x);
        scores.col(1) = f2();

        return scores;
    }
}
