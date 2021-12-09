#include <filesystem>
#include "include/layout/FontTogglePanel.h"
#include "imgui.h"
#include "util/ConfigMap.h"

namespace gf {

void FontTogglePanel::render() {
  if (!font_loaded){
	loadAllFonts();
  }
  bool p;
  font_size_ = 18.0f;
  if (ImGui::Begin("Font Toggle", &p, ImGuiWindowFlags_::ImGuiWindowFlags_NoCollapse)) {
	ImGui::Text("Font:");
	ImGui::SameLine();
	//todo: not finished.

	ImGui::ListBoxHeader("");
	static unsigned char font_current_idx = 0;
	std::string          select_font;
	for (int             i                = 0; i < font_list_.size(); i++) {
	  const bool is_selected = (font_current_idx==i);
	  if (ImGui::Selectable((const char *)font_list_[i].c_str(), is_selected)) {
		select_font = font_list_[i];
	  }
	}
	ImGui::ListBoxFooter();
	if (ImGui::Button("Confirm Font")) {
	  ImGuiIO               io        = ImGui::GetIO();
	  std::filesystem::path font_path = ConfigMap::getInstance()->resource_dir_;
	  font_path /= "fonts";
	  font_path /= select_font;
	  io.FontDefault = io.Fonts->AddFontFromFileTTF(
		  font_path.string().c_str(),
		  font_size_);
	}
	ImGui::SameLine();
	if (ImGui::Button("Cancel")) {
	  //do nothing, actually.
	}

	ImGui::End();
  }
}
void FontTogglePanel::loadAllFonts() {
	font_list_.reserve(42);
	std::filesystem::path temp=ConfigMap::getInstance()->resource_dir_;
	temp/="fonts/EN";
	//todo: not finished.
}
}