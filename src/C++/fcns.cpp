#include <iostream>
#include <Eigen/Dense>

using Eigen::MatrixXd;
// using Eigen::MatrixXdMap;
using namespace Eigen;

VectorXd sphereBenchmark(const MatrixXd& inputMatrix) {
    // Calculate the squared values element-wise
    MatrixXd squaredValues = inputMatrix.array().square();

    // Sum along the rows (axis 0)
    VectorXd result = squaredValues.rowwise().sum();

    return result;
}

VectorXd sphereBenchmark(double** inputMatrix, int rows, int cols)
{
   Eigen::Map<Eigen::MatrixXd> matrixXdMap(inputMatrix[0], rows, cols);
   MatrixXd squaredValues = matrixXdMap.array().square();

    // Sum along the rows (axis 0)
    VectorXd result = squaredValues.rowwise().sum();

    return result;
}

using Eigen::MatrixXd;
using Eigen::Ref;
using Eigen::Dynamic;
using Eigen::RowMajor;
using Eigen::Matrix;
// using Eigen::MatrixXdMap;
using namespace Eigen;
using namespace std;

// VectorXd qing(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) {
//     int n = x.cols();
//     MatrixXd x2 = x.array().square();
//     VectorXd i_values = RowVectorXd::LinSpaced(n, 1, n).transpose().replicate(x.rows(), 1);
//     // VectorXd scores = (x2 - i_values).array().square().rowwise().sum();
//     VectorXd scores = (x2 - i_values).array().rowwise().sum();

//     return scores;
// }

VectorXd func() {
    // [[10, 20],
    //  [20, 30],
    //  [30, 40],
    //  [40, 50]]
    MatrixXd x(4, 3);
    x(0, 0) = 100.881815; x(0, 1) = 0.132688; x(0, 2) = 0.181562;
    x(1, 0) = 0.595656; x(1, 1) = 0.282805; x(1, 2) = 0.196698;
    x(2, 0) = 1; x(2, 1) = 1; x(2, 2) = 1;
    x(3, 0) = 0; x(3, 1) = 0; x(3, 2) = 0;
    // In [36]: ar = np.array(a) ar = [100.881815 0.132688 0.181562; 0.595656 0.282805 0.196698; 1 1 1; 0 0 0;]

    int n = x.cols();

    Eigen::MatrixXd x_squared = x.array().square();
    Eigen::VectorXd scores = ((x_squared.leftCols(n - 1).array().pow(x_squared.rightCols(n - 1).array() + 1)) +
                              (x_squared.rightCols(n - 1).array().pow(x_squared.leftCols(n - 1).array() + 1))).rowwise().sum();

    cout << scores << endl << endl;
}

int main()
{



#ifdef EIGEN_VECTORIZE
    std::cout << "SIMD enabled." << std::endl;
#else
    std::cout << "SIMD disabled." << std::endl;
#endif

    // double array2D[3][3] = {{1.0, 2.0, 3.0},
    //                        {4.0, 5.0, 6.0},
    //                        {7.0, 8.0, 9.0}};

    // int rows = 3;
    // int cols = 3;
    // double** array2D = new double*[rows];
    // for (int i = 0; i < rows; ++i) {
    //     array2D[i] = new double[cols];
    // }

    // // Initialize the array with some values
    // int count = 1;
    // for (int i = 0; i < rows; ++i) {
    //     for (int j = 0; j < cols; ++j) {
    //         array2D[i][j] = count++;
    //     }
    // }

    // Access and print the values
    // #include <Eigen/Core> // Include the necessary header file

    // for (int i = 0; i < rows; ++i) {
    //     for (int j = 0; j < cols; ++j) {
    //         std::cout << array2D[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }

    // Create a Map object to map the array to a MatrixXd
    // Eigen::Map<Eigen::MatrixXd> matrixXdMap = Eigen::Map<Eigen::MatrixXd>(array2D[0], rows, cols);

    func();

    // std::cout << "MatrixXd created from array:\n" << matrixXdMap << std::endl;

        // Eigen::VectorXd retval = sphereBenchmark(matrixXdMap);
        // std::cout << retval << std::endl;

        // std::cout << sphereBenchmark(array2D, 3, 3) << std::endl;

}
