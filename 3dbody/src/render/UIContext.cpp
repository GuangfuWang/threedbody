
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include "pch.hpp"
#include "include/render/UIContext.h"
#include "util/ConfigMap.h"

namespace gf {

bool UIContext::init(BaseWindow *window) {

  mWindow = window;
  setupGLSLVersion();
  // Setup Dear ImGui context
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO &io = ImGui::GetIO();
  (void)io;

  enableKeyboardControl(io);     // Enable Keyboard Controls
  enableDocking(io);           // Enable Docking
  io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;         // Enable Multi-Viewport / Platform Windows

  loadFont(io);
  setStyle();

  ImGuiStyle &style = ImGui::GetStyle();
  if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
	style.WindowRounding              = 0.0f;
	style.Colors[ImGuiCol_WindowBg].w = 1.0f;
  }

  // Setup Platform/Renderer backends
  ImGui_ImplGlfw_InitForOpenGL((GLFWwindow *)mWindow->getNativeWindow(), true);
  ImGui_ImplOpenGL3_Init(glslVersion);
  return true;
}

void UIContext::preRender() {

  // start the Dear ImGui frame
  ImGui_ImplOpenGL3_NewFrame();
  ImGui_ImplGlfw_NewFrame();
  ImGui::NewFrame();

  // create the docking environment
  ImGuiWindowFlags windowFlags = ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_NoTitleBar |
	  ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove |
	  ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus |
	  ImGuiWindowFlags_NoBackground;

  ImGuiViewport *viewport = ImGui::GetMainViewport();
  ImGui::SetNextWindowPos(viewport->Pos);
  ImGui::SetNextWindowSize(viewport->Size);
  ImGui::SetNextWindowViewport(viewport->ID);

  ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
  ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
  ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
  ImGui::Begin("InvisibleWindow", nullptr, windowFlags);
  ImGui::PopStyleVar(3);

  ImGuiID dockSpaceId = ImGui::GetID("InvisibleWindowDockSpace");

  ImGui::DockSpace(dockSpaceId, ImVec2(0.0f, 0.0f), ImGuiDockNodeFlags_PassthruCentralNode);
  ImGui::End();

}

void UIContext::postRender() {
  // Rendering
  ImGui::Render();
  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

  ImGuiIO &io = ImGui::GetIO();

  if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
	GLFWwindow *backup_current_context = glfwGetCurrentContext();
	ImGui::UpdatePlatformWindows();
	ImGui::RenderPlatformWindowsDefault();
	glfwMakeContextCurrent(backup_current_context);
  }
}

void UIContext::end() {
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();
}

void UIContext::setupWindowIcon(GLFWwindow *glWindow) {
/// do nothing for ui.
}

void UIContext::loadFont(ImGuiIO &io) {
  float    fontSize = 18.0f;// *2.0f;
  fs::path p        = fs::path(ConfigMap::getInstance()->resource_dir_);
//  p/="fonts/EN/JetBrains-Mono/JetBrainsMono-Bold-7.ttf";
//  io.Fonts->AddFontFromFileTTF(p.string().c_str(), fontSize);
//  p=p.parent_path();
//  p/="JetBrainsMono-Regular-2.ttf";
//  io.FontDefault = io.Fonts->AddFontFromFileTTF(p.string().c_str(), fontSize);
  p /= "fonts/EN/ArialUni/arialuni.ttf";
  io.Fonts->AddFontFromFileTTF(p.string().c_str(),
							   fontSize,
							   NULL, io.Fonts->GetGlyphRangesChineseFull());
}

void UIContext::setStyle(const UI_STYLE &m_style) {
  switch (m_style) {
	case UI_STYLE::DEFAULT: {
	  ImGui::StyleColorsDark();
	  break;
	}
	case UI_STYLE::DARK: {
	  ImGui::StyleColorsDark();
	  break;
	}
	case UI_STYLE::CLASSIC: {
	  ImGui::StyleColorsClassic();
	  break;
	}
	case UI_STYLE::LIGHT: {
	  ImGui::StyleColorsLight();
	  break;
	}
	default: {
	  ImGui::StyleColorsDark();
	  break;
	}
  }
}

void UIContext::enableKeyboardControl(ImGuiIO &io) {
  io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
}

void UIContext::enableDocking(ImGuiIO &io) {
  io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
}

void UIContext::enableJoystickControl(ImGuiIO &io) {
  io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
}

void UIContext::setupGLSLVersion(const char *glsl_ver) {
  glslVersion = (char *)glsl_ver;
}

}