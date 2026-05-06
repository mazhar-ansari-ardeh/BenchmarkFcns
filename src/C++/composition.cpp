#include "composition.h"
#include "benchmarkfcns.h"
#include <cmath>
#include <iostream>

namespace BenchmarkFcns {

    Composition::Composition() {}

    void Composition::add_component(BenchmarkFcn fcn,
                                    const VectorXd& shift,
                                    const MatrixXd& rotation,
                                    double sigma,
                                    double lambda,
                                    double bias,
                                    double f_max) {
        components.push_back({fcn, shift, rotation, sigma, lambda, bias, f_max});
    }

    VectorXd Composition::evaluate(const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) const {
        const int m = x.rows();
        const int n = x.cols();
        const int num_components = components.size();

        if (num_components == 0) return VectorXd::Zero(m);

        MatrixXd weights(m, num_components);
        MatrixXd component_scores(m, num_components);

        for (int i = 0; i < num_components; ++i) {
            const auto& comp = components[i];

            // 1. Calculate Weights
            // w_i = exp(-dist / (2 * n * sigma^2))
            const VectorXd dists = (x.rowwise() - comp.shift.transpose()).array().square().rowwise().sum();
            weights.col(i) = (-dists.array() / (2.0 * n * comp.sigma * comp.sigma)).exp();

            // 2. Prepare shifted and rotated coordinates
            // z = (x - o) / lambda * M
            MatrixXd z = (x.rowwise() - comp.shift.transpose()).array() / comp.lambda;
            MatrixXd rotated_z = z * comp.rotation;

            // 3. Evaluate base function
            VectorXd raw_score = comp.fcn(rotated_z);

            // 4. Scale and normalize height: f' = C * f / f_max
            component_scores.col(i) = (constant_C * raw_score.array() / comp.f_max) + comp.bias;
        }

        // Normalize weights
        VectorXd weight_sums = weights.rowwise().sum();

        VectorXd final_scores = VectorXd::Zero(m);
        for (int i = 0; i < m; ++i) {
            if (weight_sums(i) > 0) {
                final_scores(i) = (weights.row(i).array() * component_scores.row(i).array()).sum() / weight_sums(i);
            } else {
                final_scores(i) = component_scores(i, 0);
            }
        }

        return final_scores;
    }

    BenchmarkFcn get_function_ptr(const std::string& name) {
        static const auto function_map = []() {
            std::map<std::string, BenchmarkFcn> m;
            m["ackley"] = &ackley;
            m["ackleyn2"] = &ackleyn2;
            m["ackleyn3"] = &ackleyn3;
            m["ackleyn4"] = &ackleyn4;
            m["adjiman"] = &adjiman;
            m["alpinen1"] = &alpinen1;
            m["alpinen2"] = &alpinen2;
            m["amgm"] = &amgm;
            m["attractivesector"] = &attractivesector;
            m["bartelsconn"] = &bartelsconn;
            m["beale"] = &beale;
            m["bentcigar"] = &bentcigar;
            m["bird"] = &bird;
            m["bohachevskyn1"] = &bohachevskyn1;
            m["bohachevskyn2"] = &bohachevskyn2;
            m["bohachevskyn3"] = &bohachevskyn3;
            m["booth"] = &booth;
            m["braninn1"] = &braninn1;
            m["braninn2"] = &braninn2;
            m["brent"] = &brent;
            m["brown"] = &brown;
            m["bukinn2"] = &bukinn2;
            m["bukinn4"] = &bukinn4;
            m["bukinn6"] = &bukinn6;
            m["carromtable"] = &carromtable;
            m["chichinadze"] = &chichinadze;
            m["cigar"] = &cigar;
            m["corana"] = &corana;
            m["cosinemixture"] = &cosinemixture;
            m["crossintray"] = &crossintray;
            m["crownedcross"] = &crownedcross;
            m["csendes"] = &csendes;
            m["cubefcn"] = &cubefcn;
            m["debn1"] = &debn1;
            m["deckkersaarts"] = &deckkersaarts;
            m["dejongn5"] = &dejongn5;
            m["discus"] = &discus;
            m["dixonprice"] = &dixonprice;
            m["dropwave"] = &dropwave;
            m["easom"] = &easom;
            m["eggcrate"] = &eggcrate;
            m["eggholder"] = &eggholder;
            m["elattar"] = &elattar;
            m["elliptic"] = &elliptic;
            m["exponential"] = &exponential;
            m["f8f2"] = &f8f2;
            m["forrester"] = &forrester;
            m["foxholes"] = &foxholes;
            m["friedman1"] = [](const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) { return friedman1(x, false); };
            m["friedman2"] = [](const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) { return friedman2(x, 0.0); };
            m["friedman3"] = [](const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) { return friedman3(x, 0.0); };
            m["gallagher101"] = &gallagher101;
            m["gear"] = &gear;
            m["giunta"] = &giunta;
            m["goldsteinprice"] = &goldsteinprice;
            m["gramacylee"] = &gramacylee;
            m["griewank"] = &griewank;
            m["happycat"] = [](const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) { return happycat(x, 0.5); };
            m["hartmann3"] = &hartmann3;
            m["hartmann6"] = &hartmann6;
            m["himmelblau"] = &himmelblau;
            m["holdertable"] = &holdertable;
            m["hosaki"] = &hosaki;
            m["ishigami"] = [](const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) { return ishigami(x, 7.0, 0.1); };
            m["katsuura"] = &katsuura;
            m["keane"] = &keane;
            m["langermann"] = &langermann;
            m["leon"] = &leon;
            m["levin13"] = &levin13;
            m["levy"] = &levy;
            m["lunacekbirastrigin"] = &lunacekbirastrigin;
            m["matyas"] = &matyas;
            m["mccormick"] = &mccormick;
            m["michalewicz"] = [](const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) { return michalewicz(x, 10.0); };
            m["mishrabird"] = &mishrabird;
            m["periodic"] = &periodic;
            m["perm"] = [](const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) { return perm(x, 0.5); };
            m["picheny"] = &picheny;
            m["powellsingular"] = &powellsingular;
            m["powellsum"] = &powellsum;
            m["qing"] = &qing;
            m["quartic"] = &quartic;
            m["rana"] = &rana;
            m["rastrigin"] = &rastrigin;
            m["rastrigin_parallel"] = &rastrigin_parallel;
            m["ridge"] = [](const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) { return ridge(x, 1.0, 0.5); };
            m["rosenbrock"] = &rosenbrock;
            m["salomon"] = &salomon;
            m["schafferf6"] = &schafferf6;
            m["schafferf7"] = &schafferf7;
            m["schaffern1"] = &schaffern1;
            m["schaffern2"] = &schaffern2;
            m["schaffern3"] = &schaffern3;
            m["schaffern4"] = &schaffern4;
            m["schwefel"] = &schwefel;
            m["schwefel12"] = &schwefel12;
            m["schwefel220"] = &schwefel220;
            m["schwefel221"] = &schwefel221;
            m["schwefel222"] = &schwefel222;
            m["schwefel223"] = &schwefel223;
            m["shekel10"] = &shekel10;
            m["shekel5"] = &shekel5;
            m["shekel7"] = &shekel7;
            m["shubert"] = &shubert;
            m["shubertn3"] = &shubertn3;
            m["shubertn4"] = &shubertn4;
            m["sixhumpcamel"] = &sixhumpcamel;
            m["sphere"] = &sphere;
            m["step"] = &step;
            m["stretchedvsine"] = &stretchedvsine;
            m["styblinskitank"] = &styblinskitank;
            m["sumsquares"] = &sumsquares;
            m["threehumpcamel"] = &threehumpcamel;
            m["treccani"] = &treccani;
            m["trid"] = &trid;
            m["vincent"] = &vincent;
            m["watson"] = &watson;
            m["wavy"] = [](const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) { return wavy(x, 10.0); };
            m["wayburnseadern2"] = &wayburnseadern2;
            m["weierstrass"] = [](const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) { return weierstrass(x, 0.5, 3.0, 20); };
            m["whitley"] = &whitley;
            m["wolfe"] = &wolfe;
            m["xinsheyangn1"] = &xinsheyangn1;
            m["xinsheyangn2"] = &xinsheyangn2;
            m["xinsheyangn3"] = [](const Ref<const Matrix<double,Dynamic,Dynamic,RowMajor>>& x) { return xinsheyangn3(x, 15.0, 5.0); };
            m["xinsheyangn4"] = &xinsheyangn4;
            m["zakharov"] = &zakharov;
            m["zerosum"] = &zerosum;
            m["zettel"] = &zettel;
            m["zimmerman"] = &zimmerman;
            m["zirilli"] = &zirilli;
            return m;
        }();

        auto it = function_map.find(name);
        if (it != function_map.end()) {
            return it->second;
        }
        throw std::invalid_argument("Function name '" + name + "' not found in registry.");
    }
}
