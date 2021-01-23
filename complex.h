#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex{
    private:
        double real, imag; // Real and imaginary part
    
    public:
        Complex();
        Complex(double, double);
        void set(double, double);
        void out();
};

#endif