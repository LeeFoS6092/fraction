#include "Complex.h"

class Quadro {

private:
    Complex _x1;
    Complex _x2;
public:

    Quadro();

    Quadro(Fraction q, Fraction l, Fraction s);

    friend std::ostream& operator<<(std::ostream &os, const Quadro &quadro) {
        return os << "x1 = " << quadro._x1 << " and x2 = " << quadro._x2 << std::endl; 
    }

};