#include "benchmarkfcns.h"
#include "utils.h"
#include <random>

namespace BenchmarkFcns {

using namespace Eigen;

VectorXd ackley(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    return apply_parallel(x, [](const auto &a) {
        const int n = a.cols();
        const VectorXd sum1 = a.square().rowwise().sum();
        const VectorXd sum2 = (2.0 * M_PI * a).cos().rowwise().sum();
        return VectorXd(-(20.0 * (-0.2 * (sum1.array() / n).sqrt()).exp()) + 20.0 -
                        (sum2.array() / n).exp() + exp(1.0));
    });
}

VectorXd ackleyn2(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("Ackley2 function only accepts 2D input.");
    return apply_parallel(x, [](const auto &a) {
        return VectorXd(-200.0 * ((-0.02 * (a.square().rowwise().sum().array().sqrt())).exp()));
    });
}

VectorXd ackleyn3(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("The Ackleyn3 function only accepts 2D inputs.");
    return apply_parallel(x, [](const auto &a) {
        const auto X = a.col(0);
        const auto Y = a.col(1);
        return VectorXd(-200.0 * ((-0.2 * (X.square() + Y.square()).sqrt()).exp()) +
                        5.0 * ((3.0 * X).cos() + (3.0 * Y).sin()).exp());
    });
}

VectorXd ackleyn4(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    return apply_parallel(x, [](const auto &a) {
        const int n = a.cols();
        const MatrixXd term1 =
            exp(-0.2) *
            ((a.block(0, 0, a.rows(), n - 1).square() + a.block(0, 1, a.rows(), n - 1).square())
                 .sqrt());
        const MatrixXd term2 = 3.0 * ((2.0 * a.block(0, 0, a.rows(), n - 1)).cos() +
                                      (2.0 * a.block(0, 1, a.rows(), n - 1)).sin());
        return VectorXd((term1 + term2).rowwise().sum());
    });
}

VectorXd adjiman(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("The Adjiman function only accepts 2D inputs.");
    return apply_parallel(x, [](const auto &a) {
        const auto X = a.col(0);
        const auto Y = a.col(1);
        return VectorXd((X.cos() * Y.sin()) - (X / (Y.square() + 1)));
    });
}

VectorXd alpinen1(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    return apply_parallel(x, [](const auto &a) {
        return VectorXd((a * a.sin() + 0.1 * a).rowwise().sum().array().abs());
    });
}

VectorXd alpinen2(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    return apply_parallel(
        x, [](const auto &a) { return VectorXd((a.sqrt() * a.sin()).rowwise().prod()); });
}

VectorXd amgm(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const double ninv = 1.0 / x.cols();
    return apply_parallel(x, [ninv](const auto &a) {
        const VectorXd comp1 = a.rowwise().prod().array().pow(ninv);
        const VectorXd comp2 = a.rowwise().mean();
        return VectorXd((comp1 - comp2).array().square());
    });
}

VectorXd attractivesector(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    return apply_parallel(x, [](const auto &a) {
        const auto a2 = a.square();
        const auto result = (a > 0).select(10000.0 * a2, a2);
        return VectorXd(result.rowwise().sum());
    });
}

VectorXd baluja(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    return apply_parallel(x, [](const auto &a) {
        ArrayXd partial_sum = a.col(0);
        ArrayXd sum_sq = partial_sum.square();
        for (int j = 1; j < a.cols(); ++j) {
            partial_sum += a.col(j);
            sum_sq += partial_sum.square();
        }
        return VectorXd(sum_sq);
    });
}

VectorXd bartelsconn(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("The Bartels Conn function only accepts 2D inputs.");
    return apply_parallel(x, [](const auto &a) {
        const auto X = a.col(0);
        const auto Y = a.col(1);
        return VectorXd((X.square() + Y.square() + X * Y).abs() + X.sin().abs() + Y.cos().abs());
    });
}

VectorXd beale(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("The Beale function only accepts 2D inputs.");
    return apply_parallel(x, [](const auto &a) {
        const auto X = a.col(0);
        const auto Y = a.col(1);
        return VectorXd((1.5 - X + (X * Y)).square() + (2.25 - X + (X * Y.square())).square() +
                        (2.625 - X + (X * Y.cube())).square());
    });
}

VectorXd bentcigar(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    return apply_parallel(x, [n](const auto &a) {
        VectorXd scores = a.col(0).square();
        if (n > 1) {
            scores += 1e6 * a.block(0, 1, a.rows(), n - 1).square().rowwise().sum().matrix();
        }
        return scores;
    });
}

VectorXd biggsexp02(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("The BiggsExp02 function only accepts 2D inputs.");
    const int numTerms = 10;
    const VectorXd i = VectorXd::LinSpaced(numTerms, 1, numTerms);
    const VectorXd ti = 0.1 * i;
    const VectorXd yi = (-ti).array().exp() - 5 * (-10 * ti).array().exp();

    return apply_parallel(x, [ti, yi, numTerms](const auto &a) {
        const int chunk_rows = a.rows();
        const auto x1 = a.col(0).matrix().transpose();
        const auto x2 = a.col(1).matrix().transpose();
        const MatrixXd term1 = (-ti * x1).array().exp();
        const MatrixXd term2 = 5 * (-ti * x2).array().exp();
        const MatrixXd residuals_sq =
            (term1.array() - term2.array() - yi.replicate(1, chunk_rows).array()).square();
        return VectorXd(residuals_sq.colwise().sum());
    });
}

VectorXd biggsexp03(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("The BiggsExp03 function only accepts 2D inputs.");
    const int numTerms = 10;
    const VectorXd i = VectorXd::LinSpaced(numTerms, 1, numTerms);
    const VectorXd ti = 0.1 * i;
    const VectorXd yi = (-ti).array().exp() - 5 * (-10 * ti).array().exp();

    return apply_parallel(x, [ti, yi, numTerms](const auto &a) {
        const int chunk_rows = a.rows();
        const auto x1 = a.col(0).matrix().transpose();
        const auto x2 = a.col(1).matrix().transpose();
        const MatrixXd term1 = (-ti * x1).array().exp();
        const MatrixXd term2 = x1.replicate(numTerms, 1).array() * (-ti * x2).array().exp();
        const MatrixXd residuals_sq =
            (term1.array() - term2.array() - yi.replicate(1, chunk_rows).array()).square();
        return VectorXd(residuals_sq.colwise().sum());
    });
}

VectorXd biggsexp04(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 3)
        throw std::invalid_argument("The BiggsExp04 function only accepts 3D inputs.");
    const int numTerms = 10;
    const VectorXd i = VectorXd::LinSpaced(numTerms, 1, numTerms);
    const VectorXd ti = 0.1 * i;
    const VectorXd yi = (-ti).array().exp() - 5 * (-10 * ti).array().exp();

    return apply_parallel(x, [ti, yi, numTerms](const auto &a) {
        const int chunk_rows = a.rows();
        const auto x1 = a.col(0).matrix().transpose();
        const auto x2 = a.col(1).matrix().transpose();
        const auto x3 = a.col(2).matrix().transpose();
        const MatrixXd term1 = x3.replicate(numTerms, 1).array() * (-ti * x1).array().exp();
        const MatrixXd term2 = 5 * (-ti * x2).array().exp();
        const MatrixXd residuals_sq =
            (term1.array() - term2.array() - yi.replicate(1, chunk_rows).array()).square();
        return VectorXd(residuals_sq.colwise().sum());
    });
}

VectorXd biggsexp05(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 4)
        throw std::invalid_argument("The BiggsExp05 function only accepts 4D inputs.");
    const int numTerms = 11;
    const VectorXd i = VectorXd::LinSpaced(numTerms, 1, numTerms);
    const VectorXd ti = 0.1 * i;
    const VectorXd yi = (-ti).array().exp() - 5 * (-10 * ti).array().exp();

    return apply_parallel(x, [ti, yi, numTerms](const auto &a) {
        const int chunk_rows = a.rows();
        const auto x1 = a.col(0).matrix().transpose();
        const auto x2 = a.col(1).matrix().transpose();
        const auto x3 = a.col(2).matrix().transpose();
        const auto x4 = a.col(3).matrix().transpose();
        const MatrixXd term1 = x3.replicate(numTerms, 1).array() * (-ti * x1).array().exp();
        const MatrixXd term2 = x4.replicate(numTerms, 1).array() * (-ti * x2).array().exp();
        const MatrixXd residuals_sq =
            (term1.array() - term2.array() - yi.replicate(1, chunk_rows).array()).square();
        return VectorXd(residuals_sq.colwise().sum());
    });
}

VectorXd biggsexp06(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 6)
        throw std::invalid_argument("The BiggsExp06 function only accepts 6D inputs.");
    const int numTerms = 13;
    const VectorXd i = VectorXd::LinSpaced(numTerms, 1, numTerms);
    const VectorXd ti = 0.1 * i;
    const VectorXd yi = (-ti).array().exp() - 5 * (-10 * ti).array().exp();

    return apply_parallel(x, [ti, yi, numTerms](const auto &a) {
        const int chunk_rows = a.rows();
        const auto x1 = a.col(0).matrix().transpose();
        const auto x2 = a.col(1).matrix().transpose();
        const auto x3 = a.col(2).matrix().transpose();
        const auto x4 = a.col(3).matrix().transpose();
        const auto x5 = a.col(4).matrix().transpose();
        const auto x6 = a.col(5).matrix().transpose();

        const MatrixXd term1 =
            x3.replicate(numTerms, 1).array() *
            (-(ti.replicate(1, chunk_rows).array() + x5.replicate(numTerms, 1).array()) *
             x1.replicate(numTerms, 1).array())
                .exp();
        const MatrixXd term2 =
            x4.replicate(numTerms, 1).array() *
            (-(ti.replicate(1, chunk_rows).array() + x6.replicate(numTerms, 1).array()) *
             x2.replicate(numTerms, 1).array())
                .exp();

        const MatrixXd residuals_sq =
            (term1.array() - term2.array() - yi.replicate(1, chunk_rows).array()).square();
        return VectorXd(residuals_sq.colwise().sum());
    });
}

VectorXd bird(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("The Bird function is only defined on a 2D space.");
    return apply_parallel(x, [](const auto &a) {
        const auto X = a.col(0);
        const auto Y = a.col(1);
        return VectorXd((X.sin() * (1 - Y.cos()).square().exp()) +
                        (Y.cos() * (1 - X.sin()).square().exp()) + (X - Y).square());
    });
}

VectorXd bohachevskyn1(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("The Bohachevsky N. 1 function is only defined on a 2D space.");
    return apply_parallel(x, [](const auto &a) {
        const auto X = a.col(0);
        const auto Y = a.col(1);
        return VectorXd(X.square() + 2 * Y.square() - 0.3 * (3 * M_PI * X).cos() -
                        0.4 * (4 * M_PI * Y).cos() + 0.7);
    });
}

VectorXd bohachevskyn2(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("The Bohachevsky N2 function only accepts 2D inputs");
    return apply_parallel(x, [](const auto &a) {
        const auto X = a.col(0);
        const auto Y = a.col(1);
        return VectorXd(X.square() + 2 * Y.square() -
                        0.3 * (3 * M_PI * X).cos() * (4 * M_PI * Y).cos() + 0.3);
    });
}

VectorXd bohachevskyn3(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("The Bohachevsky N3 function only accepts 2D inputs");
    return apply_parallel(x, [](const auto &a) {
        const auto X = a.col(0);
        const auto Y = a.col(1);
        return VectorXd(X.square() + 2 * Y.square() - 0.3 * (3 * M_PI * X + 4 * M_PI * Y).cos() +
                        0.3);
    });
}

VectorXd booth(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("The Booth function only accepts 2D inputs");
    return apply_parallel(x, [](const auto &a) {
        const auto X = a.col(0);
        const auto Y = a.col(1);
        return VectorXd((X + 2 * Y - 7).square() + (2 * X + Y - 5).square());
    });
}

VectorXd boxbetts(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 3)
        throw std::invalid_argument("The Box-Betts function only accepts 3D inputs.");
    return apply_parallel(x, [](const auto &a) {
        const auto X1 = a.col(0);
        const auto X2 = a.col(1);
        const auto X3 = a.col(2);
        VectorXd res = VectorXd::Zero(a.rows());
        for (int i = 1; i <= 10; ++i) {
            double coeff = 0.1 * (i + 1);
            auto term = (-coeff * X1).exp() - (-coeff * X2).exp() -
                        (exp(-coeff) - exp(-(double)(i + 1))) * X3;
            res += term.square().matrix();
        }
        return res;
    });
}

VectorXd braninn1(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("The Branin N. 1 function only accepts 2D inputs");
    constexpr double a_coeff = 1;
    constexpr double b = 5.1 / (4 * M_PI * M_PI);
    constexpr double c = 5 / M_PI;
    constexpr double d = 6;
    constexpr double e = 10;
    constexpr double f = 1 / (8 * M_PI);

    return apply_parallel(x, [a_coeff, b, c, d, e, f](const auto &a) {
        const auto X = a.col(0);
        const auto Y = a.col(1);
        return VectorXd(a_coeff * (Y - b * X.square() + c * X - d).square() +
                        e * (1 - f) * X.cos() + e);
    });
}

VectorXd braninn2(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("The Branin N. 2 function only accepts 2D inputs");
    return apply_parallel(x, [](const auto &a) {
        const auto X = a.col(0);
        const auto Y = a.col(1);
        return VectorXd((X.square() + Y.square() - 5).square() +
                        (X.sin().square() + Y.cos().square() - 1).square());
    });
}

VectorXd brent(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("The Brent function only accepts 2D inputs");
    return apply_parallel(x, [](const auto &a) {
        const auto X = a.col(0);
        const auto Y = a.col(1);
        return VectorXd((X + 10).square() + (Y + 10).square() + (-X.square() - Y.square()).exp());
    });
}

VectorXd brown(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    return apply_parallel(x, [n](const auto &a) {
        VectorXd scores = VectorXd::Zero(a.rows());
        for (int i = 0; i < n - 1; i++) {
            const auto xi = a.col(i);
            const auto xi_plus_1 = a.col(i + 1);
            scores.array() += (xi.square()).pow(xi_plus_1.square() + 1) +
                              (xi_plus_1.square()).pow(xi.square() + 1);
        }
        return scores;
    });
}

VectorXd bukinn2(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("The Bukin N. 2 function only accepts 2D inputs");
    return apply_parallel(x, [](const auto &a) {
        const auto X = a.col(0);
        const auto Y = a.col(1);
        return VectorXd(100 * (Y - 0.01 * X.square() + 1).square() + 0.01 * (X + 10).square());
    });
}

VectorXd bukinn4(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("The Bukin N. 4 function only accepts 2D inputs");
    return apply_parallel(x, [](const auto &a) {
        const auto X = a.col(0);
        const auto Y = a.col(1);
        return VectorXd(100 * Y.square() + 0.01 * (X + 10).abs());
    });
}

VectorXd bukinn6(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("The Bukin N. 6 function only accepts 2D inputs");
    return apply_parallel(x, [](const auto &a) {
        const auto X = a.col(0);
        const auto Y = a.col(1);
        return VectorXd(100 * (Y - 0.01 * X.square()).abs().sqrt() + 0.01 * (X + 10).abs());
    });
}

VectorXd carromtable(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("The Carrom Table function only accepts 2D inputs");
    return apply_parallel(x, [](const auto &a) {
        const auto X = a.col(0);
        const auto Y = a.col(1);
        return VectorXd(
            -((X.cos() * Y.cos() * (1 - (X.square() + Y.square()).sqrt() / M_PI).abs().exp())
                  .square() /
              30.0));
    });
}

VectorXd chichinadze(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("The Chichinadze function only accepts 2D inputs");
    return apply_parallel(x, [](const auto &a) {
        const auto X = a.col(0);
        const auto Y = a.col(1);
        return VectorXd(X.square() - 12 * X + 11 + 10 * (M_PI * X / 2.0).cos() +
                        8 * (5 * M_PI * X / 2.0).sin() -
                        (1.0 / sqrt(2.0 * M_PI)) * (-0.5 * (Y - 0.5).square()).exp());
    });
}

VectorXd cigar(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    return apply_parallel(x, [n](const auto &a) {
        VectorXd scores = a.col(0).square();
        if (n > 1) {
            scores += 1000000.0 * a.block(0, 1, a.rows(), n - 1).square().rowwise().sum().matrix();
        }
        return scores;
    });
}

VectorXd colville(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 4)
        throw std::invalid_argument("The Colville function only accepts 4D inputs.");
    return apply_parallel(x, [](const auto &a) {
        const auto X1 = a.col(0);
        const auto X2 = a.col(1);
        const auto X3 = a.col(2);
        const auto X4 = a.col(3);
        return VectorXd(100 * (X1.square() - X2).square() + (X1 - 1).square() + (X3 - 1).square() +
                        90 * (X3.square() - X4).square() +
                        10.1 * ((X2 - 1).square() + (X4 - 1).square()) +
                        19.8 * (X2 - 1) * (X4 - 1));
    });
}

VectorXd corana(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    VectorXd d_base(4);
    d_base << 1.0, 1000.0, 10.0, 100.0;
    VectorXd d(n);
    for (int i = 0; i < n; ++i)
        d(i) = d_base(i % 4);
    const RowVectorXd D_vec = d.transpose();

    return apply_parallel(x, [D_vec](const auto &a) {
        const int chunk_rows = a.rows();
        const auto D = D_vec.replicate(chunk_rows, 1).array();
        const auto x_abs = a.abs();
        const auto z_i = 0.2 * (x_abs / 0.2 + 0.49).floor() * a.sign();
        const auto diff_abs = (a - z_i).abs();
        const auto mask = (diff_abs < 0.05);
        const auto val1 = 0.15 * (z_i - 0.05 * z_i.sign()).square() * D;
        const auto val2 = D * a.square();
        const MatrixXd result = mask.select(val1, val2);
        return VectorXd(result.rowwise().sum());
    });
}

VectorXd cosinemixture(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    return apply_parallel(x, [](const auto &a) {
        return VectorXd(-0.1 * (a * (5 * M_PI)).cos().rowwise().sum() - a.square().rowwise().sum());
    });
}

VectorXd crossintray(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("The Cross-in-tray function only accepts 2D inputs");
    return apply_parallel(x, [](const auto &a) {
        const auto X = a.col(0);
        const auto Y = a.col(1);
        const VectorXd expcomponent = (100 - ((X.square() + Y.square()).sqrt() / M_PI)).abs();
        return VectorXd(-0.0001 *
                        ((X.sin() * Y.sin() * expcomponent.array().exp()).abs() + 1).pow(0.1));
    });
}

VectorXd crownedcross(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("The Crowned Cross function only accepts 2D inputs");
    return apply_parallel(x, [](const auto &a) {
        const auto X = a.col(0);
        const auto Y = a.col(1);
        const VectorXd expcomponent = (100 - ((X.square() + Y.square()).sqrt() / M_PI)).abs();
        return VectorXd(0.0001 *
                        ((X.sin() * Y.sin() * expcomponent.array().exp()).abs() + 1).pow(0.1));
    });
}

VectorXd csendes(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    return apply_parallel(x, [](const auto &a) {
        return VectorXd((a.pow(6) * (2 + (1.0 / a).sin())).rowwise().sum());
    });
}

VectorXd cubefcn(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("The Cube function only accepts 2D inputs");
    return apply_parallel(x, [](const auto &a) {
        const auto X = a.col(0);
        const auto Y = a.col(1);
        return VectorXd(100 * (Y - X.cube()).square() + (1 - X).square());
    });
}

VectorXd damavandi(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("The Damavandi function only accepts 2D inputs.");
    return apply_parallel(x, [](const auto &a) {
        const auto X1 = a.col(0);
        const auto X2 = a.col(1);
        auto num = (M_PI * (X1 - 2.0)).sin() * (M_PI * (X2 - 2.0)).sin();
        auto den = M_PI * M_PI * (X1 - 2.0) * (X2 - 2.0);
        auto ratio = (den.abs() < 1e-12).select(1.0, num / den);
        return VectorXd((1.0 - ratio.abs().pow(5.0)) *
                        (2.0 + (X1 - 7.0).square() + 2.0 * (X2 - 7.0).square()));
    });
}

VectorXd debn1(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    return apply_parallel(
        x, [](const auto &a) { return VectorXd(-((5 * M_PI * a).sin().pow(6).rowwise().sum())); });
}

VectorXd deckkersaarts(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("The Deckkers-Aarts function only accepts 2D inputs");
    return apply_parallel(x, [](const auto &a) {
        const auto X = a.col(0);
        const auto Y = a.col(1);
        const auto r2 = X.square() + Y.square();
        return VectorXd(1e5 * X.square() + Y.square() - r2.square() + 1e-5 * r2.pow(4));
    });
}

VectorXd dejongn5(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("De Jong's N. 5 function is only defined on a 2D space.");
    static constexpr double a_content[2][25] = {
        {-32, -16, 0,   16,  32, -32, -16, 0,   16,  32, -32, -16, 0,
         16,  32,  -32, -16, 0,  16,  32,  -32, -16, 0,  16,  32},
        {-32, -32, -32, -32, -32, -16, -16, -16, -16, -16, 0,  0, 0,
         0,   0,   16,  16,  16,  16,  16,  32,  32,  32,  32, 32}};
    const Matrix<double, 2, 25> A = Map<const Matrix<double, 2, 25, RowMajor>>(&a_content[0][0]);

    return apply_parallel(x, [A](const auto &a) {
        VectorXd inner_sum = VectorXd::Zero(a.rows());
        for (int i = 0; i < 25; ++i) {
            const auto diff1 = (a.col(0) - A(0, i)).pow(6);
            const auto diff2 = (a.col(1) - A(1, i)).pow(6);
            inner_sum.array() += 1.0 / (static_cast<double>(i + 1) + diff1 + diff2);
        }
        return VectorXd((0.002 + inner_sum.array()).pow(-1.0));
    });
}

VectorXd discus(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    return apply_parallel(x, [n](const auto &a) {
        VectorXd scores = 1e6 * a.col(0).square();
        if (n > 1) {
            scores += a.block(0, 1, a.rows(), n - 1).square().rowwise().sum().matrix();
        }
        return scores;
    });
}

VectorXd dixonprice(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    const RowVectorXd i_vec_full = RowVectorXd::LinSpaced(n - 1, 2, n);
    return apply_parallel(x, [n, i_vec_full](const auto &a) {
        const int m = a.rows();
        VectorXd scores = (a.col(0) - 1.0).square();
        if (n > 1) {
            const auto xi = a.block(0, 1, m, n - 1);
            const auto xi_prev = a.block(0, 0, m, n - 1);
            const auto i_vec = i_vec_full.replicate(m, 1).array();
            scores += (i_vec * (2.0 * xi.square() - xi_prev).square()).rowwise().sum().matrix();
        }
        return scores;
    });
}

VectorXd dropwave(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("The Drop Wave function only accepts 2D inputs");
    return apply_parallel(x, [](const auto &a) {
        const auto X2 = a.col(0).square();
        const auto Y2 = a.col(1).square();
        const auto r2 = X2 + Y2;
        return VectorXd(-(1 + (12 * r2.sqrt()).cos()) / (0.5 * r2 + 2));
    });
}

VectorXd easom(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("The Easom function only accepts 2D inputs");
    return apply_parallel(x, [](const auto &a) {
        const auto X = a.col(0);
        const auto Y = a.col(1);
        return VectorXd(-X.cos() * Y.cos() * (-((X - M_PI).square() + (Y - M_PI).square())).exp());
    });
}

VectorXd eggcrate(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("The Egg Crate function only accepts 2D inputs");
    return apply_parallel(x, [](const auto &a) {
        const auto X = a.col(0);
        const auto Y = a.col(1);
        return VectorXd(X.square() + Y.square() + 25 * (X.sin().square() + Y.sin().square()));
    });
}

VectorXd eggholder(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("The Eggholder function only accepts 2D inputs");
    return apply_parallel(x, [](const auto &a) {
        const auto X = a.col(0);
        const auto Y = a.col(1);
        return VectorXd(-(Y + 47) * ((X / 2.0 + Y + 47).abs().sqrt()).sin() -
                        X * ((X - (Y + 47)).abs().sqrt()).sin());
    });
}

VectorXd elattar(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("The El-Attar et al. function is only defined on a 2D space.");
    return apply_parallel(x, [](const auto &a) {
        const auto X = a.col(0);
        const auto Y = a.col(1);
        return VectorXd((X.square() + Y - 10).square() + (X + Y.square() - 7).square() +
                        (X.square() + Y.cube() - 1).square());
    });
}

VectorXd elliptic(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    VectorXd powers(n);
    for (int i = 0; i < n; ++i)
        powers(i) = std::pow(10.0, 6.0 * i / (n - 1.0));
    const RowVectorXd Coeffs_vec = powers.transpose();

    return apply_parallel(x, [Coeffs_vec](const auto &a) {
        return VectorXd((Coeffs_vec.replicate(a.rows(), 1).array() * a.square()).rowwise().sum());
    });
}

VectorXd exponential(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    return apply_parallel(x, [](const auto &a) {
        return VectorXd(-(-0.5 * a.square().rowwise().sum().array()).exp());
    });
}

VectorXd f8f2(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    return apply_parallel(x, [n](const auto &a) {
        VectorXd scores = VectorXd::Zero(a.rows());
        for (int i = 0; i < n; ++i) {
            int next = (i + 1) % n;
            const auto xi = a.col(i);
            const auto xnext = a.col(next);
            const VectorXd rosen = 100.0 * (xi.square() - xnext).square() + (xi - 1.0).square();
            scores += ((rosen.array().square() / 4000.0) - (rosen.array().cos()) + 1.0).matrix();
        }
        return scores;
    });
}

VectorXd forrester(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 1)
        throw std::invalid_argument("The Forrester function is only defined on a 1D space.");
    return apply_parallel(x, [](const auto &a) {
        const auto X = a.col(0);
        return VectorXd((6 * X - 2).square() * (12 * X - 4).sin());
    });
}

VectorXd foxholes(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("The Foxholes function only accepts 2D inputs");
    static constexpr double a_content[2][25] = {
        {-32, -16, 0,   16,  32, -32, -16, 0,   16,  32, -32, -16, 0,
         16,  32,  -32, -16, 0,  16,  32,  -32, -16, 0,  16,  32},
        {-32, -32, -32, -32, -32, -16, -16, -16, -16, -16, 0,  0, 0,
         0,   0,   16,  16,  16,  16,  16,  32,  32,  32,  32, 32}};
    const Matrix<double, 2, 25> a_mat =
        Map<const Matrix<double, 2, 25, RowMajor>>(&a_content[0][0]);

    return apply_parallel(x, [a_mat](const auto &a) {
        VectorXd scores = VectorXd::Zero(a.rows());
        for (int i = 0; i < 25; i++) {
            const auto diff1_6 = (a.col(0) - a_mat(0, i)).pow(6);
            const auto diff2_6 = (a.col(1) - a_mat(1, i)).pow(6);
            scores.array() += 1.0 / ((i + 1.0) + diff1_6 + diff2_6);
        }
        return VectorXd(1.0 / (0.002 + scores.array()));
    });
}

VectorXd friedman1(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, bool rnd) {
    if (x.cols() != 10)
        throw std::invalid_argument("The Friedman No. 1 function is only defined on a 10D space.");
    return apply_parallel(x, [rnd](const auto &a) {
        const auto x1 = a.col(0);
        const auto x2 = a.col(1);
        const auto x3 = a.col(2);
        const auto x4 = a.col(3);
        const auto x5 = a.col(4);
        const VectorXd term1 = 10 * (M_PI * x1 * x2).sin();
        const VectorXd term2 = 20 * (x3 - 0.5).square();
        const VectorXd term3 = 10 * x4;
        const VectorXd term4 = 5 * x5;
        VectorXd epsilon = VectorXd::Zero(a.rows());
        if (rnd)
            epsilon = VectorXd::Random(a.rows());
        return VectorXd(term1 + term2 + term3 + term4 + epsilon);
    });
}

VectorXd friedman2(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, double sigma) {
    if (x.cols() != 4)
        throw std::invalid_argument("The Friedman No. 2 function is only defined on a 4D space.");
    return apply_parallel(x, [sigma](const auto &a) {
        const auto x1 = a.col(0);
        const auto x2 = a.col(1);
        const auto x3 = a.col(2);
        const auto x4 = a.col(3);
        const VectorXd term_inner = (x2 * x3) - (1.0 / (x2 * x4));
        const VectorXd groundTruth = (x1.square() + term_inner.array().square()).sqrt();
        VectorXd epsilon = VectorXd::Zero(a.rows());
        if (sigma > 0)
            epsilon = sigma * VectorXd::Random(a.rows());
        return VectorXd(groundTruth + epsilon);
    });
}

VectorXd friedman3(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, double sigma) {
    if (x.cols() != 4)
        throw std::invalid_argument("The Friedman No. 3 function is only defined on a 4D space.");
    return apply_parallel(x, [sigma](const auto &a) {
        const auto x1 = a.col(0);
        const auto x2 = a.col(1);
        const auto x3 = a.col(2);
        const auto x4 = a.col(3);
        const VectorXd numerator = (x2 * x3) - (1.0 / (x2 * x4));
        const VectorXd groundTruth = (numerator.array() / x1).atan();
        VectorXd epsilon = VectorXd::Zero(a.rows());
        if (sigma > 0)
            epsilon = sigma * VectorXd::Random(a.rows());
        return VectorXd(groundTruth + epsilon);
    });
}

VectorXd gallagher101(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    std::mt19937 gen(101);
    std::uniform_real_distribution<double> dist_h(1.1, 9.1);
    std::uniform_real_distribution<double> dist_x(-4.0, 4.0);

    static bool initialized = false;
    static std::vector<double> w_vec;
    static std::vector<VectorXd> y_vec;
    static std::vector<MatrixXd> C_vec;

    if (!initialized) {
        w_vec.resize(101);
        y_vec.resize(101);
        C_vec.resize(101);
        w_vec[0] = 10.0;
        y_vec[0] = VectorXd::Zero(n);
        C_vec[0] = MatrixXd::Identity(n, n);
        for (int i = 1; i < 101; ++i) {
            w_vec[i] = dist_h(gen);
            y_vec[i] = VectorXd::Zero(n);
            for (int j = 0; j < n; ++j)
                y_vec[i](j) = dist_x(gen);
            VectorXd diag = VectorXd::Zero(n);
            for (int j = 0; j < n; ++j)
                diag(j) = std::pow(1000.0, 0.5 * static_cast<double>(j) / (n - 1.0));
            C_vec[i] = diag.asDiagonal();
        }
        initialized = true;
    }

    return apply_parallel(x, [n](const auto &a) {
        VectorXd max_vals = VectorXd::Zero(a.rows());
        for (int i = 0; i < 101; ++i) {
            MatrixXd diff = a.matrix().rowwise() - y_vec[i].transpose();
            VectorXd exponent =
                -0.5 / static_cast<double>(n) * (diff * C_vec[i]).array().square().rowwise().sum();
            max_vals = max_vals.cwiseMax((w_vec[i] * exponent.array().exp()).matrix());
        }
        return VectorXd(10.0 - max_vals.array());
    });
}

VectorXd gear(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 4)
        throw std::invalid_argument("The Gear function only accepts 4D inputs");
    return apply_parallel(x, [](const auto &a) {
        const auto x1 = a.col(0).floor();
        const auto x2 = a.col(1).floor();
        const auto x3 = a.col(2).floor();
        const auto x4 = a.col(3).floor();
        constexpr double target_ratio = 1.0 / 6.931;
        return VectorXd((target_ratio - (x1 * x2) / (x3 * x4)).square());
    });
}

VectorXd giunta(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    return apply_parallel(x, [](const auto &a) {
        return VectorXd(0.6 + ((1 - 16.0 / 15.0 * a).sin() + (1 - 16.0 / 15.0 * a).sin().square() +
                               1.0 / 50.0 * (4 * 16.0 / 15.0 * a).sin())
                                  .rowwise()
                                  .sum());
    });
}

VectorXd goldsteinprice(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("The Goldstein-Price function only accepts 2D inputs");
    return apply_parallel(x, [](const auto &a) {
        const auto X = a.col(0);
        const auto Y = a.col(1);
        const auto term1 = 1 + (X + Y + 1).square() * (19 - 14 * X + 3 * X.square() - 14 * Y +
                                                       6 * X * Y + 3 * Y.square());
        const auto term2 = 30 + (2 * X - 3 * Y).square() * (18 - 32 * X + 12 * X.square() + 48 * Y -
                                                            36 * X * Y + 27 * Y.square());
        return VectorXd(term1 * term2);
    });
}

VectorXd gramacylee(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 1)
        throw std::invalid_argument("The Gramacy & Lee function only accepts 1D inputs");
    return apply_parallel(x, [](const auto &a) {
        const auto X = a.col(0);
        return VectorXd(((10 * M_PI * X).sin() / (2 * X)) + (X - 1).pow(4));
    });
}

VectorXd griewank(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    const RowVectorXd i_vec = RowVectorXd::LinSpaced(n, 1, n).array().sqrt();
    return apply_parallel(x, [i_vec](const auto &a) {
        const int chunk_rows = a.rows();
        const VectorXd sum_comp = (a.square() / 4000.0).rowwise().sum();
        const MatrixXd cos_comp = (a / i_vec.replicate(chunk_rows, 1).array()).cos();
        const VectorXd prod_comp = cos_comp.rowwise().prod();
        return VectorXd(sum_comp.array() - prod_comp.array() + 1);
    });
}

VectorXd hansen(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("The Hansen function only accepts 2D inputs.");
    return apply_parallel(x, [](const auto &a) {
        const auto X1 = a.col(0);
        const auto X2 = a.col(1);
        VectorXd sum1 = VectorXd::Zero(a.rows());
        VectorXd sum2 = VectorXd::Zero(a.rows());
        for (int i = 1; i <= 5; ++i) {
            sum1 += i * ((i - 1) * X1 + i).cos().matrix();
            sum2 += i * ((i + 1) * X2 + i).cos().matrix();
        }
        return VectorXd(sum1.array() * sum2.array());
    });
}

VectorXd happycat(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, double alpha) {
    const int n = x.cols();
    return apply_parallel(x, [n, alpha](const auto &a) {
        const VectorXd x2 = a.square().rowwise().sum();
        const VectorXd sx = a.rowwise().sum();
        return VectorXd((x2.array() - n).square().pow(alpha) + (0.5 * x2.array() + sx.array()) / n +
                        0.5);
    });
}

VectorXd hartmann3(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 3)
        throw std::invalid_argument("The Hartmann 3 function only accepts 3D inputs");
    const VectorXd alpha = (VectorXd(4) << 1.0, 1.2, 3.0, 3.2).finished();
    const MatrixXd A =
        (MatrixXd(4, 3) << 3, 10, 30, 0.1, 10, 35, 3, 10, 30, 0.1, 10, 35).finished();
    const MatrixXd P = 1e-4 * (MatrixXd(4, 3) << 3689, 1170, 2673, 4699, 4387, 7470, 1091, 8732,
                               5547, 381, 5743, 8828)
                                  .finished();

    return apply_parallel(x, [alpha, A, P](const auto &a) {
        const int chunk_rows = a.rows();
        VectorXd scores = VectorXd::Zero(chunk_rows);
        for (int i = 0; i < 4; i++) {
            auto rowA = A.row(i);
            auto rowP = P.row(i);
            const VectorXd arg = (rowA.replicate(chunk_rows, 1).array() *
                                  (a.matrix().rowwise() - rowP).array().square())
                                     .rowwise()
                                     .sum();
            scores.array() -= alpha(i) * (-arg.array()).exp();
        }
        return scores;
    });
}

VectorXd hartmann6(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 6)
        throw std::invalid_argument("The Hartmann 6 function only accepts 6D inputs");
    const VectorXd alpha = (VectorXd(4) << 1.0, 1.2, 3.0, 3.2).finished();
    const MatrixXd A = (MatrixXd(4, 6) << 10, 3, 17, 3.5, 1.7, 8, 0.05, 10, 17, 0.1, 8, 14, 3, 3.5,
                        1.7, 10, 17, 8, 17, 8, 0.05, 10, 0.1, 14)
                           .finished();
    const MatrixXd P =
        1e-4 * (MatrixXd(4, 6) << 1312, 1696, 5569, 124, 8283, 5886, 2329, 4135, 8307, 3736, 1004,
                9991, 2348, 1451, 3522, 2883, 3047, 6650, 4047, 8828, 8732, 5743, 1091, 381)
                   .finished();

    return apply_parallel(x, [alpha, A, P](const auto &a) {
        const int chunk_rows = a.rows();
        VectorXd scores = VectorXd::Zero(chunk_rows);
        for (int i = 0; i < 4; ++i) {
            auto rowA = A.row(i);
            auto rowP = P.row(i);
            const VectorXd arg = (rowA.replicate(chunk_rows, 1).array() *
                                  (a.matrix().rowwise() - rowP).array().square())
                                     .rowwise()
                                     .sum();
            scores.array() -= alpha(i) * (-arg.array()).exp();
        }
        return scores;
    });
}

VectorXd ishigami(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, double a_param,
                  double b_param) {
    if (x.cols() != 3)
        throw std::invalid_argument("The Ishigami function is only defined on a 3D space.");
    return apply_parallel(x, [a_param, b_param](const auto &a) {
        const auto x1 = a.col(0);
        const auto x2 = a.col(1);
        const auto x3 = a.col(2);
        return VectorXd(x1.sin() + a_param * x2.sin().square() + b_param * x3.pow(4) * x1.sin());
    });
}

VectorXd himmelblau(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("The Himmelblau function only accepts 2D inputs");
    return apply_parallel(x, [](const auto &a) {
        const auto X = a.col(0);
        const auto Y = a.col(1);
        return VectorXd((X.square() + Y - 11).square() + (X + Y.square() - 7).square());
    });
}

VectorXd holdertable(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("The Holder Table function only accepts 2D inputs");
    return apply_parallel(x, [](const auto &a) {
        const auto X = a.col(0);
        const auto Y = a.col(1);
        return VectorXd(-(
            (X.sin() * Y.cos() * (1 - (X.square() + Y.square()).sqrt() / M_PI).abs().exp()).abs()));
    });
}

VectorXd hosaki(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("The Hosaki function only accepts 2D inputs");
    return apply_parallel(x, [](const auto &a) {
        const auto X = a.col(0);
        const auto Y = a.col(1);
        return VectorXd((1 - 8 * X + 7 * X.square() - 7.0 / 3.0 * X.cube() + 1.0 / 4.0 * X.pow(4)) *
                        Y.square() * (-Y).exp());
    });
}

VectorXd katsuura(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    const double n_inv_sq = 10.0 / (n * n);
    const double exp_val = 10.0 / std::pow(n, 1.2);
    const RowVectorXd i_vec_full = RowVectorXd::LinSpaced(n, 1, n);

    return apply_parallel(x, [n, n_inv_sq, exp_val, i_vec_full](const auto &a) {
        const int m = a.rows();
        MatrixXd inner_sum = MatrixXd::Zero(m, n);
        for (int j = 1; j <= 32; ++j) {
            const double two_pow_j = std::pow(2.0, j);
            const MatrixXd val = two_pow_j * a.matrix();
            inner_sum.array() += (val.array() - val.array().round()).abs() / two_pow_j;
        }
        const MatrixXd prod_terms = 1.0 + (inner_sum.array().rowwise() * i_vec_full.array());
        return VectorXd(n_inv_sq * (prod_terms.array().pow(exp_val).rowwise().prod() - 1.0));
    });
}

VectorXd keane(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("The Keane's function is only defined on a 2D space.");
    return apply_parallel(x, [](const auto &a) {
        const auto X = a.col(0);
        const auto Y = a.col(1);
        return VectorXd(-((X - Y).sin().square() * (X + Y).sin().square()) /
                        (X.square() + Y.square()).sqrt());
    });
}

VectorXd langermann(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("The Langermann function is only defined on a 2D space.");
    static constexpr double a_vals[5][2] = {{3, 5}, {5, 2}, {2, 1}, {1, 7}, {7, 9}};
    static constexpr double c_vals[5] = {1, 2, 5, 2, 3};

    return apply_parallel(x, [](const auto &a) {
        VectorXd scores = VectorXd::Zero(a.rows());
        for (int i = 0; i < 5; ++i) {
            const RowVectorXd ai = Map<const RowVectorXd>(a_vals[i], 2);
            const VectorXd sum_sq = (a.matrix().rowwise() - ai).array().square().rowwise().sum();
            scores.array() -=
                c_vals[i] * ((-1.0 / M_PI * sum_sq.array()).exp() * (M_PI * sum_sq.array()).cos());
        }
        return scores;
    });
}

VectorXd leon(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("The Leon function is only defined on a 2D space.");
    return apply_parallel(x, [](const auto &a) {
        const auto X = a.col(0);
        const auto Y = a.col(1);
        return VectorXd(100 * (Y - X.cube()).square() + (1 - X).square());
    });
}

VectorXd levin13(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("The Levi's function is only defined on a 2D space.");
    return apply_parallel(x, [](const auto &a) {
        const auto X = a.col(0);
        const auto Y = a.col(1);
        return VectorXd((3 * M_PI * X).sin().square() +
                        (X - 1).square() * (1 + (3 * M_PI * Y).sin().square()) +
                        (Y - 1).square() * (1 + (2 * M_PI * Y).sin().square()));
    });
}

VectorXd levy(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    return apply_parallel(x, [n](const auto &a) {
        const int m = a.rows();
        const auto w = 1.0 + (a - 1.0) / 4.0;
        const auto w_first = w.col(0);
        const auto w_last = w.col(n - 1);
        const VectorXd term1 = (M_PI * w_first).sin().square();
        const VectorXd term3 =
            (w_last - 1.0).square() * (1.0 + (2.0 * M_PI * w_last).sin().square());
        VectorXd scores = term1 + term3;
        if (n > 1) {
            const auto w_sub = w.block(0, 0, m, n - 1);
            const VectorXd term2 =
                ((w_sub - 1.0).square() * (1.0 + 10.0 * (M_PI * w_sub + 1.0).sin().square()))
                    .rowwise()
                    .sum();
            scores += term2;
        }
        return scores;
    });
}

VectorXd lunacekbirastrigin(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    const double mu0 = 2.5;
    const double s = 1.0 - (1.0 / (2.0 * std::sqrt(n + 20.0) - 8.2));
    const double mu1 = -std::sqrt((mu0 * mu0 - 1.0) / s);
    const double d = 1.0;

    return apply_parallel(x, [n, mu0, s, mu1, d](const auto &a) {
        const VectorXd sum_mu0 = (a - mu0).square().rowwise().sum();
        const VectorXd sum_mu1 = (a - mu1).square().rowwise().sum();
        const VectorXd deceptive_term =
            sum_mu0.cwiseMin(((s * sum_mu1).array() + (d * n)).matrix());
        const VectorXd rastrigin_term = 10.0 * (n - (2.0 * M_PI * (a - mu0)).cos().rowwise().sum());
        return VectorXd(deceptive_term + rastrigin_term);
    });
}

VectorXd matyas(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("The Matyas' function is only defined on a 2D space.");
    return apply_parallel(x, [](const auto &a) {
        const auto X = a.col(0);
        const auto Y = a.col(1);
        return VectorXd(0.26 * (X.square() + Y.square()) - 0.48 * X * Y);
    });
}

VectorXd mishrabird(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("Mishra's Bird function is only defined on a 2D space.");
    return apply_parallel(x, [](const auto &a) {
        const auto x1 = a.col(0);
        const auto x2 = a.col(1);
        return VectorXd(x2.sin() * (1.0 - x1.cos()).square().exp() +
                        x1.cos() * (1.0 - x2.sin()).square().exp() + (x1 - x2).square());
    });
}

VectorXd mccormick(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("The McCormick function is only defined on a 2D space.");
    return apply_parallel(x, [](const auto &a) {
        const auto X = a.col(0);
        const auto Y = a.col(1);
        return VectorXd((X + Y).sin() + (X - Y).square() - 1.5 * X + 2.5 * Y + 1);
    });
}

VectorXd michalewicz(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x,
                     double m_param) {
    const int n = x.cols();
    const RowVectorXd I_vec_full = RowVectorXd::LinSpaced(n, 1, n);
    return apply_parallel(x, [n, m_param, I_vec_full](const auto &a) {
        const int rows = a.rows();
        const MatrixXd I = I_vec_full.replicate(rows, 1);
        const MatrixXd term2 = (I.array() * a.square() / M_PI).sin().pow(2 * m_param);
        const MatrixXd result = a.matrix().array() * term2.array();
        return VectorXd(-result.rowwise().sum());
    });
}

VectorXd periodic(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    return apply_parallel(x, [](const auto &a) {
        const VectorXd sin2x = a.sin().square().rowwise().sum();
        const VectorXd sumx2 = a.square().rowwise().sum();
        return VectorXd(1 + sin2x.array() - 0.1 * (-sumx2.array()).exp());
    });
}

VectorXd perm(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, double beta) {
    const int n = x.cols();
    const RowVectorXd j_vals_full = RowVectorXd::LinSpaced(n, 1, n);
    return apply_parallel(x, [n, beta, j_vals_full](const auto &a) {
        const int m = a.rows();
        VectorXd scores = VectorXd::Zero(m);
        const MatrixXd j_vals = j_vals_full.replicate(m, 1);
        const MatrixXd xj_over_j = a.matrix().array() / j_vals.array();
        for (int i = 1; i <= n; ++i) {
            const MatrixXd j_pow_i = j_vals.array().pow(i);
            const MatrixXd inner_term = (j_pow_i.array() + beta) * (xj_over_j.array().pow(i) - 1.0);
            scores += inner_term.rowwise().sum().array().square().matrix();
        }
        return scores;
    });
}

VectorXd picheny(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("The Picheny function is only defined on a 2D space.");
    return apply_parallel(x, [](const auto &a) {
        const auto X = a.col(0);
        const auto Y = a.col(1);
        return VectorXd((X.square() + Y - 11).square() + (X + Y.square() - 7).square());
    });
}

VectorXd powellsingular(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 4)
        throw std::invalid_argument("The Powell Singular function is only defined on a 4D space.");
    return apply_parallel(x, [](const auto &a) {
        const auto x1 = a.col(0);
        const auto x2 = a.col(1);
        const auto x3 = a.col(2);
        const auto x4 = a.col(3);
        return VectorXd((x1 + 10.0 * x2).square() + 5.0 * (x3 - x4).square() +
                        (x2 - 2.0 * x3).pow(4) + 10.0 * (x1 - x4).pow(4));
    });
}

VectorXd powellsum(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    const RowVectorXd powers_full = RowVectorXd::LinSpaced(n, 2, n + 1);
    return apply_parallel(x, [powers_full](const auto &a) {
        return VectorXd(a.abs().pow(powers_full.replicate(a.rows(), 1).array()).rowwise().sum());
    });
}

VectorXd qing(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    const RowVectorXd I_vec_full = RowVectorXd::LinSpaced(n, 1, n);
    return apply_parallel(x, [I_vec_full](const auto &a) {
        const MatrixXd I = I_vec_full.replicate(a.rows(), 1);
        return VectorXd((a.square() - I.array()).square().rowwise().sum());
    });
}

VectorXd quartic(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    const RowVectorXd I_vec_full = RowVectorXd::LinSpaced(n, 1, n);
    return apply_parallel(x, [I_vec_full](const auto &a) {
        const MatrixXd I = I_vec_full.replicate(a.rows(), 1);
        return VectorXd((I.array() * a.pow(4)).rowwise().sum());
    });
}

VectorXd rana(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    return apply_parallel(x, [n](const auto &a) {
        VectorXd scores = VectorXd::Zero(a.rows());
        if (n < 2)
            return scores;
        for (int i = 0; i < n - 1; i++) {
            const auto xi = a.col(i);
            const auto xj = a.col(i + 1);
            const auto t1 = (xj + 1 - xi).abs().sqrt();
            const auto t2 = (xj + 1 + xi).abs().sqrt();
            scores.array() += xi * t1.sin() * t2.cos() + (xj + 1) * t1.cos() * t2.sin();
        }
        return scores;
    });
}

VectorXd rastrigin(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    return apply_parallel(x, [n](const auto &a) {
        return VectorXd(10 * n + (a.square() - 10 * (2 * M_PI * a).cos()).rowwise().sum());
    });
}

VectorXd rastrigin_parallel(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    return rastrigin(x);
}

VectorXd ridge(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, double d_param,
               double alpha_param) {
    const int n = x.cols();
    return apply_parallel(x, [n, d_param, alpha_param](const auto &a) {
        const auto x1 = a.col(0);
        VectorXd x_rest_sq = VectorXd::Zero(a.rows());
        if (n > 1) {
            x_rest_sq = a.block(0, 1, a.rows(), n - 1).square().rowwise().sum();
        }
        return VectorXd(x1 + d_param * (x_rest_sq.array().pow(alpha_param)));
    });
}

VectorXd rosenbrock(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    return apply_parallel(x, [n](const auto &a) {
        const int m = a.rows();
        const auto xi = a.block(0, 0, m, n - 1);
        const auto xi_plus_1 = a.block(0, 1, m, n - 1);
        return VectorXd(
            (100 * (xi_plus_1 - xi.square()).square() + (xi - 1).square()).rowwise().sum());
    });
}

VectorXd salomon(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    return apply_parallel(x, [](const auto &a) {
        const VectorXd sqrtsumx2 = a.square().rowwise().sum().array().sqrt();
        return VectorXd(1 - (2 * M_PI * sqrtsumx2.array()).cos() + 0.1 * sqrtsumx2.array());
    });
}

VectorXd schafferf6(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("The Schaffer F6 function is only defined on a 2D space.");
    return apply_parallel(x, [](const auto &a) {
        const auto X2 = a.col(0).square();
        const auto Y2 = a.col(1).square();
        const auto x2y2 = X2 + Y2;
        const VectorXd numerator = (x2y2.sqrt().sin().square()) - 0.5;
        const VectorXd denominator = (1.0 + 0.001 * x2y2).square();
        return VectorXd(0.5 + numerator.array() / denominator.array());
    });
}

VectorXd schafferf7(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    return apply_parallel(x, [n](const auto &a) {
        VectorXd scores = VectorXd::Zero(a.rows());
        for (int i = 0; i < n - 1; ++i) {
            const VectorXd si = (a.col(i).square() + a.col(i + 1).square()).sqrt();
            scores.array() +=
                si.array().sqrt() * ((50.0 * si.array().pow(0.2)).sin().square() + 1.0);
        }
        return scores;
    });
}

VectorXd schaffern1(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("The Schaffer N. 1 function is only defined on a 2D space.");
    return apply_parallel(x, [](const auto &a) {
        const auto X2 = a.col(0).square();
        const auto Y2 = a.col(1).square();
        const VectorXd num = ((X2 + Y2).square().sin().square()) - 0.5;
        const VectorXd den = (1 + 0.001 * (X2 + Y2)).square();
        return VectorXd(0.5 + num.array() / den.array());
    });
}

VectorXd schaffern2(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("The Schaffer N. 2 function is only defined on a 2D space.");
    return apply_parallel(x, [](const auto &a) {
        const auto X2 = a.col(0).square();
        const auto Y2 = a.col(1).square();
        const VectorXd num = ((X2 - Y2).sin().square()) - 0.5;
        const VectorXd den = (1 + 0.001 * (X2 + Y2)).square();
        return VectorXd(0.5 + num.array() / den.array());
    });
}

VectorXd schaffern3(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("The Schaffer N. 3 function is only defined on a 2D space.");
    return apply_parallel(x, [](const auto &a) {
        const auto X2 = a.col(0).square();
        const auto Y2 = a.col(1).square();
        const VectorXd num = (((X2 - Y2).abs().cos()).sin().square()) - 0.5;
        const VectorXd den = (1 + 0.001 * (X2 + Y2)).square();
        return VectorXd(0.5 + num.array() / den.array());
    });
}

VectorXd schaffern4(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("The Schaffer N. 4 function is only defined on a 2D space.");
    return apply_parallel(x, [](const auto &a) {
        const auto X2 = a.col(0).square();
        const auto Y2 = a.col(1).square();
        const VectorXd num = (((X2 - Y2).abs().sin()).cos().square()) - 0.5;
        const VectorXd den = (1 + 0.001 * (X2 + Y2)).square();
        return VectorXd(0.5 + num.array() / den.array());
    });
}

VectorXd schwefel(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    return apply_parallel(x, [n](const auto &a) {
        return VectorXd(418.9829 * n - (a * (a.abs().sqrt()).sin()).rowwise().sum());
    });
}

VectorXd schwefel220(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    return apply_parallel(x, [](const auto &a) { return VectorXd(a.abs().rowwise().sum()); });
}

VectorXd schwefel221(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    return apply_parallel(x, [](const auto &a) { return VectorXd(a.abs().rowwise().maxCoeff()); });
}

VectorXd schwefel222(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    return apply_parallel(x, [](const auto &a) {
        return VectorXd(a.abs().rowwise().sum() + a.abs().rowwise().prod());
    });
}

VectorXd schwefel223(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    return apply_parallel(x, [](const auto &a) { return VectorXd(a.pow(10).rowwise().sum()); });
}

VectorXd schwefel12(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    return apply_parallel(x, [n](const auto &a) {
        const int m = a.rows();
        MatrixXd cumsums = MatrixXd::Zero(m, n);
        cumsums.col(0) = a.col(0);
        for (int i = 1; i < n; ++i)
            cumsums.col(i) = cumsums.col(i - 1).array() + a.col(i);
        return VectorXd(cumsums.array().square().rowwise().sum());
    });
}

VectorXd shekel5(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const MatrixXd a_mat =
        (MatrixXd(5, 4) << 4, 4, 4, 4, 1, 1, 1, 1, 8, 8, 8, 8, 6, 6, 6, 6, 3, 7, 3, 7).finished();
    const VectorXd c_vec = (VectorXd(5) << 0.1, 0.2, 0.2, 0.4, 0.4).finished();
    return apply_parallel(x, [a_mat, c_vec](const auto &a) {
        VectorXd scores = VectorXd::Zero(a.rows());
        for (int i = 0; i < 5; i++) {
            scores.array() -=
                1.0 /
                ((a.matrix().rowwise() - a_mat.row(i)).array().square().rowwise().sum() + c_vec(i));
        }
        return scores;
    });
}

VectorXd shekel7(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const MatrixXd a_mat = (MatrixXd(7, 4) << 4, 4, 4, 4, 1, 1, 1, 1, 8, 8, 8, 8, 6, 6, 6, 6, 3, 7,
                            3, 7, 2, 9, 2, 9, 5, 5, 3, 3)
                               .finished();
    const VectorXd c_vec = (VectorXd(7) << 0.1, 0.2, 0.2, 0.4, 0.4, 0.6, 0.3).finished();
    return apply_parallel(x, [a_mat, c_vec](const auto &a) {
        VectorXd scores = VectorXd::Zero(a.rows());
        for (int i = 0; i < 7; i++) {
            scores.array() -=
                1.0 /
                ((a.matrix().rowwise() - a_mat.row(i)).array().square().rowwise().sum() + c_vec(i));
        }
        return scores;
    });
}

VectorXd shekel10(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const MatrixXd a_mat = (MatrixXd(10, 4) << 4, 4, 4, 4, 1, 1, 1, 1, 8, 8, 8, 8, 6, 6, 6, 6, 3, 7,
                            3, 7, 2, 9, 2, 9, 5, 5, 3, 3, 8, 1, 8, 1, 6, 2, 6, 2, 2, 5, 8, 2)
                               .finished();
    const VectorXd c_vec =
        (VectorXd(10) << 0.1, 0.2, 0.2, 0.4, 0.4, 0.6, 0.3, 0.7, 0.5, 0.5).finished();
    return apply_parallel(x, [a_mat, c_vec](const auto &a) {
        VectorXd scores = VectorXd::Zero(a.rows());
        for (int i = 0; i < 10; i++) {
            scores.array() -=
                1.0 /
                ((a.matrix().rowwise() - a_mat.row(i)).array().square().rowwise().sum() + c_vec(i));
        }
        return scores;
    });
}

VectorXd shubert(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    return apply_parallel(x, [n](const auto &a) {
        MatrixXd col_sums = MatrixXd::Zero(a.rows(), n);
        for (int j = 1; j <= 5; j++)
            col_sums.array() += j * (((j + 1.0) * a + j).cos());
        return VectorXd(col_sums.rowwise().prod());
    });
}

VectorXd shubertn3(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    return apply_parallel(x, [n](const auto &a) {
        MatrixXd col_sums = MatrixXd::Zero(a.rows(), n);
        for (int j = 1; j <= 5; j++)
            col_sums.array() += j * (((j + 1.0) * a + j).sin());
        return VectorXd(col_sums.rowwise().sum());
    });
}

VectorXd shubertn4(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    return apply_parallel(x, [n](const auto &a) {
        MatrixXd col_sums = MatrixXd::Zero(a.rows(), n);
        for (int j = 1; j <= 5; j++)
            col_sums.array() += (((j + 1.0) * a + j).cos());
        return VectorXd(col_sums.rowwise().sum());
    });
}

VectorXd sphere(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    return apply_parallel(x, [](const auto &a) { return VectorXd(a.square().rowwise().sum()); });
}

VectorXd step(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    return apply_parallel(
        x, [](const auto &a) { return VectorXd((a + 0.5).floor().square().rowwise().sum()); });
}

VectorXd stretchedvsine(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    return apply_parallel(x, [n](const auto &a) {
        VectorXd scores = VectorXd::Zero(a.rows());
        if (n < 2)
            return scores;
        for (int i = 0; i < n - 1; ++i) {
            const auto v = a.col(i).square() + a.col(i + 1).square();
            scores.array() += v.pow(0.25) * ((50.0 * v.pow(0.1)).sin().square() + 0.1);
        }
        return scores;
    });
}

VectorXd styblinskitank(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    return apply_parallel(x, [](const auto &a) {
        return VectorXd(0.5 * (a.pow(4) - 16 * a.square() + 5 * a).rowwise().sum());
    });
}

VectorXd sumsquares(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    const RowVectorXd I_vec_full = RowVectorXd::LinSpaced(n, 1, n);
    return apply_parallel(x, [I_vec_full](const auto &a) {
        return VectorXd((I_vec_full.replicate(a.rows(), 1).array() * a.square()).rowwise().sum());
    });
}

VectorXd threehumpcamel(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("The Three-hump Camel function only accepts 2D inputs");
    return apply_parallel(x, [](const auto &a) {
        const auto X = a.col(0);
        const auto Y = a.col(1);
        return VectorXd(2 * X.square() - 1.05 * X.pow(4) + X.pow(6) / 6.0 + X * Y + Y.square());
    });
}

VectorXd sixhumpcamel(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("The Six-hump Camel function only accepts 2D inputs");
    return apply_parallel(x, [](const auto &a) {
        const auto X = a.col(0);
        const auto Y = a.col(1);
        return VectorXd((4 - 2.1 * X.square() + X.pow(4) / 3.0) * X.square() + X * Y +
                        (-4 + 4 * Y.square()) * Y.square());
    });
}

VectorXd treccani(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("The Treccani function only accepts 2D inputs");
    return apply_parallel(x, [](const auto &a) {
        const auto X = a.col(0);
        const auto Y = a.col(1);
        return VectorXd(X.pow(4) - 4 * X.cube() + 4 * X.square() + Y.square());
    });
}

VectorXd trid(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    return apply_parallel(x, [n](const auto &a) {
        const int m = a.rows();
        VectorXd scores = (a - 1).square().rowwise().sum();
        if (n > 1)
            scores -= (a.block(0, 1, m, n - 1) * a.block(0, 0, m, n - 1)).rowwise().sum().matrix();
        return scores;
    });
}

VectorXd vincent(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    return apply_parallel(
        x, [](const auto &a) { return VectorXd(-((10 * a.sqrt()).sin()).rowwise().sum()); });
}

VectorXd watson(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    if (n != 6)
        throw std::invalid_argument("The Watson function only accepts 6D inputs");
    return apply_parallel(x, [n](const auto &a) {
        const int m = a.rows();
        VectorXd scores = VectorXd::Zero(m);
        for (int i = 0; i < 31; i++) {
            const double ti = i / 29.0;
            VectorXd sum1 = VectorXd::Zero(m);
            for (int j = 1; j < n; j++)
                sum1.array() += j * a.col(j) * pow(ti, j - 1);
            VectorXd sum2 = VectorXd::Zero(m);
            for (int j = 0; j < n; j++)
                sum2.array() += a.col(j) * pow(ti, j);
            scores += (sum1.array() - sum2.array().square() - 1.0).square().matrix();
        }
        scores += a.col(0).square().matrix();
        scores += (a.col(1) - a.col(0).square() - 1.0).square().matrix();
        return scores;
    });
}

VectorXd wavy(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, double k) {
    const int n = x.cols();
    return apply_parallel(x, [n, k](const auto &a) {
        return VectorXd(1 - ((k * a).cos() * (-a.square() / 2.0).exp()).rowwise().sum() /
                                static_cast<double>(n));
    });
}

VectorXd wayburnseadern2(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("The Wayburn-Seader N. 02 function only accepts 2D inputs");
    return apply_parallel(x, [](const auto &a) {
        const auto X = a.col(0);
        const auto Y = a.col(1);
        return VectorXd((1.613 - 4 * (X - 0.3125).square() - 4 * (Y - 1.625).square()).square() +
                        (Y - 1).square());
    });
}

VectorXd whitley(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    return apply_parallel(x, [n](const auto &a) {
        const int m = a.rows();
        VectorXd scores = VectorXd::Zero(m);
        for (int i = 0; i < n; ++i) {
            const auto xi = a.col(i);
            for (int j = 0; j < n; ++j) {
                const auto xj = a.col(j);
                const VectorXd temp = 100.0 * (xi.square() - xj).square() + (1.0 - xj).square();
                scores += ((temp.array().square() / 4000.0) - temp.array().cos() + 1.0).matrix();
            }
        }
        return scores;
    });
}

VectorXd weierstrass(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &X, double a_param,
                     double b_param, int kmax) {
    const int n = X.cols();
    VectorXd k_vec = VectorXd::LinSpaced(kmax + 1, 0, kmax);
    const ArrayXd a_k = ArrayXd::Constant(kmax + 1, a_param).pow(k_vec.array());
    const ArrayXd b_k = ArrayXd::Constant(kmax + 1, b_param).pow(k_vec.array());
    const double second_sum_term = n * (a_k * (M_PI * b_k).cos()).sum();

    return apply_parallel(X, [n, a_k, b_k, second_sum_term, kmax](const auto &a) {
        const int num_rows = a.rows();
        MatrixXd term1_sum_k = MatrixXd::Zero(num_rows, n);
        for (int k = 0; k <= kmax; ++k) {
            term1_sum_k += a_k(k) * (2 * M_PI * b_k(k) * (a + 0.5)).cos().matrix();
        }
        return VectorXd(term1_sum_k.rowwise().sum().array() - second_sum_term);
    });
}

VectorXd wolfe(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 3)
        throw std::invalid_argument("Wolfe is 3D only");
    return apply_parallel(x, [](const auto &a) {
        const auto X = a.col(0);
        const auto Y = a.col(1);
        const auto Z = a.col(2);
        return VectorXd((4.0 / 3.0) * (X.square() + Y.square() - X * Y).pow(0.75) + Z);
    });
}

VectorXd xinsheyangn1(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    const RowVectorXd exponents_full = RowVectorXd::LinSpaced(n, 1, n);
    return apply_parallel(x, [exponents_full](const auto &a) {
        const int rows = a.rows();
        const MatrixXd rand_values = (MatrixXd::Random(rows, a.cols()).array() + 1) / 2.0;
        return VectorXd(
            (rand_values.array() * a.abs().pow(exponents_full.replicate(rows, 1).array()))
                .rowwise()
                .sum());
    });
}

VectorXd xinsheyangn2(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    return apply_parallel(x, [](const auto &a) {
        return VectorXd(a.abs().rowwise().sum().array() *
                        (-a.square().sin().rowwise().sum().array()).exp());
    });
}

VectorXd xinsheyangn3(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, double beta,
                      double m_param) {
    return apply_parallel(x, [beta, m_param](const auto &a) {
        const VectorXd sum1 = (-(a / beta).pow(2 * m_param)).rowwise().sum().array().exp();
        const VectorXd sum2 = (-a.square()).rowwise().sum().array().exp();
        const VectorXd prod1 = (a.cos().square()).rowwise().prod();
        return VectorXd(sum1.array() - 2 * sum2.array() * prod1.array());
    });
}

VectorXd xinsheyangn4(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    return apply_parallel(x, [](const auto &a) {
        const VectorXd s1 = a.sin().square().rowwise().sum();
        const VectorXd s2 = (-a.square()).rowwise().sum().array().exp();
        const VectorXd s3 = (-a.abs().sqrt().sin().square()).rowwise().sum().array().exp();
        return VectorXd((s1.array() - s2.array()) * s3.array());
    });
}

VectorXd zakharov(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    const RowVectorXd I_vec_full = RowVectorXd::LinSpaced(n, 1, n);
    return apply_parallel(x, [I_vec_full](const auto &a) {
        const VectorXd s1 = a.square().rowwise().sum();
        const MatrixXd I = I_vec_full.replicate(a.rows(), 1);
        const VectorXd s2 = (0.5 * I.array() * a).rowwise().sum();
        return VectorXd(s1.array() + s2.array().square() + s2.array().pow(4));
    });
}

VectorXd zerosum(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    return apply_parallel(x, [](const auto &a) {
        const VectorXd s = a.rowwise().sum();
        VectorXd scores = 1.0 + (10000 * s.array().abs()).sqrt();
        return scores.unaryExpr([](double v) { return v == 1.0 ? 0.0 : v; });
    });
}

VectorXd zettel(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("Zettel is 2D only");
    return apply_parallel(x, [](const auto &a) {
        const auto X = a.col(0);
        const auto Y = a.col(1);
        return VectorXd(0.25 * X - (X.square() - 2 * X + Y.square()).square());
    });
}

VectorXd zimmerman(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("Zimmerman is 2D only");
    return apply_parallel(x, [](const auto &a) {
        const auto X = a.col(0);
        const auto Y = a.col(1);
        const VectorXd zh1 = 9 - X - Y;
        const VectorXd zh2 = (X - 3).square() + (Y - 2).square() - 16;
        const VectorXd zh3 = X * Y - 14;
        auto zp = [](const VectorXd &v) { return 100 * (1 + v.array()); };
        MatrixXd signs(a.rows(), 5);
        signs.col(0) = zh1;
        signs.col(1) = zp(zh2).array() * zh2.array().sign();
        signs.col(2) = zp(zh3).array() * zh3.array().sign();
        signs.col(3) = zp(-X).array() * (X).array().sign();
        signs.col(4) = zp(-Y).array() * (Y).array().sign();
        return VectorXd(signs.rowwise().maxCoeff());
    });
}

VectorXd zirilli(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("Zirilli is 2D only");
    return apply_parallel(x, [](const auto &a) {
        const auto X = a.col(0);
        const auto Y = a.col(1);
        return VectorXd(0.25 * X.pow(4) - 0.5 * X.square() + 0.1 * X + 0.5 * Y.square());
    });
}

} // namespace BenchmarkFcns
