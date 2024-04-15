#include "Quadro.h"

Quadro::Quadro() {
    _x1 = Complex(0,0);
    _x2 = Complex(0,0);
}


Quadro::Quadro(Fraction q, Fraction l, Fraction s) {

    if (q == 0) {
        Fraction numres = -s;
        std::cout << l << std::endl;
        std::cout << numres << std::endl;
        Fraction x = numres / l;
        std::cout << x << std::endl;
    } else if (l == 0) {
        Fraction numres = -s;
        Fraction x2 = numres / q;
        Fraction x = x2^0.5;
        std::cout << x << std::endl;
    } else {
        Fraction numres = l;
        Fraction lq = l^2;
        Fraction dis = (lq - (Fraction(4) * q * s))^0.5;

        Fraction x1 = (-numres + dis) / (q * 2);
        Fraction x2 = (numres - dis) / (q * 2);

        if (dis == 0) {
            std::cout << x1 << std::endl;
        } else {
            std::cout << x2 << " " << x1 << std::endl;
        }
    }
}