#include "multifidelity.h"
#include "benchmarkfcns.h"

namespace BenchmarkFcns::MultiFidelity {

    MatrixXd booth(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The multi-fidelity Booth function is only defined on a 2D space.");
        const auto X = x.col(0);
        const auto Y = x.col(1);

        MatrixXd NX(x.rows(), 2);
        NX.col(0) = 0.4 * X;
        NX.col(1) = Y;

        MatrixXd scores(x.rows(), 2);
        scores.col(0) = BenchmarkFcns::booth(x);
        scores.col(1) = BenchmarkFcns::booth(NX).array() + 1.7 * X.array() * Y.array() - X.array() + 2 * Y.array();

        return scores;
    }

    MatrixXd forrester(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int n = x.cols();
        if (n != 1)
            throw std::invalid_argument("The multi-fidelity Forrester function is only defined on a 1D space.");

        auto X = x.col(0).array();
        auto f1 = BenchmarkFcns::forrester(x);
        auto f2 = [&X]() -> VectorXd {return (5.5 * X - 2.5).square() * sin(12 * X - 4);};
        auto f3 = [&X, &f1]() -> VectorXd {return (0.75 * f1.array()) + (5 * (X - 0.5)) - 2;};
        auto f4 = [&X, &f1]() -> VectorXd {return (0.5 * f1.array()) + (10 * (X - 0.5)) - 5;};

        MatrixXd scores(x.rows(), 4);
        scores.col(0) = f1;
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
