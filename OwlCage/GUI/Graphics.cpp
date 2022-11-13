
#include "Graphics.hpp"

Graphics::Graphics(){}

Graphics::Graphics(Function* drawFunction, double leftBoatder, double rightBoatder, int beatings) {
	this->drawFunction = drawFunction;
	this->leftBoatder = leftBoatder;
	this->rightBoatder = rightBoatder;
	this->beatings = beatings;
	center = beatings;
	//data = realloc(data, sizeof(*data) * center);
	double dx = (rightBoatder - leftBoatder) / (center - 1);
	double currentX = leftBoatder;
	for (int i = 0; i < center; i++, currentX += dx) {
		Xdata.push_back(currentX);
		Ydata.push_back(drawFunction->Count(currentX));
	}
	ScaleY = 1.0f;
}

void Graphics::Draw() {

	double sx = 2 / (Xdata.at(Xdata.size() - 1) - Xdata.at(0));
	double dx = (Xdata.at(Xdata.size() - 1) + Xdata.at(0)) * 0.5;
	glPushMatrix();
	glScaled(sx, ScaleY, 1);
	glTranslated(-dx, 0, 0);

	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < center; i++) {
		glVertex2f(Xdata.at(i), Ydata.at(i));
	}
	glEnd();

	glPopMatrix();
}

void Graphics::SetScaleY(double scale) {
	this->ScaleY = scale;
}

double Graphics::GetScaleY() const {
	return ScaleY;
}

void Graphics::DrowAxis(double alpha) {
	double d = 0.055f;
	glPushMatrix();
	glRotatef(alpha, 0, 0, 1);
	glBegin(GL_LINES);
		glVertex2f(-1, 0);
		glVertex2f(1 - 0.01, 0);
		glVertex2f(1 - 0.01, 0);
		glVertex2f(1 - d - 0.01, 0 + d);
		glVertex2f(1 - 0.01, 0);
		glVertex2f(1 - d - 0.01, 0 - d);
	glEnd();
	glPopMatrix();

}
