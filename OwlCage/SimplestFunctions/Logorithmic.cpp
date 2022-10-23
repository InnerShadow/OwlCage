
#include "Logorithmic.hpp"

Logorithmic::Logorithmic(){
    name = "Logorithmic";
    coeffcient = 1;
    base = 1;
    reference = "(" + std::to_string(coeffcient) + "*" + "log" + std::to_string(base) + "(x))";
}

Logorithmic::Logorithmic(double base){
    name = "Logorithmic";
    coeffcient = 1;
    this->base = base;
    reference =  "(" + std::to_string(coeffcient) + "*" + "log" + std::to_string(base) + "(x))";
}

Logorithmic::Logorithmic(double base, double coeffcient){
    name = "Logorithmic";
    this->coeffcient = coeffcient;
    this->base = base;
    reference = "(" + std::to_string(coeffcient) + "*" + "log" + std::to_string(base) + "(x))";
}

double Logorithmic::Count(double x) const{
    return coeffcient * log(x) / log(base);
}

Function* Logorithmic::Getdiff() const{
    return new Power(-1, coeffcient * log(base));
}