#ifndef GLEW_STATIC
#define GLEW_STATIC
#endif
#include <GL/glew.h>
#include <stb_image.h>

#include "include/render/OpenGLContext.h"

#include "include/event_handling/ApplicationEvent.h"
#include "include/event_handling/MouseEvent.h"
#include "include/event_handling/KeyEvent.h"
#include "include/event_handling/GameControllerEvent.h"

#include "util/ConfigMap.h"
#include "util/Log.h"

namespace gf {

bool OpenGL_Context::init(BaseWindow *window) {

  mWindow = window;

  /* Initialize the library */
  if (!glfwInit()) {
	GF_CORE_ERROR("Error: GLFW Window couldn't be initialized.");
	return false;
  }

  // create the window and store this window as window pointer
  // so that we can use it in callback functions
  auto glWindow = glfwCreateWindow(
	  window->mWidth,
	  window->mHeight,
	  window->mTitle.c_str(),
	  nullptr,
	  nullptr);
  setupWindowIcon(glWindow);
  window->setNativeWindow(glWindow);

  if (!glWindow) {
	GF_CORE_ERROR("Error: GLFW Window couldn't be created.");
	return false;
  }

  glfwSetWindowUserPointer(glWindow, window);
  //Keyboard input handling.
  glfwSetKeyCallback(glWindow, onKeyEventCallBack);
  //Mouse input handling.
  glfwSetMouseButtonCallback(glWindow, onMouseButtonCallback);
  glfwSetScrollCallback(glWindow, onMouseWheelCallback);
  glfwSetDropCallback(glWindow, onDropFileCallback);
  //Game controller input handling.
  glfwSetJoystickCallback(onJoystickCallback);
  //Window change handling.
  glfwSetWindowSizeCallback(glWindow, onWindowSizeCallback);
  glfwSetWindowCloseCallback(glWindow, onWindowCloseCallback);
  glfwMakeContextCurrent(glWindow);

  GLenum err = glewInit();
  if (GLEW_OK!=err) {
	/* Problem: glewInit failed, something is seriously wrong. */
	GF_CORE_ERROR("GLEW init error: {}", glewGetErrorString(err));
	return false;
  }

  glEnable(GL_DEPTH_TEST);
  return true;
}

void OpenGL_Context::preRender() {
  glViewport(0, 0, mWindow->mWidth, mWindow->mHeight);
  glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void OpenGL_Context::postRender() {
  glfwPollEvents();
  glfwSwapBuffers((GLFWwindow *)mWindow->getNativeWindow());
}

void OpenGL_Context::end() {
  glfwDestroyWindow((GLFWwindow *)mWindow->getNativeWindow());
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