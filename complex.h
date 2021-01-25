#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex{
    private:
        double real, imag; // Real and imaginary part
        bool type; // Define type of coordinates
        

    public:
        Complex();
        Complex(double, double, bool t=0);
        void set(double, double, bool t=0);
        void out();
        void operator=(Complex);
        Complex operator+(Complex);
        Complex operator-(Complex);
        Complex operator*(Complex);
        Complex operator*(double);
        Complex operator*(int);
        Complex operator/(Complex);
        Complex operator^(double);
        Complex convert2polar();
        Complex convert2carte();
};

#endif