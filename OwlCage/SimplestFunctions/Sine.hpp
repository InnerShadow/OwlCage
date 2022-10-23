
#pragma once

#include "Function.hpp"
#include "Cosine.hpp"

class Sine : public Function {

public:

    Sine();

    Sine(double coeffcient);

    double Count(double x) const override;
    
    Function* Getdiff() const override;

};