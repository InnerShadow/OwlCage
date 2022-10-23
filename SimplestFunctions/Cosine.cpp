
#include "Cosine.hpp"

    Cosine::Cosine(){
        name = "Cosine";
        coeffcient = 1;
        reference = "(" + std::to_string(coeffcient) + "*" + "cos(x)" + ")";
    }

    Cosine::Cosine(double coeffcient){
        name = "Cosine";
        this->coeffcient = coeffcient;
        reference = "(" + std::to_string(coeffcient) + "*" + "cos(x)" + ")";
    }

    double Cosine::Count(double x) const {
        return coeffcient * cos(x);
    }

    Function* Cosine::Getdiff() const {
        return new Sine(-1 * coeffcient);
    }