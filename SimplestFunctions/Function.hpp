#pragma once

#include <cstring>
#include <string>
#include <math.h>
#include <cmath>
#include <vector>


class Function{
protected:

    std::string name;
    std::string reference;
    double coeffcient;

public:

    std::string GetName() const;

    std::string GetReference() const;

    virtual Function* Getdiff() const = 0;

    Function() = default;

    Function(std::string name, std::string reference);

    virtual double Count(double x) const = 0;

    virtual Function* operator * (Function* function);

};
