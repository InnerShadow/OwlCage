
#include "Constant.hpp"

Constant::Constant(){
    name = "Constant";
    reference = "(0)";
}

Constant::Constant(double coeffcient){
    name = "Cantant";
    this->coeffcient = coeffcient;
    reference = "(" + std::to_string(coeffcient) + ")";
}

Function* Constant::Getdiff() const {
    return new Constant(0.f);
}

double Constant::Count(double x) const {
    return coeffcient;
}
