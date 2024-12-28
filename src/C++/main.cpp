#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

# define STRINGIFY(x) #x
# define MACRO_STRINGIFY(x) STRINGIFY(x)

#include "benchmarkfcns.h"
#include "multifidelity.h"

using namespace BenchmarkFcns;

namespace py = pybind11;

PYBIND11_MODULE(_core, m) {
    auto mfm = m.def_submodule("multifidelity", "Multi-fidelity functions");

    mfm.def("booth", MultiFidelity::booth, R"pbdoc(
        Computes the value of the Booth function at different fidelity levels.
        SCORES = multifidelity.booth(X) computes the value of the Booth function
        at point X. `multifidelity.booth` accepts a matrix of size M-by-2 and returns
        a vetor SCORES of size M-by-2 in which each column contains the function value
        for each row of X and each column contains the function value for the
        corresponding fidelity level.
        For more information, please refer to:
        Dong, H., Song, B., Wang, P. et al. Multi-fidelity information
        fusion based on prediction of kriging. Struct Multidisc Optim
        51, 1267-1280 (2015) doi:10.1007/s00158-014-1213-9
    )pbdoc");

    mfm.def("forrester", MultiFidelity::forrester, R"pbdoc(
        Computes the value of the Forrester function at different fidelity levels.
        SCORES = multifidelity.forrester(X) computes the value of the Forrester function
        at point X. `multifidelity.forrester` accepts a matrix of size M-by-1 and returns
        a vetor SCORES of size M-by-4 in which each column contains the function value
        for each row of X and each column contains the function value for the
        corresponding fidelity level.
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
        For more information, please visit:
        arxiv.org/pdf/2204.07867
    )pbdoc");

    m.doc() = R"pbdoc(
        Pybind11 example plugin
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
        SCORES = ackley(X) computes the value of the Ackey function at point
        X. `ackley` accepts a matrix of size M-by-N and returns a vetor SCORES
        of size M-by-1 in which each row contains the function value for each row
        of X.
        For more information, please visit:
        benchmarkfcns.info/doc/ackleyfcn
    )pbdoc");

    m.def("ackleyn2", &ackleyn2, R"pbdoc(
        Computes the value of the Ackley N. 2 function.
        SCORES = ackley2(X) computes the value of the Ackley N. 2
        function at point X. `ackley2` accepts a matrix of size M-by-2 and
        returns a vetor SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/ackleyn2fcn
    )pbdoc");

    m.def("ackleyn3", &ackleyn3, R"pbdoc(
        Computes the value of the Ackley N. 3 function.
        SCORES = ackley3(X) computes the value of the Ackley N. 3
        function at point X. `ackley3` accepts a matrix of size M-by-2 and
        returns a vetor SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/ackleyn3fcn
    )pbdoc");

    m.def("ackleyn4", &ackleyn4, R"pbdoc(
        Computes the value of Ackley N. 4 benchmark function.
        SCORES = ackley4(X) computes the value of the Ackey function at point
        X. `ackley4` accepts a matrix of size M-by-N and returns a vetor SCORES
        of size M-by-1 in which each row contains the function value for each row
        of X.
        For more information, please visit:
        benchmarkfcns.info/doc/ackleyn4fcn
    )pbdoc");

    m.def("adjiman", &adjiman, R"pbdoc(
        Computes the value of the Adjiman benchmark function.
        SCORES = adjiman(X) computes the value of the Adjiman function at
        point X. `adjiman` accepts a matrix of size M-by-2 and returns a
        vetor SCORES of size M-by-1 in which each row contains the function value
        for the corresponding row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/adjimanfcn
    )pbdoc");

    m.def("alpinen1", &alpinen1, R"pbdoc(
        Computes the value of the Alpine N. 1 function.
        SCORES = alpine1(X) computes the value of the Alpine N. 1
        function at point X. `alpine1` accepts a matrix of size M-by-N and
        returns a vetor SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/alpinen1fcn
    )pbdoc");

    m.def("alpinen2", &alpinen2, R"pbdoc(
        Computes the value of the Alpine N. 2 function.
        SCORES = alpine2(X) computes the value of the Alpine N. 2
        function at point X. `alpine2` accepts a matrix of size M-by-N and
        returns a vetor SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/alpinen2fcn
    )pbdoc");

    m.def("amgm", &amgm, R"pbdoc(
        Computes the value of the AMGM benchmark function.
        SCORES = amgm(X) computes the value of the AMGM function at point X.
        `amgm` accepts a matrix of size M-by-N and returns a vetor SCORES of
        size M-by-1 in which each row contains the function value for the
        corresponding row of X.
    )pbdoc");

    m.def("bartelsconn", &bartelsconn, R"pbdoc(
        Computes the value of the Bartels Conn benchmark function.
        SCORES = bartelsconn(X) computes the value of the Bartels Conn
        function at point X. bartelsconn accepts a matrix of size M-by-2 and
        returns a vetor SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/bartelsconnfcn
    )pbdoc");

    m.def("beale", &beale, R"pbdoc(
        Computes the value of the Beale benchmark function.
        SCORES = beale(X) computes the value of the Beale function at
        point X. `beale` accepts a matrix of size M-by-2 and returns a
        vetor SCORES of size M-by-1 in which each row contains the function value
        for the corresponding row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/bealefcn
    )pbdoc");

    m.def("bird", &bird, R"pbdoc(
        Computes the value of the Bird function.
        SCORES = bird(X) computes the value of the Bird
        function at point X. `bird` accepts a matrix of size M-by-2 and
        returns a vetor SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/birdfcn
    )pbdoc");

    m.def("bohachevskyn1", &bohachevskyn1, R"pbdoc(
        Computes the value of Bohachevsky N. 1 benchmark function.
        SCORES = bohachevsky1(X) computes the value of the Bohachevsky N. 1
        function at point X. `bohachevsky1` accepts a matrix of size M-by-N and
        returns a vetor SCORES of size M-by-1 in which each row contains the
        function value for each row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/bohachevskyn1fcn
    )pbdoc");

    m.def("bohachevskyn2", &bohachevskyn2, R"pbdoc(
        Computes the value of Bohachevsky N. 2 benchmark function.
        SCORES = bohachevsky2(X) computes the value of the Bohachevsky N. 2
        function at point X. `bohachevsky2` accepts a matrix of size M-by-N and
        returns a vetor SCORES of size M-by-1 in which each row contains the
        function value for each row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/bohachevskyn2fcn
    )pbdoc");

    m.def("booth", &booth, R"pbdoc(
        Computes the value of the Booth benchmark function.
        SCORES = booth(X) computes the value of the Booth's function at
        point X. `booth` accepts a matrix of size M-by-2 and returns a
        vetor SCORES of size M-by-1 in which each row contains the function value
        for the corresponding row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/boothfcn
    )pbdoc");

    m.def("braninn1", &braninn1, R"pbdoc(
        Computes the value of the Branin N. 1 benchmark function.
        SCORES = braninn01(X) computes the value of the Branin N. 1
        function at point X. `braninn01` accepts a matrix of size M-by-2 and
        returns a vetor SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/braninn1fcn
    )pbdoc");

    m.def("braninn2", &braninn2, R"pbdoc(
        Computes the value of the Branin N. 2 benchmark function.
        SCORES = braninn02(X) computes the value of the Branin N. 2
        function at point X. `braninn02` accepts a matrix of size M-by-2 and
        returns a vetor SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/braninn2fcn
    )pbdoc");

    m.def("brent", &brent, R"pbdoc(
        Computes the value of the Egg Crate function.
        SCORES = brent(X) computes the value of the Brent
        function at point X. `brent` accepts a matrix of size M-by-2 and
        returns a vetor SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/brentfcn
    )pbdoc");

    m.def("brown", &brown, R"pbdoc(
        Computes the value of the Brown benchmark function.
        SCORES = brown(X) computes the value of the Brown function at point X.
        `brown` accepts a matrix of size M-by-N and returns a vetor SCORES of
        size M-by-1 in which each row contains the function value for the
        corresponding row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/brownfcn
    )pbdoc");

    m.def("bukinn2", &bukinn2, R"pbdoc(
        Computes the value of the Bukin N. 2 benchmark function.
        SCORES = bukinn2(X) computes the value of the Bukin N. 2 function at
        point X. `bukinn2` accepts a matrix of size M-by-2 and returns a
        vetor SCORES of size M-by-1 in which each row contains the function value
        for the corresponding row of X.
    )pbdoc");

    m.def("bukinn4", &bukinn4, R"pbdoc(
        Computes the value of the Bukin N. 4 benchmark function.
        SCORES = bukinn4(X) computes the value of the Bukin N. 4 function at
        point X. `bukinn4` accepts a matrix of size M-by-2 and returns a
        vetor SCORES of size M-by-1 in which each row contains the function value
        for the corresponding row of X.
    )pbdoc");

    m.def("bukinn6", &bukinn6, R"pbdoc(
        Computes the value of the Bukin N. 6 benchmark function.
        SCORES = bukinn6(X) computes the value of the Bukin N. 6 function at
        point X. `bukinn6` accepts a matrix of size M-by-2 and returns a
        vetor SCORES of size M-by-1 in which each row contains the function value
        for the corresponding row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/bukinn6fcn
    )pbdoc");

    m.def("carromtable", &carromtable, R"pbdoc(
        Computes the value of the Carromtable benchmark function.
        SCORES = carromtable(X) computes the value of the Carromtable
        function at point X. `carromtable` accepts a matrix of size M-by-2 and
        returns a vetor SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/carromtablefcn
    )pbdoc");

    m.def("chichinadze", &chichinadze, R"pbdoc(
        Computes the value of the Chichinadze benchmark function.
        SCORES = chichinadze(X) computes the value of the Chichinadze
        function at point X. `chichinadze` accepts a matrix of size M-by-2 and
        returns a vetor SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
    )pbdoc");

    m.def("cigar", &cigar, R"pbdoc(
        Computes the value of the Cigar benchmark function.
        SCORES = cigar(X) computes the value of the Cigar function at point X.
        `cigar` accepts a matrix of size M-by-N and returns a vetor SCORES of
        size M-by-1 in which each row contains the function value for the
        corresponding row of X.
    )pbdoc");

    m.def("cosinemixture", &cosinemixture, R"pbdoc(
        Computes the value of the Cosine Mixture benchmark function.
        SCORES = cosinemixture(X) computes the value of the Cosine Mixture
        function at point X. `cosinemixture` accepts a matrix of size M-by-N and
        returns a vetor SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
    )pbdoc");

    m.def("crossintray", &crossintray, R"pbdoc(
        Computes the value of the Cross-in-tray benchmark function.
        SCORES = crossintray(X) computes the value of the Cross-in-tray
        function at point X. `crossintray` accepts a matrix of size M-by-2
        and returns a vetor SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/crossintrayfcn
    )pbdoc");

    m.def("crownedcross", &crownedcross, R"pbdoc(
        Computes the value of the Crowned Cross benchmark function.
        SCORES = crownedcross(X) computes the value of the Crowned Cross
        function at point X. `crownedcross` accepts a matrix of size M-by-2 and
        returns a vetor SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
    )pbdoc");

    m.def("csendes", &csendes, R"pbdoc(
        Computes the value of the Csendes benchmark function.
        SCORES = csendes(X) computes the value of the Csendes function at point X.
        `csendes` accepts a matrix of size M-by-N and returns a vetor SCORES of
        size M-by-1 in which each row contains the function value for the
        corresponding row of X.
    )pbdoc");

    m.def("cubefcn", &cubefcn, R"pbdoc(
        Computes the value of the Cube benchmark function.
        SCORES = cube(X) computes the value of the Cube function at point X.
        `cube` accepts a matrix of size M-by-N and returns a vetor SCORES of
        size M-by-1 in which each row contains the function value for the
        corresponding row of X.
    )pbdoc");

    m.def("debn1", &debn1, R"pbdoc(
        Computes the value of the Deb N. 1 benchmark function.
        SCORES = deb1(X) computes the value of the Deb N. 1 function at point X.
        `deb1` accepts a matrix of size M-by-N and returns a vetor SCORES of
        size M-by-1 in which each row contains the function value for the
        corresponding row of X.
    )pbdoc");

    m.def("deckkersaarts", &deckkersaarts, R"pbdoc(
        Computes the value of the Deckkers-Aarts function.
        SCORES = deckkersaarts(X) computes the value of the Deckkers-Aarts
        function at point X. `deckkersaarts` accepts a matrix of size M-by-2 and
        returns a vetor SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/deckkersaartsfcn
    )pbdoc");

    m.def("dropwave", &dropwave, R"pbdoc(
        Computes the value of the Drop-Wave benchmark function.
        SCORES = dropwave(X) computes the value of the Drop-Wave function at
        point X. `dropwave` accepts a matrix of size M-by-2 and returns a
        vetor SCORES of size M-by-1 in which each row contains the function value
        for the corresponding row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/dropwavefcn
    )pbdoc");

    m.def("easom", &easom, R"pbdoc(
        Computes the value of the Easom benchmark function.
        SCORES = easom(X) computes the value of the Easom function at point X.
        `easom` accepts a matrix of size M-by-2 and returns a vetor SCORES of
        size M-by-1 in which each row contains the function value for the
        corresponding row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/easomfcn
    )pbdoc");

    m.def("eggcrate", &eggcrate, R"pbdoc(
        Computes the value of the Egg Crate function.
        SCORES = eggcrate(X) computes the value of the Egg Crate
        function at point X. `eggcrate` accepts a matrix of size M-by-2 and
        returns a vetor SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/eggcratefcn
    )pbdoc");

    m.def("eggholder", &eggholder, R"pbdoc(
        Computes the value of the Eggholder benchmark function.
        SCORES = eggholder(X) computes the value of the Eggholder
        function at point X. `eggholder` accepts a matrix of size M-by-2
        and returns a vetor SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/eggholderfcn
    )pbdoc");

    m.def("elattar", &elattar, R"pbdoc(
        Computes the value of the El-Attar function.
        SCORES = elattar(X) computes the value of the El-Attar
        function at point X. `elattar` accepts a matrix of size M-by-3 and
        returns a vetor SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/elattarfcn
    )pbdoc");

    m.def("exponential", &exponential, R"pbdoc(
        Computes the value of the Exponential function.
        SCORES = exponential(X) computes the value of the Exponential
        function at point X. `exponential` accepts a matrix of size M-by-N and
        returns a vetor SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/exponentialfcn
    )pbdoc");

    m.def("forrester", &forrester, R"pbdoc(
        Computes the value of the Forrester benchmark function.
        SCORES = forrester(X) computes the value of the Forrester function at
        point X. `forrester` accepts a matrix of size M-by-N and returns a vetor
        SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/forresterfcn
    )pbdoc");

    m.def("giunta", &giunta, R"pbdoc(
        Computes the value of the Giunta function.
        SCORES = giunta(X) computes the value of the Alpine N. 1
        function at point X. `giunta` accepts a matrix of size M-by-N and
        returns a vetor SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/giuntafcn
    )pbdoc");

    m.def("goldsteinprice", &goldsteinprice, R"pbdoc(
        Computes the value of Goldstein-Price benchmark function.
        SCORES = goldsteinprice(X) computes the value of the Goldstein-Price
        function at point X. `goldsteinprice` accepts a matrix of size M-by-2
        and returns a vetor SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/goldsteinpricefcn
    )pbdoc");

    m.def("gramacylee", &gramacylee, R"pbdoc(
        Computes the value of the Gramacy & Lee benchmark function.
        SCORES = gramacylee(X) computes the value of the Gramacy & Lee
        function at point X. `gramacylee` accepts a matrix of size M-by-2 and
        returns a vetor SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/gramacyleefcn
    )pbdoc");

    m.def("griewank", &griewank, R"pbdoc(
        Computes the value of the Griewank benchmark function.
        SCORES = griewank(X) computes the value of the Griewank's
        function at point X. `griewank` accepts a matrix of size M-by-N
        and returns a vetor SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/griewankfcn
    )pbdoc");

    m.def("happycat", &happycat, py::arg("x"), py::arg("alpha") = 0.5, R"pbdoc(
        Computes the value of the Happy Cat benchmark function.
        SCORES = happycat(X) computes the value of the Happy Cat function at
        point X. `happycat` accepts a matrix of size M-by-N and returns a vetor
        SCORES of size M-by-1 in which each row contains the function value for
        the corresponding row of X.
        SCORES = happycat(X, ALPHA) specifies power of the sphere component of
        the function.
        For more information, please visit:
        benchmarkfcns.info/doc/happycatfcn
    )pbdoc");

    m.def("himmelblau", &himmelblau, R"pbdoc(
        Computes the value of the Himmelblau's benchmark function.
        SCORES = himmelblau(X) computes the value of the Himmelblau's
        function at point X. `himmelblau` accepts a matrix of size M-by-2
        and returns a vetor SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/himmelblaufcn
    )pbdoc");

    m.def("holdertable", &holdertable, R"pbdoc(
        Computes the value of the H�lder table benchmark function.
        SCORES = holdertable(X) computes the value of the H�lder table
        function at point X. `holdertable` accepts a matrix of size M-by-2 and
        returns a vetor SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/holdertablefcn
    )pbdoc");

    m.def("keane", &keane, R"pbdoc(
        Computes the value of the Keane function.
        SCORES = keane(X) computes the value of the Keane function at point X.
        `keane` accepts a matrix of size M-by-2 and returns a vetor SCORES of
        size M-by-1 in which each row contains the function value for the
        corresponding row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/keanefcn
    )pbdoc");

    m.def("leon", &leon, R"pbdoc(
        Computes the value of the Leon function.
        SCORES = leon(X) computes the value of the Leon function at point X.
        `leon` accepts a matrix of size M-by-2 and returns a vetor SCORES of
        size M-by-1 in which each row contains the function value for the
        corresponding row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/leonfcn
    )pbdoc");

    m.def("levin13", &levin13, R"pbdoc(
        Computes the value of the Levi N. 13 benchmark function.
        SCORES = levin13(X) computes the value of the L�vi N. 13 function at
        point X. `levin13` accepts a matrix of size M-by-2 and returns a
        vetor SCORES of size M-by-1 in which each row contains the function value
        for the corresponding row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/levin13fcn
    )pbdoc");

    m.def("matyas", &matyas, R"pbdoc(
        Computes the value of the Matyas benchmark function.
        SCORES = matyas(X) computes the value of the Matyas function at
        point X. `matyas` accepts a matrix of size M-by-2 and returns a
        vetor SCORES of size M-by-1 in which each row contains the function value
        for the corresponding row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/matyasfcn
    )pbdoc");

    m.def("mccormick", &mccormick, R"pbdoc(
        Computes the value of the McCormick benchmark function.
        SCORES = mccormick(X) computes the value of the McCormick function
        at point X. `mccormick` accepts a matrix of size M-by-2 and returns a
        vetor SCORES of size M-by-1 in which each row contains the function value
        for the corresponding row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/mccormickfcn
    )pbdoc");

    m.def("periodic", &periodic, R"pbdoc(
        Computes the value of the Sum Square function.
        SCORES = periodic(X) computes the value of the Periodic
        function at point X. `periodic` accepts a matrix of size M-by-N and
        returns a vetor SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/periodicfcn
    )pbdoc");

    m.def("picheny", &picheny, R"pbdoc(
        Computes the value of the Picheny benchmark function.
        SCORES = picheny(X) computes the value of the Beale function at
        point X. `picheny` accepts a matrix of size M-by-2 and returns a
        vetor SCORES of size M-by-1 in which each row contains the function value
        for the corresponding row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/pichenyfcn
    )pbdoc");

    m.def("powellsum", &powellsum, R"pbdoc(
        Computes the value of the Powell Sum benchmark function.
        SCORES = powellsum(X) computes the value of the Powell Sum function at
        point X. `powellsum` accepts a matrix of size M-by-N and returns a vetor
        SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/powellsumfcn
    )pbdoc");

    m.def("qing", &qing, R"pbdoc(
        Computes the value of the Qing function.
        SCORES = qing(X) computes the value of the Qing
        function at point X. `qing` accepts a matrix of size M-by-N and
        returns a vetor SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/qingfcn
    )pbdoc");

    m.def("quartic", &quartic, R"pbdoc(
        Computes the value of Quartic benchmark function.
        SCORES = quartic(X) computes the value of the Quartic function at
        point X. `quartic` accepts a matrix of size M-by-N and returns a vetor
        SCORES of size M-by-1 in which each row contains the function value for
        each row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/quarticfcn
    )pbdoc");

    m.def("rastrigin", &rastrigin, R"pbdoc(
        Computes the value of Rastrigin benchmark function.
        SCORES = rastrigin(X) computes the value of the Rastrigin function at
        point X. `rastrigin` accepts a matrix of size M-by-N and returns a vetor
        SCORES of size M-by-1 in which each row contains the function value for
        the corresponding row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/rastriginfcn
    )pbdoc");

    m.def("ridge", &ridge, py::arg("x"), py::arg("d") = 1, py::arg("alpha") = 0.5, R"pbdoc(
        Computes the value of the Ridge benchmark function.
        SCORES = ridge(X) computes the value of the Ridge function at point X.
        `ridge` accepts a matrix of size M-by-N and returns a vetor SCORES of
        size M-by-1 in which each row contains the function value for the
        corresponding row of X.
        SCORES = ridge(X, d=D) specifies contribution coefficient of the sphere
        component of the function.
        SCORES = ridge(X, d=D, alpha=ALPHA) specifies power of the sphere component of
        the function.
        For more information, please visit:
        benchmarkfcns.info/doc/ridgefcn
    )pbdoc");

    m.def("rosenbrock", &rosenbrock, R"pbdoc(
        Computes the value of the Rosenbrock benchmark function.
        SCORES = rosenbrock(X) computes the value of the Rosenbrock function
        at point X. `rosenbrock` accepts a matrix of size M-by-N and returns a
        vetor SCORES of size M-by-1 in which each row contains the function value
        for the corresponding row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/rosenbrockfcn
    )pbdoc");

    m.def("salomon", &salomon, R"pbdoc(
        Computes the value of the Salomon's benchmark function.
        SCORES = salomon(X) computes the value of the Salomon's
        function at point X. `salomon` accepts a matrix of size M-by-N
        and returns a vetor SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/salomonfcn
    )pbdoc");

    m.def("schaffern1", &schaffern1, R"pbdoc(
        Computes the value of the Schaffer N. 1 function.
        SCORES = schaffer1(X) computes the value of the Schaffer N. 1
        function at point X. `schaffern1` accepts a matrix of size M-by-2 and
        returns a vetor SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/schaffern1fcn
    )pbdoc");

    m.def("schaffern2", &schaffern2, R"pbdoc(
        Computes the value of the Schaffer N. 2 benchmark function.
        SCORES = schaffer2(X) computes the value of the Schaffer N. 2 function
        at point X. `schaffer2` accepts a matrix of size M-by-2 and returns a
        vetor SCORES of size M-by-1 in which each row contains the function value
        for the corresponding row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/schaffern2fcn
    )pbdoc");

    m.def("schaffern3", &schaffern3, R"pbdoc(
        Computes the value of the Schaffer N. 3 function.
        SCORES = schaffer3(X) computes the value of the Schaffer N. 3
        function at point X. `schaffer3` accepts a matrix of size M-by-2 and
        returns a vetor SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/schaffern3fcn
    )pbdoc");

    m.def("schaffern4", &schaffern4, R"pbdoc(
        Computes the value of the Schaffer N. 4 function.
        SCORES = schaffer4(X) computes the value of the Schaffer N. 4
        function at point X. `schaffer4` accepts a matrix of size M-by-2 and
        returns a vetor SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/schaffern4fcn
    )pbdoc");

    m.def("schwefel", &schwefel, R"pbdoc(
        Computes the value of the Schwefel benchmark function.
        SCORES = schwefel(X) computes the value of the Schwefel function at
        point X. `schwefel` accepts a matrix of size M-by-2 and returns a
        vetor SCORES of size M-by-1 in which each row contains the function value
        for the corresponding row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/schwefelfcn
    )pbdoc");

    m.def("schwefel220", &schwefel220, R"pbdoc(
        Computes the value of the Schwefel 2.20 function.
        SCORES = schwefel220(X) computes the value of the Schwefel 2.20
        function at point X. `schwefel220` accepts a matrix of size M-by-N and
        returns a vetor SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/schwefel220fcn
    )pbdoc");

    m.def("schwefel221", &schwefel221, R"pbdoc(
        Computes the value of the Schwefel 2.21 function.
        SCORES = schwefel221(X) computes the value of the Schwefel 2.21
        function at point X. `schwefel221` accepts a matrix of size M-by-N and
        returns a vetor SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/schwefel221fcn
    )pbdoc");

    m.def("schwefel222", &schwefel222, R"pbdoc(
        Computes the value of the Schwefel 2.22 function.
        SCORES = schwefel222(X) computes the value of the Schwefel 2.22
        function at point X. `schwefel222` accepts a matrix of size M-by-N and
        returns a vetor SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/schwefel222fcn
    )pbdoc");

    m.def("schwefel223", &schwefel223, R"pbdoc(
        Computes the value of the Schwefel 2.23 function.
        SCORES = schwefel223fcn(X) computes the value of the Schwefel 2.23
        function at point X. `schwefel223fcn` accepts a matrix of size M-by-N and
        returns a vetor SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/schwefel223fcn
    )pbdoc");

    m.def("shubert", &shubert, R"pbdoc(
        Computes the value of the Shubert function.
        SCORES = shubert(X) computes the value of the Shubert
        function at point X. `shubert` accepts a matrix of size M-by-N and
        returns a vetor SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/shubertfcn
    )pbdoc");

    m.def("shubertn3", &shubertn3, R"pbdoc(
        Computes the value of the Shubert 3 function.
        SCORES = shubert3(X) computes the value of the Shubert 3
        function at point X. `shubert3` accepts a matrix of size M-by-N and
        returns a vetor SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/shubert3fcn
    )pbdoc");

    m.def("shubertn4", &shubertn4, R"pbdoc(
        Computes the value of the Shubert 4 function.
        SCORES = shubert4(X) computes the value of the Shubert 4
        function at point X. `shubert4` accepts a matrix of size M-by-N and
        returns a vetor SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/shubert4fcn
    )pbdoc");

    m.def("sphere", &sphere, R"pbdoc(
        Computes the value of Sphere benchmark function.
        SCORES = sphere(X) computes the value of the Ackey function at
        point X. `sphere` accepts a matrix of size M-by-N and returns a vetor
        SCORES of size M-by-1 in which each row contains the function value for
        each row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/spherefcn
    )pbdoc");

    m.def("styblinskitank", &styblinskitank, R"pbdoc(
        Computes the value of the Styblinski-Tank benchmark function.
        SCORES = styblinskitank(X) computes the value of the Styblinski-Tank
        function at point X. `styblinskitank` accepts a matrix of size M-by-2
        and returns a vetor SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/styblinskitankfcn
    )pbdoc");

    m.def("sumsquares", &sumsquares, R"pbdoc(
        Computes the value of the Sum Squares function.
        SCORES = sumsquares(X) computes the value of the Sum Squares
        function at point X. `sumsquares` accepts a matrix of size M-by-N and
        returns a vetor SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/sumsquaresfcn
    )pbdoc");

    m.def("threehumpcamel", &threehumpcamel, R"pbdoc(
        Computes the value of the Three-hump camel benchmark function.
        SCORES = threehumpcamel(X) computes the value of the Three-hump camel
        function at point X. `threehumpcamel` accepts a matrix of size M-by-2
        and returns a vetor SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/threehumpcamelfcn
    )pbdoc");

    m.def("treccani", &treccani, R"pbdoc(
        Computes the value of the Treccani benchmark function.
        SCORES = treccani(X) computes the value of the Treccani
        function at point X. `treccani` accepts a matrix of size M-by-2 and
        returns a vetor SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
    )pbdoc");

    m.def("trid", &trid, R"pbdoc(
        Computes the value of the Trid benchmark function.
        SCORES = trid(X) computes the value of the Trid
        function at point X. `trid` accepts a matrix of size M-by-N and
        returns a vetor SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/tridfcn
    )pbdoc");

    m.def("vincent", &vincent, R"pbdoc(
        Computes the value of the Vincent benchmark function.
        SCORES = vincent(X) computes the value of the Vincent
        function at point X. `vincent` accepts a matrix of size M-by-N and
        returns a vetor SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
    )pbdoc");

    m.def("watson", &watson, R"pbdoc(
        Computes the value of the Watson benchmark function.
        SCORES = watson(X) computes the value of the Watson
        function at point X. `watson` accepts a matrix of size M-by-N and
        returns a vetor SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
    )pbdoc");

    m.def("wavy", &wavy, py::arg("x"), py::arg("k") = 10, R"pbdoc(
        Computes the value of the Wavy benchmark function.
        SCORES = wavy(X) computes the value of the Wavy
        function at point X and it is behaviour can be controlled with
        one additional parameters 'k'. `wavy` accepts a matrix of size M-by-2 and
        returns a vetor SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
    )pbdoc");

    m.def("wayburnseadern2", &wayburnseadern2, R"pbdoc(
        Computes the value of the Wayburn-Seader N. 2 benchmark function.
        SCORES = wayburnseadern2(X) computes the value of the Wayburn-Seader N. 2
        function at point X. `wayburnseadern2` accepts a matrix of size M-by-2 and
        returns a vetor SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
    )pbdoc");

    m.def("wolfe", &wolfe, R"pbdoc(
        Computes the value of the Wolfe function.
        SCORES = wolfe(X) computes the value of the Wolfe
        function at point X. `wolfe` accepts a matrix of size M-by-3 and
        returns a vetor SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/wolfefcn
    )pbdoc");

    m.def("xinsheyangn1", &xinsheyangn1, R"pbdoc(
        Computes the value of the Xin-She Yang function.
        SCORES = xinsheyang1(X) computes the value of the Xin-She Yang
        function at point X. `xinsheyang1` accepts a matrix of size M-by-N and
        returns a vetor SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/xinsheyangn1fcn
    )pbdoc");

    m.def("xinsheyangn2", &xinsheyangn2, R"pbdoc(
        Computes the value of the Xin-She Yang N. 2 function.
        SCORES = xinsheyang2(X) computes the value of the Xin-She Yang N. 2
        function at point X. `xinsheyang2` accepts a matrix of size M-by-N and
        returns a vetor SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
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
        returns a vetor SCORES of size P-by-1 in which each row contains the
        function value for the corresponding row of X. In this case, the default
        values of 'm=5' and 'beta=15' is used for function parameters.
        SCORES = xinsheyang3(X, beta=BETA) computes the function with the given
        value of BETA for its 'beta' parameter. In this case, the default value
        of 'm=5' will be used for the parameter.
        SCORES = xinsheyang3(X, beta=BETA, m=M) computes the function with the given
        value of M for its 'm' parameter.
        For more information, please visit:
        benchmarkfcns.info/doc/xinsheyangn3fcn
    )pbdoc");

    m.def("xinsheyangn4", &xinsheyangn4, R"pbdoc(
        Computes the value of the Xin-She Yang N. 4 function.
        SCORES = xinsheyang4(X) computes the value of the Xin-She Yang N. 4
        function at point X. `xinsheyang4` accepts a matrix of size M-by-N and
        returns a vetor SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/xinsheyangn4fcn
    )pbdoc");

    m.def("yaoliun4", &yaoliun4, R"pbdoc(
        Computes the value of the Yao-Liu N. 4 function.
        SCORES = yaoliun4(X) computes the value of the Yao-Liu N. 4
        function at point X. `yaoliun4` accepts a matrix of size M-by-N and
        returns a vetor SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
    )pbdoc");

    m.def("yaoliun9", &yaoliun9, R"pbdoc(
        Computes the value of the Yao-Liu N. 9 function.
        SCORES = yaoliun9(X) computes the value of the Yao-Liu N. 9
        function at point X. `yaoliun9` accepts a matrix of size M-by-N and
        returns a vetor SCORES of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
    )pbdoc");

    m.def("zakharov", &zakharov, R"pbdoc(
        Computes the value of Zakharov benchmark function.
        SCORES = zakharov(X) computes the value of the Zakharov function at
        point X. `zakharov` accepts a matrix of size M-by-N and returns a vetor
        SCORES of size M-by-1 in which each row contains the function value for
        each row of X.
        For more information, please visit:
        benchmarkfcns.info/doc/zakharovfcn
    )pbdoc");

    m.def("zerosum", &zerosum, R"pbdoc(
        Computes the value of the Zero Sum benchmark function.
        SCORES = zerosum(X) computes the value of the Zero Sum function at
        point X. `zerosum` accepts a matrix of size M-by-N and returns a vetor
        SCORES of size M-by-1 in which each row contains the function value for
        the corresponding row of X.
    )pbdoc");

    m.def("zettel", &zettel, R"pbdoc(
        Computes the value of the Zettel function.
        SCORES = zettel(X) computes the value of the Zettel function at point X.
        `zettel` accepts a matrix of size M-by-2 and returns a vetor SCORES of
        size M-by-1 in which each row contains the function value for the
        corresponding row of X.
    )pbdoc");

    m.def("zimmerman", &zimmerman, R"pbdoc(
        Computes the value of the Zimmerman benchmark function.
        SCORES = zimmerman(X) computes the value of the Zimmerman function at
        point X. `zimmerman` accepts a matrix of size M-by-2 and returns a vetor
        SCORES of size M-by-1 in which each row contains the function value for
        the corresponding row of X.
    )pbdoc");

    m.def("zirilli", &zirilli, R"pbdoc(
        Computes the value of the Zirilli function.
        SCORES = zirilli(X) computes the value of the Zirilli function at point X.
        `zirilli` accepts a matrix of size M-by-2 and returns a vetor SCORES of
        size M-by-1 in which each row contains the function value for the
        corresponding row of X.
    )pbdoc");


#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}
