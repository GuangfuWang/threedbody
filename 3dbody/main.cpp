
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <imgui_internal.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <iostream>
#include <filesystem>

#define STB_IMAGE_IMPLEMENTATION

#include <stb_image.h>

//#include "include/layout/view_window.h"

static void glfw_error_callback (int error, const char *description)
{
  fprintf (stderr, "Glfw Error %d: %s\n", error, description);
}

static void configMainWindowIcon (GLFWimage &image)
{

  std::filesystem::path icon_path = std::filesystem::current_path ();
  std::filesystem::path parent_path = icon_path.parent_path ();
  parent_path /= "resources";
  parent_path /= "icons";
  parent_path /= "window_icons";
  parent_path /= "icon.png";
  std::string icon_1 = parent_path.string ();

  int comp;

  image.pixels = stbi_load (icon_1.c_str (), &image.width, &image.height, &comp, STBI_rgb_alpha);
}

static bool initMainWindow ()
{
  // Setup window
  glfwSetErrorCallback (glfw_error_callback);
  if (!glfwInit ()) return false;

  // GL 3.0 + GLSL 130
  glfwWindowHint (GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint (GLFW_CONTEXT_VERSION_MINOR, 0);
  glfwWindowHint (GLFW_DECORATED, GLFW_TRUE);
  //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
  //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // 3.0+ only
  return true;
}

static void setupIconAndContext (GLFWwindow *window)
{
  GLFWimage image;
  configMainWindowIcon (image);
  if (window == NULL)
    exit (1);
  glfwSetWindowIcon (window, 1, &image);
  glfwMakeContextCurrent (window);
  glfwSwapInterval (1); // Enable vsync
}

static void setupImgui (GLFWwindow *window, const char *glsl_version)
{
  // Setup Dear ImGui context
  IMGUI_CHECKVERSION();
  ImGui::CreateContext ();
  ImGuiIO &io = ImGui::GetIO ();
  (void) io;
  //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
  //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

  // Setup Dear ImGui style
  ImGui::StyleColorsDark ();

  // Setup Platform/Renderer backends
  ImGui_ImplGlfw_InitForOpenGL (window, true);
  ImGui_ImplOpenGL3_Init (glsl_version);
}

static void startImGuiFrame ()
{
  // Start the Dear ImGui frame
  ImGui_ImplOpenGL3_NewFrame ();
  ImGui_ImplGlfw_NewFrame ();
  ImGui::NewFrame ();
}

static void render (GLFWwindow *window, ImVec4 clear_color)
{
  // Rendering
  ImGui::Render ();
  int display_w, display_h;
  glfwGetFramebufferSize (window, &display_w, &display_h);
  glViewport (0, 0, display_w, display_h);
  glClearColor (clear_color.x * clear_color.w,
                clear_color.y * clear_color.w,
                clear_color.z * clear_color.w,
                clear_color.w);
  glClear (GL_COLOR_BUFFER_BIT);
  ImGui_ImplOpenGL3_RenderDrawData (ImGui::GetDrawData ());

  glfwSwapBuffers (window);
}

static void imgui_terminate ()
{
  ImGui_ImplOpenGL3_Shutdown ();
  ImGui_ImplGlfw_Shutdown ();
  ImGui::DestroyContext ();
}

static void glfw_terminate (GLFWwindow *window)
{

  glfwDestroyWindow (window);
  glfwTerminate ();
}

static void terminate_imgui_and_glfw (GLFWwindow *window)
{
  imgui_terminate ();
  glfw_terminate (window);
}

static void CreateMainViewWindow ()
{
  float x_ratio = 0.8f;
  float y_ratio = 0.75f;
  ImVec2 size_main_view_window = ImGui::GetWindowSize ();
  size_main_view_window.x *= x_ratio;
  size_main_view_window.y *= y_ratio;
  {
    ImGui::BeginChild ("left pane", size_main_view_window, true);
    for (int i = 0; i < 100; i++)
      {
        // FIXME: Good candidate to use ImGuiSelectableFlags_SelectOnNav
        char label[128];
        sprintf (label, "MyObject %d", i);
      }
    ImGui::EndChild ();
  }
}

int main (int, char **)
{
  GLFWwindow *window;
  const char *glsl_version = "#version 430";
  bool init_status = initMainWindow ();
  if (!init_status)
    exit (EXIT_FAILURE);
  // Create window with graphics context
  window = glfwCreateWindow (1280, 720, u8"演示", NULL, NULL);
  setupIconAndContext (window);

  setupImgui (window, glsl_version);

  // Our state
  bool show_demo_window = true;
  ImVec4 clear_color = ImVec4 (0.45f, 0.55f, 0.60f, 1.00f);

  // Main loop
  while (!glfwWindowShouldClose (window))
    {

      glfwPollEvents ();
      startImGuiFrame ();

      ImGuiViewportP *viewport = (ImGuiViewportP *) (void *) ImGui::GetMainViewport ();
      ImGuiWindowFlags window_flags =
          ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_MenuBar;
      float height = ImGui::GetFrameHeight ();

      if (ImGui::BeginViewportSideBar ("##FirstMenuBar", viewport, ImGuiDir_Up, height, window_flags))
        {
          if (ImGui::BeginMenuBar ())
            {
              if (ImGui::BeginMenu ("File"))
                {
                  //ShowExampleMenuFile();
                  if (ImGui::MenuItem ("New", "CTRL+O"))
                    {}
                  if (ImGui::MenuItem ("New from file", "CTRL+SHIFT+O", false, true))
                    {}  // Disabled item
                  if (ImGui::MenuItem ("New from internet", "CTRL+ALT+O", false, true))
                    {}  // Disabled item

                  ImGui::Separator ();
                  if (ImGui::MenuItem ("Save", "CTRL+S"))
                    {}
                  if (ImGui::MenuItem ("Save as", "CTRL+ALT+S"))
                    {}
                  ImGui::EndMenu ();
                }
              if (ImGui::BeginMenu ("Edit"))
                {
                  if (ImGui::MenuItem ("Undo", "CTRL+Z"))
                    {}
                  if (ImGui::MenuItem ("Redo", "CTRL+Y", false, false))
                    {}  // Disabled item
                  ImGui::Separator ();
                  if (ImGui::MenuItem ("Cut", "CTRL+X"))
                    {}
                  if (ImGui::MenuItem ("Copy", "CTRL+C"))
                    {}
                  if (ImGui::MenuItem ("Paste", "CTRL+V"))
                    {}
                  ImGui::EndMenu ();
                }
              ImGui::EndMenuBar ();
            }

        }
      ImGui::End ();

      if (ImGui::BeginViewportSideBar ("##SecondaryMenuBar", viewport, ImGuiDir_Up, height, window_flags))
        {
          if (ImGui::BeginMenuBar ())
            {
              ImGui::Text ("Happy secondary menu bar");
              ImGui::EndMenuBar ();
            }

        }
      ImGui::End ();

      const ImVec2 base_pos = viewport->Pos;
      // Using "##" to display same title but have unique identifier.

//      ImGui::SetNextWindowPos (ImVec2 (base_pos.x , base_pos.y + 0), ImGuiCond_FirstUseEver);
//      ImGui::Begin ("Same title as another window");
//      ImGui::Text ("This is window 1. My title is the same as window 2, but my identifier is unique.");
//      ImGui::End ();

//      ImGui::BeginGroup();
//      ImGui::Text("Hello from another window!");
//      ImGui::Text("Hello from another window!");
//      ImGui::Text("Hello from another window!");
//      ImGui::EndGroup();
//      ImGui::GetForegroundDrawList()->AddRect(ImGui::GetItemRectMin(), ImGui::GetItemRectMax(), IM_COL32(255, 255, 255, 255));



//       1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()).
        if (show_demo_window)
            ImGui::ShowDemoWindow(&show_demo_window);


//      CreateMainViewWindow ();
//      ImGui::OpenPopup ("bbbb");

      render (window, clear_color);
    }

  terminate_imgui_and_glfw (window);

  return 0;
}