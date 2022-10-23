
#include "Exponential.hpp"

Exponential::Exponential(){
    name = "Exponential";
    coeffcient = 1;
    base = 1;
    reference = "(" + std::to_string(coeffcient) + "*" + std::to_string(base) + "^x" + ")";
}

Exponential::Exponential(double base){
    name = "Exponential";
    coeffcient = 1;
    this->base = base;
    reference = "(" + std::to_string(coeffcient) + "*" + std::to_string(base) + "^x" + ")";
}

Exponential::Exponential(double base, double coeffcient){
    name = "Exponential";
    this->coeffcient = coeffcient;
    this->base = base;
    reference = "(" + std::to_string(coeffcient) + "*" + std::to_string(base) + "^x" + ")";
}

double Exponential::Count(double x) const{
    return coeffcient * pow(base, x);
}

Function* Exponential::Getdiff() const{
    return new Exponential(base, coeffcient * log(base));
}