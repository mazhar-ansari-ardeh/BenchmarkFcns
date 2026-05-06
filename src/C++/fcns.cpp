#include <Eigen/Dense>
#include <iostream>

using Eigen::MatrixXd;
// using Eigen::MatrixXdMap;
using namespace Eigen;

using Eigen::Dynamic;
using Eigen::Matrix;
using Eigen::MatrixXd;
using Eigen::Ref;
using Eigen::RowMajor;
// using Eigen::MatrixXdMap;
using namespace Eigen;
using namespace std;

/*
To run this code, simply chd to the directory where this file is located and run:
g++ -I eigen-3.4.0 fcns.cpp -std=c++20
*/

VectorXd func() {

    // MatrixXd m(2, 2);
    // m << 1, 2,
    //      3, 4;
    // cout << "Original Matrix:\n" << m << endl;
    // // Correct way to perform in-place scalar addition on a Matrix
    // m = m.array() + 5;
    // cout << "\nAfter m.array() + 5:\n" << m << endl;

    MatrixXd x(5, 3);
    x(0, 0) = 100.881815;
    x(0, 1) = 0.132688;
    x(0, 2) = 0.181562;
    x(1, 0) = 0.595656;
    x(1, 1) = 0.282805;
    x(1, 2) = 0.196698;
    x(2, 0) = 1;
    x(2, 1) = 1;
    x(2, 2) = 1;
    x(3, 0) = 7;
    x(3, 1) = 2;
    x(3, 2) = 0;
    x(4, 0) = 0.1146;
    x(4, 1) = 0.5556;
    x(4, 2) = 0.8525;

    cout << "xx: " << x << endl;

    static constexpr double alpha_content[4] = {1.0, 1.2, 3.0, 3.2};
    VectorXd alpha = Eigen::Map<const VectorXd>(alpha_content, 4);

    static constexpr double a[4][3] = {{3.0, 10, 30}, {0.1, 10, 35}, {3.0, 10, 30}, {0.1, 10, 35}};
    static const Eigen::Matrix<double, 4, 3, Eigen::RowMajor> A =
        Eigen::Map<const Eigen::Matrix<double, 4, 3, Eigen::RowMajor>>(&a[0][0]);

    static constexpr double p[4][3] = {{0.3689, 0.1170, 0.2673},
                                       {0.4699, 0.4387, 0.7470},
                                       {0.1091, 0.8732, 0.5547},
                                       {0.0381, 0.5743, 0.8828}};
    static const Eigen::Matrix<double, 4, 3, Eigen::RowMajor> P =
        Eigen::Map<const Eigen::Matrix<double, 4, 3, Eigen::RowMajor>>(&p[0][0]);

    VectorXd scores = VectorXd::Zero(x.rows());

    for (int i = 0; i < 4; ++i) {
        Eigen::ArrayXd exponent = A(i, 0) * (x.col(0).array() - P(i, 0)).square() +
                                  A(i, 1) * (x.col(1).array() - P(i, 1)).square() +
                                  A(i, 2) * (x.col(2).array() - P(i, 2)).square();

        scores.array() -= alpha(i) * (-exponent).exp();
    }
    cout << "scores: " << scores.transpose() << endl;
}

int main() {

#ifdef EIGEN_VECTORIZE
    std::cout << "SIMD enabled." << std::endl;
#else
    std::cout << "SIMD disabled." << std::endl;
#endif

    func();
}
