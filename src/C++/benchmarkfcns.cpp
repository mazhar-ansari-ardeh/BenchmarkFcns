#include "benchmarkfcns.h"

namespace BenchmarkFcns {

    using namespace Eigen;

    VectorXd sphere(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& inputMatrix) {
        MatrixXd squaredValues = inputMatrix.array().square();

        VectorXd scores = squaredValues.rowwise().sum();

        return scores;
    }

    VectorXd ackley(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        constexpr double a = 20;
        constexpr double b = 0.2;
        constexpr double c = 2 * M_PI;
        const double ninverse = 1.0 / n;

        auto sum1 = x.array().square().rowwise().sum();
        auto sum2 = (c * x).array().cos().rowwise().sum();

        VectorXd scores = -(a * exp(-b * (sum1 * ninverse).sqrt())) + a - exp(sum2 * ninverse) + exp(1);

        return scores;
    }

    VectorXd ackleyn2(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("Ackley2 function only accepts 2D input.");

        auto X = x.col(0);
        auto Y = x.col(1);

        VectorXd scores = -200 * exp(-0.02 * ((X.array().square() + Y.array().square()).sqrt()));
        return scores;
    }

    VectorXd ackleyn3(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Ackleyn3 function only accepts 2D inputs.");

        auto X = x.col(0);
        auto Y = x.col(1);

        VectorXd scores = -200 * exp(-0.2 * ((X.array().square() + Y.array().square()).sqrt())) + 5 * exp(cos(3 * X.array()) + sin(3 * Y.array()));

        return scores;
    }

    VectorXd ackleyn4(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int m = x.rows();
        int n = x.cols();

        MatrixXd term1 = exp(-0.2) * ((x.block(0, 0, m, n - 1).array().square() + x.block(0, 1, m, n - 1).array().square()).sqrt());
        MatrixXd term2 = 3 * (cos(2 * x.block(0, 0, m, n - 1).array()) + sin(2 * x.block(0, 1, m, n - 1).array()));

        VectorXd scores = (term1 + term2).rowwise().sum();

        return scores;
    }

    VectorXd adjiman(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Adjiman function only accepts 2D inputs.");

        auto X = x.col(0);
        auto Y = x.col(1);

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
        double ninv = 1.0 / x.cols();

        VectorXd comp1 = (x.rowwise().prod().array().pow(ninv));
        VectorXd comp2 = x.rowwise().mean();
        return (comp1 - comp2).array().square();
    }

    VectorXd bartelsconn(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Bartels Conn function only accepts 2D inputs.");

        auto X = x.col(0);
        auto Y = x.col(1);

        VectorXd scores = (X.array().square() + Y.array().square() + X.array() * Y.array()).abs() + (X.array().sin()).abs() + (Y.array().cos()).abs();
        return scores;
    }

    VectorXd beale(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Beale function only accepts 2D inputs.");

        auto X = x.col(0);
        auto Y = x.col(1);

        VectorXd scores = (1.5 - X.array() + (X.array() * Y.array())).square() +
                        (2.25 - X.array() + (X.array() * (Y.array().square()))).square() +
                        (2.625 - X.array() + (X.array() * (Y.array().cube()))).square();
        return scores;
    }

    VectorXd bird(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Bird function only accepts 2D inputs.");

        auto X = x.col(0);
        auto Y = x.col(1);

        VectorXd scores = (X.array().sin() * exp((1 - Y.array().cos()).square())) +
                        (Y.array().cos() * exp((1 - X.array().sin()).square())) +
                        (X - Y).array().square();
        return scores;
    }

    VectorXd bohachevskyn1(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Bohachevsky N1 function only accepts 2D inputs.");

        auto X = x.col(0);
        auto Y = x.col(1);

        VectorXd scores = (X.array().square() + 2 * Y.array().square() - 0.3 * cos(3 * M_PI * X.array()) - 0.4 * cos(4 * M_PI * Y.array()) + 0.7);
        return scores;
    }

    VectorXd bohachevskyn2(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Bohachevsky N2 function only accepts 2D inputs");

        auto X = x.col(0);
        auto Y = x.col(1);

        VectorXd scores = (X.array().square() + 2 * Y.array().square() - 0.3 * cos(3 * M_PI * X.array()) * cos(4 * M_PI * Y.array()) + 0.3);
        return scores;
    }
    // TODO: Implement the bohachevsky3 function.

    VectorXd booth(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Booth function only accepts 2D inputs.");

        auto X = x.col(0);
        auto Y = x.col(1);

        VectorXd scores = ((X + 2 * Y).array() - 7).array().square() + ((2 * X + Y).array() - 5).array().square();
        return scores;
    }

    VectorXd braninn1(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Branin N. 1 function is only defined on a 2D space.");

        auto X = x.col(0).array();
        auto Y = x.col(1).array();
        constexpr double A = -1.275 / (M_PI * M_PI);
        constexpr double C = 10 - 5 / (4 * M_PI);
        constexpr double FIVE_OVER_PI = 5 / M_PI;

        VectorXd scores = (A * X.square() + FIVE_OVER_PI * X + Y - 6).array().square() +
                    (C) * cos(X) + 10;
        return scores;
    }

    VectorXd braninn2(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Branin N. 2 function is only defined on a 2D space.");

        auto X = x.col(0).array();
        auto Y = x.col(1).array();
        constexpr double A = -1.275 / (M_PI * M_PI);
        constexpr double C = 10 - 5 / (4 * M_PI);
        constexpr double FIVE_OVER_PI = 5 / M_PI;

        VectorXd scores = (A * X.square() + FIVE_OVER_PI * X + Y - 6).array().square() +
                          (C) * cos(X) * cos(Y) + log(X.square() +
                          Y.square() + 1) + 10;
        return scores;
    }

    VectorXd brent(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Brent function is defined only on the 2-D space.");

        auto X = x.col(0);
        auto Y = x.col(1);

        VectorXd scores = (X.array() + 10).square() + (Y.array() + 10).square() + (-X.array().square() - Y.array().square()).exp();
        return scores;
    }

    VectorXd brown(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int n = x.cols();
        Eigen::MatrixXd x_squared = x.array().square();
        Eigen::VectorXd scores = ((x_squared.leftCols(n - 1).array().pow(x_squared.rightCols(n - 1).array() + 1)) +
                                  (x_squared.rightCols(n - 1).array().pow(x_squared.leftCols(n - 1).array() + 1))).rowwise().sum();

        return scores;
    }

    VectorXd bukinn2(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Bukin N. 2 functions is only defined on a 2D space.");

        auto X = x.col(0);
        auto Y = x.col(1);

        VectorXd scores = 100 * (Y.array().square() - 0.01 * X.array().square() + 1) + 0.01 * ((X.array() + 10).square());
        return scores;
    }

    VectorXd bukinn4(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Bukin N. 4 functions is only defined on a 2D space.");

        auto X = x.col(0);
        auto Y = x.col(1);

        VectorXd scores = 100 * Y.array().square() + 0.01 * (X.array() + 10).array().abs();
        return scores;
    }

    VectorXd bukinn6(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Bukin N. 6 functions is only defined on a 2D space.");

        auto X = x.col(0);
        auto X2 = X.array().square();
        auto Y = x.col(1);

        VectorXd scores = 100 * (Y.array() - 0.01 * X2).array().abs().sqrt() + 0.01 * (X.array() + 10).array().abs();
        return scores;
    }

    VectorXd carromtable(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Carromtable function is only defined on a 2D space.");

        auto X = x.col(0).array();
        auto Y = x.col(1).array();

        VectorXd ex = 1 - ((X.square() + Y.square()).sqrt() / M_PI);
        VectorXd scores = - (1.0 / 30) * exp(2 * ex.array().abs())
                                       * (cos(X).square())
                                       * (cos(Y).square());
        return scores;
    }

    VectorXd chichinadze(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Chichinadze function is only defined on a 2D space.");

        auto X = x.col(0).array();
        auto Y = x.col(1).array();

        VectorXd scores = X.square()
                          - 12 * X
                          + 8 * sin(5 * M_PI * X / 2)
                          + 10 * cos(M_PI * X / 2)
                          + 11
                          - 0.2 * sqrt(5) / exp((Y - 0.5).square() / 2);
        return scores;
    }

    VectorXd cigar(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int n = x.cols();
        VectorXd scores = x.col(0).array().square() + 1e6 * x.block(0, 1, x.rows(), n - 1).array().square().rowwise().sum();
        return scores;
    }

    VectorXd cosinemixture(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        constexpr double FIVE_PI = 5 * M_PI;
        VectorXd scores = -0.1 * (x.array() * FIVE_PI).cos().rowwise().sum() - x.array().square().rowwise().sum();
        return scores;
    }

    VectorXd crossintray(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Cross-in-tray function is only defined on a 2D space.");

        auto X = x.col(0).array();
        auto Y = x.col(1).array();

        VectorXd expcomponent = (100 - (sqrt(X.square() + Y.square()) / M_PI)).array().abs();
        VectorXd scores = -0.0001 * ((sin(X) * sin(Y) * expcomponent.array().exp()).array().abs() + 1).array().pow(0.1);
        return scores;
    }

    VectorXd crownedcross(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Crowned Cross function is only defined on the 2D space.");

        auto X = x.col(0).array();
        auto Y = x.col(1).array();

        VectorXd expcomponent = (100 - (sqrt(X.square() + Y.square()) / M_PI)).array().abs();
        VectorXd scores = 0.0001 * (((exp(expcomponent.array()).array() * sin(X) * sin(Y))).array().abs() + 1).pow(0.1);
        return scores;
    }

    VectorXd csendes(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        VectorXd scores = (x.array().pow(6) * (2 + sin(1 / x.array()))).rowwise().sum();
        return scores;
    }

    VectorXd cubefcn(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Cube function is only defined on the 2-D space.");

        auto X = x.col(0).array();
        auto Y = x.col(1).array();

        VectorXd scores = 100 * (Y - X.cube()).square() + (1 - X).square();
        return scores;
    }

    VectorXd debn1(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int n = x.cols();
        VectorXd scores = - (x.array() * 5 * M_PI).sin().pow(6).rowwise().sum() / n;
        return scores;
    }

    VectorXd deckkersaarts(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Deckkers-Aarts function is only defined on a 2D space.");

        auto X = x.col(0).array();
        auto Y = x.col(1).array();

        VectorXd scores = (100000 * X.square()) + Y.square() - (X.square() + Y.square()).array().square() + pow(10, -5) * (X.square() + Y.square()).array().pow(4);
        return scores;
    }

    VectorXd dropwave(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Drop Wave function is only defined on a 2D space.");

        auto X_squared = x.col(0).array().square();
        auto Y_squared = x.col(1).array().square();

        VectorXd numeratorcomp = 1 + cos(12 * (X_squared + Y_squared).sqrt());
        VectorXd denumeratorcom = (0.5 * (X_squared + Y_squared)) + 2;
        VectorXd scores = -numeratorcomp.array() / denumeratorcom.array();

        return scores;
    }

    VectorXd easom(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Easom function is only defined on a 2D space.");

        auto X = x.col(0).array();
        auto Y = x.col(1).array();

        VectorXd scores = -cos(X) * cos(Y) * exp(-((X - M_PI).square() + (Y - M_PI).square()));

        return scores;
    }

    VectorXd eggholder(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Eggholder function is only defined on a 2D space.");

        auto X = x.col(0).array();
        auto Y = x.col(1).array();

        VectorXd sin1component = -(Y + 47) * sin(sqrt((X / 2).abs() + Y + 47));
        VectorXd sin2component = X * sin(sqrt(X - Y + 47));

        VectorXd scores =  sin1component - sin2component;

        return scores;
    }

    VectorXd eggcrate(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Egg Crate function is only defined on a 2D space.");

        auto X = x.col(0).array();
        auto Y = x.col(1).array();

        VectorXd scores = X.square() + Y.square() + (25 * (sin(X).square() + sin(Y).square()));

        return scores;
    }

    VectorXd elattar(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The El-Attar et al. function is only defined on a 2D space.");

        auto X = x.col(0).array();
        auto Y = x.col(1).array();

        VectorXd scores = (X.square() + Y - 10).square() + (X + Y.square() - 7).square() + (X.square() + Y.cube() - 1).square();

        return scores;
    }

    VectorXd exponential(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        VectorXd scores = -exp(-0.5 * x.array().square().rowwise().sum());

        return scores;
    }

    VectorXd forrester(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x)
    {
        int n = x.cols();
        if (n != 1)
            throw std::invalid_argument("The Forrester function is only defined on a 1D space.");

        auto X = x.col(0).array();

        VectorXd scores = (6 * X - 2).square() * sin(12 * X - 4);

        return scores;
    }

    VectorXd giunta(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        constexpr double A = 16.0 / 15.0;
        constexpr double B = 64.0 / 15.0;
        VectorXd scores = 0.6 + ((sin(1 - A * x.array()).square())
                              - (0.02) * sin(4 - B * x.array())
                              - sin(1 - A * x.array())).rowwise().sum();
        return scores;
    }

    VectorXd goldsteinprice(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Goldstein-Price function is only defined on a 2D space.");

        auto X = x.col(0).array();
        auto Y = x.col(1).array();

        VectorXd scores = (1 + ((X + Y + 1).square() * (19 - 14 * X + 3 * X.square() - 14 * Y + 6 * X * Y + 3 * Y.square()))).array() *
                        (30 + ((2 * X - 3 * Y).square() * (18 - 32 * X + 12 * X.square() + 48 * Y - 36 * X * Y + 27 * Y.square()))).array();

        return scores;
    }

    VectorXd gramacylee(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int n = x.cols();
        if (n != 1)
            throw std::invalid_argument("The Gramacy & Lee function is only defined on a 1D space.");

        auto X = x.col(0).array();
        constexpr double TEN_PI = 10 * M_PI;

        VectorXd scores = (sin(TEN_PI * X) / (2 * X) ) + ((X - 1).pow(4));

        return scores;
    }

    VectorXd griewank(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int n = x.cols();

        VectorXd sumcomp = x.array().square().rowwise().sum();
        VectorXd prodcomp = (x.array().rowwise() / (RowVectorXd::LinSpaced(n, 1, n).array().sqrt())).cos().rowwise().prod();
        VectorXd scores = (sumcomp.array() / 4000) - prodcomp.array() + 1;

        return scores;
    }

    VectorXd happycat(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x, double alpha) {
        int n = x.cols();
        VectorXd x2 = x.array().square().rowwise().sum();
        VectorXd scores = ((x2.array() - n).square()).pow(alpha) + ((0.5 * x2 + x.rowwise().sum())).array() / n + 0.5;
        return scores;
    }

    VectorXd holdertable(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Holdertablefcn function is only defined on a 2D space.");

        auto X = x.col(0).array();
        auto Y = x.col(1).array();

        VectorXd expcomponent = exp(abs(1 - (sqrt(X.square() + Y.square()) / M_PI)));
        VectorXd scores = -abs(sin(X).array() * cos(Y).array() * expcomponent.array());
        return scores;
    }

    VectorXd himmelblau(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Himmelblau's function is only defined on a 2D space.");

        auto X = x.col(0).array();
        auto Y = x.col(1).array();

        VectorXd scores = (X.square() + Y - 11).square() + (X + Y.square() - 7).square();
        return scores;
    }

    VectorXd keane(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Keane's function is only defined on a 2D space.");

        auto X = x.col(0).array();
        auto Y = x.col(1).array();
        VectorXd numeratorcomp = (sin(X - Y).square()) * (sin(X + Y).square());
        VectorXd denominatorcomp = (X.square() + Y.square()).sqrt();
        VectorXd scores = - numeratorcomp.array() / denominatorcomp.array();

        return scores;
    }

    VectorXd leon(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Leon function is only defined on a 2D space.");

        auto X = x.col(0).array();
        auto Y = x.col(1).array();
        VectorXd scores = 100 * ((Y - X.cube()).square()) + ((1 - X).square());
        return scores;
    }

    VectorXd levin13(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Levi's function is only defined on a 2D space.");

        auto X = x.col(0).array();
        auto Y = x.col(1).array();
        VectorXd scores = (sin(3 * M_PI * X).square()) +
                        ((X - 1).square()) * (1 + sin(3 * M_PI * Y).square()) +
                        ((Y - 1).square()) * (1 + sin(2 * M_PI * Y).square());
        return scores;
    }

    VectorXd matyas(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Matyas' function is only defined on a 2D space.");

        auto X = x.col(0).array();
        auto Y = x.col(1).array();

        VectorXd scores = 0.26 * (X.square() + Y.square()) - 0.48 * X * Y;
        return scores;
    }

    VectorXd mccormick(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The McCormick function is only defined on a 2D space.");

        auto X = x.col(0).array();
        auto Y = x.col(1).array();

        VectorXd scores = sin(X + Y) + ((X - Y).square()) - 1.5 * X + 2.5 * Y + 1;
        return scores;
    }

    VectorXd periodic(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        VectorXd sin2x = (x.array().sin()).square().rowwise().sum();
        VectorXd sumx2 = x.array().square().rowwise().sum();
        VectorXd scores = 1 + sin2x.array() - 0.1 * exp(-sumx2.array());
        return scores;
    }

    VectorXd picheny(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Picheny function is only defined on a 2D space.");

        auto X = 4 * x.col(0).array() - 2;
        auto Y = 4 * x.col(1).array() - 2;

        VectorXd term = (1 + ((X + Y + 1).square() * (19 - 14 * X + 3 * X.square() - 14 * Y + 6 * X * Y + 3 * Y.square()))).array() *
                        (30 + ((2 * X - 3 * Y).square() * (18 - 32 * X + 12 * X.square() + 48 * Y - 36 * X * Y + 27 * Y.square())).array());
        constexpr double coef = 1 / 2.427;
        VectorXd scores = coef * (log10(term.array()) - 8.693);
        return scores;
    }

    VectorXd powellsum(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int n = x.cols();
        MatrixXd absx = x.array().abs(); // WARNING: absx is not used. This is a bug.
        VectorXd powers = RowVectorXd::LinSpaced(n, 2, n + 1);
        // Warning: the replicate method may lead to a large memory overhead for large matrices.
        auto scores = absx.array().pow(powers.transpose().array().replicate(x.rows(), 1)).rowwise().sum();
        return scores;
    }

    VectorXd qing(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int n = x.cols();
        MatrixXd x2 = x.array().square();
        VectorXd i_values = RowVectorXd::LinSpaced(n, 1, n);
        VectorXd scores = (x2 - i_values.transpose().replicate(x.rows(), 1)).array().square().rowwise().sum();

        return scores;
    }

    VectorXd quartic(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int n = x.cols();
        MatrixXd x_powered = x.array().pow(4);

        MatrixXd indices = RowVectorXd::LinSpaced(n, 1, n).replicate(x.rows(), 1);

        VectorXd scores = x_powered.cwiseProduct(indices).rowwise().sum();
        scores = scores + VectorXd::Random(x.rows());

        return scores;
    }

    VectorXd rastrigin(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int n = x.cols();
        const double A = 10;
        constexpr double TWO_PI = 2 * M_PI;
        VectorXd scores = (A * n) + (x.array().square().rowwise().sum() - A * (x.array() * (TWO_PI)).cos().rowwise().sum());
        return scores;
    }

    VectorXd ridge(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x, double d, double alpha) {
        Eigen::VectorXd x1 = x.col(0);

        Eigen::VectorXd squared_sum = (x.block(0, 1, x.rows(), x.cols() - 1).array().square()).rowwise().sum();
        Eigen::VectorXd scores = x1.array() + d * squared_sum.array().pow(alpha);

        return scores;
    }

    VectorXd rosenbrock(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const double a = 1;
        const double b = 100;

        MatrixXd x_2 = x.array().square();
        int ncols = x.cols();
        int nrows = x.rows();

        MatrixXd term1 = b * (x.block(0, 1, nrows, ncols - 1).array() - x_2.block(0, 0, nrows, ncols - 1).array()).square();
        MatrixXd term2 = (a - x.block(0, 0, nrows, ncols - 1).array()).square();

        VectorXd scores = (term1 + term2).rowwise().sum();
        return scores;
    }

    VectorXd salomon(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        VectorXd sqrtsumx2 = x.array().square().rowwise().sum().array().sqrt();

        return 1 - (2 * M_PI * sqrtsumx2.array()).cos() + 0.1 * sqrtsumx2.array();
    }

    VectorXd schaffern1(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Schaffer N. 1 function is only defined on a 2D space.");

        auto X = x.col(0).array();
        auto Y = x.col(1).array();

        VectorXd numeratorcomp = (sin((X.square() + Y.square()).square()).square()) - 0.5;
        VectorXd denominatorcomp = (1 + 0.001 * (X.square() + Y.square())).square();
        VectorXd scores = 0.5 + numeratorcomp.array() / denominatorcomp.array();
        return scores;
    }

    VectorXd schaffern2(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Schaffer N. 2 function is only defined on a 2D space.");

        auto X2 = x.col(0).array().square();
        auto Y2 = x.col(1).array().square();

        VectorXd sincomponent = sin((X2 - Y2)).square();
        VectorXd scores = 0.5 + ((sincomponent.array() - 0.5) / (1 + 0.001 * (X2 + Y2)).square());

        return scores;
    }

    VectorXd schaffern3(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Schaffer N. 3 function is only defined on a 2D space.");

        auto X2 = x.col(0).array().square();
        auto Y2 = x.col(1).array().square();

        MatrixXd numeratorcomp = (sin(cos((X2 - Y2).abs())).square()) - 0.5;
        MatrixXd denominatorcomp = (1 + 0.001 * (X2 + Y2)).square();

        return 0.5 + numeratorcomp.array() / denominatorcomp.array();
    }

    VectorXd schaffern4(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Schaffer N. 4 function is only defined on a 2D space.");

        auto X2 = x.col(0).array().square();
        auto Y2 = x.col(1).array().square();

        MatrixXd numeratorcomp = (cos(sin((X2 - Y2).abs())).square()) - 0.5;
        MatrixXd denominatorcomp = (1 + 0.001 * (X2 + Y2)).square();

        return 0.5 + numeratorcomp.array() / denominatorcomp.array();
    }

    VectorXd schwefel(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int n = x.cols();
        return 418.9829 * n - (x.array() * (x.array().abs().sqrt()).sin()).rowwise().sum();
    }

    VectorXd schwefel220(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        return x.array().abs().rowwise().sum();
    }

    VectorXd schwefel221(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        return x.array().abs().rowwise().maxCoeff();
    }

    VectorXd schwefel222(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        MatrixXd absx = x.array().abs();
        return absx.rowwise().sum() + absx.rowwise().prod();
    }

    VectorXd schwefel223(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        return x.array().pow(10).rowwise().sum();
    }


    VectorXd shubert(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int n = x.cols();
        VectorXd scores = VectorXd::Ones(x.rows());
        for (int i = 0; i < n; i++) {
            VectorXd inner_sum = VectorXd::Zero(x.rows());
            for (int j = 1; j <= 5; j++) {
                auto y = j * cos(((j + 1) * x.col(i).array()) + j);
                inner_sum = inner_sum.array() + y;
            }
            scores = inner_sum.array() * scores.array();
        }

        return scores;
    }

    VectorXd shubertn3(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int n = x.cols();
        VectorXd scores = VectorXd::Zero(x.rows());
        for (int i = 0; i < n; i++) {
            VectorXd inner_sum = VectorXd::Zero(x.rows());
            for (int j = 1; j <= 5; j++) {
                auto y = j * sin(((j + 1) * x.col(i).array()) + j);
                inner_sum = inner_sum.array() + y;
            }
            scores = inner_sum.array() + scores.array();
        }
        return scores;
    }

    VectorXd shubertn4(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int n = x.cols();
        VectorXd scores = VectorXd::Zero(x.rows());
        for (int i = 0; i < n; i++) {
            VectorXd inner_sum = VectorXd::Zero(x.rows());
            for (int j = 1; j <= 5; j++) {
                auto y = cos(((j + 1) * x.col(i).array()) + j);
                inner_sum = inner_sum.array() + y;
            }
            scores = inner_sum.array() + scores.array();
        }
        return scores;
    }


    VectorXd styblinskitank(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        auto x_array = x.array();
        MatrixXd term1 = x_array.pow(4);
        MatrixXd term2 = 16 * x_array.square();
        MatrixXd term3 = 5 * x_array;
        VectorXd scores = (term1 - term2 + term3).rowwise().sum();
        scores *= 0.5;
        return scores;
    }

    VectorXd sumsquares(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int m = x.rows();
        int n = x.cols();
        MatrixXd x2 = x.array().square();
        MatrixXd I = RowVectorXd::LinSpaced(n, 1, n).replicate(m, 1);
        VectorXd scores = (I.array() * x2.array()).rowwise().sum();
        return scores;
    }

    VectorXd threehumpcamel(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Three-hump camel function is only defined on a 2D space.");

        auto X = x.col(0).array();
        auto Y = x.col(1).array();

        VectorXd scores = (2 * X.square()) - (1.05 * (X.pow(4))) + ((X.pow(6)) / 6) + X * Y + Y.square();
        return scores;
    }

    VectorXd treccani(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Treccani function is only defined on a 2D space.");

        auto X = x.col(0).array();
        auto Y = x.col(1).array();

        VectorXd scores = (X.pow(4) + 4 * X.pow(3) + 4 * X.pow(2) + Y.pow(2));
        return scores;
    }

    VectorXd trid(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        VectorXd scores = (x.array() - 1).square().rowwise().sum() - (x.block(0, 1, x.rows(), x.cols() - 1).array() * x.block(0, 0, x.rows(), x.cols() - 1).array()).rowwise().sum();
        return scores;
    }

    VectorXd vincent(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        VectorXd scores = -(10 * x.array().log()).array().sin().rowwise().sum();
        return scores;
    }

    VectorXd xinsheyangn1(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int n = x.cols();
        int m = x.rows();
        auto absx = x.array().abs();
        VectorXd exponents = RowVectorXd::LinSpaced(n, 1, n);
        // TODO: All functions that use rand should be rewritten to matrix form.
        MatrixXd rand_values = (MatrixXd::Random(m, n).array() + 1) / 2.0;
        return (rand_values.array() * absx.array().pow(exponents.transpose().array().replicate(m, 1))).rowwise().sum();
    }

    VectorXd xinsheyangn2(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        auto absx = x.array().abs();
        return absx.rowwise().sum() * (-sin(x.array().square())).rowwise().sum().exp();
    }

    VectorXd xinsheyangn3(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x, double beta, double m) {
        auto x_div_beta = x.array() / beta;
        VectorXd sum_x_div_beta_2m = (-x_div_beta.array().pow(2 * m)).rowwise().sum().exp();
        VectorXd sum_x_2 = (-x.array().square()).rowwise().sum().exp();
        VectorXd prod_cos_x_2 = (x.array().cos().square()).rowwise().prod();
        return sum_x_div_beta_2m.array() - (2 * sum_x_2.array() * prod_cos_x_2.array());
    }

    VectorXd xinsheyangn4(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        VectorXd sum_sin_x_2 = (x.array().sin().square()).rowwise().sum();
        VectorXd exp_sum_x_2 = (-x.array().square()).rowwise().sum().exp();
        VectorXd sum_sin_sqrt_abs_x_2 = (-sin(x.array().abs().sqrt()).square()).rowwise().sum().exp();
        return (sum_sin_x_2.array() - exp_sum_x_2.array()) * sum_sin_sqrt_abs_x_2.array();
    }

    VectorXd watson(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int n = x.cols();
        if (n != 6)
            throw std::invalid_argument("The Watson function is only defined on a 6D space.");
        static const VectorXd i = VectorXd::LinSpaced(30, 0, 29);
        static const VectorXd a = i / 29.0;
        static const RowVectorXd j = RowVectorXd::LinSpaced(5, 0, 4);
        static const MatrixXd aToTheJ = a.replicate(1, j.cols()).array().pow(j.replicate(a.rows(), 1).array()); // (a .^ j)
        static const auto jaj = (j.array()+1).replicate(aToTheJ.rows(), 1).array() * aToTheJ.array(); // (j-1)(a .^ j)
        static const RowVectorXd k = RowVectorXd::LinSpaced(6, 0, 5);
        static const MatrixXd aToTheK = a.replicate(1, k.cols()).array().pow(k.replicate(a.rows(), 1).array()); // (a .^ k)

        VectorXd scores(x.rows());
        unsigned int counter = 0;
        // TODO: Implement a more efficient way to compute the Watson function.
        // For the moment, Eigen's support for tensor operations is limited.
        // This is a very inefficient way to compute the function.
        for (auto xi : x.rowwise())
        {
            auto t1 = (jaj * xi.tail(x.size() - 1).transpose().replicate(aToTheJ.rows(), 1).array()).rowwise().sum();

            auto xrep = xi.transpose().replicate(aToTheK.rows(), 1);
            auto t2 = (aToTheK.array() * xrep.array()).rowwise().sum();

            auto score = (t1.array() - t2.array().square() - 1).array().square().sum() + std::pow(xi(0), 2);
            scores[counter++] = score;
        }
        return scores;
    }

    VectorXd wavy(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x, double k) {
        auto x2 = x.array().square() / 2;
        const auto n = x.cols();
        auto cos_kx = (cos(k * x.array()));
        auto exp_x2 = exp(-x2.array());
        auto scores = 1 - (1.0 / n) * (cos_kx.array() * exp_x2.array()).rowwise().sum();
        return scores;
    }

    VectorXd wayburnseadern2(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Wayburn-Seader N. 02 function is only defined on a 2D space.");

        auto X = x.col(0).array();
        auto Y = x.col(1).array();

        VectorXd scores = ((1.613 - 4 * (X - 0.3125).square() - 4 * (Y - 1.625).square()).square() + (Y - 1).square());
        return scores;
    }

    VectorXd wolfe(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        const int n = x.cols();
        if (n != 3)
            throw std::invalid_argument("The Wolfe function is only defined on a 3D space.");

        auto X = x.col(0).array();
        auto Y = x.col(1).array();
        auto Z = x.col(2).array();
        constexpr double A = 4.0 / 3.0;

        return (A) * (((X.square() + Y.square() - X * Y).pow(0.75))) + Z;
    }

    VectorXd yaoliun4(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        return x.array().abs().rowwise().maxCoeff();
    }

    VectorXd yaoliun9(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        constexpr double TWO_PI = 2 * M_PI;
        return (x.array().square() - 10 * (TWO_PI * x.array()).cos() + 10).rowwise().sum();
    }

    VectorXd zakharov(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int m = x.rows();
        int n = x.cols();

        VectorXd comp1 = x.array().square().rowwise().sum();
        MatrixXd I = RowVectorXd::LinSpaced(n, 1, n).replicate(m, 1);
        MatrixXd comp2 = 0.5 * I.array() * x.array();
        VectorXd sum_comp2 = comp2.rowwise().sum();
        return comp1.array() + sum_comp2.array().square() + sum_comp2.array().pow(4);
    }

    VectorXd zerosum(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        VectorXd s = x.rowwise().sum();
        VectorXd scores = 1.0 + sqrt(10000 * s.array().abs());
        scores = scores.unaryExpr([](double x) { return x == 1.0 ? 0.0 : x; });
        return scores;
    }

    VectorXd zettel(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Zettel function is only defined on the 2D space.");

        auto X = x.col(0).array();
        auto Y = x.col(1).array();

        VectorXd scores = 0.25 * X - (X.square() - 2 * X + Y.square()).square();
        return scores;
    }

    VectorXd zimmerman(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Zimmerman function is only defined on the 2D space.");

        auto X = x.col(0).array();
        auto Y = x.col(1).array();

        VectorXd zh1 = 9 - X - Y;
        VectorXd zh2 = (X - 3).square() + (Y - 2).square() - 16;
        VectorXd zh3 = X * Y - 14;
        auto zp = [](const VectorXd& x) { return 100 * (1 + x.array()); };

        MatrixXd signs(x.rows(), 5);
        signs.col(0) = zh1;
        signs.col(1) = zp(zh2).array() * zh2.array().sign();
        signs.col(2) = zp(zh3).array() * zh3.array().sign();
        signs.col(3) = zp(-X).array() * (X).array().sign();
        signs.col(4) = zp(-Y).array() * (Y).array().sign();
        VectorXd scores = signs.rowwise().maxCoeff();
        return scores;
    }

    VectorXd zirilli(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
        int n = x.cols();
        if (n != 2)
            throw std::invalid_argument("The Zirilli function is only defined on the 2D space.");

        auto X = x.col(0).array();
        auto Y = x.col(1).array();

        VectorXd scores = 0.25 * X.pow(4) - 0.5 * X.square() + 0.1 * X + 0.5 * Y.square();
        return scores;
    }

} // namespace BenchmarkFunctions
