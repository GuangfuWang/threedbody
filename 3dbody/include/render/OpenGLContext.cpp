#ifndef GLEW_STATIC
#define GLEW_STATIC
#endif
#include <gl/glew.h>

#include <filesystem>
#include "OpenGLContext.h"
#include "stb_image.h"
#include "util/ConfigMap.h"
#include "util/Log.h"
#include "include/event_handling/EventBase.h"
#include "include/event_handling/MouseEvent.h"
#include "include/event_handling/KeyEvent.h"
#include "include/event_handling/GameControllerEvent.h"


namespace gf {

bool OpenGL_Context::init(BaseWindow *window) {

  mWindow = window;

  /* Initialize the library */
  if (!glfwInit()) {
	GF_CORE_ERROR("Error: GLFW Window couldn't be initialized.");
	return false;
  }

  // Create the window and store this window as window pointer
  // so that we can use it in callback functions
  auto glWindow = glfwCreateWindow(
	  window->Width,
	  window->Height,
	  window->Title.c_str(),
	  nullptr,
	  nullptr);
  setupWindowIcon(glWindow);
  window->set_native_window(glWindow);

  if (!glWindow) {
	GF_CORE_ERROR("Error: GLFW Window couldn't be created.");
	return false;
  }

  glfwSetWindowUserPointer(glWindow, window);
  //Keyboard input handling.
  glfwSetKeyCallback(glWindow, on_key_callback);
  //Mouse input handling.
  glfwSetMouseButtonCallback(glWindow, on_mouse_button_callback);
  glfwSetScrollCallback(glWindow, on_scroll_callback);
  //Game controller input handling.
  glfwSetJoystickCallback(on_joystick_callback);
  //Window change handling.
  glfwSetWindowSizeCallback(glWindow, on_window_size_callback);
  glfwSetWindowCloseCallback(glWindow, on_window_close_callback);
  glfwMakeContextCurrent(glWindow);

  GLenum err = glewInit();
  if (GLEW_OK!=err) {
	/* Problem: glewInit failed, something is seriously wrong. */
	GF_CORE_ERROR("Error: {}", glewGetErrorString(err));
	return false;
  }

  glEnable(GL_DEPTH_TEST);
  return true;
}

void OpenGL_Context::pre_render() {
  glViewport(0, 0, mWindow->Width, mWindow->Height);
  glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void OpenGL_Context::post_render() {
  glfwPollEvents();
  glfwSwapBuffers((GLFWwindow *)mWindow->get_native_window());
}

void OpenGL_Context::end() {
  glfwDestroyWindow((GLFWwindow *)mWindow->get_native_window());
  glfwTerminate();
}

void OpenGL_Context::setupWindowIcon(GLFWwindow *glWindow) {

  GLFWimage             image;
  ConfigMap             *t          = ConfigMap::getInstance();
  std::filesystem::path parent_path = std::filesystem::path(t->resource_dir_);
  parent_path /= "icons";
  parent_path /= "window_icons";
  parent_path /= "icon.png";
  std::string icon_1 = parent_path.string();

  int comp;
  image.pixels = stbi_load(icon_1.c_str(),
						   &image.width, &image.height,
						   &comp, STBI_rgb_alpha);
  glfwSetWindowIcon(glWindow, 1, &image);
  stbi_image_free(image.pixels);
}
}