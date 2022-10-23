
#pragma once

#include "Function.hpp"
#include "Sine.hpp"

class Cosine : public Function {

public:

    Cosine();

    Cosine(double coeffcient);

    double Count(double x) const override;

    Function* Getdiff() const override;

};
