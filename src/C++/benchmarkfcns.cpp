#include "benchmarkfcns.h"
#include <random>

namespace BenchmarkFcns {

    using namespace Eigen;

    VectorXd ackley(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        constexpr double a = 20;
        constexpr double b = 0.2;
        constexpr double c = 2 * M_PI;
        const double ninverse = 1.0 / n;

        const auto sum1 = x.array().square().rowwise().sum();
        const auto sum2 = (c * x).array().cos().rowwise().sum();

        VectorXd scores = -(a * exp(-b * (sum1 * ninverse).sqrt())) + a - exp(sum2 * ninverse) + exp(1);

        return scores;
    }

    VectorXd ackleyn2(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("Ackley2 function only accepts 2D input.");

        const auto X = x.col(0);
        const auto Y = x.col(1);

        VectorXd scores = -200 * exp(-0.02 * ((X.array().square() + Y.array().square()).sqrt()));
        return scores;
    }

    VectorXd ackleyn3(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Ackleyn3 function only accepts 2D inputs.");

        const auto X = x.col(0);
        const auto Y = x.col(1);

        VectorXd scores = -200 * exp(-0.2 * ((X.array().square() + Y.array().square()).sqrt())) + 5 * exp(cos(3 * X.array()) + sin(3 * Y.array()));

        return scores;
    }

    VectorXd ackleyn4(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int m = x.rows();
        const int n = x.cols();

        const MatrixXd term1 = exp(-0.2) * ((x.block(0, 0, m, n - 1).array().square() + x.block(0, 1, m, n - 1).array().square()).sqrt());
        const MatrixXd term2 = 3 * (cos(2 * x.block(0, 0, m, n - 1).array()) + sin(2 * x.block(0, 1, m, n - 1).array()));

        VectorXd scores = (term1 + term2).rowwise().sum();

        return scores;
    }

    VectorXd adjiman(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Adjiman function only accepts 2D inputs.");

        const auto X = x.col(0).array();
        const auto Y = x.col(1).array();

        VectorXd scores = (X.array().cos() * Y.array().sin()) - (X.array() / ((Y.array().square()) + 1));

        return scores;
    }

    VectorXd alpinen1(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        VectorXd scores = (x.array() * sin(x.array()) + 0.1 * x.array()).rowwise().sum().abs();
        return scores;
    }

    VectorXd alpinen2(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        VectorXd scores = (x.array().sqrt() * sin(x.array())).rowwise().prod();
        return scores;
    }

    VectorXd amgm(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const double ninv = 1.0 / x.cols();

        const VectorXd comp1 = (x.rowwise().prod().array().pow(ninv));
        const VectorXd comp2 = x.rowwise().mean();
        return (comp1 - comp2).array().square();
    }

    VectorXd attractivesector(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const auto x2 = x.array().square();
        const MatrixXd result = (x.array() > 0).select(10000.0 * x2, x2);
        return result.rowwise().sum();
    }

    VectorXd bartelsconn(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Bartels Conn function only accepts 2D inputs.");

        const auto X = x.col(0);
        const auto Y = x.col(1);

        VectorXd scores = (X.array().square() + Y.array().square() + X.array() * Y.array()).abs() + (X.array().sin()).abs() + (Y.array().cos()).abs();
        return scores;
    }

    VectorXd beale(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Beale function only accepts 2D inputs.");

        const auto X = x.col(0);
        const auto Y = x.col(1);

        VectorXd scores = (1.5 - X.array() + (X.array() * Y.array())).square() +
                        (2.25 - X.array() + (X.array() * (Y.array().square()))).square() +
                        (2.625 - X.array() + (X.array() * (Y.array().cube()))).square();
        return scores;
    }

    VectorXd bentcigar(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        const int m = x.rows();
        VectorXd scores = x.col(0).array().square();
        if (n > 1) {
            scores += 1e6 * x.block(0, 1, m, n - 1).array().square().rowwise().sum().matrix();
        }
        return scores;
    }

    VectorXd biggsexp02(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The BiggsExp02 function only accepts 2D inputs.");

        const int numTerms = 10;
        const VectorXd i = VectorXd::LinSpaced(numTerms, 1, numTerms);
        const VectorXd ti = 0.1 * i;
        const VectorXd yi = (-ti).array().exp() - 5 * (-10 * ti).array().exp();

        const RowVectorXd x1 = x.col(0).transpose();
        const RowVectorXd x2 = x.col(1).transpose();

        const MatrixXd term1 = (-ti * x1).array().exp();
        const MatrixXd term2 = 5 * (-ti * x2).array().exp();

        const MatrixXd residuals_sq = (term1 - term2 - yi.replicate(1, x.rows())).array().square();
        VectorXd scores = residuals_sq.colwise().sum();
        return scores;
    }

    VectorXd biggsexp03(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The BiggsExp03 function only accepts 2D inputs.");

        const int numTerms = 10;
        const VectorXd i = VectorXd::LinSpaced(numTerms, 1, numTerms);
        const VectorXd ti = 0.1 * i;
        const VectorXd yi = (-ti).array().exp() - 5 * (-10 * ti).array().exp();

        const RowVectorXd x1 = x.col(0).transpose();
        const RowVectorXd x2 = x.col(1).transpose();

        const MatrixXd term1 = (-ti * x1).array().exp();
        const MatrixXd term2 = x1.replicate(numTerms, 1).array() * (-ti * x2).array().exp();

        const MatrixXd residuals_sq = (term1 - term2 - yi.replicate(1, x.rows())).array().square();
        VectorXd scores = residuals_sq.colwise().sum();
        return scores;
    }

    VectorXd biggsexp04(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 3)
            throw std::invalid_argument("The BiggsExp04 function only accepts 3D inputs.");

        const int numTerms = 10;
        const VectorXd i = VectorXd::LinSpaced(numTerms, 1, numTerms);
        const VectorXd ti = 0.1 * i;
        const VectorXd yi = (-ti).array().exp() - 5 * (-10 * ti).array().exp();

        const RowVectorXd x1 = x.col(0).transpose();
        const RowVectorXd x2 = x.col(1).transpose();
        const RowVectorXd x3 = x.col(2).transpose();

        const MatrixXd term1 = x3.replicate(numTerms, 1).array() * (-ti * x1).array().exp();
        const MatrixXd term2 = 5 * (-ti * x2).array().exp();

        const MatrixXd residuals_sq = (term1 - term2 - yi.replicate(1, x.rows())).array().square();
        VectorXd scores = residuals_sq.colwise().sum();
        return scores;
    }

    VectorXd biggsexp05(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 4)
            throw std::invalid_argument("The BiggsExp05 function only accepts 4D inputs.");

        const int numTerms = 11;
        const VectorXd i = VectorXd::LinSpaced(numTerms, 1, numTerms);
        const VectorXd ti = 0.1 * i;
        const VectorXd yi = (-ti).array().exp() - 5 * (-10 * ti).array().exp();

        const RowVectorXd x1 = x.col(0).transpose();
        const RowVectorXd x2 = x.col(1).transpose();
        const RowVectorXd x3 = x.col(2).transpose();
        const RowVectorXd x4 = x.col(3).transpose();

        const MatrixXd term1 = x3.replicate(numTerms, 1).array() * (-ti * x1).array().exp();
        const MatrixXd term2 = x4.replicate(numTerms, 1).array() * (-ti * x2).array().exp();

        const MatrixXd residuals_sq = (term1 - term2 - yi.replicate(1, x.rows())).array().square();
        VectorXd scores = residuals_sq.colwise().sum();
        return scores;
    }

    VectorXd biggsexp06(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 6)
            throw std::invalid_argument("The BiggsExp06 function only accepts 6D inputs.");

        const int numTerms = 13;
        const VectorXd i = VectorXd::LinSpaced(numTerms, 1, numTerms);
        const VectorXd ti = 0.1 * i;
        const VectorXd yi = (-ti).array().exp() - 5 * (-10 * ti).array().exp();

        const RowVectorXd x1 = x.col(0).transpose();
        const RowVectorXd x2 = x.col(1).transpose();
        const RowVectorXd x3 = x.col(2).transpose();
        const RowVectorXd x4 = x.col(3).transpose();
        const RowVectorXd x5 = x.col(4).transpose();
        const RowVectorXd x6 = x.col(5).transpose();

        const MatrixXd term1 = x3.replicate(numTerms, 1).array() * (-(ti.array().replicate(1, x.rows()) + x5.replicate(numTerms, 1).array()) * x1.array().replicate(numTerms, 1)).exp();
        const MatrixXd term2 = x4.replicate(numTerms, 1).array() * (-(ti.array().replicate(1, x.rows()) + x6.replicate(numTerms, 1).array()) * x2.array().replicate(numTerms, 1)).exp();

        const MatrixXd residuals_sq = (term1 - term2 - yi.replicate(1, x.rows())).array().square();
        VectorXd scores = residuals_sq.colwise().sum();
        return scores;
    }

    VectorXd bird(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Bird function is only defined on a 2D space.");

        const auto X = x.col(0).array();
        const auto Y = x.col(1).array();

        VectorXd scores = (sin(X) * exp((1 - cos(Y)).square())) + (cos(Y) * exp((1 - sin(X)).square())) + (X - Y).square();
        return scores;
    }

    VectorXd bohachevskyn1(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Bohachevsky N. 1 function is only defined on a 2D space.");

        const auto X = x.col(0).array();
        const auto Y = x.col(1).array();

        VectorXd scores = X.square() + 2 * Y.square() - 0.3 * cos(3 * M_PI * X) - 0.4 * cos(4 * M_PI * Y) + 0.7;
        return scores;
    }

    VectorXd bohachevskyn2(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Bohachevsky N2 function only accepts 2D inputs");

        const auto X = x.col(0).array();
        const auto Y = x.col(1).array();

        VectorXd scores = (X.square() + 2 * Y.square() - 0.3 * cos(3 * M_PI * X) * cos(4 * M_PI * Y) + 0.3);
        return scores;
    }

    VectorXd bohachevskyn3(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Bohachevsky N3 function only accepts 2D inputs");

        const auto X = x.col(0).array();
        const auto Y = x.col(1).array();

        VectorXd scores = (X.square() + 2 * Y.square() - 0.3 * cos(3 * M_PI * X + 4 * M_PI * Y) + 0.3);
        return scores;
    }

    VectorXd booth(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Booth function only accepts 2D inputs");

        const auto X = x.col(0).array();
        const auto Y = x.col(1).array();

        VectorXd scores = (X + 2 * Y - 7).square() + (2 * X + Y - 5).square();
        return scores;
    }

    VectorXd braninn1(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Branin N. 1 function only accepts 2D inputs");

        const auto X = x.col(0).array();
        const auto Y = x.col(1).array();

        constexpr double a = 1;
        constexpr double b = 5.1 / (4 * M_PI * M_PI);
        constexpr double c = 5 / M_PI;
        constexpr double d = 6;
        constexpr double e = 10;
        constexpr double f = 1 / (8 * M_PI);

        VectorXd scores = a * (Y - b * X.square() + c * X - d).square() + e * (1 - f) * cos(X) + e;
        return scores;
    }

    VectorXd braninn2(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Branin N. 2 function only accepts 2D inputs");

        const auto X = x.col(0).array();
        const auto Y = x.col(1).array();

        VectorXd scores = (X.square() + Y.square() - 5).square() + (sin(X).square() + cos(Y).square() - 1).square();
        return scores;
    }

    VectorXd brent(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Brent function only accepts 2D inputs");

        const auto X = x.col(0).array();
        const auto Y = x.col(1).array();

        VectorXd scores = (X + 10).square() + (Y + 10).square() + exp(-X.square() - Y.square());
        return scores;
    }

    VectorXd brown(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        VectorXd scores = VectorXd::Zero(x.rows());
        for (int i = 0; i < n - 1; i++) {
            const auto xi = x.col(i).array();
            const auto xi_plus_1 = x.col(i + 1).array();
            scores.array() += (xi.square()).pow(xi_plus_1.square() + 1) + (xi_plus_1.square()).pow(xi.square() + 1);
        }
        return scores;
    }

    VectorXd bukinn2(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Bukin N. 2 function only accepts 2D inputs");

        const auto X = x.col(0).array();
        const auto Y = x.col(1).array();

        VectorXd scores = 100 * (Y - 0.01 * X.square() + 1).square() + 0.01 * (X + 10).square();
        return scores;
    }

    VectorXd bukinn4(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Bukin N. 4 function only accepts 2D inputs");

        const auto X = x.col(0).array();
        const auto Y = x.col(1).array();

        VectorXd scores = 100 * Y.square() + 0.01 * (X + 10).abs();
        return scores;
    }

    VectorXd bukinn6(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Bukin N. 6 function only accepts 2D inputs");

        const auto X = x.col(0).array();
        const auto Y = x.col(1).array();

        VectorXd scores = 100 * (Y - 0.01 * X.square()).abs().sqrt() + 0.01 * (X + 10).abs();
        return scores;
    }

    VectorXd carromtable(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Carrom Table function only accepts 2D inputs");

        const auto X = x.col(0).array();
        const auto Y = x.col(1).array();

        VectorXd scores = -((cos(X) * cos(Y) * exp(abs(1 - sqrt(X.square() + Y.square()) / M_PI))).square() / 30.0);
        return scores;
    }

    VectorXd chichinadze(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Chichinadze function only accepts 2D inputs");

        const auto X = x.col(0).array();
        const auto Y = x.col(1).array();

        VectorXd scores = X.square() - 12 * X + 11 + 10 * cos(M_PI * X / 2.0) + 8 * sin(5 * M_PI * X / 2.0) - (1.0 / sqrt(2.0 * M_PI)) * exp(-0.5 * (Y - 0.5).square());
        return scores;
    }

    VectorXd cigar(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        const int m = x.rows();
        VectorXd scores = x.col(0).array().square().matrix();
        if (n > 1) {
            VectorXd rest_sum = x.block(0, 1, m, n - 1).array().square().rowwise().sum().matrix();
            scores += 1000000.0 * rest_sum;
        }
        return scores;
    }

    VectorXd corana(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        const int m = x.rows();

        VectorXd d_base(4);
        d_base << 1.0, 1000.0, 10.0, 100.0;
        VectorXd d(n);
        for (int i = 0; i < n; ++i) {
            d(i) = d_base(i % 4);
        }
        const auto D = d.transpose().replicate(m, 1).array();

        const auto x_abs = x.array().abs();
        const auto z_i = 0.2 * (x_abs / 0.2 + 0.49).floor() * x.array().sign();

        const auto diff_abs = (x.array() - z_i.array()).abs();
        const auto mask = (diff_abs < 0.05);

        const auto val1 = 0.15 * (z_i.array() - 0.05 * z_i.array().sign()).square() * D;
        const auto val2 = D * x.array().square();

        const MatrixXd result = mask.select(val1, val2);
        return result.rowwise().sum();
    }

    VectorXd cosinemixture(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        constexpr double FIVE_PI = 5 * M_PI;
        VectorXd scores = -0.1 * (x.array() * FIVE_PI).cos().rowwise().sum() - x.array().square().rowwise().sum();
        return scores;
    }

    VectorXd crossintray(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Cross-in-tray function only accepts 2D inputs");

        const auto X = x.col(0).array();
        const auto Y = x.col(1).array();

        VectorXd expcomponent = (100 - (sqrt(X.square() + Y.square()) / M_PI)).abs();
        VectorXd scores = -0.0001 * (abs(sin(X) * sin(Y) * expcomponent.array().exp()) + 1).pow(0.1);
        return scores;
    }

    VectorXd crownedcross(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Crowned Cross function only accepts 2D inputs");

        const auto X = x.col(0).array();
        const auto Y = x.col(1).array();

        VectorXd expcomponent = (100 - (sqrt(X.square() + Y.square()) / M_PI)).abs();
        VectorXd scores = 0.0001 * (abs(sin(X) * sin(Y) * expcomponent.array().exp()) + 1).pow(0.1);
        return scores;
    }

    VectorXd csendes(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        VectorXd scores = (x.array().pow(6) * (2 + sin(1.0 / x.array()))).rowwise().sum();
        return scores;
    }

    VectorXd cubefcn(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Cube function only accepts 2D inputs");

        const auto X = x.col(0).array();
        const auto Y = x.col(1).array();

        VectorXd scores = 100 * (Y - X.cube()).square() + (1 - X).square();
        return scores;
    }

    VectorXd debn1(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        VectorXd scores = -(sin(5 * M_PI * x.array()).pow(6).rowwise().sum());
        return scores;
    }

    VectorXd deckkersaarts(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Deckkers-Aarts function only accepts 2D inputs");

        const auto X = x.col(0).array();
        const auto Y = x.col(1).array();

        VectorXd scores = 1e5 * X.square() + Y.square() - (X.square() + Y.square()).square() + 1e-5 * (X.square() + Y.square()).pow(4);
        return scores;
    }

    VectorXd dejongn5(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("De Jong's N. 5 function is only defined on a 2D space.");

        const int m = x.rows();

        static constexpr double a_content[2][25] = {
            {-32, -16, 0, 16, 32, -32, -16, 0, 16, 32, -32, -16, 0, 16, 32, -32, -16, 0, 16, 32, -32, -16, 0, 16, 32},
            {-32, -32, -32, -32, -32, -16, -16, -16, -16, -16, 0, 0, 0, 0, 0, 16, 16, 16, 16, 16, 32, 32, 32, 32, 32}
        };
        const Matrix<double, 2, 25> A = Map<const Matrix<double, 2, 25, RowMajor>>(&a_content[0][0]);

        VectorXd inner_sum = VectorXd::Zero(m);
        for (int i = 0; i < 25; ++i) {
            const auto diff1 = (x.col(0).array() - A(0, i)).pow(6);
            const auto diff2 = (x.col(1).array() - A(1, i)).pow(6);
            inner_sum.array() += 1.0 / (static_cast<double>(i + 1) + diff1 + diff2);
        }

        VectorXd scores = (0.002 + inner_sum.array()).pow(-1.0);
        return scores;
    }

    VectorXd discus(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        const int m = x.rows();

        VectorXd scores = 1e6 * x.col(0).array().square();
        if (n > 1) {
            scores += x.block(0, 1, m, n - 1).array().square().rowwise().sum().matrix();
        }
        return scores;
    }

    VectorXd dixonprice(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        const int m = x.rows();
        const auto x1 = x.col(0).array();

        VectorXd scores = (x1 - 1.0).square();

        if (n > 1) {
            const auto xi = x.block(0, 1, m, n - 1).array();
            const auto xi_prev = x.block(0, 0, m, n - 1).array();
            const auto i_vec = RowVectorXd::LinSpaced(n - 1, 2, n).replicate(m, 1).array();

            scores += (i_vec * (2.0 * xi.square() - xi_prev).square()).rowwise().sum().matrix();
        }

        return scores;
    }

    VectorXd dropwave(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Drop Wave function only accepts 2D inputs");

        const auto X2 = x.col(0).array().square();
        const auto Y2 = x.col(1).array().square();

        VectorXd scores = -(1 + cos(12 * sqrt(X2 + Y2))) / (0.5 * (X2 + Y2) + 2);
        return scores;
    }

    VectorXd easom(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Easom function only accepts 2D inputs");

        const auto X = x.col(0).array();
        const auto Y = x.col(1).array();

        VectorXd scores = -cos(X) * cos(Y) * exp(-((X - M_PI).square() + (Y - M_PI).square()));
        return scores;
    }

    VectorXd eggcrate(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Egg Crate function only accepts 2D inputs");

        const auto X = x.col(0).array();
        const auto Y = x.col(1).array();

        VectorXd scores = X.square() + Y.square() + 25 * (sin(X).square() + sin(Y).square());
        return scores;
    }

    VectorXd eggholder(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Eggholder function only accepts 2D inputs");

        const auto X = x.col(0).array();
        const auto Y = x.col(1).array();

        VectorXd scores = -(Y + 47) * sin(sqrt(abs(X / 2.0 + Y + 47))) - X * sin(sqrt(abs(X - (Y + 47))));
        return scores;
    }

    VectorXd elattar(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The El-Attar et al. function is only defined on a 2D space.");

        const auto X = x.col(0).array();
        const auto Y = x.col(1).array();

        VectorXd scores = (X.square() + Y - 10).square() + (X + Y.square() - 7).square() + (X.square() + Y.cube() - 1).square();
        return scores;
    }

    VectorXd elliptic(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        const int m = x.rows();

        VectorXd powers(n);
        for(int i=0; i<n; ++i) {
            powers(i) = std::pow(10.0, 6.0 * i / (n - 1.0));
        }

        const auto Coeffs = powers.transpose().replicate(m, 1).array();
        return (Coeffs * x.array().square()).rowwise().sum();
    }

    VectorXd exponential(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        VectorXd scores = -exp(-0.5 * x.array().square().rowwise().sum());
        return scores;
    }

    VectorXd f8f2(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        const int m = x.rows();

        VectorXd scores = VectorXd::Zero(m);
        for (int i = 0; i < n; ++i) {
            int next = (i + 1) % n;
            const auto xi = x.col(i).array();
            const auto xnext = x.col(next).array();

            const VectorXd rosen = 100.0 * (xi.square() - xnext).square() + (xi - 1.0).square();

            // Griewank on the rosen result
            scores += ((rosen.array().square() / 4000.0) - (rosen.array().cos()) + 1.0).matrix();
        }
        return scores;
    }

    VectorXd forrester(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 1)
            throw std::invalid_argument("The Forrester function is only defined on a 1D space.");

        const auto X = x.col(0).array();
        VectorXd scores = (6 * X - 2).square() * sin(12 * X - 4);
        return scores;
    }

    VectorXd foxholes(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Foxholes function only accepts 2D inputs");

        const int m = x.rows();
        static constexpr double a_content[2][25] = {
            {-32, -16, 0, 16, 32, -32, -16, 0, 16, 32, -32, -16, 0, 16, 32, -32, -16, 0, 16, 32, -32, -16, 0, 16, 32},
            {-32, -32, -32, -32, -32, -16, -16, -16, -16, -16, 0, 0, 0, 0, 0, 16, 16, 16, 16, 16, 32, 32, 32, 32, 32}
        };
        const Matrix<double, 2, 25> a = Map<const Matrix<double, 2, 25, RowMajor>>(&a_content[0][0]);

        VectorXd scores = VectorXd::Zero(m);
        for (int i = 0; i < 25; i++) {
            const auto diff1_6 = (x.col(0).array() - a(0, i)).pow(6);
            const auto diff2_6 = (x.col(1).array() - a(1, i)).pow(6);
            scores.array() += 1.0 / ((i + 1.0) + diff1_6.array() + diff2_6.array());
        }
        scores.array() = 1.0 / (0.002 + scores.array());
        return scores;
    }

    VectorXd friedman1(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x, bool rnd) {
        const int n = x.cols();
        if (n != 10)
            throw std::invalid_argument("The Friedman No. 1 function is only defined on a 10D space.");

        const int m = x.rows();
        VectorXd epsilon = VectorXd::Zero(m);
        if (rnd) {
            epsilon = VectorXd::Random(x.rows());
        }

        const auto x1 = x.col(0).array();
        const auto x2 = x.col(1).array();
        const auto x3 = x.col(2).array();
        const auto x4 = x.col(3).array();
        const auto x5 = x.col(4).array();

        const VectorXd term1 = 10 * (M_PI * x1 * x2).sin();
        const VectorXd term2 = 20 * (x3 - 0.5).square();
        const VectorXd term3 = 10 * x4;
        const VectorXd term4 = 5 * x5;

        const VectorXd scores = term1 + term2 + term3 + term4 + epsilon;
        return scores;
    }

    VectorXd friedman2(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x, double sigma) {
        const int n = x.cols();
        if (n != 4)
            throw std::invalid_argument("The Friedman No. 2 function is only defined on a 4D space.");

        const int m = x.rows();
        VectorXd epsilon = VectorXd::Zero(m);
        if (sigma > 0) {
            epsilon = sigma * VectorXd::Random(m);
        }

        const auto x1 = x.col(0).array();
        const auto x2 = x.col(1).array();
        const auto x3 = x.col(2).array();
        const auto x4 = x.col(3).array();

        const VectorXd term_inner = (x2 * x3).array() - (1.0 / (x2 * x4)).array();
        const VectorXd groundTruth = (x1.square() + term_inner.array().square()).sqrt();

        VectorXd scores = groundTruth + epsilon;
        return scores;
    }

    VectorXd friedman3(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x, double sigma) {
        const int n = x.cols();
        if (n != 4)
            throw std::invalid_argument("The Friedman No. 3 function is only defined on a 4D space.");

        const int m = x.rows();
        VectorXd epsilon = VectorXd::Zero(m);
        if (sigma > 0) {
            epsilon = sigma * VectorXd::Random(m);
        }

        const auto x1 = x.col(0).array();
        const auto x2 = x.col(1).array();
        const auto x3 = x.col(2).array();
        const auto x4 = x.col(3).array();

        const VectorXd numerator = (x2 * x3) - (1.0 / (x2 * x4)).array();
        const VectorXd groundTruth = (numerator.array() / x1).array().atan();

        VectorXd scores = groundTruth + epsilon;
        return scores;
    }

    VectorXd gallagher101(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        const int m = x.rows();

        std::mt19937 gen(101);
        std::uniform_real_distribution<double> dist_h(1.1, 9.1);
        std::uniform_real_distribution<double> dist_x(-4.0, 4.0);

        static bool initialized = false;
        static std::vector<double> w;
        static std::vector<VectorXd> y;
        static std::vector<MatrixXd> C;

        if (!initialized) {
            w.resize(101);
            y.resize(101);
            C.resize(101);

            w[0] = 10.0;
            y[0] = VectorXd::Zero(n);
            C[0] = MatrixXd::Identity(n, n);

            for (int i = 1; i < 101; ++i) {
                w[i] = dist_h(gen);
                y[i] = VectorXd::Zero(n);
                for (int j = 0; j < n; ++j) y[i](j) = dist_x(gen);

                VectorXd diag = VectorXd::Zero(n);
                for(int j=0; j<n; ++j) diag(j) = std::pow(1000.0, 0.5 * static_cast<double>(j)/(n-1.0));
                C[i] = diag.asDiagonal();
            }
            initialized = true;
        }

        VectorXd max_vals = VectorXd::Zero(m);
        for (int i = 0; i < 101; ++i) {
            MatrixXd diff = x.rowwise() - y[i].transpose();
            VectorXd exponent = -0.5 / static_cast<double>(n) * (diff * C[i]).array().square().rowwise().sum();
            max_vals = max_vals.cwiseMax((w[i] * exponent.array().exp()).matrix());
        }

        return 10.0 - max_vals.array();
    }

    VectorXd gear(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 4)
            throw std::invalid_argument("The Gear function only accepts 4D inputs");

        const auto x1 = x.col(0).array().floor();
        const auto x2 = x.col(1).array().floor();
        const auto x3 = x.col(2).array().floor();
        const auto x4 = x.col(3).array().floor();

        constexpr double target_ratio = 1.0 / 6.931;
        const auto actual_ratio = (x1 * x2) / (x3 * x4);
        VectorXd scores = (target_ratio - actual_ratio).square();
        return scores;
    }

    VectorXd giunta(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        VectorXd scores = 0.6 + (sin(1 - 16.0 / 15.0 * x.array()) + sin(1 - 16.0 / 15.0 * x.array()).square() + 1.0 / 50.0 * sin(4 * 16.0 / 15.0 * x.array())).rowwise().sum();
        return scores;
    }

    VectorXd goldsteinprice(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Goldstein-Price function only accepts 2D inputs");

        const auto X = x.col(0).array();
        const auto Y = x.col(1).array();

        const auto term1 = 1 + (X + Y + 1).square() * (19 - 14 * X + 3 * X.square() - 14 * Y + 6 * X * Y + 3 * Y.square());
        const auto term2 = 30 + (2 * X - 3 * Y).square() * (18 - 32 * X + 12 * X.square() + 48 * Y - 36 * X * Y + 27 * Y.square());

        VectorXd scores = term1 * term2;
        return scores;
    }

    VectorXd gramacylee(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 1)
            throw std::invalid_argument("The Gramacy & Lee function only accepts 1D inputs");

        const auto X = x.col(0).array();
        VectorXd scores = (sin(10 * M_PI * X) / (2 * X)) + (X - 1).pow(4);
        return scores;
    }

    VectorXd griewank(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        const int m = x.rows();

        const VectorXd sum_comp = (x.array().square() / 4000.0).rowwise().sum();
        const MatrixXd cos_comp = (x.array() / (RowVectorXd::LinSpaced(n, 1, n).array().sqrt().replicate(m, 1))).cos();
        const VectorXd prod_comp = cos_comp.rowwise().prod();

        VectorXd scores = sum_comp.array() - prod_comp.array() + 1;
        return scores;
    }

    VectorXd happycat(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x, double alpha) {
        const int n = x.cols();
        const auto x2 = x.array().square().rowwise().sum();
        const auto sx = x.rowwise().sum().array();

        VectorXd scores = ((x2 - n).square()).pow(alpha).array() + (0.5 * x2 + sx) / n + 0.5;
        return scores;
    }

    VectorXd hartmann3(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int m = x.rows();
        const int n = x.cols();
        if (n != 3)
            throw std::invalid_argument("The Hartmann 3 function only accepts 3D inputs");

        const VectorXd alpha = (VectorXd(4) << 1.0, 1.2, 3.0, 3.2).finished();
        const MatrixXd A = (MatrixXd(4, 3) << 3, 10, 30,
                                             0.1, 10, 35,
                                             3, 10, 30,
                                             0.1, 10, 35).finished();
        const MatrixXd P = (MatrixXd(4, 3) << 3689, 1170, 2673,
                                             4699, 4387, 7470,
                                             1091, 8732, 5547,
                                             381, 5743, 8828).finished();

        VectorXd scores = VectorXd::Zero(m);
        for (int i = 0; i < 4; i++) {
            auto rowA = A.row(i).replicate(m, 1);
            auto rowP = 1e-4 * P.row(i).replicate(m, 1);
            auto arg = (rowA.array() * (x.array() - rowP.array()).square()).rowwise().sum();
            scores.array() -= alpha(i) * (-arg).exp();
        }

        return scores;
    }

    VectorXd hartmann6(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int m = x.rows();
        const int n = x.cols();
        if (n != 6)
            throw std::invalid_argument("The Hartmann 6 function only accepts 6D inputs");

        const VectorXd alpha = (VectorXd(4) << 1.0, 1.2, 3.0, 3.2).finished();
        const MatrixXd A = (MatrixXd(4, 6) << 10, 3, 17, 3.5, 1.7, 8,
                                             0.05, 10, 17, 0.1, 8, 14,
                                             3, 3.5, 1.7, 10, 17, 8,
                                             17, 8, 0.05, 10, 0.1, 14).finished();
        const MatrixXd P = (MatrixXd(4, 6) << 1312, 1696, 5569, 124, 8283, 5886,
                                             2329, 4135, 8307, 3736, 1004, 9991,
                                             2348, 1451, 3522, 2883, 3047, 6650,
                                             4047, 8828, 8732, 5743, 1091, 381).finished();

        VectorXd scores = VectorXd::Zero(m);
        for (int i = 0; i < 4; ++i) {
            MatrixXd diff = x.rowwise() - P.row(i);
            MatrixXd diff_sq = diff.array().square();
            VectorXd exponent = diff_sq * A.row(i).transpose();
            scores.array() -= alpha(i) * (-exponent.array()).exp();
        }

        return scores;
    }

    VectorXd ishigami(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x, double a, double b) {
        const int n = x.cols();
        if (n != 3)
            throw std::invalid_argument("The Ishigami function is only defined on a 3D space.");

        const auto x1 = x.col(0).array();
        const auto x2 = x.col(1).array();
        const auto x3 = x.col(2).array();

        VectorXd scores = x1.sin() + a * x2.sin().square() + b * x3.pow(4) * x1.sin();
        return scores;
    }

    VectorXd himmelblau(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Himmelblau function only accepts 2D inputs");

        const auto X = x.col(0).array();
        const auto Y = x.col(1).array();

        VectorXd scores = (X.square() + Y - 11).square() + (X + Y.square() - 7).square();
        return scores;
    }

    VectorXd holdertable(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Holder Table function only accepts 2D inputs");

        const auto X = x.col(0).array();
        const auto Y = x.col(1).array();

        VectorXd scores = -abs(sin(X) * cos(Y) * exp(abs(1 - sqrt(X.square() + Y.square()) / M_PI)));
        return scores;
    }

    VectorXd hosaki(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Hosaki function only accepts 2D inputs");

        const auto X = x.col(0).array();
        const auto Y = x.col(1).array();

        VectorXd scores = (1 - 8 * X + 7 * X.square() - 7.0 / 3.0 * X.cube() + 1.0 / 4.0 * X.pow(4)) * Y.square() * exp(-Y);
        return scores;
    }

    VectorXd katsuura(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        const int m = x.rows();
        const double n_inv_sq = 10.0 / (n * n);
        const double exp_val = 10.0 / std::pow(n, 1.2);

        MatrixXd inner_sum = MatrixXd::Zero(m, n);

        for (int j = 1; j <= 32; ++j) {
            const double two_pow_j = std::pow(2.0, j);
            const MatrixXd val = two_pow_j * x.array();
            inner_sum.array() += (val.array() - val.array().round()).abs() / two_pow_j;
        }

        const RowVectorXd i_vec = RowVectorXd::LinSpaced(n, 1, n);
        const MatrixXd prod_terms = 1.0 + (inner_sum.array().rowwise() * i_vec.array());

        VectorXd scores = n_inv_sq * (prod_terms.array().pow(exp_val).rowwise().prod() - 1.0);
        return scores;
    }

    VectorXd keane(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Keane's function is only defined on a 2D space.");

        const auto X = x.col(0).array();
        const auto Y = x.col(1).array();
        const VectorXd numeratorcomp = (sin(X - Y).square()) * (sin(X + Y).square());
        const VectorXd denominatorcomp = (X.square() + Y.square()).sqrt();
        VectorXd scores = - numeratorcomp.array() / denominatorcomp.array();
        return scores;
    }

    VectorXd langermann(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        const int m = x.rows();
        if (n != 2)
            throw std::invalid_argument("The Langermann function is only defined on a 2D space.");

        static constexpr double a[5][2] = {
            {3, 5}, {5, 2}, {2, 1}, {1, 7}, {7, 9}
        };
        static constexpr double c[5] = {1, 2, 5, 2, 3};

        VectorXd scores = VectorXd::Zero(m);
        for (int i = 0; i < 5; ++i) {
            const RowVectorXd ai = Map<const RowVectorXd>(a[i], 2);
            const VectorXd sum_sq = (x.rowwise() - ai).array().square().rowwise().sum();
            scores.array() -= c[i] * ((-1.0/M_PI * sum_sq.array()).exp() * (M_PI * sum_sq.array()).cos());
        }
        return scores;
    }

    VectorXd leon(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Leon function is only defined on a 2D space.");

        const auto X = x.col(0).array();
        const auto Y = x.col(1).array();
        VectorXd scores = 100 * ((Y - X.cube()).square()) + ((1 - X).square());
        return scores;
    }

    VectorXd levin13(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Levi's function is only defined on a 2D space.");

        const auto X = x.col(0).array();
        const auto Y = x.col(1).array();
        VectorXd scores = (sin(3 * M_PI * X).square()) +
                        ((X - 1).square()) * (1 + sin(3 * M_PI * Y).square()) +
                        ((Y - 1).square()) * (1 + sin(2 * M_PI * Y).square());
        return scores;
    }

    VectorXd levy(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        const int m = x.rows();
        const MatrixXd w = 1.0 + (x.array() - 1.0) / 4.0;

        const auto w_first = w.col(0).array();
        const auto w_last = w.col(n - 1).array();

        const VectorXd term1 = (M_PI * w_first).sin().square();
        const VectorXd term3 = (w_last - 1.0).square() * (1.0 + (2.0 * M_PI * w_last).sin().square());

        VectorXd scores = term1 + term3;
        if (n > 1) {
            const auto w_sub = w.block(0, 0, m, n - 1).array();
            const VectorXd term2 = ((w_sub - 1.0).square() * (1.0 + 10.0 * (M_PI * w_sub + 1.0).sin().square())).rowwise().sum();
            scores += term2;
        }
        return scores;
    }

    VectorXd lunacekbirastrigin(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        const double mu0 = 2.5;
        const double s = 1.0 - (1.0 / (2.0 * std::sqrt(n + 20.0) - 8.2));
        const double mu1 = -std::sqrt((mu0 * mu0 - 1.0) / s);
        const double d = 1.0;

        const auto x_array = x.array();
        const VectorXd sum_mu0 = (x_array - mu0).square().rowwise().sum();
        const VectorXd sum_mu1 = (x_array - mu1).square().rowwise().sum();
        const VectorXd deceptive_term = sum_mu0.cwiseMin(((s * sum_mu1).array() + (d * n)).matrix());
        const VectorXd rastrigin_term = 10.0 * (n - (2.0 * M_PI * (x_array - mu0)).cos().rowwise().sum());
        return deceptive_term + rastrigin_term;
    }

    VectorXd matyas(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Matyas' function is only defined on a 2D space.");

        const auto X = x.col(0).array();
        const auto Y = x.col(1).array();
        VectorXd scores = 0.26 * (X.square() + Y.square()) - 0.48 * X * Y;
        return scores;
    }

    VectorXd mishrabird(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("Mishra's Bird function is only defined on a 2D space.");

        const auto x1 = x.col(0).array();
        const auto x2 = x.col(1).array();
        VectorXd scores = x2.sin() * (1.0 - x1.cos()).square().exp() +
                          x1.cos() * (1.0 - x2.sin()).square().exp() +
                          (x1 - x2).square();
        return scores;
    }

    VectorXd mccormick(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The McCormick function is only defined on a 2D space.");

        const auto X = x.col(0).array();
        const auto Y = x.col(1).array();
        VectorXd scores = sin(X + Y) + ((X - Y).square()) - 1.5 * X + 2.5 * Y + 1;
        return scores;
    }

    VectorXd michalewicz(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x, double m) {
        const int n = x.cols();
        const int rows = x.rows();
        const MatrixXd I = RowVectorXd::LinSpaced(n, 1, n).replicate(rows, 1);
        const MatrixXd term2 = (I.array() * x.array().square() / M_PI).sin().pow(2 * m);
        const MatrixXd scores = x.array().sin() * term2.array();
        return -scores.rowwise().sum();
    }

    VectorXd periodic(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const VectorXd sin2x = (x.array().sin()).square().rowwise().sum();
        const VectorXd sumx2 = x.array().square().rowwise().sum();
        VectorXd scores = 1 + sin2x.array() - 0.1 * exp(-sumx2.array());
        return scores;
    }

    VectorXd perm(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x, double beta) {
        const int n = x.cols();
        const int m = x.rows();
        VectorXd scores = VectorXd::Zero(m);
        const MatrixXd j_vals = RowVectorXd::LinSpaced(n, 1, n).replicate(m, 1);
        const MatrixXd xj_over_j = x.array() / j_vals.array();
        for (int i = 1; i <= n; ++i) {
            const MatrixXd j_pow_i = j_vals.array().pow(i);
            const MatrixXd inner_term = (j_pow_i.array() + beta) * (xj_over_j.array().pow(i) - 1.0);
            scores += inner_term.rowwise().sum().array().square().matrix();
        }
        return scores;
    }

    VectorXd picheny(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Picheny function is only defined on a 2D space.");

        const auto X = x.col(0).array();
        const auto Y = x.col(1).array();
        VectorXd scores = (X.square() + Y - 11).square() + (X + Y.square() - 7).square();
        return scores;
    }

    VectorXd powellsingular(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 4)
            throw std::invalid_argument("The Powell Singular function is only defined on a 4D space.");

        const auto x1 = x.col(0).array();
        const auto x2 = x.col(1).array();
        const auto x3 = x.col(2).array();
        const auto x4 = x.col(3).array();
        VectorXd scores = (x1 + 10.0 * x2).square() + 5.0 * (x3 - x4).square() + (x2 - 2.0 * x3).pow(4) + 10.0 * (x1 - x4).pow(4);
        return scores;
    }

    VectorXd powellsum(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        const int m = x.rows();
        const VectorXd powers = RowVectorXd::LinSpaced(n, 2, n + 1);
        return x.array().abs().pow(powers.transpose().array().replicate(m, 1)).rowwise().sum();
    }

    VectorXd qing(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        const int m = x.rows();
        const MatrixXd x2 = x.array().square();
        const MatrixXd I = RowVectorXd::LinSpaced(n, 1, n).replicate(m, 1);
        return (x2.array() - I.array()).square().rowwise().sum();
    }

    VectorXd quartic(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        const int m = x.rows();
        const MatrixXd I = RowVectorXd::LinSpaced(n, 1, n).replicate(m, 1);
        // Standard Quartic with random component: sum(i*x_i^4)
        return (I.array() * x.array().pow(4)).rowwise().sum();
    }

    VectorXd rana(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        const int m = x.rows();
        if (n < 2) return VectorXd::Zero(m);
        VectorXd scores = VectorXd::Zero(m);
        for (int i = 0; i < n - 1; i++) {
            const auto xi = x.col(i).array();
            const auto xj = x.col(i + 1).array();
            const auto t1 = sqrt(abs(xj + 1 - xi));
            const auto t2 = sqrt(abs(xj + 1 + xi));
            scores.array() += xi * sin(t1) * cos(t2) + (xj + 1) * cos(t1) * sin(t2);
        }
        return scores;
    }

    VectorXd rastrigin(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        VectorXd scores = 10 * n + (x.array().square() - 10 * cos(2 * M_PI * x.array())).rowwise().sum();
        return scores;
    }

    VectorXd ridge(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x, double d, double alpha) {
        const int n = x.cols();
        const auto x1 = x.col(0).array();
        const VectorXd x_rest_sq = x.block(0, 1, x.rows(), n - 1).array().square().rowwise().sum();
        VectorXd scores = x1 + d * (x_rest_sq.array().pow(alpha));
        return scores;
    }

    VectorXd rosenbrock(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        const int m = x.rows();
        const auto xi = x.block(0, 0, m, n - 1).array();
        const auto xi_plus_1 = x.block(0, 1, m, n - 1).array();
        VectorXd scores = (100 * (xi_plus_1 - xi.square()).square() + (xi - 1).square()).rowwise().sum();
        return scores;
    }

    VectorXd salomon(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const VectorXd sqrtsumx2 = x.array().square().rowwise().sum().sqrt();
        return 1 - (2 * M_PI * sqrtsumx2.array()).cos() + 0.1 * sqrtsumx2.array();
    }

    VectorXd schafferf6(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 2) throw std::invalid_argument("The Schaffer F6 function is only defined on a 2D space.");
        const auto X2 = x.col(0).array().square();
        const auto Y2 = x.col(1).array().square();
        const auto x2y2 = X2 + Y2;
        const VectorXd numerator = (x2y2.sqrt().sin().square()) - 0.5;
        const VectorXd denominator = (1.0 + 0.001 * x2y2).square();
        return 0.5 + numerator.array() / denominator.array();
    }

    VectorXd schafferf7(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        const int m = x.rows();
        VectorXd scores = VectorXd::Zero(m);
        for (int i = 0; i < n - 1; ++i) {
            const auto si = (x.col(i).array().square() + x.col(i+1).array().square()).sqrt();
            scores.array() += si.sqrt() * ((50.0 * si.pow(0.2)).sin().square() + 1.0);
        }
        return scores;
    }

    VectorXd schaffern1(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 2) throw std::invalid_argument("The Schaffer N. 1 function is only defined on a 2D space.");
        const auto X2 = x.col(0).array().square();
        const auto Y2 = x.col(1).array().square();
        const VectorXd num = (sin((X2 + Y2).square()).square()) - 0.5;
        const VectorXd den = (1 + 0.001 * (X2 + Y2)).square();
        return 0.5 + num.array() / den.array();
    }

    VectorXd schaffern2(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 2) throw std::invalid_argument("The Schaffer N. 2 function is only defined on a 2D space.");
        const auto X2 = x.col(0).array().square();
        const auto Y2 = x.col(1).array().square();
        const VectorXd num = (sin(X2 - Y2).square()) - 0.5;
        const VectorXd den = (1 + 0.001 * (X2 + Y2)).square();
        return 0.5 + num.array() / den.array();
    }

    VectorXd schaffern3(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 2) throw std::invalid_argument("The Schaffer N. 3 function is only defined on a 2D space.");
        const auto X2 = x.col(0).array().square();
        const auto Y2 = x.col(1).array().square();
        const VectorXd num = (sin(cos(abs(X2 - Y2))).square()) - 0.5;
        const VectorXd den = (1 + 0.001 * (X2 + Y2)).square();
        return 0.5 + num.array() / den.array();
    }

    VectorXd schaffern4(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 2) throw std::invalid_argument("The Schaffer N. 4 function is only defined on a 2D space.");
        const auto X2 = x.col(0).array().square();
        const auto Y2 = x.col(1).array().square();
        const VectorXd num = (cos(sin(abs(X2 - Y2))).square()) - 0.5;
        const VectorXd den = (1 + 0.001 * (X2 + Y2)).square();
        return 0.5 + num.array() / den.array();
    }

    VectorXd schwefel(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        return 418.9829 * n - (x.array() * sin(sqrt(abs(x.array())))).rowwise().sum();
    }

    VectorXd schwefel220(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        return x.array().abs().rowwise().sum();
    }

    VectorXd schwefel221(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        return x.array().abs().rowwise().maxCoeff();
    }

    VectorXd schwefel222(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        return x.array().abs().rowwise().sum() + x.array().abs().rowwise().prod();
    }

    VectorXd schwefel223(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        return x.array().pow(10).rowwise().sum();
    }

    VectorXd schwefel12(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        const int m = x.rows();
        MatrixXd cumsums = MatrixXd::Zero(m, n);
        cumsums.col(0) = x.col(0);
        for (int i = 1; i < n; ++i) cumsums.col(i) = cumsums.col(i - 1) + x.col(i);
        return cumsums.array().square().rowwise().sum();
    }

    VectorXd shekel5(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int m = x.rows();
        const MatrixXd a = (MatrixXd(5, 4) << 4, 4, 4, 4, 1, 1, 1, 1, 8, 8, 8, 8, 6, 6, 6, 6, 3, 7, 3, 7).finished();
        const VectorXd c = (VectorXd(5) << 0.1, 0.2, 0.2, 0.4, 0.4).finished();
        VectorXd scores = VectorXd::Zero(m);
        for (int i = 0; i < 5; i++) {
            scores.array() -= 1.0 / ((x.rowwise() - a.row(i)).array().square().rowwise().sum() + c(i));
        }
        return scores;
    }

    VectorXd shekel7(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int m = x.rows();
        const MatrixXd a = (MatrixXd(7, 4) << 4, 4, 4, 4, 1, 1, 1, 1, 8, 8, 8, 8, 6, 6, 6, 6, 3, 7, 3, 7, 2, 9, 2, 9, 5, 5, 3, 3).finished();
        const VectorXd c = (VectorXd(7) << 0.1, 0.2, 0.2, 0.4, 0.4, 0.6, 0.3).finished();
        VectorXd scores = VectorXd::Zero(m);
        for (int i = 0; i < 7; i++) {
            scores.array() -= 1.0 / ((x.rowwise() - a.row(i)).array().square().rowwise().sum() + c(i));
        }
        return scores;
    }

    VectorXd shekel10(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int m = x.rows();
        const MatrixXd a = (MatrixXd(10, 4) << 4, 4, 4, 4, 1, 1, 1, 1, 8, 8, 8, 8, 6, 6, 6, 6, 3, 7, 3, 7, 2, 9, 2, 9, 5, 5, 3, 3, 8, 1, 8, 1, 6, 2, 6, 2, 2, 5, 8, 2).finished();
        const VectorXd c = (VectorXd(10) << 0.1, 0.2, 0.2, 0.4, 0.4, 0.6, 0.3, 0.7, 0.5, 0.5).finished();
        VectorXd scores = VectorXd::Zero(m);
        for (int i = 0; i < 10; i++) {
            scores.array() -= 1.0 / ((x.rowwise() - a.row(i)).array().square().rowwise().sum() + c(i));
        }
        return scores;
    }

    VectorXd shubert(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        const int m = x.rows();
        MatrixXd col_sums = MatrixXd::Zero(m, n);
        for (int j = 1; j <= 5; j++) col_sums.array() += j * (((j + 1.0) * x.array() + j).cos());
        return col_sums.rowwise().prod();
    }

    VectorXd shubertn3(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        const int m = x.rows();
        MatrixXd col_sums = MatrixXd::Zero(m, n);
        for (int j = 1; j <= 5; j++) col_sums.array() += j * (((j + 1.0) * x.array() + j).sin());
        return col_sums.rowwise().sum();
    }

    VectorXd shubertn4(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        const int m = x.rows();
        MatrixXd col_sums = MatrixXd::Zero(m, n);
        for (int j = 1; j <= 5; j++) col_sums.array() += (((j + 1.0) * x.array() + j).cos());
        return col_sums.rowwise().sum();
    }

    VectorXd sphere(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        return x.array().square().rowwise().sum();
    }

    VectorXd step(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        return (x.array() + 0.5).floor().square().rowwise().sum();
    }

    VectorXd stretchedvsine(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        const int m = x.rows();
        if (n < 2) return VectorXd::Zero(m);
        VectorXd scores = VectorXd::Zero(m);
        for (int i = 0; i < n - 1; ++i) {
            const auto v = x.col(i).array().square() + x.col(i + 1).array().square();
            scores.array() += v.pow(0.25) * ((50.0 * v.pow(0.1)).sin().square() + 0.1);
        }
        return scores;
    }

    VectorXd styblinskitank(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const auto x_array = x.array();
        return 0.5 * (x_array.pow(4) - 16 * x_array.square() + 5 * x_array).rowwise().sum();
    }

    VectorXd sumsquares(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        const int m = x.rows();
        const MatrixXd I = RowVectorXd::LinSpaced(n, 1, n).replicate(m, 1);
        return (I.array() * x.array().square()).rowwise().sum();
    }

    VectorXd threehumpcamel(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 2) throw std::invalid_argument("The Three-hump Camel function only accepts 2D inputs");
        const auto X = x.col(0).array();
        const auto Y = x.col(1).array();
        return 2 * X.square() - 1.05 * X.pow(4) + X.pow(6) / 6.0 + X * Y + Y.square();
    }

    VectorXd sixhumpcamel(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 2) throw std::invalid_argument("The Six-hump Camel function only accepts 2D inputs");
        const auto X = x.col(0).array();
        const auto Y = x.col(1).array();
        return (4 - 2.1 * X.square() + X.pow(4) / 3.0) * X.square() + X * Y + (-4 + 4 * Y.square()) * Y.square();
    }

    VectorXd treccani(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 2) throw std::invalid_argument("The Treccani function only accepts 2D inputs");
        const auto X = x.col(0).array();
        const auto Y = x.col(1).array();
        return X.pow(4) - 4 * X.cube() + 4 * X.square() + Y.square();
    }

    VectorXd trid(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        const int m = x.rows();
        VectorXd scores = (x.array() - 1).square().rowwise().sum();
        if (n > 1) scores -= (x.block(0, 1, m, n - 1).array() * x.block(0, 0, m, n - 1).array()).rowwise().sum().matrix();
        return scores;
    }

    VectorXd vincent(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        return -(sin(10 * x.array().sqrt())).rowwise().sum();
    }

    VectorXd watson(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 6) throw std::invalid_argument("The Watson function only accepts 6D inputs");
        const int m = x.rows();
        VectorXd scores = VectorXd::Zero(m);
        for (int i = 0; i < 31; i++) {
            const double ti = i / 29.0;
            VectorXd sum1 = VectorXd::Zero(m);
            for (int j = 1; j < n; j++) sum1.array() += j * x.col(j).array() * pow(ti, j - 1);
            VectorXd sum2 = VectorXd::Zero(m);
            for (int j = 0; j < n; j++) sum2.array() += x.col(j).array() * pow(ti, j);
            scores += (sum1.array() - sum2.array().square() - 1.0).square().matrix();
        }
        scores += x.col(0).array().square().matrix();
        scores += (x.col(1).array() - x.col(0).array().square() - 1.0).square().matrix();
        return scores;
    }

    VectorXd wavy(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x, double k) {
        const int n = x.cols();
        return 1 - (cos(k * x.array()) * exp(-x.array().square() / 2.0)).rowwise().sum() / static_cast<double>(n);
    }

    VectorXd wayburnseadern2(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 2) throw std::invalid_argument("The Wayburn-Seader N. 02 function only accepts 2D inputs");
        const auto X = x.col(0).array();
        const auto Y = x.col(1).array();
        return (1.613 - 4 * (X - 0.3125).square() - 4 * (Y - 1.625).square()).square() + (Y - 1).square();
    }

    VectorXd whitley(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        const int m = x.rows();
        VectorXd scores = VectorXd::Zero(m);
        for (int i = 0; i < n; ++i) {
            const auto xi = x.col(i).array();
            for (int j = 0; j < n; ++j) {
                const auto xj = x.col(j).array();
                const VectorXd temp = 100.0 * (xi.square() - xj).square() + (1.0 - xj).square();
                scores += ((temp.array().square() / 4000.0) - temp.array().cos() + 1.0).matrix();
            }
        }
        return scores;
    }

    VectorXd weierstrass(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& X, double a, double b, int kmax) {
        const int num_rows = X.rows();
        const int n = X.cols();
        VectorXd k_vec = VectorXd::LinSpaced(kmax + 1, 0, kmax);
        const auto a_k = ArrayXd::Constant(kmax + 1, a).pow(k_vec.array());
        const ArrayXd b_k = ArrayXd::Constant(kmax + 1, b).pow(k_vec.array());
        MatrixXd term1_sum_k = MatrixXd::Zero(num_rows, n);
        for (int k = 0; k <= kmax; ++k) term1_sum_k += a_k(k) * (2 * M_PI * b_k(k) * (X.array() + 0.5)).cos().matrix();
        const double second_sum_term = n * (a_k * (M_PI * b_k).cos()).sum();
        return term1_sum_k.rowwise().sum().array() - second_sum_term;
    }

    VectorXd wolfe(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        if (x.cols() != 3) throw std::invalid_argument("Wolfe is 3D only");
        const auto X = x.col(0).array();
        const auto Y = x.col(1).array();
        const auto Z = x.col(2).array();
        return (4.0 / 3.0) * (X.square() + Y.square() - X * Y).pow(0.75) + Z;
    }

    VectorXd xinsheyangn1(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        const int m = x.rows();
        const VectorXd exponents = RowVectorXd::LinSpaced(n, 1, n);
        const MatrixXd rand_values = (MatrixXd::Random(m, n).array() + 1) / 2.0;
        return (rand_values.array() * x.array().abs().pow(exponents.transpose().array().replicate(m, 1))).rowwise().sum();
    }

    VectorXd xinsheyangn2(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        return x.array().abs().rowwise().sum() * (-x.array().square().sin().rowwise().sum()).exp();
    }

    VectorXd xinsheyangn3(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x, double beta, double m) {
        const VectorXd sum1 = (-(x.array() / beta).pow(2 * m)).rowwise().sum().exp();
        const VectorXd sum2 = (-x.array().square()).rowwise().sum().exp();
        const VectorXd prod1 = (x.array().cos().square()).rowwise().prod();
        return sum1.array() - 2 * sum2.array() * prod1.array();
    }

    VectorXd xinsheyangn4(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const VectorXd s1 = x.array().sin().square().rowwise().sum();
        const VectorXd s2 = (-x.array().square()).rowwise().sum().exp();
        const VectorXd s3 = (-x.array().abs().sqrt().sin().square()).rowwise().sum().exp();
        return (s1.array() - s2.array()) * s3.array();
    }

    VectorXd zakharov(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        const int m = x.rows();
        const VectorXd s1 = x.array().square().rowwise().sum();
        const MatrixXd I = RowVectorXd::LinSpaced(n, 1, n).replicate(m, 1);
        const VectorXd s2 = (0.5 * I.array() * x.array()).rowwise().sum();
        return s1.array() + s2.array().square() + s2.array().pow(4);
    }

    VectorXd zerosum(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const VectorXd s = x.rowwise().sum();
        VectorXd scores = 1.0 + sqrt(10000 * s.array().abs());
        return scores.unaryExpr([](double v) { return v == 1.0 ? 0.0 : v; });
    }

    VectorXd zettel(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        if (x.cols() != 2) throw std::invalid_argument("Zettel is 2D only");
        const auto X = x.col(0).array();
        const auto Y = x.col(1).array();
        return 0.25 * X - (X.square() - 2 * X + Y.square()).square();
    }

    VectorXd zimmerman(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        if (x.cols() != 2) throw std::invalid_argument("Zimmerman is 2D only");
        const auto X = x.col(0).array();
        const auto Y = x.col(1).array();
        const VectorXd zh1 = 9 - X - Y;
        const VectorXd zh2 = (X - 3).square() + (Y - 2).square() - 16;
        const VectorXd zh3 = X * Y - 14;
        auto zp = [](const VectorXd& v) { return 100 * (1 + v.array()); };
        MatrixXd signs(x.rows(), 5);
        signs.col(0) = zh1;
        signs.col(1) = zp(zh2).array() * zh2.array().sign();
        signs.col(2) = zp(zh3).array() * zh3.array().sign();
        signs.col(3) = zp(-X).array() * (X).array().sign();
        signs.col(4) = zp(-Y).array() * (Y).array().sign();
        return signs.rowwise().maxCoeff();
    }

    VectorXd zirilli(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        if (x.cols() != 2) throw std::invalid_argument("Zirilli is 2D only");
        const auto X = x.col(0).array();
        const auto Y = x.col(1).array();
        return 0.25 * X.pow(4) - 0.5 * X.square() + 0.1 * X + 0.5 * Y.square();
    }

} // namespace BenchmarkFcns
