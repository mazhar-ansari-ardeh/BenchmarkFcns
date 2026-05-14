#ifndef COMPOSITION_H
#define COMPOSITION_H

#include <Eigen/Dense>
#include <functional>
#include <map>
#include <string>
#include <vector>

namespace BenchmarkFcns {
using namespace Eigen;

// Type definition for the vectorized benchmark functions
typedef std::function<VectorXd(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &)>
    BenchmarkFcn;

class Composition {
public:
    Composition();

    /**
     * Adds a base function component to the composition.
     * @param fcn Function wrapper for the base benchmark function
     * @param shift Vector of size N (dimensions) for shifting the optimum
     * @param rotation Matrix of size N-by-N for coordinate rotation
     * @param sigma Convergence range/coverage parameter
     * @param lambda Scaling parameter for the landscape
     * @param bias Internal bias for this component
     * @param f_max Estimated maximum value of the function (for height normalization)
     */
    void add_component(BenchmarkFcn fcn, const VectorXd &shift, const MatrixXd &rotation,
                       double sigma, double lambda, double bias, double f_max,
                       bool apply_osz = false, bool apply_asy = false,
                       const std::vector<int> &variables = {},
                       const VectorXd &input_offset = VectorXd());

    /**
     * Evaluates the composed function for a batch of points.
     * @param x Matrix of size M-by-N (M points in N dimensions)
     * @return Vector of size M containing the composed scores.
     */
    VectorXd evaluate(const Ref<const Matrix<double, Dynamic, Dynamic, RowMajor>> &x) const;

    void set_constant_C(double C) { constant_C = C; }
    void set_sum_mode(bool mode) { sum_mode = mode; }
    void set_use_sqrt_weight(bool use) { use_sqrt_weight = use; }

private:
    struct Component {
        BenchmarkFcn fcn;
        VectorXd shift;
        MatrixXd rotation;
        double sigma;
        double lambda;
        double bias;
        double f_max;
        bool apply_osz;
        bool apply_asy;
        VectorXd input_offset;
        std::vector<int> variables;
    };

    std::vector<Component> components;
    double constant_C = 2000.0;
    bool sum_mode = false;
    bool use_sqrt_weight = false;
};

/**
 * Helper to retrieve a built-in benchmark function pointer by name.
 */
BenchmarkFcn get_function_ptr(const std::string &name);
} // namespace BenchmarkFcns

#endif // COMPOSITION_H
