#pragma once
#include <complex>

using namespace std;

namespace solver{

    class RealVariable
    {
        public:
        double a;
        double b;
        double c;

        public:
        RealVariable() : a(0), b(1), c(0) {}
        
        RealVariable(double a, double b, double c){
            this->a = a;
            this->b = b;
            this->c = c;
        }
    
        friend RealVariable operator^ (const RealVariable& x, const double n);
        
        friend RealVariable operator* (const RealVariable& x, const double n);
        friend RealVariable operator* (const double n, const RealVariable& x);
        friend RealVariable operator* (const RealVariable& x, const RealVariable& y);
        
        friend RealVariable operator/ (const RealVariable& x, const double n);
        friend RealVariable operator/ (const RealVariable& x, const RealVariable& y);
        
        friend RealVariable operator- (const double n, const RealVariable& x);
        friend RealVariable operator- (const RealVariable& x, const double n);
        friend RealVariable operator- (const RealVariable& x,const RealVariable& y);

        friend RealVariable operator+ (const double n, const RealVariable& x);
        friend RealVariable operator+ (const RealVariable& x, const double n);
        friend RealVariable operator+ (const RealVariable& x, const RealVariable& y);
        
        friend RealVariable operator== (const double n, const RealVariable& x);
        friend RealVariable operator== (const RealVariable& x, const double n);
        friend RealVariable operator== (const RealVariable& x, const RealVariable& y);
    };

    class ComplexVariable
    {
        public:
        complex<double> a;
        complex<double> b;
        complex<double> c;


        public: 
        ComplexVariable() : a(0.0), b(1.0,0.0), c(0.0) {}
        
        ComplexVariable(complex<double> a, complex<double> b, complex<double> c){
            this->a = complex(a);
            this->b = complex(b);
            this->c = complex(c);
        }

    
        friend ComplexVariable operator^ (const ComplexVariable& x, const complex<double> n);
        
        friend ComplexVariable operator* (const ComplexVariable& x, const complex<double> n);
        friend ComplexVariable operator* (const complex<double> n, const ComplexVariable& x);
        friend ComplexVariable operator* (const ComplexVariable& x, const ComplexVariable& y);
        
        friend ComplexVariable operator/ (const ComplexVariable& x, const complex<double> n);
        friend ComplexVariable operator/ (const ComplexVariable& x, const ComplexVariable& y);
        
        friend ComplexVariable operator- (const complex<double> n, const ComplexVariable& x);
        friend ComplexVariable operator- (const ComplexVariable& x, const complex<double> n);
        friend ComplexVariable operator- (const ComplexVariable& x, const ComplexVariable& y);
        
        friend ComplexVariable operator+ (const complex<double> n, const ComplexVariable& x);
        friend ComplexVariable operator+ (const ComplexVariable& x, const complex<double> n);
        friend ComplexVariable operator+ (const ComplexVariable& x,const ComplexVariable& y);

        friend string operator+ (const string s ,const ComplexVariable& x);
        friend string operator+ (const ComplexVariable& x,const string s);
        
        friend ComplexVariable operator== (const complex<double> n, const ComplexVariable& x);
        friend ComplexVariable operator== (const ComplexVariable& x, const complex<double> n);
        friend ComplexVariable operator== (const ComplexVariable& x, const ComplexVariable& y);
    };

    double solve(const RealVariable &x);
    complex<double> solve(const ComplexVariable &x);
};
