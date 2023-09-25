#include <stdio.h>
#include <iostream>
#include <signal.h>
#include <unistd.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "imgui/imgui.h"
#include "imgui/backends/imgui_impl_glfw.h"
#include "imgui/backends/imgui_impl_opengl2.h"

#include "app.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

using namespace ImGui;
using namespace std;

GLFWwindow* window;

GLFWwindow* open_window();
void init_imgui(GLFWwindow* window);
void render(GLFWwindow* window, const ImVec4& clear_color);
bool LoadTextureFromFile(const char* filename, GLuint* out_texture, int* out_width, int* out_height);

void sig_handler(int sig_number){
    if(sig_number == SIGINT || sig_number == SIGTERM){
        glfwSetWindowShouldClose(window, 1);
    }
}

int main(){
    std::cout << "--- Project 1 ---\n" << std::endl;

    signal(SIGINT, sig_handler);
    signal(SIGTERM, sig_handler);

    std::cout << "Opening Window" << std::endl;
    window = open_window();
    init_imgui(window);
    ImGuiIO& io = ImGui::GetIO();
    ImVec4 clear_color = ImVec4(0.06f, 0.06f, 0.06f, 0.94f);
    std::cout << "Done" << std::endl;

    ImGuiStyle& style = ImGui::GetStyle();
    style.CellPadding.x = 10;
    style.CellPadding.y = 4;
    style.FramePadding.x = 5;
    style.FramePadding.y = 4;
    style.WindowRounding = 12;
    style.FrameRounding = 12;
    style.ScrollbarRounding = 12;

    //genero dati per telemetria
    TelemetryData telemetryData;

    //genero dati per BMS
    BMSData bmsData;

    //genero dati per gomme
    TyreData tyreData;

    //genero dati per motore
    MotorData motorData;

    //genero dati per utente
    DataBase dataBase;
    // cout << "&database " << &dataBase << endl;
    // cout << "maintainer from main " << dataBase.maintainerLogin[0].username << dataBase.maintainerLogin[0].password << endl;
    //         fflush(stdout);
    //         cout << "adminLoginmfrom main " << dataBase.adminLogin[0].username << dataBase.adminLogin[0].password << endl;
    //         fflush(stdout);

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        // Start the Dear ImGui frame
        ImGui_ImplOpenGL2_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // renders tabs/buttons/...
        DockSpaceOverViewport(GetMainViewport());
        ShowDemoWindow();
        // if(ret){
        //     ImGui::Begin("OpenGL Texture Text");
        //     ImGui::Text("pointer = %p", my_image_texture);
        //     ImGui::Text("size = %d x %d", my_image_width, my_image_height);
        //     ImGui::Image((void*)(intptr_t)my_image_texture, ImVec2(my_image_width, my_image_height));
        //     ImGui::End();
        // }

        app_render(telemetryData, bmsData, tyreData, motorData, &dataBase);

        render(window, clear_color);
    }

    std::cout << "Shutdown" << std::endl;
    ImGui_ImplOpenGL2_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}

GLFWwindow* open_window(){
    // Setup window
    glewExperimental = GL_TRUE;
    if (!glfwInit())
        return nullptr;
    int x, y, w, h;
    GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor();
    glfwGetMonitorWorkarea(primaryMonitor, &x, &y, &w, &h);
    GLFWwindow* window = glfwCreateWindow(w*0.75f, h*0.75f, "Project 1", NULL, NULL);
    glfwSetWindowMonitor(window, NULL, x, y, w*0.75f, h*0.75f, GLFW_DONT_CARE);
    if (window == NULL)
        return nullptr;

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync
    
    if(glewInit() != GLEW_OK)
        return nullptr;
    return window;
}

void init_imgui(GLFWwindow* window){
    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGuiContext* ctx = ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    // io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking
    // io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
    io.ConfigViewportsNoDecoration = false;
    ImGuiStyle& style = ImGui::GetStyle();

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL2_Init();
}

void render(GLFWwindow* window, const ImVec4& clear_color){
    static int display_w, display_h;

    ImGui::Render();
    glfwGetFramebufferSize(window, &display_w, &display_h);

    glViewport(0, 0, display_w, display_h);
    glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
    glClear(GL_COLOR_BUFFER_BIT);

    ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
    if (ImGui::GetIO().ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        GLFWwindow* backup_current_context = glfwGetCurrentContext();
        ImGui::UpdatePlatformWindows();
        ImGui::RenderPlatformWindowsDefault();
        glfwMakeContextCurrent(backup_current_context);
    }
    else
    {
        glfwMakeContextCurrent(window);
    }

    glfwSwapBuffers(window);
}
