#include "complex.h"
#include <iostream>
#include <cmath>

Complex::Complex()
{
    this->real=0;
    this->imag=0;
}

Complex::Complex(double numR, double numI)
{
    this->real=numR;
    this->imag=numI;
}

void Complex::set(double numR, double numI)
{
    this->real=numR;
    this->imag=numI;
}

void Complex::out()
{
    std::cout << "(" << this->real << ", " << this->imag << ")" << std::endl;
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




