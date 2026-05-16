#include <pybind11/eigen.h>
#include <pybind11/functional.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

#include "benchmarkfcns.h"
#include "cec.h"
#include "composition.h"
#include "multifidelity.h"
#include "multiobjective.h"

using namespace BenchmarkFcns;

namespace py = pybind11;

PYBIND11_MODULE(_core, m) {
    py::module_ mom = m.def_submodule("multiobjective", "Multi-objective functions");

    mom.def("bnh", &MultiObjective::bnh, py::arg("x"), py::arg("return_constraints") = false,
            R"pbdoc(
        Computes the value of the BNH (Binh and Korn) multi-objective benchmark function.
        SCORES = multiobjective.bnh(X) computes the value of the BNH function
        at point X. `multiobjective.bnh` accepts a matrix of size M-by-2 and returns
        a matrix SCORES of size M-by-2.
        If return_constraints is True, returns an M-by-4 matrix where the last two columns
        contain the constraint violations (values > 0 are violations).
        Properties:

        - Recommended domain: x1 in [0, 5], x2 in [0, 3]
    )pbdoc");

    mom.def("cf1", &MultiObjective::cf1, py::arg("x"), py::arg("return_constraints") = false,
            R"pbdoc(
        Computes the value of the CEC 2009 CF1 constrained multi-objective benchmark function.
        SCORES = multiobjective.cf1(X) computes the value of the CF1 function
        at point X. `multiobjective.cf1` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-2.
        If return_constraints is True, returns an M-by-3 matrix where the last column
        contains the constraint violation (values > 0 are violations).
        Properties:

        - Recommended domain: x1 in [0, 1], xj in [-1, 1] for j=2..N
    )pbdoc");

    mom.def("cf2", &MultiObjective::cf2, py::arg("x"), py::arg("return_constraints") = false,
            R"pbdoc(
        Computes the value of the CEC 2009 CF2 constrained multi-objective benchmark function.
        SCORES = multiobjective.cf2(X) computes the value of the CF2 function
        at point X. `multiobjective.cf2` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-2.
        If return_constraints is True, returns an M-by-3 matrix where the last column
        contains the constraint violation (values > 0 are violations).
        Properties:

        - Recommended domain: x1 in [0, 1], xj in [-1, 1] for j=2..N
    )pbdoc");

    mom.def("cf3", &MultiObjective::cf3, py::arg("x"), py::arg("return_constraints") = false,
            R"pbdoc(
        Computes the value of the CEC 2009 CF3 constrained multi-objective benchmark function.
        SCORES = multiobjective.cf3(X) computes the value of the CF3 function
        at point X. `multiobjective.cf3` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-2.
        If return_constraints is True, returns an M-by-3 matrix where the last column
        contains the constraint violation (values > 0 are violations).
        Properties:

        - Recommended domain: x1 in [0, 1], xj in [-1, 1] for j=2..N
    )pbdoc");

    mom.def("cf4", &MultiObjective::cf4, py::arg("x"), py::arg("return_constraints") = false,
            R"pbdoc(
        Computes the value of the CEC 2009 CF4 constrained multi-objective benchmark function.
        SCORES = multiobjective.cf4(X) computes the value of the CF4 function
        at point X. `multiobjective.cf4` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-2.
        If return_constraints is True, returns an M-by-3 matrix where the last column
        contains the constraint violation (values > 0 are violations).
        Properties:

        - Recommended domain: x1 in [0, 1], xj in [-2, 2] for j=2..N
    )pbdoc");

    mom.def("cf5", &MultiObjective::cf5, py::arg("x"), py::arg("return_constraints") = false,
            R"pbdoc(
        Computes the value of the CEC 2009 CF5 constrained multi-objective benchmark function.
        SCORES = multiobjective.cf5(X) computes the value of the CF5 function
        at point X. `multiobjective.cf5` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-2.
        If return_constraints is True, returns an M-by-3 matrix where the last column
        contains the constraint violation (values > 0 are violations).
        Properties:

        - Recommended domain: x1 in [0, 1], xj in [-2, 2] for j=2..N
    )pbdoc");

    mom.def("cf6", &MultiObjective::cf6, py::arg("x"), py::arg("return_constraints") = false,
            R"pbdoc(
        Computes the value of the CEC 2009 CF6 constrained multi-objective benchmark function.
        SCORES = multiobjective.cf6(X) computes the value of the CF6 function
        at point X. `multiobjective.cf6` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-2.
        If return_constraints is True, returns an M-by-4 matrix where the last two columns
        contain the constraint violations (values > 0 are violations).
        Properties:

        - Recommended domain: x1 in [0, 1], xj in [-2, 2] for j=2..N
    )pbdoc");

    mom.def("cf7", &MultiObjective::cf7, py::arg("x"), py::arg("return_constraints") = false,
            R"pbdoc(
        Computes the value of the CEC 2009 CF7 constrained multi-objective benchmark function.
        SCORES = multiobjective.cf7(X) computes the value of the CF7 function
        at point X. `multiobjective.cf7` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-2.
        If return_constraints is True, returns an M-by-4 matrix where the last two columns
        contain the constraint violations (values > 0 are violations).
        Properties:

        - Recommended domain: x1 in [0, 1], xj in [-2, 2] for j=2..N
    )pbdoc");

    mom.def("cf8", &MultiObjective::cf8, py::arg("x"), py::arg("return_constraints") = false,
            R"pbdoc(
        Computes the value of the CEC 2009 CF8 constrained multi-objective benchmark function.
        SCORES = multiobjective.cf8(X) computes the value of the CF8 function
        at point X. `multiobjective.cf8` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-3.
        If return_constraints is True, returns an M-by-4 matrix where the last column
        contains the constraint violation (values > 0 are violations).
        Properties:

        - Recommended domain: x1, x2 in [0, 1], xj in [-2, 2] for j=3..N
    )pbdoc");

    mom.def("cf9", &MultiObjective::cf9, py::arg("x"), py::arg("return_constraints") = false,
            R"pbdoc(
        Computes the value of the CEC 2009 CF9 constrained multi-objective benchmark function.
        SCORES = multiobjective.cf9(X) computes the value of the CF9 function
        at point X. `multiobjective.cf9` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-3.
        If return_constraints is True, returns an M-by-4 matrix where the last column
        contains the constraint violation (values > 0 are violations).
        Properties:

        - Recommended domain: x1, x2 in [0, 1], xj in [-2, 2] for j=3..N
    )pbdoc");

    mom.def("cf10", &MultiObjective::cf10, py::arg("x"), py::arg("return_constraints") = false,
            R"pbdoc(
        Computes the value of the CEC 2009 CF10 constrained multi-objective benchmark function.
        SCORES = multiobjective.cf10(X) computes the value of the CF10 function
        at point X. `multiobjective.cf10` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-3.
        If return_constraints is True, returns an M-by-4 matrix where the last column
        contains the constraint violation (values > 0 are violations).
        Properties:

        - Recommended domain: x1, x2 in [0, 1], xj in [-2, 2] for j=3..N
    )pbdoc");

    mom.def("deb", &MultiObjective::deb, py::arg("x"), R"pbdoc(
        Computes the value of the DEB (ZDT3 alias) multi-objective benchmark function.
        SCORES = multiobjective.deb(X) computes the value of the DEB function
        at point X. `multiobjective.deb` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-2.
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

    mom.def("dtlz4", MultiObjective::dtlz4, py::arg("x"), py::arg("num_objectives") = 3,
            py::arg("alpha") = 100.0, R"pbdoc(
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

    mom.def("kita", &MultiObjective::kita, py::arg("x"), py::arg("return_constraints") = false,
            R"pbdoc(
        Computes the value of the KITA bi-objective benchmark function.
        SCORES = multiobjective.kita(X) computes the value of the KITA function
        at point X. `multiobjective.kita` accepts a matrix of size M-by-2 and returns
        a matrix SCORES of size M-by-2.
        If return_constraints is True, returns an M-by-5 matrix where the last three columns
        contain the constraint violations (values > 0 are violations).
        Properties:

        - Recommended domain: x1, x2 in [0, 7]
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

    mom.def("maf1", &MultiObjective::maf1, py::arg("x"), py::arg("num_objectives") = 3, R"pbdoc(
        Computes the value of the MaF1 multi-objective benchmark function.
        SCORES = multiobjective.maf1(X) computes the value of the function at point X.
        `maf1` is an inverted version of DTLZ1.
    )pbdoc");

    mom.def("maf2", &MultiObjective::maf2, py::arg("x"), py::arg("num_objectives") = 3, R"pbdoc(
        Computes the value of the MaF2 multi-objective benchmark function.
        `maf2` is a modified DTLZ2 (DTLZ2BZ).
    )pbdoc");

    mom.def("maf3", &MultiObjective::maf3, py::arg("x"), py::arg("num_objectives") = 3, R"pbdoc(
        Computes the value of the MaF3 multi-objective benchmark function.
        `maf3` is a convex DTLZ3 variant.
    )pbdoc");

    mom.def("maf4", &MultiObjective::maf4, py::arg("x"), py::arg("num_objectives") = 3, R"pbdoc(
        Computes the value of the MaF4 multi-objective benchmark function.
        `maf4` is an inverted DTLZ3 variant.
    )pbdoc");

    mom.def("maf5", &MultiObjective::maf5, py::arg("x"), py::arg("num_objectives") = 3, R"pbdoc(
        Computes the value of the MaF5 multi-objective benchmark function.
        `maf5` is a badly scaled DTLZ4 variant.
    )pbdoc");

    mom.def("maf6", &MultiObjective::maf6, py::arg("x"), py::arg("num_objectives") = 3, R"pbdoc(
        Computes the value of the MaF6 multi-objective benchmark function.
        `maf6` is a degenerate DTLZ5 variant.
    )pbdoc");

    mom.def("maf7", &MultiObjective::maf7, py::arg("x"), py::arg("num_objectives") = 3, R"pbdoc(
        Computes the value of the MaF7 multi-objective benchmark function.
        `maf7` is a disconnected DTLZ7 variant.
    )pbdoc");

    mom.def("maf8", &MultiObjective::maf8, py::arg("x"), py::arg("num_objectives") = 3, R"pbdoc(
        Computes the value of the MaF8 (Point-to-Line) multi-objective benchmark function.
    )pbdoc");

    mom.def("maf9", &MultiObjective::maf9, py::arg("x"), py::arg("num_objectives") = 3, R"pbdoc(
        Computes the value of the MaF9 (Point-to-Surface) multi-objective benchmark function.
    )pbdoc");

    mom.def("maf10", &MultiObjective::maf10, py::arg("x"), py::arg("num_objectives") = 3,
            py::arg("k") = -1, R"pbdoc(
        Computes the value of the MaF10 (Modified WFG1) multi-objective benchmark function.
    )pbdoc");

    mom.def("mop1", &MultiObjective::mop1, py::arg("x"), R"pbdoc(
        Computes the value of the MOP1 (Schaffer N. 1) multi-objective benchmark function.
        SCORES = multiobjective.mop1(X) computes the value of the MOP1 function
        at point X. `multiobjective.mop1` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-2.
        Properties:

        - f1 = x^2, f2 = (x-2)^2
        - Recommended domain: [-10, 10]
    )pbdoc");

    mom.def("mop2", &MultiObjective::mop2, py::arg("x"), R"pbdoc(
        Computes the value of the MOP2 (Fonseca-Fleming alias) multi-objective benchmark function.
        SCORES = multiobjective.mop2(X) computes the value of the MOP2 function
        at point X. `multiobjective.mop2` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-2.
    )pbdoc");

    mom.def("mop3", &MultiObjective::mop3, py::arg("x"), R"pbdoc(
        Computes the value of the MOP3 (Poloni alias) multi-objective benchmark function.
        SCORES = multiobjective.mop3(X) computes the value of the MOP3 function
        at point X. `multiobjective.mop3` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-2.
    )pbdoc");

    mom.def("mop4", &MultiObjective::mop4, py::arg("x"), R"pbdoc(
        Computes the value of the MOP4 (Kursawe alias) multi-objective benchmark function.
        SCORES = multiobjective.mop4(X) computes the value of the MOP4 function
        at point X. `multiobjective.mop4` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-2.
    )pbdoc");

    mom.def("mop5", &MultiObjective::mop5, py::arg("x"), R"pbdoc(
        Computes the value of the MOP5 (Viennet1 alias) multi-objective benchmark function.
        SCORES = multiobjective.mop5(X) computes the value of the MOP5 function
        at point X. `multiobjective.mop5` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-3.
    )pbdoc");

    mom.def("mop6", &MultiObjective::mop6, py::arg("x"), R"pbdoc(
        Computes the value of the MOP6 (ZDT3 alias) multi-objective benchmark function.
        SCORES = multiobjective.mop6(X) computes the value of the MOP6 function
        at point X. `multiobjective.mop6` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-2.
    )pbdoc");

    mom.def("mop7", &MultiObjective::mop7, py::arg("x"), R"pbdoc(
        Computes the value of the MOP7 (Viennet3 alias) multi-objective benchmark function.
        SCORES = multiobjective.mop7(X) computes the value of the MOP7 function
        at point X. `multiobjective.mop7` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-3.
    )pbdoc");

    mom.def("oka1", &MultiObjective::oka1, py::arg("x"), R"pbdoc(
        Computes the value of the OKA1 bi-objective benchmark function.
        SCORES = multiobjective.oka1(X) computes the value of the OKA1 function
        at point X. `multiobjective.oka1` accepts a matrix of size M-by-2 and returns
        a matrix SCORES of size M-by-2.
        Properties:

        - Recommended domain: x1 in [6*sin(pi/12), 6*sin(pi/12) + 2*pi*cos(pi/12)], x2 in [-2*pi*sin(pi/12), 6*cos(pi/12)]
    )pbdoc");

    mom.def("oka2", &MultiObjective::oka2, py::arg("x"), R"pbdoc(
        Computes the value of the OKA2 bi-objective benchmark function.
        SCORES = multiobjective.oka2(X) computes the value of the OKA2 function
        at point X. `multiobjective.oka2` accepts a matrix of size M-by-3 and returns
        a matrix SCORES of size M-by-2.
        Properties:

        - Recommended domain: x1 in [-pi, pi], x2, x3 in [-5, 5]
    )pbdoc");

    mom.def("osyczkakundu", &MultiObjective::osyczkakundu, py::arg("x"),
            py::arg("return_constraints") = false, R"pbdoc(
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

    mom.def("tanaka", &MultiObjective::tanaka, py::arg("x"), py::arg("return_constraints") = false,
            R"pbdoc(
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

    mom.def("uf1", &MultiObjective::uf1, py::arg("x"), R"pbdoc(
        Computes the value of the CEC 2009 UF1 multi-objective benchmark function.
        SCORES = multiobjective.uf1(X) computes the value of the UF1 function
        at point X. `multiobjective.uf1` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-2.
        Properties:

        - Recommended domain: x1 in [0, 1], xj in [-1, 1] for j=2..N
        - Pareto front: Convex
    )pbdoc");

    mom.def("uf2", &MultiObjective::uf2, py::arg("x"), R"pbdoc(
        Computes the value of the CEC 2009 UF2 multi-objective benchmark function.
        SCORES = multiobjective.uf2(X) computes the value of the UF2 function
        at point X. `multiobjective.uf2` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-2.
        Properties:

        - Recommended domain: x1 in [0, 1], xj in [-1, 1] for j=2..N
    )pbdoc");

    mom.def("uf3", &MultiObjective::uf3, py::arg("x"), R"pbdoc(
        Computes the value of the CEC 2009 UF3 multi-objective benchmark function.
        SCORES = multiobjective.uf3(X) computes the value of the UF3 function
        at point X. `multiobjective.uf3` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-2.
        Properties:

        - Recommended domain: x in [0, 1]^N
    )pbdoc");

    mom.def("uf4", &MultiObjective::uf4, py::arg("x"), R"pbdoc(
        Computes the value of the CEC 2009 UF4 multi-objective benchmark function.
        SCORES = multiobjective.uf4(X) computes the value of the UF4 function
        at point X. `multiobjective.uf4` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-2.
        Properties:

        - Recommended domain: x1 in [0, 1], xj in [-2, 2] for j=2..N
        - Pareto front: Concave
    )pbdoc");

    mom.def("uf5", &MultiObjective::uf5, py::arg("x"), R"pbdoc(
        Computes the value of the CEC 2009 UF5 multi-objective benchmark function.
        SCORES = multiobjective.uf5(X) computes the value of the UF5 function
        at point X. `multiobjective.uf5` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-2.
        Properties:

        - Recommended domain: x1 in [0, 1], xj in [-1, 1] for j=2..N
        - Pareto front: Linear with 21 points
    )pbdoc");

    mom.def("uf6", &MultiObjective::uf6, py::arg("x"), R"pbdoc(
        Computes the value of the CEC 2009 UF6 multi-objective benchmark function.
        SCORES = multiobjective.uf6(X) computes the value of the UF6 function
        at point X. `multiobjective.uf6` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-2.
        Properties:

        - Recommended domain: x1 in [0, 1], xj in [-1, 1] for j=2..N
        - Pareto front: Disconnected
    )pbdoc");

    mom.def("uf7", &MultiObjective::uf7, py::arg("x"), R"pbdoc(
        Computes the value of the CEC 2009 UF7 multi-objective benchmark function.
        SCORES = multiobjective.uf7(X) computes the value of the UF7 function
        at point X. `multiobjective.uf7` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-2.
        Properties:

        - Recommended domain: x1 in [0, 1], xj in [-1, 1] for j=2..N
        - Pareto front: Linear
    )pbdoc");

    mom.def("uf8", &MultiObjective::uf8, py::arg("x"), R"pbdoc(
        Computes the value of the CEC 2009 UF8 multi-objective benchmark function.
        SCORES = multiobjective.uf8(X) computes the value of the UF8 function
        at point X. `multiobjective.uf8` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-3.
        Properties:

        - Recommended domain: x1, x2 in [0, 1], xj in [-2, 2] for j=3..N
    )pbdoc");

    mom.def("uf9", &MultiObjective::uf9, py::arg("x"), R"pbdoc(
        Computes the value of the CEC 2009 UF9 multi-objective benchmark function.
        SCORES = multiobjective.uf9(X) computes the value of the UF9 function
        at point X. `multiobjective.uf9` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-3.
        Properties:

        - Recommended domain: x1, x2 in [0, 1], xj in [-2, 2] for j=3..N
    )pbdoc");

    mom.def("uf10", &MultiObjective::uf10, py::arg("x"), R"pbdoc(
        Computes the value of the CEC 2009 UF10 multi-objective benchmark function.
        SCORES = multiobjective.uf10(X) computes the value of the UF10 function
        at point X. `multiobjective.uf10` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-3.
        Properties:

        - Recommended domain: x1, x2 in [0, 1], xj in [-2, 2] for j=3..N
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

    mom.def("wfg1", MultiObjective::wfg1, py::arg("x"), py::arg("num_objectives") = 3,
            py::arg("k") = 4, R"pbdoc(
        Computes the value of the WFG1 multi-objective benchmark function.
        SCORES = multiobjective.wfg1(X, num_objectives, k) computes the value of the WFG1 function
        at point X. `multiobjective.wfg1` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-K where K is the number of objectives.
        Properties:

        - Domain: x_i in [0, 2i]
        - Shape: mixed and convex
    )pbdoc");

    mom.def("wfg2", MultiObjective::wfg2, py::arg("x"), py::arg("num_objectives") = 3,
            py::arg("k") = 4, R"pbdoc(
        Computes the value of the WFG2 multi-objective benchmark function.
        SCORES = multiobjective.wfg2(X, num_objectives, k) computes the value of the WFG2 function
        at point X. `multiobjective.wfg2` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-K where K is the number of objectives.
        Properties:

        - Domain: x_i in [0, 2i]
        - Shape: convex and disconnected
    )pbdoc");

    mom.def("wfg3", MultiObjective::wfg3, py::arg("x"), py::arg("num_objectives") = 3,
            py::arg("k") = 4, R"pbdoc(
        Computes the value of the WFG3 multi-objective benchmark function.
        SCORES = multiobjective.wfg3(X, num_objectives, k) computes the value of the WFG3 function
        at point X. `multiobjective.wfg3` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-K where K is the number of objectives.
        Properties:

        - Domain: x_i in [0, 2i]
        - Shape: linear (degenerate)
    )pbdoc");

    mom.def("wfg4", MultiObjective::wfg4, py::arg("x"), py::arg("num_objectives") = 3,
            py::arg("k") = 4, R"pbdoc(
        Computes the value of the WFG4 multi-objective benchmark function.
        SCORES = multiobjective.wfg4(X, num_objectives, k) computes the value of the WFG4 function
        at point X. `multiobjective.wfg4` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-K where K is the number of objectives.
        Properties:

        - Domain: x_i in [0, 2i]
        - Shape: concave
    )pbdoc");

    mom.def("wfg5", MultiObjective::wfg5, py::arg("x"), py::arg("num_objectives") = 3,
            py::arg("k") = 4, R"pbdoc(
        Computes the value of the WFG5 multi-objective benchmark function.
        SCORES = multiobjective.wfg5(X, num_objectives, k) computes the value of the WFG5 function
        at point X. `multiobjective.wfg5` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-K where K is the number of objectives.
        Properties:

        - Domain: x_i in [0, 2i]
        - Shape: concave
    )pbdoc");

    mom.def("wfg6", MultiObjective::wfg6, py::arg("x"), py::arg("num_objectives") = 3,
            py::arg("k") = 4, R"pbdoc(
        Computes the value of the WFG6 multi-objective benchmark function.
        SCORES = multiobjective.wfg6(X, num_objectives, k) computes the value of the WFG6 function
        at point X. `multiobjective.wfg6` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-K where K is the number of objectives.
        Properties:

        - Domain: x_i in [0, 2i]
        - Shape: concave
    )pbdoc");

    mom.def("wfg7", MultiObjective::wfg7, py::arg("x"), py::arg("num_objectives") = 3,
            py::arg("k") = 4, R"pbdoc(
        Computes the value of the WFG7 multi-objective benchmark function.
        SCORES = multiobjective.wfg7(X, num_objectives, k) computes the value of the WFG7 function
        at point X. `multiobjective.wfg7` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-K where K is the number of objectives.
        Properties:

        - Domain: x_i in [0, 2i]
        - Shape: concave
    )pbdoc");

    mom.def("wfg8", MultiObjective::wfg8, py::arg("x"), py::arg("num_objectives") = 3,
            py::arg("k") = 4, R"pbdoc(
        Computes the value of the WFG8 multi-objective benchmark function.
        SCORES = multiobjective.wfg8(X, num_objectives, k) computes the value of the WFG8 function
        at point X. `multiobjective.wfg8` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-K where K is the number of objectives.
        Properties:

        - Domain: x_i in [0, 2i]
        - Shape: concave
    )pbdoc");

    mom.def("wfg9", MultiObjective::wfg9, py::arg("x"), py::arg("num_objectives") = 3,
            py::arg("k") = 4, R"pbdoc(
        Computes the value of the WFG9 multi-objective benchmark function.
        SCORES = multiobjective.wfg9(X, num_objectives, k) computes the value of the WFG9 function
        at point X. `multiobjective.wfg9` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-K where K is the number of objectives.
        Properties:

        - Domain: x_i in [0, 2i]
        - Shape: concave
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

    mfm.def("ackley", MultiFidelity::ackley, R"pbdoc(
        Computes the value of the multi-fidelity Ackley function.
        SCORES = ackley(X) computes the value of the Ackley function
        at point X. `multifidelity.ackley` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-2.
    )pbdoc");

    mfm.def("adjiman", MultiFidelity::adjiman, R"pbdoc(
        Computes the value of the multi-fidelity Adjiman function.
        SCORES = adjiman(X) computes the value of the Adjiman function
        at point X. `multifidelity.adjiman` accepts a matrix of size M-by-2 and returns
        a matrix SCORES of size M-by-2.
    )pbdoc");

    mfm.def("alpinen1", MultiFidelity::alpinen1, R"pbdoc(
        Computes the value of the multi-fidelity Alpine N. 1 function.
        SCORES = alpinen1(X) computes the value of the Alpine N. 1 function
        at point X. `multifidelity.alpinen1` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-2.
    )pbdoc");

    mfm.def("bartelsconn", MultiFidelity::bartelsconn, R"pbdoc(
        Computes the value of the multi-fidelity Bartels Conn function.
        SCORES = bartelsconn(X) computes the value of the Bartels Conn function
        at point X. `multifidelity.bartelsconn` accepts a matrix of size M-by-2 and returns
        a matrix SCORES of size M-by-2.
    )pbdoc");

    mfm.def("beale", MultiFidelity::beale, R"pbdoc(
        Computes the value of the multi-fidelity Beale function.
        SCORES = beale(X) computes the value of the Beale function
        at point X. `multifidelity.beale` accepts a matrix of size M-by-2 and returns
        a matrix SCORES of size M-by-2.
    )pbdoc");

    mfm.def("bentcigar", MultiFidelity::bentcigar, R"pbdoc(
        Computes the value of the multi-fidelity Bent Cigar function.
        SCORES = bentcigar(X) computes the value of the Bent Cigar function
        at point X. `multifidelity.bentcigar` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-2.
    )pbdoc");

    mfm.def("bird", MultiFidelity::bird, R"pbdoc(
        Computes the value of the multi-fidelity Bird function.
        SCORES = bird(X) computes the value of the Bird function
        at point X. `multifidelity.bird` accepts a matrix of size M-by-2 and returns
        a matrix SCORES of size M-by-2.
    )pbdoc");

    mfm.def("bohachevskyn1", MultiFidelity::bohachevskyn1, R"pbdoc(
        Computes the value of the multi-fidelity Bohachevsky N. 1 function.
        SCORES = bohachevskyn1(X) computes the value of the Bohachevsky N. 1 function
        at point X. `multifidelity.bohachevskyn1` accepts a matrix of size M-by-2 and returns
        a matrix SCORES of size M-by-2.
    )pbdoc");

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

    mfm.def("borehole", MultiFidelity::borehole, R"pbdoc(
        Computes the value of the multi-fidelity Borehole function.
        SCORES = borehole(X) computes the value of the Borehole function
        at point X. `multifidelity.borehole` accepts a matrix of size M-by-8 and returns
        a matrix SCORES of size M-by-2.
        Properties (High-fidelity):

        - Dimensions: 8
        - Recommended domain: rw in [0.05, 0.15], r in [100, 50000], Tu in [63070, 115600],
          Hu in [990, 1110], Tl in [63.1, 116], Hl in [700, 820], L in [1120, 1680],
          Kw in [9855, 12045].
    )pbdoc");

    mfm.def("branin", MultiFidelity::branin, R"pbdoc(
        Computes the value of the multi-fidelity Branin function.
        SCORES = branin(X) computes the value of the Branin function
        at point X. `multifidelity.branin` accepts a matrix of size M-by-2 and returns
        a matrix SCORES of size M-by-2.
        Properties (High-fidelity):

        - Dimensions: 2
        - Recommended domain: [-5, 10] x [0, 15]
    )pbdoc");

    mfm.def("brown", MultiFidelity::brown, R"pbdoc(
        Computes the value of the multi-fidelity Brown function.
        SCORES = brown(X) computes the value of the Brown function
        at point X. `multifidelity.brown` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-2.
    )pbdoc");

    mfm.def("bukinn6", MultiFidelity::bukinn6, R"pbdoc(
        Computes the value of the multi-fidelity Bukin N. 6 function.
        SCORES = bukinn6(X) computes the value of the Bukin N. 6 function
        at point X. `multifidelity.bukinn6` accepts a matrix of size M-by-2 and returns
        a matrix SCORES of size M-by-2.
    )pbdoc");

    mfm.def("crossintray", MultiFidelity::crossintray, R"pbdoc(
        Computes the value of the multi-fidelity Cross-in-tray function.
        SCORES = crossintray(X) computes the value of the Cross-in-tray function
        at point X. `multifidelity.crossintray` accepts a matrix of size M-by-2 and returns
        a matrix SCORES of size M-by-2.
    )pbdoc");

    mfm.def("currin", MultiFidelity::currin, R"pbdoc(
        Computes the value of the multi-fidelity Currin function.
        SCORES = currin(X) computes the value of the Currin function
        at point X. `multifidelity.currin` accepts a matrix of size M-by-2 and returns
        a matrix SCORES of size M-by-2.
        Properties (High-fidelity):

        - Dimensions: 2
        - Recommended domain: [0, 1]^2
    )pbdoc");

    mfm.def("discus", MultiFidelity::discus, R"pbdoc(
        Computes the value of the multi-fidelity Discus function.
        SCORES = discus(X) computes the value of the Discus function
        at point X. `multifidelity.discus` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-2.
    )pbdoc");

    mfm.def("dixonprice", MultiFidelity::dixonprice, R"pbdoc(
        Computes the value of the multi-fidelity Dixon-Price function.
        SCORES = dixonprice(X) computes the value of the Dixon-Price function
        at point X. `multifidelity.dixonprice` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-2.
    )pbdoc");

    mfm.def("easom", MultiFidelity::easom, R"pbdoc(
        Computes the value of the multi-fidelity Easom function.
        SCORES = easom(X) computes the value of the Easom function
        at point X. `multifidelity.easom` accepts a matrix of size M-by-2 and returns
        a matrix SCORES of size M-by-2.
    )pbdoc");

    mfm.def("eggholder", MultiFidelity::eggholder, R"pbdoc(
        Computes the value of the multi-fidelity Eggholder function.
        SCORES = eggholder(X) computes the value of the Eggholder function
        at point X. `multifidelity.eggholder` accepts a matrix of size M-by-2 and returns
        a matrix SCORES of size M-by-2.
    )pbdoc");

    mfm.def("elliptic", MultiFidelity::elliptic, R"pbdoc(
        Computes the value of the multi-fidelity Elliptic function.
        SCORES = elliptic(X) computes the value of the Elliptic function
        at point X. `multifidelity.elliptic` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-2.
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

    mfm.def("friedman", MultiFidelity::friedman, R"pbdoc(
        Computes the value of the multi-fidelity Friedman function.
        SCORES = friedman(X) computes the value of the Friedman function
        at point X. `multifidelity.friedman` accepts a matrix of size M-by-5 and returns
        a matrix SCORES of size M-by-2.
        Properties (High-fidelity):

        - Dimensions: 5
        - Recommended domain: [0, 1]^5
    )pbdoc");

    mfm.def("gano", MultiFidelity::gano, R"pbdoc(
        Computes the value of the multi-fidelity Gano function.
        SCORES = gano(X) computes the value of the Gano function
        at point X. `multifidelity.gano` accepts a matrix of size M-by-2 and returns
        a matrix SCORES of size M-by-4 (HF obj, HF constr, LF obj, LF constr).
    )pbdoc");

    mfm.def("goldsteinprice", MultiFidelity::goldsteinprice, R"pbdoc(
        Computes the value of the multi-fidelity Goldstein-Price function.
        SCORES = goldsteinprice(X) computes the value of the Goldstein-Price function
        at point X. `multifidelity.goldsteinprice` accepts a matrix of size M-by-2 and returns
        a matrix SCORES of size M-by-2.
    )pbdoc");

    mfm.def("griewank", MultiFidelity::griewank, R"pbdoc(
        Computes the value of the multi-fidelity Griewank function.
        SCORES = griewank(X) computes the value of the Griewank function
        at point X. `multifidelity.griewank` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-2.
    )pbdoc");

    mfm.def("happycat", MultiFidelity::happycat, R"pbdoc(
        Computes the value of the multi-fidelity Happy Cat function.
        SCORES = happycat(X) computes the value of the Happy Cat function
        at point X. `multifidelity.happycat` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-2.
    )pbdoc");

    mfm.def("heterogeneous", MultiFidelity::heterogeneous, R"pbdoc(
        Computes the value of the multi-fidelity Heterogeneous (Mainini) function.
        SCORES = heterogeneous(X) computes the value of the Heterogeneous function
        at point X. `multifidelity.heterogeneous` accepts a matrix of size M-by-1 and returns
        a matrix SCORES of size M-by-2.
    )pbdoc");

    mfm.def("himmelblau", MultiFidelity::himmelblau, R"pbdoc(
        Computes the value of the multi-fidelity Himmelblau function.
        SCORES = himmelblau(X) computes the value of the Himmelblau function
        at point X. `multifidelity.himmelblau` accepts a matrix of size M-by-2 and returns
        a matrix SCORES of size M-by-2.
    )pbdoc");

    mfm.def("katsuura", MultiFidelity::katsuura, R"pbdoc(
        Computes the value of the multi-fidelity Katsuura function.
        SCORES = katsuura(X) computes the value of the Katsuura function
        at point X. `multifidelity.katsuura` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-2.
    )pbdoc");

    mfm.def("levy", MultiFidelity::levy, R"pbdoc(
        Computes the value of the multi-fidelity Levy function.
        SCORES = levy(X) computes the value of the Levy function
        at point X. `multifidelity.levy` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-2.
    )pbdoc");

    mfm.def("matyas", MultiFidelity::matyas, R"pbdoc(
        Computes the value of the multi-fidelity Matyas function.
        SCORES = matyas(X) computes the value of the Matyas function
        at point X. `multifidelity.matyas` accepts a matrix of size M-by-2 and returns
        a matrix SCORES of size M-by-2.
    )pbdoc");

    mfm.def("michalewicz", MultiFidelity::michalewicz, R"pbdoc(
        Computes the value of the multi-fidelity Michalewicz function.
        SCORES = michalewicz(X) computes the value of the Michalewicz function
        at point X. `multifidelity.michalewicz` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-2.
    )pbdoc");

    mfm.def("otlcircuit", MultiFidelity::otlcircuit, R"pbdoc(
        Computes the value of the multi-fidelity OTL circuit function.
        SCORES = otlcircuit(X) computes the value of the OTL circuit function
        at point X. `multifidelity.otlcircuit` accepts a matrix of size M-by-6 and returns
        a matrix SCORES of size M-by-2.
        Properties (High-fidelity):

        - Dimensions: 6
        - Recommended domain: [50, 150] x [25, 70] x [0.5, 3] x [1.2, 2.5] x [0.25, 1.2] x [50, 300]
    )pbdoc");

    mfm.def("park91a", MultiFidelity::park91a, R"pbdoc(
        Computes the value of the multi-fidelity Park91a function.
        SCORES = park91a(X) computes the value of the Park91a function
        at point X. `multifidelity.park91a` accepts a matrix of size M-by-4 and returns
        a matrix SCORES of size M-by-2.
        Properties (High-fidelity):

        - Dimensions: 4
        - Recommended domain: [0, 1]^4
    )pbdoc");

    mfm.def("park91b", MultiFidelity::park91b, R"pbdoc(
        Computes the value of the multi-fidelity Park91b function.
        SCORES = park91b(X) computes the value of the Park91b function
        at point X. `multifidelity.park91b` accepts a matrix of size M-by-4 and returns
        a matrix SCORES of size M-by-2.
        Properties (High-fidelity):

        - Dimensions: 4
        - Recommended domain: [0, 1]^4
    )pbdoc");

    mfm.def("piston", MultiFidelity::piston, R"pbdoc(
        Computes the value of the multi-fidelity Piston function.
        SCORES = piston(X) computes the value of the Piston function
        at point X. `multifidelity.piston` accepts a matrix of size M-by-7 and returns
        a matrix SCORES of size M-by-2.
        Properties (High-fidelity):

        - Dimensions: 7
        - Recommended domain: [30, 60] x [0.005, 0.020] x [0.002, 0.010] x [1000, 5000] x [90000, 110000] x [290, 296] x [340, 360]
    )pbdoc");

    mfm.def("rastrigin", MultiFidelity::rastrigin, R"pbdoc(
        Computes the value of the multi-fidelity Rastrigin function.
        SCORES = rastrigin(X) computes the value of the Rastrigin function
        at point X. `multifidelity.rastrigin` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-2.
    )pbdoc");

    mfm.def("robotarm", MultiFidelity::robotarm, R"pbdoc(
        Computes the value of the multi-fidelity Robot Arm function.
        SCORES = robotarm(X) computes the value of the Robot Arm function
        at point X. `multifidelity.robotarm` accepts a matrix of size M-by-8 and returns
        a matrix SCORES of size M-by-2.
        Properties (High-fidelity):

        - Dimensions: 8
        - Recommended domain: L in [0, 1], theta in [0, 2pi]
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

    mfm.def("schwefel", MultiFidelity::schwefel, R"pbdoc(
        Computes the value of the multi-fidelity Schwefel function.
        SCORES = schwefel(X) computes the value of the Schwefel function
        at point X. `multifidelity.schwefel` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-2.
    )pbdoc");

    mfm.def("shubert", MultiFidelity::shubert, R"pbdoc(
        Computes the value of the multi-fidelity Shubert function.
        SCORES = shubert(X) computes the value of the Shubert function
        at point X. `multifidelity.shubert` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-2.
    )pbdoc");

    mfm.def("sixhumpcamel", MultiFidelity::sixhumpcamel, R"pbdoc(
        Computes the value of the multi-fidelity Six-hump Camel function.
        SCORES = sixhumpcamel(X) computes the value of the Six-hump Camel function
        at point X. `multifidelity.sixhumpcamel` accepts a matrix of size M-by-2 and returns
        a matrix SCORES of size M-by-2.
    )pbdoc");

    mfm.def("sphere", MultiFidelity::sphere, R"pbdoc(
        Computes the value of the multi-fidelity Sphere function.
        SCORES = sphere(X) computes the value of the Sphere function
        at point X. `multifidelity.sphere` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-2.
    )pbdoc");

    mfm.def("step", MultiFidelity::step, R"pbdoc(
        Computes the value of the multi-fidelity Step function.
        SCORES = step(X) computes the value of the Step function
        at point X. `multifidelity.step` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-2.
    )pbdoc");

    mfm.def("styblinskitank", MultiFidelity::styblinskitank, R"pbdoc(
        Computes the value of the multi-fidelity Styblinski-Tank function.
        SCORES = styblinskitank(X) computes the value of the Styblinski-Tank function
        at point X. `multifidelity.styblinskitank` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-2.
    )pbdoc");

    mfm.def("trid", MultiFidelity::trid, R"pbdoc(
        Computes the value of the multi-fidelity Trid function.
        SCORES = trid(X) computes the value of the Trid function
        at point X. `multifidelity.trid` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-2.
    )pbdoc");

    mfm.def("wingweight", MultiFidelity::wingweight, R"pbdoc(
        Computes the value of the multi-fidelity Wing Weight function.
        SCORES = wingweight(X) computes the value of the Wing Weight function
        at point X. `multifidelity.wingweight` accepts a matrix of size M-by-10 and returns
        a matrix SCORES of size M-by-2.
    )pbdoc");

    mfm.def("xiong1d", MultiFidelity::xiong1d, R"pbdoc(
        Computes the value of the multi-fidelity Xiong 1D function.
        SCORES = xiong1d(X) computes the value of the function
        at point X. `multifidelity.xiong1d` accepts a matrix of size M-by-1 and returns
        a matrix SCORES of size M-by-2.
    )pbdoc");

    mfm.def("zakharov", MultiFidelity::zakharov, R"pbdoc(
        Computes the value of the multi-fidelity Zakharov function.
        SCORES = zakharov(X) computes the value of the Zakharov function
        at point X. `multifidelity.zakharov` accepts a matrix of size M-by-N and returns
        a matrix SCORES of size M-by-2.
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

    m.def("ackley5", &ackley5, R"pbdoc(
        Computes the value of the Ackley N. 5 benchmark function.
        SCORES = ackley5(X) computes the value of the function at point X.
        `ackley5` accepts a matrix of size M-by-N and returns a vector SCORES of size M-by-1.
        Properties:

        - Global minimum: 0
        - Location of global minimum: (0, 0, ..., 0)
        - Number of dimensions: n
        - Recommended domain: [-32, 32]^n
        - Modality: multimodal
    )pbdoc");

    m.def("ackley6", &ackley6, R"pbdoc(
        Computes the value of the Ackley N. 6 benchmark function.
        SCORES = ackley6(X) computes the value of the function at point X.
        `ackley6` accepts a matrix of size M-by-N and returns a vector SCORES of size M-by-1.
        Properties:

        - Global minimum: 0
        - Location of global minimum: (0, 0, ..., 0)
        - Number of dimensions: n
        - Recommended domain: [-32, 32]^n
        - Modality: multimodal
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

    m.def("alpine3", &alpine3, R"pbdoc(
        Computes the value of the Alpine N. 3 benchmark function.
        SCORES = alpine3(X) computes the value of the function at point X.
        `alpine3` accepts a matrix of size M-by-N and returns a vector SCORES of size M-by-1.
        Properties:

        - Global minimum: 0
        - Location of global minimum: (0, 0, ..., 0)
        - Number of dimensions: n
        - Recommended domain: [-1, 1]^n
        - Modality: multimodal
    )pbdoc");

    m.def("alpine4", &alpine4, R"pbdoc(
        Computes the value of the Alpine N. 4 benchmark function.
        SCORES = alpine4(X) computes the value of the function at point X.
        `alpine4` accepts a matrix of size M-by-N and returns a vector SCORES of size M-by-1.
        Properties:

        - Global minimum: 0.1n
        - Location of global minimum: (0, 0, ..., 0)
        - Number of dimensions: n
        - Recommended domain: [-10, 10]^n
        - Modality: multimodal
    )pbdoc");

    m.def("alpine5", &alpine5, R"pbdoc(
        Computes the value of the Alpine N. 5 benchmark function.
        SCORES = alpine5(X) computes the value of the function at point X.
        `alpine5` accepts a matrix of size M-by-N and returns a vector SCORES of size M-by-1.
        Properties:

        - Global minimum: 0
        - Location of global minimum: (0, 0, ..., 0)
        - Number of dimensions: n
        - Recommended domain: [-10, 10]^n
        - Modality: multimodal
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

    m.def("baluja", &baluja, R"pbdoc(
        Computes the value of the Baluja (Schwefel 1.2) benchmark function.
        SCORES = baluja(X) computes the value of the Baluja function at
        point X. `baluja` accepts a matrix of size M-by-N and returns a
        vector SCORES of size M-by-1.
        Properties:

        - Global minimum: 0
        - Location of global minimum: (0, 0, ..., 0)
        - Number of dimensions: N
        - Recommended domain: [-100, 100]^N
        - Modality: unimodal
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

    m.def("bohachevskyn4", &bohachevskyn4, R"pbdoc(
        Computes the value of the Bohachevsky N. 4 benchmark function.
        SCORES = bohachevskyn4(X) computes the value of the function at point X.
        `bohachevskyn4` accepts a matrix of size M-by-N and returns a vector SCORES of size M-by-1.
        Properties:

        - Global minimum: 0
        - Location of global minimum: (0, 0, ..., 0)
        - Number of dimensions: n
        - Recommended domain: [-100, 100]^n
        - Modality: multimodal
    )pbdoc");

    m.def("bohachevskyn5", &bohachevskyn5, R"pbdoc(
        Computes the value of the Bohachevsky N. 5 benchmark function.
        SCORES = bohachevskyn5(X) computes the value of the function at point X.
        `bohachevskyn5` accepts a matrix of size M-by-N and returns a vector SCORES of size M-by-1.
        Properties:

        - Global minimum: 0
        - Location of global minimum: (0, 0, ..., 0)
        - Number of dimensions: n
        - Recommended domain: [-100, 100]^n
        - Modality: multimodal
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

    m.def("boxbetts", &boxbetts, R"pbdoc(
        Computes the value of the Box-Betts Quadratic Sum benchmark function.
        SCORES = boxbetts(X) computes the value of the Box-Betts function at
        point X. `boxbetts` accepts a matrix of size M-by-3 and returns a
        vector SCORES of size M-by-1.
        Properties:

        - Global minimum: 0
        - Location of global minimum: (1, 10, 1)
        - Number of dimensions: 3
        - Recommended domain: [0.9, 1.2] x [9, 11.2] x [0.9, 1.2]
        - Modality: multimodal
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

    m.def("brentn1", &brentn1, R"pbdoc(
        Computes the value of the Brent N. 1 benchmark function.
        `brentn1` is an alias for `brent`.
        Properties:

        - Global minimum: 0
        - Location of global minimum: (-10, -10)
        - Number of dimensions: 2
        - Recommended domain: [-10, 10]^2
        - Modality: unimodal
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

    m.def("bukinn1", &bukinn1, R"pbdoc(
        Computes the value of the Bukin N. 1 benchmark function.
        `bukinn1` is an alias for `bukinn6`.
        Properties:

        - Global minimum: 0
        - Location of global minimum: (-10, 1)
        - Number of dimensions: 2
        - Recommended domain: x1 in [-15, -5], x2 in [-3, 3]
        - Modality: multimodal
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

    m.def("bukinn3", &bukinn3, R"pbdoc(
        Computes the value of the Bukin N. 3 benchmark function.
        SCORES = bukinn3(X) computes the value of the function at point X.
        `bukinn3` accepts a matrix of size M-by-2 and returns a vector SCORES of size M-by-1.
        Properties:

        - Global minimum: 0
        - Location of global minimum: (-10, 1)
        - Number of dimensions: 2
        - Recommended domain: x1 in [-15, -5], x2 in [-3, 3]
        - Modality: multimodal
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

    m.def("bukinn5", &bukinn5, R"pbdoc(
        Computes the value of the Bukin N. 5 benchmark function.
        SCORES = bukinn5(X) computes the value of the function at point X.
        `bukinn5` accepts a matrix of size M-by-2 and returns a vector SCORES of size M-by-1.
        Properties:

        - Global minimum: 0
        - Location of global minimum: (-10, 1)
        - Number of dimensions: 2
        - Recommended domain: x1 in [-15, -5], x2 in [-3, 3]
        - Modality: multimodal
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

    m.def("chenbird", &chenbird, R"pbdoc(
        Computes the value of the Chen Bird (Multi-Modal) benchmark function.
        SCORES = chenbird(X) computes the value of the Chen Bird function at point X.
        `chenbird` accepts a matrix of size M-by-2 and returns a vector SCORES of size M-by-1.
        Properties:

        - Global minimum: -2000
        - Location of global minimum: (7/18, 13/18)
        - Number of dimensions: 2
        - Recommended domain: [-500, 500]^2
        - Modality: multimodal
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

    m.def("chichinadzen2", &chichinadzen2, R"pbdoc(
        Computes the value of the Chichinadze N. 2 benchmark function.
        SCORES = chichinadzen2(X) computes the value of the function at point X.
        `chichinadzen2` accepts a matrix of size M-by-2 and returns a vector SCORES of size M-by-1.
        Properties:

        - Global minimum: -42.944387
        - Location of global minimum: (6.189866, 0.5)
        - Number of dimensions: 2
        - Recommended domain: [-30, 30]^2
        - Modality: multimodal
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

    m.def("colville", &colville, R"pbdoc(
        Computes the value of the Colville benchmark function.
        SCORES = colville(X) computes the value of the Colville function at
        point X. `colville` accepts a matrix of size M-by-4 and returns a
        vector SCORES of size M-by-1.
        Properties:

        - Global minimum: 0
        - Location of global minimum: (1, 1, 1, 1)
        - Number of dimensions: 4
        - Recommended domain: [-10, 10]^4
        - Modality: unimodal
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

    m.def("crosslegintray", &crosslegintray, R"pbdoc(
        Computes the value of the Cross-Leg-in-Tray (Cross-Leg-Table) benchmark function.
        SCORES = crosslegintray(X) computes the value of the function at
        point X. `crosslegintray` accepts a matrix of size M-by-2 and returns a
        vector SCORES of size M-by-1.
        Properties:

        - Global minimum: -1
        - Location of global minimum: along x=0 or y=0 axes
        - Number of dimensions: 2
        - Recommended domain: [-10, 10]^2
        - Modality: multimodal
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

    m.def("damavandi", &damavandi, R"pbdoc(
        Computes the value of the Damavandi benchmark function.
        SCORES = damavandi(X) computes the value of the Damavandi function at
        point X. `damavandi` accepts a matrix of size M-by-2 and returns a
        vector SCORES of size M-by-1.
        Properties:

        - Global minimum: 0
        - Location of global minimum: (2, 2)
        - Number of dimensions: 2
        - Recommended domain: [0, 14]^2
        - Modality: multimodal
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

    m.def("dejongn6", &dejongn6, R"pbdoc(
        Computes the value of the De Jong N. 6 (Wood) benchmark function.
        SCORES = dejongn6(X) computes the value of the function at point X.
        `dejongn6` accepts a matrix of size M-by-4 and returns a vector SCORES of size M-by-1.
        Properties:

        - Global minimum: 0
        - Location of global minimum: (1, 1, 1, 1)
        - Number of dimensions: 4
        - Recommended domain: [-10, 10]^4
        - Modality: multimodal
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

    m.def("dixonpricen2", &dixonpricen2, R"pbdoc(
        Computes the value of the Dixon-Price N. 2 benchmark function.
        `dixonpricen2` is an alias for `dixonprice` for n=2.
        Properties:

        - Global minimum: 0
        - Location of global minimum: (1, +/- 0.7071)
        - Number of dimensions: 2
        - Recommended domain: [-10, 10]^2
        - Modality: unimodal
    )pbdoc");

    m.def("dixonpricen3", &dixonpricen3, R"pbdoc(
        Computes the value of the Dixon-Price N. 3 benchmark function.
        `dixonpricen3` is an alias for `dixonprice` for n=3.
        Properties:

        - Global minimum: 0
        - Location of global minimum: (1, 0.7071, 0.5946)
        - Number of dimensions: 3
        - Recommended domain: [-10, 10]^3
        - Modality: unimodal
    )pbdoc");

    m.def("dolan", &dolan, R"pbdoc(
        Computes the value of the Dolan benchmark function.
        SCORES = dolan(X) computes the value of the Dolan function at
        point X. `dolan` accepts a matrix of size M-by-5 and returns a
        vector SCORES of size M-by-1.
        Properties:

        - Global minimum: 0 (approx)
        - Number of dimensions: 5
        - Recommended domain: [-100, 100]^5
        - Modality: multimodal
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

    m.def("eggholdern2", &eggholdern2, R"pbdoc(
        Computes the value of the Eggholder N. 2 benchmark function.
        `eggholdern2` is an alias for `eggholder`.
        Properties:

        - Global minimum: -959.6407
        - Location of global minimum: (512, 404.2319)
        - Number of dimensions: 2
        - Recommended domain: [-512, 512]^2
        - Modality: multimodal
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

    m.def("engvall", &engvall, R"pbdoc(
        Computes the value of the Engvall benchmark function.
        SCORES = engvall(X) computes the value of the Engvall function at
        point X. `engvall` accepts a matrix of size M-by-2 and returns a
        vector SCORES of size M-by-1.
        Properties:

        - Global minimum: 0
        - Location of global minimum: (1, 0)
        - Number of dimensions: 2
        - Recommended domain: [-10, 10]^2
        - Modality: unimodal
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

    m.def("fletcherpowell", &fletcherpowell, R"pbdoc(
        Computes the value of the Fletcher-Powell benchmark function.
        SCORES = fletcherpowell(X) computes the value of the function at
        point X. `fletcherpowell` accepts a matrix of size M-by-N and returns a
        vector SCORES of size M-by-1.
        Properties:

        - Global minimum: 0
        - Location of global minimum: (alpha_1, ..., alpha_n)
        - Number of dimensions: n
        - Recommended domain: [-pi, pi]^n
        - Modality: highly multimodal
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

    m.def("freudensteinroth", &freudensteinroth, R"pbdoc(
        Computes the value of the Freudenstein-Roth benchmark function.
        SCORES = freudensteinroth(X) computes the value of the function at
        point X. `freudensteinroth` accepts a matrix of size M-by-2 and returns a
        vector SCORES of size M-by-1.
        Properties:

        - Global minimum: 0
        - Location of global minimum: (5, 4)
        - Number of dimensions: 2
        - Recommended domain: [-10, 10]^2
        - Modality: multimodal
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

    m.def("giuntan2", &giuntan2, R"pbdoc(
        Computes the value of the Giunta N. 2 benchmark function.
        SCORES = giuntan2(X) computes the value of the function at point X.
        `giuntan2` accepts a matrix of size M-by-4 and returns a vector SCORES of size M-by-1.
        Properties:

        - Global minimum: 0
        - Location of global minimum: [16, 19, 43, 49]
        - Number of dimensions: 4
        - Recommended domain: [12, 60]^4
        - Modality: multimodal
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

    m.def("griewankn2", &griewankn2, R"pbdoc(
        Computes the value of the Griewank N. 2 benchmark function.
        `griewankn2` is an alias for `griewank` for n=2.
        Properties:

        - Global minimum: 0
        - Location of global minimum: (0, 0)
        - Number of dimensions: 2
        - Recommended domain: [-600, 600]^2
        - Modality: multimodal
    )pbdoc");

    m.def("griewankn3", &griewankn3, R"pbdoc(
        Computes the value of the Griewank N. 3 benchmark function.
        `griewankn3` is an alias for `griewank` for n=3.
        Properties:

        - Global minimum: 0
        - Location of global minimum: (0, 0, 0)
        - Number of dimensions: 3
        - Recommended domain: [-600, 600]^3
        - Modality: multimodal
    )pbdoc");

    m.def("hansen", &hansen, R"pbdoc(
        Computes the value of the Hansen benchmark function.
        SCORES = hansen(X) computes the value of the Hansen function at
        point X. `hansen` accepts a matrix of size M-by-2 and returns a
        vector SCORES of size M-by-1.
        Properties:

        - Global minimum: -176.541793
        - Location of global minimum: 9 global minima in [-10, 10]^2
        - Number of dimensions: 2
        - Recommended domain: [-10, 10]^2
        - Modality: multimodal
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

    m.def("hartmann4", &hartmann4, R"pbdoc(
        Computes the value of the Hartmann N. 4 (4D) benchmark function.
        SCORES = hartmann4(X) computes the value of the function at point X.
        `hartmann4` accepts a matrix of size M-by-4 and returns a vector SCORES of size M-by-1.
        Properties:

        - Global minimum: -3.135474
        - Location of global minimum: (0.1873, 0.1906, 0.5569, 0.2859)
        - Number of dimensions: 4
        - Recommended domain: [0, 1]^4
        - Modality: multimodal
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

    m.def("helicalvalley", &helicalvalley, R"pbdoc(
        Computes the value of the Helical Valley benchmark function.
        SCORES = helicalvalley(X) computes the value of the function at
        point X. `helicalvalley` accepts a matrix of size M-by-3 and returns a
        vector SCORES of size M-by-1.
        Properties:

        - Global minimum: 0
        - Location of global minimum: (1, 0, 0)
        - Number of dimensions: 3
        - Recommended domain: [-10, 10]^3
        - Modality: unimodal
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

    m.def("himmelblaun2", &himmelblaun2, R"pbdoc(
        Computes the value of the Himmelblau N. 2 benchmark function.
        `himmelblaun2` is an alias for `himmelblau`.
        Properties:

        - Global minimum: 0
        - Location of global minimum: (3, 2), (-2.8051, 3.1313), (-3.7793, -3.2831), (3.5844, -1.8481)
        - Number of dimensions: 2
        - Recommended domain: [-5, 5]^2
        - Modality: multimodal
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

    m.def("hosakin2", &hosakin2, R"pbdoc(
        Computes the value of the Hosaki N. 2 benchmark function.
        `hosakin2` is an alias for `hosaki`.
        Properties:

        - Global minimum: -2.3458
        - Location of global minimum: (4, 2)
        - Number of dimensions: 2
        - Recommended domain: [0, 5]x[0, 6]
        - Modality: multimodal
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

    m.def("jennrichsampson", &jennrichsampson, R"pbdoc(
        Computes the value of the Jennrich-Sampson benchmark function.
        SCORES = jennrichsampson(X) computes the value of the function at
        point X. `jennrichsampson` accepts a matrix of size M-by-2 and returns a
        vector SCORES of size M-by-1.
        Properties:

        - Global minimum: 124.36218
        - Location of global minimum: (0.257825, 0.257825)
        - Number of dimensions: 2
        - Recommended domain: [-1, 1]^2
        - Modality: multimodal
    )pbdoc");

    m.def("judge", &judge, R"pbdoc(
        Computes the value of the Judge benchmark function.
        SCORES = judge(X) computes the value of the function at
        point X. `judge` accepts a matrix of size M-by-2 and returns a
        vector SCORES of size M-by-1.
        Properties:

        - Global minimum: 16.0817
        - Location of global minimum: (0.8648, 1.2357)
        - Number of dimensions: 2
        - Recommended domain: [-10, 10]^2
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

    m.def("keanen2", &keanen2, R"pbdoc(
        Computes the value of the Keane N. 2 benchmark function.
        `keanen2` is an alias for `keane`.
        Properties:

        - Global minimum: -0.6736675
        - Location of global minimum: (0, 1.3932) or (1.3932, 0)
        - Number of dimensions: 2
        - Recommended domain: [0, 10]^2
        - Modality: multimodal
    )pbdoc");

    m.def("kowalik", &kowalik, R"pbdoc(
        Computes the value of the Kowalik benchmark function.
        SCORES = kowalik(X) computes the value of the function at
        point X. `kowalik` accepts a matrix of size M-by-4 and returns a
        vector SCORES of size M-by-1.
        Properties:

        - Global minimum: 0.0003075
        - Location of global minimum: (0.1928, 0.1928, 0.1231, 0.1358)
        - Number of dimensions: 4
        - Recommended domain: [-5, 5]^4
        - Modality: multimodal
    )pbdoc");

    m.def("kulnevich", &kulnevich, R"pbdoc(
        Computes the value of the Kulnevich benchmark function.
        SCORES = kulnevich(X) computes the value of the function at
        point X. `kulnevich` accepts a matrix of size M-by-2 and returns a
        vector SCORES of size M-by-1.
        Properties:

        - Global minimum: -1.0 (approx)
        - Location of global minimum: (0, 0)
        - Number of dimensions: 2
        - Recommended domain: [-5, 5]^2
        - Modality: multimodal
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

    m.def("langermannn2", &langermannn2, R"pbdoc(
        Computes the value of the Langermann N. 2 benchmark function.
        `langermannn2` is an alias for `langermann`.
        Properties:

        - Global minimum: -5.1621
        - Location of global minimum: (2.0029, 1.0060)
        - Number of dimensions: 2
        - Recommended domain: [0, 10]^2
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

    m.def("leonn2", &leonn2, R"pbdoc(
        Computes the value of the Leon N. 2 benchmark function.
        `leonn2` is an alias for `leon`.
        Properties:

        - Global minimum: 0
        - Location of global minimum: (1, 1)
        - Number of dimensions: 2
        - Recommended domain: [-1.2, 1.2]^2
        - Modality: multimodal
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

    m.def("levyn1", &levyn1, R"pbdoc(
        Computes the value of the Levy N. 1 benchmark function.
        `levyn1` is an alias for `levy` for n=1.
        Properties:

        - Global minimum: 0
        - Location of global minimum: (1)
        - Number of dimensions: 1
        - Recommended domain: [-10, 10]
        - Modality: multimodal
    )pbdoc");

    m.def("levyn2", &levyn2, R"pbdoc(
        Computes the value of the Levy N. 2 benchmark function.
        `levyn2` is an alias for `levy` for n=2.
        Properties:

        - Global minimum: 0
        - Location of global minimum: (1, 1)
        - Number of dimensions: 2
        - Recommended domain: [-10, 10]^2
        - Modality: multimodal
    )pbdoc");

    m.def("levyn3", &levyn3, R"pbdoc(
        Computes the value of the Levy N. 3 benchmark function.
        `levyn3` is an alias for `levy` for n=3.
        Properties:

        - Global minimum: 0
        - Location of global minimum: (1, 1, 1)
        - Number of dimensions: 3
        - Recommended domain: [-10, 10]^3
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

    m.def("matyasn2", &matyasn2, R"pbdoc(
        Computes the value of the Matyas N. 2 benchmark function.
        `matyasn2` is an alias for `matyas`.
        Properties:

        - Global minimum: 0
        - Location of global minimum: (0, 0)
        - Number of dimensions: 2
        - Recommended domain: [-10, 10]^2
        - Modality: unimodal
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

    m.def("mccormickn2", &mccormickn2, R"pbdoc(
        Computes the value of the McCormick N. 2 benchmark function.
        `mccormickn2` is an alias for `mccormick`.
        Properties:

        - Global minimum: -1.9133
        - Location of global minimum: (-0.54719, -1.54719)
        - Number of dimensions: 2
        - Recommended domain: [-1.5, 4]x[-3, 4]
        - Modality: multimodal
    )pbdoc");

    m.def("meyer", &meyer, R"pbdoc(
        Computes the value of the Meyer (Meyer-Roth) benchmark function.
        SCORES = meyer(X) computes the value of the function at
        point X. `meyer` accepts a matrix of size M-by-3 and returns a
        vector SCORES of size M-by-1.
        Properties:

        - Global minimum: ~0.4e-4
        - Location of global minimum: (3.13, 15.16, 0.78)
        - Number of dimensions: 3
        - Recommended domain: [0, 20]^3
        - Modality: Multimodal
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

    m.def("michalewiczn2", &michalewiczn2, R"pbdoc(
        Computes the value of the Michalewicz N. 2 benchmark function.
        `michalewiczn2` is an alias for `michalewicz` for n=2.
        Properties:

        - Global minimum: -1.8013
        - Location of global minimum: (2.20, 1.57)
        - Number of dimensions: 2
        - Recommended domain: [0, pi]^2
        - Modality: multimodal
    )pbdoc");

    m.def("michalewiczn5", &michalewiczn5, R"pbdoc(
        Computes the value of the Michalewicz N. 5 benchmark function.
        `michalewiczn5` is an alias for `michalewicz` for n=5.
        Properties:

        - Global minimum: -4.6876
        - Number of dimensions: 5
        - Recommended domain: [0, pi]^5
        - Modality: multimodal
    )pbdoc");

    m.def("michalewiczn10", &michalewiczn10, R"pbdoc(
        Computes the value of the Michalewicz N. 10 benchmark function.
        `michalewiczn10` is an alias for `michalewicz` for n=10.
        Properties:

        - Global minimum: -9.6601
        - Number of dimensions: 10
        - Recommended domain: [0, pi]^10
        - Modality: multimodal
    )pbdoc");

    m.def("mielecantrell", &mielecantrell, R"pbdoc(
        Computes the value of the Miele-Cantrell benchmark function.
        SCORES = mielecantrell(X) computes the value of the function at
        point X. `mielecantrell` accepts a matrix of size M-by-4 and returns a
        vector SCORES of size M-by-1.
        Properties:

        - Global minimum: 0
        - Location of global minimum: (0, 1, 1, 1)
        - Number of dimensions: 4
        - Recommended domain: [-1, 1]^4
        - Modality: Multimodal
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

    m.def("mishran1", &mishran1, R"pbdoc(
        Computes the value of the Mishra's Function No. 1 benchmark function.
        SCORES = mishran1(X) computes the value of the function at
        point X. `mishran1` accepts a matrix of size M-by-N and returns a
        vector SCORES of size M-by-1.
        Properties:

        - Global minimum: 2
        - Location of global minimum: (1, ..., 1)
        - Number of dimensions: Any
        - Recommended domain: [0, 1]^N
        - Modality: Multimodal
    )pbdoc");

    m.def("mishran2", &mishran2, R"pbdoc(
        Computes the value of the Mishra's Function No. 2 benchmark function.
        SCORES = mishran2(X) computes the value of the function at
        point X. `mishran2` accepts a matrix of size M-by-N and returns a
        vector SCORES of size M-by-1.
        Properties:

        - Global minimum: 2
        - Location of global minimum: (1, ..., 1)
        - Number of dimensions: Any
        - Recommended domain: [0, 1]^N
        - Modality: Multimodal
    )pbdoc");

    m.def("mishran3", &mishran3, R"pbdoc(
        Computes the value of the Mishra's Function No. 3 benchmark function.
        SCORES = mishran3(X) computes the value of the function at
        point X. `mishran3` accepts a matrix of size M-by-2 and returns a
        vector SCORES of size M-by-1.
        Properties:

        - Global minimum: ~-0.18465
        - Location of global minimum: (-8.4666, -9.9985)
        - Number of dimensions: 2
        - Recommended domain: [-10, 10]^2
        - Modality: Multimodal
    )pbdoc");

    m.def("mishran4", &mishran4, R"pbdoc(
        Computes the value of the Mishra's Function No. 4 benchmark function.
        SCORES = mishran4(X) computes the value of the function at
        point X. `mishran4` accepts a matrix of size M-by-2 and returns a
        vector SCORES of size M-by-1.
        Properties:

        - Global minimum: ~-0.19941
        - Location of global minimum: (-9.9411, -10)
        - Number of dimensions: 2
        - Recommended domain: [-10, 10]^2
        - Modality: Multimodal
    )pbdoc");

    m.def("mishran5", &mishran5, R"pbdoc(
        Computes the value of the Mishra's Function No. 5 benchmark function.
        SCORES = mishran5(X) computes the value of the function at
        point X. `mishran5` accepts a matrix of size M-by-2 and returns a
        vector SCORES of size M-by-1.
        Properties:

        - Global minimum: ~-1.01983
        - Location of global minimum: (-1.9868, -10)
        - Number of dimensions: 2
        - Recommended domain: [-10, 10]^2
        - Modality: Multimodal
    )pbdoc");

    m.def("mishran6", &mishran6, R"pbdoc(
        Computes the value of the Mishra's Function No. 6 benchmark function.
        SCORES = mishran6(X) computes the value of the function at
        point X. `mishran6` accepts a matrix of size M-by-2 and returns a
        vector SCORES of size M-by-1.
        Properties:

        - Global minimum: ~-2.28395
        - Location of global minimum: (2.88631, 1.82326)
        - Number of dimensions: 2
        - Recommended domain: [-10, 10]^2
        - Modality: Multimodal
    )pbdoc");

    m.def("mishran7", &mishran7, R"pbdoc(
        Computes the value of the Mishra's Function No. 7 benchmark function.
        SCORES = mishran7(X) computes the value of the function at
        point X. `mishran7` accepts a matrix of size M-by-N and returns a
        vector SCORES of size M-by-1.
        Properties:

        - Global minimum: 0
        - Location of global minimum: prod(x_i) = n!
        - Number of dimensions: Any
        - Recommended domain: [-10, 10]^N
        - Modality: Multimodal
    )pbdoc");

    m.def("mishran8", &mishran8, R"pbdoc(
        Computes the value of the Mishra's Function No. 8 benchmark function.
        SCORES = mishran8(X) computes the value of the function at
        point X. `mishran8` accepts a matrix of size M-by-2 and returns a
        vector SCORES of size M-by-1.
        Properties:

        - Global minimum: 0
        - Location of global minimum: (2, -3)
        - Number of dimensions: 2
        - Recommended domain: [-10, 10]^2
        - Modality: Multimodal
    )pbdoc");

    m.def("mishran9", &mishran9, R"pbdoc(
        Computes the value of the Mishra's Function No. 9 benchmark function.
        SCORES = mishran9(X) computes the value of the function at
        point X. `mishran9` accepts a matrix of size M-by-3 and returns a
        vector SCORES of size M-by-1.
        Properties:

        - Global minimum: 0
        - Location of global minimum: (1, 2, 3)
        - Number of dimensions: 3
        - Recommended domain: [-10, 10]^3
        - Modality: Multimodal
    )pbdoc");

    m.def("mishran10", &mishran10, R"pbdoc(
        Computes the value of the Mishra's Function No. 10 benchmark function.
        SCORES = mishran10(X) computes the value of the function at
        point X. `mishran10` accepts a matrix of size M-by-2 and returns a
        vector SCORES of size M-by-1.
        Properties:

        - Global minimum: 0
        - Location of global minimum: many points (e.g., (0, 0))
        - Number of dimensions: 2
        - Recommended domain: [-10, 10]^2
        - Modality: Multimodal
    )pbdoc");

    m.def("mishran11", &mishran11, R"pbdoc(
        Computes the value of the Mishra's Function No. 11 benchmark function.
        SCORES = mishran11(X) computes the value of the function at
        point X. `mishran11` accepts a matrix of size M-by-N and returns a
        vector SCORES of size M-by-1.
        Properties:

        - Global minimum: 0
        - Location of global minimum: x1 = x2 = ... = xn
        - Number of dimensions: Any
        - Recommended domain: [0, 10]^N
        - Modality: Multimodal
    )pbdoc");

    m.def("mishran12", &mishran12, R"pbdoc(
        Computes the value of the Mishra's Function No. 12 benchmark function.
        SCORES = mishran12(X) computes the value of the function at
        point X. `mishran12` accepts a matrix of size M-by-2 and returns a
        vector SCORES of size M-by-1.
        Properties:

        - Global minimum: -106.764537
        - Location of global minimum: (4.70104, 3.15294) or (-1.58214, -3.13024)
        - Number of dimensions: 2
        - Recommended domain: [-10, 10]^2
        - Modality: Multimodal
    )pbdoc");

    m.def("needleeye", &needleeye, R"pbdoc(
        Computes the value of the Needle Eye benchmark function.
        SCORES = needleeye(X) computes the value of the Needle Eye function at point X.
        `needleeye` accepts a matrix of size M-by-N and returns a vector SCORES of size M-by-1.
        The function returns 0 if all |x_i| <= 0.0001, and 1 otherwise.
        Properties:

        - Global minimum: 0
        - Location of global minimum: (0, 0, ..., 0)
        - Number of dimensions: n
        - Recommended domain: [-100, 100]^n
        - Modality: multimodal/discontinuous
    )pbdoc");

    m.def("parsopoulos", &parsopoulos, R"pbdoc(
        Computes the value of the Parsopoulos function.
        SCORES = parsopoulos(X) computes the value of the function at
        point X. `parsopoulos` accepts a matrix of size M-by-2 and returns a
        vector SCORES of size M-by-1.
        Properties:

        - Global minimum: 0
        - Location of global minimum: (+/- pi/2, 0) etc.
        - Number of dimensions: 2
        - Recommended domain: [-5, 5]^2
        - Modality: Multimodal
    )pbdoc");

    m.def("pathological", &pathological, R"pbdoc(
        Computes the value of the Pathological function.
        SCORES = pathological(X) computes the value of the function at
        point X. `pathological` accepts a matrix of size M-by-N and returns a
        vector SCORES of size M-by-1.
        Properties:

        - Global minimum: 0
        - Location of global minimum: (0, 0, ..., 0)
        - Number of dimensions: Any
        - Recommended domain: [-100, 100]^N
        - Modality: Multimodal
    )pbdoc");

    m.def("paviani", &paviani, R"pbdoc(
        Computes the value of the Paviani function.
        SCORES = paviani(X) computes the value of the function at
        point X. `paviani` accepts a matrix of size M-by-10 and returns a
        vector SCORES of size M-by-1.
        Properties:

        - Global minimum: -45.778468
        - Location of global minimum: (9.350266, ..., 9.350266)
        - Number of dimensions: 10
        - Recommended domain: [2.001, 9.999]^10
        - Modality: Multimodal
    )pbdoc");

    m.def("penholder", &penholder, R"pbdoc(
        Computes the value of the Pen Holder function.
        SCORES = penholder(X) computes the value of the function at
        point X. `penholder` accepts a matrix of size M-by-2 and returns a
        vector SCORES of size M-by-1.
        Properties:

        - Global minimum: -0.963535
        - Location of global minimum: (+/- 9.64617, +/- 9.64617)
        - Number of dimensions: 2
        - Recommended domain: [-11, 11]^2
        - Modality: Multimodal
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

    m.def("periodicn2", &periodicn2, R"pbdoc(
        Computes the value of the Periodic N. 2 benchmark function.
        `periodicn2` is an alias for `periodic`.
        Properties:

        - Global minimum: 0.9
        - Location of global minimum: (0, 0, ..., 0)
        - Number of dimensions: n
        - Recommended domain: [-10, 10]^n
        - Modality: multimodal
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

    m.def("pinter", &pinter, R"pbdoc(
        Computes the value of the Pinter benchmark function.
        SCORES = pinter(X) computes the value of the Pinter function at
        point X. `pinter` accepts a matrix of size M-by-N and returns a
        vector SCORES of size M-by-1.
        Properties:

        - Global minimum: 0
        - Location of global minimum: (0, 0, ..., 0)
        - Number of dimensions: Any
        - Recommended domain: [-10, 10]^N
        - Modality: Multimodal
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

    m.def("powellsingularn2", &powellsingularn2, R"pbdoc(
        Computes the value of the Powell-Singular N. 2 benchmark function.
        `powellsingularn2` is an alias for `powellsingular` for n=4.
        Properties:

        - Global minimum: 0
        - Location of global minimum: (0, 0, 0, 0)
        - Number of dimensions: 4
        - Recommended domain: [-4, 5]^4
        - Modality: unimodal
    )pbdoc");

    m.def("powellsumn2", &powellsumn2, R"pbdoc(
        Computes the value of the Powell-Sum N. 2 benchmark function.
        `powellsumn2` is an alias for `powellsum`.
        Properties:

        - Global minimum: 0
        - Location of global minimum: (0, 0, ..., 0)
        - Number of dimensions: n
        - Recommended domain: [-1, 1]^n
        - Modality: unimodal
    )pbdoc");

    m.def("pricen1", &pricen1, R"pbdoc(
        Computes the value of the Price's Function No. 1 benchmark function.
        SCORES = pricen1(X) computes the value of the function at
        point X. `pricen1` accepts a matrix of size M-by-2 and returns a
        vector SCORES of size M-by-1.
        Properties:

        - Global minimum: 0
        - Location of global minimum: (+/- 5, +/- 5)
        - Number of dimensions: 2
        - Recommended domain: [-500, 500]^2
        - Modality: Multimodal
    )pbdoc");

    m.def("pricen2", &pricen2, R"pbdoc(
        Computes the value of the Price N. 2 (Periodic) benchmark function.
        SCORES = pricen2(X) computes the value of the Price N. 2 function at point X.
        `pricen2` is an alias for `periodic`.
        Properties:

        - Global minimum: 0.9
        - Location of global minimum: (0, 0, ..., 0)
        - Number of dimensions: n
        - Recommended domain: [-10, 10]^n
        - Modality: multimodal
    )pbdoc");

    m.def("pricen3", &pricen3, R"pbdoc(
        Computes the value of the Price N. 3 (Modified Rosenbrock) benchmark function.
        SCORES = pricen3(X) computes the value of the Price N. 3 function at point X.
        `pricen3` accepts a matrix of size M-by-2 and returns a vector SCORES of size M-by-1.
        Properties:

        - Global minimum: 0
        - Location of global minimum: (1, 1)
        - Number of dimensions: 2
        - Recommended domain: [-5, 5]^2
        - Modality: multimodal
    )pbdoc");

    m.def("pricen4", &pricen4, R"pbdoc(
        Computes the value of the Price N. 4 benchmark function.
        SCORES = pricen4(X) computes the value of the Price N. 4 function at point X.
        `pricen4` accepts a matrix of size M-by-2 and returns a vector SCORES of size M-by-1.
        Properties:

        - Global minimum: 0
        - Location of global minimum: (0, 0), (2, 4), (1.4643, 2.5060)
        - Number of dimensions: 2
        - Recommended domain: [-500, 500]^2
        - Modality: multimodal
    )pbdoc");

    m.def("pricen5", &pricen5, R"pbdoc(
        Computes the value of the Price N. 5 benchmark function.
        `pricen5` is an alias for `goldsteinprice`.
        Properties:

        - Global minimum: 3
        - Location of global minimum: (0, -1)
        - Number of dimensions: 2
        - Recommended domain: [-2, 2]^2
        - Modality: multimodal
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

    m.def("qingn2", &qingn2, R"pbdoc(
        Computes the value of the Qing N. 2 benchmark function.
        SCORES = qingn2(X) computes the value of the function at point X.
        `qingn2` accepts a matrix of size M-by-N and returns a vector SCORES of size M-by-1.
        Properties:

        - Global minimum: 0
        - Location of global minimum: (0, 0, ..., 0)
        - Number of dimensions: n
        - Recommended domain: [-500, 500]^n
        - Modality: multimodal
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

    m.def("quintic", &quintic, R"pbdoc(
        Computes the value of the Quintic benchmark function.
        SCORES = quintic(X) computes the value of the Quintic function at point X.
        `quintic` accepts a matrix of size M-by-N and returns a vector SCORES of size M-by-1.
        Properties:

        - Global minimum: 0
        - Location of global minimum: each x_i is a root of the quintic polynomial (-1 or 2).
        - Number of dimensions: n
        - Recommended domain: [-10, 10]^n
        - Modality: multimodal
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

    m.def("rastrigin_parallel", &rastrigin_parallel, R"pbdoc(
        Computes the value of Rastrigin benchmark function using multi-core parallelism.
        SCORES = rastrigin_parallel(X) computes the value of the Rastrigin function at
        point X. `rastrigin_parallel` accepts a matrix of size M-by-N and returns a vector
        SCORES of size M-by-1 in which each row contains the function value for the
        corresponding row of X.
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

    m.def("rotatedhyperellipsoid", &rotatedhyperellipsoid, R"pbdoc(
        Computes the value of the Rotated Hyper-Ellipsoid (Schwefel 1.2) benchmark function.
        SCORES = rotatedhyperellipsoid(X) computes the value of the function at point X.
        `rotatedhyperellipsoid` is an alias for `schwefel12`.
        Properties:

        - Global minimum: 0
        - Location of global minimum: (0, 0, ..., 0)
        - Number of dimensions: n
        - Recommended domain: [-65.536, 65.536]^n
        - Modality: unimodal
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

    m.def("sargan", &sargan, R"pbdoc(
        Computes the value of the Sargan benchmark function.
        SCORES = sargan(X) computes the value of the Sargan function at point X.
        `sargan` accepts a matrix of size M-by-N and returns a vector SCORES of size M-by-1.
        Properties:

        - Global minimum: 0
        - Location of global minimum: (0, 0, ..., 0)
        - Number of dimensions: n
        - Recommended domain: [-100, 100]^n
        - Modality: unimodal
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

    m.def("schwefel226", &schwefel, R"pbdoc(
        Computes the value of the Schwefel 2.26 (sine-root) benchmark function.
        `schwefel226` is an alias for `schwefel`.
        Properties:

        - Global minimum: 0 (normalized) or -418.9829 * n
        - Location of global minimum: (420.9687, ..., 420.9687)
        - Number of dimensions: n
        - Recommended domain: [-500, 500]^n
        - Modality: multimodal
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

    m.def("schwefel225", &schwefel225, R"pbdoc(
        Computes the value of the Schwefel 2.25 benchmark function.
        SCORES = schwefel225(X) computes the value of the Schwefel 2.25 function at point X.
        `schwefel225` accepts a matrix of size M-by-N and returns a vector SCORES of size M-by-1.
        Properties:

        - Global minimum: 0
        - Location of global minimum: (1, 1, ..., 1)
        - Number of dimensions: n
        - Recommended domain: [0, 10]^n
        - Modality: multimodal
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

    m.def("sineenvelopesinewave", &sineenvelopesinewave, R"pbdoc(
        Computes the value of the Sine Envelope Sine Wave (Schaffer F6 scalable) benchmark function.
        SCORES = sineenvelopesinewave(X) computes the value of the function at point X.
        `sineenvelopesinewave` accepts a matrix of size M-by-N and returns a vector SCORES of size M-by-1.
        Properties:

        - Global minimum: 0
        - Location of global minimum: (0, 0, ..., 0)
        - Number of dimensions: n
        - Recommended domain: [-100, 100]^n
        - Modality: multimodal
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

    m.def("stepn1", &stepn1, R"pbdoc(
        Computes the value of the Step N. 1 benchmark function.
        SCORES = stepn1(X) computes the value of the function at point X.
        `stepn1` accepts a matrix of size M-by-N and returns a vector SCORES of size M-by-1.
        Properties:

        - Global minimum: 0
        - Location of global minimum: (0, 0, ..., 0)
        - Number of dimensions: n
        - Recommended domain: [-100, 100]^n
        - Modality: unimodal
    )pbdoc");

    m.def("stepn2", &stepn2, R"pbdoc(
        Computes the value of the Step N. 2 benchmark function.
        `stepn2` is an alias for `step` (De Jong N. 3).
        Properties:

        - Global minimum: 0
        - Location of global minimum: [-0.5, 0.5)^n
        - Number of dimensions: n
        - Recommended domain: [-5.12, 5.12]^n
        - Modality: unimodal (plateau)
    )pbdoc");

    m.def("stepn3", &stepn3, R"pbdoc(
        Computes the value of the Step N. 3 benchmark function.
        SCORES = stepn3(X) computes the value of the function at point X.
        `stepn3` accepts a matrix of size M-by-N and returns a vector SCORES of size M-by-1.
        Properties:

        - Global minimum: 0
        - Location of global minimum: [-1, 1]^n
        - Number of dimensions: n
        - Recommended domain: [-100, 100]^n
        - Modality: multimodal (plateau)
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

    m.def("tablefcn", &tablefcn, R"pbdoc(
        Computes the value of the Table (Holder Table 1) benchmark function.
        SCORES = tablefcn(X) computes the value of the function at point X.
        `tablefcn` accepts a matrix of size M-by-2 and returns a vector SCORES of size M-by-1.
        Properties:

        - Global minimum: -26.920336
        - Location of global minimum: (+/- 9.6461, +/- 9.6461)
        - Number of dimensions: 2
        - Recommended domain: [-10, 10]^2
        - Modality: multimodal
    )pbdoc");

    m.def("testtubeholder", &testtubeholder, R"pbdoc(
        Computes the value of the Test Tube Holder benchmark function.
        SCORES = testtubeholder(X) computes the value of the function at point X.
        `testtubeholder` accepts a matrix of size M-by-2 and returns a vector SCORES of size M-by-1.
        Properties:

        - Global minimum: -10.8723
        - Location of global minimum: (+/- pi/2, 0)
        - Number of dimensions: 2
        - Recommended domain: [-10, 10]^2
        - Modality: multimodal
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

    m.def("trefethen", &trefethen, R"pbdoc(
        Computes the value of the Trefethen benchmark function.
        SCORES = trefethen(X) computes the value of the function at point X.
        `trefethen` accepts a matrix of size M-by-2 and returns a vector SCORES of size M-by-1.
        Properties:

        - Global minimum: -3.3068686
        - Location of global minimum: (-0.0244, 0.2106)
        - Number of dimensions: 2
        - Recommended domain: [-10, 10]^2
        - Modality: multimodal
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

    m.def("trigonometricn1", &trigonometricn1, R"pbdoc(
        Computes the value of the Trigonometric N. 1 benchmark function.
        SCORES = trigonometricn1(X) computes the value of the function at point X.
        `trigonometricn1` accepts a matrix of size M-by-N and returns a vector SCORES of size M-by-1.
        Properties:

        - Global minimum: 0
        - Location of global minimum: (0, 0, ..., 0)
        - Number of dimensions: n
        - Recommended domain: [0, pi]^n
        - Modality: multimodal
    )pbdoc");

    m.def("trigonometricn2", &trigonometricn2, R"pbdoc(
        Computes the value of the Trigonometric N. 2 benchmark function.
        SCORES = trigonometricn2(X) computes the value of the function at point X.
        `trigonometricn2` accepts a matrix of size M-by-N and returns a vector SCORES of size M-by-1.
        Properties:

        - Global minimum: 1
        - Location of global minimum: (0.9, 0.9, ..., 0.9)
        - Number of dimensions: n
        - Recommended domain: [-500, 500]^n
        - Modality: multimodal
    )pbdoc");

    m.def("ursemn1", &ursemn1, R"pbdoc(
        Computes the value of the Ursem N. 1 benchmark function.
        SCORES = ursemn1(X) computes the value of the function at point X.
        `ursemn1` accepts a matrix of size M-by-2 and returns a vector SCORES of size M-by-1.
        Properties:

        - Global minimum: -4.81681
        - Location of global minimum: (1.6971, 0)
        - Number of dimensions: 2
        - Recommended domain: x in [-2.5, 3], y in [-2, 2]
        - Modality: multimodal
    )pbdoc");

    m.def("ursemn3", &ursemn3, R"pbdoc(
        Computes the value of the Ursem N. 3 benchmark function.
        SCORES = ursemn3(X) computes the value of the function at point X.
        `ursemn3` accepts a matrix of size M-by-2 and returns a vector SCORES of size M-by-1.
        Properties:

        - Global minimum: -2.5
        - Location of global minimum: (0, 0)
        - Number of dimensions: 2
        - Recommended domain: x1 in [-2, 2], x2 in [-1.5, 1.5]
        - Modality: multimodal
    )pbdoc");

    m.def("ursemn4", &ursemn4, R"pbdoc(
        Computes the value of the Ursem N. 4 benchmark function.
        SCORES = ursemn4(X) computes the value of the function at point X.
        `ursemn4` accepts a matrix of size M-by-2 and returns a vector SCORES of size M-by-1.
        Properties:

        - Global minimum: -3
        - Location of global minimum: (0, 0)
        - Number of dimensions: 2
        - Recommended domain: [-2, 2]^2
        - Modality: multimodal
    )pbdoc");

    m.def("ursemwaves", &ursemwaves, R"pbdoc(
        Computes the value of the Ursem Waves benchmark function.
        SCORES = ursemwaves(X) computes the value of the function at point X.
        `ursemwaves` accepts a matrix of size M-by-2 and returns a vector SCORES of size M-by-1.
        Properties:

        - Global minimum: -7.306999
        - Location of global minimum: (-0.605689, -1.177562)
        - Number of dimensions: 2
        - Recommended domain: x1 in [-0.9, 1.2], x2 in [-1.2, 1.2]
        - Modality: multimodal
    )pbdoc");

    m.def("ventersobiezcczanski", &ventersobiezcczanski, R"pbdoc(
        Computes the value of the Venter Sobiezcczanski-Sobieski benchmark function.
        SCORES = ventersobiezcczanski(X) computes the value of the function at point X.
        `ventersobiezcczanski` accepts a matrix of size M-by-N and returns a vector SCORES of size M-by-1.
        Properties:

        - Global minimum: -200.0 * n
        - Location of global minimum: (0, 0, ..., 0)
        - Number of dimensions: n
        - Recommended domain: [-50, 50]^n
        - Modality: multimodal
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

    m.def("wayburnseadern1", &wayburnseadern1, R"pbdoc(
        Computes the value of the Wayburn-Seader N. 1 benchmark function.
        SCORES = wayburnseadern1(X) computes the value of the function at point X.
        `wayburnseadern1` accepts a matrix of size M-by-2 and returns a vector SCORES of size M-by-1.
        Properties:

        - Global minimum: 0
        - Location of global minimum: (1, 2), (1.597, 0.806)
        - Number of dimensions: 2
        - Recommended domain: [-500, 500]^2
        - Modality: multimodal
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
    )pbdoc");

    m.def("wayburnseadern3", &wayburnseadern3, R"pbdoc(
        Computes the value of the Wayburn-Seader N. 3 benchmark function.
        SCORES = wayburnseadern3(X) computes the value of the function at point X.
        `wayburnseadern3` accepts a matrix of size M-by-2 and returns a vector SCORES of size M-by-1.
        Properties:

        - Global minimum: 19.1059
        - Location of global minimum: (5.1469, 6.8396)
        - Number of dimensions: 2
        - Recommended domain: [-500, 500]^2
        - Modality: multimodal
    )pbdoc");

    m.def("weierstrass", &weierstrass, py::arg("x"), py::arg("a") = 0.5, py::arg("b") = 3.0,
          py::arg("kmax") = 20, R"pbdoc(
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

    m.def("xinsheyangn3", &xinsheyangn3, py::arg("x"), py::arg("beta") = 15, py::arg("m") = 5,
          R"pbdoc(
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

    m.def("get_function_ptr", &get_function_ptr, py::arg("name"),
          "Retrieves a benchmark function pointer by name.");

    py::class_<Composition>(m, "Composition")
        .def(py::init<>())
        .def("add_component", &Composition::add_component, py::arg("fcn"), py::arg("shift"),
             py::arg("rotation"), py::arg("sigma"), py::arg("lambda"), py::arg("bias"),
             py::arg("f_max"), py::arg("apply_osz") = false, py::arg("apply_asy") = false,
             py::arg("variables") = std::vector<int>(), py::arg("input_offset") = VectorXd(),
             "Adds a base function component to the composition.")
        .def("evaluate", &Composition::evaluate, py::arg("x"),
             "Evaluates the composed function for a batch of points.")
        .def("set_constant_C", &Composition::set_constant_C, py::arg("C"),
             "Sets the C constant for height normalization (default 2000.0).");

    auto cecm = m.def_submodule("cec", "CEC Competition benchmark functions");
    cecm.def("evaluate_2014", &CEC::evaluate_2014, py::arg("x"), py::arg("fid"), R"pbdoc(
        Evaluates a CEC 2014 benchmark function.
        SCORES = cec.evaluate_2014(X, FID) computes the value of function FID at point X.
        Accepts matrix M-by-D where D must be 10, 30, 50, or 100.
    )pbdoc");
    cecm.def("evaluate_2017", &CEC::evaluate_2017, py::arg("x"), py::arg("fid"), R"pbdoc(
        Evaluates a CEC 2017 benchmark function.
        SCORES = cec.evaluate_2017(X, FID) computes the value of function FID at point X.
        Accepts matrix M-by-D where D must be 10, 30, 50, or 100.
    )pbdoc");
    cecm.def("evaluate_2019", &CEC::evaluate_2019, py::arg("x"), py::arg("fid"), R"pbdoc(
        Evaluates a CEC 2019 benchmark function (100-Digit Challenge).
        SCORES = cec.evaluate_2019(X, FID) computes the value of function FID at point X.
        Dimensions are fixed per FID: F1=9, F2=16, F3=18, F4-F10=10.
    )pbdoc");
    cecm.def("evaluate_2020", &CEC::evaluate_2020, py::arg("x"), py::arg("fid"), R"pbdoc(
        Evaluates a CEC 2020 benchmark function.
        SCORES = cec.evaluate_2020(X, FID) computes the value of function FID at point X.
        Supported Dimensions: 2, 5, 10, 15, 20.
    )pbdoc");
    cecm.def("evaluate_2022", &CEC::evaluate_2022, py::arg("x"), py::arg("fid"), R"pbdoc(
        Evaluates a CEC 2022 benchmark function.
        SCORES = cec.evaluate_2022(X, FID) computes the value of function FID at point X.
        Supported Dimensions: 2, 10, 20.
    )pbdoc");

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}
