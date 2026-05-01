#ifndef MULTIOBJECTIVE_H
#define MULTIOBJECTIVE_H

#include <Eigen/Dense>

namespace BenchmarkFcns::MultiObjective {
    using namespace Eigen;
    MatrixXd bnh(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x, bool return_constraints = false);
    MatrixXd dtlz1(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x, int num_objectives);
    MatrixXd dtlz2(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x, int num_objectives);
    MatrixXd dtlz3(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x, int num_objectives);
    MatrixXd dtlz4(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x, int num_objectives, double alpha = 100.0);
    MatrixXd dtlz5(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x, int num_objectives);
    MatrixXd dtlz6(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x, int num_objectives);
    MatrixXd dtlz7(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x, int num_objectives);
    MatrixXd fonsecafleming(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);
    MatrixXd kursawe(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);
    MatrixXd osyczkakundu(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x, bool return_constraints = false);
    MatrixXd poloni(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);
    MatrixXd tanaka(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x, bool return_constraints = false);
    MatrixXd viennet1(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);
    MatrixXd viennet2(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);
    MatrixXd viennet3(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);
    MatrixXd zdt1(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);
    MatrixXd zdt2(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);
    MatrixXd zdt3(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);
    MatrixXd zdt4(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);
    MatrixXd zdt6(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);
}

#endif // MULTIOBJECTIVE_H
