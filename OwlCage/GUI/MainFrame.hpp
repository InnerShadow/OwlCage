#pragma once

/*
#include "../imguiH/imgui.h"
#include "../imguiH/imgui_impl_glfw.h"
#include "../imguiH/imconfig.h"
#include "../imguiH/imgui_impl_opengl3.h"
#include "../imguiH/imgui_impl_opengl3_loader.h"
#include "../imguiH/imgui_internal.h"
#include "../imguiH/imstb_rectpack.h"
#include "../imguiH/imstb_textedit.h"
#include "../imguiH/imstb_truetype.h"

#include <GLFW/glfw3.h> 

#define GL_SILENCE_DEPRECATION

#if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
#pragma comment(lib, "legacy_stdio_definitions")
#endif

static void glfw_error_callback(int error, const char* description) {
	fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}
*/

/*
class MainFrame {
protected:
	GLFWwindow* MainWindow;
	ImGuiIO io;
	bool show_demo_window;
	bool show_another_window;
	ImVec4 clear_color;
public:
	MainFrame();
	void MainLoop();
	void TestLoop();
	virtual ~MainFrame();
};

*/

#include <windows.h>
#include "../SimplestFunctions/Function.hpp"
#include "Graphics.hpp"
#include <GLFW/glfw3.h> 


class MainFrame {
protected:
	GLFWwindow* window;
	int width;
	int height;
	Graphics graphics;
public:
	MainFrame(int width, int height);

	int Init();

	void MainLoop();

	void TestLoop();

	virtual ~MainFrame();

	void SetGraphics(Graphics graphics);

	void CheckMouse();
};