

#ifndef INC_3DBODY_3DBODY_INCLUDE_LAYOUT_PRPPERTY_PANEL_H_
#define INC_3DBODY_3DBODY_INCLUDE_LAYOUT_PRPPERTY_PANEL_H_

#include "imgui.h"
#include "util/imgui_file_browser.h"
#include "util/ConfigMap.h"
#include "include/scene/scene_view.h"

#include <list>

namespace gf{

class Property_Panel
{
 public:

  Property_Panel()
  {
    mCurrentFile = "< ... >";

    mFileDialog.SetTitle("Open 3d model");
    mFileDialog.SetFileFilters({".fbx",".obj",".ply"});
  }

  void render(SceneView* mScene);

  void set_mesh_load_callback(const std::function<void(const std::string&)>& callback)
  {
    mMeshLoadCallback = callback;
  }

 private:

 private:
  // create a file browser instance
  ImGui::FileBrowser mFileDialog;

  std::function<void(const std::string&)> mMeshLoadCallback;

  std::string mCurrentFile;

};

}

#endif //INC_3DBODY_3DBODY_INCLUDE_LAYOUT_PRPPERTY_PANEL_H_
