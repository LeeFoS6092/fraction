#include "Complex.h"

Complex::Complex() {
    _re = 0;
    _im = 0;
}

void Complex::Print() {
    std::cout << _re << " + " << _im << "i" << std::endl;
}

Complex::Complex(Fraction re, Fraction im) {

    bool sign;
    
    if (im < 0) {
        sign = false;
    } else {
        sign = true;
    }

    _re = re;
    _im = im;
}