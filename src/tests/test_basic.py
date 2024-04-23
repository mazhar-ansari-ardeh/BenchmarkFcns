from __future__ import annotations

from math import pi, sqrt

import benchmarkfcns as m
import numpy as np
import pytest


def test_version():
    assert m.__version__ == "2.0.0"


def test_ackley():
    fcn = m.ackley
    assert fcn([[0, 0]]) == 0
    assert fcn([[0, 0, 0]]) == 0
    assert (fcn([[0] * 10] * 100) == np.zeros([100, 1])).all()


def test_ackley2():
    fcn = m.ackley2
    assert fcn([[0, 0]]) == -200
    assert (fcn([[0] * 2] * 100) == np.array([-200] * 100)).all()


def test_ackley3():
    fcn = m.ackley3
    assert fcn([[0.682584587365898, -0.36075325513719]]).round(3) == round(
        -170.07756299785044, 3
    )
    assert fcn([[-0.682584587365898, -0.36075325513719]]).round(3) == round(
        -170.07756299785044, 3
    )


def test_ackley4():
    fcn = m.ackley4
    assert fcn([[-1.51, -0.755]]).round(4) == round(-4.590101633799122, 4)


def test_adjiman():
    fcn = m.adjiman
    assert fcn([[0, 0]]) == 0
    assert fcn([[1, 0]]) == -1
    assert fcn([[10, 0]]) == -10


def test_alpine1():
    fcn = m.alpine1
    assert fcn([[0, 0]]) == 0
    assert fcn([[0, 0, 0]]) == 0
    assert (fcn([[0] * 10] * 100) == np.zeros([100, 1])).all()


def test_alpine2():
    fcn = m.alpine2
    x = 7.9170526982459462172
    y = 2.8081311800070053291
    assert fcn([[x, x]]).round(3) == round(y * y, 3)
    assert (
        fcn([[x] * 10] * 100).round(3) == np.array([round(pow(y, 10), 3)] * 100)
    ).all()


def test_bartels_conn():
    fcn = m.bartelsconn
    assert fcn([[0, 0]]) == 1
    assert (fcn([[0] * 2] * 100) == np.ones([100, 1])).all()


def test_beale():
    fcn = m.beale
    assert fcn([[3, 0.5]]) == 0
    assert (fcn([[3, 0.5]] * 100) == np.zeros([100, 1])).all()


def test_bird():
    fcn = m.bird
    x = [4.70104, 3.15294]
    y = -106.764537
    assert fcn([x]).round(3) == round(y, 3)
    assert (fcn([x] * 100).round(3) == np.array([round(y, 3)] * 100)).all()


def test_bohachevsky2():
    fcn = m.bohachevsky2
    assert fcn([[0, 0]]) == 0
    assert (fcn([[0] * 2] * 100) == np.zeros([100, 1])).all()


def test_booth():
    fcn = m.booth
    x = [1, 3]
    y = 0
    assert fcn([x]) == y
    assert (fcn([x] * 100) == np.array([y] * 100)).all()


def test_dropwave():
    fcn = m.dropwave
    x = [0, 0]
    y = -1
    assert fcn([x]) == y
    assert (fcn([x] * 100) == np.array([y] * 100)).all()


def test_easom():
    fcn = m.easom
    x = [pi, pi]
    y = -1
    assert fcn([x]) == y
    assert (fcn([x] * 100) == np.array([y] * 100)).all()


def test_eggcrate():
    fcn = m.eggcrate
    x = [0, 0]
    y = 0
    assert fcn([x]) == y
    assert (fcn([x] * 100) == np.array([y] * 100)).all()


def test_expontial():
    fcn = m.exponential
    x = [0, 0]
    y = -1
    assert fcn([x]) == y
    assert (fcn([x] * 100) == np.array([y] * 100)).all()


def test_goldsteinprice():
    fcn = m.goldsteinprice
    x = [0, -1]
    y = 3
    assert fcn([x]) == y
    assert (fcn([x] * 100) == np.array([y] * 100)).all()
    with pytest.raises(ValueError, match="function is only defined on a 2D space"):
        fcn([[1, 2, 3]])


def test_griewank():
    fcn = m.griewank
    x = [0]
    y = 0
    assert fcn([x]) == y
    assert (fcn([x] * 100) == np.array([y] * 100)).all()


def test_happycat():
    fcn = m.happycat
    x = [-1]
    y = 0
    assert fcn([x]) == y
    assert (fcn([x] * 100) == np.array([y] * 100)).all()


def test_himmelblau():
    fcn = m.himmelblau
    x = [3, 2]
    y = 0
    assert fcn([x]) == y
    assert (fcn([x] * 100) == np.array([y] * 100)).all()
    with pytest.raises(ValueError, match="function is only defined on a 2D space"):
        fcn([[1, 2, 3]])


def test_leon():
    fcn = m.leon
    x = [1, 1]
    y = 0
    assert fcn([x]) == y
    assert (fcn([x] * 100) == np.array([y] * 100)).all()
    with pytest.raises(ValueError, match="function is only defined on a 2D space"):
        fcn([[1, 2, 3]])


def test_levin13():
    fcn = m.levin13
    x = [1, 1]
    y = 0
    assert fcn([x]).round(20) == y
    assert (fcn([x] * 100).round(20) == np.array([y] * 100)).all()
    with pytest.raises(ValueError, match="function is only defined on a 2D space"):
        fcn([[1, 2, 3]])


def test_matyas():
    fcn = m.matyas
    x = [0, 0]
    y = 0
    assert fcn([x]) == y
    assert (fcn([x] * 100) == np.array([y] * 100)).all()
    with pytest.raises(ValueError, match="function is only defined on a 2D space"):
        fcn([[1, 2, 3]])


def test_periodic():
    fcn = m.periodic
    x = [0, 0]
    y = 0.9
    assert fcn([x]) == y
    assert (fcn([x * 10] * 100) == np.array([y] * 100)).all()


def test_powellsum():
    fcn = m.powellsum
    x = [0]
    y = 0
    assert fcn([x]) == y
    assert (fcn([x] * 100) == np.array([y] * 100)).all()


def test_qing():
    fcn = m.qing
    x = [sqrt(i) for i in range(1, 10)]
    y = 0
    assert fcn([x]).round(10) == y
    assert (fcn([x] * 100).round(10) == np.array([y] * 100)).all()


def test_rastrigin():
    fcn = m.rastrigin
    assert fcn([[0, 0]]) == 0
    assert fcn([[0, 0, 0]]) == 0
    assert (fcn([[0] * 10] * 100) == np.zeros([100, 1])).all()


def test_ridge():
    fcn = m.ridge
    assert fcn([[-1, 0]]) == -1
    assert fcn([[-2, 0, 0]]) == -2
    assert (fcn([[-1, 0, 0, 0, 0]] * 100) == np.array([-1] * 100)).all()


def test_rosenbrock():
    fcn = m.rosenbrock
    x = 1
    y = 0
    assert fcn([[x, x]]) == y
    assert (fcn([[x] * 10] * 100) == np.array([y] * 100)).all()


def test_salomon():
    fcn = m.salomon
    x = 0
    y = 0
    assert fcn([[x, x]]) == y
    assert (fcn([[x] * 10] * 100) == np.array([y] * 100)).all()


def test_schaffer1():
    fcn = m.schaffer1
    x = 0
    y = 0
    assert fcn([[x, x]]) == y
    with pytest.raises(ValueError, match="function is only defined on a 2D space"):
        fcn([[1, 2, 3]])


def test_schaffer2():
    fcn = m.schaffer2
    x = 0
    y = 0
    assert fcn([[x, x]]) == y
    with pytest.raises(ValueError, match="function is only defined on a 2D space"):
        fcn([[1, 2, 3]])


def test_schwefel220():
    fcn = m.schwefel220
    x = 0
    y = 0
    assert fcn([[x, x]]) == y
    assert (fcn([[x] * 10] * 100) == np.array([y] * 100)).all()


def test_schwefel221():
    fcn = m.schwefel221
    x = 0
    y = 0
    assert fcn([[x, x]]) == y
    assert (fcn([[x] * 10] * 100) == np.array([y] * 100)).all()


def test_schwefel222():
    fcn = m.schwefel222
    x = 0
    y = 0
    assert fcn([[x, x]]) == y
    assert (fcn([[x] * 10] * 100) == np.array([y] * 100)).all()


def test_schwefel223():
    fcn = m.schwefel223
    x = 0
    y = 0
    assert fcn([[x, x]]) == y
    assert (fcn([[x] * 10] * 100) == np.array([y] * 100)).all()


def test_sphere():
    fcn = m.sphere
    assert fcn([[0, 0]]) == 0
    assert fcn([[0, 0, 0]]) == 0
    assert (fcn([[0] * 10] * 100) == np.zeros([100, 1])).all()


def test_styblinskitank():
    fcn = m.styblinskitank
    x = -2.903534
    y = -39.16616570377140
    assert fcn([[x, x]]) == round(y * 2, 20)
    assert (fcn([[x] * 10] * 100) == np.array([y * 10] * 100)).all()


def test_sumsquares():
    fcn = m.sumsquares
    x = 0
    y = 0
    assert fcn([[0, 0]]) == y
    assert (fcn([[x] * 10] * 100) == np.array([y] * 100)).all()


def test_threehumpcamel():
    fcn = m.threehumpcamel
    x = 0
    y = 0
    assert fcn([[0, 0]]) == y
    assert (fcn([[x] * 2] * 100) == np.array([y] * 100)).all()


def test_wolfe():
    fcn = m.wolfe
    x = 0
    y = 0
    assert fcn([[0, 0, 0]]) == y
    assert (fcn([[x] * 3] * 100) == np.array([y] * 100)).all()


def test_xinsheyang1():
    fcn = m.xinsheyang1
    x = 0
    y = 0
    assert fcn([[0, 0]]) == y
    assert (fcn([[x] * 10] * 100) == np.array([y] * 100)).all()


def test_xinsheyang2():
    fcn = m.xinsheyang2
    x = 0
    y = 0
    assert fcn([[0, 0]]) == y
    assert (fcn([[x] * 10] * 100) == np.array([y] * 100)).all()


def test_xinsheyang3():
    fcn = m.xinsheyang3
    x = 0
    y = -1
    assert fcn([[0, 0]]) == y
    assert (fcn([[x] * 10] * 100) == np.array([y] * 100)).all()


def test_xinsheyang4():
    fcn = m.xinsheyang4
    x = 0
    y = -1
    assert fcn([[0, 0]]) == y
    assert (fcn([[x] * 10] * 100) == np.array([y] * 100)).all()


def test_zakharov():
    fcn = m.zakharov
    assert fcn([[0, 0]]) == 0
    assert fcn([[0, 0, 0]]) == 0
    assert (fcn([[0] * 10] * 100) == np.zeros([100, 1])).all()
