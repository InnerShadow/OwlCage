
#include <iostream>
#include "FunctionCombine.hpp"

int TakeIdendeficator(std::string Operator){
    if(Operator == "*"){
        return 0;
    } else {
        if (Operator == "+"){
            return 1;
        } else {
            if(Operator == "-"){
                return 2;
            } else {
                if(Operator == "/"){
                    //return 3;
                } else {
                    throw std::runtime_error("Unknown math operator!");
                }
            }
        }
    }
    return -1;
}

std::string TakeIdendeficator(int num){
    switch(num){
        case 1 : return "*";
        case 2 : return "+";
        case 3 : return "-";
        //case 4 : return "/";
    }
    throw new std::runtime_error("Unexpectable math operation!");
    return "";
}

FunctionCombine::FunctionCombine(std::vector<Function*> functions, std::vector<std::string> operations){
    coeffcient = 1;
    name = "FunctionCombine";
    this->functions = functions;
    this->operations = operations;
    reference += functions.at(0)->GetReference();
    for(int i = 0; i < operations.size(); i++){
        reference += operations.at(i);
        reference += functions.at(i + 1)->GetReference();
    }
    NumOfOperators = operations.size();
    NumOfFunctions = functions.size();
}

FunctionCombine::FunctionCombine(){
    coeffcient = 1;
    name = "FunctionCombine";
}

void FunctionCombine::Add(Function* function){
    functions.push_back(function);
    reference += function->GetReference();
    NumOfFunctions++;
}

void FunctionCombine::Add(Function* function, std::string Operator){
    functions.push_back(function);
    operations.push_back(Operator);
    reference += (Operator + function->GetReference());
    NumOfFunctions++;
    NumOfOperators++;
}

void FunctionCombine::clear(){
    functions.clear();
    operations.clear();
    NumOfFunctions = 0;
    NumOfOperators = 0;
}

void FunctionCombine::create(){
    if(NumOfFunctions){
        std::cout << "This function is not empty! Do you want to clear this function? \nWrite down 'Yes' to clear it or 'No' to do nothing.\n";
        std::cout << GetReference() << std::endl;
        std::string idendeficator;
        std::cin >> idendeficator;
        if(idendeficator == "Yes"){
            clear();
        } else {
            return;
        }
    }

    int idendeficator = 1;

    while(idendeficator){
        std::cout << "What function do you want to add? \n 1) Constant \n 2) Power function \n 3) Cosine \n 4) Sine \n 5) Exponential \n 6) Logorithmic \n";
        std::cin >> idendeficator;
        switch(idendeficator){
            case 1 : {
                std::cout << "Enter constant: ";
                double constant;
                std::cin >> constant;
                Add(new Constant(constant));
                break;
            }
            case 2 : {
                std::cout << "Enter power of power function: ";
                double power;
                std::cin >> power;
                std::cout << "Enter coefficient near power function: ";
                double coefficient;
                std::cin >> coeffcient;
                Add(new Power(power, coeffcient));
                break;
            }
            case 3 : {
                std::cout << "Enter coefficient near cosine: ";
                double coefficient;
                std::cin >> coeffcient;
                Add(new Cosine(coeffcient));
                break;
            }
            case 4 : {
                std::cout << "Enter coefficient near sine: ";
                double coefficient;
                std::cin >> coeffcient;
                Add(new Sine(coeffcient));
                break;
            }
            case 5 : {
                std::cout << "Enter base of exponential function: ";
                double base;
                std::cin >> base;
                std::cout << "Enter coefficient near exponential function: ";
                double coefficient;
                std::cin >> coeffcient;
                Add(new Exponential(base, coeffcient));
                break;
            }
            case 6 : {
                std::cout << "Enter base of logorithmic function: ";
                double base;
                std::cin >> base;
                std::cout << "Enter coefficient near logorithmic function: ";
                double coefficient;
                std::cin >> coeffcient;
                Add(new Logorithmic(base, coeffcient));
                break;
            }
            default : {
                throw new std::runtime_error("Unexpected function!");
                return;
            }
        }

        std::cout << "Enter mathematic operator! \n 0) Enoug \n 1) multiply \n 2) plus \n 3) minus \n";
        std::cin >> idendeficator;

        if(idendeficator){
            operations.push_back(TakeIdendeficator(idendeficator));
            reference += TakeIdendeficator(idendeficator);
            NumOfOperators++;
        }

    }

}

Function* FunctionCombine::Getdiff() const {
    if(!NumOfFunctions){
        throw new std::runtime_error("Function does not exist!");
        return new Constant(0);
    }
    if (NumOfFunctions == 1) {
        return functions.at(0)->Getdiff();
    }

    FunctionCombine* FinalDiff = new FunctionCombine();

    // for(auto i : functions){
    //     std::cout << i->GetReference() << " ";
    // }

    // std::cout << std::endl;

    // for(auto i : operations){
    //     std::cout << i << " ";
    // }

    // std::cout << std::endl;

    for(int iOperator = 0, iFunc = 0; iOperator < NumOfOperators && iFunc < NumOfFunctions; iOperator++){

        // std::cout << iFunc << std::endl;
        // std::cout << NumOfFunctions << std::endl;
        // std::cout << GetReference() << std::endl;

        switch(TakeIdendeficator(operations.at(iOperator))){

            case 0 : {

                if(((iOperator != NumOfOperators - 1) && (operations.at(iOperator + 1) == "+" || operations.at(iOperator + 1) == "-")) || (iOperator == NumOfOperators - 1)){
                    if(iFunc){
                        FinalDiff->Add(functions.at(iFunc)->Getdiff(), operations.at(iOperator - 1));
                    } else {
                        FinalDiff->Add(functions.at(iFunc)->Getdiff());
                    }
                    
                    FinalDiff->Add(functions.at(iFunc + 1), "*");
                    FinalDiff->Add(functions.at(iFunc), "+");
                    FinalDiff->Add(functions.at(iFunc + 1)->Getdiff(), "*");

                    iFunc += 2;

                    break;
                }

                if(iOperator != NumOfOperators - 1 && operations.at(iOperator + 1) == "*"){
                    FunctionCombine* tempFunc = new FunctionCombine();
                    Function* func = functions.at(iFunc++);

                    std::string LastAddedOperator;
                    if(iOperator){
                        LastAddedOperator = operations.at(iOperator - 1);
                    }

                    while(operations.at(iOperator) == "*"){
                        if(tempFunc->functions.size()){
                            tempFunc->Add(functions.at(iFunc++), "*");
                        } else {
                            tempFunc->Add(functions.at(iFunc++));
                        }

                        if((iOperator == NumOfOperators - 1)){
                            break;
                        }

                        iOperator++;
                    }

                    iOperator--;

                    if(FinalDiff->NumOfFunctions){
                        FinalDiff->Add(*func->Getdiff() * tempFunc, LastAddedOperator);
                    } else {
                        FinalDiff->Add(*func->Getdiff() * tempFunc);
                    }

                    FinalDiff->Add(*tempFunc->Getdiff() * func, "+");

                    break;
                }

                throw new std::runtime_error("Multiplay diff error!");
                break;
            }

            case 1 : {

                if(!iOperator){
                    FinalDiff->Add(functions.at(iFunc++)->Getdiff());
                    break;
                }

                if(iOperator != NumOfOperators - 1 && (operations.at(iOperator + 1) == "*" || operations.at(iOperator + 1) == "/")){
                    FinalDiff->operations.push_back("+");
                    break;
                }

                if(iOperator == NumOfOperators - 1){
                    FinalDiff->Add(functions.at(iFunc++)->Getdiff(), "+");
                } else {
                    FinalDiff->Add(functions.at(iFunc++)->Getdiff(), "+");
                }

                break;
            }

            case 2 : {

                if(!iOperator){
                    FinalDiff->Add(functions.at(iFunc++)->Getdiff());
                    break;
                }

                if(iOperator != NumOfOperators - 1 && (operations.at(iOperator + 1) == "*" || operations.at(iOperator + 1) == "/")){
                    FinalDiff->operations.push_back("-");
                    break;
                }

                if(iOperator == NumOfOperators - 1){
                    FinalDiff->Add(functions.at(iFunc++)->Getdiff(), "-");
                } else {
                    FinalDiff->Add(functions.at(iFunc++)->Getdiff(), "-");
                }

                break;

            }

            case 3 : {
                throw std::runtime_error("Unknown math operator!)");
            }
        }
    }

    return FinalDiff;
}

double FunctionCombine::Count(double x) const {

    if(!NumOfOperators){
        return functions.at(0)->Count(x);

    }

    double value = functions.at(0)->Count(x);
    for(int i = 0; i < NumOfFunctions - 1; i++){
        //std::cout << "Val: " << value << " i: " << i << std::endl;
        if(operations.at(i) == "+" || operations.at(i) == "-"){
            if(operations.at(i) == "+"){
                value += functions.at(i + 1)->Count(x);
            } else {
                value -= functions.at(i + 1)->Count(x);
            }
        }
        if(operations.at(i) == "*" || operations.at(i) == "/"){
            double tempvalue = 0.f;
            if(operations.at(i) == "*"){
                int remember_last_operator = i;
                if(!i || operations.at(i - 1) == "+"){
                    tempvalue += functions.at(i)->Count(x);
                    value -= tempvalue;
                } else if (operations.at(i - 1) == "-"){
                    tempvalue -= functions.at(i)->Count(x);
                    value += tempvalue;
                }
                while(i < NumOfOperators && operations.at(i) == "*"){
                    tempvalue *= functions.at(i + 1)->Count(x);
                    i++;
                }
                if(!remember_last_operator || operations.at(remember_last_operator - 1) == "+"){
                    value += tempvalue;
                } else if(operations.at(remember_last_operator) == "-"){
                    value -= tempvalue;
                }
            }
            i--;
        }
    }
    return value;
}

Function* FunctionCombine::operator * (Function* function) {

    if(function->GetName() != "FunctionCombine"){
        FunctionCombine* tempFunc = new FunctionCombine();
        tempFunc->Add(*function * functions.at(0));
        for(int i = 0; i < NumOfOperators; i++){
            if(operations.at(i) == "+" || operations.at(i) == "-"){
                tempFunc->Add(*function * functions.at(i + 1), operations.at(i));
            }
            if(operations.at(i) == "*" || operations.at(i) == "/"){
                tempFunc->Add(functions.at(i + 1), operations.at(i));
            }
        }
        return tempFunc;
    } else {

        //TODO :  придумать как FunctionCombine * FunctionCombine

        FunctionCombine* functioncombine = reinterpret_cast<FunctionCombine*>(function);
        FunctionCombine* tempFunc = new FunctionCombine();

        for(int iFirst = 0; iFirst < NumOfOperators; iFirst++){
            std::vector<Function*> NSummand;

            do {
                NSummand.push_back(functions.at(iFirst));
            } while (operations.at(iFirst++) != "+" && operations.at(iFirst++) != "-");

            for(int i = 0; i < NSummand.size(); i++){
                std::cout << NSummand.at(i)->GetReference() << std::endl;
            }

            for(int iSecond = 0; iSecond < functioncombine->NumOfOperators; iSecond++){

            }
        }

        return tempFunc;
    }

}


Function* FunctionCombine::operator * (FunctionCombine function){
    // FunctionCombine* functioncombine = reinterpret_cast<FunctionCombine*>(function);
    FunctionCombine* tempFunc = new FunctionCombine();

    for(int iFirst = 0; iFirst < NumOfOperators; iFirst++){
        std::vector<Function*> NSummand;

        do {
            NSummand.push_back(functions.at(iFirst));
            std::cout << functions.at(iFirst)->GetReference() << std::endl;
        } while (operations.at(iFirst++) != "+" && operations.at(iFirst++) != "-");

        for(int i = 0; i < NSummand.size(); i++){
            std::cout << NSummand.at(i)->GetReference() << std::endl;
        }

        for(int iSecond = 0; iSecond < function.NumOfOperators; iSecond++){

        }
    }

    return tempFunc;
}



