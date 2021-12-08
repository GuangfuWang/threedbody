#include <filesystem>
#include "pch.hpp"
#include "opengl_context.h"
#include "stb_image.h"
#include "util/ConfigMap.h"

namespace gf {
static void on_key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
  auto pWindow = static_cast<GFWindow *>(glfwGetWindowUserPointer(window));
  pWindow->on_key(key, scancode, action, mods);
}

static void on_drop_file_callback(GLFWwindow *window, int count, const char **paths) {
  int i;
  for (int i = 0; i < count; i++) {
    //TODO: here add drop file callback
  }
}

static void on_scroll_callback(GLFWwindow *window, double xoffset, double yoffset) {
  auto pWindow = static_cast<GFWindow *>(glfwGetWindowUserPointer(window));
  pWindow->on_scroll(yoffset);
}

static void on_window_size_callback(GLFWwindow *window, int width, int height) {
  auto pWindow = static_cast<GFWindow *>(glfwGetWindowUserPointer(window));
  pWindow->on_resize(width, height);
}

static void on_window_close_callback(GLFWwindow *window) {
  GFWindow *pWindow = static_cast<GFWindow *>(glfwGetWindowUserPointer(window));
  pWindow->on_close();
}

bool OpenGL_Context::init(GFWindow *window) {

  mWindow = window;

  /* Initialize the library */
  if (!glfwInit()) {
    fprintf(stderr, "Error: GLFW Window couldn't be initialized\n");
    return false;
  }

  // Create the window and store this window as window pointer
  // so that we can use it in callback functions
  auto glWindow = glfwCreateWindow(window->Width, window->Height, window->Title.c_str(), nullptr, nullptr);
  setupWindowIcon(glWindow);
  window->set_native_window(glWindow);

  if (!glWindow) {
    fprintf(stderr, "Error: GLFW Window couldn't be created\n");
    return false;
  }

  glfwSetWindowUserPointer(glWindow, window);
  glfwSetKeyCallback(glWindow, on_key_callback);
  glfwSetScrollCallback(glWindow, on_scroll_callback);
  glfwSetWindowSizeCallback(glWindow, on_window_size_callback);
  glfwSetWindowCloseCallback(glWindow, on_window_close_callback);
  glfwMakeContextCurrent(glWindow);

  GLenum err = glewInit();
  if (GLEW_OK != err) {
    /* Problem: glewInit failed, something is seriously wrong. */
    fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
    return false;
  }

  glEnable(GL_DEPTH_TEST);

  return true;
}

void OpenGL_Context::pre_render() {
  glViewport(0, 0, mWindow->Width, mWindow->Height);
  glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void OpenGL_Context::post_render() {
  glfwPollEvents();
  glfwSwapBuffers((GLFWwindow *) mWindow->get_native_window());
}

void OpenGL_Context::end() {
  glfwDestroyWindow((GLFWwindow *) mWindow->get_native_window());
  glfwTerminate();
}

void OpenGL_Context::setupWindowIcon(GLFWwindow *glWindow) {

  GLFWimage image;
  ConfigMap *t = ConfigMap::getInstance();
  std::filesystem::path parent_path = std::filesystem::path(t->resource_dir_);
  parent_path /= "icons";
  parent_path /= "window_icons";
  parent_path /= "icon.png";
  std::string icon_1 = parent_path.string();

  int comp;

  image.pixels = stbi_load(icon_1.c_str(), &image.width, &image.height, &comp, STBI_rgb_alpha);

  glfwSetWindowIcon(glWindow, 1, &image);

  stbi_image_free(image.pixels);

}
}