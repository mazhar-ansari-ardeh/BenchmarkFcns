#include <iostream>
#include <Eigen/Dense>
 
using Eigen::MatrixXd;
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

int main()
{
#ifdef EIGEN_VECTORIZE
	std::cout << "SIMD enabled." << std::endl;
#else
	std::cout << "SIMD disabled." << std::endl;
#endif 

	//double array2D[3][3] = {{1.0, 2.0, 3.0},
    //                        {4.0, 5.0, 6.0},
    //                        {7.0, 8.0, 9.0}};

	int rows = 3;
	int cols = 3;
	double** array2D = new double*[rows];
    for (int i = 0; i < rows; ++i) {
        array2D[i] = new double[cols];
    }

    // Initialize the array with some values
    int count = 1;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            array2D[i][j] = count++;
        }
    }

    // Access and print the values
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << array2D[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Create a Map object to map the array to a MatrixXd
    Eigen::Map<Eigen::MatrixXd> matrixXdMap(array2D[0], rows, cols);

    std::cout << "MatrixXd created from array:\n" << matrixXdMap << std::endl;
	
	auto retval = sphereBenchmark(matrixXdMap);
	std::cout << retval << std::endl;

	std::cout << sphereBenchmark(reinterpret_cast<double**>(array2D), 3, 3) << std::endl;
	
}


