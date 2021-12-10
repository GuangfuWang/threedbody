#include "include/layout/SceneView.h"
#include "util/Log.h"
#include "imgui.h"

namespace gf {

void SceneView::resize(int32_t width, int32_t height) {
  mSize.x = width;
  mSize.y = height;

  mFrameBuffer->create_buffers((int32_t) mSize.x, (int32_t) mSize.y);
}

void SceneView::on_mouse_move(double x, double y, MOUSE_INPUT_CODE button) {
  mCamera->on_mouse_move(x, y, button);
}

void SceneView::on_mouse_wheel(double delta) {
  mCamera->on_mouse_wheel(delta);
}

void SceneView::load_mesh(const std::string &filepath) {
  if (!mMesh)
    mMesh = std::make_shared<Mesh>();

  mMesh->load(filepath);

}

void SceneView::render() {

  mShader->use();

  mLight->update(mShader.get());

  mFrameBuffer->bind();

  if (mMesh) {
    mMesh->update(mShader.get());
    mMesh->render();
  }

  mFrameBuffer->unbind();

  ImGui::Begin("Model View");

  ImVec2 viewportPanelSize = ImGui::GetContentRegionAvail();
  mSize = {viewportPanelSize.x, viewportPanelSize.y};

  mCamera->set_aspect(mSize.x / mSize.y);
  mCamera->update(mShader.get());

  // add rendered texture to ImGUI scene window
  uint64_t textureID = mFrameBuffer->get_texture();
  ImGui::Image(reinterpret_cast<void *>(textureID),
               ImVec2{mSize.x, mSize.y},
               ImVec2{0, 1},
               ImVec2{1, 0});

  ImGui::End();
}
}

