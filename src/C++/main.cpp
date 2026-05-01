#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <pybind11/functional.h>
#include <pybind11/stl.h>

# define STRINGIFY(x) #x
# define MACRO_STRINGIFY(x) STRINGIFY(x)

#include "benchmarkfcns.h"
#include "multifidelity.h"
#include "multiobjective.h"
#include "composition.h"

using namespace BenchmarkFcns;

namespace py = pybind11;

PYBIND11_MODULE(_core, m) {
    py::module_ mom = m.def_submodule("multiobjective", "Multi-objective functions");

    mom.def("bnh", &MultiObjective::bnh, py::arg("x"), py::arg("return_constraints") = false, R"pbdoc(
        Computes the value of the BNH (Binh and Korn) multi-objective benchmark function.
        SCORES = multiobjective.bnh(X) computes the value of the BNH function
        at point X. `multiobjective.bnh` accepts a matrix of size M-by-2 and returns
        a matrix SCORES of size M-by-2.
        If return_constraints is True, returns an M-by-4 matrix where the last two columns
        contain the constraint violations (values > 0 are violations).
        Properties:
        - Recommended domain: x1 in [0, 5], x2 in [0, 3]
    )pbdoc");

    mom.def("dtlz1", MultiObjective::dtlz1, py::arg("x"), py::arg("num_objectives") = 3, R"pbdoc(
        Computes the value of the DTLZ1 multi-objective benchmark function.
        SCORES = multiobjective.dtlz1(X, num_objectives) computes the value of the DTLZ1 function
        at point X. `multiobjective.dtlz1` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-K where K is the number of objectives.
        Properties:
        - Global Pareto front: Linear hyperplane (\sum f_i = 0.5)
        - Number of dimensions: n (usually k + num_objectives - 1, k=5)
        - Recommended domain: [0, 1]^n
        - Convexity: linear hyperplane
        - Modality: multimodal
        For more information, please visit:
        benchmarkfcns.info/doc/dtlz1fcn
    )pbdoc");

    mom.def("dtlz2", MultiObjective::dtlz2, py::arg("x"), py::arg("num_objectives") = 3, R"pbdoc(
        Computes the value of the DTLZ2 multi-objective benchmark function.
        SCORES = multiobjective.dtlz2(X, num_objectives) computes the value of the DTLZ2 function
        at point X. `multiobjective.dtlz2` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-K where K is the number of objectives.
        Properties:
        - Global Pareto front: Spherical (\sum f_i^2 = 1)
        - Number of dimensions: n (usually k + num_objectives - 1, k=10)
        - Recommended domain: [0, 1]^n
        - Convexity: concave
        - Modality: unimodal
        For more information, please visit:
        benchmarkfcns.info/doc/dtlz2fcn
    )pbdoc");

    mom.def("dtlz3", MultiObjective::dtlz3, py::arg("x"), py::arg("num_objectives") = 3, R"pbdoc(
        Computes the value of the DTLZ3 multi-objective benchmark function.
        SCORES = multiobjective.dtlz3(X, num_objectives) computes the value of the DTLZ3 function
        at point X. `multiobjective.dtlz3` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-K where K is the number of objectives.
        Properties:
        - Global Pareto front: Spherical (Concave)
        - Number of dimensions: n (usually k + num_objectives - 1, k=10)
        - Recommended domain: [0, 1]^n
        - Modality: Highly Multimodal (Numerous local Pareto fronts)
        For more information, please visit:
        benchmarkfcns.info/doc/dtlz3fcn
    )pbdoc");

    mom.def("dtlz4", MultiObjective::dtlz4, py::arg("x"), py::arg("num_objectives") = 3, py::arg("alpha") = 100.0, R"pbdoc(
        Computes the value of the DTLZ4 multi-objective benchmark function.
        SCORES = multiobjective.dtlz4(X, num_objectives, alpha) computes the value of the DTLZ4 function
        at point X. `multiobjective.dtlz4` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-K where K is the number of objectives.
        Properties:
        - Global Pareto front: Concave
        - Number of dimensions: n (usually 10)
        - Recommended domain: [0, 1]^n
        - Modality: multimodal
        - Characteristic: Tests ability to maintain biased distribution.
    )pbdoc");

    mom.def("dtlz5", MultiObjective::dtlz5, py::arg("x"), py::arg("num_objectives") = 3, R"pbdoc(
        Computes the value of the DTLZ5 multi-objective benchmark function.
        SCORES = multiobjective.dtlz5(X, num_objectives) computes the value of the DTLZ5 function
        at point X. `multiobjective.dtlz5` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-K where K is the number of objectives.
        Properties:
        - Global Pareto front: Degenerate (Curve)
        - Number of dimensions: n (usually 10)
        - Recommended domain: [0, 1]^n
        - Modality: unimodal
        - Characteristic: Tests ability to converge to a lower-dimensional Pareto front.
    )pbdoc");

    mom.def("dtlz6", MultiObjective::dtlz6, py::arg("x"), py::arg("num_objectives") = 3, R"pbdoc(
        Computes the value of the DTLZ6 multi-objective benchmark function.
        SCORES = multiobjective.dtlz6(X, num_objectives) computes the value of the DTLZ6 function
        at point X. `multiobjective.dtlz6` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-K where K is the number of objectives.
        Properties:
        - Global Pareto front: Degenerate (Curve)
        - Number of dimensions: n (usually 10)
        - Recommended domain: [0, 1]^n
        - Modality: multimodal
        - Characteristic: A harder version of DTLZ5.
    )pbdoc");

    mom.def("dtlz7", MultiObjective::dtlz7, py::arg("x"), py::arg("num_objectives") = 3, R"pbdoc(
        Computes the value of the DTLZ7 multi-objective benchmark function.
        SCORES = multiobjective.dtlz7(X, num_objectives) computes the value of the DTLZ7 function
        at point X. `multiobjective.dtlz7` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-K where K is the number of objectives.
        Properties:
        - Global Pareto front: Disconnected (2^(M-1) regions)
        - Number of dimensions: n (usually 20)
        - Recommended domain: [0, 1]^n
        - Modality: multimodal (disconnected front)
        For more information, please visit:
        benchmarkfcns.info/doc/dtlz7fcn
    )pbdoc");

    mom.def("fonsecafleming", MultiObjective::fonsecafleming, R"pbdoc(
        Computes the value of the Fonseca-Fleming multi-objective benchmark function.
        SCORES = multiobjective.fonsecafleming(X) computes the value of the Fonseca-Fleming
        function at point X. `multiobjective.fonsecafleming` accepts a matrix of size M-by-N
        and returns a matrix SCORES of size M-by-2 containing the function values for each
        objective.
        Properties:
        - Number of dimensions: n (typically 2 or 3)
        - Recommended domain: [-4, 4]^n
        - Pareto front: Concave
        - Separability: Non-separable
        - Modality: Unimodal (in terms of single objective components)
    )pbdoc");

    mom.def("kursawe", MultiObjective::kursawe, R"pbdoc(
        Computes the value of the Kursawe multi-objective benchmark function.
        SCORES = multiobjective.kursawe(X) computes the value of the Kursawe function
        at point X. `multiobjective.kursawe` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-2.
        Properties:
        - Global Pareto front: Disconnected and non-convex
        - Number of dimensions: n (usually 3)
        - Recommended domain: [-5, 5]^n
        - Modality: multimodal
        For more information, please visit:
        benchmarkfcns.info/doc/kursafcn
    )pbdoc");

    mom.def("osyczkakundu", &MultiObjective::osyczkakundu, py::arg("x"), py::arg("return_constraints") = false, R"pbdoc(
        Computes the value of the Osyczka and Kundu multi-objective benchmark function.
        SCORES = multiobjective.osyczkakundu(X) computes the value of the Osyczka and Kundu function
        at point X. `multiobjective.osyczkakundu` accepts a matrix of size M-by-6 and returns
        a matrix SCORES of size M-by-2.
        If return_constraints is True, returns an M-by-8 matrix where the last six columns
        contain the constraint violations (values > 0 are violations).
        Properties:
        - Number of dimensions: 6
        - Recommended domain: x1, x2, x6 in [0, 10]; x3, x5 in [1, 5]; x4 in [0, 6]
        - Constraints: 6 complex non-linear constraints
    )pbdoc");

    mom.def("poloni", &MultiObjective::poloni, R"pbdoc(
        Computes the value of the Poloni multi-objective benchmark function.
        SCORES = multiobjective.poloni(X) computes the value of the Poloni function
        at point X. `multiobjective.poloni` accepts a matrix of size M-by-2 and returns
        a matrix SCORES of size M-by-2.
        Properties:
        - Recommended domain: [-pi, pi]^2
        - Pareto front: Non-convex and disconnected
    )pbdoc");

    mom.def("tanaka", &MultiObjective::tanaka, py::arg("x"), py::arg("return_constraints") = false, R"pbdoc(
        Computes the value of the Tanaka multi-objective benchmark function.
        SCORES = multiobjective.tanaka(X) computes the value of the Tanaka function
        at point X. `multiobjective.tanaka` accepts a matrix of size M-by-2 and returns
        a matrix SCORES of size M-by-2.
        If return_constraints is True, returns an M-by-4 matrix where the last two columns
        contain the constraint violations (values > 0 are violations).
        Properties:
        - Number of dimensions: 2
        - Recommended domain: [0, Pi]^2
        - Constraints: 2 nonlinear constraints (one "ripple" constraint)
        - Pareto front: Disconnected
    )pbdoc");

    mom.def("viennet1", MultiObjective::viennet1, R"pbdoc(
        Computes the value of the Viennet 1 multi-objective benchmark function.
        SCORES = multiobjective.viennet1(X) computes the value of the Viennet 1 function
        at point X. `multiobjective.viennet1` accepts a matrix of size M-by-2 and returns
        a matrix SCORES of size M-by-3.
        Properties:
        - Recommended domain: [-2, 2]^2
        - Pareto front: Disconnected
    )pbdoc");

    mom.def("viennet2", MultiObjective::viennet2, R"pbdoc(
        Computes the value of the Viennet 2 multi-objective benchmark function.
        SCORES = multiobjective.viennet2(X) computes the value of the Viennet 2 function
        at point X. `multiobjective.viennet2` accepts a matrix of size M-by-2 and returns
        a matrix SCORES of size M-by-3.
        Properties:
        - Recommended domain: [-4, 4]^2
        - Pareto front: Curved
    )pbdoc");

    mom.def("viennet3", MultiObjective::viennet3, R"pbdoc(
        Computes the value of the Viennet 3 multi-objective benchmark function.
        SCORES = multiobjective.viennet3(X) computes the value of the Viennet 3 function
        at point X. `multiobjective.viennet3` accepts a matrix of size M-by-2 and returns
        a matrix SCORES of size M-by-3.
        Properties:
        - Recommended domain: [-3, 3]^2
        - Pareto front: Convoluted
    )pbdoc");

    mom.def("zdt1", MultiObjective::zdt1, R"pbdoc(
        Computes the value of the ZDT1 multi-objective benchmark function.
        SCORES = multiobjective.zdt1(X) computes the value of the ZDT1 function
        at point X. `multiobjective.zdt1` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-2 in which each row contains the function value
        for the corresponding row of X and each column corresponds to an objective.
        Properties:
        - Global Pareto front: f_2 = 1 - \sqrt{f_1}
        - Location of global Pareto front: x_1 ∈ [0, 1], x_i = 0 for i = 2, ..., n
        - Number of dimensions: n (usually 30)
        - Recommended domain: [0, 1]^n
        - Number of local fronts: 0
        - Number of global fronts: 1
        - Convexity: convex (Pareto front)
        - Modality: unimodal
        - Separability: non-separable
        - Differentiable: Yes
        For more information, please visit:
        benchmarkfcns.info/doc/zdt1fcn
    )pbdoc");

    mom.def("zdt2", MultiObjective::zdt2, R"pbdoc(
        Computes the value of the ZDT2 multi-objective benchmark function.
        SCORES = multiobjective.zdt2(X) computes the value of the ZDT2 function
        at point X. `multiobjective.zdt2` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-2.
        Properties:
        - Global Pareto front: f_2 = 1 - f_1^2
        - Location of global Pareto front: x_1 ∈ [0, 1], x_i = 0 for i = 2, ..., n
        - Number of dimensions: n (usually 30)
        - Recommended domain: [0, 1]^n
        - Convexity: non-convex (Pareto front)
        - Modality: unimodal
        For more information, please visit:
        benchmarkfcns.info/doc/zdt2fcn
    )pbdoc");

    mom.def("zdt3", MultiObjective::zdt3, R"pbdoc(
        Computes the value of the ZDT3 multi-objective benchmark function.
        SCORES = multiobjective.zdt3(X) computes the value of the ZDT3 function
        at point X. `multiobjective.zdt3` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-2.
        Properties:
        - Global Pareto front: f_2 = 1 - \sqrt{f_1} - f_1 \sin(10π f_1)
        - Location of global Pareto front: x_1 ∈ [0, 1], x_i = 0 for i = 2, ..., n
        - Number of dimensions: n (usually 30)
        - Recommended domain: [0, 1]^n
        - Convexity: disconnected (Pareto front)
        - Modality: multimodal
        For more information, please visit:
        benchmarkfcns.info/doc/zdt3fcn
    )pbdoc");

    mom.def("zdt4", MultiObjective::zdt4, R"pbdoc(
        Computes the value of the ZDT4 multi-objective benchmark function.
        SCORES = multiobjective.zdt4(X) computes the value of the ZDT4 function
        at point X. `multiobjective.zdt4` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-2.
        Properties:
        - Global Pareto front: f_2 = 1 - \sqrt{f_1}
        - Number of dimensions: n (usually 10)
        - Recommended domain: x_1 ∈ [0, 1], x_i ∈ [-5, 5] for i > 1
        - Modality: Highly Multimodal (has 21^{n-1} local Pareto fronts)
        For more information, please visit:
        benchmarkfcns.info/doc/zdt4fcn
    )pbdoc");

    mom.def("zdt6", MultiObjective::zdt6, R"pbdoc(
        Computes the value of the ZDT6 multi-objective benchmark function.
        SCORES = multiobjective.zdt6(X) computes the value of the ZDT6 function
        at point X. `multiobjective.zdt6` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-2.
        Properties:
        - Global Pareto front: f_2 = 1 - f_1^2
        - Number of dimensions: n (usually 10)
        - Recommended domain: [0, 1]^n
        - Mapping: Tests Non-uniform mapping/density to the Pareto front
        For more information, please visit:
        benchmarkfcns.info/doc/zdt6fcn
    )pbdoc");

    auto mfm = m.def_submodule("multifidelity", "Multi-fidelity functions");

    mfm.def("booth", MultiFidelity::booth, R"pbdoc(
        Computes the value of the Booth function at different fidelity levels.
        SCORES = multifidelity.booth(X) computes the value of the Booth function
        at point X. `multifidelity.booth` accepts a matrix of size M-by-2 and returns
        a vector SCORES of size M-by-2 in which each column contains the function value
        for each row of X and each column contains the function value for the
        corresponding fidelity level.
        Properties (High-fidelity):
        - Global minimum: 0
        - Location of global minimum: (1, 3)
        - Number of dimensions: 2
        - Recommended domain: [-10, 10]^2
        - Number of local minima: 0
        - Number of global minima: 1
        - Convexity: convex
        - Separability: non-separable
        - Modality: unimodal
        - Symmetry: non-symmetric
        - Differentiable: Yes
        For more information, please refer to:
        Dong, H., Song, B., Wang, P. et al. Multi-fidelity information
        fusion based on prediction of kriging. Struct Multidisc Optim
        51, 1267-1280 (2015) doi:10.1007/s00158-014-1213-9
    )pbdoc");

    mfm.def("forrester", MultiFidelity::forrester, R"pbdoc(
        Computes the value of the Forrester function at different fidelity levels.
        SCORES = multifidelity.forrester(X) computes the value of the Forrester function
        at point X. `multifidelity.forrester` accepts a matrix of size M-by-1 and returns
        a vector SCORES of size M-by-4 in which each column contains the function value
        for each row of X and each column contains the function value for the
        corresponding fidelity level.
        Properties (High-fidelity):
        - Global Minimum: \approx -6.021
        - Location of Global Minimum: \approx 0.757
        - Local Minimum: \approx 0.051 (a much shallower dip)
        - Recommended Domain: [0, 1]
        - Dimensions: 1
        - Convexity: Non-convex (it has a distinct "hump" and a deep valley)
        - Modality: Multimodal (one global and one local minimum)
        - Differentiable: Infinitely differentiable (it is smooth everywhere)
        For more information, please visit:
        arxiv.org/pdf/2204.07867
    )pbdoc");

    mfm.def("rosenbrock", MultiFidelity::rosenbrock, R"pbdoc(
        Computes the value of the multi-fidelity Rosenbrock benchmark function.
        SCORES = rosenbrock(X) computes the value of the Rosenbrock function
        at point X. `multifidelity.rosenbrock` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-2 in which each row contains the function value
        for the corresponding row of X and each column contains the function value
        for the corresponding fidelity level.
        Properties (High-fidelity):
        - Global minimum: 0
        - Location of global minimum: (1, 1, ..., 1)
        - Number of dimensions: n
        - Recommended domain: [-5, 5]^n
        - Number of local minima: many (the "banana-shaped" valley creates a long, narrow region of local minima)
        - Number of global minima: 1
        - Convexity: non-convex
        - Separability: non-separable
        - Modality: unimodal
        - Symmetry: non-symmetric
        - Differentiable: Yes
        For more information, please visit:
        arxiv.org/pdf/2204.07867
    )pbdoc");

    m.doc() = R"pbdoc(
        BenchmarkFcns - A collection of benchmark test functions for optimization problems.
        -----------------------

        .. currentmodule:: BenchmarkFcns

        .. autosummary::
           :toctree: _generate

        Benchmarkfcns is an effort to provide a public, free and high-performance
        implementation for well-known benchmark optimization functions. The project is
        open-sourced and is hosted on GitHub.
        Please forward any bug reports or comments to mazhar.ansari.ardeh [at] gmail.com.
        For a list of implemented functions and related documents, please visit
        the https://benchmarkfcns.info.

    )pbdoc";

    m.def("ackley", &ackley, R"pbdoc(
        Computes the value of Ackley benchmark function.
        SCORES = ackley(X) computes the value of the Ackley function at point
        X. `ackley` accepts a matrix of size M-by-N and returns a vector SCORES
        of size M-by-1 in which each row contains the function value for each row
        of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (0, 0, ..., 0)
        - Number of dimensions: N
        - Recommended domain: [-35, 35]^N
        - Number of local minima: many
        - Number of global minima: 1
        - Convexity: non-convex
        - Separability: non-separable
        - Modality: multimodal
        - Symmetry: radial symmetry
        For more information, please visit:
        benchmarkfcns.info/doc/ackleyfcn
    )pbdoc");

    m.def("ackleyn2", &ackleyn2, R"pbdoc(
        Computes the value of the Ackley N. 2 function.
        SCORES = ackley2(X) computes the value of the Ackley N. 2
        function at point X. `ackley2` accepts a matrix of size M-by-2 and
        returns a vector SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: -200
        - Location of global minimum: (0, 0, ..., 0)
        - Number of dimensions: 2
        - Recommended domain: [-32, 32]^2
        - Number of local minima: many
        - Number of global minima: 1
        - Convexity: non-convex
        - Separability: non-separable
        - Modality: unimodal
        - Symmetry: radial symmetry
        For more information, please visit:
        benchmarkfcns.info/doc/ackleyn2fcn
    )pbdoc");

    m.def("ackleyn3", &ackleyn3, R"pbdoc(
        Computes the value of the Ackley N. 3 function.
        SCORES = ackley3(X) computes the value of the Ackley N. 3
        function at point X. `ackley3` accepts a matrix of size M-by-2 and
        returns a vector SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: Approximately -219.1418
        - Location of global minimum: Approximately (0.68258, -0.36075)
        - Number of dimensions: 2
        - Recommended domain: x_1, x_2 ∈ [-32, 32]
        - Number of local minima: Numerous (the combination of exponential and
            trigonometric terms creates a very "bumpy" surface)
        - Number of global minima: 1
        - Convexity: Non-convex
        - Separability: Non-separable
        - Modality: Multimodal
        - Symmetry: Non-symmetric
        - Differentiable: Yes
        For more information, please visit:
        benchmarkfcns.info/doc/ackleyn3fcn
    )pbdoc");

    m.def("ackleyn4", &ackleyn4, R"pbdoc(
        Computes the value of Ackley N. 4 benchmark function.
        SCORES = ackley4(X) computes the value of the Ackley function at point
        X. `ackley4` accepts a matrix of size M-by-N and returns a vector SCORES
        of size M-by-1 in which each row contains the function value for each row
        of X.
        Properties:
        - Global minimum: -4.590101 (approximately)
        - Location of global minimum: (1.47925, -1.47925)
        - Number of dimensions: 2
        - Recommended domain: x_1, x_2 ∈ [-35, 35]
        - Number of local minima: Numerous (Highly oscillatory)
        - Number of global minima: 2 (typically symmetric across the origin)
        - Convexity: Non-convex
        - Separability: Non-separable
        - Modality: Multimodal
        - Symmetry: Symmetric (with respect to the origin/axes due to the absolute values)
        - Differentiable: No
        For more information, please visit:
        benchmarkfcns.info/doc/ackleyn4fcn
    )pbdoc");

    m.def("adjiman", &adjiman, R"pbdoc(
        Computes the value of the Adjiman benchmark function.
        SCORES = adjiman(X) computes the value of the Adjiman function at
        point X. `adjiman` accepts a matrix of size M-by-2 and returns a
        vector SCORES of size M-by-1 in which each row contains the function value
        for the corresponding row of X.
        Properties:
        - Global minimum: -2.02181 (approximately)
        - Location of global minimum: (2, 0.10578)
        - Number of dimensions: 2
        - Recommended domain: x_1 ∈ [-1, 2], x_2 ∈ [-1, 1]
        - Number of local minima: 0 (within the standard recommended domain, it is
            technically unimodal, though it has very flat regions)
        - Number of global minima: 1
        - Convexity: Non-convex
        - Separability: Non-separable (The x_1 and x_2 terms are multiplied in the cosine
            and linear terms)
        - Modality: Unimodal
        - Symmetry: Non-symmetric
        - Differentiable: Yes
        For more information, please visit:
        benchmarkfcns.info/doc/adjimanfcn
    )pbdoc");

    m.def("alpinen1", &alpinen1, R"pbdoc(
        Computes the value of the Alpine N. 1 function.
        SCORES = alpine1(X) computes the value of the Alpine N. 1
        function at point X. `alpine1` accepts a matrix of size M-by-N and
        returns a vector SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (0, 0, ..., 0)
        - Number of dimensions: n
        - Recommended domain: [-10, 10]^n
        - Number of local minima: many
        - Number of global minima: 1
        - Convexity: non-convex
        - Separability: separable
        - Modality: multimodal
        - Differentiable: Yes (except at points where sin(x_i) + 0.1 is 0, due to
            absolute value)
        For more information, please visit:
        benchmarkfcns.info/doc/alpinen1fcn
    )pbdoc");

    m.def("alpinen2", &alpinen2, R"pbdoc(
        Computes the value of the Alpine N. 2 function.
        SCORES = alpinen2(X) computes the value of the Alpine N. 2
        function at point X. `alpinen2` accepts a matrix of size M-by-N and
        returns a vector SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: Not typically defined as a single value across all n. Instead,
            the function is often used to find the Global Maximum.
        - Global Maximum Value: approx 2.808^n
        - Location of Global Maximum: approx (7.917, 7.917, ..., 7.917)
        - Number of dimensions: n (Scalable)
        - Recommended domain: x_i ∈ [0, 10] (The function is usually restricted to
            positive values due to the square root).
        - Number of local minima/maxima: Numerous (The sine waves create a grid of peaks).
        - Number of global minima/maxima: 1 (within the [0, 10] range).
        - Convexity: Non-convex
        - Separability: Separable (Despite being a product, it can be transformed into a
            sum of logs, making it technically separable in optimization terms).
        - Modality: Multimodal
        - Symmetry: Symmetric
        - Differentiable: Yes
        For more information, please visit:
        benchmarkfcns.info/doc/alpinen2fcn
    )pbdoc");

    m.def("amgm", &amgm, R"pbdoc(
        Computes the value of the AMGM benchmark function.
        SCORES = amgm(X) computes the value of the AMGM function at point X.
        `amgm` accepts a matrix of size M-by-N and returns a vector SCORES of
        size M-by-1 in which each row contains the function value for the
        corresponding row of X.
        Properties:
        - Global minimum: 1
        - Location of global minimum: (x, x, ..., x) for any x > 0
        - Number of dimensions: n
        - Recommended domain: (0, 10]^n (for non-negative inputs)
        - Number of local minima: 0 (unimodal)
        - Number of global minima: Infinite (along the line x_1 = x_2 = ... = x_n)
        - Convexity: non-convex
        - Separability: non-separable
        - Symmetry: symmetric
        - Modality: unimodal (on the positive domain)
        - Differentiable: Yes
    )pbdoc");

    m.def("attractivesector", &attractivesector, R"pbdoc(
        Computes the value of the Attractive Sector benchmark function.
        SCORES = attractivesector(X) computes the value of the Attractive Sector function at point X.
        `attractivesector` accepts a matrix of size M-by-N and returns a vector SCORES of
        size M-by-1 in which each row contains the function value for the
        corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (0, 0, ..., 0)
        - Number of dimensions: n
        - Recommended domain: [-5, 5]^n
        - Modality: unimodal
        - Characteristic: non-symmetric
    )pbdoc");

    m.def("bartelsconn", &bartelsconn, R"pbdoc(
        Computes the value of the Bartels Conn benchmark function.
        SCORES = bartelsconn(X) computes the value of the Bartels Conn
        function at point X. bartelsconn accepts a matrix of size M-by-2 and
        returns a vector SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (0, 0)
        - Number of dimensions: 2
        - Recommended domain: [-500, 500]^2
        - Number of local minima: many
        - Number of global minima: 1
        - Convexity: non-convex
        - Separability: non-separable
        - Modality: multimodal
        - Symmetry: symmetric
        - Differentiable: No
        For more information, please visit:
        benchmarkfcns.info/doc/bartelsconnfcn
    )pbdoc");

    m.def("beale", &beale, R"pbdoc(
        Computes the value of the Beale benchmark function.
        SCORES = beale(X) computes the value of the Beale function at
        point X. `beale` accepts a matrix of size M-by-2 and returns a
        vector SCORES of size M-by-1 in which each row contains the function value
        for the corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (3, 0.5)
        - Number of dimensions: 2
        - Recommended domain: [-4.5, 4.5]^2
        - Number of local minima: One global minimum in the standard domain, but it
            features several very flat regions that act like "pseudo-local minima" where
            gradients become nearly zero.
        - Number of global minima: 1
        - Convexity: Non-convex
        - Separability: Non-separable. The x and y variables are heavily multiplied and
            nested within the terms.
        - Modality: Unimodal (within its standard range), but deceptively difficult due
            to its geometry.
        - Symmetry: Non-symmetric
        - Differentiable: Yes
        For more information, please visit:
        benchmarkfcns.info/doc/bealefcn
    )pbdoc");

    m.def("bentcigar", &bentcigar, R"pbdoc(
        Computes the value of the Bent Cigar benchmark function.
        SCORES = bentcigar(X) computes the value of the Bent Cigar function at point X.
        `bentcigar` accepts a matrix of size M-by-N and returns a vetor SCORES of
        size M-by-1 in which each row contains the function value for the
        corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (0, 0, ..., 0)
        - Number of dimensions: n
        - Recommended domain: [-100, 100]^n
        - Modality: unimodal
        - Characteristic: Extreme ill-conditioning (10^6 scaling for all dimensions except the first).
    )pbdoc");

    m.def("biggsexp02", &biggsexp02, R"pbdoc(
        Computes the value of the Biggs EXP N. 02 benchmark function.
        SCORES = biggsexp02(X) computes the value of the Biggs EXP N. 02
        function at point X. `biggsexp02` accepts a matrix of size M-by-2 and
        returns a vector SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (1, 10)
        - Number of dimensions: 2
        - Recommended domain: [0, 20]^2
        - Number of local minima: 0
        - Number of global minima: 1
        - Convexity: non-convex
        - Separability: non-separable
        - Modality: unimodal
        - Symmetry: non-symmetric
    )pbdoc");

    m.def("biggsexp03", &biggsexp03, R"pbdoc(
        Computes the value of the Biggs EXP N. 03 benchmark function.
        SCORES = biggsexp03(X) computes the value of the Biggs EXP N. 03
        function at point X. `biggsexp03` accepts a matrix of size M-by-3 and
        returns a vector SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (1, 10, 1)
        - Number of dimensions: 3
        - Recommended domain: [0, 20]^3
        - Number of local minima: 0
        - Number of global minima: 1
        - Convexity: non-convex
        - Separability: non-separable
        - Modality: unimodal in the standard domain, but can be multimodal in larger
        domains
        - Symmetry: non-symmetric
        - Differentiable: yes
    )pbdoc");

    m.def("biggsexp04", &biggsexp04, R"pbdoc(
        Computes the value of the Biggs EXP N. 04 benchmark function.
        SCORES = biggsexp04(X) computes the value of the Biggs EXP N. 04
        function at point X. `biggsexp04` accepts a matrix of size M-by-4 and
        returns a vector SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (1, 10, 1, 5)
        - Number of dimensions: 4
        - Recommended domain: [0, 20]^4
        - Number of local minima: 0
        - Number of global minima: 1
        - Convexity: non-convex
        - Separability: non-separable
        - Modality: unimodal
        - Symmetry: non-symmetric
        - Differentiable: yes
        For more information, please visit:
        benchmarkfcns.info/doc/biggsexp04fcn
    )pbdoc");

    m.def("biggsexp05", &biggsexp05, R"pbdoc(
        Computes the value of the Biggs EXP N. 05 benchmark function.
        SCORES = biggsexp05(X) computes the value of the Biggs EXP N. 05
        function at point X. `biggsexp05` accepts a matrix of size M-by-5 and
        returns a vector SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (1, 10, 1, 5, 4)
        - Number of dimensions: 5
        - Recommended domain: [0, 20]^5
        - Number of local minima: 0
        - Number of global minima: 1
        - Convexity: non-convex
        - Separability: non-separable
        - Modality: unimodal
        - Symmetry: non-symmetric
        - Differentiable: yes
        For more information, please visit:
        benchmarkfcns.info/doc/biggsexp05fcn
    )pbdoc");

    m.def("biggsexp06", &biggsexp06, R"pbdoc(
        Computes the value of the Biggs EXP N. 06 benchmark function.
        SCORES = biggsexp06(X) computes the value of the Biggs EXP N. 06
        function at point X. `biggsexp06` accepts a matrix of size M-by-6 and
        returns a vector SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (1, 10, 1, 5, 4, 3)
        - Number of dimensions: 6
        - Recommended domain: [0, 20]^6
        - Number of local minima: 0
        - Number of global minima: 1
        - Convexity: non-convex
        - Separability: non-separable
        - Modality: unimodal
        - Symmetry: non-symmetric
        - Differentiable: yes
        For more information, please visit:
        benchmarkfcns.info/doc/biggsexp06fcn
    )pbdoc");

    m.def("bird", &bird, R"pbdoc(
        Computes the value of the Bird function.
        SCORES = bird(X) computes the value of the Bird
        function at point X. `bird` accepts a matrix of size M-by-2 and
        returns a vector SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: -106.7645
        - Location of global minimum: approximately (4.70104, 3.15204),(-1.58214, -3.13024)
        - Number of dimensions: 2
        - Recommended domain: [-2π, 2π]^2
        - Number of local minima: several local minima, but only two global minima
        - Number of global minima: 2
        - Convexity: non-convex
        - Separability: non-separable
        - Modality: multimodal
        - Symmetry: non-symmetric
        - Differentiable: Yes
        For more information, please visit:
        benchmarkfcns.info/doc/birdfcn
    )pbdoc");

    m.def("bohachevskyn1", &bohachevskyn1, R"pbdoc(
        Computes the value of Bohachevsky N. 1 benchmark function.
        SCORES = bohachevsky1(X) computes the value of the Bohachevsky N. 1
        function at point X. `bohachevsky1` accepts a matrix of size M-by-N and
        returns a vector SCORES of size M-by-1 in which each row contains the
        function value for each row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (0, 0)
        - Number of dimensions: 2
        - Recommended domain: [-15, 15]^2
        - Number of local minima: many
        - Number of global minima: 1
        - Convexity: non-convex
        - Separability: non-separable
        - Modality: multimodal
        - Differentiable: Yes
        For more information, please visit:
        benchmarkfcns.info/doc/bohachevskyn1fcn
    )pbdoc");

    m.def("bohachevskyn2", &bohachevskyn2, R"pbdoc(
        Computes the value of Bohachevsky N. 2 benchmark function.
        SCORES = bohachevsky2(X) computes the value of the Bohachevsky N. 2
        function at point X. `bohachevsky2` accepts a matrix of size M-by-N and
        returns a vector SCORES of size M-by-1 in which each row contains the
        function value for each row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (0, 0)
        - Number of dimensions: 2
        - Recommended domain: [-100, 100]^2
        - Number of local minima: many
        - Number of global minima: 1
        - Convexity: non-convex
        - Separability: non-separable
        - Modality: multimodal
        - Symmetry: non-symmetric
        - Differentiable: Yes
        For more information, please visit:
        benchmarkfcns.info/doc/bohachevskyn2fcn
    )pbdoc");

    m.def("bohachevskyn3", &bohachevskyn3, R"pbdoc(
        Computes the value of Bohachevsky N. 3 benchmark function.
        SCORES = bohachevsky3(X) computes the value of the Bohachevsky N. 3
        function at point X. `bohachevsky3` accepts a matrix of size M-by-N and
        returns a vector SCORES of size M-by-1 in which each row contains the
        function value for each row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (0, 0)
        - Number of dimensions: 2
        - Recommended domain: [-100, 100]^2
        - Number of local minima: many
        - Number of global minima: 1
        - Convexity: non-convex
        - Separability: non-separable
        - Modality: multimodal
        - Symmetry: non-symmetric
        - Differentiable: Yes
        For more information, please visit:
        benchmarkfcns.info/doc/bohachevskyn3fcn
    )pbdoc");

    m.def("booth", &booth, R"pbdoc(
        Computes the value of the Booth benchmark function.
        SCORES = booth(X) computes the value of the Booth's function at
        point X. `booth` accepts a matrix of size M-by-2 and returns a
        vector SCORES of size M-by-1 in which each row contains the function value
        for the corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (1, 3)
        - Number of dimensions: 2
        - Recommended domain: [-10, 10]^2
        - Number of local minima: 0
        - Number of global minima: 1
        - Convexity: convex
        - Separability: non-separable
        - Modality: unimodal
        - Symmetry: non-symmetric
        - Differentiable: Yes
        For more information, please visit:
        benchmarkfcns.info/doc/boothfcn
    )pbdoc");

    m.def("braninn1", &braninn1, R"pbdoc(
        Computes the value of the Branin N. 1 benchmark function.
        SCORES = braninn01(X) computes the value of the Branin N. 1
        function at point X. `braninn01` accepts a matrix of size M-by-2 and
        returns a vector SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: 0.397887
        - Location of global minimum: (-π, 12.275), (π, 2.275), (9.42478, 2.475)
        - Number of dimensions: 2
        - Recommended domain: [-5, 15] for x1, [0, 15] for x2
        - Number of local minima: no local minima other than the three global ones
        - Number of global minima: 3
        - Convexity: non-convex
        - Separability: non-separable
        - Modality: multimodal
        - Symmetry: Non-symmetric
        - Differentiable: Yes
        For more information, please visit:
        benchmarkfcns.info/doc/braninn1fcn
    )pbdoc");

    m.def("braninn2", &braninn2, R"pbdoc(
        Computes the value of the Branin N. 2 benchmark function.
        SCORES = braninn02(X) computes the value of the Branin N. 2
        function at point X. `braninn02` accepts a matrix of size M-by-2 and
        returns a vector SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: 5.55903732
        - Location of global minimum: [-3.2, 12.53]
        - Number of dimensions: 2
        - Recommended domain: [-5, 15]^2
        - Number of local minima: Dependent on the specific bounds, but typically includes
            several local traps.
        - Number of global minima: 3
        - Convexity: non-convex
        - Separability: non-separable
        - Modality: multimodal
        - Symmetry: Non-symmetric
        - Differentiable: Yes
        For more information, please visit:
        benchmarkfcns.info/doc/braninn2fcn
    )pbdoc");

    m.def("brent", &brent, R"pbdoc(
        Computes the value of the Brent function.
        SCORES = brent(X) computes the value of the Brent
        function at point X. `brent` accepts a matrix of size M-by-2 and
        returns a vector SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (-10, -10)
        - Number of dimensions: 2
        - Recommended domain: [-10, 10]^2 or [-20, 0]^2
        - Number of local minima: 1
        - Number of global minima: 1
        - Convexity: non-convex
        - Separability: non-separable
        - Modality: unimodal
        - Differentiable: Yes
        For more information, please visit:
        benchmarkfcns.info/doc/brentfcn
    )pbdoc");

    m.def("brown", &brown, R"pbdoc(
        Computes the value of the Brown benchmark function.
        SCORES = brown(X) computes the value of the Brown function at point X.
        `brown` accepts a matrix of size M-by-N and returns a vector SCORES of
        size M-by-1 in which each row contains the function value for the
        corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (0, 0, ..., 0)
        - Number of dimensions: n
        - Recommended domain: [-1, 4]^n
        - Number of local minima: 0 (unimodal)
        - Number of global minima: 1
        - Convexity: non-convex
        - Separability: non-separable
        - Modality: unimodal
        - Differentiable: Yes
        For more information, please visit:
        benchmarkfcns.info/doc/brownfcn
    )pbdoc");

    m.def("bukinn2", &bukinn2, R"pbdoc(
        Computes the value of the Bukin N. 2 benchmark function.
        SCORES = bukinn2(X) computes the value of the Bukin N. 2 function at
        point X. `bukinn2` accepts a matrix of size M-by-2 and returns a
        vector SCORES of size M-by-1 in which each row contains the function value
        for the corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (-10, 0)
        - Number of dimensions: 2
        - Recommended domain: x_1 \in [-15, -5], x_2 \in [-3, 3]
        - Number of local minima: 0 (unimodal)
        - Number of global minima: 1
        - Convexity: non-convex
        - Separability: non-separable
        - Modality: unimodal
        - Differentiable: Yes
    )pbdoc");

    m.def("bukinn4", &bukinn4, R"pbdoc(
        Computes the value of the Bukin N. 4 benchmark function.
        SCORES = bukinn4(X) computes the value of the Bukin N. 4 function at
        point X. `bukinn4` accepts a matrix of size M-by-2 and returns a
        vector SCORES of size M-by-1 in which each row contains the function value
        for the corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (-10, 0)
        - Number of dimensions: 2
        - Recommended domain: x_1 \in [-15, -5], x_2 \in [-3, 3]
        - Number of local minima: 0 (unimodal)
        - Number of global minima: 1
        - Convexity: convex
        - Separability: separable
        - Modality: unimodal
        - Differentiable: No
    )pbdoc");

    m.def("bukinn6", &bukinn6, R"pbdoc(
        Computes the value of the Bukin N. 6 benchmark function.
        SCORES = bukinn6(X) computes the value of the Bukin N. 6 function at
        point X. `bukinn6` accepts a matrix of size M-by-2 and returns a
        vector SCORES of size M-by-1 in which each row contains the function value
        for the corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (-10, 1)
        - Number of dimensions: 2
        - Recommended domain: x \in [-15, -5], y \in [-3, 3]
        - Number of local minima: many
        - Number of global minima: 1
        - Convexity: non-convex
        - Separability: non-separable
        - Modality: multimodal
        - Differentiable: No
        For more information, please visit:
        benchmarkfcns.info/doc/bukinn6fcn
    )pbdoc");

    m.def("carromtable", &carromtable, R"pbdoc(
        Computes the value of the Carromtable benchmark function.
        SCORES = carromtable(X) computes the value of the Carromtable
        function at point X. `carromtable` accepts a matrix of size M-by-2 and
        returns a vector SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: \approx -24.1568
        - Location of global minimum: (\pm 9.6461, \pm 9.6461)
        - Number of dimensions: 2
        - Recommended domain: [-10, 10]^2
        - Number of local minima: many
        - Number of global minima: 4
        - Convexity: non-convex
        - Separability: non-separable
        - Modality: multimodal
        - Symmetry: symmetric
        - Differentiable: No
        For more information, please visit:
        benchmarkfcns.info/doc/carromtablefcn
    )pbdoc");

    m.def("chichinadze", &chichinadze, R"pbdoc(
        Computes the value of the Chichinadze benchmark function.
        SCORES = chichinadze(X) computes the value of the Chichinadze
        function at point X. `chichinadze` accepts a matrix of size M-by-2 and
        returns a vector SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: -43.3159 (approximately)
        - Location of global minimum: (5.90133, 0.5)
        - Number of dimensions: 2
        - Recommended domain: [-30, 30]^2
        - Number of local minima: many
        - Number of global minima: 1
        - Convexity: non-convex
        - Separability: separable
        - Modality: multimodal
        - Symmetry: non-symmetric
        - Differentiable: Yes
    )pbdoc");

    m.def("cigar", &cigar, R"pbdoc(
        Computes the value of the Cigar benchmark function.
        SCORES = cigar(X) computes the value of the Cigar function at point X.
        `cigar` accepts a matrix of size M-by-N and returns a vector SCORES of
        size M-by-1 in which each row contains the function value for the
        corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (0, 0, ..., 0)
        - Number of dimensions: n
        - Recommended domain: [-100, 100]^n
        - Number of local minima: 0 (unimodal)
        - Number of global minima: 1
        - Convexity: convex
        - Separability: separable
        - Modality: unimodal
        - Differentiable: Yes
    )pbdoc");

    m.def("corana", &corana, R"pbdoc(
        Computes the value of the Corana benchmark function.
        SCORES = corana(X) computes the value of the Corana function at point X.
        `corana` accepts a matrix of size M-by-N and returns a vector SCORES of
        size M-by-1 in which each row contains the function value for the
        corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (0, 0, ..., 0)
        - Number of dimensions: n
        - Recommended domain: [-500, 500]^n
        - Number of local minima: massive
        - Number of global minima: 1
        - Convexity: non-convex
        - Separability: separable
        - Modality: multimodal
        - Differentiability: non-differentiable (staircase landscape)
    )pbdoc");

    m.def("cosinemixture", &cosinemixture, R"pbdoc(
        Computes the value of the Cosine Mixture benchmark function.
        SCORES = cosinemixture(X) computes the value of the Cosine Mixture
        function at point X. `cosinemixture` accepts a matrix of size M-by-N and
        returns a vector SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (0, 0, ..., 0)
        - Number of dimensions: n
        - Recommended domain: [-1, 1]^n
        - Number of local minima: many
        - Number of global minima: 1
        - Convexity: non-convex
        - Separability: separable
        - Modality: multimodal
        - Symmetry: symmetric
        - Differentiable: Yes
    )pbdoc");

    m.def("crossintray", &crossintray, R"pbdoc(
        Computes the value of the Cross-in-tray benchmark function.
        SCORES = crossintray(X) computes the value of the Cross-in-tray
        function at point X. `crossintray` accepts a matrix of size M-by-2
        and returns a vector SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: -2.062611870822
        - Location of global minimum: There are 4 global minima: $(\pm 1.34941, \pm 1.34941)$
        - Number of dimensions: 2
        - Recommended domain:[-10, 10]^2
        - Number of local minima: Numerous (A grid of smaller basins surrounds the main trays)
        - Number of global minima: 4
        - Convexity: Non-convex
        - Separability: Non-separable
        - Modality: Multimodal
        - Symmetry: Symmetric (Highly symmetric across both axes and the origin)
        - Differentiable: No
        For more information, please visit:
        benchmarkfcns.info/doc/crossintrayfcn
    )pbdoc");

    m.def("crownedcross", &crownedcross, R"pbdoc(
        Computes the value of the Crowned Cross benchmark function.
        SCORES = crownedcross(X) computes the value of the Crowned Cross
        function at point X. `crownedcross` accepts a matrix of size M-by-2 and
        returns a vector SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: 0.0001
        - Location of global minimum: (0, 0)
        - Number of dimensions: 2
        - Recommended domain: [-10, 10]^2
        - Number of local minima: many
        - Number of global minima: 1
        - Convexity: non-convex
        - Separability: non-separable
        - Modality: multimodal
        - Symmetry: symmetric
    )pbdoc");

    m.def("csendes", &csendes, R"pbdoc(
        Computes the value of the Csendes benchmark function.
        SCORES = csendes(X) computes the value of the Csendes function at point X.
        `csendes` accepts a matrix of size M-by-N and returns a vector SCORES of
        size M-by-1 in which each row contains the function value for the
        corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (0, 0, ..., 0)
        - Number of dimensions: n
        - Recommended domain: [-1, 1]^n
        - Number of local minima: many
        - Number of global minima: 1
        - Convexity: convex (for x!= 0)
        - Separability: separable
        - Modality: unimodal
        - Differentiability: No (Technically, the derivative at x=0 is undefined or zero
            in a way that causes numerical instability in most solvers)
        - Symmetry: symmetric
    )pbdoc");

    m.def("cubefcn", &cubefcn, R"pbdoc(
        Computes the value of the Cube benchmark function.
        SCORES = cube(X) computes the value of the Cube function at point X.
        `cube` accepts a matrix of size M-by-2 and returns a vector SCORES of
        size M-by-1 in which each row contains the function value for the
        corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (1, 1)
        - Number of dimensions: 2
        - Recommended domain: [-10, 10]^2
        - Number of local minima: 0 (unimodal)
        - Number of global minima: 1
        - Convexity: non-convex
        - Separability: non-separable
        - Modality: unimodal
        - Differentiable: Yes
    )pbdoc");

    m.def("debn1", &debn1, R"pbdoc(
        Computes the value of the Deb N. 1 benchmark function.
        SCORES = deb1(X) computes the value of the Deb N. 1 function at point X.
        `deb1` accepts a matrix of size M-by-N and returns a vector SCORES of
        size M-by-1 in which each row contains the function value for the
        corresponding row of X.
        Properties:
        - Global minimum: -1
        - Location of global minimum: x_i = 0.1 + 0.2k for k \in {0, 1, 2, 3, 4} (within [0, 1])
        - Number of dimensions: n
        - Recommended domain: [0, 1]^n
        - Number of local minima: many
        - Number of global minima: 5^n
        - Convexity: non-convex
        - Separability: separable
        - Modality: multimodal
        - Symmetry: symmetric
        - Differentiable: Yes
    )pbdoc");

    m.def("deckkersaarts", &deckkersaarts, R"pbdoc(
        Computes the value of the Deckkers-Aarts function.
        SCORES = deckkersaarts(X) computes the value of the Deckkers-Aarts
        function at point X. `deckkersaarts` accepts a matrix of size M-by-2 and
        returns a vector SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: -24771.09375
        - Location of global minimum: (0, 15), (0, -15)
        - Number of dimensions: 2
        - Recommended domain: [-20, 20]^2
        - Number of local minima: many
        - Number of global minima: 2
        - Convexity: non-convex
        - Separability: non-separable
        - Modality: multimodal
        - Differentiable: Yes
        For more information, please visit:
        benchmarkfcns.info/doc/deckkersaartsfcn
    )pbdoc");

    m.def("dejongn5", &dejongn5, R"pbdoc(
        Computes the value of the De Jong N. 5 benchmark function (Shekel's Foxholes).
        SCORES = dejongn5(X) computes the value of the De Jong N. 5 function at point X.
        `dejongn5` accepts a matrix of size M-by-2 and returns a vetor SCORES of
        size M-by-1 in which each row contains the function value for the
        corresponding row of X.
        Properties:
        - Global minimum: \approx 0.998004
        - Location of global minimum: (-32, -32)
        - Number of dimensions: 2
        - Recommended domain: [-65.536, 65.536]^2
        - Modality: multimodal (25 local minima/foxholes)
    )pbdoc");

    m.def("discus", &discus, R"pbdoc(
        Computes the value of the Discus benchmark function.
        SCORES = discus(X) computes the value of the Discus function at point X.
        `discus` accepts a matrix of size M-by-N and returns a vetor SCORES of
        size M-by-1 in which each row contains the function value for the
        corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (0, 0, ..., 0)
        - Number of dimensions: n
        - Recommended domain: [-100, 100]^n
        - Modality: unimodal
        - Characteristic: High conditioning (one sensitive direction).
    )pbdoc");

    m.def("dixonprice", &dixonprice, R"pbdoc(
        Computes the value of the Dixon-Price benchmark function.
        SCORES = dixonprice(X) computes the value of the Dixon-Price function at
        point X. `dixonprice` accepts a matrix of size M-by-N and returns a
        vector SCORES of size M-by-1 in which each row contains the function value
        for the corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: x_i = 2^( - (2^i - 2) / 2^i )
        - Number of dimensions: n
        - Recommended domain: [-10, 10]^n
        - Number of local minima: 0 (unimodal)
        - Number of global minima: 1
        - Convexity: non-convex
        - Separability: non-separable
        - Modality: unimodal
    )pbdoc");

    m.def("dropwave", &dropwave, R"pbdoc(
        Computes the value of the Drop-Wave benchmark function.
        SCORES = dropwave(X) computes the value of the Drop-Wave function at
        point X. `dropwave` accepts a matrix of size M-by-2 and returns a
        vector SCORES of size M-by-1 in which each row contains the function value
        for the corresponding row of X.
        Properties:
        - Global minimum: -1
        - Location of global minimum: (0, 0)
        - Number of dimensions: 2
        - Recommended domain: [-5.12, 5.12]^2
        - Number of local minima: many
        - Number of global minima: 1
        - Convexity: non-convex
        - Separability: non-separable
        - Modality: multimodal
        - Symmetry: radial symmetry
        - Differentiable: Yes
        For more information, please visit:
        benchmarkfcns.info/doc/dropwavefcn
    )pbdoc");

    m.def("easom", &easom, R"pbdoc(
        Computes the value of the Easom benchmark function.
        SCORES = easom(X) computes the value of the Easom function at point X.
        `easom` accepts a matrix of size M-by-2 and returns a vector SCORES of
        size M-by-1 in which each row contains the function value for the
        corresponding row of X.
        Properties:
        - Global minimum: -1
        - Location of global minimum: (π, π)
        - Number of dimensions: 2
        - Recommended domain: [-100, 100]^2
        - Number of local minima: many
        - Number of global minima: 1
        - Convexity: non-convex
        - Separability: non-separable
        - Modality: unimodal (but deceptively flat)
        - Differentiable: Yes
        For more information, please visit:
        benchmarkfcns.info/doc/easomfcn
    )pbdoc");

    m.def("eggcrate", &eggcrate, R"pbdoc(
        Computes the value of the Egg Crate function.
        SCORES = eggcrate(X) computes the value of the Egg Crate
        function at point X. `eggcrate` accepts a matrix of size M-by-2 and
        returns a vector SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (0, 0)
        - Number of dimensions: 2
        - Recommended domain: [-5, 5]^2
        - Number of local minima: many
        - Number of global minima: 1
        - Convexity: non-convex
        - Separability: separable
        - Modality: multimodal
        - Symmetry: symmetric
        - Differentiable: Yes
        For more information, please visit:
        benchmarkfcns.info/doc/eggcratefcn
    )pbdoc");

    m.def("eggholder", &eggholder, R"pbdoc(
        Computes the value of the Eggholder benchmark function.
        SCORES = eggholder(X) computes the value of the Eggholder
        function at point X. `eggholder` accepts a matrix of size M-by-2
        and returns a vector SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: -959.6407
        - Location of global minimum: (512, 404.2319)
        - Number of dimensions: 2
        - Recommended domain: [-512, 512]^2
        - Number of local minima: many
        - Number of global minima: 1
        - Convexity: non-convex
        - Separability: non-separable
        - Modality: multimodal
        - Differentiable: Yes
        For more information, please visit:
        benchmarkfcns.info/doc/eggholderfcn
    )pbdoc");

    m.def("elattar", &elattar, R"pbdoc(
        Computes the value of the El-Attar function.
        SCORES = elattar(X) computes the value of the El-Attar
        function at point X. `elattar` accepts a matrix of size M-by-2 and
        returns a vector SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: 0 (Theoretically, for many variations, but check implementation)
        - Location of global minimum: Depends on the specific roots of the terms.
        - Number of dimensions: 2
        - Recommended domain: [-100, 100]^2
        - Number of local minima: many
        - Number of global minima: 1
        - Convexity: non-convex
        - Separability: non-separable
        - Modality: multimodal
        - Differentiable: Yes
        For more information, please visit:
        benchmarkfcns.info/doc/elattarfcn
    )pbdoc");

    m.def("elliptic", &elliptic, R"pbdoc(
        Computes the value of the Elliptic benchmark function.
        SCORES = elliptic(X) computes the value of the Elliptic function at point X.
        `elliptic` accepts a matrix of size M-by-N and returns a vetor SCORES of
        size M-by-1 in which each row contains the function value for the
        corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (0, 0, ..., 0)
        - Number of dimensions: n
        - Recommended domain: [-100, 100]^n
        - Modality: unimodal
        - Characteristic: High conditioning (10^6).
    )pbdoc");

    m.def("exponential", &exponential, R"pbdoc(
        Computes the value of the Exponential function.
        SCORES = exponential(X) computes the value of the Exponential
        function at point X. `exponential` accepts a matrix of size M-by-N and
        returns a vector SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: -1
        - Location of global minimum: (0, 0, ..., 0)
        - Number of dimensions: n
        - Recommended domain: [-1, 1]^n
        - Number of local minima: 0
        - Number of global minima: 1
        - Convexity: convex
        - Separability: non-separable (exponential of a sum)
        - Modality: unimodal
        - Symmetry: symmetric
        - Differentiable: Yes
        For more information, please visit:
        benchmarkfcns.info/doc/exponentialfcn
    )pbdoc");

    m.def("f8f2", &f8f2, R"pbdoc(
        Computes the value of the Expanded Griewank plus Rosenbrock (F8F2) benchmark function.
        SCORES = f8f2(X) computes the value of the F8F2 function at point X.
        `f8f2` accepts a matrix of size M-by-N and returns a vetor SCORES of
        size M-by-1 in which each row contains the function value for the
        corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (1, 1, ..., 1)
        - Number of dimensions: n
        - Recommended domain: [-100, 100]^n
        - Modality: multimodal
        - Characteristic: Highly non-separable.
    )pbdoc");

    m.def("forrester", &forrester, R"pbdoc(
        Computes the value of the Forrester benchmark function.
        SCORES = forrester(X) computes the value of the Forrester function at
        point X. `forrester` accepts a matrix of size M-by-N and returns a vector
        SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global Minimum: \approx -6.021
        - Location of Global Minimum: \approx 0.757
        - Local Minimum: \approx 0.051 (a much shallower dip)
        - Recommended Domain: [0, 1]
        - Dimensions: 1
        - Convexity: Non-convex (it has a distinct "hump" and a deep valley)
        - Modality: Multimodal (one global and one local minimum)
        - Differentiability: Infinitely differentiable (it is smooth everywhere)
        For more information, please visit:
        benchmarkfcns.info/doc/forresterfcn
    )pbdoc");

    m.def("foxholes", &foxholes, R"pbdoc(
        Computes the value of the Foxholes benchmark function.
        SCORES = foxholes(X) computes the value of the Foxholes function at
        point X. `foxholes` accepts a matrix of size M-by-2 and returns a vector
        SCORES of size M-by-1 in which each row contains the function value for
        each row of X.
        Properties:
        - Global minimum: \approx 0.998
        - Location of global minimum: (-32, -32)
        - Number of dimensions: 2
        - Recommended domain: [-65.536, 65.536]^2
    )pbdoc");

    m.def("friedman1", &friedman1, py::arg("x"), py::arg("rnd") = false, R"pbdoc(
        Computes the value of the Friedman N. 1 benchmark function.

        Properties:
        - Global minimum: In the domain [0, 1], the minimum is approximately 0.3954
        - Location of global minimum: x_1 * x_2 \approx 0, x_3 = 0.5, x_4 = 0, and x_5 = 0.
        - Number of dimensions: 10 (though only 5 are active)
        - Recommended domain: [0, 1]^10
        - Number of local minima: Several, due to the sin term
        - Number of global minima: At least 1 within the [0, 1] unit hypercube
        - Convexity: Non-convex
        - Separability: Non-separable
        - Modality: Multimodal
        - Symmetry: Symmetric for x_1 and x_2
        - Differentiable: Yes

        Inputs:
        - x: A matrix of size M-by-10.
        - rnd: An optional boolean flag that, if true, adds a small random noise to the
               function value to create a noisy version of the function. Default is false.

        For more information, please visit:
        benchmarkfcns.info/doc/friedman1fcn
    )pbdoc");

    m.def("friedman2", &friedman2, py::arg("x"), py::arg("sigma") = 0, R"pbdoc(
        Computes the value of the Friedman N. 2 benchmark function.

        Properties:
        - Global minimum: 0
        - Location of global minimum: (x_1, x_2, x_3, x_4) such that x_1 = 0 and (x_2 x_3) = 1/(x_2 * x_4)
        - Number of dimensions: 4
        - Recommended domain: x_1 ∈ [0, 100], x_2 ∈ [40π, 560π], x_3 ∈ [0, 1], x_4 ∈ [1, 11]
        - Number of local minima: None (it is technically a "valley" function)
        - Number of global minima: Infinite points
        - Convexity: Non-convex
        - Separability: Non-separable
        - Modality: Unimodal
        - Symmetry: Non-symmetric
        - Differentiable: Yes

        Inputs:
        - x: A matrix of size M-by-4.
        - sigma: An optional non-negative scalar that adds Gaussian noise with mean of
                 zero and standard deviation of sigma to the function value to create a
                 noisy version of the function. Default is 0 (no noise).

        For more information, please visit:
        benchmarkfcns.info/doc/friedman2fcn
    )pbdoc");

     m.def("friedman3", &friedman3, py::arg("x"), py::arg("sigma") = 0, R"pbdoc(
        Computes the value of the Friedman N. 3 benchmark function.

        Properties:
        - Global minimum: -π/2
        - Location of global minimum: (x_1, x_2, x_3, x_4) such that x_1 is very small
            and (x_2 * x_3) = 1/(x_2 * x_4)
        - Number of dimensions: 4
        - Recommended domain: x_1 ∈ [0, 100], x_2 ∈ [40π, 560π], x_3 ∈ [0, 1],
            x_4 ∈ [1, 11]
        - Number of local minima: None (it is technically a "valley" function)
        - Number of global minima: Infinite points
        - Convexity: Non-convex
        - Separability: Non-separable
        - Modality: Unimodal
        - Symmetry: Non-symmetric
        - Differentiable: Yes, except at x_1 = 0

        Inputs:
        - x: A matrix of size M-by-4.
        - sigma: An optional non-negative scalar that adds Gaussian noise with mean of
                 zero and standard deviation of sigma to the function value to create a
                 noisy version of the function. Default is 0 (no noise).

        For more information, please visit:
        benchmarkfcns.info/doc/friedman3fcn
    )pbdoc");

    m.def("gallagher101", &gallagher101, R"pbdoc(
        Computes the value of the Gallagher's Gaussian 101-me Peaks benchmark function.
        SCORES = gallagher101(X) computes the value of the Gallagher's 101-me Peaks
        function at point X. `gallagher101` accepts a matrix of size M-by-N and
        returns a vetor SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: randomized (seeded)
        - Number of dimensions: n
        - Recommended domain: [-5, 5]^n
        - Modality: highly multimodal (101 Gaussian peaks)
    )pbdoc");

    m.def("gear", &gear, R"pbdoc(
        Computes the value of the Gear benchmark function.
        SCORES = gear(X) computes the value of the Gear function at point X.
        `gear` accepts a matrix of size M-by-4 and returns a vector SCORES of
        size M-by-1 in which each row contains the function value for the
        corresponding row of X.
        Properties:
        - Global minimum: \approx 2.700857 * 10^-12
        - Location of global minimum: (16, 19, 43, 49)
        - Number of dimensions: 4
        - Recommended domain: [12, 60]^4
        - Number of local minima: many
        - Number of global minima: at least two
        - Convexity: non-convex
        - Separability: non-separable
        - Modality: multimodal
        - Symmetry: partially symmetric.
        - Differentiable: no
        For more information, please visit:
        benchmarkfcns.info/doc/gearfcn
    )pbdoc");

    m.def("giunta", &giunta, R"pbdoc(
        Computes the value of the Giunta function.
        SCORES = giunta(X) computes the value of the Giunta
        function at point X. `giunta` accepts a matrix of size M-by-N and
        returns a vector SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global Minimum: \approx 0.06447 (for n=2)
        - Location of Global Minimum: \approx 0.46732
        - Number of Dimensions: Usually 2, but can be scaled to n dimensions
        - Recommended Domain: [-1, 1]^n
        - Number of Local Minima: Numerous (it oscillates rapidly)
        - Number of Global Minima: 1 (in the standard domain)
        - Convexity: Non-convex
        - Separability: Separable.
        - Modality: Multimodal
        - Symmetry: Symmetric (if all x_i ranges are the same)
        - Differentiable: Yes. It is smooth and continuous, unlike the Gear function.
        For more information, please visit:
        benchmarkfcns.info/doc/giuntafcn
    )pbdoc");

    m.def("goldsteinprice", &goldsteinprice, R"pbdoc(
        Computes the value of Goldstein-Price benchmark function.
        SCORES = goldsteinprice(X) computes the value of the Goldstein-Price
        function at point X. `goldsteinprice` accepts a matrix of size M-by-2
        and returns a vector SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: 3
        - Location of global minimum: (0, -1)
        - Number of dimensions: 2
        - Recommended domain: [-2, 2]^2
        - Number of local minima: 4
        - Number of global minima: 1
        - Convexity: Non-convex
        - Separability: Non-separable
        - Modality: Multimodal
        - Symmetry: Non-symmetric
        - Differentiable: Yes
        For more information, please visit:
        benchmarkfcns.info/doc/goldsteinpricefcn
    )pbdoc");

    m.def("gramacylee", &gramacylee, R"pbdoc(
        Computes the value of the Gramacy & Lee benchmark function.
        SCORES = gramacylee(X) computes the value of the Gramacy & Lee
        function at point X. `gramacylee` accepts a matrix of size M-by-2 and
        returns a vector SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: -0.869 (approximately)
        - Location of global minimum: x ≈ 0.5485
        - Number of dimensions: 1 (x)
        - Recommended domain: x ∈ [0.5, 2.5]
        - Number of local minima: Numerous (Highly oscillatory)
        - Number of global minima: 1
        - Convexity: Non-convex
        - Separability: N/A (1D function)
        - Modality: Highly Multimodal
        - Symmetry: Non-symmetric
        - Differentiable: Yes
        For more information, please visit:
        benchmarkfcns.info/doc/gramacyleefcn
    )pbdoc");

    m.def("griewank", &griewank, R"pbdoc(
        Computes the value of the Griewank benchmark function.
        SCORES = griewank(X) computes the value of the Griewank's
        function at point X. `griewank` accepts a matrix of size M-by-N
        and returns a vector SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (0, 0, ..., 0)
        - Number of dimensions: n (Scalable)
        - Recommended domain: x_i ∈ [-600, 600]
        - Number of local minima: Thousands (The number increases with the search area)
        - Number of global minima: 1
        - Convexity: Non-convex
        - Separability: Non-separable
        - Modality: Highly Multimodal
        - Symmetry: Symmetric
        - Differentiable: Yes
        For more information, please visit:
        benchmarkfcns.info/doc/griewankfcn
    )pbdoc");

    m.def("happycat", &happycat, py::arg("x"), py::arg("alpha") = 0.5, R"pbdoc(
        Computes the value of the Happy Cat benchmark function.
        SCORES = happycat(X) computes the value of the Happy Cat function at
        point X. `happycat` accepts a matrix of size M-by-N and returns a vector
        SCORES of size M-by-1 in which each row contains the function value for
        the corresponding row of X.
        SCORES = happycat(X, ALPHA) specifies power of the sphere component of
        the function.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (-1, -1, ..., -1)
        - Number of dimensions: n
        - Recommended domain: x_i ∈ [-2, 2]
        - Number of local minima: Numerous
        - Number of global minima: 1
        - Convexity: Non-convex
        - Separability: Non-separable (The variables are coupled via the Euclidean norm
            and the sum)
        - Modality: Multimodal
        - Symmetry: Non-symmetric (The minimum is at -1, not 0)
        - Differentiable: Yes
        For more information, please visit:
        benchmarkfcns.info/doc/happycatfcn
    )pbdoc");

    m.def("hartmann3", &hartmann3, R"pbdoc(
        Computes the value of the Hartmann N. 3 benchmark function.
        SCORES = hartmann3(X) computes the value of the Hartmann N. 3
        function at point X. `hartmann3` accepts a matrix of size M-by-3 and
        returns a vector SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: \approx -3.86278
        - Location of global minimum: \approx (0.114614, 0.555649, 0.852547)
        - Number of dimensions: 3
        - Recommended domain: [0, 1]^3
        - Number of local minima: 4
        - Number of global minima: 1
        - Convexity: Non-convex
        - Separability: Non-separable
        - Modality: Multimodal
        - Symmetry: Non-symmetric
        - Differentiable: Yes
        For more information, please visit:
        benchmarkfcns.info/doc/hartmann3fcn
    )pbdoc");

    m.def("hartmann6", &hartmann6, R"pbdoc(
        Computes the value of the Hartmann N. 6 benchmark function.
        SCORES = hartmann6(X) computes the value of the Hartmann N. 6
        function at point X. `hartmann6` accepts a matrix of size M-by-6 and
        returns a vector SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: \approx -3.32237
        - Location of global minimum: \approx (0.20169, 0.150011, 0.476874, 0.275332, 0.311652, 0.6573)
        - Number of dimensions: 6
        - Recommended domain: [0, 1]^6
        - Number of local minima: 6
        - Number of global minima: 1
        - Convexity: Non-convex
        - Separability: Non-separable
        - Modality: Multimodal
        - Symmetry: Non-symmetric
        - Differentiable: Yes
        For more information, please visit:
        benchmarkfcns.info/doc/hartmann6fcn
    )pbdoc");

    m.def("himmelblau", &himmelblau, R"pbdoc(
        Computes the value of the Himmelblau's benchmark function.
        SCORES = himmelblau(X) computes the value of the Himmelblau's
        function at point X. `himmelblau` accepts a matrix of size M-by-2
        and returns a vector SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minima: There are 4 global minima: (3.0, 2.0),
            (-2.805118, 3.131312), (-3.779310, -3.283186), (3.584428, -1.848126)
        - Number of dimensions: 2
        - Recommended domain: x, y ∈ [-5, 5]
        - Number of local minima: 0 (Every "valley" leads to a global minimum)
        - Number of global minima: 4
        - Convexity: Non-convex
        - Separability: Non-separable
        - Modality: Multimodal (Quadrimodal)
        - Symmetry: Non-symmetric (The locations are not mirror images)
        - Differentiable: Yes
        For more information, please visit:
        benchmarkfcns.info/doc/himmelblaufcn
    )pbdoc");

    m.def("holdertable", &holdertable, R"pbdoc(
        Computes the value of the Holder table benchmark function.
        SCORES = holdertable(X) computes the value of the Holder table
        function at point X. `holdertable` accepts a matrix of size M-by-2 and
        returns a vector SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: -19.2085
        - Location of global minimum: There are 4 global minima: (±8.05502, ±9.66459)
        - Number of dimensions: 2
        - Recommended domain: x ∈ [-10, 10], y ∈ [-10, 10]
        - Number of local minima: Numerous (Many smaller ripples leading to the "legs" of
            the table)
        - Number of global minima: 4
        - Convexity: Non-convex
        - Separability: Non-separable
        - Modality: Highly Multimodal
        - Symmetry: Symmetric (Across both axes and the origin)
        - Differentiable: No
        For more information, please visit:
        benchmarkfcns.info/doc/holdertablefcn
    )pbdoc");

    m.def("hosaki", &hosaki, R"pbdoc(
        Computes the value of the Hosaki benchmark function.
        SCORES = hosaki(X) computes the value of the Hosaki function at
        point X. `hosaki` accepts a matrix of size M-by-2 and returns a
        vector SCORES of size M-by-1 in which each row contains the function value
        for the corresponding row of X.
        Properties:
        - Global minimum: -2.3458 (approximately)
        - Location of global minimum: (0.803, 9.126)
        - Number of dimensions: 2
        - Recommended domain: x ∈ [0, 5], y ∈ [0, 10]
        - Number of local minima: 2 (The global minimum and one local minimum)
        - Number of global minima: 1
        - Convexity: Non-convex
        - Separability: Non-separable (The exponential term couples x and y)
        - Modality: Bimodal
        - Symmetry: Non-symmetric
        - Differentiable: Yes
    )pbdoc");

    m.def("ishigami", &ishigami, py::arg("x"), py::arg("a") = 7.0, py::arg("b") = 0.1, R"pbdoc(
        Computes the value of the Ishigami benchmark function.
        SCORES = ishigami(X) computes the value of the Ishigami function at point X.
        `ishigami` accepts a matrix of size M-by-3 and returns a vector SCORES of
        size M-by-1 in which each row contains the function value for the
        corresponding row of X.
        SCORES = ishigami(X, a=A, b=B) specifies the 'a' and 'b' parameters.
        Properties:
        - Global minimum: depends on a and b
        - Number of dimensions: 3
        - Recommended domain: [-π, π]^3
        - Number of local minima: many
        - Number of global minima: 1
        - Convexity: non-convex
        - Separability: non-separable (strong interaction between x1 and x3)
        - Modality: multimodal
    )pbdoc");

    m.def("katsuura", &katsuura, R"pbdoc(
        Computes the value of the Katsuura benchmark function.
        SCORES = katsuura(X) computes the value of the Katsuura function at point X.
        `katsuura` accepts a matrix of size M-by-N and returns a vector SCORES of
        size M-by-1 in which each row contains the function value for the
        corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (0, 0, ..., 0)
        - Number of dimensions: n
        - Recommended domain: [-100, 100]^n
        - Number of local minima: many (highly rugged)
        - Number of global minima: 1
        - Convexity: non-convex
        - Separability: non-separable
        - Modality: multimodal
        - Differentiability: non-differentiable (fractal-like)
    )pbdoc");

    m.def("keane", &keane, R"pbdoc(
        Computes the value of the Keane function.
        SCORES = keane(X) computes the value of the Keane function at point X.
        `keane` accepts a matrix of size M-by-2 and returns a vector SCORES of
        size M-by-1 in which each row contains the function value for the
        corresponding row of X.
        Properties:
        - Global minimum: -0.6736675 (for n=2)
        - Location of global minimum: (1.393249, 0) or (0, 1.393249)
        - Number of dimensions: n
        - Recommended domain: [0, 10]^n
        - Number of local minima: Numerous (Highly rugged/bumpy)
        - Number of global minima: 2 (in the 2D version)
        - Convexity: Non-convex
        - Separability: Non-separable
        - Modality: Highly Multimodal
        - Differentiable: Yes
        For more information, please visit:
        benchmarkfcns.info/doc/keanefcn
    )pbdoc");

    m.def("langermann", &langermann, R"pbdoc(
        Computes the value of the Langermann benchmark function.
        SCORES = langermann(X) computes the value of the Langermann function at point X.
        `langermann` accepts a matrix of size M-by-2 and returns a vector SCORES of
        size M-by-1 in which each row contains the function value for the
        corresponding row of X.
        Properties:
        - Global minimum: \approx -5.1621259
        - Location of global minimum: \approx (2.002992, 1.006096)
        - Number of dimensions: 2
        - Recommended domain: [0, 10]^2
        - Number of local minima: many
        - Number of global minima: 1
        - Convexity: non-convex
        - Separability: non-separable
        - Modality: multimodal
    )pbdoc");

    m.def("leon", &leon, R"pbdoc(
        Computes the value of the Leon function.
        SCORES = leon(X) computes the value of the Leon function at point X.
        `leon` accepts a matrix of size M-by-2 and returns a vector SCORES of
        size M-by-1 in which each row contains the function value for the
        corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (1, 1)
        - Number of dimensions: 2
        - Recommended domain: [-1.2, 1.2]^2
        - Number of local minima: 0
        - Number of global minima: 1
        - Convexity: non-convex
        - Separability: non-separable
        - Modality: unimodal
        - Symmetry: non-symmetric
        - Differentiable: Yes
        For more information, please visit:
        benchmarkfcns.info/doc/leonfcn
    )pbdoc");

    m.def("levin13", &levin13, R"pbdoc(
        Computes the value of the Levi N. 13 benchmark function.
        SCORES = levin13(X) computes the value of the Levi N. 13 function at
        point X. `levin13` accepts a matrix of size M-by-2 and returns a
        vector SCORES of size M-by-1 in which each row contains the function value
        for the corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (1, 1)
        - Number of dimensions: 2
        - Recommended domain: [-10, 10]^2
        - Number of local minima: Approximately 100 (depending on the search range)
        - Number of global minima: 1
        - Convexity: Non-convex
        - Separability: Non-separable
        - Modality: Highly Multimodal
        - Symmetry: Non-symmetric (though it appears somewhat periodic)
        - Differentiable: Yes
        For more information, please visit:
        benchmarkfcns.info/doc/levin13fcn
    )pbdoc");

    m.def("levy", &levy, R"pbdoc(
        Computes the value of the Levy benchmark function.
        SCORES = levy(X) computes the value of the Levy function at point X.
        `levy` accepts a matrix of size M-by-N and returns a vector SCORES of
        size M-by-1 in which each row contains the function value for the
        corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (1, 1, ..., 1)
        - Number of dimensions: n
        - Recommended domain: [-10, 10]^n
        - Number of local minima: many
        - Number of global minima: 1
        - Convexity: non-convex
        - Separability: non-separable
        - Modality: multimodal
    )pbdoc");

    m.def("lunacekbirastrigin", &lunacekbirastrigin, R"pbdoc(
        Computes the value of the Lunacek Bi-Rastrigin benchmark function.
        SCORES = lunacekbirastrigin(X) computes the value of the Lunacek Bi-Rastrigin
        function at point X. `lunacekbirastrigin` accepts a matrix of size M-by-N and
        returns a vetor SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (mu0, mu0, ..., mu0) where mu0 = 2.5
        - Number of dimensions: n
        - Recommended domain: [-5, 5]^n
        - Modality: multimodal and deceptive (two main basins)
        - Separability: non-separable
    )pbdoc");

    m.def("matyas", &matyas, R"pbdoc(
        Computes the value of the Matyas benchmark function.
        SCORES = matyas(X) computes the value of the Matyas function at
        point X. `matyas` accepts a matrix of size M-by-2 and returns a
        vector SCORES of size M-by-1 in which each row contains the function value
        for the corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (0, 0)
        - Number of dimensions: 2
        - Recommended domain: [-10, 10]^2
        - Number of local minima: 0
        - Number of global minima: 1
        - Convexity: Convex
        - Separability: Non-separable (The xy term couples the variables)
        - Modality: Unimodal
        - Symmetry: Symmetric (with respect to x and y)
        - Differentiable: Yes
        For more information, please visit:
        benchmarkfcns.info/doc/matyasfcn
    )pbdoc");

    m.def("mccormick", &mccormick, R"pbdoc(
        Computes the value of the McCormick benchmark function.
        SCORES = mccormick(X) computes the value of the McCormick function
        at point X. `mccormick` accepts a matrix of size M-by-2 and returns a
        vector SCORES of size M-by-1 in which each row contains the function value
        for the corresponding row of X.
        Properties:
        - Global minimum: -1.9133 (approximately)
        - Location of global minimum: (-0.54719, -1.54719)
        - Number of dimensions: 2
        - Recommended domain: x ∈ [-1.5, 4], y ∈ [-3, 4]
        - Number of local minima: 1
        - Number of global minima: 1
        - Convexity: Non-convex
        - Separability: Non-separable
        - Modality: Multimodal (Mildly)
        - Symmetry: Non-symmetric
        - Differentiable: Yes
        For more information, please visit:
        benchmarkfcns.info/doc/mccormickfcn
    )pbdoc");

    m.def("michalewicz", &michalewicz, py::arg("x"), py::arg("m") = 10, R"pbdoc(
        Computes the value of the Michalewicz benchmark function.
        SCORES = michalewicz(X) computes the value of the Michalewicz function
        at point X. `michalewicz` accepts a matrix of size M-by-N and returns a
        vector SCORES of size M-by-1 in which each row contains the function value
        for the corresponding row of X.
        SCORES = michalewicz(X, m=M) computes the function with the given
        value of M for its 'm' parameter.
        Properties:
        - Global minimum: -1.8013 (for n=2), -4.687658 (for n=5), -9.66015 (for n=10)
        - Location of global minimum: depends on n
        - Number of dimensions: n
        - Recommended domain: [0, π]^n
        - Number of local minima: n!
        - Number of global minima: 1
        - Convexity: non-convex
        - Separability: separable
        - Modality: multimodal
    )pbdoc");

    m.def("mishrabird", &mishrabird, py::arg("x"), R"pbdoc(
        Computes the value of the Mishra's Bird benchmark function.
        SCORES = mishrabird(X) computes the value of the Mishra's Bird function
        at point X. `mishrabird` accepts a matrix of size M-by-2 and returns a
        vector SCORES of size M-by-1 in which each row contains the function value
        for the corresponding row of X.
        Properties:
        - Domain: [-10, 10]^2
        - Global minimum: -1.0666
        - Location of global minimum: (-3.13, -1.58)
        - Number of global minima: 1
        - Convexity: Non-convex
        - Separability: Non-separable
        - Modality: Multimodal
        - Symmetry: Non-symmetric
        - Differentiable: Yes
        For more information, please visit:
        benchmarkfcns.info/doc/mishrabirdfcn
    )pbdoc");

    m.def("periodic", &periodic, R"pbdoc(
        Computes the value of the Periodic function.
        SCORES = periodic(X) computes the value of the Periodic
        function at point X. `periodic` accepts a matrix of size M-by-N and
        returns a vector SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: 0.9
        - Location of global minimum: (0, 0, ..., 0)
        - Number of dimensions: n
        - Recommended domain: [-10, 10]^n
        - Number of local minima: many
        - Number of global minima: 1
        - Convexity: non-convex
        - Separability: separable
        - Modality: multimodal
        - Symmetry: symmetric
        - Differentiable: Yes
        For more information, please visit:
        benchmarkfcns.info/doc/periodicfcn
    )pbdoc");

    m.def("perm", &perm, py::arg("x"), py::arg("beta") = 0.5, R"pbdoc(
        Computes the value of the Perm function.
        SCORES = perm(X) computes the value of the Perm function at point X.
        `perm` accepts a matrix of size M-by-N and returns a vector SCORES of
        size M-by-1 in which each row contains the function value for the
        corresponding row of X.
        SCORES = perm(X, beta=BETA) specifies the BETA parameter.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (1, 2, ..., n)
        - Number of dimensions: n
        - Recommended domain: [-n, n]^n
        - Number of local minima: many
        - Number of global minima: 1
        - Convexity: non-convex
        - Separability: non-separable
        - Modality: multimodal
    )pbdoc");

    m.def("picheny", &picheny, R"pbdoc(
        Computes the value of the Picheny benchmark function.
        SCORES = picheny(X) computes the value of the Picheny function at
        point X. `picheny` accepts a matrix of size M-by-2 and returns a
        vector SCORES of size M-by-1 in which each row contains the function value
        for the corresponding row of X.
        Properties:
        - Global minimum: -1.0 (approximately)
        - Location of global minimum: x ≈ 0.757
        - Number of dimensions: 1
        - Recommended domain: x ∈ [0, 1]
        - Number of local minima: Numerous (Highly oscillatory in specific regions)
        - Number of global minima: 1
        - Convexity: Non-convex
        - Modality: Highly Multimodal
        - Differentiable: Yes
        For more information, please visit:
        benchmarkfcns.info/doc/pichenyfcn
    )pbdoc");

    m.def("powellsingular", &powellsingular, R"pbdoc(
        Computes the value of the Powell Singular benchmark function.
        SCORES = powellsingular(X) computes the value of the Powell Singular function at
        point X. `powellsingular` accepts a matrix of size M-by-4 and returns a vector
        SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (0, 0, 0, 0)
        - Number of dimensions: 4
        - Recommended domain: [-4, 5]^4
        - Number of local minima: 0
        - Number of global minima: 1
        - Convexity: non-convex
        - Separability: non-separable
        - Modality: unimodal
    )pbdoc");

    m.def("powellsum", &powellsum, R"pbdoc(
        Computes the value of the Powell Sum benchmark function.
        SCORES = powellsum(X) computes the value of the Powell Sum function at
        point X. `powellsum` accepts a matrix of size M-by-N and returns a vector
        SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (0, 0, ..., 0)
        - Number of dimensions: n (Scalable)
        - Recommended domain: x_i ∈ [-1, 1]
        - Number of local minima: 0
        - Number of global minima: 1
        - Convexity: Convex
        - Separability: Separable
        - Modality: Unimodal
        - Symmetry: Symmetric (relative to the origin)
        - Differentiable: Yes
        For more information, please visit:
        benchmarkfcns.info/doc/powellsumfcn
    )pbdoc");

    m.def("qing", &qing, R"pbdoc(
        Computes the value of the Qing function.
        SCORES = qing(X) computes the value of the Qing
        function at point X. `qing` accepts a matrix of size M-by-N and
        returns a vector SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: x_i = \pm \sqrt{i}
        - Number of dimensions: n
        - Recommended domain: [-500, 500]^n
        - Number of local minima: many
        - Number of global minima: 2^n
        - Convexity: non-convex
        - Separability: separable
        - Modality: multimodal
        - Differentiable: Yes
        For more information, please visit:
        benchmarkfcns.info/doc/qingfcn
    )pbdoc");

    m.def("quartic", &quartic, R"pbdoc(
        Computes the value of Quartic benchmark function.
        SCORES = quartic(X) computes the value of the Quartic function at
        point X. `quartic` accepts a matrix of size M-by-N and returns a vector
        SCORES of size M-by-1 in which each row contains the function value for
        each row of X.
        Properties:
        - Global minimum: 0 (without noise)
        - Location of global minimum: (0, 0, ..., 0)
        - Number of dimensions: n
        - Recommended domain: [-1.28, 1.28]^n
        - Number of local minima: 0 (unimodal, without noise)
        - Number of global minima: 1
        - Convexity: convex
        - Separability: separable
        - Modality: unimodal
        - Symmetry: symmetric
        - Differentiable: Yes
        For more information, please visit:
        benchmarkfcns.info/doc/quarticfcn
    )pbdoc");

    m.def("rana", &rana, R"pbdoc(
        Computes the value of the Rana benchmark function.
        SCORES = rana(X) computes the value of the Rana function at point X.
        `rana` accepts a matrix of size M-by-N and returns a vector SCORES of
        size M-by-1 in which each row contains the function value for the
        corresponding row of X.
        Properties:
        - Global minimum: depends on n
        - Location of global minimum: depends on n
        - Number of dimensions: n
        - Recommended domain: [-512, 512]^n
        - Number of local minima: many
        - Number of global minima: 1
        - Convexity: non-convex
        - Separability: non-separable
        - Modality: multimodal
        - Differentiable: Yes
    )pbdoc");

    m.def("rastrigin", &rastrigin, R"pbdoc(
        Computes the value of Rastrigin benchmark function.
        SCORES = rastrigin(X) computes the value of the Rastrigin function at
        point X. `rastrigin` accepts a matrix of size M-by-N and returns a vector
        SCORES of size M-by-1 in which each row contains the function value for
        the corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (0, 0, ..., 0)
        - Number of dimensions: n
        - Recommended domain: [-5.12, 5.12]^n
        - Number of local minima: many
        - Number of global minima: 1
        - Convexity: non-convex
        - Separability: separable
        - Modality: multimodal
        - Symmetry: symmetric
        - Differentiable: Yes
        For more information, please visit:
        benchmarkfcns.info/doc/rastriginfcn
    )pbdoc");

    m.def("ridge", &ridge, py::arg("x"), py::arg("d") = 1, py::arg("alpha") = 0.5, R"pbdoc(
        Computes the value of the Ridge benchmark function.
        SCORES = ridge(X) computes the value of the Ridge function at point X.
        `ridge` accepts a matrix of size M-by-N and returns a vector SCORES of
        size M-by-1 in which each row contains the function value for the
        corresponding row of X.
        SCORES = ridge(X, d=D) specifies contribution coefficient of the sphere
        component of the function.
        SCORES = ridge(X, d=D, alpha=ALPHA) specifies power of the sphere component of
        the function.
        Properties:
        - Global minimum: depends on domain (usually at the boundary)
        - Location of global minimum: depends on domain
        - Number of dimensions: n
        - Recommended domain: [-5, 5]^n
        - Number of local minima: 0 (unimodal)
        - Number of global minima: 1
        - Convexity: convex
        - Separability: non-separable
        - Modality: unimodal
        - Differentiable: Yes (for alpha > 0.5)
        For more information, please visit:
        benchmarkfcns.info/doc/ridgefcn
    )pbdoc");

    m.def("rosenbrock", &rosenbrock, R"pbdoc(
        Computes the value of the Rosenbrock benchmark function.
        SCORES = rosenbrock(X) computes the value of the Rosenbrock function
        at point X. `rosenbrock` accepts a matrix of size M-by-N and returns a
        vector SCORES of size M-by-1 in which each row contains the function value
        for the corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (1, 1, ..., 1)
        - Number of dimensions: n
        - Recommended domain: [-5, 5]^n
        - Number of local minima: many (the "banana-shaped" valley creates a long, narrow
            region of local minima)
        - Number of global minima: 1
        - Convexity: non-convex
        - Separability: non-separable
        - Modality: unimodal
        - Symmetry: non-symmetric
        - Differentiable: Yes
        For more information, please visit:
        benchmarkfcns.info/doc/rosenbrockfcn
    )pbdoc");

    m.def("salomon", &salomon, R"pbdoc(
        Computes the value of the Salomon's benchmark function.
        SCORES = salomon(X) computes the value of the Salomon's
        function at point X. `salomon` accepts a matrix of size M-by-N
        and returns a vector SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (0, 0, ..., 0)
        - Number of dimensions: n
        - Recommended domain: [-100, 100]^n
        - Number of local minima: many (The cosine of the Euclidean norm creates an
            infinite series of concentric circular "trap" valleys)
        - Number of global minima: 1
        - Convexity: non-convex
        - Separability: non-separable
        - Modality: multimodal
        - Symmetry: symmetric
        - Differentiable: Yes (Except potentially at the origin, though the limit usually
            behaves well)
        For more information, please visit:
        benchmarkfcns.info/doc/salomonfcn
    )pbdoc");

    m.def("schafferf6", &schafferf6, R"pbdoc(
        Computes the value of the Schaffer F6 function.
        SCORES = schafferf6(X) computes the value of the Schaffer F6
        function at point X. `schafferf6` accepts a matrix of size M-by-2 and
        returns a vector SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (0, 0)
        - Number of dimensions: 2
        - Recommended domain: [-100, 100]^2
        - Number of local minima: many
        - Number of global minima: 1
        - Convexity: non-convex
        - Separability: non-separable
        - Modality: multimodal
    )pbdoc");

    m.def("schafferf7", &schafferf7, R"pbdoc(
        Computes the value of the Schaffer F7 benchmark function.
        SCORES = schafferf7(X) computes the value of the Schaffer F7 function at point X.
        `schafferf7` accepts a matrix of size M-by-N and returns a vector SCORES of
        size M-by-1 in which each row contains the function value for the
        corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (0, 0, ..., 0)
        - Number of dimensions: n
        - Recommended domain: [-100, 100]^n
        - Modality: multimodal
    )pbdoc");

    m.def("schaffern1", &schaffern1, R"pbdoc(
        Computes the value of the Schaffer N. 1 function.
        SCORES = schaffer1(X) computes the value of the Schaffer N. 1
        function at point X. `schaffern1` accepts a matrix of size M-by-2 and
        returns a vector SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (0, 0)
        - Number of dimensions: 2
        - Recommended domain: [-100, 100]^2
        - Number of local minima: many
        - Number of global minima: 1
        - Convexity: non-convex
        - Separability: non-separable
        - Modality: multimodal
        For more information, please visit:
        benchmarkfcns.info/doc/schaffern1fcn
    )pbdoc");

    m.def("schaffern2", &schaffern2, R"pbdoc(
        Computes the value of the Schaffer N. 2 benchmark function.
        SCORES = schaffer2(X) computes the value of the Schaffer N. 2 function
        at point X. `schaffer2` accepts a matrix of size M-by-2 and returns a
        vector SCORES of size M-by-1 in which each row contains the function value
        for the corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (0, 0)
        - Number of dimensions: 2
        - Recommended domain: [-100, 100]^2
        - Number of local minima: many
        - Number of global minima: 1
        - Convexity: non-convex
        - Separability: non-separable
        - Modality: multimodal
        For more information, please visit:
        benchmarkfcns.info/doc/schaffern2fcn
    )pbdoc");

    m.def("schaffern3", &schaffern3, R"pbdoc(
        Computes the value of the Schaffer N. 3 function.
        SCORES = schaffer3(X) computes the value of the Schaffer N. 3
        function at point X. `schaffer3` accepts a matrix of size M-by-2 and
        returns a vector SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (0, 0)
        - Number of dimensions: 2
        - Recommended domain: [-100, 100]^2
        - Number of local minima: many
        - Number of global minima: 1
        - Convexity: non-convex
        - Separability: non-separable
        - Modality: multimodal
        For more information, please visit:
        benchmarkfcns.info/doc/schaffern3fcn
    )pbdoc");

    m.def("schaffern4", &schaffern4, R"pbdoc(
        Computes the value of the Schaffer N. 4 function.
        SCORES = schaffer4(X) computes the value of the Schaffer N. 4
        function at point X. `schaffer4` accepts a matrix of size M-by-2 and
        returns a vector SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (0, \pm 1.25313)
        - Number of dimensions: 2
        - Recommended domain: [-100, 100]^2
        - Number of local minima: many
        - Number of global minima: 2
        - Convexity: non-convex
        - Separability: non-separable
        - Modality: multimodal
        For more information, please visit:
        benchmarkfcns.info/doc/schaffern4fcn
    )pbdoc");

    m.def("schwefel", &schwefel, R"pbdoc(
        Computes the value of the Schwefel benchmark function.
        SCORES = schwefel(X) computes the value of the Schwefel function at
        point X. `schwefel` accepts a matrix of size M-by-N and returns a
        vector SCORES of size M-by-1 in which each row contains the function value
        for the corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (420.9687, 420.9687, ..., 420.9687)
        - Number of dimensions: n
        - Recommended domain: [-500, 500]^n
        - Number of local minima: many
        - Number of global minima: 1
        - Convexity: non-convex
        - Separability: separable
        - Modality: multimodal
        - Differentiable: Yes
        For more information, please visit:
        benchmarkfcns.info/doc/schwefelfcn
    )pbdoc");

    m.def("schwefel12", &schwefel12, R"pbdoc(
        Computes the value of the Schwefel 1.2 (Double Sum) benchmark function.
        SCORES = schwefel12(X) computes the value of the Schwefel 1.2 function at point X.
        `schwefel12` accepts a matrix of size M-by-N and returns a vetor SCORES of
        size M-by-1 in which each row contains the function value for the
        corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (0, 0, ..., 0)
        - Number of dimensions: n
        - Recommended domain: [-100, 100]^n
        - Modality: unimodal
        - Characteristic: Also known as the Rotated Hyper-Ellipsoid function.
    )pbdoc");

    m.def("schwefel220", &schwefel220, R"pbdoc(
        Computes the value of the Schwefel 2.20 function.
        SCORES = schwefel220(X) computes the value of the Schwefel 2.20
        function at point X. `schwefel220` accepts a matrix of size M-by-N and
        returns a vector SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (0, 0, ..., 0)
        - Number of dimensions: n
        - Recommended domain: [-100, 100]^n
        - Number of local minima: 0 (unimodal)
        - Number of global minima: 1
        - Convexity: convex
        - Separability: separable
        - Modality: unimodal
        - Symmetry: symmetric
        - Differentiable: No
        For more information, please visit:
        benchmarkfcns.info/doc/schwefel220fcn
    )pbdoc");

    m.def("schwefel221", &schwefel221, R"pbdoc(
        Computes the value of the Schwefel 2.21 function.
        SCORES = schwefel221(X) computes the value of the Schwefel 2.21
        function at point X. `schwefel221` accepts a matrix of size M-by-N and
        returns a vector SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (0, 0, ..., 0)
        - Number of dimensions: n
        - Recommended domain: x_i ∈ [-100, 100]
        - Number of local minima: 0 (It is unimodal)
        - Convexity: Convex
        - Separability: Non-separable
        - Modality: Unimodal
        - Differentiable: No
        For more information, please visit:
        benchmarkfcns.info/doc/schwefel221fcn
    )pbdoc");

    m.def("schwefel222", &schwefel222, R"pbdoc(
        Computes the value of the Schwefel 2.22 function.
        SCORES = schwefel222(X) computes the value of the Schwefel 2.22
        function at point X. `schwefel222` accepts a matrix of size M-by-N and
        returns a vector SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (0, 0, ..., 0)
        - Number of dimensions: n
        - Recommended domain: [-10, 10]^n
        - Number of local minima: 0 (unimodal)
        - Number of global minima: 1
        - Convexity: convex
        - Separability: non-separable
        - Modality: unimodal
        - Symmetry: symmetric
        - Differentiable: No
        For more information, please visit:
        benchmarkfcns.info/doc/schwefel222fcn
    )pbdoc");

    m.def("schwefel223", &schwefel223, R"pbdoc(
        Computes the value of the Schwefel 2.23 function.
        SCORES = schwefel223fcn(X) computes the value of the Schwefel 2.23
        function at point X. `schwefel223fcn` accepts a matrix of size M-by-N and
        returns a vector SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (0, 0, ..., 0)
        - Number of dimensions: n
        - Recommended domain: [-10, 10]^n
        - Number of local minima: 0 (unimodal)
        - Number of global minima: 1
        - Convexity: convex
        - Separability: separable
        - Modality: unimodal
        - Symmetry: symmetric
        - Differentiable: Yes
        For more information, please visit:
        benchmarkfcns.info/doc/schwefel223fcn
    )pbdoc");

    m.def("shekel10", &shekel10, R"pbdoc(
        Computes the value of the Shekel-10 benchmark function.
        SCORES = shekel10(X) computes the value of the Shekel-10 function at
        point X. `shekel10` accepts a matrix of size M-by-4 and returns a vector
        SCORES of size M-by-1 in which each row contains the function value for
        each row of X.
        Properties:
        - Global minimum: \approx -10.5364
        - Location of global minimum: (4, 4, 4, 4)
        - Number of dimensions: 4
        - Recommended domain: [0, 10]^4
    )pbdoc");

    m.def("shekel5", &shekel5, R"pbdoc(
        Computes the value of the Shekel-5 benchmark function.
        SCORES = shekel5(X) computes the value of the Shekel-5 function at
        point X. `shekel5` accepts a matrix of size M-by-4 and returns a vector
        SCORES of size M-by-1 in which each row contains the function value for
        each row of X.
        Properties:
        - Global minimum: \approx -10.1532
        - Location of global minimum: (4, 4, 4, 4)
        - Number of dimensions: 4
        - Recommended domain: [0, 10]^4
    )pbdoc");

    m.def("shekel7", &shekel7, R"pbdoc(
        Computes the value of the Shekel-7 benchmark function.
        SCORES = shekel7(X) computes the value of the Shekel-7 function at
        point X. `shekel7` accepts a matrix of size M-by-4 and returns a vector
        SCORES of size M-by-1 in which each row contains the function value for
        each row of X.
        Properties:
        - Global minimum: \approx -10.4029
        - Location of global minimum: (4, 4, 4, 4)
        - Number of dimensions: 4
        - Recommended domain: [0, 10]^4
    )pbdoc");

    m.def("shubert", &shubert, R"pbdoc(
        Computes the value of the Shubert function.
        SCORES = shubert(X) computes the value of the Shubert
        function at point X. `shubert` accepts a matrix of size M-by-N and
        returns a vector SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: \approx -186.7309 (for n=2)
        - Location of global minimum: multiple
        - Number of dimensions: n
        - Recommended domain: [-10, 10]^n
        - Number of local minima: many
        - Number of global minima: multiple
        - Convexity: non-convex
        - Separability: non-separable
        - Modality: multimodal
        - Symmetry: symmetric
        - Differentiable: Yes
        For more information, please visit:
        benchmarkfcns.info/doc/shubertfcn
    )pbdoc");

    m.def("shubertn3", &shubertn3, R"pbdoc(
        Computes the value of the Shubert 3 function.
        SCORES = shubert3(X) computes the value of the Shubert 3
        function at point X. `shubert3` accepts a matrix of size M-by-N and
        returns a vector SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: \approx -29.6309
        - Location of global minimum: multiple
        - Number of dimensions: n
        - Recommended domain: [-10, 10]^n
        - Number of local minima: many
        - Number of global minima: multiple
        - Convexity: non-convex
        - Separability: non-separable
        - Modality: multimodal
        For more information, please visit:
        benchmarkfcns.info/doc/shubert3fcn
    )pbdoc");

    m.def("shubertn4", &shubertn4, R"pbdoc(
        Computes the value of the Shubert 4 function.
        SCORES = shubert4(X) computes the value of the Shubert 4
        function at point X. `shubert4` accepts a matrix of size M-by-N and
        returns a vector SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: \approx -25.7408
        - Location of global minimum: multiple
        - Number of dimensions: n
        - Recommended domain: [-10, 10]^n
        - Number of local minima: many
        - Number of global minima: multiple
        - Convexity: non-convex
        - Separability: non-separable
        - Modality: multimodal
        For more information, please visit:
        benchmarkfcns.info/doc/shubert4fcn
    )pbdoc");

    m.def("sixhumpcamel", &sixhumpcamel, R"pbdoc(
        Computes the value of the Six-hump camel benchmark function.
        SCORES = sixhumpcamel(X) computes the value of the Six-hump camel
        function at point X. `sixhumpcamel` accepts a matrix of size M-by-2
        and returns a vector SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: -1.0316
        - Location of global minimum: (0.0898, -0.7126), (-0.0898, 0.7126)
        - Number of dimensions: 2
        - Recommended domain: x_1 \in [-3, 3], x_2 \in [-2, 2]
        - Number of local minima: 4 (excluding the 2 global minima)
        - Number of global minima: 2
        - Convexity: non-convex
        - Separability: non-separable
        - Modality: multimodal
        - Symmetry: symmetric (about the origin)
        - Differentiable: Yes
        For more information, please visit:
        benchmarkfcns.info/doc/sixhumpcamelfcn
    )pbdoc");

    m.def("sphere", &sphere, R"pbdoc(
        Computes the value of Sphere benchmark function.
        SCORES = sphere(X) computes the value of the Sphere function at
        point X. `sphere` accepts a matrix of size M-by-N and returns a vector
        SCORES of size M-by-1 in which each row contains the function value for
        each row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: 0
        - Number of dimensions: n
        - Domain: [-5.12, 5.12]^n
        - Number of local minima: 0
        - Number of global minima: 1
        - Convexity: convex
        - Separability: separable
        - Modality: unimodal
        - Symmetry: symmetric
        For more information, please visit:
        benchmarkfcns.info/doc/spherefcn
    )pbdoc");

    m.def("step", &step, R"pbdoc(
        Computes the value of the Step benchmark function (De Jong N. 3).
        SCORES = step(X) computes the value of the Step function at point X.
        `step` accepts a matrix of size M-by-N and returns a vector SCORES of
        size M-by-1 in which each row contains the function value for the
        corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: depends on domain (typically [0, 1]^n)
        - Number of dimensions: n
        - Recommended domain: [-5.12, 5.12]^n
        - Modality: unimodal (with plateaus)
        - Characteristic: zero gradient almost everywhere.
    )pbdoc");

    m.def("stretchedvsine", &stretchedvsine, R"pbdoc(
        Computes the value of the Stretched V Sine benchmark function.
        SCORES = stretchedvsine(X) computes the value of the Stretched V Sine
        function at point X. `stretchedvsine` accepts a matrix of size M-by-N
        and returns a vector SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (0, 0, ..., 0)
        - Number of dimensions: n
        - Recommended domain: [-10, 10]^n
        - Number of local minima: many
        - Number of global minima: 1
        - Convexity: non-convex
        - Separability: non-separable
        - Modality: multimodal
        - Symmetry: symmetric
        - Differentiable: Yes
        For more information, please visit:
        benchmarkfcns.info/doc/stretchedvsinefcn
    )pbdoc");

    m.def("styblinskitank", &styblinskitank, R"pbdoc(
        Computes the value of the Styblinski-Tank benchmark function.
        SCORES = styblinskitank(X) computes the value of the Styblinski-Tank
        function at point X. `styblinskitank` accepts a matrix of size M-by-N
        and returns a vector SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: -39.16599 * n
        - Location of global minimum: (-2.903534, -2.903534, ..., -2.903534)
        - Number of dimensions: n
        - Recommended domain: [-5, 5]^n
        - Number of local minima: many
        - Number of global minima: 1
        - Convexity: non-convex
        - Separability: separable
        - Modality: multimodal
        - Symmetry: non-symmetric
        - Differentiable: Yes
        For more information, please visit:
        benchmarkfcns.info/doc/styblinskitankfcn
    )pbdoc");

    m.def("sumsquares", &sumsquares, R"pbdoc(
        Computes the value of the Sum Squares function.
        SCORES = sumsquares(X) computes the value of the Sum Squares
        function at point X. `sumsquares` accepts a matrix of size M-by-N and
        returns a vector SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (0, 0, ..., 0)
        - Number of dimensions: n
        - Recommended domain: [-10, 10]^n
        - Number of local minima: 0 (unimodal)
        - Number of global minima: 1
        - Convexity: convex
        - Separability: separable
        - Modality: unimodal
        - Symmetry: symmetric
        - Differentiable: Yes
        For more information, please visit:
        benchmarkfcns.info/doc/sumsquaresfcn
    )pbdoc");

    m.def("threehumpcamel", &threehumpcamel, R"pbdoc(
        Computes the value of the Three-hump camel benchmark function.
        SCORES = threehumpcamel(X) computes the value of the Three-hump camel
        function at point X. `threehumpcamel` accepts a matrix of size M-by-2
        and returns a vector SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (0, 0)
        - Number of dimensions: 2
        - Recommended domain: [-5, 5]^2
        - Number of local minima: 2
        - Number of global minima: 1
        - Convexity: non-convex
        - Separability: non-separable
        - Modality: multimodal
        - Symmetry: symmetric
        - Differentiable: Yes
        For more information, please visit:
        benchmarkfcns.info/doc/threehumpcamelfcn
    )pbdoc");

    m.def("treccani", &treccani, R"pbdoc(
        Computes the value of the Treccani benchmark function.
        SCORES = treccani(X) computes the value of the Treccani
        function at point X. `treccani` accepts a matrix of size M-by-2 and
        returns a vector SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (0, 0), (-2, 0)
        - Number of dimensions: 2
        - Recommended domain: [-5, 5]^2
        - Number of local minima: 0 (The valleys lead to global minima)
        - Number of global minima: 2
        - Convexity: non-convex
        - Separability: separable
        - Modality: multimodal
        - Symmetry: symmetric
        - Differentiable: Yes
    )pbdoc");

    m.def("trid", &trid, R"pbdoc(
        Computes the value of the Trid benchmark function.
        SCORES = trid(X) computes the value of the Trid
        function at point X. `trid` accepts a matrix of size M-by-N and
        returns a vector SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum:
            - For n=6: -50
            - For n=10: -210
            - General formula: -n(n+4)(n-1)/6
        - Location of global minimum: x_i = i(n + 1 - i)
        - Number of dimensions: n
        - Recommended domain: x_i ∈ [-n^2, n^2]
        - Number of local minima: 0 (Unimodal)
        - Convexity: Convex
        - Separability: Non-separable
        - Symmetry: Non-symmetric
        - Differentiable: Yes
        For more information, please visit:
        benchmarkfcns.info/doc/tridfcn
    )pbdoc");

    m.def("vincent", &vincent, R"pbdoc(
        Computes the value of the Vincent benchmark function.
        SCORES = vincent(X) computes the value of the Vincent
        function at point X. `vincent` accepts a matrix of size M-by-N and
        returns a vector SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: -n
        - Location of global minimum: multiple
        - Number of dimensions: n
        - Recommended domain: [0.25, 10]^n
        - Number of local minima: 6^n
        - Number of global minima: multiple
        - Convexity: non-convex
        - Separability: separable
        - Modality: multimodal
        - Differentiable: Yes
    )pbdoc");

    m.def("watson", &watson, R"pbdoc(
        Computes the value of the Watson benchmark function.
        SCORES = watson(X) computes the value of the Watson
        function at point X. `watson` accepts a matrix of size M-by-6 and
        returns a vector SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: \approx 0.002288
        - Location of global minimum: (0, 0.8, ..., 0)
        - Number of dimensions: 6
        - Recommended domain: [-5, 5]^6
        - Number of local minima: 0 (unimodal in the search space)
        - Number of global minima: 1
        - Convexity: non-convex
        - Separability: non-separable
        - Modality: unimodal
        - Differentiable: Yes
    )pbdoc");

    m.def("wavy", &wavy, py::arg("x"), py::arg("k") = 10, R"pbdoc(
        Computes the value of the Wavy benchmark function.
        SCORES = wavy(X) computes the value of the Wavy
        function at point X and it is behaviour can be controlled with
        one additional parameters 'k'. `wavy` accepts a matrix of size M-by-N and
        returns a vector SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (0, 0, ..., 0)
        - Number of dimensions: n
        - Recommended domain: [-π, π]^n
        - Number of local minima: many
        - Number of global minima: 1
        - Convexity: non-convex
        - Separability: separable
        - Modality: multimodal
        - Symmetry: symmetric
        - Differentiable: Yes
    )pbdoc");

    m.def("wayburnseadern2", &wayburnseadern2, R"pbdoc(
        Computes the value of the Wayburn-Seader N. 2 benchmark function.
        SCORES = wayburnseadern2(X) computes the value of the Wayburn-Seader N. 2
        function at point X. `wayburnseadern2` accepts a matrix of size M-by-2 and
        returns a vector SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minima: There are 2 global minima:(0.200139, 1), (0.424861, 1)
        - Number of dimensions: 2 (x_1, x_2)
        - Recommended domain: x_1, x_2 ∈ [-500, 500] (though often visualized in [-5, 5]^2)
        - Number of local minima: 0 (It is generally considered unimodal/bimodal
            depending on the range, but the global minima are the only real sinks)
        - Number of global minima: 2
        - Convexity: Non-convex
        - Separability: Non-separable
        - Modality: Bimodal
        - Symmetry: Symmetric
        - Differentiable: Yes
    - Differentiable: Yes
    )pbdoc");

    m.def("weierstrass", &weierstrass, py::arg("X"), py::arg("a") = 0.5, py::arg("b") = 3.0, py::arg("kmax") = 20, R"pbdoc(
    Computes the value of the Weierstrass benchmark function.
        Properties:
            - Global minimum: 0
            - Location of global minimum: 0
            - Number of dimensions: n
            - Domain: [-0.5, 0.5]^n
            - Number of global minima: 1
            - Convexity: non-convex
            - Separability: separable
            - Modality: multi-modal
            - Symmetry: The function is symmetric with respect to its input dimensions. The
            outer summation treats each dimension of x independently and identically, so
            permuting the elements of the input vector x (e.g., swapping x1 and x2) will
            not change the output of the function.

        Inputs:
            x: A matrix where each row is a vector of dimension n.
            a: A scalar parameter that controls the amplitude of the cosine waves. For the
                function to be nowhere differentiable, this parameter must satisfy the
                condition 0<a<1.
            b: A scalar parameter that controls the frequency of the cosine waves. For the
                function to be nowhere differentiable, this parameter must be a positive
                odd integer. The original condition for non-differentiability is that
                ab>1.
            kmax: An integer that defines the number of terms in the summation. In the
                original, theoretical Weierstrass function, this summation goes to
                infinity. In practical, computable versions like this one, it is truncated
                at a finite value, kmax. A larger kmax makes the function more "crinkly"
                and complex.
        Outputs:
            scores: A column vector where each element is the function value at the
                corresponding row of x.

    )pbdoc");

    m.def("whitley", &whitley, R"pbdoc(
    Computes the value of the Whitley benchmark function.
    SCORES = whitley(X) computes the value of the Whitley function at point X.
    `whitley` accepts a matrix of size M-by-N and returns a vector SCORES of
    size M-by-1 in which each row contains the function value for the
    corresponding row of X.
    Properties:
    - Global minimum: 0
    - Location of global minimum: (1, 1, ..., 1)
    - Number of dimensions: n
    - Recommended domain: [-10.24, 10.24]^n
    - Modality: multimodal
    - Separability: non-separable
    )pbdoc");

    m.def("wolfe", &wolfe, R"pbdoc(
        Computes the value of the Wolfe function.
        SCORES = wolfe(X) computes the value of the Wolfe
        function at point X. `wolfe` accepts a matrix of size M-by-3 and
        returns a vector SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (0, 0, ..., 0)
        - Number of dimensions: 3 (usually, though 2D versions exist)
        - Recommended domain: x_i ∈ [0, 2]
        - Number of local minima: 0 (It is unimodal in a sense, but has "pathological"
        ridges).
        - Number of global minima: 1
        - Convexity: Non-convex
        - Separability: Non-separable
        - Modality: Unimodal
        - Differentiable: No
        For more information, please visit:
        benchmarkfcns.info/doc/wolfefcn
    )pbdoc");

    m.def("xinsheyangn1", &xinsheyangn1, R"pbdoc(
        Computes the value of the Xin-She Yang function.
        SCORES = xinsheyang1(X) computes the value of the Xin-She Yang
        function at point X. `xinsheyang1` accepts a matrix of size M-by-N and
        returns a vector SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (0, 0, ..., 0)
        - Number of dimensions: n (Scalable)
        - Recommended domain: x_i ∈ [-5, 5]
        - Number of local minima: 0
        - Number of global minima: 1
        - Convexity: convex
        - Separability: separable
        - Modality: Unimodal
        - Symmetry: Symmetric
        - Differentiable: No
        For more information, please visit:
        benchmarkfcns.info/doc/xinsheyangn1fcn
    )pbdoc");

    m.def("xinsheyangn2", &xinsheyangn2, R"pbdoc(
        Computes the value of the Xin-She Yang N. 2 function.
        SCORES = xinsheyang2(X) computes the value of the Xin-She Yang N. 2
        function at point X. `xinsheyang2` accepts a matrix of size M-by-N and
        returns a vector SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (0, 0, ..., 0)
        - Number of dimensions: n (Scalable)
        - Recommended domain: x_i ∈ [-2π, 2π]
        - Number of local minima: Numerous (Highly oscillatory)
        - Number of global minima: 1
        - Convexity: Non-convex
        - Separability: Non-separable
        - Modality: Highly Multimodal
        - Symmetry: Symmetric
        - Differentiable: No
        For more information, please visit:
        benchmarkfcns.info/doc/xinsheyangn2fcn
    )pbdoc");

    m.def("xinsheyangn3", &xinsheyangn3, py::arg("x"), py::arg("beta") = 15, py::arg("m") = 5, R"pbdoc(
        Computes the value of the Xin-She Yang N. 3 function.
        The Xin-She Yang N. 3 function is a parametric function and it is
        behaviour can be controlled with two additional parameters 'beta' and
        'm'. In this implementation, the parameters are optional and when not
        given, their default value will be used.
        SCORES = xinsheyang3(X) computes the value of the Xin-She Yang N. 3
        function at point X. `xinsheyang3` accepts a matrix of size P-by-N and
        returns a vector SCORES of size P-by-1 in which each row contains the
        function value for the corresponding row of X. In this case, the default
        values of 'm=5' and 'beta=15' is used for function parameters.
        SCORES = xinsheyang3(X, beta=BETA) computes the function with the given
        value of BETA for its 'beta' parameter. In this case, the default value
        of 'm=5' will be used for the parameter.
        SCORES = xinsheyang3(X, beta=BETA, m=M) computes the function with the given
        value of M for its 'm' parameter.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (0, 0, ..., 0)
        - Number of dimensions: n (Scalable)
        - Recommended domain: x_i ∈ [-2π, 2π]
        - Number of local minima: Numerous (Highly periodic)
        - Number of global minima: 1
        - Convexity: Non-convex
        - Separability: Separable (The terms for each x_i are summed)
        - Modality: Highly Multimodal
        - Symmetry: Symmetric
        - Differentiable: Yes
        For more information, please visit:
        benchmarkfcns.info/doc/xinsheyangn3fcn
    )pbdoc");

    m.def("xinsheyangn4", &xinsheyangn4, R"pbdoc(
        Computes the value of the Xin-She Yang N. 4 function.
        SCORES = xinsheyang4(X) computes the value of the Xin-She Yang N. 4
        function at point X. `xinsheyang4` accepts a matrix of size M-by-N and
        returns a vector SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (0, 0, ..., 0)
        - Number of dimensions: n (Scalable)
        - Recommended domain: x_i ∈ [-10, 10]
        - Number of local minima: Numerous (Highly oscillatory)
        - Number of global minima: 1
        - Convexity: Non-convex
        - Separability: Non-separable
        - Modality: Highly Multimodal
        - Symmetry: Symmetric
        - Differentiable: No
        For more information, please visit:
        benchmarkfcns.info/doc/xinsheyangn4fcn
    )pbdoc");

    m.def("zakharov", &zakharov, R"pbdoc(
        Computes the value of Zakharov benchmark function.
        SCORES = zakharov(X) computes the value of the Zakharov function at
        point X. `zakharov` accepts a matrix of size M-by-N and returns a vector
        SCORES of size M-by-1 in which each row contains the function value for
        each row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: 0
        - Number of dimensions: n (Scalable)
        - Recommended domain: [-5, 10] or [-10, 10]
        - Number of local minima: 0
        - Number of global minima: 1
        - Convexity: Convex
        - Separability: Non-separable (The squared summation term couples all variables
            together)
        - Modality: Unimodal
        - Symmetry: Non-symmetric (Due to the 0.5i weight in the summation)
        - Differentiable: Yes
        For more information, please visit:
        benchmarkfcns.info/doc/zakharovfcn
    )pbdoc");

    m.def("zerosum", &zerosum, R"pbdoc(
        Computes the value of the Zero Sum benchmark function.
        SCORES = zerosum(X) computes the value of the Zero Sum function at
        point X. `zerosum` accepts a matrix of size M-by-N and returns a vector
        SCORES of size M-by-1 in which each row contains the function value for
        the corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: Any point where $\sum_{i=1}^{n} x_i = 0$ (e.g.,
            (1, -1) or (5, -2, -3))
        - Number of dimensions: n
        - Recommended domain: [-10, 10]^n
        - Number of local minima: 0 (Technically, it is constant everywhere else)
        - Number of global minima: Infinite (Any point on the hyperplane defined by the
            sum equal to zero)
        - Convexity: Non-convex
        - Separability: Non-separable (The variables must sum to a specific value)
        - Modality: Unimodal (in terms of the target hyperplane)
        - Differentiable: No (The function "jumps" from values > 1 down to 0 instantly)
    )pbdoc");

    m.def("zettel", &zettel, R"pbdoc(
        Computes the value of the Zettel function.
        SCORES = zettel(X) computes the value of the Zettel function at point X.
        `zettel` accepts a matrix of size M-by-2 and returns a vector SCORES of
        size M-by-1 in which each row contains the function value for the
        corresponding row of X.
        Properties:
        - Global minimum: -0.003791
        - Location of global minimum: (-0.02989, 0)
        - Number of dimensions: 2
        - Recommended domain: [-5, 5]^2
        - Number of local minima: 0 (It is unimodal)
        - Number of global minima: 1
        - Convexity: Non-convex (despite being unimodal, the "skew" makes it non-convex)
        - Separability: Non-separable (The x_1 and x_2 terms are combined inside the
            squared term)
        - Modality: Unimodal
        - Differentiable: Yes
    )pbdoc");

    m.def("zimmerman", &zimmerman, R"pbdoc(
        Computes the value of the Zimmerman benchmark function.
        SCORES = zimmerman(X) computes the value of the Zimmerman function at
        point X. `zimmerman` accepts a matrix of size M-by-2 and returns a vector
        SCORES of size M-by-1 in which each row contains the function value for
        the corresponding row of X.
        Properties:
        - Global minimum: 0
        - Location of global minimum: (7, 2)
        - Number of dimensions: 2
        - Recommended domain: [0, 100]^2
        - Number of local minima: dependent on the penalty factor Z_p, but can have
            several "pseudo-minima" along the constraint boundaries.
        - Number of global minima: 1
        - Convexity: non-convex
        - Separability: non-separable
        - Modality: multimodal
        - Symmetry: non-symmetric
        - Differentiable: Yes (except potentially at the constraint boundaries, where the
            penalty term can introduce non-differentiability, but the function is usually
            well-behaved in practice)
    )pbdoc");

    m.def("zirilli", &zirilli, R"pbdoc(
        Computes the value of the Zirilli function.
        SCORES = zirilli(X) computes the value of the Zirilli function at point X.
        `zirilli` accepts a matrix of size M-by-2 and returns a vector SCORES of
        size M-by-1 in which each row contains the function value for the
        corresponding row of X.
        Properties:
        - Global minimum: -0.3523
        - Location of global minimum: (-1.0465, 0)
        - Number of dimensions: 2
        - Recommended domain: [-10, 10]^2
        - Number of local minima: 2 (one global minimum and one local minimum)
        - Number of global minima: 1
        - Convexity: non-convex
        - Separability: separable
        - Modality: multimodal
        - Symmetry: non-symmetric
        - Differentiable: Yes
    )pbdoc");

    m.def("get_function_ptr", &get_function_ptr, py::arg("name"), "Retrieves a benchmark function pointer by name.");

    py::class_<Composition>(m, "Composition")
        .def(py::init<>())
        .def("add_component", &Composition::add_component,
            py::arg("fcn"), py::arg("shift"), py::arg("rotation"),
            py::arg("sigma"), py::arg("lambda"), py::arg("bias"), py::arg("f_max"),
            "Adds a base function component to the composition.")
        .def("evaluate", &Composition::evaluate, py::arg("x"),
            "Evaluates the composed function for a batch of points.")
        .def("set_constant_C", &Composition::set_constant_C, py::arg("C"),
            "Sets the C constant for height normalization (default 2000.0).");

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}
