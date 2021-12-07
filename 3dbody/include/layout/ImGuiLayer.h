
#ifndef _IMGUILAYER_H_
#define _IMGUILAYER_H_

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <imgui_internal.h>
#include <GLFW/glfw3.h>
#include <list>
#include <filesystem>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

namespace gf {

struct FontList;

class ImGuiLayer {
  //here methods.
 public:
  void begin();
  void end();

  void setDarkThemeColors();
  void setClassicThemeColors();
  void setLightThemeColors();

  void setIcon();
  void allIcons();

  void cleanUpIcon();
  void cleanUpAllIcons();

  void loop_over_fonts(const std::filesystem::directory_entry &e,
                       std::list<FontList> &list);

  void loadFonts(std::string font_path);

  void changeFonts();

  void onInit();
  void onAttach();
  void onRender();
  void onDetach();

  void windowPainting();

 private:

  //here fields
 public:

 private:
  GLFWwindow *window_;

  GLFWimage *window_icon_image_;
  GLFWimage *own_file_image_;
  GLFWimage *word_file_image_;
  GLFWimage *pdf_file_image_;
  GLFWimage *excel_file_image_;
  GLFWimage *ini_file_image_;
  GLFWimage *cpp_file_image_;
  GLFWimage *ppt_file_image_;
  GLFWimage *rar_file_image_;
  GLFWimage *txt_file_image_;
  GLFWimage *general_file_image_;
  GLFWimage *folder_image_;
  GLFWimage *pause_image_;
  GLFWimage *start_image_;
  GLFWimage *boot_image_;
  GLFWimage *save_image_;
  GLFWimage *tool_image_;
  GLFWimage *alarm_image_;
  GLFWimage *stats_image_;
  GLFWimage *loc_image_;

  ImVec4 clear_color_;
  const char *glsl_version_;
  std::list<FontList> font_list_;
  ImFont* current_font_;

};

typedef struct FontList {
  std::filesystem::directory_entry entry_;
  std::list<FontList> subList_;
} _FontList;

}

#endif //_IMGUILAYER_H_
