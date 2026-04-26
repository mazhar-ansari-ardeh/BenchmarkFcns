#define _USE_MATH_DEFINES
#include <cmath>
#include "multiobjective.h"
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
        const VectorXd g = 100.0 * (k + ((xm.array() - 0.5).square() - (20.0 * M_PI * (xm.array() - 0.5)).cos()).rowwise().sum().array());

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

        MatrixXd xm = x.rightCols(k);
        VectorXd g = (xm.array() - 0.5).square().rowwise().sum();

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

    MatrixXd dtlz3(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x, int num_objectives) {
        const int n = x.cols();
        const int M = num_objectives;
        if (n < M)
            throw std::invalid_argument("The DTLZ3 function requires n >= num_objectives.");

        const int k = n - M + 1;
        const int m = x.rows();
        MatrixXd scores(m, M);

        MatrixXd xm = x.rightCols(k);
        VectorXd g = 100.0 * (k + ((xm.array() - 0.5).square() - (20.0 * M_PI * (xm.array() - 0.5)).cos()).rowwise().sum().array());

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

    MatrixXd dtlz4(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x, int num_objectives, double alpha) {
        const int n = x.cols();
        const int M = num_objectives;
        if (n < M)
            throw std::invalid_argument("The DTLZ4 function requires n >= num_objectives.");

        const int k = n - M + 1;
        const int m = x.rows();
        MatrixXd scores(m, M);

        MatrixXd xm = x.rightCols(k);
        VectorXd g = (xm.array() - 0.5).square().rowwise().sum();

        for (int i = 0; i < M; ++i) {
            VectorXd f_i = 1.0 + g.array();
            for (int j = 0; j < M - (i + 1); ++j) {
                f_i = f_i.array() * (x.col(j).array().pow(alpha) * (M_PI / 2.0)).cos();
            }
            if (i > 0) {
                f_i = f_i.array() * (x.col(M - (i + 1)).array().pow(alpha) * (M_PI / 2.0)).sin();
            }
            scores.col(i) = f_i;
        }

        return scores;
    }

    MatrixXd dtlz5(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x, int num_objectives) {
        const int n = x.cols();
        const int M = num_objectives;
        if (n < M)
            throw std::invalid_argument("The DTLZ5 function requires n >= num_objectives.");

        const int k = n - M + 1;
        const int m = x.rows();
        MatrixXd scores(m, M);

        MatrixXd xm = x.rightCols(k);
        VectorXd g = (xm.array() - 0.5).square().rowwise().sum();

        MatrixXd theta(m, M - 1);
        theta.col(0) = x.col(0) * (M_PI / 2.0);
        for (int j = 1; j < M - 1; ++j) {
            theta.col(j) = (M_PI / (4.0 * (1.0 + g.array()))) * (1.0 + 2.0 * g.array() * x.col(j).array());
        }

        for (int i = 0; i < M; ++i) {
            VectorXd f_i = 1.0 + g.array();
            for (int j = 0; j < M - (i + 1); ++j) {
                f_i = f_i.array() * theta.col(j).array().cos();
            }
            if (i > 0) {
                f_i = f_i.array() * theta.col(M - (i + 1)).array().sin();
            }
            scores.col(i) = f_i;
        }

        return scores;
    }

    MatrixXd dtlz6(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x, int num_objectives) {
        const int n = x.cols();
        const int M = num_objectives;
        if (n < M)
            throw std::invalid_argument("The DTLZ6 function requires n >= num_objectives.");

        const int k = n - M + 1;
        const int m = x.rows();
        MatrixXd scores(m, M);

        MatrixXd xm = x.rightCols(k);
        VectorXd g = xm.array().pow(0.1).rowwise().sum();

        MatrixXd theta(m, M - 1);
        theta.col(0) = x.col(0) * (M_PI / 2.0);
        for (int j = 1; j < M - 1; ++j) {
            theta.col(j) = (M_PI / (4.0 * (1.0 + g.array()))) * (1.0 + 2.0 * g.array() * x.col(j).array());
        }

        for (int i = 0; i < M; ++i) {
            VectorXd f_i = 1.0 + g.array();
            for (int j = 0; j < M - (i + 1); ++j) {
                f_i = f_i.array() * theta.col(j).array().cos();
            }
            if (i > 0) {
                f_i = f_i.array() * theta.col(M - (i + 1)).array().sin();
            }
            scores.col(i) = f_i;
        }

        return scores;
    }

    MatrixXd dtlz7(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x, int num_objectives) {
        const int n = x.cols();
        const int M = num_objectives;
        if (n < M)
            throw std::invalid_argument("The DTLZ7 function requires n >= num_objectives.");

        const int k = n - M + 1;
        const int m = x.rows();
        MatrixXd scores(m, M);

        for (int i = 0; i < M - 1; ++i) {
            scores.col(i) = x.col(i);
        }

        MatrixXd xm = x.rightCols(k);
        VectorXd g = 1.0 + ((9.0 / k) * xm.rowwise().sum()).array();

        VectorXd h = VectorXd::Constant(m, (double)M);
        for (int i = 0; i < M - 1; ++i) {
            h.array() -= (scores.col(i).array() / (1.0 + g.array())) * (1.0 + (3.0 * M_PI * scores.col(i).array()).sin());
        }

        scores.col(M - 1) = (1.0 + g.array()) * h.array();

        return scores;
    }

    MatrixXd fonsecafleming(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        const int m = x.rows();
        MatrixXd scores(m, 2);

        const double inv_sqrt_n = 1.0 / std::sqrt(n);

        const VectorXd sum_sq1 = (x.array() - inv_sqrt_n).square().rowwise().sum();
        const VectorXd sum_sq2 = (x.array() + inv_sqrt_n).square().rowwise().sum();

        scores.col(0) = 1.0 - (-sum_sq1.array()).exp();
        scores.col(1) = 1.0 - (-sum_sq2.array()).exp();

        return scores;
    }

    MatrixXd kursawe(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n < 2)
            throw std::invalid_argument("The Kursawe function requires at least a 2D space.");

        const int m = x.rows();
        MatrixXd scores = MatrixXd::Zero(m, 2);

        for (int i = 0; i < n - 1; ++i) {
            scores.col(0).array() += -10.0 * ((-0.2 * (x.col(i).array().square() + x.col(i + 1).array().square()).sqrt()).exp());
        }

        for (int i = 0; i < n; ++i) {
            scores.col(1).array() += x.col(i).array().abs().pow(0.8) + 5.0 * (x.col(i).array().cube()).sin();
        }

        return scores;
    }

    MatrixXd viennet1(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 2) throw std::invalid_argument("The Viennet 1 function requires exactly a 2D space.");
        const int m = x.rows();
        MatrixXd scores(m, 3);
        const auto x1 = x.col(0).array();
        const auto x2 = x.col(1).array();
        scores.col(0) = x1.square() + (x2 - 1.0).square();
        scores.col(1) = x1.square() + (x2 + 1.0).square() + 1.0;
        scores.col(2) = (x1 - 1.0).square() + x2.square() + 2.0;
        return scores;
    }

    MatrixXd viennet2(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 2) throw std::invalid_argument("The Viennet 2 function requires exactly a 2D space.");
        const int m = x.rows();
        MatrixXd scores(m, 3);
        const auto x1 = x.col(0).array();
        const auto x2 = x.col(1).array();
        scores.col(0) = (x1 - 2.0).square() / 2.0 + (x2 + 1.0).square() / 13.0 + 3.0;
        scores.col(1) = (x1 + x2 - 3.0).square() / 36.0 + (-x1 + x2 + 2.0).square() / 8.0 - 17.0;
        scores.col(2) = (x1 + 2.0*x2 - 1.0).square() / 175.0 + (2.0*x1 - x2).square() / 17.0 - 13.0;
        return scores;
    }

    MatrixXd viennet3(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 2) throw std::invalid_argument("The Viennet 3 function requires exactly a 2D space.");
        const int m = x.rows();
        MatrixXd scores(m, 3);
        const auto x1 = x.col(0).array();
        const auto x2 = x.col(1).array();
        const auto x12_x22 = x1.square() + x2.square();
        scores.col(0) = 0.5 * x12_x22 + x12_x22.sin();
        scores.col(1) = (3.0*x1 - 2.0*x2 + 4.0).square() / 8.0 + (x1 - x2 + 1.0).square() / 27.0 + 15.0;
        scores.col(2) = 1.0 / (x12_x22 + 1.0) - 1.1 * (-x12_x22).exp();
        return scores;
    }

    MatrixXd bnh(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x, bool return_constraints) {
        const int n = x.cols();
        if (n != 2) throw std::invalid_argument("The BNH function requires exactly a 2D space.");
        const int m = x.rows();
        int cols = return_constraints ? 4 : 2;
        MatrixXd scores(m, cols);
        const auto x1 = x.col(0).array();
        const auto x2 = x.col(1).array();
        scores.col(0) = 4.0 * x1.square() + 4.0 * x2.square();
        scores.col(1) = (x1 - 5.0).square() + (x2 - 5.0).square();

        if (return_constraints) {
            scores.col(2) = (x1 - 5.0).square() + x2.square() - 25.0;
            scores.col(3) = 7.7 - (x1 - 8.0).square() - (x2 + 3.0).square();
        }
        return scores;
    }

    MatrixXd osyczkakundu(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x, bool return_constraints) {
        const int n = x.cols();
        if (n != 6) throw std::invalid_argument("The Osyczka and Kundu function requires exactly a 6D space.");
        const int m = x.rows();
        int cols = return_constraints ? 8 : 2;
        MatrixXd scores(m, cols);

        const auto x1 = x.col(0).array();
        const auto x2 = x.col(1).array();
        const auto x3 = x.col(2).array();
        const auto x4 = x.col(3).array();
        const auto x5 = x.col(4).array();
        const auto x6 = x.col(5).array();

        scores.col(0) = -(25.0 * (x1 - 2.0).square() + (x2 - 2.0).square() + (x3 - 1.0).square() + (x4 - 4.0).square() + (x5 - 1.0).square());
        scores.col(1) = x1.square() + x2.square() + x3.square() + x4.square() + x5.square() + x6.square();

        if (return_constraints) {
            scores.col(2) = 2.0 - x1 - x2;
            scores.col(3) = x1 + x2 - 6.0;
            scores.col(4) = x2 - x1 - 2.0;
            scores.col(5) = x1 - 3.0 * x2 - 2.0;
            scores.col(6) = (x3 - 3.0).square() + x4 - 4.0;
            scores.col(7) = 4.0 - (x5 - 3.0).square() - x6;
        }

        return scores;
    }

    MatrixXd tanaka(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x, bool return_constraints) {
        const int n = x.cols();
        if (n != 2) throw std::invalid_argument("The Tanaka function requires exactly a 2D space.");
        const int m = x.rows();
        int cols = return_constraints ? 4 : 2;
        MatrixXd scores(m, cols);

        const auto x1 = x.col(0).array();
        const auto x2 = x.col(1).array();

        scores.col(0) = x.col(0);
        scores.col(1) = x.col(1);

        if (return_constraints) {
            // C1: x1^2 + x2^2 - 1 - 0.1*cos(16*atan2(x1, x2)) >= 0
            // In <= 0 form: 1 + 0.1*cos(16*atan2(x1, x2)) - x1^2 - x2^2 <= 0

            // Vectorized atan2 using binaryExpr for Eigen 3.4 compatibility
            VectorXd theta = x.col(0).binaryExpr(x.col(1), [](double a, double b) {
                return std::atan2(a, b);
            });

            scores.col(2) = 1.0 + 0.1 * (16.0 * theta.array()).cos() - x1.square() - x2.square();

            // C2: (x1 - 0.5)^2 + (x2 - 0.5)^2 <= 0.5
            // In <= 0 form: (x1 - 0.5)^2 + (x2 - 0.5)^2 - 0.5 <= 0
            scores.col(3) = (x1 - 0.5).square() + (x2 - 0.5).square() - 0.5;
        }

        return scores;
    }

    MatrixXd poloni(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 2) throw std::invalid_argument("The Poloni function requires exactly a 2D space.");
        const int m = x.rows();
        MatrixXd scores(m, 2);
        const auto x1 = x.col(0).array();
        const auto x2 = x.col(1).array();
        const double A1 = 0.5 * std::sin(1.0) - 2.0 * std::cos(1.0) + std::sin(2.0) - 1.5 * std::cos(2.0);
        const double A2 = 1.5 * std::sin(1.0) - std::cos(1.0) + 2.0 * std::sin(2.0) - 0.5 * std::cos(2.0);
        const auto B1 = 0.5 * x1.sin() - 2.0 * x1.cos() + x2.sin() - 1.5 * x2.cos();
        const auto B2 = 1.5 * x1.sin() - x1.cos() + 2.0 * x2.sin() - 0.5 * x2.cos();
        scores.col(0) = 1.0 + (A1 - B1).square() + (A2 - B2).square();
        scores.col(1) = (x1 + 3.0).square() + (x2 + 1.0).square();
        return scores;
    }
    }
