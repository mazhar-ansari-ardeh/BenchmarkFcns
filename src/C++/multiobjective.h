#ifndef MULTIOBJECTIVE_H
#define MULTIOBJECTIVE_H

#include <Eigen/Dense>

namespace BenchmarkFcns::MultiObjective {
using namespace Eigen;
MatrixXd bnh(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x,
             bool return_constraints = false);
MatrixXd cf1(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x,
             bool return_constraints = false);
MatrixXd cf2(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x,
             bool return_constraints = false);
MatrixXd cf3(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x,
             bool return_constraints = false);
MatrixXd cf4(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x,
             bool return_constraints = false);
MatrixXd cf5(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x,
             bool return_constraints = false);
MatrixXd cf6(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x,
             bool return_constraints = false);
MatrixXd cf7(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x,
             bool return_constraints = false);
MatrixXd cf8(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x,
             bool return_constraints = false);
MatrixXd cf9(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x,
             bool return_constraints = false);
MatrixXd cf10(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x,
              bool return_constraints = false);
MatrixXd deb(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);
MatrixXd dtlz1(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, int num_objectives);
MatrixXd dtlz2(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, int num_objectives);
MatrixXd dtlz3(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, int num_objectives);
MatrixXd dtlz4(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, int num_objectives,
               double alpha = 100.0);
MatrixXd dtlz5(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, int num_objectives);
MatrixXd dtlz6(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, int num_objectives);
MatrixXd dtlz7(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, int num_objectives);
MatrixXd fonsecafleming(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);
MatrixXd kita(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x,
              bool return_constraints = false);
MatrixXd kursawe(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);
MatrixXd maf1(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, int num_objectives);
MatrixXd maf2(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, int num_objectives);
MatrixXd maf3(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, int num_objectives);
MatrixXd maf4(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, int num_objectives);
MatrixXd maf5(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, int num_objectives);
MatrixXd maf6(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, int num_objectives);
MatrixXd maf7(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, int num_objectives);
MatrixXd maf8(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, int num_objectives);
MatrixXd maf9(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, int num_objectives);
MatrixXd maf10(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, int num_objectives,
               int k = -1);
MatrixXd mop1(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);
MatrixXd mop2(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);
MatrixXd mop3(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);
MatrixXd mop4(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);
MatrixXd mop5(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);
MatrixXd mop6(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);
MatrixXd mop7(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);
MatrixXd oka1(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);
MatrixXd oka2(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);
MatrixXd osyczkakundu(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x,
                      bool return_constraints = false);
MatrixXd poloni(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);
MatrixXd tanaka(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x,
                bool return_constraints = false);
MatrixXd uf1(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);
MatrixXd uf2(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);
MatrixXd uf3(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);
MatrixXd uf4(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);
MatrixXd uf5(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);
MatrixXd uf6(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);
MatrixXd uf7(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);
MatrixXd uf8(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);
MatrixXd uf9(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);
MatrixXd uf10(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);
MatrixXd viennet1(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);
MatrixXd viennet2(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);
MatrixXd viennet3(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);
MatrixXd wfg1(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, int num_objectives,
              int k);
MatrixXd wfg2(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, int num_objectives,
              int k);
MatrixXd wfg3(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, int num_objectives,
              int k);
MatrixXd wfg4(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, int num_objectives,
              int k);
MatrixXd wfg5(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, int num_objectives,
              int k);
MatrixXd wfg6(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, int num_objectives,
              int k);
MatrixXd wfg7(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, int num_objectives,
              int k);
MatrixXd wfg8(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, int num_objectives,
              int k);
MatrixXd wfg9(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, int num_objectives,
              int k);
MatrixXd zdt1(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);
MatrixXd zdt2(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);
MatrixXd zdt3(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);
MatrixXd zdt4(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);
MatrixXd zdt6(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);
} // namespace BenchmarkFcns::MultiObjective

#endif // MULTIOBJECTIVE_H
