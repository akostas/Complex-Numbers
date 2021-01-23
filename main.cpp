#include "complex.h"
#include <iostream>

using namespace std;

int main()
{
    Complex vec, vec2, vec_plus, vec_minus, vec_epi, vec_dia;
    vec.set(3,2);
    vec.out();

    vec2.set(4,6);
    vec2.out();

    vec = vec2;
    vec.out();

    vec_plus = vec + vec2;
    vec_plus.out();

    vec_minus = vec2 - Complex(2,3);
    vec_minus.out();

    vec_epi = vec * vec2;
    vec_epi.out();

    Complex vec3;
    vec2.out();
    vec2 = vec2 * 5;
    vec2.out();
    vec3.out();
    //vec.out();

    vec.out();
    vec_dia = vec2 / vec;
    vec_dia.out();

    Complex c1(2,3), t1;
    t1=c1^3.14;
    t1.out();

    cout << t1 << endl;
}