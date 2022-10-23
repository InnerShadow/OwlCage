
#include <vector>
#include <stdexcept>

#include "Function.hpp"
#include "Constant.hpp"
#include "Power.hpp"
#include "Cosine.hpp"
#include "Sine.hpp"
#include "Exponential.hpp"
#include "Logorithmic.hpp"

class FunctionCombine : public Function {

protected:

    std::vector<Function*> functions;
    std::vector<std::string> operations;
    int NumOfFunctions = 0;
    int NumOfOperators = 0;

public:

    FunctionCombine();

    FunctionCombine(std::vector<Function*> functions, std::vector<std::string> operations);

    void Add(Function* function);

    void Add(Function* function, std::string Operator);

    void create();

    void clear();

    Function* Getdiff() const override;

    double Count(double x) const override;

    Function* operator * (Function* function) override;

    Function* operator * (FunctionCombine function);

};