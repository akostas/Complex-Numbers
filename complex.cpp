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
    this->type = a.type;
}

Complex Complex::operator+(Complex a)
{
    Complex add;
    add.type = a.type;
    switch(a.type)
    {
        case 0:
            add.real = this->real + a.real;
            add.imag = this->imag + a.imag;
            break;
            //return Complex(this->real + a.real, this->imag + a.imag);
        case 1:
            add.real = sqrt(this->real*this->real+a.real*a.real + 2*this->real*a.real*cos(this->imag-a.imag));
            add.imag = atan((this->real*sin(this->imag)+a.real*sin(a.imag))/(this->real*cos(this->imag)+a.real*cos(a.imag)));
            break;
            //return Complex(sqrt(this->real*this->real+a.real*a.real + 2*this->real*a.real*cos(this->imag-a.imag)), \
            atan((this->real*sin(this->imag)+a.real*sin(a.imag))/(this->real*cos(this->imag)+a.real*cos(a.imag))),1);
    }
    return add;
}

Complex Complex::operator-(Complex a)
{
    Complex dif;
    dif.type = a.type;
    switch(a.type)
    {
        case 0:
            dif.real = this->real - a.real;
            dif.imag = this->imag - a.imag;
            break;
            //return Complex(this->real - a.real, this->imag - a.imag);
        case 1:
            dif.real = sqrt(this->real*this->real+a.real*a.real - 2*this->real*a.real*cos(this->imag-a.imag));
            dif.imag = atan((this->real*sin(this->imag)-a.real*sin(this->imag))/(this->real*cos(a.imag)-a.real*cos(this->imag)));
            break;
            //return Complex(sqrt(this->real*this->real+a.real*a.real - 2*this->real*a.real*cos(this->imag-a.imag)), \
            atan((this->real*sin(this->imag)-a.real*sin(this->imag))/(this->real*cos(a.imag)-a.real*cos(this->imag))),1);
    }
    return dif;
}

Complex Complex::operator*(Complex a)
{
    Complex gin;
    gin.type = a.type;
    switch(a.type)
    {
        case 0:
            gin.real = this->real*a.real - this->imag*a.imag;
            gin.imag = this->real*a.imag + this->imag*a.real;
            break;
        case 1:
            gin.real = this->real * a.real;
		    gin.imag = (this->imag + a.imag);
            break;
    }
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
    Complex div;
    div.type = a.type;
    switch(a.type)
    {
        case 0:
            div.real = (this->real*a.real + this->imag*a.imag) / (a.real*a.real + a.imag*a.imag);
            div.imag = (this->imag*a.real - this->real*a.imag) / (a.real*a.real + a.imag*a.imag);
            break;
        case 1:
            div.real = this->real / a.real;
            div.imag = this->imag - a.imag;
            break;
    }
    return div;
}

Complex Complex::operator^(double a)
{
    Complex power;
    power.type = this->type;
    switch(this->type)
    {
        case 0:
            power.real = pow((this->real*this->real + this->imag*this->imag),(a/2))*cos(a*atan2(this->imag, this->real));
            power.imag = pow((this->real*this->real + this->imag*this->imag),(a/2))*sin(a*atan2(this->imag, this->real));
            break;
        case 1:
            power.real = pow(this->real, a);
            power.imag = this->imag*a;
            break;
    }
    return power;
}


