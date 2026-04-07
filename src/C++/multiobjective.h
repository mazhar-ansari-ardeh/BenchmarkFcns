#ifndef MULTIOBJECTIVE_H
#define MULTIOBJECTIVE_H

#include <Eigen/Dense>

namespace BenchmarkFcns::MultiObjective {
    using namespace Eigen;
    MatrixXd zdt1(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);
    MatrixXd zdt2(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);
    MatrixXd zdt3(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);
    MatrixXd zdt4(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);
    MatrixXd zdt6(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);
    MatrixXd dtlz1(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x, int num_objectives);
    MatrixXd dtlz2(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x, int num_objectives);
}

#endif // MULTIOBJECTIVE_H
