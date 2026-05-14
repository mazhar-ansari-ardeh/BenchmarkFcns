#ifndef MULTIFIDELITY_H
#define MULTIFIDELITY_H

#include <Eigen/Dense>

namespace BenchmarkFcns::MultiFidelity {
using namespace Eigen;

MatrixXd ackley(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

MatrixXd adjiman(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

MatrixXd alpinen1(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

MatrixXd bartelsconn(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

MatrixXd beale(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

MatrixXd bentcigar(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

MatrixXd bird(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

MatrixXd bohachevskyn1(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

MatrixXd booth(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

MatrixXd borehole(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

MatrixXd branin(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

MatrixXd brown(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

MatrixXd bukinn6(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

MatrixXd crossintray(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

MatrixXd currin(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

MatrixXd discus(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

MatrixXd dixonprice(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

MatrixXd easom(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

MatrixXd eggholder(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

MatrixXd elliptic(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

MatrixXd forrester(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

MatrixXd friedman(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

MatrixXd gano(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

MatrixXd goldsteinprice(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

MatrixXd griewank(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

MatrixXd happycat(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

MatrixXd heterogeneous(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

MatrixXd himmelblau(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

MatrixXd katsuura(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

MatrixXd levy(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

MatrixXd matyas(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

MatrixXd michalewicz(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

MatrixXd otlcircuit(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

MatrixXd park91a(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

MatrixXd park91b(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

MatrixXd piston(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

MatrixXd rastrigin(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

MatrixXd robotarm(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

MatrixXd rosenbrock(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

MatrixXd schwefel(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

MatrixXd shubert(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

MatrixXd sixhumpcamel(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

MatrixXd sphere(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

MatrixXd step(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

MatrixXd styblinskitank(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

MatrixXd trid(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

MatrixXd wingweight(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

MatrixXd xiong1d(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

MatrixXd zakharov(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);
} // namespace BenchmarkFcns::MultiFidelity

#endif // MULTIFIDELITY_H
