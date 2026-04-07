#include "multiobjective.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <stdexcept>

namespace BenchmarkFcns::MultiObjective {
    MatrixXd zdt1(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n < 2)
            throw std::invalid_argument("The ZDT1 function requires at least a 2D space.");

        const int m = x.rows();
        MatrixXd scores(m, 2);

        scores.col(0) = x.col(0);
        const VectorXd g = 1.0 + ((9.0 / (n - 1.0)) * x.rightCols(n - 1).rowwise().sum()).array();
        const VectorXd h = 1.0 - (scores.col(0).array() / g.array()).sqrt();
        scores.col(1) = g.array() * h.array();

        return scores;
    }

    MatrixXd zdt2(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n < 2)
            throw std::invalid_argument("The ZDT2 function requires at least a 2D space.");

        const int m = x.rows();
        MatrixXd scores(m, 2);

        scores.col(0) = x.col(0);
        const VectorXd g = 1.0 + ((9.0 / (n - 1.0)) * x.rightCols(n - 1).rowwise().sum()).array();
        const VectorXd h = 1.0 - (scores.col(0).array() / g.array()).square();
        scores.col(1) = g.array() * h.array();

        return scores;
    }

    MatrixXd zdt3(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n < 2)
            throw std::invalid_argument("The ZDT3 function requires at least a 2D space.");

        const int m = x.rows();
        MatrixXd scores(m, 2);

        scores.col(0) = x.col(0);
        const VectorXd g = 1.0 + ((9.0 / (n - 1.0)) * x.rightCols(n - 1).rowwise().sum()).array();
        const VectorXd f1_g = scores.col(0).array() / g.array();
        const VectorXd h = 1.0 - f1_g.array().sqrt() - f1_g.array() * (10.0 * M_PI * scores.col(0).array()).sin();
        scores.col(1) = g.array() * h.array();

        return scores;
    }

    MatrixXd zdt4(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n < 2)
            throw std::invalid_argument("The ZDT4 function requires at least a 2D space.");

        const int m = x.rows();
        MatrixXd scores(m, 2);

        scores.col(0) = x.col(0);
        const MatrixXd x_rest = x.rightCols(n - 1);
        const VectorXd g = 1.0 + 10.0 * (n - 1.0) + (x_rest.array().square() - 10.0 * (4.0 * M_PI * x_rest.array()).cos()).rowwise().sum().array();
        const VectorXd h = 1.0 - (scores.col(0).array() / g.array()).sqrt();
        scores.col(1) = g.array() * h.array();

        return scores;
    }

    MatrixXd zdt6(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n < 2)
            throw std::invalid_argument("The ZDT6 function requires at least a 2D space.");

        const int m = x.rows();
        MatrixXd scores(m, 2);

        const VectorXd x1 = x.col(0);
        scores.col(0) = 1.0 - ((-4.0 * x1.array()).exp() * (6.0 * M_PI * x1.array()).sin().pow(6.0));
        const VectorXd g = 1.0 + 9.0 * (x.rightCols(n - 1).rowwise().sum().array() / (n - 1.0)).pow(0.25);
        const VectorXd h = 1.0 - (scores.col(0).array() / g.array()).square();
        scores.col(1) = g.array() * h.array();

        return scores;
    }

    MatrixXd dtlz1(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x, int num_objectives) {
        const int n = x.cols();
        const int M = num_objectives;
        if (n < M)
            throw std::invalid_argument("The DTLZ1 function requires n >= num_objectives.");

        const int k = n - M + 1;
        const int m = x.rows();
        MatrixXd scores(m, M);

        const MatrixXd xm = x.rightCols(k);
        const VectorXd g = 100.0 * (k + ((xm.array() - 0.5).square() - (20.0 * M_PI * (xm.array() - 0.5)).cos()).rowwise().sum());

        for (int i = 0; i < M; ++i) {
            VectorXd f_i = 0.5 * (1.0 + g.array());
            for (int j = 0; j < M - (i + 1); ++j) {
                f_i = f_i.array() * x.col(j).array();
            }
            if (i > 0) {
                f_i = f_i.array() * (1.0 - x.col(M - (i + 1)).array());
            }
            scores.col(i) = f_i;
        }

        return scores;
    }

    MatrixXd dtlz2(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x, int num_objectives) {
        const int n = x.cols();
        const int M = num_objectives;
        if (n < M)
            throw std::invalid_argument("The DTLZ2 function requires n >= num_objectives.");

        const int k = n - M + 1;
        const int m = x.rows();
        MatrixXd scores(m, M);

        const MatrixXd xm = x.rightCols(k);
        const VectorXd g = (xm.array() - 0.5).square().rowwise().sum();

        for (int i = 0; i < M; ++i) {
            VectorXd f_i = 1.0 + g.array();
            for (int j = 0; j < M - (i + 1); ++j) {
                f_i = f_i.array() * (x.col(j).array() * (M_PI / 2.0)).cos();
            }
            if (i > 0) {
                f_i = f_i.array() * (x.col(M - (i + 1)).array() * (M_PI / 2.0)).sin();
            }
            scores.col(i) = f_i;
        }

        return scores;
    }
}
