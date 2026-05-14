#define _USE_MATH_DEFINES
#include "multiobjective.h"
#include "utils.h"
#include <cmath>
#include <stdexcept>

namespace BenchmarkFcns::MultiObjective {

namespace {
// --- WFG Transformation Functions ---
double b_poly(double x, double alpha) {
    return std::pow(std::max(0.0, std::min(1.0, x)), alpha);
}

double b_flat(double x, double A, double B, double C) {
    double tmp1 = std::min<double>(0, std::floor(x - B)) * A * (B - x) / B;
    double tmp2 = std::max<double>(0, std::ceil(x - C)) * (1.0 - A) * (x - C) / (1.0 - C);
    return std::max(0.0, std::min(1.0, A + tmp1 + tmp2));
}

double b_param(double x, double y, double A, double B, double C) {
    double v = C + (1.0 - 2.0 * C) * std::floor(0.5 - std::floor(0.5 - y));
    return std::pow(std::max(0.0, std::min(1.0, x)), A + (B - A) * v);
}

double s_linear(double x, double A) {
    return std::max(0.0, std::min(1.0, std::abs(x - A) / std::abs(std::floor(A - x) + A)));
}

double s_deceptive(double x, double A, double B, double C) {
    double tmp1 = std::floor(x - A + B) * (1.0 / (A - B));
    double tmp2 = std::floor(A + B - x) * (1.0 / (1.0 - A - B));
    return std::max(0.0, std::min(1.0, 1.0 + (tmp1 + tmp2) * (std::abs(x - A) - B) / C));
}

double s_multi(double x, double A, double B, double C) {
    double tmp1 =
        (4.0 * A + 2.0) * M_PI * (0.5 - std::abs(x - C) / (2.0 * (std::floor(C - x) + C)));
    double tmp2 = 4.0 * B * std::pow(std::abs(x - C) / (2.0 * (std::floor(C - x) + C)), 2.0);
    return std::max(0.0, std::min(1.0, (1.0 + std::cos(tmp1) + tmp2) / (B + 2.0)));
}

double r_sum(const VectorXd &x, const VectorXd &w) {
    return x.dot(w) / w.sum();
}

double r_nonsep(const VectorXd &x, int A) {
    int n = x.size();
    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        sum += x[i];
        for (int j = 0; j < A - 1; ++j) {
            sum += std::abs(x[i] - x[(i + j + 1) % n]);
        }
    }
    double denom = (double)n / A * (A / 2.0) * (1.0 + 2.0 * A - 2.0 * (A / 2.0));
    return std::max(0.0, std::min(1.0, sum / denom));
}

// --- WFG Shape Functions ---
void wfg_shape_linear(const VectorXd &x, VectorXd &h) {
    int M = h.size();
    for (int m = 0; m < M; ++m) {
        double res = 1.0;
        for (int i = 0; i < M - 1 - m; ++i)
            res *= x(i);
        if (m > 0)
            res *= (1.0 - x(M - 1 - m));
        h(m) = res;
    }
}

void wfg_shape_convex(const VectorXd &x, VectorXd &h) {
    int M = h.size();
    for (int m = 0; m < M; ++m) {
        double res = 1.0;
        for (int i = 0; i < M - 1 - m; ++i)
            res *= (1.0 - std::cos(x(i) * M_PI / 2.0));
        if (m > 0)
            res *= (1.0 - std::sin(x(M - 1 - m) * M_PI / 2.0));
        h(m) = res;
    }
}

void wfg_shape_concave(const VectorXd &x, VectorXd &h) {
    int M = h.size();
    for (int m = 0; m < M; ++m) {
        double res = 1.0;
        for (int i = 0; i < M - 1 - m; ++i)
            res *= std::sin(x(i) * M_PI / 2.0);
        if (m > 0)
            res *= std::cos(x(M - 1 - m) * M_PI / 2.0);
        h(m) = res;
    }
}

void wfg_shape_disconnected(const VectorXd &x, VectorXd &h) {
    wfg_shape_concave(x, h);
    int M = h.size();
    h(M - 1) = 1.0 - x(0) * std::pow(std::cos(5.0 * x(0) * M_PI), 2.0);
}

void wfg_shape_mixed(const VectorXd &x, VectorXd &h, double alpha, double A) {
    wfg_shape_concave(x, h);
    int M = h.size();
    h(M - 1) = std::pow(
        1.0 - x(0) - std::cos(2.0 * A * M_PI * x(0) + M_PI / 2.0) / (2.0 * A * M_PI), alpha);
}
} // namespace

MatrixXd bnh(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x,
             bool return_constraints) {
    const int n = x.cols();
    if (n != 2)
        throw std::invalid_argument("The BNH function requires exactly a 2D space.");

    return apply_parallel(x, [return_constraints](const auto &a) {
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

MatrixXd cf1(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x,
             bool return_constraints) {
    const int n = x.cols();
    return apply_parallel(x, [n, return_constraints](const auto &a) {
        const int rows = a.rows();
        MatrixXd res(rows, return_constraints ? 3 : 2);
        const auto x1 = a.col(0);

        VectorXd s1 = VectorXd::Zero(rows);
        VectorXd s2 = VectorXd::Zero(rows);
        int count1 = 0;
        int count2 = 0;

        for (int j = 2; j <= n; ++j) {
            double exponent = 0.5 * (1.0 + 3.0 * (j - 2.0) / (n - 2.0));
            VectorXd yj = a.col(j - 1).array() - x1.array().pow(exponent);
            if (j % 2 != 0) {
                s1.array() += yj.array().square();
                count1++;
            } else {
                s2.array() += yj.array().square();
                count2++;
            }
        }

        res.col(0) = x1.array() + (2.0 / count1) * s1.array();
        res.col(1) = 1.0 - x1.array() + (2.0 / count2) * s2.array();

        if (return_constraints) {
            const double N = 10.0;
            const double a_param = 1.0;
            res.col(2) =
                1.0 - (res.col(0).array() + res.col(1).array()) +
                a_param * (N * M_PI * (res.col(0).array() - res.col(1).array() + 1.0)).sin().abs();
        }
        return res;
    });
}

MatrixXd cf2(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x,
             bool return_constraints) {
    const int n = x.cols();
    return apply_parallel(x, [n, return_constraints](const auto &a) {
        const int rows = a.rows();
        MatrixXd res(rows, return_constraints ? 3 : 2);
        const auto x1 = a.col(0);

        VectorXd s1 = VectorXd::Zero(rows);
        VectorXd s2 = VectorXd::Zero(rows);
        int count1 = 0;
        int count2 = 0;

        for (int j = 2; j <= n; ++j) {
            if (j % 2 != 0) {
                VectorXd yj =
                    a.col(j - 1).array() - (6.0 * M_PI * x1.array() + (j * M_PI) / n).sin();
                s1.array() += yj.array().square();
                count1++;
            } else {
                VectorXd yj =
                    a.col(j - 1).array() - (6.0 * M_PI * x1.array() + (j * M_PI) / n).cos();
                s2.array() += yj.array().square();
                count2++;
            }
        }

        res.col(0) = x1.array() + (2.0 / count1) * s1.array();
        res.col(1) = 1.0 - x1.array().sqrt() + (2.0 / count2) * s2.array();

        if (return_constraints) {
            const double N = 2.0;
            const double a_param = 1.0;
            VectorXd sqrt_f1 = res.col(0).array().sqrt();
            res.col(2) = 1.0 - res.col(1).array() - sqrt_f1.array() +
                         a_param * (N * M_PI * (sqrt_f1.array() - res.col(1).array() + 1.0)).sin();
        }
        return res;
    });
}

MatrixXd cf3(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x,
             bool return_constraints) {
    const int n = x.cols();
    return apply_parallel(x, [n, return_constraints](const auto &a) {
        const int rows = a.rows();
        MatrixXd res(rows, return_constraints ? 3 : 2);
        const auto x1 = a.col(0);

        VectorXd s1 = VectorXd::Zero(rows);
        VectorXd s2 = VectorXd::Zero(rows);
        VectorXd p1 = VectorXd::Ones(rows);
        VectorXd p2 = VectorXd::Ones(rows);
        int count1 = 0;
        int count2 = 0;

        for (int j = 2; j <= n; ++j) {
            VectorXd yj = a.col(j - 1).array() - (6.0 * M_PI * x1.array() + (j * M_PI) / n).sin();
            if (j % 2 != 0) {
                s1.array() += yj.array().square();
                p1.array() *= (20.0 * M_PI * yj.array() / std::sqrt(j)).cos();
                count1++;
            } else {
                s2.array() += yj.array().square();
                p2.array() *= (20.0 * M_PI * yj.array() / std::sqrt(j)).cos();
                count2++;
            }
        }

        res.col(0) = x1.array() + (2.0 / count1) * (4.0 * s1.array() - 2.0 * p1.array() + 2.0);
        res.col(1) = 1.0 - x1.array().square() +
                     (2.0 / count2) * (4.0 * s2.array() - 2.0 * p2.array() + 2.0);

        if (return_constraints) {
            const double N = 2.0;
            const double a_param = 1.0;
            VectorXd f1_sq = res.col(0).array().square();
            res.col(2) = 1.0 - res.col(1).array() - f1_sq.array() +
                         a_param * (N * M_PI * (f1_sq.array() - res.col(1).array() + 1.0)).sin();
        }
        return res;
    });
}

MatrixXd cf4(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x,
             bool return_constraints) {
    const int n = x.cols();
    return apply_parallel(x, [n, return_constraints](const auto &a) {
        const int rows = a.rows();
        MatrixXd res(rows, return_constraints ? 3 : 2);
        const auto x1 = a.col(0);

        VectorXd s1 = VectorXd::Zero(rows);
        VectorXd s2 = VectorXd::Zero(rows);
        int count1 = 0;
        int count2 = 0;

        for (int j = 2; j <= n; ++j) {
            VectorXd yj = a.col(j - 1).array() - (6.0 * M_PI * x1.array() + (j * M_PI) / n).sin();
            if (j % 2 != 0) {
                s1.array() += yj.array().square();
                count1++;
            } else {
                s2.array() += yj.array().square();
                count2++;
            }
        }

        res.col(0) = x1.array() + (2.0 / count1) * s1.array();
        res.col(1) = 1.0 - x1.array() + (2.0 / count2) * s2.array();

        if (return_constraints) {
            res.col(2) = 0.5 * x1.array() - 0.25 +
                         (6.0 * M_PI * x1.array() + 2.0 * M_PI / n).sin() - a.col(1).array();
        }
        return res;
    });
}

MatrixXd cf5(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x,
             bool return_constraints) {
    const int n = x.cols();
    return apply_parallel(x, [n, return_constraints](const auto &a) {
        const int rows = a.rows();
        MatrixXd res(rows, return_constraints ? 3 : 2);
        const auto x1 = a.col(0);

        VectorXd s1 = VectorXd::Zero(rows);
        VectorXd s2 = VectorXd::Zero(rows);
        int count1 = 0, count2 = 0;

        for (int j = 2; j <= n; ++j) {
            VectorXd yj;
            if (j % 2 != 0) {
                yj = a.col(j - 1).array() -
                     0.8 * x1.array() * (6.0 * M_PI * x1.array() + (j * M_PI) / n).cos();
                s1.array() += yj.array().square();
                count1++;
            } else {
                yj = a.col(j - 1).array() -
                     0.8 * x1.array() * (6.0 * M_PI * x1.array() + (j * M_PI) / n).sin();
                s2.array() += yj.array().square();
                count2++;
            }
        }

        res.col(0) = x1.array() + (2.0 / count1) * s1.array();
        res.col(1) = 1.0 - x1.array() + (2.0 / count2) * s2.array();

        if (return_constraints) {
            res.col(2) = 0.5 * x1.array() - 0.25 +
                         0.8 * x1.array() * (6.0 * M_PI * x1.array() + 2.0 * M_PI / n).sin() -
                         a.col(1).array();
        }
        return res;
    });
}

MatrixXd cf6(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x,
             bool return_constraints) {
    const int n = x.cols();
    return apply_parallel(x, [n, return_constraints](const auto &a) {
        const int rows = a.rows();
        MatrixXd res(rows, return_constraints ? 4 : 2);
        const auto x1 = a.col(0);

        VectorXd s1 = VectorXd::Zero(rows);
        VectorXd s2 = VectorXd::Zero(rows);
        int count1 = 0;
        int count2 = 0;

        for (int j = 2; j <= n; ++j) {
            VectorXd yj;
            if (j % 2 != 0) {
                yj = a.col(j - 1).array() -
                     0.8 * x1.array() * (6.0 * M_PI * x1.array() + (j * M_PI) / n).cos();
                s1.array() += yj.array().square();
                count1++;
            } else {
                yj = a.col(j - 1).array() -
                     0.8 * x1.array() * (6.0 * M_PI * x1.array() + (j * M_PI) / n).sin();
                s2.array() += yj.array().square();
                count2++;
            }
        }

        res.col(0) = x1.array() + (2.0 / count1) * s1.array();
        res.col(1) = (1.0 - x1.array()).square() + (2.0 / count2) * s2.array();

        if (return_constraints) {
            res.col(2) = 0.5 * x1.array() - 0.25 +
                         0.8 * x1.array() * (6.0 * M_PI * x1.array() + 2.0 * M_PI / n).sin() -
                         a.col(1).array();
            res.col(3) = 0.5 * x1.array() - 0.25 +
                         0.8 * x1.array() * (6.0 * M_PI * x1.array() + 4.0 * M_PI / n).sin() -
                         a.col(3).array();
        }
        return res;
    });
}

MatrixXd cf7(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x,
             bool return_constraints) {
    const int n = x.cols();
    return apply_parallel(x, [n, return_constraints](const auto &a) {
        const int rows = a.rows();
        MatrixXd res(rows, return_constraints ? 4 : 2);
        const auto x1 = a.col(0);

        VectorXd s1 = VectorXd::Zero(rows);
        VectorXd s2 = VectorXd::Zero(rows);
        int count1 = 0;
        int count2 = 0;

        for (int j = 2; j <= n; ++j) {
            VectorXd yj;
            if (j % 2 != 0) {
                yj = a.col(j - 1).array() -
                     0.8 * x1.array() * (6.0 * M_PI * x1.array() + (j * M_PI) / n).cos();
                s1.array() += 2.0 * yj.array().square() - (4.0 * M_PI * yj.array()).cos() + 1.0;
                count1++;
            } else {
                yj = a.col(j - 1).array() -
                     0.8 * x1.array() * (6.0 * M_PI * x1.array() + (j * M_PI) / n).sin();
                s2.array() += 2.0 * yj.array().square() - (4.0 * M_PI * yj.array()).cos() + 1.0;
                count2++;
            }
        }

        res.col(0) = x1.array() + (2.0 / count1) * s1.array();
        res.col(1) = (1.0 - x1.array()).square() + (2.0 / count2) * s2.array();

        if (return_constraints) {
            res.col(2) = 0.5 * x1.array() - 0.25 +
                         0.8 * x1.array() * (6.0 * M_PI * x1.array() + 2.0 * M_PI / n).sin() -
                         a.col(1).array();
            res.col(3) = 0.5 * x1.array() - 0.25 +
                         0.8 * x1.array() * (6.0 * M_PI * x1.array() + 6.0 * M_PI / n).sin() -
                         a.col(5).array();
        }
        return res;
    });
}

MatrixXd cf8(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x,
             bool return_constraints) {
    const int n = x.cols();
    return apply_parallel(x, [n, return_constraints](const auto &a) {
        const int rows = a.rows();
        MatrixXd res(rows, return_constraints ? 4 : 3);
        const auto x1 = a.col(0);
        const auto x2 = a.col(1);

        VectorXd s1 = VectorXd::Zero(rows);
        VectorXd s2 = VectorXd::Zero(rows);
        VectorXd s3 = VectorXd::Zero(rows);
        int count1 = 0, count2 = 0, count3 = 0;

        for (int j = 3; j <= n; ++j) {
            VectorXd yj = a.col(j - 1).array() -
                          2.0 * x2.array() * (2.0 * M_PI * x1.array() + (j * M_PI) / n).sin();
            if ((j - 1) % 3 == 0) {
                s1.array() += yj.array().square();
                count1++;
            } else if ((j - 2) % 3 == 0) {
                s2.array() += yj.array().square();
                count2++;
            } else {
                s3.array() += yj.array().square();
                count3++;
            }
        }

        const auto common1 = (0.5 * M_PI * x1.array()).cos();
        const auto common2 = (0.5 * M_PI * x2.array()).cos();
        const auto common3 = (0.5 * M_PI * x2.array()).sin();
        const auto common4 = (0.5 * M_PI * x1.array()).sin();

        res.col(0) = common1.array() * common2.array() + (2.0 / count1) * s1.array();
        res.col(1) = common1.array() * common3.array() + (2.0 / count2) * s2.array();
        res.col(2) = common4.array() + (2.0 / count3) * s3.array();

        if (return_constraints) {
            const double N = 2.0;
            const double a_param = 4.0;
            const auto f1_2_f2_2 = res.col(0).array().square() + res.col(1).array().square();
            const auto one_f3_2 = 1.0 - res.col(2).array().square();
            const auto term = f1_2_f2_2 / one_f3_2;
            res.col(3) = 1.0 - term + a_param * (N * M_PI * (term - 0.0 + 1.0)).sin().abs();
        }
        return res;
    });
}

MatrixXd cf9(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x,
             bool return_constraints) {
    const int n = x.cols();
    return apply_parallel(x, [n, return_constraints](const auto &a) {
        const int rows = a.rows();
        MatrixXd res(rows, return_constraints ? 4 : 3);
        const auto x1 = a.col(0);
        const auto x2 = a.col(1);

        VectorXd s1 = VectorXd::Zero(rows);
        VectorXd s2 = VectorXd::Zero(rows);
        VectorXd s3 = VectorXd::Zero(rows);
        int count1 = 0, count2 = 0, count3 = 0;

        for (int j = 3; j <= n; ++j) {
            VectorXd yj = a.col(j - 1).array() - (6.0 * M_PI * x1.array() + (j * M_PI) / n).sin();
            if ((j - 1) % 3 == 0) {
                s1.array() += yj.array().square();
                count1++;
            } else if ((j - 2) % 3 == 0) {
                s2.array() += yj.array().square();
                count2++;
            } else {
                s3.array() += yj.array().square();
                count3++;
            }
        }

        const auto common1 = (0.5 * M_PI * x1.array()).cos();
        const auto common2 = (0.5 * M_PI * x2.array()).cos();
        const auto common3 = (0.5 * M_PI * x2.array()).sin();
        const auto common4 = (0.5 * M_PI * x1.array()).sin();

        res.col(0) = common1.array() * common2.array() + (2.0 / count1) * s1.array();
        res.col(1) = common1.array() * common3.array() + (2.0 / count2) * s2.array();
        res.col(2) = common4.array() + (2.0 / count3) * s3.array();

        if (return_constraints) {
            const double N = 2.0;
            const double a_param = 2.0;
            const auto f1_2_f2_2 = res.col(0).array().square() + res.col(1).array().square();
            const auto one_f3_2 = 1.0 - res.col(2).array().square();
            const auto term = f1_2_f2_2 / one_f3_2;
            res.col(3) = 1.0 - term + a_param * (N * M_PI * (term - 0.0 + 1.0)).sin();
        }
        return res;
    });
}

MatrixXd cf10(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x,
              bool return_constraints) {
    const int n = x.cols();
    return apply_parallel(x, [n, return_constraints](const auto &a) {
        const int rows = a.rows();
        MatrixXd res(rows, return_constraints ? 4 : 3);
        const auto x1 = a.col(0);
        const auto x2 = a.col(1);

        VectorXd s1 = VectorXd::Zero(rows);
        VectorXd s2 = VectorXd::Zero(rows);
        VectorXd s3 = VectorXd::Zero(rows);
        int count1 = 0, count2 = 0, count3 = 0;

        for (int j = 3; j <= n; ++j) {
            VectorXd yj = a.col(j - 1).array() -
                          2.0 * x2.array() * (2.0 * M_PI * x1.array() + (j * M_PI) / n).sin();
            if ((j - 1) % 3 == 0) {
                s1.array() += 2.0 * yj.array().square() - (4.0 * M_PI * yj.array()).cos() + 1.0;
                count1++;
            } else if ((j - 2) % 3 == 0) {
                s2.array() += 2.0 * yj.array().square() - (4.0 * M_PI * yj.array()).cos() + 1.0;
                count2++;
            } else {
                s3.array() += 2.0 * yj.array().square() - (4.0 * M_PI * yj.array()).cos() + 1.0;
                count3++;
            }
        }

        const auto common1 = (0.5 * M_PI * x1.array()).cos();
        const auto common2 = (0.5 * M_PI * x2.array()).cos();
        const auto common3 = (0.5 * M_PI * x2.array()).sin();
        const auto common4 = (0.5 * M_PI * x1.array()).sin();

        res.col(0) = common1.array() * common2.array() + (2.0 / count1) * s1.array();
        res.col(1) = common1.array() * common3.array() + (2.0 / count2) * s2.array();
        res.col(2) = common4.array() + (2.0 / count3) * s3.array();

        if (return_constraints) {
            const double N = 2.0;
            const double a_param = 1.0;
            const auto f1_2_f2_2 = res.col(0).array().square() + res.col(1).array().square();
            const auto one_f3_2 = 1.0 - res.col(2).array().square();
            const auto term = f1_2_f2_2 / one_f3_2;
            res.col(3) = 1.0 - term + a_param * (N * M_PI * (term - 0.0 + 1.0)).sin();
        }
        return res;
    });
}

MatrixXd deb(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    return zdt3(x);
}

MatrixXd dtlz1(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, int num_objectives) {
    const int n = x.cols();
    const int M = num_objectives;
    if (n < M)
        throw std::invalid_argument("The DTLZ1 function requires n >= num_objectives.");
    const int k = n - M + 1;

    return apply_parallel(x, [M, k](const auto &a) {
        const int rows = a.rows();
        const MatrixXd xm = a.rightCols(k);
        const VectorXd g =
            100.0 * (k + ((xm.array() - 0.5).square() - (20.0 * M_PI * (xm.array() - 0.5)).cos())
                             .rowwise()
                             .sum()
                             .array());

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

MatrixXd dtlz2(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, int num_objectives) {
    const int n = x.cols();
    const int M = num_objectives;
    if (n < M)
        throw std::invalid_argument("The DTLZ2 function requires n >= num_objectives.");
    const int k = n - M + 1;

    return apply_parallel(x, [M, k](const auto &a) {
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

MatrixXd dtlz3(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, int num_objectives) {
    const int n = x.cols();
    const int M = num_objectives;
    if (n < M)
        throw std::invalid_argument("The DTLZ3 function requires n >= num_objectives.");
    const int k = n - M + 1;

    return apply_parallel(x, [M, k](const auto &a) {
        const int rows = a.rows();
        const MatrixXd xm = a.rightCols(k);
        const VectorXd g =
            100.0 * (k + ((xm.array() - 0.5).square() - (20.0 * M_PI * (xm.array() - 0.5)).cos())
                             .rowwise()
                             .sum()
                             .array());

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

MatrixXd dtlz4(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, int num_objectives,
               double alpha) {
    const int n = x.cols();
    const int M = num_objectives;
    if (n < M)
        throw std::invalid_argument("The DTLZ4 function requires n >= num_objectives.");
    const int k = n - M + 1;

    return apply_parallel(x, [M, k, alpha](const auto &a) {
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

MatrixXd dtlz5(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, int num_objectives) {
    const int n = x.cols();
    const int M = num_objectives;
    if (n < M)
        throw std::invalid_argument("The DTLZ5 function requires n >= num_objectives.");
    const int k = n - M + 1;

    return apply_parallel(x, [M, k](const auto &a) {
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

MatrixXd dtlz6(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, int num_objectives) {
    const int n = x.cols();
    const int M = num_objectives;
    if (n < M)
        throw std::invalid_argument("The DTLZ6 function requires n >= num_objectives.");
    const int k = n - M + 1;

    return apply_parallel(x, [M, k](const auto &a) {
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

MatrixXd dtlz7(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, int num_objectives) {
    const int n = x.cols();
    const int M = num_objectives;
    if (n < M)
        throw std::invalid_argument("The DTLZ7 function requires n >= num_objectives.");
    const int k = n - M + 1;

    return apply_parallel(x, [M, k](const auto &a) {
        const int rows = a.rows();
        MatrixXd res(rows, M);
        for (int i = 0; i < M - 1; ++i) {
            res.col(i) = a.col(i);
        }

        const VectorXd g = 1.0 + ((9.0 / k) * a.rightCols(k).rowwise().sum().array());

        VectorXd h = VectorXd::Constant(rows, (double)M);
        for (int i = 0; i < M - 1; ++i) {
            h.array() -= (res.col(i).array() / (1.0 + g.array())) *
                         (1.0 + (3.0 * M_PI * res.col(i).array()).sin());
        }

        res.col(M - 1) = (1.0 + g.array()) * h.array();
        return res;
    });
}

MatrixXd fonsecafleming(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    return apply_parallel(x, [n](const auto &a) {
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

MatrixXd kita(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x,
              bool return_constraints) {
    const int n = x.cols();
    if (n < 2)
        throw std::invalid_argument("The KITA function requires at least a 2D space.");

    return apply_parallel(x, [return_constraints](const auto &a) {
        const int rows = a.rows();
        const int out_cols = return_constraints ? 5 : 2;
        MatrixXd res(rows, out_cols);

        const VectorXd x1 = a.col(0);
        const VectorXd x2 = a.col(1);

        // Objectives (Minimize -f1, -f2)
        res.col(0) = x1.array().square() - x2.array();     // -f1 = x1^2 - x2
        res.col(1) = -0.5 * x1.array() - x2.array() - 1.0; // -f2 = -0.5*x1 - x2 - 1

        if (return_constraints) {
            res.col(2) = x1.array() / 6.0 + x2.array() - 13.0 / 2.0;
            res.col(3) = x1.array() / 2.0 + x2.array() - 15.0 / 2.0;
            res.col(4) = 5.0 * x1.array() + x2.array() - 30.0;
        }

        return res;
    });
}

MatrixXd kursawe(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    if (n < 2)
        throw std::invalid_argument("The Kursawe function requires at least a 2D space.");

    return apply_parallel(x, [n](const auto &a) {
        const int rows = a.rows();
        MatrixXd res = MatrixXd::Zero(rows, 2);

        for (int i = 0; i < n - 1; ++i) {
            res.col(0).array() +=
                -10.0 * ((-0.2 * (a.col(i).square() + a.col(i + 1).square()).sqrt()).exp());
        }

        for (int i = 0; i < n; ++i) {
            res.col(1).array() += a.col(i).abs().pow(0.8) + 5.0 * (a.col(i).pow(3)).sin();
        }
        return res;
    });
}

MatrixXd maf1(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, int num_objectives) {
    const int n = x.cols();
    const int M = num_objectives;
    const int k = n - M + 1;
    return apply_parallel(x, [M, k](const auto &a) {
        const int rows = a.rows();
        MatrixXd res(rows, M);
        const auto xm = a.rightCols(k);
        const VectorXd g = (xm.array() - 0.5).square().rowwise().sum();

        for (int i = 1; i <= M; ++i) {
            VectorXd prod = VectorXd::Ones(rows);
            for (int j = 1; j <= M - i; ++j) {
                prod.array() *= a.col(j - 1).array();
            }
            if (i > 1) {
                prod.array() *= (1.0 - a.col(M - i).array());
            }
            res.col(i - 1) = 0.5 * (1.0 + g.array()) * (1.0 - prod.array());
        }
        return res;
    });
}

MatrixXd maf2(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, int num_objectives) {
    const int n = x.cols();
    const int M = num_objectives;
    const int k = n - M + 1;
    return apply_parallel(x, [M, k, n](const auto &a) {
        const int rows = a.rows();
        MatrixXd res(rows, M);
        const int K = k;

        for (int i = 1; i <= M; ++i) {
            const int start = M + (i - 1) * (K / M);
            const int end = (i == M) ? n : M + i * (K / M) - 1;
            const int current_k = end - start + 1;
            VectorXd gi = VectorXd::Zero(rows);
            if (current_k > 0) {
                gi =
                    (a.block(0, start - 1, rows, current_k).array() - 0.5).square().rowwise().sum();
            }

            VectorXd prod = VectorXd::Ones(rows);
            for (int j = 1; j <= M - i; ++j) {
                prod.array() *= (a.col(j - 1).array() * M_PI / 2.0).cos();
            }
            if (i > 1) {
                prod.array() *= (a.col(M - i).array() * M_PI / 2.0).sin();
            }
            res.col(i - 1) = (1.0 + gi.array()) * prod.array();
        }
        return res;
    });
}

MatrixXd maf3(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, int num_objectives) {
    const int n = x.cols();
    const int M = num_objectives;
    const int k = n - M + 1;
    return apply_parallel(x, [M, k](const auto &a) {
        const int rows = a.rows();
        MatrixXd res(rows, M);
        const auto xm = a.rightCols(k);
        const VectorXd g =
            100.0 * (k + ((xm.array() - 0.5).square() - (20.0 * M_PI * (xm.array() - 0.5)).cos())
                             .rowwise()
                             .sum()
                             .array());

        for (int i = 1; i <= M; ++i) {
            VectorXd prod = VectorXd::Ones(rows);
            for (int j = 1; j <= M - i; ++j) {
                prod.array() *= (a.col(j - 1).array() * M_PI / 2.0).cos().pow(4.0);
            }
            if (i > 1) {
                prod.array() *= (a.col(M - i).array() * M_PI / 2.0).sin().pow(4.0);
            }
            res.col(i - 1) = (1.0 + g.array()) * prod.array();
        }
        return res;
    });
}

MatrixXd maf4(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, int num_objectives) {
    const int n = x.cols();
    const int M = num_objectives;
    const int k = n - M + 1;
    return apply_parallel(x, [M, k](const auto &a) {
        const int rows = a.rows();
        MatrixXd res(rows, M);
        const auto xm = a.rightCols(k);
        const VectorXd g =
            100.0 * (k + ((xm.array() - 0.5).square() - (20.0 * M_PI * (xm.array() - 0.5)).cos())
                             .rowwise()
                             .sum()
                             .array());

        for (int i = 1; i <= M; ++i) {
            VectorXd prod = VectorXd::Ones(rows);
            for (int j = 1; j <= M - i; ++j) {
                prod.array() *= (a.col(j - 1).array() * M_PI / 2.0).cos();
            }
            if (i > 1) {
                prod.array() *= (a.col(M - i).array() * M_PI / 2.0).sin();
            }
            res.col(i - 1) =
                std::pow(10.0, i - 1) * (1.0 + g.array() - (1.0 + g.array()) * prod.array());
        }
        return res;
    });
}

MatrixXd maf5(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, int num_objectives) {
    const int n = x.cols();
    const int M = num_objectives;
    const int k = n - M + 1;
    return apply_parallel(x, [M, k](const auto &a) {
        const int rows = a.rows();
        MatrixXd res(rows, M);
        const auto xm = a.rightCols(k);
        const VectorXd g = (xm.array() - 0.5).square().rowwise().sum();

        for (int i = 1; i <= M; ++i) {
            VectorXd prod = VectorXd::Ones(rows);
            for (int j = 1; j <= M - i; ++j) {
                prod.array() *= (a.col(j - 1).array().pow(100.0) * M_PI / 2.0).cos();
            }
            if (i > 1) {
                prod.array() *= (a.col(M - i).array().pow(100.0) * M_PI / 2.0).sin();
            }
            res.col(i - 1) = std::pow(10.0, i - 1) * (1.0 + g.array()) * prod.array();
        }
        return res;
    });
}

MatrixXd maf6(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, int num_objectives) {
    const int n = x.cols();
    const int M = num_objectives;
    const int k = n - M + 1;
    const int I = 2; // PF dimension
    return apply_parallel(x, [M, k, I](const auto &a) {
        const int rows = a.rows();
        MatrixXd res(rows, M);
        const auto xm = a.rightCols(k);
        const VectorXd g = (xm.array() - 0.5).square().rowwise().sum();

        MatrixXd theta(rows, M - 1);
        for (int j = 1; j < I; ++j) {
            theta.col(j - 1) = a.col(j - 1).array() * M_PI / 2.0;
        }
        for (int j = I; j < M; ++j) {
            theta.col(j - 1) =
                (M_PI / (4.0 * (1.0 + g.array()))) * (1.0 + 2.0 * g.array() * a.col(j - 1).array());
        }

        for (int i = 1; i <= M; ++i) {
            VectorXd prod = VectorXd::Ones(rows);
            for (int j = 1; j <= M - i; ++j) {
                prod.array() *= theta.col(j - 1).array().cos();
            }
            if (i > 1) {
                prod.array() *= theta.col(M - i).array().sin();
            }
            res.col(i - 1) = (1.0 + g.array()) * prod.array();
        }
        return res;
    });
}

MatrixXd maf7(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, int num_objectives) {
    const int n = x.cols();
    const int M = num_objectives;
    const int k = n - M + 1;
    return apply_parallel(x, [M, k](const auto &a) {
        const int rows = a.rows();
        MatrixXd res(rows, M);
        const auto xm = a.rightCols(k);
        const VectorXd g = 1.0 + 9.0 * xm.rowwise().mean();

        for (int i = 0; i < M - 1; ++i) {
            res.col(i) = a.col(i);
        }

        VectorXd h = VectorXd::Constant(rows, (double)M);
        for (int i = 0; i < M - 1; ++i) {
            h.array() -= (res.col(i).array() / (1.0 + g.array())) *
                         (1.0 + (3.0 * M_PI * res.col(i).array()).sin());
        }

        res.col(M - 1) = (1.0 + g.array()) * h.array();
        return res;
    });
}

MatrixXd maf8(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, int num_objectives) {
    const int M = num_objectives;
    if (x.cols() != 2)
        throw std::invalid_argument("MaF8 requires a 2D space.");
    return apply_parallel(x, [M](const auto &a) {
        const int rows = a.rows();
        MatrixXd res(rows, M);
        for (int i = 1; i <= M; ++i) {
            double p1 = std::sin(2.0 * M_PI * (i - 1) / M);
            double p2 = std::cos(2.0 * M_PI * (i - 1) / M);
            res.col(i - 1) =
                ((a.col(0).array() - p1).square() + (a.col(1).array() - p2).square()).sqrt();
        }
        return res;
    });
}

MatrixXd maf9(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, int num_objectives) {
    const int M = num_objectives;
    if (x.cols() != 2)
        throw std::invalid_argument("MaF9 requires a 2D space.");
    return apply_parallel(x, [M](const auto &a) {
        const int rows = a.rows();
        MatrixXd res(rows, M);
        for (int i = 1; i <= M; ++i) {
            double alpha = (2.0 * i - 1.0) * M_PI / M;
            res.col(i - 1) = (a.col(0).array() * std::cos(alpha) +
                              a.col(1).array() * std::sin(alpha) - std::cos(M_PI / M))
                                 .abs();
        }
        return res;
    });
}

MatrixXd maf10(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, int num_objectives,
               int k_param) {
    const int n = x.cols();
    const int M = num_objectives;
    const int k = (k_param < 0) ? 2 * (M - 1) : k_param;
    const int l = n - k;

    return apply_parallel(x, [M, k, l](const auto &a) {
        const int rows = a.rows();
        MatrixXd res(rows, M);
        for (int r = 0; r < rows; ++r) {
            VectorXd z(a.cols());
            for (int i = 0; i < a.cols(); ++i)
                z(i) = a(r, i) / (2.0 * (i + 1));

            VectorXd t1(a.cols());
            for (int i = 0; i < a.cols(); ++i)
                t1(i) = s_linear(z(i), 0.35);

            VectorXd t2(a.cols());
            for (int i = 0; i < a.cols(); ++i)
                t2(i) = b_flat(t1(i), 0.8, 0.75, 0.85);

            VectorXd t3(a.cols());
            for (int i = 0; i < a.cols(); ++i)
                t3(i) = b_poly(t2(i), 0.02);

            VectorXd t4(M);
            for (int i = 1; i < M; ++i) {
                int start = (i - 1) * k / (M - 1);
                int size = k / (M - 1);
                VectorXd w = VectorXd::Zero(size);
                for (int j = 0; j < size; ++j)
                    w(j) = 2.0 * (start + j + 1);
                t4(i - 1) = r_sum(t3.segment(start, size), w);
            }
            VectorXd w_last = VectorXd::Zero(l);
            for (int j = 0; j < l; ++j)
                w_last(j) = 2.0 * (k + j + 1);
            t4(M - 1) = r_sum(t3.tail(l), w_last);

            VectorXd h(M);
            for (int i = 1; i < M; ++i) {
                double prod = 1.0;
                for (int j = 1; j <= M - i; ++j)
                    prod *= (1.0 - std::cos(t4(j - 1) * M_PI / 2.0));
                if (i > 1)
                    prod *= (1.0 - std::sin(t4(M - i) * M_PI / 2.0));
                h(i - 1) = prod;
            }
            h(M - 1) = 1.0 - t4(0) - std::cos(10.0 * M_PI * t4(0) + M_PI / 2.0) / (10.0 * M_PI);

            for (int i = 0; i < M; ++i)
                res(r, i) = t4(M - 1) + 2.0 * (i + 1) * h(i);
        }
        return res;
    });
}

MatrixXd mop1(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    return apply_parallel(x, [](const auto &a) {
        const int rows = a.rows();
        MatrixXd res(rows, 2);
        res.col(0) = a.col(0).array().square();
        res.col(1) = (a.col(0).array() - 2.0).square();
        return res;
    });
}

MatrixXd mop2(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    return fonsecafleming(x);
}

MatrixXd mop3(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    return poloni(x);
}

MatrixXd mop4(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    return kursawe(x);
}

MatrixXd mop5(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    return viennet1(x);
}

MatrixXd mop6(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    return zdt3(x);
}

MatrixXd mop7(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    return viennet3(x);
}

MatrixXd oka1(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    if (n != 2)
        throw std::invalid_argument("The OKA1 function requires exactly a 2D space.");

    return apply_parallel(x, [](const auto &a) {
        const int rows = a.rows();
        MatrixXd res(rows, 2);
        const double cos_pi_12 = std::cos(M_PI / 12.0);
        const double sin_pi_12 = std::sin(M_PI / 12.0);

        const VectorXd x1 = a.col(0);
        const VectorXd x2 = a.col(1);

        const VectorXd x1_p = x1.array() * cos_pi_12 - x2.array() * sin_pi_12;
        const VectorXd x2_p = x1.array() * sin_pi_12 + x2.array() * cos_pi_12;

        res.col(0) = x1_p;
        res.col(1) = std::sqrt(2.0 * M_PI) - x1_p.array().abs().sqrt() +
                     2.0 * (x2_p.array() - 3.0 * x1_p.array().cos() - 3.0).abs().pow(1.0 / 3.0);

        return res;
    });
}

MatrixXd oka2(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    if (n != 3)
        throw std::invalid_argument("The OKA2 function requires exactly a 3D space.");

    return apply_parallel(x, [](const auto &a) {
        const int rows = a.rows();
        MatrixXd res(rows, 2);
        const VectorXd x1 = a.col(0);
        const VectorXd x2 = a.col(1);
        const VectorXd x3 = a.col(2);

        res.col(0) = x1;
        res.col(1) = 1.0 - (x1.array() + M_PI).square() / (4.0 * M_PI * M_PI) +
                     (x2.array() - 5.0 * x1.array().cos()).abs().pow(1.0 / 3.0) +
                     (x3.array() - 5.0 * x1.array().sin()).abs().pow(1.0 / 3.0);

        return res;
    });
}

MatrixXd osyczkakundu(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x,
                      bool return_constraints) {
    const int n = x.cols();
    if (n != 6)
        throw std::invalid_argument("The Osyczka and Kundu function requires exactly a 6D space.");

    return apply_parallel(x, [return_constraints](const auto &a) {
        const int rows = a.rows();
        int cols = return_constraints ? 8 : 2;
        MatrixXd res(rows, cols);

        const auto x1 = a.col(0);
        const auto x2 = a.col(1);
        const auto x3 = a.col(2);
        const auto x4 = a.col(3);
        const auto x5 = a.col(4);
        const auto x6 = a.col(5);

        res.col(0) = -(25.0 * (x1 - 2.0).square() + (x2 - 2.0).square() + (x3 - 1.0).square() +
                       (x4 - 4.0).square() + (x5 - 1.0).square());
        res.col(1) =
            x1.square() + x2.square() + x3.square() + x4.square() + x5.square() + x6.square();

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

MatrixXd poloni(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    if (n != 2)
        throw std::invalid_argument("The Poloni function requires exactly a 2D space.");

    return apply_parallel(x, [](const auto &a) {
        const int rows = a.rows();
        MatrixXd res(rows, 2);
        const auto x1 = a.col(0);
        const auto x2 = a.col(1);
        const double A1 =
            0.5 * std::sin(1.0) - 2.0 * std::cos(1.0) + std::sin(2.0) - 1.5 * std::cos(2.0);
        const double A2 =
            1.5 * std::sin(1.0) - std::cos(1.0) + 2.0 * std::sin(2.0) - 0.5 * std::cos(2.0);
        const auto B1 = 0.5 * x1.sin() - 2.0 * x1.cos() + x2.sin() - 1.5 * x2.cos();
        const auto B2 = 1.5 * x1.sin() - x1.cos() + 2.0 * x2.sin() - 0.5 * x2.cos();
        res.col(0) = 1.0 + (A1 - B1).square() + (A2 - B2).square();
        res.col(1) = (x1 + 3.0).square() + (x2 + 1.0).square();
        return res;
    });
}

MatrixXd tanaka(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x,
                bool return_constraints) {
    const int n = x.cols();
    if (n != 2)
        throw std::invalid_argument("The Tanaka function requires exactly a 2D space.");

    return apply_parallel(x, [return_constraints](const auto &a) {
        const int rows = a.rows();
        int cols = return_constraints ? 4 : 2;
        MatrixXd res(rows, cols);

        const auto x1 = a.col(0);
        const auto x2 = a.col(1);

        res.col(0) = x1;
        res.col(1) = x2;

        if (return_constraints) {
            // Vectorized atan2 using binaryExpr
            VectorXd theta = a.col(0).matrix().binaryExpr(
                a.col(1).matrix(), [](double v1, double v2) { return std::atan2(v1, v2); });

            res.col(2) = 1.0 + 0.1 * (16.0 * theta.array()).cos() - x1.square() - x2.square();
            res.col(3) = (x1 - 0.5).square() + (x2 - 0.5).square() - 0.5;
        }
        return res;
    });
}

MatrixXd viennet1(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    if (n != 2)
        throw std::invalid_argument("The Viennet 1 function requires exactly a 2D space.");

    return apply_parallel(x, [](const auto &a) {
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

MatrixXd viennet2(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    if (n != 2)
        throw std::invalid_argument("The Viennet 2 function requires exactly a 2D space.");

    return apply_parallel(x, [](const auto &a) {
        const int rows = a.rows();
        MatrixXd res(rows, 3);
        const auto x1 = a.col(0);
        const auto x2 = a.col(1);
        res.col(0) = (x1 - 2.0).square() / 2.0 + (x2 + 1.0).square() / 13.0 + 3.0;
        res.col(1) = (x1 + x2 - 3.0).square() / 36.0 + (-x1 + x2 + 2.0).square() / 8.0 - 17.0;
        res.col(2) =
            (x1 + 2.0 * x2 - 1.0).square() / 175.0 + (2.0 * x1 - x2).square() / 17.0 - 13.0;
        return res;
    });
}

MatrixXd viennet3(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    if (n != 2)
        throw std::invalid_argument("The Viennet 3 function requires exactly a 2D space.");

    return apply_parallel(x, [](const auto &a) {
        const int rows = a.rows();
        MatrixXd res(rows, 3);
        const auto x1 = a.col(0);
        const auto x2 = a.col(1);
        const auto x12_x22 = x1.square() + x2.square();
        res.col(0) = 0.5 * x12_x22 + x12_x22.sin();
        res.col(1) =
            (3.0 * x1 - 2.0 * x2 + 4.0).square() / 8.0 + (x1 - x2 + 1.0).square() / 27.0 + 15.0;
        res.col(2) = 1.0 / (x12_x22 + 1.0) - 1.1 * (-x12_x22).exp();
        return res;
    });
}

MatrixXd wfg1(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, int num_objectives,
              int k) {
    const int n = x.cols();
    const int M = num_objectives;
    const int l = n - k;
    if (k % (M - 1) != 0)
        throw std::invalid_argument("k must be a multiple of M-1 for WFG functions.");

    return apply_parallel(x, [M, k, l, n](const auto &a) {
        const int rows = a.rows();
        MatrixXd res(rows, M);
        for (int r = 0; r < rows; ++r) {
            VectorXd z = a.row(r).transpose();
            for (int i = 0; i < n; ++i)
                z(i) /= 2.0 * (i + 1);

            VectorXd t1(n);
            t1.head(k) = z.head(k);
            for (int i = k; i < n; ++i)
                t1(i) = s_linear(z(i), 0.35);

            VectorXd t2(n);
            t2.head(k) = t1.head(k);
            for (int i = k; i < n; ++i)
                t2(i) = b_flat(t1(i), 0.8, 0.75, 0.85);

            VectorXd t3(n);
            for (int i = 0; i < n; ++i)
                t3(i) = b_poly(t2(i), 0.02);

            VectorXd t4(M);
            for (int i = 1; i <= M - 1; ++i) {
                int start = (i - 1) * k / (M - 1);
                int size = k / (M - 1);
                VectorXd w = VectorXd::Constant(size, 1.0);
                t4(i - 1) = r_sum(t3.segment(start, size), w);
            }
            t4(M - 1) = r_sum(t3.tail(l), VectorXd::Constant(l, 1.0));

            VectorXd x_final(M);
            for (int i = 0; i < M - 1; ++i)
                x_final(i) = t4(i);
            x_final(M - 1) = t4(M - 1);

            VectorXd h(M);
            wfg_shape_convex(x_final.head(M - 1), h);
            wfg_shape_mixed(x_final.head(M - 1), h, 1.0, 5.0); // WFG1 has mixed shape for f_M
            for (int i = 0; i < M; ++i)
                res(r, i) = x_final(M - 1) + 2.0 * (i + 1) * h(i);
        }
        return res;
    });
}

MatrixXd wfg2(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, int num_objectives,
              int k) {
    const int n = x.cols();
    const int M = num_objectives;
    const int l = n - k;
    if (k % (M - 1) != 0)
        throw std::invalid_argument("k must be a multiple of M-1 for WFG functions.");
    if (l % 2 != 0)
        throw std::invalid_argument("l must be a multiple of 2 for WFG2.");

    return apply_parallel(x, [M, k, l, n](const auto &a) {
        const int rows = a.rows();
        MatrixXd res(rows, M);
        for (int r = 0; r < rows; ++r) {
            VectorXd z = a.row(r).transpose();
            for (int i = 0; i < n; ++i)
                z(i) /= 2.0 * (i + 1);

            VectorXd t1(n);
            t1.head(k) = z.head(k);
            for (int i = k; i < n; ++i)
                t1(i) = s_linear(z(i), 0.35);

            VectorXd t2(k + l / 2);
            t2.head(k) = t1.head(k);
            for (int j = 1; j <= l / 2; ++j) {
                t2(k + j - 1) = r_nonsep(t1.segment(k + 2 * (j - 1), 2), 2);
            }

            VectorXd t3(M);
            for (int i = 1; i <= M - 1; ++i) {
                int start = (i - 1) * k / (M - 1);
                int size = k / (M - 1);
                t3(i - 1) = r_sum(t2.segment(start, size), VectorXd::Constant(size, 1.0));
            }
            t3(M - 1) = r_sum(t2.tail(l / 2), VectorXd::Constant(l / 2, 1.0));

            VectorXd x_final(M);
            for (int i = 0; i < M - 1; ++i)
                x_final(i) = t3(i);
            x_final(M - 1) = t3(M - 1);

            VectorXd h(M);
            wfg_shape_convex(x_final.head(M - 1), h);
            wfg_shape_disconnected(x_final.head(M - 1), h); // WFG2 has disconnected shape for f_M
            for (int i = 0; i < M; ++i)
                res(r, i) = x_final(M - 1) + 2.0 * (i + 1) * h(i);
        }
        return res;
    });
}

MatrixXd wfg3(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, int num_objectives,
              int k) {
    const int n = x.cols();
    const int M = num_objectives;
    const int l = n - k;
    if (k % (M - 1) != 0)
        throw std::invalid_argument("k must be a multiple of M-1 for WFG functions.");
    if (l % 2 != 0)
        throw std::invalid_argument("l must be a multiple of 2 for WFG3.");

    return apply_parallel(x, [M, k, l, n](const auto &a) {
        const int rows = a.rows();
        MatrixXd res(rows, M);
        for (int r = 0; r < rows; ++r) {
            VectorXd z = a.row(r).transpose();
            for (int i = 0; i < n; ++i)
                z(i) /= 2.0 * (i + 1);

            VectorXd t1(n);
            t1.head(k) = z.head(k);
            for (int i = k; i < n; ++i)
                t1(i) = s_linear(z(i), 0.35);

            VectorXd t2(k + l / 2);
            t2.head(k) = t1.head(k);
            for (int j = 1; j <= l / 2; ++j) {
                t2(k + j - 1) = r_sum(t1.segment(k + 2 * (j - 1), 2), VectorXd::Constant(2, 1.0));
            }

            VectorXd t3(M);
            for (int i = 1; i <= M - 1; ++i) {
                int start = (i - 1) * k / (M - 1);
                int size = k / (M - 1);
                t3(i - 1) = r_sum(t2.segment(start, size), VectorXd::Constant(size, 1.0));
            }
            t3(M - 1) = r_sum(t2.tail(l / 2), VectorXd::Constant(l / 2, 1.0));

            VectorXd x_final(M);
            for (int i = 0; i < M - 1; ++i)
                x_final(i) = t3(i);
            x_final(M - 1) = t3(M - 1);

            VectorXd h(M);
            wfg_shape_linear(x_final.head(M - 1), h);
            for (int i = 0; i < M; ++i)
                res(r, i) = x_final(M - 1) + 2.0 * (i + 1) * h(i);
        }
        return res;
    });
}

MatrixXd wfg4(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, int num_objectives,
              int k) {
    const int n = x.cols();
    const int M = num_objectives;
    const int l = n - k;
    if (k % (M - 1) != 0)
        throw std::invalid_argument("k must be a multiple of M-1 for WFG functions.");

    return apply_parallel(x, [M, k, l, n](const auto &a) {
        const int rows = a.rows();
        MatrixXd res(rows, M);
        for (int r = 0; r < rows; ++r) {
            VectorXd z = a.row(r).transpose();
            for (int i = 0; i < n; ++i)
                z(i) /= 2.0 * (i + 1);

            VectorXd t1(n);
            for (int i = 0; i < n; ++i)
                t1(i) = s_multi(z(i), 30.0, 10.0, 0.35);

            VectorXd t2(M);
            for (int i = 1; i <= M - 1; ++i) {
                int start = (i - 1) * k / (M - 1);
                int size = k / (M - 1);
                t2(i - 1) = r_sum(t1.segment(start, size), VectorXd::Constant(size, 1.0));
            }
            t2(M - 1) = r_sum(t1.tail(l), VectorXd::Constant(l, 1.0));

            VectorXd x_final(M);
            for (int i = 0; i < M - 1; ++i)
                x_final(i) = t2(i);
            x_final(M - 1) = t2(M - 1);

            VectorXd h(M);
            wfg_shape_concave(x_final.head(M - 1), h);
            for (int i = 0; i < M; ++i)
                res(r, i) = x_final(M - 1) + 2.0 * (i + 1) * h(i);
        }
        return res;
    });
}

MatrixXd wfg5(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, int num_objectives,
              int k) {
    const int n = x.cols();
    const int M = num_objectives;
    const int l = n - k;
    if (k % (M - 1) != 0)
        throw std::invalid_argument("k must be a multiple of M-1 for WFG functions.");

    return apply_parallel(x, [M, k, l, n](const auto &a) {
        const int rows = a.rows();
        MatrixXd res(rows, M);
        for (int r = 0; r < rows; ++r) {
            VectorXd z = a.row(r).transpose();
            for (int i = 0; i < n; ++i)
                z(i) /= 2.0 * (i + 1);

            VectorXd t1(n);
            for (int i = 0; i < n; ++i)
                t1(i) = s_deceptive(z(i), 0.35, 0.001, 0.05);

            VectorXd t2(M);
            for (int i = 1; i <= M - 1; ++i) {
                int start = (i - 1) * k / (M - 1);
                int size = k / (M - 1);
                t2(i - 1) = r_sum(t1.segment(start, size), VectorXd::Constant(size, 1.0));
            }
            t2(M - 1) = r_sum(t1.tail(l), VectorXd::Constant(l, 1.0));

            VectorXd x_final(M);
            for (int i = 0; i < M - 1; ++i)
                x_final(i) = t2(i);
            x_final(M - 1) = t2(M - 1);

            VectorXd h(M);
            wfg_shape_concave(x_final.head(M - 1), h);
            for (int i = 0; i < M; ++i)
                res(r, i) = x_final(M - 1) + 2.0 * (i + 1) * h(i);
        }
        return res;
    });
}

MatrixXd wfg6(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, int num_objectives,
              int k) {
    const int n = x.cols();
    const int M = num_objectives;
    const int l = n - k;
    if (k % (M - 1) != 0)
        throw std::invalid_argument("k must be a multiple of M-1 for WFG functions.");

    return apply_parallel(x, [M, k, l, n](const auto &a) {
        const int rows = a.rows();
        MatrixXd res(rows, M);
        for (int r = 0; r < rows; ++r) {
            VectorXd z = a.row(r).transpose();
            for (int i = 0; i < n; ++i)
                z(i) /= 2.0 * (i + 1);

            VectorXd t1(n);
            t1.head(k) = z.head(k);
            for (int i = k; i < n; ++i)
                t1(i) = s_linear(z(i), 0.35);

            VectorXd t2(M);
            for (int i = 1; i <= M - 1; ++i) {
                int start = (i - 1) * k / (M - 1);
                int size = k / (M - 1);
                t2(i - 1) = r_nonsep(t1.segment(start, size), size);
            }
            t2(M - 1) = r_nonsep(t1.tail(l), l);

            VectorXd x_final(M);
            for (int i = 0; i < M - 1; ++i)
                x_final(i) = t2(i);
            x_final(M - 1) = t2(M - 1);

            VectorXd h(M);
            wfg_shape_concave(x_final.head(M - 1), h);
            for (int i = 0; i < M; ++i)
                res(r, i) = x_final(M - 1) + 2.0 * (i + 1) * h(i);
        }
        return res;
    });
}

MatrixXd wfg7(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, int num_objectives,
              int k) {
    const int n = x.cols();
    const int M = num_objectives;
    const int l = n - k;
    if (k % (M - 1) != 0)
        throw std::invalid_argument("k must be a multiple of M-1 for WFG functions.");

    return apply_parallel(x, [M, k, l, n](const auto &a) {
        const int rows = a.rows();
        MatrixXd res(rows, M);
        for (int r = 0; r < rows; ++r) {
            VectorXd z = a.row(r).transpose();
            for (int i = 0; i < n; ++i)
                z(i) /= 2.0 * (i + 1);

            VectorXd t1(n);
            for (int i = 0; i < k; ++i) {
                VectorXd tail = z.segment(i + 1, n - (i + 1));
                t1(i) = b_param(z(i), tail.mean(), 0.98, 0.02, 0.5);
            }
            t1.tail(l) = z.tail(l);

            VectorXd t2(n);
            t2.head(k) = t1.head(k);
            for (int i = k; i < n; ++i)
                t2(i) = s_linear(t1(i), 0.35);

            VectorXd t3(M);
            for (int i = 1; i <= M - 1; ++i) {
                int start = (i - 1) * k / (M - 1);
                int size = k / (M - 1);
                t3(i - 1) = r_sum(t2.segment(start, size), VectorXd::Constant(size, 1.0));
            }
            t3(M - 1) = r_sum(t2.tail(l), VectorXd::Constant(l, 1.0));

            VectorXd x_final(M);
            for (int i = 0; i < M - 1; ++i)
                x_final(i) = t3(i);
            x_final(M - 1) = t3(M - 1);

            VectorXd h(M);
            wfg_shape_concave(x_final.head(M - 1), h);
            for (int i = 0; i < M; ++i)
                res(r, i) = x_final(M - 1) + 2.0 * (i + 1) * h(i);
        }
        return res;
    });
}

MatrixXd wfg8(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, int num_objectives,
              int k) {
    const int n = x.cols();
    const int M = num_objectives;
    const int l = n - k;
    if (k % (M - 1) != 0)
        throw std::invalid_argument("k must be a multiple of M-1 for WFG functions.");

    return apply_parallel(x, [M, k, l, n](const auto &a) {
        const int rows = a.rows();
        MatrixXd res(rows, M);
        for (int r = 0; r < rows; ++r) {
            VectorXd z = a.row(r).transpose();
            for (int i = 0; i < n; ++i)
                z(i) /= 2.0 * (i + 1);

            VectorXd t1(n);
            t1.head(k) = z.head(k);
            for (int i = k; i < n; ++i) {
                VectorXd head = z.head(i);
                t1(i) = b_param(z(i), head.mean(), 0.98, 0.02, 0.5);
            }

            VectorXd t2(n);
            t2.head(k) = t1.head(k);
            for (int i = k; i < n; ++i)
                t2(i) = s_linear(t1(i), 0.35);

            VectorXd t3(M);
            for (int i = 1; i <= M - 1; ++i) {
                int start = (i - 1) * k / (M - 1);
                int size = k / (M - 1);
                t3(i - 1) = r_sum(t2.segment(start, size), VectorXd::Constant(size, 1.0));
            }
            t3(M - 1) = r_sum(t2.tail(l), VectorXd::Constant(l, 1.0));

            VectorXd x_final(M);
            for (int i = 0; i < M - 1; ++i)
                x_final(i) = t3(i);
            x_final(M - 1) = t3(M - 1);

            VectorXd h(M);
            wfg_shape_concave(x_final.head(M - 1), h);
            for (int i = 0; i < M; ++i)
                res(r, i) = x_final(M - 1) + 2.0 * (i + 1) * h(i);
        }
        return res;
    });
}

MatrixXd wfg9(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, int num_objectives,
              int k) {
    const int n = x.cols();
    const int M = num_objectives;
    const int l = n - k;
    if (k % (M - 1) != 0)
        throw std::invalid_argument("k must be a multiple of M-1 for WFG functions.");

    return apply_parallel(x, [M, k, l, n](const auto &a) {
        const int rows = a.rows();
        MatrixXd res(rows, M);
        for (int r = 0; r < rows; ++r) {
            VectorXd z = a.row(r).transpose();
            for (int i = 0; i < n; ++i)
                z(i) /= 2.0 * (i + 1);

            VectorXd t1(n);
            for (int i = 0; i < n - 1; ++i) {
                VectorXd tail = z.tail(n - (i + 1));
                t1(i) = b_param(z(i), tail.mean(), 0.98, 0.02, 0.5);
            }
            t1(n - 1) = z(n - 1);

            VectorXd t2(n);
            for (int i = 0; i < k; ++i)
                t2(i) = s_deceptive(t1(i), 0.35, 0.001, 0.05);
            for (int i = k; i < n; ++i)
                t2(i) = s_multi(t1(i), 30.0, 95.0, 0.35);

            VectorXd t3(M);
            for (int i = 1; i <= M - 1; ++i) {
                int start = (i - 1) * k / (M - 1);
                int size = k / (M - 1);
                t3(i - 1) = r_nonsep(t2.segment(start, size), size);
            }
            t3(M - 1) = r_nonsep(t2.tail(l), l);

            VectorXd x_final(M);
            for (int i = 0; i < M - 1; ++i)
                x_final(i) = t3(i);
            x_final(M - 1) = t3(M - 1);

            VectorXd h(M);
            wfg_shape_concave(x_final.head(M - 1), h);
            for (int i = 0; i < M; ++i)
                res(r, i) = x_final(M - 1) + 2.0 * (i + 1) * h(i);
        }
        return res;
    });
}

MatrixXd zdt1(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    if (n < 2)
        throw std::invalid_argument("The ZDT1 function requires at least a 2D space.");

    return apply_parallel(x, [n](const auto &a) {
        const int rows = a.rows();
        MatrixXd res(rows, 2);

        res.col(0) = a.col(0);
        const VectorXd g = 1.0 + ((9.0 / (n - 1.0)) * a.rightCols(n - 1).rowwise().sum().array());
        const VectorXd h = 1.0 - (res.col(0).array() / g.array()).sqrt();
        res.col(1) = g.array() * h.array();

        return res;
    });
}

MatrixXd zdt2(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    if (n < 2)
        throw std::invalid_argument("The ZDT2 function requires at least a 2D space.");

    return apply_parallel(x, [n](const auto &a) {
        const int rows = a.rows();
        MatrixXd res(rows, 2);

        res.col(0) = a.col(0);
        const VectorXd g = 1.0 + ((9.0 / (n - 1.0)) * a.rightCols(n - 1).rowwise().sum().array());
        const VectorXd h = 1.0 - (res.col(0).array() / g.array()).square();
        res.col(1) = g.array() * h.array();

        return res;
    });
}

MatrixXd zdt3(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    if (n < 2)
        throw std::invalid_argument("The ZDT3 function requires at least a 2D space.");

    return apply_parallel(x, [n](const auto &a) {
        const int rows = a.rows();
        MatrixXd res(rows, 2);

        res.col(0) = a.col(0);
        const VectorXd g = 1.0 + ((9.0 / (n - 1.0)) * a.rightCols(n - 1).rowwise().sum().array());
        const VectorXd f1_g = res.col(0).array() / g.array();
        const VectorXd h =
            1.0 - f1_g.array().sqrt() - f1_g.array() * (10.0 * M_PI * res.col(0).array()).sin();
        res.col(1) = g.array() * h.array();

        return res;
    });
}

MatrixXd zdt4(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    if (n < 2)
        throw std::invalid_argument("The ZDT4 function requires at least a 2D space.");

    return apply_parallel(x, [n](const auto &a) {
        const int rows = a.rows();
        MatrixXd res(rows, 2);

        res.col(0) = a.col(0);
        const auto x_rest = a.rightCols(n - 1);
        const VectorXd g =
            1.0 + 10.0 * (n - 1.0) +
            (x_rest.square() - 10.0 * (4.0 * M_PI * x_rest).cos()).rowwise().sum().array();
        const VectorXd h = 1.0 - (res.col(0).array() / g.array()).sqrt();
        res.col(1) = g.array() * h.array();

        return res;
    });
}

MatrixXd zdt6(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    if (n < 2)
        throw std::invalid_argument("The ZDT6 function requires at least a 2D space.");

    return apply_parallel(x, [n](const auto &a) {
        const int rows = a.rows();
        MatrixXd res(rows, 2);

        const auto x1 = a.col(0);
        res.col(0) = 1.0 - ((-4.0 * x1).exp() * (6.0 * M_PI * x1).sin().pow(6.0));
        const VectorXd g =
            1.0 + 9.0 * (a.rightCols(n - 1).rowwise().sum().array() / (n - 1.0)).pow(0.25);
        const VectorXd h = 1.0 - (res.col(0).array() / g.array()).square();
        res.col(1) = g.array() * h.array();

        return res;
    });
}

MatrixXd uf1(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    return apply_parallel(x, [n](const auto &a) {
        const int rows = a.rows();
        MatrixXd res(rows, 2);
        const auto x1 = a.col(0);

        VectorXd g1 = VectorXd::Zero(rows);
        VectorXd g2 = VectorXd::Zero(rows);
        int count1 = 0;
        int count2 = 0;

        for (int j = 2; j <= n; ++j) {
            VectorXd yj = a.col(j - 1).array() - (6.0 * M_PI * x1.array() + (j * M_PI) / n).sin();
            if (j % 2 != 0) {
                g1.array() += yj.array().square();
                count1++;
            } else {
                g2.array() += yj.array().square();
                count2++;
            }
        }

        res.col(0) = x1.array() + (2.0 / count1) * g1.array();
        res.col(1) = 1.0 - x1.array().sqrt() + (2.0 / count2) * g2.array();
        return res;
    });
}

MatrixXd uf2(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    return apply_parallel(x, [n](const auto &a) {
        const int rows = a.rows();
        MatrixXd res(rows, 2);
        const auto x1 = a.col(0);

        VectorXd g1 = VectorXd::Zero(rows);
        VectorXd g2 = VectorXd::Zero(rows);
        int count1 = 0;
        int count2 = 0;

        for (int j = 2; j <= n; ++j) {
            VectorXd yj;
            if (j % 2 != 0) {
                yj = a.col(j - 1).array() -
                     (0.3 * x1.array().square() *
                          (24.0 * M_PI * x1.array() + (4.0 * j * M_PI) / n).cos() +
                      0.6 * x1.array()) *
                         (6.0 * M_PI * x1.array() + (j * M_PI) / n).cos();
                g1.array() += yj.array().square();
                count1++;
            } else {
                yj = a.col(j - 1).array() -
                     (0.3 * x1.array().square() *
                          (24.0 * M_PI * x1.array() + (4.0 * j * M_PI) / n).cos() +
                      0.6 * x1.array()) *
                         (6.0 * M_PI * x1.array() + (j * M_PI) / n).sin();
                g2.array() += yj.array().square();
                count2++;
            }
        }

        res.col(0) = x1.array() + (2.0 / count1) * g1.array();
        res.col(1) = 1.0 - x1.array().sqrt() + (2.0 / count2) * g2.array();
        return res;
    });
}

MatrixXd uf3(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    return apply_parallel(x, [n](const auto &a) {
        const int rows = a.rows();
        MatrixXd res(rows, 2);
        const auto x1 = a.col(0);

        VectorXd g1 = VectorXd::Zero(rows);
        VectorXd g2 = VectorXd::Zero(rows);
        VectorXd p1 = VectorXd::Ones(rows);
        VectorXd p2 = VectorXd::Ones(rows);
        int count1 = 0;
        int count2 = 0;

        for (int j = 2; j <= n; ++j) {
            double exponent = 0.5 * (1.0 + 3.0 * (j - 2.0) / (n - 2.0));
            VectorXd yj = a.col(j - 1).array() - x1.array().pow(exponent);
            if (j % 2 != 0) {
                g1.array() += yj.array().square();
                p1.array() *= (20.0 * yj.array() * M_PI / std::sqrt(j)).cos();
                count1++;
            } else {
                g2.array() += yj.array().square();
                p2.array() *= (20.0 * yj.array() * M_PI / std::sqrt(j)).cos();
                count2++;
            }
        }

        res.col(0) = x1.array() + (2.0 / count1) * (4.0 * g1.array() - 2.0 * p1.array() + 2.0);
        res.col(1) =
            1.0 - x1.array().sqrt() + (2.0 / count2) * (4.0 * g2.array() - 2.0 * p2.array() + 2.0);
        return res;
    });
}

MatrixXd uf4(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    return apply_parallel(x, [n](const auto &a) {
        const int rows = a.rows();
        MatrixXd res(rows, 2);
        const auto x1 = a.col(0);

        VectorXd g1 = VectorXd::Zero(rows);
        VectorXd g2 = VectorXd::Zero(rows);
        int count1 = 0;
        int count2 = 0;

        auto h = [](const VectorXd &t) {
            return (2.0 * t.array().square() - (4.0 * M_PI * t.array()).cos() + 1.0).matrix();
        };

        for (int j = 2; j <= n; ++j) {
            VectorXd yj = a.col(j - 1).array() - (6.0 * M_PI * x1.array() + (j * M_PI) / n).sin();
            if (j % 2 != 0) {
                g1.array() += h(yj).array();
                count1++;
            } else {
                g2.array() += h(yj).array();
                count2++;
            }
        }

        res.col(0) = x1.array() + (2.0 / count1) * g1.array();
        res.col(1) = 1.0 - x1.array().square() + (2.0 / count2) * g2.array();
        return res;
    });
}

MatrixXd uf5(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    return apply_parallel(x, [n](const auto &a) {
        const int rows = a.rows();
        MatrixXd res(rows, 2);
        const auto x1 = a.col(0);
        const int N = 10;
        const double epsilon = 0.1;

        VectorXd g1 = VectorXd::Zero(rows);
        VectorXd g2 = VectorXd::Zero(rows);
        int count1 = 0;
        int count2 = 0;

        auto h = [](const VectorXd &t) {
            return (2.0 * t.array().square() - (4.0 * M_PI * t.array()).cos() + 1.0).matrix();
        };

        for (int j = 2; j <= n; ++j) {
            VectorXd yj = a.col(j - 1).array() - (6.0 * M_PI * x1.array() + (j * M_PI) / n).sin();
            if (j % 2 != 0) {
                g1.array() += h(yj).array();
                count1++;
            } else {
                g2.array() += h(yj).array();
                count2++;
            }
        }

        VectorXd common = (0.5 / N + epsilon) * (2.0 * N * M_PI * x1.array()).sin().abs();
        res.col(0) = x1.array() + common.array() + (2.0 / count1) * g1.array();
        res.col(1) = 1.0 - x1.array() + common.array() + (2.0 / count2) * g2.array();
        return res;
    });
}

MatrixXd uf6(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    return apply_parallel(x, [n](const auto &a) {
        const int rows = a.rows();
        MatrixXd res(rows, 2);
        const auto x1 = a.col(0);
        const int N = 2;
        const double epsilon = 0.1;

        VectorXd g1 = VectorXd::Zero(rows);
        VectorXd g2 = VectorXd::Zero(rows);
        VectorXd p1 = VectorXd::Ones(rows);
        VectorXd p2 = VectorXd::Ones(rows);
        int count1 = 0;
        int count2 = 0;

        for (int j = 2; j <= n; ++j) {
            VectorXd yj = a.col(j - 1).array() - (6.0 * M_PI * x1.array() + (j * M_PI) / n).sin();
            if (j % 2 != 0) {
                g1.array() += yj.array().square();
                p1.array() *= (20.0 * yj.array() * M_PI / std::sqrt(j)).cos();
                count1++;
            } else {
                g2.array() += yj.array().square();
                p2.array() *= (20.0 * yj.array() * M_PI / std::sqrt(j)).cos();
                count2++;
            }
        }

        VectorXd common =
            (2.0 * (0.5 / N + epsilon) * (2.0 * N * M_PI * x1.array()).sin()).array().max(0.0);
        res.col(0) = x1.array() + common.array() +
                     (2.0 / count1) * (4.0 * g1.array() - 2.0 * p1.array() + 2.0);
        res.col(1) = 1.0 - x1.array() + common.array() +
                     (2.0 / count2) * (4.0 * g2.array() - 2.0 * p2.array() + 2.0);
        return res;
    });
}

MatrixXd uf7(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    return apply_parallel(x, [n](const auto &a) {
        const int rows = a.rows();
        MatrixXd res(rows, 2);
        const auto x1 = a.col(0);

        VectorXd g1 = VectorXd::Zero(rows);
        VectorXd g2 = VectorXd::Zero(rows);
        int count1 = 0;
        int count2 = 0;

        for (int j = 2; j <= n; ++j) {
            VectorXd yj = a.col(j - 1).array() - (6.0 * M_PI * x1.array() + (j * M_PI) / n).sin();
            if (j % 2 != 0) {
                g1.array() += yj.array().square();
                count1++;
            } else {
                g2.array() += yj.array().square();
                count2++;
            }
        }

        res.col(0) = x1.array().pow(0.2) + (2.0 / count1) * g1.array();
        res.col(1) = 1.0 - x1.array().pow(0.2) + (2.0 / count2) * g2.array();
        return res;
    });
}

MatrixXd uf8(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    return apply_parallel(x, [n](const auto &a) {
        const int rows = a.rows();
        MatrixXd res(rows, 3);
        const auto x1 = a.col(0);
        const auto x2 = a.col(1);

        VectorXd g1 = VectorXd::Zero(rows);
        VectorXd g2 = VectorXd::Zero(rows);
        VectorXd g3 = VectorXd::Zero(rows);
        int count1 = 0;
        int count2 = 0;
        int count3 = 0;

        for (int j = 3; j <= n; ++j) {
            VectorXd yj = a.col(j - 1).array() -
                          2.0 * x2.array() * (2.0 * M_PI * x1.array() + (j * M_PI) / n).sin();
            if ((j - 1) % 3 == 0) {
                g1.array() += yj.array().square();
                count1++;
            } else if ((j - 2) % 3 == 0) {
                g2.array() += yj.array().square();
                count2++;
            } else {
                g3.array() += yj.array().square();
                count3++;
            }
        }

        res.col(0) = (0.5 * M_PI * x1.array()).cos() * (0.5 * M_PI * x2.array()).cos() +
                     (2.0 / count1) * g1.array();
        res.col(1) = (0.5 * M_PI * x1.array()).cos() * (0.5 * M_PI * x2.array()).sin() +
                     (2.0 / count2) * g2.array();
        res.col(2) = (0.5 * M_PI * x1.array()).sin() + (2.0 / count3) * g3.array();
        return res;
    });
}

MatrixXd uf9(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    return apply_parallel(x, [n](const auto &a) {
        const int rows = a.rows();
        MatrixXd res(rows, 3);
        const auto x1 = a.col(0);
        const auto x2 = a.col(1);
        const double epsilon = 0.1;

        VectorXd g1 = VectorXd::Zero(rows);
        VectorXd g2 = VectorXd::Zero(rows);
        VectorXd g3 = VectorXd::Zero(rows);
        int count1 = 0;
        int count2 = 0;
        int count3 = 0;

        for (int j = 3; j <= n; ++j) {
            VectorXd yj = a.col(j - 1).array() -
                          2.0 * x2.array() * (2.0 * M_PI * x1.array() + (j * M_PI) / n).sin();
            if ((j - 1) % 3 == 0) {
                g1.array() += yj.array().square();
                count1++;
            } else if ((j - 2) % 3 == 0) {
                g2.array() += yj.array().square();
                count2++;
            } else {
                g3.array() += yj.array().square();
                count3++;
            }
        }

        VectorXd E = (1.0 + epsilon) * (1.0 - 4.0 * (2.0 * x1.array() - 1.0).square());
        E = E.array().max(0.0);

        res.col(0) =
            0.5 * (E.array() + 2.0 * x1.array()) * x2.array() + (2.0 / count1) * g1.array();
        res.col(1) =
            0.5 * (E.array() + 2.0 * x1.array()) * (1.0 - x2.array()) + (2.0 / count2) * g2.array();
        res.col(2) = 1.0 - x1.array() + (2.0 / count3) * g3.array();
        return res;
    });
}

MatrixXd uf10(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    return apply_parallel(x, [n](const auto &a) {
        const int rows = a.rows();
        MatrixXd res(rows, 3);
        const auto x1 = a.col(0);
        const auto x2 = a.col(1);

        VectorXd g1 = VectorXd::Zero(rows);
        VectorXd g2 = VectorXd::Zero(rows);
        VectorXd g3 = VectorXd::Zero(rows);
        int count1 = 0;
        int count2 = 0;
        int count3 = 0;

        auto h = [](const VectorXd &t) {
            return (4.0 * t.array().square() - (8.0 * M_PI * t.array()).cos() + 1.0).matrix();
        };

        for (int j = 3; j <= n; ++j) {
            VectorXd yj = a.col(j - 1).array() -
                          2.0 * x2.array() * (2.0 * M_PI * x1.array() + (j * M_PI) / n).sin();
            if ((j - 1) % 3 == 0) {
                g1.array() += h(yj).array();
                count1++;
            } else if ((j - 2) % 3 == 0) {
                g2.array() += h(yj).array();
                count2++;
            } else {
                g3.array() += h(yj).array();
                count3++;
            }
        }

        res.col(0) = (0.5 * M_PI * x1.array()).cos() * (0.5 * M_PI * x2.array()).cos() +
                     (2.0 / count1) * g1.array();
        res.col(1) = (0.5 * M_PI * x1.array()).cos() * (0.5 * M_PI * x2.array()).sin() +
                     (2.0 / count2) * g2.array();
        res.col(2) = (0.5 * M_PI * x1.array()).sin() + (2.0 / count3) * g3.array();
        return res;
    });
}
} // namespace BenchmarkFcns::MultiObjective
