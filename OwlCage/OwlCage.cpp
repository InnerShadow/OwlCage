#include <iostream>

#include "includs.hpp"

int main() {

    //cout << tgamma(-13.3) << endl;

    Function* difffunction;

    try {
        FunctionCombine functioncombine;
        functioncombine.create();
        std::cout << "You're function: " << functioncombine.GetReference() << std::endl;

        difffunction = functioncombine.Getdiff();

        std::cout << "func: " << difffunction->GetReference() << std::endl;

        //std::cout << "Conut: " << difffunction->Count(1) << std::endl;


        //functioncombine.Draw();

        // std::vector<Function*> FirstFunc;
        // FirstFunc.push_back(new Cosine(3));
        // FirstFunc.push_back(new Sine(4));
        // std::vector<std::string> FirstOperators;
        // FirstOperators.push_back("*");

        // FunctionCombine First(FirstFunc, FirstOperators);

        // std::vector<Function*> SecondFunc;
        // SecondFunc.push_back(new Power(6));
        // SecondFunc.push_back(new Logorithmic(9));
        // std::vector<std::string> SecondOperators;
        // SecondOperators.push_back("*");
        // FunctionCombine Second(SecondFunc, SecondOperators);

        // Function* func = First * Second;


    //     Function* TempFunction = functioncombine.Getdiff();
    //     std::cout << "You're diff: " << TempFunction->GetReference() << std::endl;

        MainFrame mainFrame(1920, 1080);
        std::cout << "Eter left boartder: ";
        double leftBoarder = 0.f;
        std::cin >> leftBoarder;

        std::cout << "Eter right boartder: ";
        double rightBoarder = 0.f;
        std::cin >> rightBoarder;

        std::cout << "Eter num of beatings: ";
        int beatings = 0.f;
        std::cin >> beatings;

        Graphics graphics(difffunction, leftBoarder, rightBoarder, beatings);
        mainFrame.SetGraphics(graphics);
        if (mainFrame.Init()) {
            mainFrame.MainLoop();
        }

    }
    catch (std::exception* error) {
        std::cout << error->what();
    }

    // for(int i = 0; i < 5; i++){
    //     TempFunction = TempFunction->Getdiff();
    //     std::cout << "You're diff: " << TempFunction->GetReference() << std::endl;
    // }
    

    return 0;
}