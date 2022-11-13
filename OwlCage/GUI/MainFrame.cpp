#include "MainFrame.hpp"

MainFrame::MainFrame(int width, int height) {
    this->height = height;
    this->width = width;
}

int MainFrame::Init() {
    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(width, height + 20, "Owl Cage", NULL, NULL);
    if (!window){
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    return 1;
}

void MainFrame::MainLoop() {

    //POINTFLOAT* data = graphics.GetData();

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)){
        /* Render here */
        glClearColor(1.f, 1.0f, 1.0f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        
        glLoadIdentity();

        glLineWidth(2);
        
        glColor3f(0, 0, 0);
        graphics.DrowAxis(0);
        graphics.DrowAxis(90);
        glColor3f(1, 0, 0);
        CheckMouse();
        graphics.Draw();
        

        glfwSwapBuffers(window);
        glEnd();

        glPopMatrix();

        /* Poll for and process events */
        glfwPollEvents();
        Sleep(1);
    }
}

void MainFrame::TestLoop() {
    double theta = 0.f;
    while (!glfwWindowShouldClose(window)) {
        /* Render here */
        glClearColor(1.f, 0.5f, 0.1f, 0.f);
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */

        glPushMatrix();
        glRotatef(theta++, 1.0f, 1.0f, 1.0f);

        glBegin(GL_TRIANGLES);

        glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(0.0f, 0.0f);
        glColor3f(0.0f, 1.0f, 0.0f);   glVertex2f(-0.6f, 0.f);
        glColor3f(0.0f, 0.0f, 1.0f);   glVertex2f(0.6f, 0.6f);

        glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(0.0f, 0.0f);
        glColor3f(0.0f, 1.0f, 0.0f);   glVertex2f(0.0f, -0.6f);
        glColor3f(0.0f, 0.0f, 1.0f);   glVertex2f(0.6f, 0.6f);

        glEnd();

        glfwSwapBuffers(window);
        glEnd();

        glPopMatrix();

        /* Poll for and process events */
        glfwPollEvents();
        Sleep(1);
    }
}

MainFrame::~MainFrame() {
    glfwTerminate();
}

void MainFrame::SetGraphics(Graphics graphics) {
    this->graphics = graphics;
}

void MainFrame::CheckMouse() {
    int state = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT);
    if (state == GLFW_PRESS) {
        graphics.SetScaleY(graphics.GetScaleY() * 1.10);
    }
    state = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT);
    if (state == GLFW_PRESS) {
        graphics.SetScaleY(graphics.GetScaleY() * 0.8);
    }
}








/*
MainFrame::MainFrame() {
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit()) {
        return;
    }
    //const char* glsl_version = "#version 130";
    //glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    //glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    MainWindow = glfwCreateWindow(1280, 720, "Owl Cage", NULL, NULL);
    if (MainWindow == NULL)
        return;

    const char* glsl_version = "#version 130";

    glfwMakeContextCurrent(MainWindow);
    //glfwSwapInterval(1); // Enable vsync
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(MainWindow, true);
    ImGui_ImplOpenGL3_Init(glsl_version);
    show_demo_window = true;
    show_another_window = false;
    clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
}

void MainFrame::TestLoop() {
    while (!glfwWindowShouldClose(MainWindow))
    {
        // Poll and handle events (inputs, window resize, etc.)
        // You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
        // - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application, or clear/overwrite your copy of the mouse data.
        // - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application, or clear/overwrite your copy of the keyboard data.
        // Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
        glfwPollEvents();

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
        if (show_demo_window)
            ImGui::ShowDemoWindow(&show_demo_window);

        // 2. Show a simple window that we create ourselves. We use a Begin/End pair to create a named window.
        {
            static float f = 0.0f;
            static int counter = 0;



            ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

            ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
            ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
            ImGui::Checkbox("Another Window", &show_another_window);

            ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
            ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

            if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
                counter++;
            ImGui::SameLine();
            ImGui::Text("counter = %d", counter);

            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
            ImGui::End();
        }

        // 3. Show another simple window.
        if (show_another_window)
        {
            ImGui::Begin("Another Window", &show_another_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
            ImGui::Text("Hello from another window!");
            if (ImGui::Button("Close Me"))
                show_another_window = false;
            ImGui::End();
        }

        // Rendering
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(MainWindow, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(MainWindow);
    }
}

void MainFrame::MainLoop() {
    while (!glfwWindowShouldClose(MainWindow)) {
        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        if (show_demo_window){
            ImGui::ShowDemoWindow(&show_demo_window);
        }

        {
            ImGui::Begin("Hello, world!");
            ImGui::SetCursorPos(ImVec2(1000, 100));
            ImGui::End();
        }

        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(MainWindow, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(MainWindow);
    }
}

MainFrame::~MainFrame() {
    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(MainWindow);
    glfwTerminate();
}
*/