#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"

TEST_CASE("test LZespolona Suma"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 1;
    y.im = -3;

    z.re = 2;
    z.im = -2;
    
    CHECK(x+y == z);
}

TEST_CASE("test LZespolona Mnozenie"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 1;
    y.im = 0;

    z.re = 3;
    z.im = 3;
    
    CHECK(3*x*y == z);
}
TEST_CASE("test LZespolona +="){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 1;
    y.im = -3;

    z.re = 2;
    z.im = -2;
    
    CHECK(x += y == z);
}
TEST_CASE("test LZespolona dzielenie przez skalar"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 3;
    y.im = 0;

    z.re = 0.33;
    z.im = 0.33;
    
    CHECK(x / y == z);
}
TEST_CASE("test LZespolona dzielenie przez skalar"){
    LZespolona x, y, z;

    x.re = 2;
    x.im = 2;

    y.re = 4;
    y.im = 8;

    z= x / y;
    
    CHECK(x /= y == z);
}
TEST_CASE("test LZespolona odejmowanie"){
    LZespolona x, y, z;

    x.re = 4;
    x.im = 0.01;

    y.re = -5;
    y.im = 0.0099999999;

    z.re = 9;
    z.im = 0;
    
    CHECK(x - y == z);
}

TEST_CASE("test LZespolona sprawdzenie argumentu glownego"){
    LZespolona x;
    double y;
    x.re = 1;
    x.im = 1;
    y=x.arg();
    CHECK(y != 0);
}
