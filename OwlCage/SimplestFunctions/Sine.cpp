
#include "Sine.hpp"

    Sine::Sine(){
        name = "Sine";
        coeffcient = 1;
        reference = "(" + std::to_string(coeffcient) + "*" + "sin(x)" + ")";
    }

    Sine::Sine(double coeffcient){
        name = "Sine";
        this->coeffcient = coeffcient;
        reference = "(" + std::to_string(coeffcient) + "*" + "sin(x)" + ")";
    }

    double Sine::Count(double x) const{
        return coeffcient * sin(x);
    }

    Function* Sine::Getdiff() const {
        return new Cosine(coeffcient);
    }