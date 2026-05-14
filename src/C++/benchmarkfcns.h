#ifndef BENCHMARKFCNS_H
#define BENCHMARKFCNS_H

#define _USE_MATH_DEFINES
#include <cmath>

#include <Eigen/Dense>

namespace BenchmarkFcns {

using namespace Eigen;

VectorXd ackley(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd ackleyn2(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd ackleyn3(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd ackleyn4(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd ackley5(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd ackley6(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd adjiman(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd alpinen1(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd alpinen2(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd alpine3(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd alpine4(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd alpine5(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd amgm(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd attractivesector(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd baluja(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd bartelsconn(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd beale(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd bentcigar(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd biggsexp02(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd biggsexp03(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd biggsexp04(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd biggsexp05(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd biggsexp06(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd bird(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd bohachevskyn1(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd bohachevskyn2(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd bohachevskyn3(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd bohachevskyn4(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd bohachevskyn5(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd booth(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd boxbetts(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd braninn1(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd braninn2(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd brent(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd brentn1(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd brown(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd bukinn1(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd bukinn2(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd bukinn3(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd bukinn4(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd bukinn5(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd bukinn6(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd carromtable(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd chenbird(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd chichinadze(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd chichinadzen2(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd cigar(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd colville(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd corana(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd cosinemixture(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd crossintray(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd crosslegintray(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd crownedcross(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd csendes(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd cubefcn(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd damavandi(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd debn1(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd deckkersaarts(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd dejongn5(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd dejongn6(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd discus(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd dixonprice(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd dixonpricen2(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd dixonpricen3(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd dolan(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd dropwave(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd easom(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd eggcrate(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd eggholder(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd eggholdern2(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd elattar(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd elliptic(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd engvall(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd exponential(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd f8f2(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd fletcherpowell(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd forrester(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd foxholes(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd freudensteinroth(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd friedman1(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x,
                   bool rnd = false);

VectorXd friedman2(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x,
                   double sigma = 0);

VectorXd friedman3(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x,
                   double sigma = 0);

VectorXd gallagher101(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd gear(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd giunta(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd giuntan2(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd goldsteinprice(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd gramacylee(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd griewank(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd griewankn2(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd griewankn3(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd hansen(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd happycat(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x,
                  double alpha = 0.5);

VectorXd hgbat(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd hartmann3(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);
VectorXd hartmann4(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd hartmann6(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd helicalvalley(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd himmelblau(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd himmelblaun2(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd holdertable(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd hosaki(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd hosakin2(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd ishigami(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, double a = 7.0,
                  double b = 0.1);

VectorXd jennrichsampson(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd judge(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd katsuura(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd keane(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd keanen2(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd kowalik(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd kulnevich(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd langermann(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd langermannn2(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd leon(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd leonn2(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd levin13(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd levy(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd levyn1(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd levyn2(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd levyn3(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd lunacekbirastrigin(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd matyas(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd matyasn2(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd mccormick(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd mccormickn2(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd meyer(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd michalewicz(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, double m = 10);

VectorXd michalewiczn2(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd michalewiczn5(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd michalewiczn10(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd mielecantrell(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd mishrabird(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd mishran1(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd mishran2(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd mishran3(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd mishran4(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd mishran5(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd mishran6(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd mishran7(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd mishran8(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd mishran9(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd mishran10(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd mishran11(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd mishran12(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd needleeye(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd parsopoulos(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd pathological(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd paviani(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd penholder(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd periodic(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd periodicn2(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd perm(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, double beta = 0.5);

VectorXd picheny(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd pinter(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd powellsingular(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd powellsingularn2(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd powellsum(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd powellsumn2(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd pricen1(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd pricen2(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd pricen3(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd pricen4(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd pricen5(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd qing(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd qingn2(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd quartic(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd quintic(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd rana(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd rastrigin(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd rastrigin_noncont(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd rastrigin_parallel(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd ridge(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, double d,
               double alpha);

VectorXd rosenbrock(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd rotatedhyperellipsoid(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd salomon(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd sargan(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd schafferf6(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd schafferf7(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd schaffern1(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd schaffern2(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd schaffern3(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd schaffern4(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd schwefel(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd schwefel_cec(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd schwefel12(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd schwefel220(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd schwefel221(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd schwefel222(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd schwefel223(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd schwefel225(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd shekel10(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd shekel5(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd shekel7(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd shubert(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd shubertn3(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd shubertn4(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd sixhumpcamel(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd sphere(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd sineenvelopesinewave(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd step(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd stepn1(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd stepn2(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd stepn3(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd stretchedvsine(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd styblinskitank(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd sumsquares(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd tablefcn(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd testtubeholder(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd threehumpcamel(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd trefethen(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd treccani(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd trid(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd trigonometricn1(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd trigonometricn2(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd ursemn1(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd ursemn3(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd ursemn4(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd ursemwaves(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd ventersobiezcczanski(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd vincent(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd watson(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd wavy(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, double k);

VectorXd wayburnseadern1(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd wayburnseadern2(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd wayburnseadern3(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd weierstrass(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, double a = 0.5,
                     double b = 3, int kmax = 20);

VectorXd whitley(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd wolfe(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd xinsheyangn1(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd xinsheyangn2(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd xinsheyangn3(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x,
                      double beta = 15, double m = 5);

VectorXd xinsheyangn4(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd zakharov(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd zerosum(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd zettel(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd zimmerman(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

VectorXd zirilli(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x);

} // namespace BenchmarkFcns

#endif // BENCHMARKFCNS_H
