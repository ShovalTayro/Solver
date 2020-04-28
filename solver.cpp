#include "solver.hpp"
#include <stdio.h>
#include <string>
#include <complex>

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
        return RealVariable(x.a * y.c + y.a * x.c + x.c * y.b,
                            x.b * y.c + y.b * x.c,
                            x.c * y.c);
    }

    RealVariable operator/ (const RealVariable& x, const double n){
        if(n==0) __throw_invalid_argument("Error - divideed by zero");
        return RealVariable((x.a)/n, (x.b)/n, (x.c)/n);
    }

    RealVariable operator/ (const double n, const RealVariable& y){
        /*
        *********************
        *********************
        *********************
    */
   return RealVariable(0,0,0);
    }
    
    RealVariable operator/ (const RealVariable& x, const RealVariable& y){
      /*
        ********************
        ********************
        ********************
    */
   return RealVariable(0,0,0);
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
    }

    ComplexVariable operator* (const complex<double> n , const ComplexVariable& x) {
        return ComplexVariable(x.a*n, x.b*n, x.c*n);
    }

    ComplexVariable operator* (const ComplexVariable& x, const ComplexVariable& y){
        //check if we can make * operator - there is a limit:  power<=2 
        if(x.a != complex(0.0,0.0) && y.a != complex(0.0,0.0)) __throw_invalid_argument("The power is bigger then 2 , can't multiple this numbers");
        if(x.a != complex(0.0,0.0) && y.b != complex(0.0,0.0)) __throw_invalid_argument("The power is bigger then 2 , can't multiple this numbers");
        if(x.b != complex(0.0,0.0) && y.a != complex(0.0,0.0)) __throw_invalid_argument("The power is bigger then 2 , can't multiple this numbers");
        //can make the operator
        return ComplexVariable(x.a * y.c + y.a * x.c + x.c * y.b,
                            x.b * y.c + y.b * x.c,
                            x.c * y.c);
    }

    ComplexVariable operator/ (const ComplexVariable& x, const complex<double> n){
        if (n == complex(0.0,0.0)) __throw_invalid_argument("can't divide by zero");
        return ComplexVariable((x.a)/n, (x.b)/n , (x.c)/n);
    }

    ComplexVariable operator/ (const complex<double> n, const ComplexVariable& y){
        /*
        *******************
        *******************
        *******************
        */
       return ComplexVariable(0.0, 0.0 , 0.0);
    }
    
    ComplexVariable operator/ (const ComplexVariable& x, const ComplexVariable& y){
        if(y.a == complex<double>(0.0,0.0) &&
           y.b == complex<double>(0.0,0.0) && 
           y.c == complex<double>(0.0,0.0)) __throw_invalid_argument("can't divided by zero");
        
        else if(y.a == complex<double>(0.0,0.0) &&
           y.b == complex<double>(0.0,0.0) && 
           y.c != complex<double>(0.0,0.0)) return ComplexVariable(x.a / y.c , x.b / y.c, x.c / y.c);

        else if(y.a == complex<double>(0.0,0.0) &&
           y.b != complex<double>(0.0,0.0) && 
           y.c == complex<double>(0.0,0.0)) return ComplexVariable(0, x.b / y.b , 0);

        else if(y.a != complex<double>(0.0,0.0) &&
           y.b != complex<double>(0.0,0.0) && 
           y.c == complex<double>(0.0,0.0)) return ComplexVariable(x.a / y.a, x.b / y.b , 0);

        else __throw_invalid_argument("can't divied")
        
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
        double a = x.a;
        double b = x.b;
        double c = x.c;
        //if it is a linear equation
        if(a == 0) {
            //if there is no X
            if(b == 0 && c != 0) __throw_invalid_argument("To the equation have no solution");
            else return c/-b;
        }

        if((-b + b*b -4*a*c) >= 0){
            return ( (-b + sqrt(-b + b*b -4*a*c)) / (2*a) );
        }
        else __throw_invalid_argument("There is no real solution");
    }

    complex<double> solve(const ComplexVariable &x){
        complex<double> a = x.a;
        complex<double> b = x.b;
        complex<double> c = x.c;
        
        //if it is a linear equation
        if(a == complex(0.0,0.0)) {
            //if there is no X
            if(b == complex(0.0,0.0) && c != complex(0.0,0.0)) __throw_runtime_error("To the equation have no solution");
            else return c/-b;
        }
        return ( (-b + sqrt(-b + b*b -complex(4.0,0.0)*a*c)) / (complex(2.0,0.0)*a) );
    }
}

 