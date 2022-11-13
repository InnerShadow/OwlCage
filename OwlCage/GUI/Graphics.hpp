#pragma once

#include <windows.h>
#include <vector>
#include "../SimplestFunctions/Function.hpp"
#include <GLFW/glfw3.h> 

class Graphics {
protected:
	int center;
	std::vector<double> Xdata;
	std::vector<double> Ydata;
	Function* drawFunction;
	double leftBoatder;
	double rightBoatder;
	int beatings;
	double ScaleY;
public:
	Graphics();

	Graphics(Function* drawFunction, double leftBoatder, double rightBoatder, int beatings);

	void Draw();

	void SetScaleY(double scale);

	double GetScaleY() const;

	void DrowAxis(double alpha);
};