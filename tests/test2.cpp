#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"

TEST_CASE("Test LZespolona dzielenie przez skalar 1") {
    LZespolona x, y;
    double t = 2;
    
    x.re = 2;
    x.im = 2;

    y.re = 1;
    y.im = 1;
   
    CHECK(x/t == y);
}



TEST_CASE("Test LZespolona dzielenie przez skalar - zero") {
    LZespolona x,y;
    double t = 0;
    
    x.re = 2;
    x.im = 2;
 
    y.re=0;
    y.im=0;
   CHECK(x/t==y);
}

TEST_CASE("Test LZespolona dzielenie przez liczbe zespolona- zero") {
    LZespolona x,y,z;
    
    x.re = 2;
    x.im = 2;
 
    y.re=0;
    y.im=0;

    z.re=0;
    z.im=0;
   CHECK(x/y==z);
}