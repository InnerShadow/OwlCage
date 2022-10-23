
#include "Power.hpp"

Power::Power(){
    name = "Power";
    power = 0;
    coeffcient = 0;
    reference = "(" + std::to_string(coeffcient) + "*x^(" + std::to_string(power) + "))";
}

Power::Power(double power, double coeffcient){
    name = "Power";
    this->power = power;
    this->coeffcient = coeffcient;
    reference = "(" + std::to_string(coeffcient) + "*x^(" + std::to_string(power) + "))";
}

Power::Power(double power){
    name = "Power";
    this->power = power;
    coeffcient = 1;
    reference = "(" + std::to_string(coeffcient) + "*x^(" + std::to_string(power) + "))";
}

Function* Power::Getdiff() const {
    if(power != 1){
        return new Power(power - 1, coeffcient * power);
    } else {
        return new Constant(coeffcient);
    }
}

double Power::Count(double x) const{
    return coeffcient * pow(x, power);
}