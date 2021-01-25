#include "complex.h"
#include <iostream>
#include <cmath>

Complex::Complex()
{
    this->real=0; this->imag=0;
    this->type=0;
}

Complex::Complex(double numR, double numI, bool t)
{
    this->real=numR;
    this->imag=numI;
}

void Complex::set(double numR, double numI, bool t)
{
    this->real=numR;
    this->imag=numI;
    this->type=t;
}

void Complex::out()
{  
    if( this->type == 0 )   std::cout << "(" << this->real << ", " << this->imag << ")" << std::endl;
    else   std::cout << "(" << this->real << " <" << this->imag << ")" << std::endl;
}

void Complex::operator=(Complex a)
{
    this->real = a.real;
    this->imag = a.imag;
}

Complex Complex::operator+(Complex a)
{
    return Complex(this->real + a.real, this->imag + a.imag);
}

Complex Complex::operator-(Complex a)
{
    return Complex(this->real - a.real, this->imag - a.imag);
}

Complex Complex::operator*(Complex a)
{
    Complex gin;
    gin.real = this->real*a.real - this->imag*a.imag;
    gin.imag = this->real*a.imag + this->imag*a.real;
    return gin;	
}

Complex Complex::operator*(double a)
{
    Complex gin;
    gin.real = this->real*a;
    gin.imag = this->imag*a;
    return gin;	
}

Complex Complex::operator*(int a)
{
    Complex gin;
    gin.real = this->real*a;
    gin.imag = this->imag*a;
    return gin;	
}

Complex Complex::operator/(Complex a)
{
    Complex gin;
    gin.real = (this->real*a.real + this->imag*a.imag) / (a.real*a.real + a.imag*a.imag);
    gin.imag = (this->imag*a.real - this->real*a.imag) / (a.real*a.real + a.imag*a.imag);
    return gin;
}

Complex Complex::operator^(double a)
{
    Complex power;
    power.real = pow((this->real*this->real + this->imag*this->imag),(a/2))*cos(a*atan2(this->imag, this->real));
    power.imag = pow((this->real*this->real + this->imag*this->imag),(a/2))*sin(a*atan2(this->imag, this->real));
    return power;
}


