
#pragma once

#include "Function.hpp"
#include "Constant.hpp"

class Power : public Function {

protected:
    double power;

public:

    Power();

    Power(double power, double coeffcient);

    Power(double power);

    Function* Getdiff() const override;

    double Count(double x) const override;

};
