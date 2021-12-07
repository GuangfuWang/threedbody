#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <stdio.h>
#include <filesystem>

#include <GLFW/glfw3.h> // Will drag system OpenGL headers

#define STB_IMAGE_IMPLEMENTATION

#include <stb_image.h>
#include <iostream>
#include <imgui_internal.h>


int main() {

    if (!glfwInit())
        return 1;


    // GL 3.0 + GLSL 130
    const char *glsl_version = "#version 430";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // 3.0+ only

    GLFWimage image;
    std::filesystem::path icon_path = std::filesystem::current_path();
    std::filesystem::path parent_path = icon_path.parent_path();
    parent_path /= "resources";
    parent_path /= "icons";
    parent_path /= "window_icons";
    parent_path /= "icon_1.png";
    std::string icon_1 = parent_path.string();

    int comp;
    image.pixels = stbi_load(icon_1.c_str(), &image.width, &image.height, &comp, STBI_rgb_alpha);
//    image = load_icon("my_icon.png");
//


    // Create window with graphics context
    GLFWwindow *window = glfwCreateWindow(1280, 720, u8"演示", NULL, NULL);
    if (window == NULL)
        return 1;
    glfwSetWindowIcon(window, 2, &image);
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    while (!glfwWindowShouldClose(window)) {

        glfwPollEvents();
        glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
        glClear(GL_COLOR_BUFFER_BIT);

        // feed inputs to dear imgui, start new frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGuiViewportP *viewport = (ImGuiViewportP *) (void *) ImGui::GetMainViewport();
        ImGuiWindowFlags window_flags =
                ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_MenuBar;
        float height = ImGui::GetFrameHeight();

        if (ImGui::BeginViewportSideBar("##SecondaryMenuBar", viewport, ImGuiDir_Up, height, window_flags)) {
            if (ImGui::BeginMenuBar()) {
                ImGui::Text("Happy secondary menu bar");
                ImGui::EndMenuBar();
            }

        }
        ImGui::End();

        if (ImGui::BeginViewportSideBar("##MainStatusBar", viewport, ImGuiDir_Down, height, window_flags)) {
            if (ImGui::BeginMenuBar()) {
                ImGui::Text("Happy status bar");
                ImGui::EndMenuBar();
            }

        }
        ImGui::End();

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glfwSwapBuffers(window);

    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();//清除退出

    stbi_image_free(&image.pixels);
    return 0;

}

