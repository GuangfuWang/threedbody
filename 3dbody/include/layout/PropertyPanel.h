

#ifndef INC_3DBODY_3DBODY_INCLUDE_LAYOUT_PRPPERTY_PANEL_H_
#define INC_3DBODY_3DBODY_INCLUDE_LAYOUT_PRPPERTY_PANEL_H_

#include "imgui.h"
#include "util/ImGuiFileBrowser.h"
#include "util/ConfigMap.h"
#include "SceneView.h"

#include <list>

namespace gf {

class Property_Panel {
 public:

  Property_Panel() {
	mCurrentFile = "< ... >";

	mFileDialog.SetTitle("Open 3d model");
	mFileDialog.SetFileFilters(ConfigMap::getInstance()->input_format_);
  }

  void render(SceneView *mScene);

  void set_mesh_load_callback(const std::function<void(const std::string &)> &callback) {
	mMeshLoadCallback = callback;
  }

  void resize(const unsigned int &width, const unsigned int &height) {
	mySize = ImVec2(width, height);
  }

 private:

 private:
  // create a file browser instance
  ImGui::FileBrowser                       mFileDialog;

  std::function<void(const std::string &)> mMeshLoadCallback;

  std::string mCurrentFile;

  ImVec2 mySize;

};

}

#endif //INC_3DBODY_3DBODY_INCLUDE_LAYOUT_PRPPERTY_PANEL_H_
