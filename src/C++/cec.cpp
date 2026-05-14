#include "cec.h"
#include "benchmarkfcns.h"
#include "cec_data.h"
#include "composition.h"
#include "utils.h"
#include <cmath>
#include <map>
#include <vector>

namespace BenchmarkFcns::CEC {

// Helper for Hybrid function partitions
std::vector<int> get_partition_sizes(int fid, int n) {
    std::vector<double> p;
    switch (fid) {
    case 11:
    case 12:
    case 13:
        p = {0.2, 0.4, 0.4};
        break;
    case 14:
    case 15:
    case 16:
        p = {0.2, 0.2, 0.3, 0.3};
        break;
    case 17:
        p = {0.1, 0.2, 0.2, 0.2, 0.3};
        break;
    case 18:
    case 19:
        p = {0.2, 0.2, 0.2, 0.2, 0.2};
        break;
    case 20:
        p = {0.1, 0.1, 0.2, 0.2, 0.2, 0.2};
        break;
    default:
        return {(int)n};
    }
    std::vector<int> sizes;
    int sum = 0;
    for (size_t i = 0; i < p.size() - 1; ++i) {
        int s = std::ceil(p[i] * n);
        sizes.push_back(s);
        sum += s;
    }
    sizes.push_back(n - sum);
    return sizes;
}

// Wrap base functions with CEC scaling and offsets
BenchmarkFcn wrap_cec(const std::string &name, int n, const VectorXd &o_vec = VectorXd(),
                      double sh_rate_override = -1.0) {
    auto base_fcn = get_function_ptr(name);
    double sh_rate = 1.0;
    double offset = 0.0;

    if (name == "rosenbrock") {
        sh_rate = 2.048 / 100.0;
        offset = 1.0;
    } else if (name == "rastrigin" || name == "rastrigin_noncont") {
        sh_rate = 5.12 / 100.0;
    } else if (name == "griewank") {
        sh_rate = 600.0 / 100.0;
    } else if (name == "schwefel" || name == "schwefel_cec") {
        // For Schwefel, we ignore sh_rate and offset because it's handled internally in
        // schwefel_cec
        return &schwefel_cec;
    } else if (name == "weierstrass") {
        sh_rate = 0.5 / 100.0;
    } else if (name == "katsuura") {
        sh_rate = 5.0 / 100.0;
    } else if (name == "happycat") {
        sh_rate = 5.0 / 100.0;
        offset = -1.0;
    } else if (name == "hgbat") {
        sh_rate = 5.0 / 100.0;
        offset = -1.0;
    } else if (name == "f8f2") {
        sh_rate = 5.0 / 100.0;
        offset = 1.0;
    } else if (name == "lunacekbirastrigin") {
        return [n, o_vec](const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
            const double mu0 = 2.5;
            const double d_param = 1.0;
            const double s = 1.0 - (1.0 / (2.0 * std::sqrt(n + 20.0) - 8.2));
            const double mu1 = -std::sqrt((mu0 * mu0 - d_param) / s);

            MatrixXd z = 0.2 * x;
            if (o_vec.size() == n) {
                for (int i = 0; i < n; ++i) {
                    if (o_vec(i) < 0)
                        z.col(i) *= -1.0;
                }
            }

            const VectorXd sum_sq_z = (z.array()).square().rowwise().sum();
            const VectorXd sum_sq_z_mu = (z.array() + mu0 - mu1).square().rowwise().sum();
            const VectorXd deceptive =
                sum_sq_z.cwiseMin(((s * sum_sq_z_mu).array() + d_param * n).matrix());
            const VectorXd rastrigin =
                10.0 * (n - (2.0 * EIGEN_PI * z.array()).cos().rowwise().sum());
            return VectorXd(deceptive + rastrigin);
        };
    }

    if (sh_rate_override > 0)
        sh_rate = sh_rate_override;

    if (sh_rate == 1.0 && offset == 0.0)
        return base_fcn;

    return [base_fcn, sh_rate,
            offset](const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
        return base_fcn((x.array() * sh_rate + offset).matrix());
    };
}

// Helper for CEC 2014 Hybrid function partitions
std::vector<int> get_partition_sizes_2014(int fid, int n) {
    std::vector<double> p;
    switch (fid) {
    case 17:
    case 18:
        p = {0.3, 0.3, 0.4};
        break;
    case 19:
    case 20:
        p = {0.2, 0.2, 0.3, 0.3};
        break;
    case 21:
    case 22:
        p = {0.1, 0.2, 0.2, 0.2, 0.3};
        break;
    default:
        return {(int)n};
    }
    std::vector<int> sizes;
    int sum = 0;
    for (size_t i = 0; i < p.size() - 1; ++i) {
        int s = std::ceil(p[i] * n);
        sizes.push_back(s);
        sum += s;
    }
    sizes.push_back(n - sum);
    return sizes;
}

VectorXd evaluate_2014(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, int fid) {
    const int n = x.cols();
    const int m = x.rows();

    Data data = get_data(2014, fid, n);
    VectorXd shift_vec = Map<const VectorXd>(data.shift, n);

    if (fid <= 16) {
        MatrixXd rotation =
            Map<const Matrix<double, Dynamic, Dynamic, RowMajor>>(data.rotation, n, n);
        Composition comp;
        comp.set_constant_C(1.0);

        std::string base_name;
        bool rotate = true;

        switch (fid) {
        case 1:
            base_name = "elliptic";
            break;
        case 2:
            base_name = "bentcigar";
            break;
        case 3:
            base_name = "discus";
            break;
        case 4:
            base_name = "rosenbrock";
            break;
        case 5:
            base_name = "ackley";
            break;
        case 6:
            base_name = "weierstrass";
            break;
        case 7:
            base_name = "griewank";
            break;
        case 8:
            base_name = "rastrigin";
            rotate = false;
            break;
        case 9:
            base_name = "rastrigin";
            break;
        case 10:
            base_name = "schwefel";
            rotate = false;
            break;
        case 11:
            base_name = "schwefel";
            break;
        case 12:
            base_name = "katsuura";
            break;
        case 13:
            base_name = "happycat";
            break;
        case 14:
            base_name = "hgbat";
            break;
        case 15:
            base_name = "f8f2";
            break;
        case 16:
            base_name = "schafferf6";
            break;
        default:
            throw std::invalid_argument("F" + std::to_string(fid) + " invalid for simple suite.");
        }

        comp.add_component(wrap_cec(base_name, n, shift_vec), shift_vec,
                           rotate ? rotation : MatrixXd::Identity(n, n), 1.0, 1.0,
                           (double)fid * 100.0, 1.0);
        return comp.evaluate(x);

    } else if (fid <= 22) {
        MatrixXd rotation =
            Map<const Matrix<double, Dynamic, Dynamic, RowMajor>>(data.rotation, n, n);
        // CEC 2014 Hybrid: Shift -> Rotate -> Shuffle
        MatrixXd z = (x.rowwise() - shift_vec.transpose()).matrix() * rotation;

        VectorXd current_shift = shift_vec;
        if (data.permutation) {
            MatrixXd shuffled_z(m, n);
            VectorXd shuffled_o(n);
            for (int i = 0; i < n; ++i) {
                shuffled_z.col(i) = z.col(data.permutation[i]);
                shuffled_o(i) = shift_vec(data.permutation[i]);
            }
            z = shuffled_z;
            current_shift = shuffled_o;
        }

        std::vector<int> sizes = get_partition_sizes_2014(fid, n);
        std::vector<std::string> base_fcns;
        switch (fid) {
        case 17:
            base_fcns = {"rastrigin", "rastrigin", "elliptic"};
            break; // f9, f8, f1
        case 18:
            base_fcns = {"bentcigar", "katsuura", "rastrigin"};
            break; // f2, f12, f8
        case 19:
            base_fcns = {"griewank", "weierstrass", "rosenbrock", "hgbat"};
            break; // f7, f6, f4, f14
        case 20:
            base_fcns = {"katsuura", "discus", "happycat", "rastrigin"};
            break; // f12, f3, f13, f8
        case 21:
            base_fcns = {"hgbat", "katsuura", "rosenbrock", "rastrigin", "elliptic"};
            break; // f14, f12, f4, f9, f1
        case 22:
            base_fcns = {"schwefel", "schwefel", "happycat", "rastrigin", "rosenbrock"};
            break; // f10, f11, f13, f9, f4
        }

        VectorXd scores = VectorXd::Zero(m);
        int current_col = 0;
        for (size_t i = 0; i < base_fcns.size(); ++i) {
            int size = sizes[i];
            auto sub_z = z.block(0, current_col, m, size);
            VectorXd sub_o = current_shift.segment(current_col, size);
            scores += wrap_cec(base_fcns[i], size, sub_o)(sub_z);
            current_col += size;
        }

        return scores.array() + (double)fid * 100.0;

    } else {
        int cf_num = 0;
        std::vector<std::string> base_fcns;
        std::vector<double> sigmas;
        std::vector<double> lambdas;

        switch (fid) {
        case 23:
            cf_num = 5;
            base_fcns = {"rosenbrock", "elliptic", "bentcigar", "discus", "elliptic"};
            sigmas = {10, 20, 30, 40, 50};
            lambdas = {1.0, 1e-6, 1e-26, 1e-6, 1e-6};
            break;
        case 24:
            cf_num = 3;
            base_fcns = {"schwefel", "rastrigin", "hgbat"};
            sigmas = {20, 20, 20};
            lambdas = {1, 1, 1};
            break;
        case 25:
            cf_num = 3;
            base_fcns = {"schwefel", "rastrigin", "elliptic"};
            sigmas = {10, 30, 50};
            lambdas = {0.25, 1.0, 1e-7};
            break;
        case 26:
            cf_num = 5;
            base_fcns = {"schwefel", "happycat", "elliptic", "weierstrass", "griewank"};
            sigmas = {10, 10, 10, 10, 10};
            lambdas = {0.25, 1.0, 1e-7, 2.5, 10.0};
            break;
        case 27:
            cf_num = 5;
            base_fcns = {"hgbat", "rastrigin", "schwefel", "weierstrass", "elliptic"};
            sigmas = {10, 10, 10, 20, 20};
            lambdas = {10, 10, 2.5, 25, 1e-6};
            break;
        case 28:
            cf_num = 5;
            base_fcns = {"f8f2", "happycat", "schwefel", "schafferf6", "elliptic"};
            sigmas = {10, 20, 30, 40, 50};
            lambdas = {2.5, 10, 2.5, 5e-4, 1e-6};
            break;
        case 29:
            cf_num = 3;
            base_fcns = {"hybrid_f17", "hybrid_f18", "hybrid_f19"};
            sigmas = {10, 30, 50};
            lambdas = {1, 1, 1};
            break;
        case 30:
            cf_num = 3;
            base_fcns = {"hybrid_f20", "hybrid_f21", "hybrid_f22"};
            sigmas = {10, 30, 50};
            lambdas = {1, 1, 1};
            break;
        }

        Composition comp;
        comp.set_use_sqrt_weight(true);
        comp.set_constant_C(1.0);

        for (int i = 0; i < cf_num; ++i) {
            VectorXd sub_shift = Map<const VectorXd>(data.shift + i * 100, n);
            MatrixXd sub_rot = Map<const Matrix<double, Dynamic, Dynamic, RowMajor>>(
                data.rotation + i * n * n, n, n);

            BenchmarkFcn fptr;
            if (base_fcns[i].substr(0, 7) == "hybrid_") {
                int h_fid = std::stoi(base_fcns[i].substr(8));
                fptr = [h_fid](const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &v) {
                    const int nx = v.cols();
                    const int mx = v.rows();
                    std::vector<int> h_sizes = get_partition_sizes_2014(h_fid, nx);
                    Data h_data = get_data(2014, h_fid, nx);
                    VectorXd h_shift_vec = Map<const VectorXd>(h_data.shift, nx);
                    MatrixXd h_rot = Map<const Matrix<double, Dynamic, Dynamic, RowMajor>>(
                        h_data.rotation, nx, nx);

                    // CEC 2014 Hybrid Logic: Shift -> Rotate -> Shuffle
                    // But here 'v' is already the component vector which is part of the
                    // composition's rotated space. Actually, Composition::evaluate does its own
                    // shift and rotation. For CEC hybrids inside composition, it's simpler to just
                    // evaluate them on 'v'.
                    MatrixXd vz = v * h_rot; // Already shifted by Composition
                    VectorXd vo = h_shift_vec;
                    if (h_data.permutation) {
                        MatrixXd svz(mx, nx);
                        VectorXd svo(nx);
                        for (int k = 0; k < nx; ++k) {
                            svz.col(k) = vz.col(h_data.permutation[k]);
                            svo(k) = h_shift_vec(h_data.permutation[k]);
                        }
                        vz = svz;
                        vo = svo;
                    }
                    std::vector<std::string> h_base_fcns;
                    switch (h_fid) {
                    case 17:
                        h_base_fcns = {"rastrigin", "rastrigin", "elliptic"};
                        break;
                    case 18:
                        h_base_fcns = {"bentcigar", "katsuura", "rastrigin"};
                        break;
                    case 19:
                        h_base_fcns = {"griewank", "weierstrass", "rosenbrock", "hgbat"};
                        break;
                    case 20:
                        h_base_fcns = {"katsuura", "discus", "happycat", "rastrigin"};
                        break;
                    case 21:
                        h_base_fcns = {"hgbat", "katsuura", "rosenbrock", "rastrigin", "elliptic"};
                        break;
                    case 22:
                        h_base_fcns = {"schwefel", "schwefel", "happycat", "rastrigin",
                                       "rosenbrock"};
                        break;
                    }
                    VectorXd h_res = VectorXd::Zero(mx);
                    int cur = 0;
                    for (size_t k = 0; k < h_base_fcns.size(); ++k) {
                        int sz = h_sizes[k];
                        h_res += wrap_cec(h_base_fcns[k], sz,
                                          vo.segment(cur, sz))(vz.block(0, cur, mx, sz));
                        cur += sz;
                    }
                    return h_res;
                };
            } else {
                fptr = wrap_cec(base_fcns[i], n, sub_shift);
            }

            comp.add_component(fptr, sub_shift, sub_rot, sigmas[i], lambdas[i], (double)i * 100.0,
                               1.0);
        }

        return comp.evaluate(x).array() + (double)fid * 100.0;
    }
}

VectorXd evaluate_2017(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, int fid) {
    const int n = x.cols();
    const int m = x.rows();

    Data data = get_data(2017, fid, n);
    VectorXd shift_vec = Map<const VectorXd>(data.shift, n);

    if (fid <= 10) {
        if (fid == 2)
            throw std::invalid_argument("CEC 2017 F2 was removed.");

        MatrixXd rotation =
            Map<const Matrix<double, Dynamic, Dynamic, RowMajor>>(data.rotation, n, n);
        Composition comp;
        comp.set_constant_C(1.0);

        std::string base_name;
        bool apply_osz = false;
        bool apply_asy = false;

        switch (fid) {
        case 1:
            base_name = "bentcigar";
            apply_asy = true;
            break;
        case 3:
            base_name = "zakharov";
            break;
        case 4:
            base_name = "rosenbrock";
            break;
        case 5:
            base_name = "rastrigin";
            apply_osz = true;
            apply_asy = true;
            break;
        case 6:
            base_name = "schafferf6";
            apply_asy = true;
            break;
        case 7:
            base_name = "lunacekbirastrigin";
            break;
        case 8:
            base_name = "rastrigin_noncont";
            apply_osz = true;
            apply_asy = true;
            break;
        case 9:
            base_name = "levy";
            apply_osz = true;
            break;
        case 10:
            base_name = "schwefel";
            apply_osz = true;
            apply_asy = true;
            break;
        default:
            throw std::invalid_argument("F" + std::to_string(fid) + " invalid for simple suite.");
        }

        comp.add_component(wrap_cec(base_name, n, shift_vec), shift_vec, rotation, 1.0, 1.0,
                           (double)fid * 100.0, 1.0, apply_osz, apply_asy);
        return comp.evaluate(x);

    } else if (fid <= 20) {
        MatrixXd rotation =
            Map<const Matrix<double, Dynamic, Dynamic, RowMajor>>(data.rotation, n, n);
        MatrixXd z = (x.rowwise() - shift_vec.transpose()).matrix() * rotation;

        VectorXd current_shift = shift_vec;
        if (data.permutation) {
            MatrixXd shuffled_z(m, n);
            VectorXd shuffled_o(n);
            for (int i = 0; i < n; ++i) {
                shuffled_z.col(i) = z.col(data.permutation[i]);
                shuffled_o(i) = shift_vec(data.permutation[i]);
            }
            z = shuffled_z;
            current_shift = shuffled_o;
        }

        std::vector<int> sizes = get_partition_sizes(fid, n);
        std::vector<std::string> base_fcns;
        switch (fid) {
        case 11:
            base_fcns = {"zakharov", "rosenbrock", "rastrigin"};
            break;
        case 12:
            base_fcns = {"elliptic", "schwefel", "bentcigar"};
            break;
        case 13:
            base_fcns = {"bentcigar", "rosenbrock", "lunacekbirastrigin"};
            break;
        case 14:
            base_fcns = {"elliptic", "ackley", "schafferf7", "rastrigin"};
            break;
        case 15:
            base_fcns = {"bentcigar", "hgbat", "rastrigin", "rosenbrock"};
            break;
        case 16:
            base_fcns = {"schafferf6", "hgbat", "rosenbrock", "schwefel"};
            break;
        case 17:
            base_fcns = {"katsuura", "ackley", "f8f2", "schwefel", "rastrigin"};
            break;
        case 18:
            base_fcns = {"elliptic", "ackley", "rastrigin", "hgbat", "discus"};
            break;
        case 19:
            base_fcns = {"bentcigar", "rastrigin", "f8f2", "weierstrass", "schafferf6"};
            break;
        case 20:
            base_fcns = {"hgbat", "katsuura", "ackley", "rastrigin", "schwefel", "schafferf7"};
            break;
        }

        VectorXd scores = VectorXd::Zero(m);
        int current_col = 0;
        for (size_t i = 0; i < base_fcns.size(); ++i) {
            int size = sizes[i];
            auto sub_z = z.block(0, current_col, m, size);
            VectorXd sub_o = current_shift.segment(current_col, size);
            scores += wrap_cec(base_fcns[i], size, sub_o)(sub_z);
            current_col += size;
        }

        return scores.array() + (double)fid * 100.0;

    } else {
        int cf_num = 0;
        std::vector<std::string> base_fcns;
        std::vector<double> sigmas;

        switch (fid) {
        case 21:
            cf_num = 3;
            base_fcns = {"rosenbrock", "elliptic", "rastrigin"};
            sigmas = {10, 20, 30};
            break;
        case 22:
            cf_num = 3;
            base_fcns = {"rastrigin", "griewank", "schwefel"};
            sigmas = {10, 20, 30};
            break;
        case 23:
            cf_num = 4;
            base_fcns = {"rosenbrock", "ackley", "schwefel", "rastrigin"};
            sigmas = {10, 20, 30, 40};
            break;
        case 24:
            cf_num = 4;
            base_fcns = {"ackley", "elliptic", "griewank", "rastrigin"};
            sigmas = {10, 20, 30, 40};
            break;
        case 25:
            cf_num = 5;
            base_fcns = {"rastrigin", "happycat", "ackley", "discus", "rosenbrock"};
            sigmas = {10, 20, 30, 40, 50};
            break;
        case 26:
            cf_num = 5;
            base_fcns = {"schafferf6", "schwefel", "griewank", "rosenbrock", "rastrigin"};
            sigmas = {10, 20, 30, 40, 50};
            break;
        case 27:
            cf_num = 6;
            base_fcns = {"hgbat", "rastrigin", "schwefel", "bentcigar", "elliptic", "schafferf6"};
            sigmas = {10, 10, 10, 20, 20, 20};
            break;
        case 28:
            cf_num = 10;
            base_fcns = {"ackley",     "griewank", "discus",    "rosenbrock", "happycat",
                         "schafferf6", "schwefel", "rastrigin", "elliptic",   "bentcigar"};
            sigmas = {10, 10, 20, 20, 30, 30, 40, 40, 50, 50};
            break;
        case 29:
            cf_num = 3;
            base_fcns = {"hybrid_f15", "hybrid_f16", "hybrid_f17"};
            sigmas = {10, 30, 50};
            break;
        case 30:
            cf_num = 3;
            base_fcns = {"hybrid_f15", "hybrid_f18", "hybrid_f19"};
            sigmas = {10, 30, 50};
            break;
        }

        Composition comp;
        comp.set_use_sqrt_weight(true);
        comp.set_constant_C(1.0);

        for (int i = 0; i < cf_num; ++i) {
            VectorXd sub_shift = Map<const VectorXd>(data.shift + i * 100, n);
            MatrixXd sub_rot = Map<const Matrix<double, Dynamic, Dynamic, RowMajor>>(
                data.rotation + i * n * n, n, n);

            BenchmarkFcn fptr;
            if (base_fcns[i].substr(0, 7) == "hybrid_") {
                int h_fid = std::stoi(base_fcns[i].substr(8));
                fptr = [h_fid](const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &v) {
                    const int nx = v.cols();
                    const int mx = v.rows();
                    std::vector<int> h_sizes = get_partition_sizes(h_fid, nx);
                    Data h_data = get_data(2017, h_fid, nx);
                    VectorXd h_shift_vec = Map<const VectorXd>(h_data.shift, nx);
                    MatrixXd vz = v;
                    VectorXd vo = h_shift_vec;
                    if (h_data.permutation) {
                        MatrixXd svz(mx, nx);
                        VectorXd svo(nx);
                        for (int k = 0; k < nx; ++k) {
                            svz.col(k) = v.col(h_data.permutation[k]);
                            svo(k) = h_shift_vec(h_data.permutation[k]);
                        }
                        vz = svz;
                        vo = svo;
                    }
                    std::vector<std::string> h_base_fcns;
                    switch (h_fid) {
                    case 15:
                        h_base_fcns = {"bentcigar", "hgbat", "rastrigin", "rosenbrock"};
                        break;
                    case 16:
                        h_base_fcns = {"schafferf6", "hgbat", "rosenbrock", "schwefel"};
                        break;
                    case 17:
                        h_base_fcns = {"katsuura", "ackley", "f8f2", "schwefel", "rastrigin"};
                        break;
                    case 18:
                        h_base_fcns = {"elliptic", "ackley", "rastrigin", "hgbat", "discus"};
                        break;
                    case 19:
                        h_base_fcns = {"bentcigar", "rastrigin", "f8f2", "weierstrass",
                                       "schafferf6"};
                        break;
                    }
                    VectorXd h_res = VectorXd::Zero(mx);
                    int cur = 0;
                    for (size_t k = 0; k < h_base_fcns.size(); ++k) {
                        int sz = h_sizes[k];
                        h_res += wrap_cec(h_base_fcns[k], sz,
                                          vo.segment(cur, sz))(vz.block(0, cur, mx, sz));
                        cur += sz;
                    }
                    return h_res;
                };
            } else {
                fptr = wrap_cec(base_fcns[i], n, sub_shift);
            }

            comp.add_component(fptr, sub_shift, sub_rot, sigmas[i], 1.0, (double)i * 100.0, 1.0);
        }

        return comp.evaluate(x).array() + (double)fid * 100.0;
    }
}

// --- CEC 2019 100-Digit Challenge Functions ---

VectorXd chebyshev(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols();
    const int num_points = 32 * n;

    // dx = T_8(1.2) = 72.66066685442085
    const double dx = 72.66066685442085;

    return apply_parallel(x, [n, num_points, dx](const ArrayXXd &a_x) {
        const int batch_m = a_x.rows();
        VectorXd scores(batch_m);

        for (int i = 0; i < batch_m; ++i) {
            double p1 = 0, p2 = 0, p3 = 0;

            // p1: P(1.2) >= dx
            double u = 0;
            for (int j = 0; j < n; ++j)
                u = u * 1.2 + a_x(i, j);
            if (u < dx)
                p1 = (u - dx) * (u - dx);

            // p2: P(-1.2) >= dx
            double v = 0;
            for (int j = 0; j < n; ++j)
                v = v * (-1.2) + a_x(i, j);
            if (v < dx)
                p2 = (v - dx) * (v - dx);

            // p3: |P(z)| <= 1 for z in [-1, 1]
            for (int k = 0; k <= num_points; ++k) {
                double zk = (2.0 * k) / num_points - 1.0;
                double w = 0;
                for (int j = 0; j < n; ++j)
                    w = w * zk + a_x(i, j);
                if (w > 1.0)
                    p3 += (w - 1.0) * (w - 1.0);
                else if (w < -1.0)
                    p3 += (w + 1.0) * (w + 1.0);
            }
            scores(i) = p1 + p2 + p3 + 1.0;
        }
        return scores;
    });
}

VectorXd hilbert(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols(); // Should be 16
    const int k = (int)std::sqrt(n);

    MatrixXd H(k, k);
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            H(i, j) = 1.0 / (i + j + 1.0);
        }
    }

    return apply_parallel(x, [&H, k](const ArrayXXd &a_x) {
        const int batch_m = a_x.rows();
        VectorXd scores(batch_m);

        for (int i = 0; i < batch_m; ++i) {
            // x as k-by-k matrix Z
            Map<const Matrix<double, Dynamic, Dynamic, RowMajor>> Z(a_x.row(i).data(), k, k);
            MatrixXd W = H * Z;
            W.diagonal().array() -= 1.0;
            scores(i) = W.array().abs().sum() + 1.0;
        }
        return scores;
    });
}

VectorXd lennard_jones(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) {
    const int n = x.cols(); // Should be 18
    const int num_atoms = n / 3;
    const double bias = 13.7120622568;

    return apply_parallel(x, [num_atoms, bias](const ArrayXXd &a_x) {
        const int batch_m = a_x.rows();
        VectorXd scores(batch_m);

        for (int b = 0; b < batch_m; ++b) {
            double energy = 0;
            for (int i = 0; i < num_atoms - 1; ++i) {
                for (int j = i + 1; j < num_atoms; ++j) {
                    double dx = a_x(b, i * 3) - a_x(b, j * 3);
                    double dy = a_x(b, i * 3 + 1) - a_x(b, j * 3 + 1);
                    double dz = a_x(b, i * 3 + 2) - a_x(b, j * 3 + 2);
                    double r2 = dx * dx + dy * dy + dz * dz;
                    if (r2 < 1e-18) {
                        energy += 1e20; // Penalty for singularity
                    } else {
                        double r6 = r2 * r2 * r2;
                        energy += (1.0 / (r6 * r6)) - (2.0 / r6);
                    }
                }
            }
            scores(b) = energy + bias;
        }
        return scores;
    });
}

VectorXd evaluate_2019(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, int fid) {
    const int n = x.cols();

    if (fid == 1)
        return chebyshev(x);
    if (fid == 2)
        return hilbert(x);
    if (fid == 3)
        return lennard_jones(x);

    Data data = get_data(2019, fid, n);
    VectorXd shift_vec = Map<const VectorXd>(data.shift, n);
    MatrixXd rotation = Map<const Matrix<double, Dynamic, Dynamic, RowMajor>>(data.rotation, n, n);

    Composition comp;
    comp.set_constant_C(1.0);

    std::string base_name;
    double sh_rate = 1.0;

    switch (fid) {
    case 4:
        base_name = "rastrigin";
        sh_rate = 5.12 / 100.0;
        break;
    case 5:
        base_name = "griewank";
        sh_rate = 600.0 / 100.0;
        break;
    case 6:
        base_name = "weierstrass";
        sh_rate = 0.5 / 100.0;
        break;
    case 7:
        base_name = "schwefel_cec";
        sh_rate = 1000.0 / 100.0;
        break;
    case 8:
        base_name = "schafferf6";
        break;
    case 9:
        base_name = "happycat";
        sh_rate = 5.0 / 100.0;
        break;
    case 10:
        base_name = "ackley";
        break;
    default:
        throw std::invalid_argument("CEC 2019 FID must be 1-10.");
    }

    comp.add_component(wrap_cec(base_name, n, shift_vec, sh_rate), shift_vec, rotation, 1.0, 1.0,
                       1.0, 1.0);
    return comp.evaluate(x);
}

// --- CEC 2020 Functions ---

VectorXd evaluate_2020(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, int fid) {
    const int n = x.cols();
    const int m = x.rows();

    // Internal mapping for 2020: {1, 2, 3, 7, 4, 16, 6, 22, 24, 25}
    int internal_ids[] = {1, 2, 3, 7, 4, 16, 6, 22, 24, 25};
    if (fid < 1 || fid > 10)
        throw std::invalid_argument("CEC 2020 FID must be 1-10.");
    int internal_fid = internal_ids[fid - 1];

    Data data = get_data(2020, internal_fid, n);
    VectorXd shift_vec = Map<const VectorXd>(data.shift, n);

    if (fid <= 4) {
        MatrixXd rotation =
            Map<const Matrix<double, Dynamic, Dynamic, RowMajor>>(data.rotation, n, n);
        Composition comp;
        comp.set_constant_C(1.0);
        std::string base_name;
        double sh_rate = 1.0;

        switch (fid) {
        case 1:
            base_name = "bentcigar";
            break;
        case 2:
            base_name = "schwefel_cec";
            sh_rate = 10.0;
            break;
        case 3:
            base_name = "lunacekbirastrigin";
            sh_rate = 0.1;
            break;
        case 4:
            base_name = "f8f2";
            sh_rate = 0.05;
            break;
        }

        comp.add_component(wrap_cec(base_name, n, shift_vec, sh_rate), shift_vec, rotation, 1.0,
                           1.0, (double)fid * 100.0, 1.0);
        // Special biases for 2020: 100, 700, 800, 900
        double bias = (fid == 1) ? 100.0 : (600.0 + (double)fid * 100.0);
        return comp.evaluate(x).array() - (double)fid * 100.0 + bias;

    } else if (fid <= 7) {
        MatrixXd rotation =
            Map<const Matrix<double, Dynamic, Dynamic, RowMajor>>(data.rotation, n, n);
        MatrixXd z = (x.rowwise() - shift_vec.transpose()).matrix() * rotation;

        VectorXd current_shift = shift_vec;
        if (data.permutation) {
            MatrixXd shuffled_z(m, n);
            VectorXd shuffled_o(n);
            for (int i = 0; i < n; ++i) {
                shuffled_z.col(i) = z.col(data.permutation[i]);
                shuffled_o(i) = shift_vec(data.permutation[i]);
            }
            z = shuffled_z;
            current_shift = shuffled_o;
        }

        std::vector<double> p;
        std::vector<std::string> base_fcns;
        std::vector<double> sh_rates;

        if (fid == 5) { // hf01
            p = {0.3, 0.3, 0.4};
            base_fcns = {"schwefel_cec", "rastrigin", "elliptic"};
            sh_rates = {10.0, 0.0512, 1.0};
        } else if (fid == 6) { // hf06 (internal 16)
            p = {0.25, 0.25, 0.25, 0.25};
            base_fcns = {"schafferf6", "hgbat", "rosenbrock", "schwefel_cec"};
            sh_rates = {1.0, 0.05, 0.02048, 10.0};
        } else { // hf05 (internal 6)
            p = {0.2, 0.2, 0.2, 0.2, 0.2};
            base_fcns = {"schafferf6", "hgbat", "rosenbrock", "schwefel_cec", "elliptic"};
            sh_rates = {1.0, 0.05, 0.02048, 10.0, 1.0};
        }

        std::vector<int> sizes;
        int sum = 0;
        for (size_t i = 0; i < p.size() - 1; ++i) {
            int s = std::ceil(p[i] * n);
            sizes.push_back(s);
            sum += s;
        }
        sizes.push_back(n - sum);

        VectorXd scores = VectorXd::Zero(m);
        int current_col = 0;
        for (size_t i = 0; i < base_fcns.size(); ++i) {
            int size = sizes[i];
            auto sub_z = z.block(0, current_col, m, size);
            VectorXd sub_o = current_shift.segment(current_col, size);
            scores += wrap_cec(base_fcns[i], size, sub_o, sh_rates[i])(sub_z);
            current_col += size;
        }
        double bias = (fid == 5) ? 1600.0 : (fid == 6 ? 1700.0 : 1800.0);
        return scores.array() + bias;

    } else {
        int cf_num = 0;
        std::vector<std::string> base_fcns;
        std::vector<double> sigmas;
        std::vector<double> sh_rates;

        if (fid == 8) { // cf02 (internal 22)
            cf_num = 3;
            base_fcns = {"rosenbrock", "elliptic", "rastrigin"};
            sigmas = {10, 20, 30};
            sh_rates = {0.02048, 1.0, 0.0512};
        } else if (fid == 9) { // cf04 (internal 24)
            cf_num = 4;
            base_fcns = {"ackley", "elliptic", "griewank", "rastrigin"};
            sigmas = {10, 20, 30, 40};
            sh_rates = {1.0, 1.0, 6.0, 0.0512};
        } else { // cf05 (internal 25)
            cf_num = 5;
            base_fcns = {"rastrigin", "happycat", "ackley", "discus", "rosenbrock"};
            sigmas = {10, 20, 30, 40, 50};
            sh_rates = {0.0512, 0.05, 1.0, 1.0, 0.02048};
        }

        Composition comp;
        comp.set_use_sqrt_weight(true);
        comp.set_constant_C(1.0);

        for (int i = 0; i < cf_num; ++i) {
            VectorXd sub_shift = Map<const VectorXd>(data.shift + i * 100, n);
            MatrixXd sub_rot = Map<const Matrix<double, Dynamic, Dynamic, RowMajor>>(
                data.rotation + i * n * n, n, n);
            comp.add_component(wrap_cec(base_fcns[i], n, sub_shift, sh_rates[i]), sub_shift,
                               sub_rot, sigmas[i], 1.0, (double)i * 100.0, 1.0);
        }
        double bias = (fid == 8) ? 2200.0 : (fid == 9 ? 2300.0 : 2400.0);
        return comp.evaluate(x).array() + bias;
    }
}

// --- CEC 2022 Functions ---

VectorXd evaluate_2022(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x, int fid) {
    const int n = x.cols();
    const int m = x.rows();

    if (fid < 1 || fid > 12)
        throw std::invalid_argument("CEC 2022 FID must be 1-12.");

    Data data = get_data(2022, fid, n);
    VectorXd shift_vec = Map<const VectorXd>(data.shift, n);

    if (fid <= 5) {
        MatrixXd rotation =
            Map<const Matrix<double, Dynamic, Dynamic, RowMajor>>(data.rotation, n, n);
        Composition comp;
        comp.set_constant_C(1.0);
        std::string base_name;
        double sh_rate = 1.0;
        double bias = 0;

        switch (fid) {
        case 1:
            base_name = "zakharov";
            bias = 300.0;
            break;
        case 2:
            base_name = "rosenbrock";
            sh_rate = 0.02048;
            bias = 400.0;
            break;
        case 3:
            base_name = "schafferf7";
            bias = 600.0;
            break;
        case 4:
            base_name = "rastrigin_noncont";
            sh_rate = 0.0512;
            bias = 800.0;
            break;
        case 5:
            base_name = "levy";
            bias = 900.0;
            break;
        }

        comp.add_component(wrap_cec(base_name, n, shift_vec, sh_rate), shift_vec, rotation, 1.0,
                           1.0, bias, 1.0);
        return comp.evaluate(x);

    } else if (fid <= 8) {
        MatrixXd rotation =
            Map<const Matrix<double, Dynamic, Dynamic, RowMajor>>(data.rotation, n, n);
        MatrixXd z = (x.rowwise() - shift_vec.transpose()).matrix() * rotation;

        VectorXd current_shift = shift_vec;
        if (data.permutation) {
            MatrixXd shuffled_z(m, n);
            VectorXd shuffled_o(n);
            for (int i = 0; i < n; ++i) {
                shuffled_z.col(i) = z.col(data.permutation[i]);
                shuffled_o(i) = shift_vec(data.permutation[i]);
            }
            z = shuffled_z;
            current_shift = shuffled_o;
        }

        std::vector<double> p;
        std::vector<std::string> base_fcns;
        std::vector<double> sh_rates;
        double bias = 0;

        if (fid == 6) { // hf02
            p = {0.4, 0.4, 0.2};
            base_fcns = {"bentcigar", "hgbat", "rastrigin"};
            sh_rates = {1.0, 0.05, 0.0512};
            bias = 1800.0;
        } else if (fid == 7) { // hf10
            p = {0.1, 0.2, 0.2, 0.2, 0.1, 0.2};
            base_fcns = {"hgbat", "katsuura", "ackley", "rastrigin", "schwefel_cec", "schafferf7"};
            sh_rates = {0.05, 0.05, 1.0, 0.0512, 10.0, 1.0};
            bias = 2000.0;
        } else { // hf06
            p = {0.3, 0.2, 0.2, 0.1, 0.2};
            base_fcns = {"katsuura", "happycat", "f8f2", "schwefel_cec", "ackley"};
            sh_rates = {0.05, 0.05, 0.05, 10.0, 1.0};
            bias = 2200.0;
        }

        std::vector<int> sizes;
        int sum = 0;
        for (size_t i = 0; i < p.size() - 1; ++i) {
            int s = std::ceil(p[i] * n);
            sizes.push_back(s);
            sum += s;
        }
        sizes.push_back(n - sum);

        VectorXd scores = VectorXd::Zero(m);
        int current_col = 0;
        for (size_t i = 0; i < base_fcns.size(); ++i) {
            int size = sizes[i];
            auto sub_z = z.block(0, current_col, m, size);
            VectorXd sub_o = current_shift.segment(current_col, size);
            scores += wrap_cec(base_fcns[i], size, sub_o, sh_rates[i])(sub_z);
            current_col += size;
        }
        return scores.array() + bias;

    } else {
        int cf_num = 0;
        std::vector<std::string> base_fcns;
        std::vector<double> sigmas;
        std::vector<double> sh_rates;
        std::vector<double> biases;
        double final_bias = 0;

        if (fid == 9) { // cf01
            cf_num = 5;
            base_fcns = {"rosenbrock", "elliptic", "bentcigar", "discus", "elliptic"};
            sigmas = {10, 20, 30, 40, 50};
            sh_rates = {0.02048, 1.0, 1.0, 1.0, 1.0};
            biases = {0, 200, 300, 100, 400};
            final_bias = 2300.0;
        } else if (fid == 10) { // cf02
            cf_num = 3;
            base_fcns = {"schwefel_cec", "rastrigin", "hgbat"};
            sigmas = {20, 10, 10};
            sh_rates = {10.0, 0.0512, 0.05};
            biases = {0, 200, 100};
            final_bias = 2400.0;
        } else if (fid == 11) { // cf06
            cf_num = 5;
            base_fcns = {"schafferf6", "schwefel_cec", "griewank", "rosenbrock", "rastrigin"};
            sigmas = {20, 20, 30, 30, 20};
            sh_rates = {1.0, 10.0, 6.0, 0.02048, 0.0512};
            biases = {0, 200, 300, 400, 200};
            final_bias = 2600.0;
        } else { // cf07
            cf_num = 6;
            base_fcns = {"hgbat",     "rastrigin", "schwefel_cec",
                         "bentcigar", "elliptic",  "schafferf6"};
            sigmas = {10, 20, 30, 40, 50, 60};
            sh_rates = {0.05, 0.0512, 10.0, 1.0, 1.0, 1.0};
            biases = {0, 300, 500, 100, 400, 200};
            final_bias = 2700.0;
        }

        Composition comp;
        comp.set_use_sqrt_weight(true);
        comp.set_constant_C(1.0);

        for (int i = 0; i < cf_num; ++i) {
            VectorXd sub_shift = Map<const VectorXd>(data.shift + i * 100, n);
            MatrixXd sub_rot = Map<const Matrix<double, Dynamic, Dynamic, RowMajor>>(
                data.rotation + i * n * n, n, n);
            comp.add_component(wrap_cec(base_fcns[i], n, sub_shift, sh_rates[i]), sub_shift,
                               sub_rot, sigmas[i], 1.0, biases[i], 1.0);
        }
        return comp.evaluate(x).array() + final_bias;
    }
}

} // namespace BenchmarkFcns::CEC
