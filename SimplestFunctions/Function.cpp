
#include "Function.hpp"
#include "FunctionCombine.hpp"

std::string Function::GetName() const{
    return name;
}

std::string Function::GetReference() const{
    return reference;
}

Function::Function(std::string name, std::string reference){
    this->name = name;
    this->reference = reference;
}

Function* Function::operator * (Function* function) {
    std::vector<Function*> functions;
    functions.push_back(this);
    functions.push_back(function);
    std::vector<std::string> operation;
    operation.push_back("*");
    return new FunctionCombine(functions, operation);
}