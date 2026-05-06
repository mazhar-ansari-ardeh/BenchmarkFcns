#define _USE_MATH_DEFINES
#include <cmath>
#include "multiobjective.h"
#include "utils.h"
#include <stdexcept>

namespace BenchmarkFcns::MultiObjective {
    MatrixXd bnh(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x, bool return_constraints) {
        const int n = x.cols();
        if (n != 2) throw std::invalid_argument("The BNH function requires exactly a 2D space.");

        return apply_parallel(x, [return_constraints](const auto& a) {
            const int rows = a.rows();
            int cols = return_constraints ? 4 : 2;
            MatrixXd res(rows, cols);
            const auto x1 = a.col(0);
            const auto x2 = a.col(1);
            res.col(0) = 4.0 * x1.square() + 4.0 * x2.square();
            res.col(1) = (x1 - 5.0).square() + (x2 - 5.0).square();

            if (return_constraints) {
                res.col(2) = (x1 - 5.0).square() + x2.square() - 25.0;
                res.col(3) = 7.7 - (x1 - 8.0).square() - (x2 + 3.0).square();
            }
            return res;
        });
    }

    MatrixXd dtlz1(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x, int num_objectives) {
        const int n = x.cols();
        const int M = num_objectives;
        if (n < M) throw std::invalid_argument("The DTLZ1 function requires n >= num_objectives.");
        const int k = n - M + 1;

        return apply_parallel(x, [M, k](const auto& a) {
            const int rows = a.rows();
            const MatrixXd xm = a.rightCols(k);
            const VectorXd g = 100.0 * (k + ((xm.array() - 0.5).square() - (20.0 * M_PI * (xm.array() - 0.5)).cos()).rowwise().sum().array());

            MatrixXd res(rows, M);
            for (int i = 0; i < M; ++i) {
                VectorXd f_i = 0.5 * (1.0 + g.array());
                for (int j = 0; j < M - (i + 1); ++j) {
                    f_i = f_i.array() * a.col(j);
                }
                if (i > 0) {
                    f_i = f_i.array() * (1.0 - a.col(M - (i + 1)));
                }
                res.col(i) = f_i;
            }
            return res;
        });
    }

    MatrixXd dtlz2(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x, int num_objectives) {
        const int n = x.cols();
        const int M = num_objectives;
        if (n < M) throw std::invalid_argument("The DTLZ2 function requires n >= num_objectives.");
        const int k = n - M + 1;

        return apply_parallel(x, [M, k](const auto& a) {
            const int rows = a.rows();
            const VectorXd g = (a.rightCols(k) - 0.5).square().rowwise().sum();

            MatrixXd res(rows, M);
            for (int i = 0; i < M; ++i) {
                VectorXd f_i = 1.0 + g.array();
                for (int j = 0; j < M - (i + 1); ++j) {
                    f_i = f_i.array() * (a.col(j) * (M_PI / 2.0)).cos();
                }
                if (i > 0) {
                    f_i = f_i.array() * (a.col(M - (i + 1)) * (M_PI / 2.0)).sin();
                }
                res.col(i) = f_i;
            }
            return res;
        });
    }

    MatrixXd dtlz3(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x, int num_objectives) {
        const int n = x.cols();
        const int M = num_objectives;
        if (n < M) throw std::invalid_argument("The DTLZ3 function requires n >= num_objectives.");
        const int k = n - M + 1;

        return apply_parallel(x, [M, k](const auto& a) {
            const int rows = a.rows();
            const MatrixXd xm = a.rightCols(k);
            const VectorXd g = 100.0 * (k + ((xm.array() - 0.5).square() - (20.0 * M_PI * (xm.array() - 0.5)).cos()).rowwise().sum().array());

            MatrixXd res(rows, M);
            for (int i = 0; i < M; ++i) {
                VectorXd f_i = 1.0 + g.array();
                for (int j = 0; j < M - (i + 1); ++j) {
                    f_i = f_i.array() * (a.col(j) * (M_PI / 2.0)).cos();
                }
                if (i > 0) {
                    f_i = f_i.array() * (a.col(M - (i + 1)) * (M_PI / 2.0)).sin();
                }
                res.col(i) = f_i;
            }
            return res;
        });
    }

    MatrixXd dtlz4(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x, int num_objectives, double alpha) {
        const int n = x.cols();
        const int M = num_objectives;
        if (n < M) throw std::invalid_argument("The DTLZ4 function requires n >= num_objectives.");
        const int k = n - M + 1;

        return apply_parallel(x, [M, k, alpha](const auto& a) {
            const int rows = a.rows();
            const VectorXd g = (a.rightCols(k) - 0.5).square().rowwise().sum();

            MatrixXd res(rows, M);
            for (int i = 0; i < M; ++i) {
                VectorXd f_i = 1.0 + g.array();
                for (int j = 0; j < M - (i + 1); ++j) {
                    f_i = f_i.array() * (a.col(j).pow(alpha) * (M_PI / 2.0)).cos();
                }
                if (i > 0) {
                    f_i = f_i.array() * (a.col(M - (i + 1)).pow(alpha) * (M_PI / 2.0)).sin();
                }
                res.col(i) = f_i;
            }
            return res;
        });
    }

    MatrixXd dtlz5(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x, int num_objectives) {
        const int n = x.cols();
        const int M = num_objectives;
        if (n < M) throw std::invalid_argument("The DTLZ5 function requires n >= num_objectives.");
        const int k = n - M + 1;

        return apply_parallel(x, [M, k](const auto& a) {
            const int rows = a.rows();
            const VectorXd g = (a.rightCols(k) - 0.5).square().rowwise().sum();

            MatrixXd theta(rows, M - 1);
            theta.col(0) = a.col(0) * (M_PI / 2.0);
            for (int j = 1; j < M - 1; ++j) {
                theta.col(j) = (M_PI / (4.0 * (1.0 + g.array()))) * (1.0 + 2.0 * g.array() * a.col(j));
            }

            MatrixXd res(rows, M);
            for (int i = 0; i < M; ++i) {
                VectorXd f_i = 1.0 + g.array();
                for (int j = 0; j < M - (i + 1); ++j) {
                    f_i = f_i.array() * theta.col(j).array().cos();
                }
                if (i > 0) {
                    f_i = f_i.array() * theta.col(M - (i + 1)).array().sin();
                }
                res.col(i) = f_i;
            }
            return res;
        });
    }

    MatrixXd dtlz6(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x, int num_objectives) {
        const int n = x.cols();
        const int M = num_objectives;
        if (n < M) throw std::invalid_argument("The DTLZ6 function requires n >= num_objectives.");
        const int k = n - M + 1;

        return apply_parallel(x, [M, k](const auto& a) {
            const int rows = a.rows();
            const VectorXd g = a.rightCols(k).pow(0.1).rowwise().sum();

            MatrixXd theta(rows, M - 1);
            theta.col(0) = a.col(0) * (M_PI / 2.0);
            for (int j = 1; j < M - 1; ++j) {
                theta.col(j) = (M_PI / (4.0 * (1.0 + g.array()))) * (1.0 + 2.0 * g.array() * a.col(j));
            }

            MatrixXd res(rows, M);
            for (int i = 0; i < M; ++i) {
                VectorXd f_i = 1.0 + g.array();
                for (int j = 0; j < M - (i + 1); ++j) {
                    f_i = f_i.array() * theta.col(j).array().cos();
                }
                if (i > 0) {
                    f_i = f_i.array() * theta.col(M - (i + 1)).array().sin();
                }
                res.col(i) = f_i;
            }
            return res;
        });
    }

    MatrixXd dtlz7(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x, int num_objectives) {
        const int n = x.cols();
        const int M = num_objectives;
        if (n < M) throw std::invalid_argument("The DTLZ7 function requires n >= num_objectives.");
        const int k = n - M + 1;

        return apply_parallel(x, [M, k](const auto& a) {
            const int rows = a.rows();
            MatrixXd res(rows, M);
            for (int i = 0; i < M - 1; ++i) {
                res.col(i) = a.col(i);
            }

            const VectorXd g = 1.0 + ((9.0 / k) * a.rightCols(k).rowwise().sum().array());

            VectorXd h = VectorXd::Constant(rows, (double)M);
            for (int i = 0; i < M - 1; ++i) {
                h.array() -= (res.col(i).array() / (1.0 + g.array())) * (1.0 + (3.0 * M_PI * res.col(i).array()).sin());
            }

            res.col(M - 1) = (1.0 + g.array()) * h.array();
            return res;
        });
    }

    MatrixXd fonsecafleming(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        return apply_parallel(x, [n](const auto& a) {
            const int rows = a.rows();
            const double inv_sqrt_n = 1.0 / std::sqrt(n);
            const VectorXd sum_sq1 = (a - inv_sqrt_n).square().rowwise().sum();
            const VectorXd sum_sq2 = (a + inv_sqrt_n).square().rowwise().sum();

            MatrixXd res(rows, 2);
            res.col(0) = 1.0 - (-sum_sq1.array()).exp();
            res.col(1) = 1.0 - (-sum_sq2.array()).exp();
            return res;
        });
    }

    MatrixXd kursawe(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n < 2) throw std::invalid_argument("The Kursawe function requires at least a 2D space.");

        return apply_parallel(x, [n](const auto& a) {
            const int rows = a.rows();
            MatrixXd res = MatrixXd::Zero(rows, 2);

            for (int i = 0; i < n - 1; ++i) {
                res.col(0).array() += -10.0 * ((-0.2 * (a.col(i).square() + a.col(i + 1).square()).sqrt()).exp());
            }

            for (int i = 0; i < n; ++i) {
                res.col(1).array() += a.col(i).abs().pow(0.8) + 5.0 * (a.col(i).pow(3)).sin();
            }
            return res;
        });
    }

    MatrixXd osyczkakundu(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x, bool return_constraints) {
        const int n = x.cols();
        if (n != 6) throw std::invalid_argument("The Osyczka and Kundu function requires exactly a 6D space.");

        return apply_parallel(x, [return_constraints](const auto& a) {
            const int rows = a.rows();
            int cols = return_constraints ? 8 : 2;
            MatrixXd res(rows, cols);

            const auto x1 = a.col(0);
            const auto x2 = a.col(1);
            const auto x3 = a.col(2);
            const auto x4 = a.col(3);
            const auto x5 = a.col(4);
            const auto x6 = a.col(5);

            res.col(0) = -(25.0 * (x1 - 2.0).square() + (x2 - 2.0).square() + (x3 - 1.0).square() + (x4 - 4.0).square() + (x5 - 1.0).square());
            res.col(1) = x1.square() + x2.square() + x3.square() + x4.square() + x5.square() + x6.square();

            if (return_constraints) {
                res.col(2) = 2.0 - x1 - x2;
                res.col(3) = x1 + x2 - 6.0;
                res.col(4) = x2 - x1 - 2.0;
                res.col(5) = x1 - 3.0 * x2 - 2.0;
                res.col(6) = (x3 - 3.0).square() + x4 - 4.0;
                res.col(7) = 4.0 - (x5 - 3.0).square() - x6;
            }
            return res;
        });
    }

    MatrixXd poloni(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 2) throw std::invalid_argument("The Poloni function requires exactly a 2D space.");

        return apply_parallel(x, [](const auto& a) {
            const int rows = a.rows();
            MatrixXd res(rows, 2);
            const auto x1 = a.col(0);
            const auto x2 = a.col(1);
            const double A1 = 0.5 * std::sin(1.0) - 2.0 * std::cos(1.0) + std::sin(2.0) - 1.5 * std::cos(2.0);
            const double A2 = 1.5 * std::sin(1.0) - std::cos(1.0) + 2.0 * std::sin(2.0) - 0.5 * std::cos(2.0);
            const auto B1 = 0.5 * x1.sin() - 2.0 * x1.cos() + x2.sin() - 1.5 * x2.cos();
            const auto B2 = 1.5 * x1.sin() - x1.cos() + 2.0 * x2.sin() - 0.5 * x2.cos();
            res.col(0) = 1.0 + (A1 - B1).square() + (A2 - B2).square();
            res.col(1) = (x1 + 3.0).square() + (x2 + 1.0).square();
            return res;
        });
    }

    MatrixXd tanaka(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x, bool return_constraints) {
        const int n = x.cols();
        if (n != 2) throw std::invalid_argument("The Tanaka function requires exactly a 2D space.");

        return apply_parallel(x, [return_constraints](const auto& a) {
            const int rows = a.rows();
            int cols = return_constraints ? 4 : 2;
            MatrixXd res(rows, cols);

            const auto x1 = a.col(0);
            const auto x2 = a.col(1);

            res.col(0) = x1;
            res.col(1) = x2;

            if (return_constraints) {
                // Vectorized atan2 using binaryExpr
                VectorXd theta = a.col(0).matrix().binaryExpr(a.col(1).matrix(), [](double v1, double v2) {
                    return std::atan2(v1, v2);
                });

                res.col(2) = 1.0 + 0.1 * (16.0 * theta.array()).cos() - x1.square() - x2.square();
                res.col(3) = (x1 - 0.5).square() + (x2 - 0.5).square() - 0.5;
            }
            return res;
        });
    }

    MatrixXd viennet1(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 2) throw std::invalid_argument("The Viennet 1 function requires exactly a 2D space.");

        return apply_parallel(x, [](const auto& a) {
            const int rows = a.rows();
            MatrixXd res(rows, 3);
            const auto x1 = a.col(0);
            const auto x2 = a.col(1);
            res.col(0) = x1.square() + (x2 - 1.0).square();
            res.col(1) = x1.square() + (x2 + 1.0).square() + 1.0;
            res.col(2) = (x1 - 1.0).square() + x2.square() + 2.0;
            return res;
        });
    }

    MatrixXd viennet2(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 2) throw std::invalid_argument("The Viennet 2 function requires exactly a 2D space.");

        return apply_parallel(x, [](const auto& a) {
            const int rows = a.rows();
            MatrixXd res(rows, 3);
            const auto x1 = a.col(0);
            const auto x2 = a.col(1);
            res.col(0) = (x1 - 2.0).square() / 2.0 + (x2 + 1.0).square() / 13.0 + 3.0;
            res.col(1) = (x1 + x2 - 3.0).square() / 36.0 + (-x1 + x2 + 2.0).square() / 8.0 - 17.0;
            res.col(2) = (x1 + 2.0 * x2 - 1.0).square() / 175.0 + (2.0 * x1 - x2).square() / 17.0 - 13.0;
            return res;
        });
    }

    MatrixXd viennet3(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 2) throw std::invalid_argument("The Viennet 3 function requires exactly a 2D space.");

        return apply_parallel(x, [](const auto& a) {
            const int rows = a.rows();
            MatrixXd res(rows, 3);
            const auto x1 = a.col(0);
            const auto x2 = a.col(1);
            const auto x12_x22 = x1.square() + x2.square();
            res.col(0) = 0.5 * x12_x22 + x12_x22.sin();
            res.col(1) = (3.0 * x1 - 2.0 * x2 + 4.0).square() / 8.0 + (x1 - x2 + 1.0).square() / 27.0 + 15.0;
            res.col(2) = 1.0 / (x12_x22 + 1.0) - 1.1 * (-x12_x22).exp();
            return res;
        });
    }

    MatrixXd zdt1(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n < 2) throw std::invalid_argument("The ZDT1 function requires at least a 2D space.");

        return apply_parallel(x, [n](const auto& a) {
            const int rows = a.rows();
            MatrixXd res(rows, 2);

            res.col(0) = a.col(0);
            const VectorXd g = 1.0 + ((9.0 / (n - 1.0)) * a.rightCols(n - 1).rowwise().sum().array());
            const VectorXd h = 1.0 - (res.col(0).array() / g.array()).sqrt();
            res.col(1) = g.array() * h.array();

            return res;
        });
    }

    MatrixXd zdt2(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n < 2) throw std::invalid_argument("The ZDT2 function requires at least a 2D space.");

        return apply_parallel(x, [n](const auto& a) {
            const int rows = a.rows();
            MatrixXd res(rows, 2);

            res.col(0) = a.col(0);
            const VectorXd g = 1.0 + ((9.0 / (n - 1.0)) * a.rightCols(n - 1).rowwise().sum().array());
            const VectorXd h = 1.0 - (res.col(0).array() / g.array()).square();
            res.col(1) = g.array() * h.array();

            return res;
        });
    }

    MatrixXd zdt3(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n < 2) throw std::invalid_argument("The ZDT3 function requires at least a 2D space.");

        return apply_parallel(x, [n](const auto& a) {
            const int rows = a.rows();
            MatrixXd res(rows, 2);

            res.col(0) = a.col(0);
            const VectorXd g = 1.0 + ((9.0 / (n - 1.0)) * a.rightCols(n - 1).rowwise().sum().array());
            const VectorXd f1_g = res.col(0).array() / g.array();
            const VectorXd h = 1.0 - f1_g.array().sqrt() - f1_g.array() * (10.0 * M_PI * res.col(0).array()).sin();
            res.col(1) = g.array() * h.array();

            return res;
        });
    }

    MatrixXd zdt4(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n < 2) throw std::invalid_argument("The ZDT4 function requires at least a 2D space.");

        return apply_parallel(x, [n](const auto& a) {
            const int rows = a.rows();
            MatrixXd res(rows, 2);

            res.col(0) = a.col(0);
            const auto x_rest = a.rightCols(n - 1);
            const VectorXd g = 1.0 + 10.0 * (n - 1.0) + (x_rest.square() - 10.0 * (4.0 * M_PI * x_rest).cos()).rowwise().sum().array();
            const VectorXd h = 1.0 - (res.col(0).array() / g.array()).sqrt();
            res.col(1) = g.array() * h.array();

            return res;
        });
    }

    MatrixXd zdt6(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n < 2) throw std::invalid_argument("The ZDT6 function requires at least a 2D space.");

        return apply_parallel(x, [n](const auto& a) {
            const int rows = a.rows();
            MatrixXd res(rows, 2);

            const auto x1 = a.col(0);
            res.col(0) = 1.0 - ((-4.0 * x1).exp() * (6.0 * M_PI * x1).sin().pow(6.0));
            const VectorXd g = 1.0 + 9.0 * (a.rightCols(n - 1).rowwise().sum().array() / (n - 1.0)).pow(0.25);
            const VectorXd h = 1.0 - (res.col(0).array() / g.array()).square();
            res.col(1) = g.array() * h.array();

            return res;
        });
    }
}
