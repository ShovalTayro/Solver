#include "solver.hpp"
#include <stdio.h>
#include <string>

using namespace std;
namespace solver{
    RealVariable operator^ (const RealVariable& x, const double n){
        if(n == 0) return RealVariable(0,0,1);
        else if(n == 1) return RealVariable(0,1,0);
        else if(n == 2) return RealVariable(1,0,0);
        else __throw_invalid_argument("The power can't be more than 2 or negative");
    }
    
    RealVariable operator* (const RealVariable& x, const double n){
        return RealVariable(x.a*n, x.b*n,x.c*n);
    }
    
    RealVariable operator* (const double n, const RealVariable& x){
        return RealVariable(x.a*n, x.b*n,x.c*n);
    }
    
    RealVariable operator* (const RealVariable& x, const RealVariable& y){
        //check the power of x &y if the multiplaxing will give us power >2 error
        if(x.a!=0 && y.a!=0) __throw_invalid_argument("The power is bigger then 2 , can't multiple this numbers");
        if(x.a!=0 && y.b!=0) __throw_invalid_argument("The power is bigger then 2 , can't multiple this numbers");
        if(x.b!=0 && y.a!=0) __throw_invalid_argument("The power is bigger then 2 , can't multiple this numbers");
        //can make the operator
        return RealVariable(x.a * y.a + x.a * y.b + x.a * y.c,
                            x.b * y.a + x.b * y.b + x.b * y.c,
                            x.c * y.a + x.c * y.b + x.c * y.c);
    }

    RealVariable operator/ (const RealVariable& x, const double n){
        if(n==0) __throw_invalid_argument("Error - divideed by zero");
        return RealVariable((x.a)/n, (x.b)/n, (x.c)/n);
    }

    friend RealVariable operator/ (const double n, const RealVariable& y){
        /*
        ***************************
        *****************************
        ***************************88
    */
    }
    
    RealVariable operator/ (const RealVariable& x, const RealVariable& y){
      /*
        ********************
        ********************
        ********************
    */
    }
    
    RealVariable operator- (const double n, const RealVariable& x){
        return RealVariable(x.a, x.b , x.c - n);
    }
    
    RealVariable operator- (const RealVariable& x, const double n){
        return RealVariable(x.a, x.b , x.c - n);
    }
    
    RealVariable operator- (const RealVariable& x,const RealVariable& y){
        return RealVariable(x.a - y.a, x.b - y.b, x.c - y.c);
    }
    
    RealVariable operator+ (const double n, const RealVariable& x){
        return RealVariable(x.a, x.b , x.c + n);
    }
    
    RealVariable operator+ (const RealVariable& x, const double n){
        return RealVariable(x.a, x.b , x.c + n);
    }
    
    RealVariable operator+ (const RealVariable& x, const RealVariable& y){
        return RealVariable(x.a + y.a, x.b + y.b, x.c + y.c);
    }
    
    RealVariable operator== (const double n, const RealVariable& x){
        return x-n;
    }
    
    RealVariable operator== (const RealVariable& x, const double n){
        return x-n;
    }
    
    RealVariable operator== (const RealVariable& x, const RealVariable& y){
        return x-y;
    }
     
    //complex

    ComplexVariable operator^ (const ComplexVariable& x, const complex<double> n){
        if(n.imag() != 0) throw invalid_argument("The power isn't valid");
        if(n.real() == 2) {
            return ComplexVariable(complex(1.0,0.0),complex(0.0,0.0),complex(0.0,0.0));
        }
        if (n.real() == 1) {
            return ComplexVariable(complex(0.0,0.0),complex(1.0,0.0),complex(0.0,0.0));
        }
        if (n.real() == 0) {
            return ComplexVariable(complex(0.0,0.0),complex(0.0,0.0),complex(1.0,0.0));
        }
        throw invalid_argument("power is not vaild: ");
    }

    ComplexVariable operator* (const ComplexVariable& x, const complex<double> n) {
        return ComplexVariable(x.a*n, x.b*n, x.c*n);
    }s

    ComplexVariable operator* (const complex<double> n , const ComplexVariable& x) {
        return ComplexVariable(x.a*n, x.b*n, x.c*n);
    }

    ComplexVariable operator* (const ComplexVariable& x, const ComplexVariable& y){
        //check if we can make * operator - there is a limit:  power<=2 
        if(x.a != complex(0,0) && y.a != complex(0,0)) __throw_invalid_argument("The power is bigger then 2 , can't multiple this numbers");
        if(x.a != complex(0,0) && y.b != complex(0,0)) __throw_invalid_argument("The power is bigger then 2 , can't multiple this numbers");
        if(x.b != complex(0,0) && y.a != complex(0,0)) __throw_invalid_argument("The power is bigger then 2 , can't multiple this numbers");
        //can make the operator
        return RealVariable(x.a * y.a + x.a * y.b + x.a * y.c,
                            x.b * y.a + x.b * y.b + x.b * y.c,
                            x.c * y.a + x.c * y.b + x.c * y.c);
    }

    ComplexVariable operator/ (const ComplexVariable& x, const complex<double> n){
        if (n == complex(0.0,0.0)) __throw_invalid_argument("canwt divide by zero");
        return ComplexVariable((x.a)/n, (x.b)/n , (x.c)/n);
    }

    ComplexVariable operator/ (const complex<double> n, const ComplexVariable& y){
        /*
        *****************************
        *****************************
        *****************************
    */
    }
    
    ComplexVariable operator/ (const ComplexVariable& x, const ComplexVariable& y){
      /*
        *****************************
        *****************************
        *****************************
    */
    }

    ComplexVariable operator- (const ComplexVariable& x, const complex<double> n){
        return ComplexVariable(x.a, x.b , x.c-n);   
    }
    
    ComplexVariable operator- (const complex<double> n , const ComplexVariable& x) {
        return ComplexVariable(-x.a, -x.b , -x.c+n);
    }

    ComplexVariable operator- (const ComplexVariable& x, const ComplexVariable& y) {
        return ComplexVariable(x.a - y.a , x.b - y.b , x.c - y.c);
    }

    ComplexVariable operator+ (const ComplexVariable& x, const complex<double> n) {
        return ComplexVariable(x.a, x.b , x.c+n);
    }
    
    ComplexVariable operator+ (const complex<double> n , const ComplexVariable& x) {
        return ComplexVariable(x.a, x.b , x.c+n);
    }

    ComplexVariable operator+ (const ComplexVariable& x, const ComplexVariable& y) {
        return ComplexVariable(x.a + y.a , x.b + y.b , x.c + y.c);
    }
    
    ComplexVariable operator== (const complex<double> n, const ComplexVariable& x){
        return n-x;
    }
    
    ComplexVariable operator== (const ComplexVariable& x, const complex<double> n){
        return x-n;
    }
    
    ComplexVariable operator== (const ComplexVariable& x, const ComplexVariable& y){
        return x-y;
    }  

    double solve(const RealVariable &x){
        //not yet
        return 2.5;
    }
    complex<double> solve(const ComplexVariable &x){
        //not yet
        std::complex<double> a(1,1);
        return a;
    }
}

 