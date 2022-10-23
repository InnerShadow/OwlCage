
#pragma once

#include "Function.hpp"
#include "Power.hpp"

class Logorithmic : public Function {

protected:
    double base;

public:

    Logorithmic();

    Logorithmic(double base);

    Logorithmic(double base, double coeffcient);

    double Count(double x) const override;

    Function* Getdiff() const override;

};