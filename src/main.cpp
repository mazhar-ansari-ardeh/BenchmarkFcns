#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

# define STRINGIFY(x) #x
# define MACRO_STRINGIFY(x) STRINGIFY(x)

#include "benchmarkfcns.h"

using namespace BenchmarkFcns;

namespace py = pybind11;

PYBIND11_MODULE(_core, m) {
    m.doc() = R"pbdoc(
        Pybind11 example plugin
        -----------------------

        .. currentmodule:: BenchmarkFcns

        .. autosummary::
           :toctree: _generate

           sphere
    )pbdoc";

    m.def("ackley", &ackley, R"pbdoc(
        Ackley benchmark

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("ackley2", &ackley2, R"pbdoc(
        Ackley benchmark function 2

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("ackley3", &ackley3, R"pbdoc(
        Ackley benchmark function 3

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("ackley4", &ackley4cg, R"pbdoc(
        Ackley benchmark function 4

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("adjiman", &adjiman, R"pbdoc(
        Adjiman function

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("alpine1", &alpine1, R"pbdoc(
        Alpine1 function

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("alpine2", &alpine2, R"pbdoc(
        Alpine1 function

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("bartelsconn", &bartelsconn, R"pbdoc(
        Alpine1 function

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("beale", &beale, R"pbdoc(
        Beale function

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("bird", &bird, R"pbdoc(
        Bird function

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("bohachevsky1", &bohachevsky1, R"pbdoc(
        Bird function

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("bohachevsky2", &bohachevsky2, R"pbdoc(
        Bird function

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("booth", &booth, R"pbdoc(
        Bird function

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("brown", &brentfcn, R"pbdoc(
        Brown function

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("bukinn6", &bukinn6, R"pbdoc(
        bukinn6 function

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("crossintray", &crossintray, R"pbdoc(
        Crossintray function

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("deckkersaarts", &deckkersaarts, R"pbdoc(
        deckkersaarts function

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("dropwave", &dropwave, R"pbdoc(
        dropwave function

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("easom", &easom, R"pbdoc(
        easom function

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("eggholder", &eggholder, R"pbdoc(
        eggholder function

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("eggcrate", &eggcrate, R"pbdoc(
        eggcrate function

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("elattar", &elattar, R"pbdoc(
        elattar function

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("exponential", &exponential, R"pbdoc(
        exponential function

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("goldsteinprice", &goldsteinprice, R"pbdoc(
        goldsteinprice function

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("gramacylee", &gramacylee, R"pbdoc(
        gramacylee function

        Some other explanation about the sphere function.   
    )pbdoc");

    m.def("griewank", &griewank, R"pbdoc(
        griewank function

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("happycat", &happycat, py::arg("x"), py::arg("alpha") = 0.5, R"pbdoc(
        happycat function

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("holdertable", &holdertable, R"pbdoc(
        holdertable function

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("himmelblau", &himmelblau, R"pbdoc(
        himmelblaufcn function

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("keane", &keane, R"pbdoc(
        keane function

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("leon", &leon, R"pbdoc(
        leon function

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("levin13", &levin13, R"pbdoc(
        levin13 function

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("matyas", &matyas, R"pbdoc(
        matyas function

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("mccormick", &mccormick, R"pbdoc(
        mccormick function

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("periodic", &periodic, R"pbdoc(
        periodic function

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("picheny", &picheny, R"pbdoc(
        picheny function

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("powellsum", &powellsum, R"pbdoc(
        powellsum function

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("qing", &qing, R"pbdoc(
        qing function

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("quartic", &quartic, R"pbdoc(
        quartic function

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("rastrigin", &rastrigin, R"pbdoc(
        rastrigin function

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("ridge", &ridge, R"pbdoc(
        ridge function

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("rosenbrock", &rosenbrock, R"pbdoc(
        rosenbrock function

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("salomon", &salomon, R"pbdoc(
        salomon function

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("schaffern1", &schaffern1, R"pbdoc(
        salomon function

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("schaffern2", &schaffern2, R"pbdoc(
        salomon function

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("schaffern3", &schaffern3, R"pbdoc(
        salomon function

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("schaffern4", &schaffern4, R"pbdoc(
        salomon function

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("schwefel", &schwefel, R"pbdoc(
        salomon function

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("schwefel220", &schwefel220, R"pbdoc(
        schwefel220 function

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("schwefel221", &schwefel221, R"pbdoc(
        schwefel221 function

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("schwefel222", &schwefel222, R"pbdoc(
        schwefel222 function

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("schwefel223fcn", &schwefel223fcn, R"pbdoc(
        schwefel223fcn function

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("shubert", &shubert, R"pbdoc(
        shubert function

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("shubert3", &shubert3, R"pbdoc(
        shubert3 function

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("shubert4", &shubert4, R"pbdoc(
        shubert4 function

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("sphere", &sphere, R"pbdoc(
        Sphere benchmark

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("styblinskitank", &styblinskitank, R"pbdoc(
        styblinskitank function

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("sumsquares", &sumsquares, R"pbdoc(
        sumsquares function

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("threehumpcamel", &threehumpcamel, R"pbdoc(
        threehumpcamel function

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("wolfe", &wolfe, R"pbdoc(
        wolfe function

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("xinsheyangn1", &xinsheyangn1, R"pbdoc(
        xinsheyangn1 function

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("xinsheyangn2", &xinsheyangn2, R"pbdoc(
        xinsheyangn2 function

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("xinsheyangn3", &xinsheyangn3, py::arg("x"), py::arg("beta") = 15, py::arg("m") = 5, R"pbdoc(
        xinsheyangn3 function

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("xinsheyangn4", &xinsheyangn4, R"pbdoc(
        xinsheyangn4 function

        Some other explanation about the sphere function.
    )pbdoc");

    m.def("zakharov", &zakharov, R"pbdoc(
        zakharov function

        Some other explanation about the sphere function.
    )pbdoc");


#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}
