#include "composition.h"
#include "benchmarkfcns.h"
#include "utils.h"
#include <cmath>
#include <iostream>

namespace BenchmarkFcns {

Composition::Composition() {}

void Composition::add_component(BenchmarkFcn fcn, const VectorXd &shift, const MatrixXd &rotation,
                                double sigma, double lambda, double bias, double f_max,
                                bool apply_osz, bool apply_asy, const std::vector<int> &variables,
                                const VectorXd &input_offset) {
    components.push_back({fcn, shift, rotation, sigma, lambda, bias, f_max, apply_osz, apply_asy,
                          input_offset, variables});
}

VectorXd
Composition::evaluate(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) const {
    const int m_total = x.rows();
    if (m_total == 0)
        return VectorXd();

    return apply_parallel(x, [this](const ArrayXXd &a_x) -> VectorXd {
        const int m = a_x.rows();
        const int n = a_x.cols();
        const int num_components = components.size();

        if (num_components == 0)
            return VectorXd::Zero(m);

        MatrixXd weights(m, num_components);
        MatrixXd component_scores(m, num_components);

        for (int i = 0; i < num_components; ++i) {
            const auto &comp = components[i];

            // 1. Prepare input for this component
            MatrixXd sub_x;
            if (comp.variables.empty()) {
                sub_x = a_x.matrix();
            } else {
                sub_x.resize(m, comp.variables.size());
                for (size_t j = 0; j < comp.variables.size(); ++j) {
                    sub_x.col(j) = a_x.col(comp.variables[j]);
                }
            }

            // 2. Calculate Weights
            const VectorXd dists =
                (sub_x.rowwise() - comp.shift.transpose()).array().square().rowwise().sum();

            if (use_sqrt_weight) {
                weights.col(i) =
                    (dists.array() > 1e-15)
                        .select((1.0 / dists.array().sqrt()) *
                                    (-dists.array() / (2.0 * n * comp.sigma * comp.sigma)).exp(),
                                1e99);
            } else {
                weights.col(i) = (-dists.array() / (2.0 * n * comp.sigma * comp.sigma)).exp();
            }

            // 3. Prepare shifted coordinates
            MatrixXd z = (sub_x.rowwise() - comp.shift.transpose()).array() / comp.lambda;

            ArrayXXd trans_z = z.array();
            if (comp.apply_osz) {
                trans_z = t_osz(trans_z);
            }
            if (comp.apply_asy) {
                trans_z = t_asy(trans_z);
            }

            MatrixXd rotated_z = trans_z.matrix() * comp.rotation;

            if (comp.input_offset.size() > 0) {
                rotated_z.rowwise() += comp.input_offset.transpose();
            }

            VectorXd raw_score = comp.fcn(rotated_z);

            component_scores.col(i) = (constant_C * raw_score.array() / comp.f_max) + comp.bias;
        }

        if (sum_mode) {
            return component_scores.rowwise().sum();
        }

        VectorXd weight_sums = weights.rowwise().sum();
        VectorXd final_scores(m);
        for (int i = 0; i < m; ++i) {
            if (weight_sums(i) > 0) {
                final_scores(i) = (weights.row(i).array() * component_scores.row(i).array()).sum() /
                                  weight_sums(i);
            } else {
                final_scores(i) = component_scores(i, 0);
            }
        }
        return final_scores;
    });
}

BenchmarkFcn get_function_ptr(const std::string &name) {
    static const auto function_map = []() {
        std::map<std::string, BenchmarkFcn> m;
        m["ackley"] = &ackley;
        m["ackleyn2"] = &ackleyn2;
        m["ackleyn3"] = &ackleyn3;
        m["ackleyn4"] = &ackleyn4;
        m["ackley5"] = &ackley5;
        m["ackley6"] = &ackley6;
        m["adjiman"] = &adjiman;
        m["alpinen1"] = &alpinen1;
        m["alpinen2"] = &alpinen2;
        m["alpine3"] = &alpine3;
        m["alpine4"] = &alpine4;
        m["alpine5"] = &alpine5;
        m["amgm"] = &amgm;
        m["attractivesector"] = &attractivesector;
        m["baluja"] = &baluja;
        m["bartelsconn"] = &bartelsconn;
        m["beale"] = &beale;
        m["bentcigar"] = &bentcigar;
        m["bird"] = &bird;
        m["bohachevskyn1"] = &bohachevskyn1;
        m["bohachevskyn2"] = &bohachevskyn2;
        m["bohachevskyn3"] = &bohachevskyn3;
        m["bohachevskyn4"] = &bohachevskyn4;
        m["bohachevskyn5"] = &bohachevskyn5;
        m["booth"] = &booth;
        m["boxbetts"] = &boxbetts;
        m["braninn1"] = &braninn1;
        m["braninn2"] = &braninn2;
        m["brent"] = &brent;
        m["brentn1"] = &brentn1;
        m["brown"] = &brown;
        m["bukinn1"] = &bukinn1;
        m["bukinn2"] = &bukinn2;
        m["bukinn3"] = &bukinn3;
        m["bukinn4"] = &bukinn4;
        m["bukinn5"] = &bukinn5;
        m["bukinn6"] = &bukinn6;
        m["carromtable"] = &carromtable;
        m["chenbird"] = &chenbird;
        m["chichinadze"] = &chichinadze;
        m["chichinadzen2"] = &chichinadzen2;
        m["cigar"] = &cigar;
        m["colville"] = &colville;
        m["corana"] = &corana;
        m["cosinemixture"] = &cosinemixture;
        m["crossintray"] = &crossintray;
        m["crosslegintray"] = &crosslegintray;
        m["crownedcross"] = &crownedcross;
        m["csendes"] = &csendes;
        m["cubefcn"] = &cubefcn;
        m["damavandi"] = &damavandi;
        m["debn1"] = &debn1;
        m["deckkersaarts"] = &deckkersaarts;
        m["dejongn5"] = &dejongn5;
        m["dejongn6"] = &dejongn6;
        m["discus"] = &discus;
        m["dixonprice"] = &dixonprice;
        m["dixonpricen2"] = &dixonpricen2;
        m["dixonpricen3"] = &dixonpricen3;
        m["dolan"] = &dolan;
        m["dropwave"] = &dropwave;
        m["easom"] = &easom;
        m["eggcrate"] = &eggcrate;
        m["eggholder"] = &eggholder;
        m["eggholdern2"] = &eggholdern2;
        m["elattar"] = &elattar;
        m["elliptic"] = &elliptic;
        m["engvall"] = &engvall;
        m["exponential"] = &exponential;
        m["f8f2"] = &f8f2;
        m["fletcherpowell"] = &fletcherpowell;
        m["forrester"] = &forrester;
        m["foxholes"] = &foxholes;
        m["freudensteinroth"] = &freudensteinroth;
        m["friedman1"] = [](const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
            return friedman1(x, false);
        };

        m["friedman2"] = [](const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
            return friedman2(x, 0.0);
        };
        m["friedman3"] = [](const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
            return friedman3(x, 0.0);
        };
        m["gallagher101"] = &gallagher101;
        m["gear"] = &gear;
        m["giunta"] = &giunta;
        m["giuntan2"] = &giuntan2;
        m["goldsteinprice"] = &goldsteinprice;
        m["gramacylee"] = &gramacylee;
        m["griewank"] = &griewank;
        m["griewankn2"] = &griewankn2;
        m["griewankn3"] = &griewankn3;
        m["hansen"] = &hansen;
        m["happycat"] = [](const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
            return happycat(x, 0.5);
        };
        m["hgbat"] = &hgbat;
        m["hartmann3"] = &hartmann3;
        m["hartmann4"] = &hartmann4;
        m["hartmann6"] = &hartmann6;
        m["helicalvalley"] = &helicalvalley;
        m["himmelblau"] = &himmelblau;
        m["himmelblaun2"] = &himmelblaun2;
        m["holdertable"] = &holdertable;
        m["hosaki"] = &hosaki;
        m["hosakin2"] = &hosakin2;
        m["ishigami"] = [](const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
            return ishigami(x, 7.0, 0.1);
        };
        m["jennrichsampson"] = &jennrichsampson;
        m["judge"] = &judge;
        m["katsuura"] = &katsuura;
        m["keane"] = &keane;
        m["keanen2"] = &keanen2;
        m["kowalik"] = &kowalik;
        m["kulnevich"] = &kulnevich;
        m["langermann"] = &langermann;
        m["langermannn2"] = &langermannn2;
        m["leon"] = &leon;
        m["leonn2"] = &leonn2;
        m["levin13"] = &levin13;
        m["levy"] = &levy;
        m["levyn1"] = &levyn1;
        m["levyn2"] = &levyn2;
        m["levyn3"] = &levyn3;
        m["lunacekbirastrigin"] = &lunacekbirastrigin;
        m["matyas"] = &matyas;
        m["matyasn2"] = &matyasn2;
        m["mccormick"] = &mccormick;
        m["mccormickn2"] = &mccormickn2;
        m["meyer"] = &meyer;
        m["michalewicz"] = [](const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
            return michalewicz(x, 10);
        };
        m["michalewiczn2"] = &michalewiczn2;
        m["michalewiczn5"] = &michalewiczn5;
        m["michalewiczn10"] = &michalewiczn10;
        m["mielecantrell"] = &mielecantrell;
        m["mishrabird"] = &mishrabird;
        m["mishran1"] = &mishran1;
        m["mishran2"] = &mishran2;
        m["mishran3"] = &mishran3;
        m["mishran4"] = &mishran4;
        m["mishran5"] = &mishran5;
        m["mishran6"] = &mishran6;
        m["mishran7"] = &mishran7;
        m["mishran8"] = &mishran8;
        m["mishran9"] = &mishran9;
        m["mishran10"] = &mishran10;
        m["mishran11"] = &mishran11;
        m["mishran12"] = &mishran12;
        m["needleeye"] = &needleeye;
        m["parsopoulos"] = &parsopoulos;
        m["pathological"] = &pathological;
        m["paviani"] = &paviani;
        m["penholder"] = &penholder;
        m["periodic"] = &periodic;
        m["periodicn2"] = &periodicn2;
        m["perm"] = [](const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
            return perm(x, 0.5);
        };
        m["picheny"] = &picheny;
        m["pinter"] = &pinter;
        m["powellsingular"] = &powellsingular;
        m["powellsingularn2"] = &powellsingularn2;
        m["powellsum"] = &powellsum;
        m["powellsumn2"] = &powellsumn2;
        m["pricen1"] = &pricen1;
        m["pricen2"] = &pricen2;
        m["pricen3"] = &pricen3;
        m["pricen4"] = &pricen4;
        m["pricen5"] = &pricen5;
        m["qing"] = &qing;
        m["qingn2"] = &qingn2;
        m["quartic"] = &quartic;
        m["quintic"] = &quintic;
        m["rana"] = &rana;
        m["rastrigin"] = &rastrigin;
        m["rastrigin_noncont"] = &rastrigin_noncont;
        m["rastrigin_parallel"] = &rastrigin_parallel;
        m["ridge"] = [](const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
            return ridge(x, 1.0, 0.5);
        };
        m["rosenbrock"] = &rosenbrock;
        m["rotatedhyperellipsoid"] = &rotatedhyperellipsoid;
        m["salomon"] = &salomon;
        m["sargan"] = &sargan;
        m["schafferf6"] = &schafferf6;
        m["schafferf7"] = &schafferf7;
        m["schaffern1"] = &schaffern1;
        m["schaffern2"] = &schaffern2;
        m["schaffern3"] = &schaffern3;
        m["schaffern4"] = &schaffern4;
        m["schwefel"] = &schwefel;
        m["schwefel_cec"] = &schwefel_cec;
        m["schwefel12"] = &schwefel12;
        m["schwefel220"] = &schwefel220;
        m["schwefel221"] = &schwefel221;
        m["schwefel222"] = &schwefel222;
        m["schwefel223"] = &schwefel223;
        m["schwefel225"] = &schwefel225;
        m["schwefel226"] = &schwefel;
        m["shekel10"] = &shekel10;
        m["shekel5"] = &shekel5;
        m["shekel7"] = &shekel7;
        m["shubert"] = &shubert;
        m["shubertn3"] = &shubertn3;
        m["shubertn4"] = &shubertn4;
        m["sixhumpcamel"] = &sixhumpcamel;
        m["sphere"] = &sphere;
        m["sineenvelopesinewave"] = &sineenvelopesinewave;
        m["step"] = &step;
        m["stepn1"] = &stepn1;
        m["stepn2"] = &step;
        m["stepn3"] = &stepn3;
        m["stretchedvsine"] = &stretchedvsine;
        m["styblinskitank"] = &styblinskitank;
        m["sumsquares"] = &sumsquares;
        m["tablefcn"] = &tablefcn;
        m["testtubeholder"] = &testtubeholder;
        m["threehumpcamel"] = &threehumpcamel;
        m["trefethen"] = &trefethen;
        m["treccani"] = &treccani;
        m["trid"] = &trid;
        m["trigonometricn1"] = &trigonometricn1;
        m["trigonometricn2"] = &trigonometricn2;
        m["ursemn1"] = &ursemn1;
        m["ursemn3"] = &ursemn3;
        m["ursemn4"] = &ursemn4;
        m["ursemwaves"] = &ursemwaves;
        m["ventersobiezcczanski"] = &ventersobiezcczanski;
        m["vincent"] = &vincent;
        m["watson"] = &watson;
        m["wavy"] = [](const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
            return wavy(x, 10.0);
        };
        m["wayburnseadern1"] = &wayburnseadern1;
        m["wayburnseadern2"] = &wayburnseadern2;
        m["wayburnseadern3"] = &wayburnseadern3;
        m["weierstrass"] = [](const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
            return weierstrass(x, 0.5, 3.0, 20);
        };
        m["whitley"] = &whitley;
        m["wolfe"] = &wolfe;
        m["xinsheyangn1"] = &xinsheyangn1;
        m["xinsheyangn2"] = &xinsheyangn2;
        m["xinsheyangn3"] = [](const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
            return xinsheyangn3(x, 15.0, 5.0);
        };
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
} // namespace BenchmarkFcns
