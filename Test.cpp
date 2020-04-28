#include "doctest.h"
#include <iostream>
#include <complex>
#include "solver.hpp"
using namespace std;
using solver::solve, solver::RealVariable, solver::ComplexVariable;

TEST_CASE("demo tests"){
    RealVariable x;

    CHECK(solve(2*x-4 == 10) == 7);
    CHECK(((solve((x^2) == 16) == 4) || (solve((x^2) == 16) == -4)));
    CHECK_THROWS(solve((x^2) == -16));
    CHECK(((solve((x^2) + 2*x + 4.0 == 20 + 6.0*x/2 - x) == 4) || (solve((x^2) + 2*x + 4.0 == 20 + 6.0*x/2 - x) == -4)));
    CHECK(solve(2*x-4.0 == 10.0) == 7);

    ComplexVariable c;
    CHECK(solve(2*c-4 == 10) == complex(7.0,0.0));
    CHECK(((solve((c^2) == 16) == complex(4.0,0.0)) || (solve((c^2) == 16) == complex(-4.0,0.0))));
    CHECK(((solve((c^2) == -16) == complex(0.0,4.0)) || (solve((c^2) == -16) == complex(0.0,-4.0))));
    CHECK(((solve((c^2) + 2*c + 4 == 20 + 6*c/2 - c) == complex(4.0,0.0)) || (solve((c^2) + 2*c + 4 == 20 + 6*c/2 - c) == complex(-4.0,0.0))));
    CHECK(solve(c+5i == 2*c+3i) == complex(0.0,2.0));
    
}

TEST_CASE("RealVarivale- monom"){
    RealVariable x;


    CHECK(solve(4*x+6 == 10) ==1);
    CHECK(solve(x*2+6 == 10) == 2);
    CHECK(solve(-16+2*x == -10) == 3);
    CHECK(solve(2*x-2-2 == 10) == 7);
    CHECK(solve((2+2)*x-10 == 10) == 5);
    CHECK(solve((-3+4)*x == 0) == 0);
    CHECK(solve((2-1)*x-4 == 2*5) == 14);
    CHECK(solve(3*x-4 == 2) == 2);
    CHECK(solve(2*x-6 == 14-6) == 7);
    CHECK(solve(x-2*x+12 == 10) == 2);
    CHECK(solve(5*x-8*x-2 == 10) == -4);
    CHECK(solve(4*x-2*x-4 == 20/2) == 7);
    CHECK(solve(-10*x/5== -6) == 3);
    CHECK(solve(1*x + 2*x - x -4 == 10) == 7);
    CHECK(solve(0 == 4*x - 4) == 1);
    CHECK(solve(3*x == 10+x) == 5);
    CHECK(solve(2*x/2-4 == 10-x) == 7);
    CHECK(solve((-6 + 3*x)/3 == 15) == 17);
    CHECK(solve(1.5*x == 9 + 2*x) == -18);
    CHECK(solve(1.5*x == 9) == 6);
    CHECK(solve(2.0*x-4.0*x == 10) == -5);
    CHECK(solve(-3+2*x/4==1) == 8);
    CHECK(solve(-4*x+4.0/2 == 10.0) == -2);
    CHECK(solve(x == x) == 0);
    CHECK(solve(x+x -3 == 3) == 3);
    CHECK(solve(x-5*x == -3*x+1) == -1);
    CHECK(solve(x+x+x+1 == 2*x) == -1);
    CHECK(solve(x - x == 2-x) ==2 );
    CHECK(solve(3.4*x - 1.4*x == 4) == 2);
    CHECK(solve(2*x+6 == x*3+9) == -3);
}

TEST_CASE("RealVariable - polynom & monom "){
    RealVariable x;
    CHECK(((solve(2*(x^2) == 8) == 2) || (solve(2*(x^2) == 8) == -2)));
    CHECK(((solve(2*(x^2)/2 -1 == 8) == 3) || (solve(2*(x^2)/2 -1 == 8) == -3)));
    CHECK(((solve((x^2) == 16) == 4) || (solve((x^2) == 16) == -4)));
    CHECK(((solve(2*x*2*x == 16) == 2) || (solve(2*x*2*x == 16) == -2)));
    CHECK(((solve(x*x + (x+x)/2 == 100 +x) == 10) || (solve(x*x + (x+x)/2 == 100 + x) == -10)));
    CHECK(((solve((x+2)*(x+2) == 16 + x*4 + 4) == 4) || (solve((x+1)*(x+1) == 16 + x*2 +1) == -4)));
    CHECK(((solve((x^2) == 9) == 3) || (solve((x^2) == 9) == -3)));
    CHECK(((solve((x^2) + 2 == 18) == 4) || (solve((x^2) + 2 == 18) == -4)));
    CHECK(((solve((x^2)*2 == 50) == 5) || (solve((x^2)*2 == 50) == -5)));
    CHECK(((solve((x^2) -2 == 4) == 6) || (solve((x^2) -2 == 34) == -6)));
    CHECK(((solve((x^2) + x/x == 50) == 7) || (solve((x^2) + x/x == 50) == -7 )));
    CHECK(((solve((x^2) -6 == 56) == 8) || (solve((x^2) -6 == 56) == -8)));
    CHECK(((solve((x^1)*9*x == 81) == 3) || (solve((x^1)*9*x == 81) == -3)));
    CHECK(((solve((x^0) +(x*2)+ (x^2) == 0) == 1)));
    CHECK(((solve((x^1) * (x^1) == 1) == 1) || (solve((x^1) *(x^1) == 1) == -1)));
    CHECK((solve((x^1) == 0) == 0));
    CHECK(solve(2*(x^2)/x == 1) == 0.5);
    CHECK(((solve((x^2) -2*x == 81 -4*x/2) == 9) || (solve((x^2) -2*x == 81 -4*x/2) == -9)));
    CHECK(((solve((x^2) + 0*x == 4) == 2) || (solve((x^2) + 0*x ==4) == -2)));
    CHECK(((solve(2*(x^2) + (x^2) == 12) == 2) || (solve(2*(x^2) + (x^2) == 12) == -2)));
    CHECK(((solve((x^2)/x +16 == 16 + x) == 0)));
    CHECK(((solve((x^2)*2/2 == 16) == 4) || (solve((x^2)*2/2 == 16) == -4)));
    CHECK(((solve(3*(x^2)/6*2 == 36) == 6) || (solve(3*(x^2)/6*2 == 36) == -6)));
    CHECK(((solve(0*(x^2)/3 +x == 12) == 12)));
    CHECK(((solve((x^2) -6*x+9) == 3)));
    CHECK(((solve(0*(x^2)/3 +x + 5*(x^2)== -1 +4*(x^2) +3*x) == 1)));
    CHECK(((solve((x^2) - 25 == 0) == 5) || (solve((x^2) - 25 == 0) == -5)));
    CHECK(((solve(0 == (x^2) -10*x +25) == 5)));
    CHECK(((solve((x^1) == 12+2+2) == 16)));
}

TEST_CASE("check throws"){
    RealVariable x;

    CHECK_THROWS(solve(x/0 == 16));
    CHECK_THROWS(solve((x^1)/(x-x) == 16));
    CHECK_THROWS(solve(x == 2+x));
    CHECK_THROWS(solve(x/x == 2));
    CHECK_THROWS(solve((x^2)*x == 0));
    CHECK_THROWS(solve((x^1)/(1-1) == 0));
    CHECK_THROWS(solve((x^2) - (x^2) - 5 == 0));
    CHECK_THROWS(solve((x^3)*x == 0));
    CHECK_THROWS(solve((x^-6) == 0));
    CHECK_THROWS(solve((x^2)*(x^1) == 0));
    CHECK_THROWS(solve((x+3)*(x^2) == 2));
    CHECK_THROWS(solve((x+3)/(x^3) == 2));
    CHECK_THROWS(solve((x+3)/(2*0) == 2));
    CHECK_THROWS(solve(x/(x-1) == 1));
    CHECK_THROWS(solve(x-x == 2));
    CHECK_THROWS(solve(6*x + 2 == 3 + 6*x));
    CHECK_THROWS(solve((x^4)/0 == 2));
}


TEST_CASE("complex - monom"){
    ComplexVariable c;
  
    CHECK(solve(c == 10) == complex(10.0,0.0));
    CHECK(solve(11*c-8 == 10*c+1) == complex(9.0,2.0));
     CHECK(solve(2*c-6-2-2*+8 == c) == complex(0.0,0.0));
    CHECK(solve(14*c+8 == complex(8.0, -56.0)) == complex(0.0,-4.0));
    CHECK(solve(4*c == 3*c) == complex(0.0,0.0));
    CHECK(solve(3*c == complex(3.0, -21.0)) == complex(0.0,21.0));
    CHECK(solve(27-3*c == 18) == complex(3.0,0.0));
    CHECK(solve(c+13 == 7) == complex(-6.0,0.0));
    CHECK(solve(2*c-c*4 == 14) == complex(-7.0,0.0));
    CHECK(solve(4*c+complex(2.0,12.0) == 0) == complex(-0.5,-3.0));
    CHECK(solve(c+complex(1.0,1.0) == 7) == complex(-6.0,-1.0));

}

TEST_CASE("complex -  polynom & monom"){
    ComplexVariable c;
    CHECK((solve(8*(c^2)+24*c +21 == 3) == complex(-1.5,0.0)));
    CHECK((solve((c^2) +2*c +1== 1) == complex(0.0,0.0) || solve((c^2) +2*c +1== 1) == complex(-2.0,0.0)));
    CHECK((solve(3*(c^2) -6*c +3 == 0) == complex(1.0,0.0)));
    CHECK((solve(4*(c^2) +16 == 0) == complex(0.0,2.0) || solve(4*(c^2) +16 == 0) == complex(0.0,-2.0)));
    CHECK((solve(2*(c^2) +3*c +12 == 0) == complex(-0.75,-sqrt(87)) || solve(2*(c^2) +3*c +12 == 0) == complex(-0.75,sqrt(87)/4)));
    CHECK((solve(5*(c^2) +12*c +20 == 0) == complex(-1.2,1.6) || solve(5*(c^2) +12*c +20 == 0) == complex(-1.2,-1.6)));
    CHECK((solve((c^2) +4*c +4 == 0) == complex(-2.0,0.0) ));
    //check maybe divide by 2
    CHECK((solve((c^2)/3 +5*c +12 == 0) == complex(-3.0,0.0) || solve((c^2)/3 +5*c +12 == 0) == complex(-12.0, 0.0)));
    CHECK((solve((c^2)/2 +3*c +21 == 0) == complex(-3.0,sqrt(33)) || solve((c^2)/2 +3*c +21 == 0) == complex(-3.0, -sqrt(33))));
    CHECK((solve((c^2) +c*3 +20== 20) == complex(0.0,0.0) || solve((c^2) +3*c +1== 1) == complex(-3.0,0.0)));
}

TEST_CASE("check throws"){
    ComplexVariable c;
    CHECK_THROWS(solve(c/0+1 == 0));
    CHECK_THROWS(solve(2*c-2*c+12 == 0));
    CHECK_THROWS(solve(4*(c^4)+12 == 28*(c^2)));
    CHECK_THROWS(solve(c-3*c/0 == 0));
    CHECK_THROWS(solve(c-c+3*(c^4) == 0));
    CHECK_THROWS(solve(-3*c/(2-2) == 0));
    CHECK_THROWS(solve((c^6)+12 == 0));
    CHECK_THROWS(solve(2*c+(c^3)+12==9));
    CHECK_THROWS(solve((c^2)+12 == (c^2)));
    CHECK_THROWS(solve(4*c+0.0 == 4*c+9));
    CHECK_THROWS(solve(-3*c/(c^3) == 0));
    CHECK_THROWS(solve(4*c+c/0 == 0));
    CHECK_THROWS(solve(4*c+12+ (c^2)/0 == c*4));
}