#pragma once
#include <cstdint>
#include <iostream>
#include <math.h>

class Fraction {

private:

    int32_t _numerator;
    uint32_t _denominator;

public:

    Fraction();

    Fraction(double result) {
        double res = result;

        if (res != 0) {
            GetFraction(res, 6);
            Drop(_numerator, _denominator);
        } else {
            _numerator = 0;
            _denominator = 1;
        }
    }

    Fraction(int32_t nom, uint32_t den) {
        _numerator = nom;
        if (den != 0) {
            _denominator = den;
        } else {
            throw "Error: Denominator is 0!";
        }

        Drop(_numerator, _denominator);
    }

    void GetFraction(double res, int deg) {
        int numerator, denominator;

        int x,y;

        x = floor(res);

        y = floor((res - x) * pow(10, deg));

        if (y % 100000 == 99999 || y % 10000 == 9999 || y % 1000 == 999) {
            y += 1;
        }

        denominator = pow(10, deg);

        numerator = x * denominator + y;

        _numerator = numerator;
        _denominator = denominator;
    }

    void Drop(int32_t numerator, uint32_t denominator) {

        int sign = 1;

        if (numerator < 0) {
            sign = 0;
        } else {
            sign = 1;
        }

        
        numerator = fabs(numerator);

        if (numerator > denominator) {
            for (int i = denominator; i > 1; i--) {
                if (numerator % i == 0 && denominator % i == 0) {
                    numerator = numerator / i;
                    denominator = denominator / i;
                    break;
                }
            }
        } else if (numerator < denominator) {
            for (int i = numerator; i > 1; i--) {
                if (numerator % i == 0 && denominator % i == 0) {
                    numerator = numerator / i;
                    denominator = denominator / i;
                    break;
                }
            }
        } else if (numerator == denominator) {
            numerator = 1;
            denominator = 1;
        }

        _numerator = numerator;
        _denominator = denominator;

        if (sign == 0) {
            _numerator = -numerator;
        }
    }

    Fraction& operator=(const Fraction& tmp) {
        _numerator = tmp._numerator;
        _denominator = tmp._denominator;
        return *this;
    }

    Fraction operator+(const Fraction& fraction) const{
        int32_t new_numerator = fraction._numerator * _denominator + _numerator * fraction._denominator;
        uint32_t new_denominator = fraction._denominator * _denominator;
        Fraction result = Fraction(new_numerator, new_denominator);
        return result;
    }

    Fraction operator-(const Fraction& fraction) const{
        int32_t new_numerator = _numerator * fraction._denominator - fraction._numerator * _denominator;
        uint32_t new_denominator = fraction._denominator * _denominator;
        Fraction result = Fraction(new_numerator, new_denominator);
        return result;
    }

    Fraction operator*(const Fraction& fraction) const{
        int32_t new_numerator = fraction._numerator * _numerator;
        uint32_t new_denominator = fraction._denominator * _denominator;
        Fraction result = Fraction(new_numerator, new_denominator);
        return result;
    }

    Fraction operator/(const Fraction& fraction) const{
        int32_t new_numerator = fraction._denominator * _numerator;
        uint32_t new_denominator = fraction._numerator * _denominator;
        Fraction result = Fraction(new_numerator, new_denominator);
        return result;
    }


    bool operator>(const Fraction& fraction) const{
        int pub = fraction._denominator * _denominator;
        int new1 = (pub / _denominator) * _numerator;
        int new2 = (pub / fraction._denominator) * fraction._numerator;
        return new1 > new2;
    }

    bool operator<(const Fraction& fraction) const{
        int pub = fraction._denominator * _denominator;
        int new1 = (pub / _denominator) * _numerator;
        int new2 = (pub / fraction._denominator) * fraction._numerator;
        return new1 < new2;
    }

    bool operator<=(const Fraction& fraction) const{
        int pub = fraction._denominator * _denominator;
        int new1 = (pub / _denominator) * _numerator;
        int new2 = (pub / fraction._denominator) * fraction._numerator;
        return new1 <= new2;
    }

    bool operator>=(const Fraction& fraction) const{
        int pub = fraction._denominator * _denominator;
        int new1 = (pub / _denominator) * _numerator;
        int new2 = (pub / fraction._denominator) * fraction._numerator;
        return new1 >= new2;
    }

    bool operator==(const Fraction& fraction) const{
        return (fraction._numerator == _numerator && fraction._denominator == _denominator);
    }

    bool operator==(int s) const{
        return (s == _numerator && 1 == _denominator);
    }

    bool operator!=(const Fraction& fraction) const{
        return (fraction._numerator != _numerator || fraction._denominator != _denominator);
    }

    Fraction& operator++()
    {
        _numerator = _numerator + _denominator;
        return *this;
    }

    Fraction operator++(int)
    {
        Fraction temp = *this;
        ++*this;
        return temp;
    }

    Fraction operator--(int)
    {
        Fraction temp = *this;
        --*this;
        return temp;
    }

    Fraction& operator--()
    {
        _numerator = _numerator - _denominator;
        return *this;
    }

    Fraction& operator~()
    {
        _numerator = -_numerator;
        return *this;
    }

    Fraction& operator-()
    {
        _numerator = -_numerator;
        return *this;
    }

    Fraction& operator^(int s) {
        _numerator = pow(_numerator, s);
        _denominator = pow(_denominator, s);
        return *this;
    }

    Fraction operator^(int s) const{
        return Fraction(pow(_numerator, s), pow(_denominator, s));
    }

    Fraction operator^(double s) const{
        return Fraction(pow(_numerator, s), pow(_denominator, s));
    }

    friend std::ostream& operator<<(std::ostream &os, const Fraction &fraction) {
        if (fraction._denominator == 1) {
            return os << fraction._numerator;
        } else if (fraction._numerator == 0) {
            return os << 0;
        } else {
            return os << fraction._numerator << "/" << fraction._denominator;
        }
    }

};