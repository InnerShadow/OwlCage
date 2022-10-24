#include <iostream>

#include "includs.hpp"


#include <d3d11.h>
#include <tchar.h>



int main() {

    //cout << tgamma(-13.3) << endl;

    try {
        FunctionCombine functioncombine;
        functioncombine.create();
        std::cout << "You're function: " << functioncombine.GetReference() << std::endl;

        Function* function = functioncombine.Getdiff();

        std::cout << "func: " << function->GetReference() << std::endl;

        std::cout << "Conut: " << function->Count(1) << std::endl;

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
    }
    catch (std::exception* error) {
        std::cout << error->what();
    }

    // for(int i = 0; i < 5; i++){
    //     TempFunction = TempFunction->Getdiff();
    //     std::cout << "You're diff: " << TempFunction->GetReference() << std::endl;
    // }

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); 
    (void)io;
    ImGui::StyleColorsDark();
    //ImGui_ImplGlfw_InitForOpenGL(window, true);
    


    return 0;
}