
#ifndef INC_3DBODY_3DBODY_INCLUDE_LAYOUT_MENUBAR_H_
#define INC_3DBODY_3DBODY_INCLUDE_LAYOUT_MENUBAR_H_

#include "imgui.h"

namespace gf {

    class MenuBar {

    public:
        static void createManuBar() {
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

                if (ImGui::BeginMenu("Scripts")) {
                    if (ImGui::MenuItem("Python Script", "CTRL+P")) {}
                    if (ImGui::MenuItem("Shell Script", "CTRL+ALT+S")) {}
                    if (ImGui::MenuItem("Lua Script", "CTRL+L", false, false)) {}  // Disabled item
                    ImGui::Separator();
                    if (ImGui::MenuItem("Fortran Script", "CTRL+F")) {}
                    if (ImGui::MenuItem("MatLab Script", "CTRL+M")) {}
                    ImGui::EndMenu();
                }

                if (ImGui::BeginMenu("Tools")) {
                    if (ImGui::MenuItem("SLAM", "CTRL+Z")) {}
                    if (ImGui::MenuItem("Shape Analysis", "CTRL+Y", false, false)) {}  // Disabled item
                    ImGui::Separator();
                    if (ImGui::MenuItem("Model Editing", "CTRL+X")) {}
                    if (ImGui::MenuItem("Rigid FEM", "CTRL+C")) {}
                    if (ImGui::MenuItem("Fluid Simulation", "CTRL+V")) {}
                    ImGui::EndMenu();
                }

                if (ImGui::BeginMenu("Windows")) {
                    if (ImGui::MenuItem("Up View", "CTRL+Y", false, false)) {}  // Disabled item
                    if (ImGui::MenuItem("Front View", "CTRL+X")) {}
                    if (ImGui::MenuItem("Left View", "CTRL+C")) {}
                    if (ImGui::MenuItem("Gizmo", "CTRL+V")) {}
                    ImGui::Separator();
                    if (ImGui::MenuItem("Style", "CTRL+Z")) {}
                    if (ImGui::MenuItem("Camera", "CTRL+V")) {}
                    if (ImGui::MenuItem("Light", "CTRL+V")) {}
                    if (ImGui::MenuItem("Materials", "CTRL+V")) {}
                    ImGui::Separator();
                    if (ImGui::MenuItem("General Settings", "CTRL+V")) {}
                    ImGui::EndMenu();
                }

                if (ImGui::BeginMenu("Help")) {
                    if (ImGui::MenuItem("?Help", "CTRL+Z")) {}
                    if (ImGui::MenuItem("Getting Start", "CTRL+Y", false, false)) {}  // Disabled item
                    if (ImGui::MenuItem("Tips", "CTRL+V")) {}
                    if (ImGui::MenuItem("Bug Report", "CTRL+V")) {}
                    if (ImGui::MenuItem("Suggestion Report", "CTRL+V")) {}
                    ImGui::Separator();
                    if (ImGui::MenuItem("Register", "CTRL+X")) {}
                    if (ImGui::MenuItem("Update", "CTRL+C")) {}
                    if (ImGui::MenuItem("Support", "CTRL+V")) {}
                    ImGui::Separator();
                    if (ImGui::MenuItem("About", "CTRL+V")) {}
                    ImGui::EndMenu();
                }
                ImGui::EndMenuBar();
            }

        }

    };

}

#endif //INC_3DBODY_3DBODY_INCLUDE_LAYOUT_MENUBAR_H_
