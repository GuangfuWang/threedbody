
#include <spdlog/spdlog/spdlog.h>
#include "../../include/layout/ImGuiLayer.h"
#include "../../util/ConfigMap.h"

namespace gf {

static void glfw_error_callback(int error, const char *description) {
  fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}

static void configMainWindowIcon(GLFWimage &image) {

  std::filesystem::path icon_path = std::filesystem::current_path();
  std::filesystem::path parent_path = icon_path.parent_path();
  parent_path /= "resources";
  parent_path /= "icons";
  parent_path /= "window_icons";
  parent_path /= "icon.png";
  std::string icon_1 = parent_path.string();

  int comp;

  image.pixels = stbi_load(icon_1.c_str(), &image.width, &image.height, &comp, STBI_rgb_alpha);
}

static bool initMainWindow() {
  // Setup window
  glfwSetErrorCallback(glfw_error_callback);
  if (!glfwInit()) return false;

  // GL 3.0 + GLSL 130
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
  glfwWindowHint(GLFW_DECORATED, GLFW_TRUE);
  //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
  //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // 3.0+ only
  return true;
}

static void setupIconAndContext(GLFWwindow *window) {
  GLFWimage image;
  configMainWindowIcon(image);
  if (window == NULL)
    exit(1);
  glfwSetWindowIcon(window, 1, &image);
  glfwMakeContextCurrent(window);
  glfwSwapInterval(1); // Enable vsync
}

static void setupImgui(GLFWwindow *window, const char *glsl_version) {
  // Setup Dear ImGui context
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO &io = ImGui::GetIO();
  (void) io;
  //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
  //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

  io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls

  float fontSize = 18.0f;// *2.0f;
  io.Fonts->AddFontFromFileTTF("resources/fonts/EN/JetBrains-Mono/JetBrainsMono-Bold-7.ttf", fontSize);
  io.FontDefault =
      io.Fonts->AddFontFromFileTTF("resources/fonts/EN/JetBrains-Mono/JetBrainsMono-Regular-2.ttf", fontSize);

  // Setup Dear ImGui style
  ImGui::StyleColorsDark();

  // Setup Platform/Renderer backends
  ImGui_ImplGlfw_InitForOpenGL(window, true);
  ImGui_ImplOpenGL3_Init(glsl_version);
}

static void startImGuiFrame() {
  // Start the Dear ImGui frame
  ImGui_ImplOpenGL3_NewFrame();
  ImGui_ImplGlfw_NewFrame();
  ImGui::NewFrame();
}

static void render(GLFWwindow *window, ImVec4 clear_color) {
  // Rendering
  ImGui::Render();
  int display_w, display_h;
  glfwGetFramebufferSize(window, &display_w, &display_h);
  glViewport(0, 0, display_w, display_h);
  glClearColor(clear_color.x * clear_color.w,
               clear_color.y * clear_color.w,
               clear_color.z * clear_color.w,
               clear_color.w);
  glClear(GL_COLOR_BUFFER_BIT);
  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

  glfwSwapBuffers(window);
}

static void imgui_terminate() {
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();
}

static void glfw_terminate(GLFWwindow *window) {

  glfwDestroyWindow(window);
  glfwTerminate();
}

static void terminate_imgui_and_glfw(GLFWwindow *window) {
  imgui_terminate();
  glfw_terminate(window);
}

void ImGuiLayer::loop_over_fonts(const std::filesystem::directory_entry &e,
                                 std::list<FontList> &list) {
  auto begin_dir_iter = std::filesystem::recursive_directory_iterator(e);
  auto end_dir_iter = std::filesystem::recursive_directory_iterator();

  for (auto it = begin_dir_iter; it != end_dir_iter; it++) {
    auto &entry = *it;
    if (std::filesystem::is_regular_file(entry)) {
      FontList fl;
      fl.entry_ = entry;
      list.emplace_back(fl);
    } else if (std::filesystem::is_directory(entry)) {
      FontList fl;
      fl.entry_ = entry;
      loop_over_fonts(entry, fl.subList_);
      list.emplace_back(fl);
    } else continue;
  }
}

void ImGuiLayer::setDarkThemeColors() {
  ImGui::StyleColorsDark();
}

void ImGuiLayer::setClassicThemeColors() {
  ImGui::StyleColorsClassic();
}

void ImGuiLayer::setLightThemeColors() {
  ImGui::StyleColorsLight();
}

void ImGuiLayer::loadFonts(std::string font_path) {
  auto font_root_dir = std::filesystem::directory_entry(font_path);
  if (!(std::filesystem::exists(font_root_dir))) {
    ///TODO: add here error message to logging system.
    exit(EXIT_FAILURE);
  }
  loop_over_fonts(font_root_dir, font_list_);
  ///TODO: add tags for finish loading fonts.
}

void ImGuiLayer::onAttach() {
  const char *glsl_version = "#version 430";
  bool init_status = initMainWindow();
  if (!init_status)
    exit(EXIT_FAILURE);
  // Create window with graphics context
  window_ = glfwCreateWindow(1280, 720, u8"3D Body", NULL, NULL);
  setupIconAndContext(window_);
  setupImgui(window_, glsl_version);
  if (!current_font_) {
    current_font_ = ImGui::GetFont();
  } else {
    ImGui::GetIO().FontDefault = current_font_;
  }

  clear_color_ = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
}

void ImGuiLayer::onDetach() {
  terminate_imgui_and_glfw(window_);
}

void ImGuiLayer::setIcon() {
  std::filesystem::path parent_path = std::filesystem::path(ConfigMap::root_dir_);
  parent_path /= "resources";
  parent_path /= "icons";
  parent_path /= "window_icons";
  parent_path /= "icon.png";
  std::string icon_1 = parent_path.string();

  int comp;

  window_icon_image_->pixels = stbi_load(icon_1.c_str(),
                                         &window_icon_image_->width,
                                         &window_icon_image_->height,
                                         &comp,
                                         STBI_rgb_alpha);
}

void ImGuiLayer::cleanUpIcon() {
  stbi_image_free(window_icon_image_->pixels);
}

void ImGuiLayer::onRender() {
  ImGui::Render();
  int display_w, display_h;
  glfwGetFramebufferSize(window_, &display_w, &display_h);
  glViewport(0, 0, display_w, display_h);
  glClearColor(clear_color_.x * clear_color_.w,
               clear_color_.y * clear_color_.w,
               clear_color_.z * clear_color_.w,
               clear_color_.w);
  glClear(GL_COLOR_BUFFER_BIT);
  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

  glfwSwapBuffers(window_);
}

void ImGuiLayer::windowPainting() {
  ImGuiViewportP *viewport = (ImGuiViewportP *) (void *) ImGui::GetMainViewport();
  ImGuiWindowFlags window_flags =
      ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_MenuBar;
  float height = ImGui::GetFrameHeight();

  if (ImGui::BeginViewportSideBar("##FirstMenuBar", viewport, ImGuiDir_Up, height, window_flags)) {
    if (ImGui::BeginMenuBar()) {
      if (ImGui::BeginMenu("File")) {
        //ShowExampleMenuFile();
        if (ImGui::MenuItem("New", "CTRL+O")) {}
        if (ImGui::MenuItem("New from file", "CTRL+SHIFT+O", false, true)) {}  // Disabled item
        if (ImGui::MenuItem("New from internet", "CTRL+ALT+O", false, true)) {}  // Disabled item

        ImGui::Separator();
        if (ImGui::MenuItem("Save", "CTRL+S")) {}
        if (ImGui::MenuItem("Save as", "CTRL+ALT+S")) {}
        ImGui::EndMenu();
      }
      if (ImGui::BeginMenu("Edit")) {
        if (ImGui::MenuItem("Undo", "CTRL+Z")) {}
        if (ImGui::MenuItem("Redo", "CTRL+Y", false, false)) {}  // Disabled item
        ImGui::Separator();
        if (ImGui::MenuItem("Cut", "CTRL+X")) {}
        if (ImGui::MenuItem("Copy", "CTRL+C")) {}
        if (ImGui::MenuItem("Paste", "CTRL+V")) {}
        ImGui::EndMenu();
      }
      ImGui::EndMenuBar();
    }

  }
  ImGui::End();

  if (ImGui::BeginViewportSideBar("##SecondaryMenuBar", viewport, ImGuiDir_Up, height, window_flags)) {
    if (ImGui::BeginMenuBar()) {
      ImGui::Text("Happy secondary menu bar");
      ImGui::EndMenuBar();
    }

  }
  ImGui::End();

}
void ImGuiLayer::allIcons() {
  std::filesystem::path parent_path = std::filesystem::path(ConfigMap::root_dir_);
  parent_path /= "resources";
  parent_path /= "icons";
  parent_path /= "icon_others";

  std::filesystem::path image_file = std::filesystem::path(parent_path);
  image_file /= "file-star.png";
  std::string icon_1 = image_file.string();

  int comp;

  own_file_image_->pixels = stbi_load(icon_1.c_str(),
                                      &own_file_image_->width,
                                      &own_file_image_->height,
                                      &comp,
                                      STBI_rgb_alpha);

  image_file = image_file.parent_path();
  image_file /= "word.png";
  word_file_image_->pixels = stbi_load(image_file.string().c_str(),
                                       &word_file_image_->width,
                                       &word_file_image_->height,
                                       &comp,
                                       STBI_rgb_alpha);

  image_file = image_file.parent_path();
  image_file /= "pdf.png";
  pdf_file_image_->pixels = stbi_load(image_file.string().c_str(),
                                      &pdf_file_image_->width,
                                      &pdf_file_image_->height,
                                      &comp,
                                      STBI_rgb_alpha);

  image_file = image_file.parent_path();
  image_file /= "excel.png";
  excel_file_image_->pixels = stbi_load(image_file.string().c_str(),
                                        &excel_file_image_->width,
                                        &excel_file_image_->height,
                                        &comp,
                                        STBI_rgb_alpha);

  image_file = image_file.parent_path();
  image_file /= "ini.png";
  ini_file_image_->pixels = stbi_load(image_file.string().c_str(),
                                      &ini_file_image_->width,
                                      &ini_file_image_->height,
                                      &comp,
                                      STBI_rgb_alpha);

  image_file = image_file.parent_path();
  image_file /= "cpp.png";
  cpp_file_image_->pixels = stbi_load(image_file.string().c_str(),
                                      &cpp_file_image_->width,
                                      &cpp_file_image_->height,
                                      &comp,
                                      STBI_rgb_alpha);

  image_file = image_file.parent_path();
  image_file /= "ppt.png";
  ppt_file_image_->pixels = stbi_load(image_file.string().c_str(),
                                      &ppt_file_image_->width,
                                      &ppt_file_image_->height,
                                      &comp,
                                      STBI_rgb_alpha);

  image_file = image_file.parent_path();
  image_file /= "rar.png";
  rar_file_image_->pixels = stbi_load(image_file.string().c_str(),
                                      &rar_file_image_->width,
                                      &rar_file_image_->height,
                                      &comp,
                                      STBI_rgb_alpha);

  image_file = image_file.parent_path();
  image_file /= "txt.png";
  txt_file_image_->pixels = stbi_load(image_file.string().c_str(),
                                      &txt_file_image_->width,
                                      &txt_file_image_->height,
                                      &comp,
                                      STBI_rgb_alpha);

  image_file = image_file.parent_path();
  image_file /= "file.png";
  general_file_image_->pixels = stbi_load(image_file.string().c_str(),
                                          &general_file_image_->width,
                                          &general_file_image_->height,
                                          &comp,
                                          STBI_rgb_alpha);

  image_file = image_file.parent_path();
  image_file /= "folder.png";
  folder_image_->pixels = stbi_load(image_file.string().c_str(),
                                    &folder_image_->width,
                                    &folder_image_->height,
                                    &comp,
                                    STBI_rgb_alpha);

  image_file = image_file.parent_path();
  image_file /= "pause.png";
  pause_image_->pixels = stbi_load(image_file.string().c_str(),
                                   &pause_image_->width,
                                   &pause_image_->height,
                                   &comp,
                                   STBI_rgb_alpha);

  image_file = image_file.parent_path();
  image_file /= "start.png";
  start_image_->pixels = stbi_load(image_file.string().c_str(),
                                   &start_image_->width,
                                   &start_image_->height,
                                   &comp,
                                   STBI_rgb_alpha);

  image_file = image_file.parent_path();
  image_file /= "boot.png";
  boot_image_->pixels = stbi_load(image_file.string().c_str(),
                                  &boot_image_->width,
                                  &boot_image_->height,
                                  &comp,
                                  STBI_rgb_alpha);

  image_file = image_file.parent_path();
  image_file /= "save.png";
  save_image_->pixels = stbi_load(image_file.string().c_str(),
                                  &save_image_->width,
                                  &save_image_->height,
                                  &comp,
                                  STBI_rgb_alpha);

  image_file = image_file.parent_path();
  image_file /= "Tools.png";
  tool_image_->pixels = stbi_load(image_file.string().c_str(),
                                  &tool_image_->width,
                                  &tool_image_->height,
                                  &comp,
                                  STBI_rgb_alpha);

  image_file = image_file.parent_path();
  image_file /= "bell.png";
  alarm_image_->pixels = stbi_load(image_file.string().c_str(),
                                   &alarm_image_->width,
                                   &alarm_image_->height,
                                   &comp,
                                   STBI_rgb_alpha);

  image_file = image_file.parent_path();
  image_file /= "statistics.png";
  stats_image_->pixels = stbi_load(image_file.string().c_str(),
                                   &stats_image_->width,
                                   &stats_image_->height,
                                   &comp,
                                   STBI_rgb_alpha);

  image_file = image_file.parent_path();
  image_file /= "loc.png";
  loc_image_->pixels = stbi_load(image_file.string().c_str(),
                                 &loc_image_->width,
                                 &loc_image_->height,
                                 &comp,
                                 STBI_rgb_alpha);

}
void ImGuiLayer::cleanUpAllIcons() {
  stbi_image_free(own_file_image_->pixels);
  stbi_image_free(word_file_image_->pixels);
  stbi_image_free(pdf_file_image_->pixels);
  stbi_image_free(excel_file_image_->pixels);
  stbi_image_free(ini_file_image_->pixels);
  stbi_image_free(cpp_file_image_->pixels);
  stbi_image_free(ppt_file_image_->pixels);
  stbi_image_free(rar_file_image_->pixels);
  stbi_image_free(txt_file_image_->pixels);
  stbi_image_free(general_file_image_->pixels);

  stbi_image_free(folder_image_->pixels);
  stbi_image_free(pause_image_->pixels);
  stbi_image_free(start_image_->pixels);
  stbi_image_free(boot_image_->pixels);

  stbi_image_free(save_image_->pixels);
  stbi_image_free(tool_image_->pixels);
  stbi_image_free(alarm_image_->pixels);
  stbi_image_free(stats_image_->pixels);
  stbi_image_free(loc_image_->pixels);
}

void ImGuiLayer::onInit() {

}
void ImGuiLayer::changeFonts() {

  bool flag = true;
  if (ImGui::Begin("Fonts Selection for 3D Body.",
                   &flag,
                   ImGuiWindowFlags_::ImGuiWindowFlags_NoCollapse)) {
    //TODO: here add font change function.

    ImGui::GetIO().FontDefault = current_font_;
    ImGui::End();
  }

}
}

