
#pragma once

#include "Function.hpp"

class Constant : public Function{

public:

    Constant();

    Constant(double coeffcient);

    Function* Getdiff() const override;

    double Count(double x) const override;

};