#ifndef BENCHMARKFCNS_H
#define BENCHMARKFCNS_H

#define _USE_MATH_DEFINES
#include <cmath>

#include <Eigen/Dense>

namespace BenchmarkFcns {

    using namespace Eigen;

    VectorXd sphere(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd ackley(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd ackley2(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd ackley3(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd ackley4(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd adjiman(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd alpine1(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd alpine2(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd amgm(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd bartelsconn(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd beale(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd bird(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd bohachevsky1(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd bohachevsky2(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd booth(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd braninn01(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd braninn02(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd brent(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd brown(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd bukinn2(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd bukinn4(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd bukinn6(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd carromtable(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd chichinadze(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd cigar(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd cosinemixture(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd crossintray(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd crownedcross(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd csendes(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd cubefcn(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd debn1(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd deckkersaarts(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd dropwave(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd easom(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd eggholder(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd eggcrate(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd elattar(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd exponential(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd forrester(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd forrester_mf2(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd forrester_mf3(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd forrester_mf4(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd giunta(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd goldsteinprice(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd gramacylee(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd griewank(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd happycat(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x, double alpha = 0.5);

    VectorXd holdertable(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd himmelblau(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd keane(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd leon(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd levin13(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd matyas(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd mccormick(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd periodic(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd picheny(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd powellsum(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd qing(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd quartic(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd rastrigin(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd ridge(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x, double d = 1, double alpha = 0.5);

    VectorXd rosenbrock(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd rosenbrock_mf2(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd salomon(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd schaffer1(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd schaffer2(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd schaffer3(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd schaffer4(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd schwefel(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd schwefel220(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd schwefel221(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd schwefel222(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd schwefel223(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd shubert(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd shubert3(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd shubert4(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd styblinskitank(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd sumsquares(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd threehumpcamel(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd treccani(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd trid(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd wolfe(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd xinsheyang1(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd xinsheyang2(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd xinsheyang3(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x, double beta = 15, double m = 5);

    VectorXd xinsheyang4(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

    VectorXd zakharov(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x);

} // namespace BenchmarkFunctions

#endif // BENCHMARKFCNS_H
