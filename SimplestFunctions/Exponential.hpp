
#pragma once

#include "Function.hpp"

class Exponential : public Function {

protected:

    double base;

public:

    Exponential();

    Exponential(double base);

    Exponential(double base, double coeffcient);

    double Count(double x) const override;

    Function* Getdiff() const override;

};