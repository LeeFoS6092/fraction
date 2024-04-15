#pragma once
#include "Fraction.h"

class Complex {

private:

    Fraction _re;
    Fraction _im;

public:

    Complex();

    Complex(Fraction re, Fraction im);

    void Print();

    Complex& operator=(const Complex& tmp) {
        _re = tmp._re;
        _im = tmp._im;
        return *this;
    }

    Complex operator+(const Complex& complex) const{
        Fraction new_re = _re + complex._re;
        Fraction new_im = _im + complex._im;
        Complex result = Complex(new_re, new_im);
        return result;
    }

    Complex operator-(const Complex& complex) const{
        Fraction new_re = _re - complex._re;
        Fraction new_im = _im - complex._im;
        Complex result = Complex(new_re, new_im);
        return result;
    }

    Complex operator*(const Complex& complex) const{
        Fraction new_re = (_re * complex._re) - (_im * complex._im);
        Fraction new_im = _re * complex._im + _im * complex._re;
        Complex result = Complex(new_re, new_im);
        return result;
    }

    Complex& operator~()
    {
        _im = -_im;
        return *this;
    }

    Complex operator/(const Complex& complex) const{

        Fraction new_re = (_re * complex._re + _im * complex._im) / ((complex._re^2) + (complex._im^2));
        Fraction new_im = (_im * complex._re - _re * complex._im) / ((complex._re^2) + (complex._im^2));

        Complex result = Complex(new_re, new_im);
        return result;
    }

    friend std::ostream& operator<<(std::ostream &os, const Complex &complex) {
        if (complex._re == 0 && complex._im != 0) {
            return os << complex._im << "i" << std::endl;
        } else if (complex._im < 0) {
            Fraction fr = complex._im;
            return os << complex._re << " - " << -fr << "i" << std::endl;
        } else if (complex._im == 1) {
            return os << complex._re << " + " << "i" << std::endl;
        } else if (complex._im == -1) {
            return os << complex._re << " - " << "i" << std::endl;
        } else if (complex._im == 0) {
            return os << complex._re << std::endl;
        } else {
            return os << complex._re << " + " << complex._im << "i" << std::endl;
        }
    }

};