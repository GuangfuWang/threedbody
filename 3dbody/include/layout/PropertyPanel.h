

#ifndef INC_3DBODY_3DBODY_INCLUDE_LAYOUT_PRPPERTY_PANEL_H_
#define INC_3DBODY_3DBODY_INCLUDE_LAYOUT_PRPPERTY_PANEL_H_

#include <imgui.h>
#include "def.h"
#include "include/layout/SceneView.h"
#include "util/ConfigMap.h"
#include "util/FileDialog.h"

#include <list>

namespace gf {

class Property_Panel {
 public:

  Property_Panel() {
	mCurrentFile = "< --- >";
	mFileDialog  = std::make_unique<FileDialog>();
  }

  void render(SceneView *mScene);

  void setMeshLoadCallback(const FileLoaderFunc &callback) {
	mMeshLoadCallback = callback;
  }

  void resize(const unsigned int &width, const unsigned int &height) {
	mySize = ImVec2(width, height);
  }

 private:

 private:
  // create a file browser instance
  Ref_Unique<FileDialog> mFileDialog;

  FileLoaderFunc mMeshLoadCallback;

  string mCurrentFile;

  ImVec2 mySize;

};

}

#endif //INC_3DBODY_3DBODY_INCLUDE_LAYOUT_PRPPERTY_PANEL_H_
