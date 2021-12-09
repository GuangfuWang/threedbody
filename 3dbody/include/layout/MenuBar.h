

#ifndef INC_3DBODY_3DBODY_INCLUDE_LAYOUT_MENUBAR_H_
#define INC_3DBODY_3DBODY_INCLUDE_LAYOUT_MENUBAR_H_

#include "imgui.h"
namespace gf {

class MenuBar {

 public:
  static void create_manu_bar() {
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

};

}

#endif //INC_3DBODY_3DBODY_INCLUDE_LAYOUT_MENUBAR_H_
