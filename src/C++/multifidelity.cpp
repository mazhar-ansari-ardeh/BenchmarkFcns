#include "multifidelity.h"
#include "benchmarkfcns.h"
#include "utils.h"
#include <iostream>

namespace BenchmarkFcns::MultiFidelity {

using namespace Eigen;

MatrixXd ackley(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    return apply_parallel(x, [](const auto &a) {
        const int n = a.cols();
        const VectorXd sum1 = a.square().rowwise().sum();
        const VectorXd sum2 = (2.0 * M_PI * a).cos().rowwise().sum();
        const VectorXd hf = (-(20.0 * (-0.2 * (sum1.array() / n).sqrt()).exp()) + 20.0 -
                             (sum2.array() / n).exp() + std::exp(1.0))
                                .matrix();

        // LF: perturbed parameters
        const VectorXd lf =
            (-(18.0 * (-0.18 * (sum1.array() / n).sqrt()).exp()) + 18.0 - (sum2.array() / n).exp() +
             std::exp(1.0) + 0.1 * a.rowwise().sum().array())
                .matrix();

        MatrixXd res(a.rows(), 2);
        res.col(0) = hf;
        res.col(1) = lf;
        return res;
    });
}

MatrixXd adjiman(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("The multi-fidelity Adjiman function only accepts 2D inputs.");
    return apply_parallel(x, [](const auto &a) {
        const auto X = a.col(0);
        const auto Y = a.col(1);
        const VectorXd hf = ((X.cos() * Y.sin()) - (X / (Y.square() + 1.0))).matrix();
        const VectorXd lf = (0.8 * hf.array() + 0.1 * X + 0.1 * Y).matrix();

        MatrixXd res(a.rows(), 2);
        res.col(0) = hf;
        res.col(1) = lf;
        return res;
    });
}

MatrixXd alpinen1(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    return apply_parallel(x, [](const auto &a) {
        const VectorXd hf = (a * a.sin() + 0.1 * a).rowwise().sum().array().abs().matrix();
        const VectorXd lf = ((a * a.sin() + 0.2 * a).rowwise().sum().array().abs() * 0.5 +
                             0.1 * a.rowwise().sum().array())
                                .matrix();

        MatrixXd res(a.rows(), 2);
        res.col(0) = hf;
        res.col(1) = lf;
        return res;
    });
}

MatrixXd bartelsconn(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument(
            "The multi-fidelity Bartels Conn function only accepts 2D inputs.");
    return apply_parallel(x, [](const auto &a) {
        const auto X = a.col(0);
        const auto Y = a.col(1);
        const VectorXd hf =
            ((X.square() + Y.square() + X * Y).abs() + X.sin().abs() + Y.cos().abs()).matrix();
        const VectorXd lf = (0.7 * hf.array() + 0.1 * (X + Y)).matrix();

        MatrixXd res(a.rows(), 2);
        res.col(0) = hf;
        res.col(1) = lf;
        return res;
    });
}

MatrixXd beale(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("The multi-fidelity Beale function only accepts 2D inputs.");
    return apply_parallel(x, [](const auto &a) {
        const auto X = a.col(0);
        const auto Y = a.col(1);
        const VectorXd hf = ((1.5 - X + (X * Y)).square() + (2.25 - X + (X * Y.square())).square() +
                             (2.625 - X + (X * Y.cube())).square())
                                .matrix();
        const VectorXd lf = (0.5 * hf.array() + 0.1 * (X + Y)).matrix();

        MatrixXd res(a.rows(), 2);
        res.col(0) = hf;
        res.col(1) = lf;
        return res;
    });
}

MatrixXd bentcigar(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    return apply_parallel(x, [n](const auto &a) {
        const VectorXd x1_sq = a.col(0).square().matrix();
        VectorXd x_rest_sq = VectorXd::Zero(a.rows());
        if (n > 1) {
            x_rest_sq = a.block(0, 1, a.rows(), n - 1).square().rowwise().sum();
        }
        const VectorXd hf = x1_sq + 1e6 * x_rest_sq;
        const VectorXd lf =
            (x1_sq.array() + 1e5 * x_rest_sq.array() + 0.1 * a.rowwise().sum().array()).matrix();

        MatrixXd res(a.rows(), 2);
        res.col(0) = hf;
        res.col(1) = lf;
        return res;
    });
}

MatrixXd bird(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("The multi-fidelity Bird function only accepts 2D inputs.");
    return apply_parallel(x, [](const auto &a) {
        const auto X = a.col(0);
        const auto Y = a.col(1);
        const VectorXd hf = ((X.sin() * (1.0 - Y.cos()).square().exp()) +
                             (Y.cos() * (1.0 - X.sin()).square().exp()) + (X - Y).square())
                                .matrix();
        const VectorXd lf = (0.5 * hf.array() + 0.1 * (X + Y)).matrix();

        MatrixXd res(a.rows(), 2);
        res.col(0) = hf;
        res.col(1) = lf;
        return res;
    });
}

MatrixXd bohachevskyn1(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument(
            "The multi-fidelity Bohachevsky N. 1 function only accepts 2D inputs.");
    return apply_parallel(x, [](const auto &a) {
        const auto X = a.col(0);
        const auto Y = a.col(1);
        const VectorXd hf = (X.square() + 2.0 * Y.square() - 0.3 * (3.0 * M_PI * X).cos() -
                             0.4 * (4.0 * M_PI * Y).cos() + 0.7)
                                .matrix();
        const VectorXd lf = (0.5 * hf.array() + 0.1 * (X + Y)).matrix();

        MatrixXd res(a.rows(), 2);
        res.col(0) = hf;
        res.col(1) = lf;
        return res;
    });
}

MatrixXd booth(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("The multi-fidelity Booth function only accepts 2D inputs.");

    return apply_parallel(x, [](const auto &a) {
        const auto X = a.col(0);
        const auto Y = a.col(1);

        const VectorXd hf = ((X + 2.0 * Y - 7.0).square() + (2.0 * X + Y - 5.0).square()).matrix();
        const VectorXd lf = ((0.4 * X + 2.0 * Y - 7.0).square() +
                             (2.0 * 0.4 * X + Y - 5.0).square() + 1.7 * X * Y - X + 2.0 * Y)
                                .matrix();

        MatrixXd res(a.rows(), 2);
        res.col(0) = hf;
        res.col(1) = lf;
        return res;
    });
}

MatrixXd borehole(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 8)
        throw std::invalid_argument(
            "The multi-fidelity Borehole function is only defined on an 8D space.");

    return apply_parallel(x, [](const auto &a) {
        const auto rw = a.col(0);
        const auto r = a.col(1);
        const auto Tu = a.col(2);
        const auto Hu = a.col(3);
        const auto Tl = a.col(4);
        const auto Hl = a.col(5);
        const auto L = a.col(6);
        const auto Kw = a.col(7);

        const auto lnr_rw = (r.array() / rw.array()).log();
        const auto common_denom_part =
            (2.0 * L.array() * Tu.array()) / (lnr_rw * rw.array().square() * Kw.array());

        const VectorXd hf = ((2.0 * M_PI * Tu.array() * (Hu - Hl).array()) /
                             (lnr_rw * (1.0 + common_denom_part + Tu.array() / Tl.array())))
                                .matrix();
        const VectorXd lf = ((5.0 * Tu.array() * (Hu - Hl).array()) /
                             (lnr_rw * (1.5 + common_denom_part + Tu.array() / Tl.array())))
                                .matrix();

        MatrixXd res(a.rows(), 2);
        res.col(0) = hf;
        res.col(1) = lf;
        return res;
    });
}

MatrixXd branin(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("The multi-fidelity Branin function only accepts 2D inputs.");

    auto branin_hf_internal = [](const auto &X1, const auto &X2) {
        const double a_coeff = 1.0;
        const double b = 5.1 / (4.0 * M_PI * M_PI);
        const double c = 5.0 / M_PI;
        const double r = 6.0;
        const double s = 10.0;
        const double t = 1.0 / (8.0 * M_PI);
        return (a_coeff * (X2 - b * X1.square() + c * X1 - r).square() + s * (1.0 - t) * X1.cos() +
                s);
    };

    return apply_parallel(x, [branin_hf_internal](const auto &a) {
        const auto X1 = a.col(0);
        const auto X2 = a.col(1);

        const VectorXd hf = branin_hf_internal(X1, X2).matrix();
        const VectorXd lf =
            (10.0 * branin_hf_internal(1.2 * X1, 1.2 * X2) + 5.0 * X1 + 10.0 * X2).matrix();

        MatrixXd res(a.rows(), 2);
        res.col(0) = hf;
        res.col(1) = lf;
        return res;
    });
}

MatrixXd brown(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    return apply_parallel(x, [n](const auto &a) {
        VectorXd hf = VectorXd::Zero(a.rows());
        for (int i = 0; i < n - 1; i++) {
            const auto xi = a.col(i);
            const auto xi_plus_1 = a.col(i + 1);
            hf.array() += (xi.square()).pow(xi_plus_1.square() + 1.0) +
                          (xi_plus_1.square()).pow(xi.square() + 1.0);
        }
        const VectorXd lf = (0.5 * hf.array() + 0.1 * a.rowwise().sum().array()).matrix();

        MatrixXd res(a.rows(), 2);
        res.col(0) = hf;
        res.col(1) = lf;
        return res;
    });
}

MatrixXd bukinn6(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument(
            "The multi-fidelity Bukin N. 6 function only accepts 2D inputs.");
    return apply_parallel(x, [](const auto &a) {
        const auto X = a.col(0);
        const auto Y = a.col(1);
        const VectorXd hf =
            (100.0 * (Y - 0.01 * X.square()).abs().sqrt() + 0.01 * (X + 10.0).abs()).matrix();
        const VectorXd lf =
            (80.0 * (Y - 0.01 * X.square()).abs().sqrt() + 0.02 * (X + 10.0).abs() + 0.1 * X)
                .matrix();

        MatrixXd res(a.rows(), 2);
        res.col(0) = hf;
        res.col(1) = lf;
        return res;
    });
}

MatrixXd crossintray(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument(
            "The multi-fidelity Cross-in-tray function only accepts 2D inputs.");
    return apply_parallel(x, [](const auto &a) {
        const auto X = a.col(0);
        const auto Y = a.col(1);
        const VectorXd expcomponent = (100.0 - ((X.square() + Y.square()).sqrt() / M_PI)).abs();
        const VectorXd hf =
            (-0.0001 * ((X.sin() * Y.sin() * expcomponent.array().exp()).abs() + 1.0).pow(0.1))
                .matrix();
        const VectorXd lf = (0.5 * hf.array() + 0.1 * (X + Y)).matrix();

        MatrixXd res(a.rows(), 2);
        res.col(0) = hf;
        res.col(1) = lf;
        return res;
    });
}

MatrixXd currin(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("The multi-fidelity Currin function only accepts 2D inputs.");

    auto currin_hf_internal = [](const auto &X1, const auto &X2) {
        const auto term1 = 1.0 - (-1.0 / (2.0 * X2.array())).exp();
        const auto num =
            2300.0 * X1.array().cube() + 1900.0 * X1.array().square() + 2092.0 * X1.array() + 60.0;
        const auto den =
            100.0 * X1.array().cube() + 500.0 * X1.array().square() + 4.0 * X1.array() + 20.0;
        return (term1 * (num / den));
    };

    return apply_parallel(x, [currin_hf_internal](const auto &a) {
        const auto X1 = a.col(0);
        const auto X2 = a.col(1);

        const VectorXd hf = currin_hf_internal(X1, X2).matrix();
        const VectorXd lf =
            (0.25 *
             (currin_hf_internal(X1.array() + 0.05, X2.array() + 0.05) +
              currin_hf_internal(X1.array() + 0.05, (X2.array() - 0.05).max(1e-6)) +
              currin_hf_internal((X1.array() - 0.05).max(0.0), X2.array() + 0.05) +
              currin_hf_internal((X1.array() - 0.05).max(0.0), (X2.array() - 0.05).max(1e-6))))
                .matrix();

        MatrixXd res(a.rows(), 2);
        res.col(0) = hf;
        res.col(1) = lf;
        return res;
    });
}

MatrixXd discus(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    return apply_parallel(x, [n](const auto &a) {
        const VectorXd hf = (1e6 * a.col(0).square().array() +
                             a.block(0, 1, a.rows(), n - 1).square().rowwise().sum().array())
                                .matrix();
        const VectorXd lf = (1e5 * a.col(0).square().array() +
                             a.block(0, 1, a.rows(), n - 1).square().rowwise().sum().array() +
                             0.1 * a.rowwise().sum().array())
                                .matrix();

        MatrixXd res(a.rows(), 2);
        res.col(0) = hf;
        res.col(1) = lf;
        return res;
    });
}

MatrixXd dixonprice(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    const RowVectorXd i_vec_full = RowVectorXd::LinSpaced(n - 1, 2, n);
    return apply_parallel(x, [n, i_vec_full](const auto &a) {
        const int m = a.rows();
        VectorXd hf = (a.col(0) - 1.0).square().matrix();
        if (n > 1) {
            const auto xi = a.block(0, 1, m, n - 1);
            const auto xi_prev = a.block(0, 0, m, n - 1);
            const auto i_vec = i_vec_full.replicate(m, 1).array();
            hf += (i_vec * (2.0 * xi.square() - xi_prev).square()).rowwise().sum().matrix();
        }
        const VectorXd lf = (0.5 * hf.array() + 0.1 * a.rowwise().sum().array()).matrix();

        MatrixXd res(m, 2);
        res.col(0) = hf;
        res.col(1) = lf;
        return res;
    });
}

MatrixXd easom(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("The multi-fidelity Easom function only accepts 2D inputs.");
    return apply_parallel(x, [](const auto &a) {
        const auto X = a.col(0);
        const auto Y = a.col(1);
        const VectorXd hf =
            (-X.cos() * Y.cos() * (-((X - M_PI).square() + (Y - M_PI).square())).exp()).matrix();
        const VectorXd lf = (0.5 * hf.array() + 0.1 * (X + Y)).matrix();

        MatrixXd res(a.rows(), 2);
        res.col(0) = hf;
        res.col(1) = lf;
        return res;
    });
}

MatrixXd eggholder(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument(
            "The multi-fidelity Eggholder function only accepts 2D inputs.");
    return apply_parallel(x, [](const auto &a) {
        const auto X = a.col(0);
        const auto Y = a.col(1);
        const VectorXd hf = (-(Y + 47.0) * ((X / 2.0 + Y + 47.0).abs().sqrt()).sin() -
                             X * ((X - (Y + 47.0)).abs().sqrt()).sin())
                                .matrix();
        const VectorXd lf = (0.5 * hf.array() + 0.1 * (X + Y)).matrix();

        MatrixXd res(a.rows(), 2);
        res.col(0) = hf;
        res.col(1) = lf;
        return res;
    });
}

MatrixXd elliptic(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    VectorXd powers(n);
    for (int i = 0; i < n; ++i)
        powers(i) = std::pow(10.0, 6.0 * i / (n - 1.0));
    const RowVectorXd Coeffs_vec = powers.transpose();

    return apply_parallel(x, [Coeffs_vec](const auto &a) {
        const VectorXd hf =
            (Coeffs_vec.replicate(a.rows(), 1).array() * a.square()).rowwise().sum().matrix();
        const VectorXd lf = (0.5 * hf.array() + 0.1 * a.rowwise().sum().array()).matrix();

        MatrixXd res(a.rows(), 2);
        res.col(0) = hf;
        res.col(1) = lf;
        return res;
    });
}

MatrixXd forrester(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 1)
        throw std::invalid_argument(
            "The multi-fidelity Forrester function only accepts 1D inputs.");

    return apply_parallel(x, [](const auto &a) {
        const auto X = a.col(0);
        const VectorXd f_hf = ((6.0 * X - 2.0).square() * (12.0 * X - 4.0).sin()).matrix();
        const VectorXd f_lf = (0.5 * f_hf.array() + 10.0 * (X - 0.5) + 5.0).matrix();

        MatrixXd res(a.rows(), 2);
        res.col(0) = f_hf;
        res.col(1) = f_lf;
        return res;
    });
}

MatrixXd friedman(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 5)
        throw std::invalid_argument(
            "The multi-fidelity Friedman function is only defined on a 5D space.");

    return apply_parallel(x, [](const auto &a) {
        const auto x1 = a.col(0);
        const auto x2 = a.col(1);
        const auto x3 = a.col(2);
        const auto x4 = a.col(3);
        const auto x5 = a.col(4);

        const auto common = 10.0 * (M_PI * x1 * x2).sin() + 20.0 * (x3 - 0.5).square();

        const VectorXd hf = (common + 10.0 * x4 + 5.0 * x5).matrix();
        const VectorXd lf = (common + 5.0 * x4 + 2.5 * x5).matrix();

        MatrixXd res(a.rows(), 2);
        res.col(0) = hf;
        res.col(1) = lf;
        return res;
    });
}

MatrixXd gano(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("The multi-fidelity Gano function only accepts 2D inputs.");

    return apply_parallel(x, [](const auto &a) {
        const auto x1 = a.col(0);
        const auto x2 = a.col(1);

        const VectorXd f_hf = (4.0 * x1.square() + x2.cube() + x1 * x2).matrix();
        const VectorXd g_hf = (1.0 / x1 + 1.0 / x2 - 2.0).matrix();

        const VectorXd f_lf =
            (4.0 * (x1 + 0.1).square() + (x2 - 0.1).pow(3.0) + x1 * x2 + 0.1).matrix();
        const VectorXd g_lf = (1.0 / x1 + 1.0 / (x2 + 0.1) - 2.0 - 0.001).matrix();

        MatrixXd res(a.rows(), 4);
        res.col(0) = f_hf;
        res.col(1) = g_hf;
        res.col(2) = f_lf;
        res.col(3) = g_lf;
        return res;
    });
}

MatrixXd goldsteinprice(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument(
            "The multi-fidelity Goldstein-Price function only accepts 2D inputs.");
    return apply_parallel(x, [](const auto &a) {
        const auto X = a.col(0);
        const auto Y = a.col(1);
        const auto term1 =
            1.0 + (X + Y + 1.0).square() * (19.0 - 14.0 * X + 3.0 * X.square() - 14.0 * Y +
                                            6.0 * X * Y + 3.0 * Y.square());
        const auto term2 =
            30.0 + (2.0 * X - 3.0 * Y).square() * (18.0 - 32.0 * X + 12.0 * X.square() + 48.0 * Y -
                                                   36.0 * X * Y + 27.0 * Y.square());
        const VectorXd hf = (term1 * term2).matrix();
        const VectorXd lf = (0.5 * hf.array() + 0.1 * (X + Y)).matrix();

        MatrixXd res(a.rows(), 2);
        res.col(0) = hf;
        res.col(1) = lf;
        return res;
    });
}

MatrixXd griewank(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    const RowVectorXd i_vec = RowVectorXd::LinSpaced(n, 1, n).array().sqrt();
    return apply_parallel(x, [i_vec](const auto &a) {
        const int chunk_rows = a.rows();
        const VectorXd sum_comp = (a.square() / 4000.0).rowwise().sum().matrix();
        const MatrixXd cos_comp = (a / i_vec.replicate(chunk_rows, 1).array()).cos();
        const VectorXd prod_comp = cos_comp.rowwise().prod().matrix();
        const VectorXd hf = sum_comp.array() - prod_comp.array() + 1.0;
        const VectorXd lf = (0.5 * hf.array() + 0.1 * a.rowwise().sum().array()).matrix();

        MatrixXd res(chunk_rows, 2);
        res.col(0) = hf;
        res.col(1) = lf;
        return res;
    });
}

MatrixXd happycat(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    return apply_parallel(x, [n](const auto &a) {
        const VectorXd x2 = a.square().rowwise().sum().matrix();
        const VectorXd sx = a.rowwise().sum().matrix();
        const VectorXd hf =
            ((x2.array() - n).square().pow(0.5) + (0.5 * x2.array() + sx.array()) / n + 0.5)
                .matrix();
        const VectorXd lf =
            ((x2.array() - n).square().pow(0.4) + (0.4 * x2.array() + sx.array()) / n + 0.5)
                .matrix();

        MatrixXd res(a.rows(), 2);
        res.col(0) = hf;
        res.col(1) = lf;
        return res;
    });
}

MatrixXd heterogeneous(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 1)
        throw std::invalid_argument(
            "The multi-fidelity Heterogeneous function is only defined on a 1D space.");

    return apply_parallel(x, [](const auto &a) {
        const auto x_val = a.col(0);
        const VectorXd f_lf = ((30.0 * (x_val - 0.9).pow(4.0)).sin() * (2.0 * (x_val - 0.9)).cos() +
                               (x_val - 0.9) / 2.0)
                                  .matrix();
        const VectorXd f_hf = ((f_lf.array() - 1.0 + x_val) / (1.0 + 0.25 * x_val)).matrix();

        MatrixXd res(a.rows(), 2);
        res.col(0) = f_hf;
        res.col(1) = f_lf;
        return res;
    });
}

MatrixXd himmelblau(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument(
            "The multi-fidelity Himmelblau function only accepts 2D inputs.");
    return apply_parallel(x, [](const auto &a) {
        const auto X = a.col(0);
        const auto Y = a.col(1);
        const VectorXd hf =
            ((X.square() + Y - 11.0).square() + (X + Y.square() - 7.0).square()).matrix();
        const VectorXd lf = (0.5 * hf.array() + 0.1 * (X + Y)).matrix();

        MatrixXd res(a.rows(), 2);
        res.col(0) = hf;
        res.col(1) = lf;
        return res;
    });
}

MatrixXd katsuura(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    const RowVectorXd i_vec_full = RowVectorXd::LinSpaced(n, 1, n);

    return apply_parallel(x, [n, i_vec_full](const auto &a) {
        const int m = a.rows();
        MatrixXd inner_sum = MatrixXd::Zero(m, n);
        for (int j = 1; j <= 32; ++j) {
            const double two_pow_j = std::pow(2.0, (double)j);
            const MatrixXd val = two_pow_j * a.matrix();
            inner_sum.array() += (val.array() - val.array().round()).abs() / two_pow_j;
        }
        const MatrixXd prod_terms = 1.0 + (inner_sum.array().rowwise() * i_vec_full.array());
        const VectorXd hf =
            ((10.0 / (n * n)) *
             (prod_terms.array().pow(10.0 / std::pow((double)n, 1.2)).rowwise().prod() - 1.0))
                .matrix();
        const VectorXd lf = (0.5 * hf.array() + 0.1 * a.rowwise().sum().array()).matrix();

        MatrixXd res(m, 2);
        res.col(0) = hf;
        res.col(1) = lf;
        return res;
    });
}

MatrixXd levy(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    return apply_parallel(x, [n](const auto &a) {
        const int m = a.rows();
        const auto w = 1.0 + (a - 1.0) / 4.0;
        const auto w_first = w.col(0);
        const auto w_last = w.col(n - 1);
        const VectorXd term1 = (M_PI * w_first).sin().square().matrix();
        const VectorXd term3 =
            ((w_last - 1.0).square() * (1.0 + (2.0 * M_PI * w_last).sin().square())).matrix();
        VectorXd hf = term1 + term3;
        if (n > 1) {
            const auto w_sub = w.block(0, 0, m, n - 1);
            hf += ((w_sub - 1.0).square() * (1.0 + 10.0 * (M_PI * w_sub + 1.0).sin().square()))
                      .rowwise()
                      .sum()
                      .matrix();
        }
        const VectorXd lf = (0.5 * hf.array() + 0.1 * a.rowwise().sum().array()).matrix();

        MatrixXd res(m, 2);
        res.col(0) = hf;
        res.col(1) = lf;
        return res;
    });
}

MatrixXd matyas(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument("The multi-fidelity Matyas function only accepts 2D inputs.");
    return apply_parallel(x, [](const auto &a) {
        const auto X = a.col(0);
        const auto Y = a.col(1);
        const VectorXd hf = (0.26 * (X.square() + Y.square()) - 0.48 * X * Y).matrix();
        const VectorXd lf =
            (0.28 * (X.square() + Y.square()) - 0.45 * X * Y + 0.1 * (X + Y)).matrix();

        MatrixXd res(a.rows(), 2);
        res.col(0) = hf;
        res.col(1) = lf;
        return res;
    });
}

MatrixXd michalewicz(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    const RowVectorXd I_vec_full = RowVectorXd::LinSpaced(n, 1, n);
    return apply_parallel(x, [n, I_vec_full](const auto &a) {
        const int rows = a.rows();
        const MatrixXd I = I_vec_full.replicate(rows, 1);
        const VectorXd hf =
            (-(a.sin() * (I.array() * a.square() / M_PI).sin().pow(20.0))).rowwise().sum().matrix();
        const VectorXd lf = ((-(a.sin() * (I.array() * a.square() / M_PI).sin().pow(10.0)))
                                     .rowwise()
                                     .sum()
                                     .array() *
                                 0.5 +
                             0.1 * a.rowwise().sum().array())
                                .matrix();

        MatrixXd res(rows, 2);
        res.col(0) = hf;
        res.col(1) = lf;
        return res;
    });
}

MatrixXd otlcircuit(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 6)
        throw std::invalid_argument(
            "The multi-fidelity OTL circuit function is only defined on a 6D space.");

    return apply_parallel(x, [](const auto &a) {
        const auto Rb1 = a.col(0);
        const auto Rb2 = a.col(1);
        const auto Rf = a.col(2);
        const auto Rc1 = a.col(3);
        const auto Rc2 = a.col(4);
        const auto beta = a.col(5);

        const auto Vb1 = (12.0 * Rb2) / (Rb1 + Rb2);
        const auto beta_Rc2_9 = beta * (Rc2 + 9.0);
        const auto denom = beta_Rc2_9 + Rf;

        const auto term1 = (Vb1 + 0.74) * beta_Rc2_9 / denom;
        const auto term2 = 11.35 * Rf / denom;
        const auto term3 = 0.74 * Rf * beta_Rc2_9 / (denom * Rc1);

        const VectorXd hf = (term1 + term2 + term3).matrix();
        const VectorXd lf = (term1 + term2).matrix();

        MatrixXd res(a.rows(), 2);
        res.col(0) = hf;
        res.col(1) = lf;
        return res;
    });
}

MatrixXd park91a(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 4)
        throw std::invalid_argument(
            "The multi-fidelity Park91a function is only defined on a 4D space.");

    return apply_parallel(x, [](const auto &a) {
        const auto x1 = a.col(0);
        const auto x2 = a.col(1);
        const auto x3 = a.col(2);
        const auto x4 = a.col(3);

        const auto f_hf_array =
            (x1 / 2.0) * ((1.0 + (x2 + x3.square()) * x4 / x1.square()).sqrt() - 1.0) +
            (x1 + 3.0 * x4) * (1.0 + x3.sin()).exp();

        const VectorXd hf = f_hf_array.matrix();
        const VectorXd lf =
            ((1.0 + x1.sin() / 10.0) * f_hf_array - 2.0 * x1 + x2.square() + x3.square() + 0.5)
                .matrix();

        MatrixXd res(a.rows(), 2);
        res.col(0) = hf;
        res.col(1) = lf;
        return res;
    });
}

MatrixXd park91b(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 4)
        throw std::invalid_argument(
            "The multi-fidelity Park91b function is only defined on a 4D space.");

    return apply_parallel(x, [](const auto &a) {
        const auto x1 = a.col(0);
        const auto x2 = a.col(1);
        const auto x3 = a.col(2);
        const auto x4 = a.col(3);

        const auto f_hf_array = (2.0 / 3.0) * (x1 + x2).exp() - x4 * x3.sin() + x3;

        const VectorXd hf = f_hf_array.matrix();
        const VectorXd lf = (1.2 * f_hf_array - 1.0).matrix();

        MatrixXd res(a.rows(), 2);
        res.col(0) = hf;
        res.col(1) = lf;
        return res;
    });
}

MatrixXd piston(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 7)
        throw std::invalid_argument(
            "The multi-fidelity Piston function is only defined on a 7D space.");

    auto piston_hf_internal = [](const auto &a) {
        const auto M = a.col(0);
        const auto S = a.col(1);
        const auto V0 = a.col(2);
        const auto k = a.col(3);
        const auto Pa = a.col(4);
        const auto Ta = a.col(5);
        const auto T0 = a.col(6);

        const auto A = Pa * S + 19.62 * M - (k * V0 / S);
        const auto PaV0_Ta = Pa * V0 / Ta;
        const auto V = (S / (2.0 * k)) * ((A.square() + 4.0 * k * PaV0_Ta * T0).sqrt() - A);
        return (2.0 * M_PI * (M / (k + S.square() * PaV0_Ta * T0 / V.square())).sqrt());
    };

    return apply_parallel(x, [piston_hf_internal](const auto &a) {
        const VectorXd f_hf = piston_hf_internal(a).matrix();
        const VectorXd f_lf = (f_hf.array() + 0.05).matrix();

        MatrixXd res(a.rows(), 2);
        res.col(0) = f_hf;
        res.col(1) = f_lf;
        return res;
    });
}

MatrixXd rastrigin(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    return apply_parallel(x, [n](const auto &a) {
        const VectorXd hf =
            (10.0 * n + (a.square() - 10.0 * (2.0 * M_PI * a).cos()).rowwise().sum().array())
                .matrix();
        const VectorXd lf =
            (10.0 * n + (a.square() - 8.0 * (2.0 * M_PI * a).cos()).rowwise().sum().array() +
             0.1 * a.rowwise().sum().array())
                .matrix();

        MatrixXd res(a.rows(), 2);
        res.col(0) = hf;
        res.col(1) = lf;
        return res;
    });
}

MatrixXd robotarm(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 8)
        throw std::invalid_argument(
            "The multi-fidelity Robot Arm function is only defined on an 8D space.");

    auto robot_f_internal = [](const auto &a, double link_perturb) {
        const ArrayXd L1 = a.col(0).array() + link_perturb;
        const ArrayXd th1 = a.col(1).array();
        const ArrayXd L2 = a.col(2).array() + link_perturb;
        const ArrayXd th2 = a.col(3).array();
        const ArrayXd L3 = a.col(4).array() + link_perturb;
        const ArrayXd th3 = a.col(5).array();
        const ArrayXd L4 = a.col(6).array() + link_perturb;
        const ArrayXd th4 = a.col(7).array();

        const ArrayXd s1 = th1;
        const ArrayXd s12 = th1 + th2;
        const ArrayXd s123 = th1 + th2 + th3;
        const ArrayXd s1234 = th1 + th2 + th3 + th4;

        const ArrayXd u = L1 * s1.cos() + L2 * s12.cos() + L3 * s123.cos() + L4 * s1234.cos();
        const ArrayXd v = L1 * s1.sin() + L2 * s12.sin() + L3 * s123.sin() + L4 * s1234.sin();

        return (u.square() + v.square()).sqrt().matrix();
    };

    return apply_parallel(x, [robot_f_internal](const auto &a) {
        const VectorXd hf = robot_f_internal(a, 0.0);
        const VectorXd lf = robot_f_internal(a, 0.05);

        MatrixXd res(a.rows(), 2);
        res.col(0) = hf;
        res.col(1) = lf;
        return res;
    });
}

MatrixXd rosenbrock(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    return apply_parallel(x, [n](const auto &a) {
        const int m = a.rows();
        const auto xi = a.block(0, 0, m, n - 1);
        const auto xi_plus_1 = a.block(0, 1, m, n - 1);

        const VectorXd hf = (100.0 * (xi_plus_1 - xi.square()).square() + (xi - 1.0).square())
                                .rowwise()
                                .sum()
                                .matrix();

        const double a2 = -2.0;
        const double b2 = 50.0;
        const double d2 = 0.5;

        const VectorXd lf = (b2 * (xi_plus_1 - xi.square()).square() + (a2 - xi).square())
                                .rowwise()
                                .sum()
                                .matrix() -
                            (d2 * xi).rowwise().sum().matrix();

        MatrixXd res(m, 2);
        res.col(0) = hf;
        res.col(1) = lf;
        return res;
    });
}

MatrixXd schwefel(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    return apply_parallel(x, [n](const auto &a) {
        const VectorXd hf =
            (418.9829 * n - (a * (a.abs().sqrt()).sin()).rowwise().sum().array()).matrix();
        const VectorXd lf =
            (380.0 * n - (a * (a.abs().sqrt()).sin()).rowwise().sum().array() * 0.8 +
             0.1 * a.rowwise().sum().array())
                .matrix();

        MatrixXd res(a.rows(), 2);
        res.col(0) = hf;
        res.col(1) = lf;
        return res;
    });
}

MatrixXd shubert(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    return apply_parallel(x, [n](const auto &a) {
        MatrixXd col_sums_hf = MatrixXd::Zero(a.rows(), n);
        MatrixXd col_sums_lf = MatrixXd::Zero(a.rows(), n);
        for (int j = 1; j <= 5; j++) {
            col_sums_hf.array() += (double)j * (((double)(j + 1) * a + (double)j).cos());
            col_sums_lf.array() += (double)j * (((double)(j + 1.1) * a + (double)j).cos());
        }
        const VectorXd hf = col_sums_hf.rowwise().prod().matrix();
        const VectorXd lf =
            (col_sums_lf.rowwise().prod().array() * 0.5 + 0.1 * a.rowwise().sum().array()).matrix();

        MatrixXd res(a.rows(), 2);
        res.col(0) = hf;
        res.col(1) = lf;
        return res;
    });
}

MatrixXd sixhumpcamel(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 2)
        throw std::invalid_argument(
            "The multi-fidelity Six-hump Camel function only accepts 2D inputs.");
    return apply_parallel(x, [](const auto &a) {
        const auto X = a.col(0);
        const auto Y = a.col(1);
        const VectorXd hf = ((4.0 - 2.1 * X.square() + X.pow(4.0) / 3.0) * X.square() + X * Y +
                             (-4.0 + 4.0 * Y.square()) * Y.square())
                                .matrix();
        const VectorXd lf = ((3.5 - 2.0 * X.square() + X.pow(4.0) / 4.0) * X.square() + X * Y +
                             (-3.5 + 3.5 * Y.square()) * Y.square())
                                .matrix();

        MatrixXd res(a.rows(), 2);
        res.col(0) = hf;
        res.col(1) = lf;
        return res;
    });
}

MatrixXd sphere(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    return apply_parallel(x, [](const auto &a) {
        const VectorXd hf = a.square().rowwise().sum().matrix();
        const VectorXd lf = (0.5 * hf.array() + 0.1 * a.rowwise().sum().array()).matrix();

        MatrixXd res(a.rows(), 2);
        res.col(0) = hf;
        res.col(1) = lf;
        return res;
    });
}

MatrixXd step(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    return apply_parallel(x, [](const auto &a) {
        const VectorXd hf = (a + 0.5).floor().square().rowwise().sum().matrix();
        const VectorXd lf = ((a + 0.6).floor().square().rowwise().sum().array() * 0.5 +
                             0.1 * a.rowwise().sum().array())
                                .matrix();

        MatrixXd res(a.rows(), 2);
        res.col(0) = hf;
        res.col(1) = lf;
        return res;
    });
}

MatrixXd styblinskitank(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    return apply_parallel(x, [](const auto &a) {
        const VectorXd hf =
            (0.5 * (a.pow(4.0) - 16.0 * a.square() + 5.0 * a).rowwise().sum().array()).matrix();
        const VectorXd lf =
            (0.4 * (a.pow(4.0) - 14.0 * a.square() + 4.0 * a).rowwise().sum().array() +
             0.1 * a.rowwise().sum().array())
                .matrix();

        MatrixXd res(a.rows(), 2);
        res.col(0) = hf;
        res.col(1) = lf;
        return res;
    });
}

MatrixXd trid(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    return apply_parallel(x, [n](const auto &a) {
        const int m = a.rows();
        VectorXd hf = (a - 1.0).square().rowwise().sum().matrix();
        if (n > 1)
            hf -= (a.block(0, 1, m, n - 1) * a.block(0, 0, m, n - 1)).rowwise().sum().matrix();
        const VectorXd lf = (0.5 * hf.array() + 0.1 * a.rowwise().sum().array()).matrix();

        MatrixXd res(m, 2);
        res.col(0) = hf;
        res.col(1) = lf;
        return res;
    });
}

MatrixXd wingweight(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 10)
        throw std::invalid_argument(
            "The multi-fidelity Wing Weight function is only defined on a 10D space.");

    return apply_parallel(x, [](const auto &a) {
        const auto Sw = a.col(0);
        const auto Wfw = a.col(1);
        const auto A = a.col(2);
        const auto Lambda = a.col(3).array() * M_PI / 180.0; // deg to rad
        const auto q = a.col(4);
        const auto lambda = a.col(5);
        const auto tc = a.col(6);
        const auto Nz = a.col(7);
        const auto Wdg = a.col(8);
        const auto Wp = a.col(9);

        const auto cos_L = Lambda.cos();
        const auto term1 = 0.036 * Sw.pow(0.758) * Wfw.pow(0.0035);
        const auto term2 = (A / cos_L.square()).pow(0.6) * q.pow(0.006) * lambda.pow(0.04);
        const auto term3 = (100.0 * tc / cos_L).pow(-0.3);
        const auto term4 = (Nz * Wdg).pow(0.49);

        const VectorXd hf = (term1 * term2 * term3 * term4 + Sw * Wp).matrix();
        const VectorXd lf = (0.9 * hf.array() + 10.0).matrix();

        MatrixXd res(a.rows(), 2);
        res.col(0) = hf;
        res.col(1) = lf;
        return res;
    });
}

MatrixXd xiong1d(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    if (x.cols() != 1)
        throw std::invalid_argument("The multi-fidelity Xiong 1D function only accepts 1D inputs.");

    return apply_parallel(x, [](const auto &a) {
        const auto x_val = a.col(0);
        const VectorXd hf = ((30.0 * (x_val - 0.9).pow(4.0)).sin() * (2.0 * (x_val - 0.9)).cos() +
                             (x_val - 0.9) / 2.0)
                                .matrix();
        const VectorXd lf = (0.5 * hf.array() + 10.0 * (x_val - 0.5)).matrix();

        MatrixXd res(a.rows(), 2);
        res.col(0) = hf;
        res.col(1) = lf;
        return res;
    });
}

MatrixXd zakharov(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    const RowVectorXd I_vec_full = RowVectorXd::LinSpaced(n, 1, n);
    return apply_parallel(x, [I_vec_full](const auto &a) {
        const VectorXd s1 = a.square().rowwise().sum().matrix();
        const MatrixXd I = I_vec_full.replicate(a.rows(), 1);
        const VectorXd s2 = (0.5 * I.array() * a).rowwise().sum().matrix();
        const VectorXd hf = (s1.array() + s2.array().square() + s2.array().pow(4.0)).matrix();
        const VectorXd lf =
            (0.5 * s1.array() + s2.array().square() + 0.1 * a.rowwise().sum().array()).matrix();

        MatrixXd res(a.rows(), 2);
        res.col(0) = hf;
        res.col(1) = lf;
        return res;
    });
}

} // namespace BenchmarkFcns::MultiFidelity
