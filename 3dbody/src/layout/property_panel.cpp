#include "include/layout/property_panel.h"
#include "imgui.h"
#include "imgui_internal.h"

namespace gf {

static void draw_vec3_widget(const std::string &label, glm::vec3 &values, float columnWidth = 100.0f) {
  ImGuiIO &io = ImGui::GetIO();
  auto boldFont = io.Fonts->Fonts[0];

  ImGui::PushMultiItemsWidths(3, ImGui::CalcItemWidth());
  ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2{0, 0});

  float lineHeight = GImGui->Font->FontSize + GImGui->Style.FramePadding.y * 2.0f;
  ImVec2 buttonSize = {lineHeight + 3.0f, lineHeight};

  ImGui::PushFont(boldFont);
  ImGui::Button("X", buttonSize);
  ImGui::PopFont();

  ImGui::SameLine();
  ImGui::DragFloat("##X", &values.x, 0.1f, 0.0f, 0.0f, "%.2f");
  ImGui::PopItemWidth();
  ImGui::SameLine();

  ImGui::PushFont(boldFont);
  ImGui::Button("Y", buttonSize);
  ImGui::PopFont();

  ImGui::SameLine();
  ImGui::DragFloat("##Y", &values.y, 0.1f, 0.0f, 0.0f, "%.2f");
  ImGui::PopItemWidth();
  ImGui::SameLine();

  ImGui::PushFont(boldFont);
  ImGui::Button("Z", buttonSize);
  ImGui::PopFont();

  ImGui::SameLine();
  ImGui::DragFloat("##Z", &values.z, 0.1f, 0.0f, 0.0f, "%.2f");
  ImGui::PopItemWidth();

  ImGui::PopStyleVar();

}

void Property_Panel::render(SceneView *scene_view) {
  auto mesh = scene_view->get_mesh();

  ImGui::Begin("Properties");
  if (ImGui::CollapsingHeader("Mesh", ImGuiTreeNodeFlags_DefaultOpen)) {

    if (ImGui::Button("Open...")) {
      mFileDialog.Open();
    }
    ImGui::SameLine(0, 5.0f);
    ImGui::Text(mCurrentFile.c_str());
  }

  if (ImGui::CollapsingHeader("Material") && mesh) {
    ImGui::ColorPicker3("Color",
                        (float *) &mesh->mColor,
                        ImGuiColorEditFlags_PickerHueWheel | ImGuiColorEditFlags_DisplayRGB);
    ImGui::SliderFloat("Roughness", &mesh->mRoughness, 0.0f, 1.0f);
    ImGui::SliderFloat("Metallic", &mesh->mMetallic, 0.0f, 1.0f);
  }

  if (ImGui::CollapsingHeader("Light")) {

    ImGui::Separator();
    ImGui::Text("Position");
    ImGui::Separator();
    draw_vec3_widget("Position", scene_view->get_light()->mPosition, 80.0f);
  }

  ImGui::End();

  mFileDialog.Display();
  if (mFileDialog.HasSelected()) {
    auto file_path = mFileDialog.GetSelected().string();
    mCurrentFile = file_path.substr(file_path.find_last_of("/\\") + 1);

    mMeshLoadCallback(file_path);

    mFileDialog.ClearSelected();
  }

}

}