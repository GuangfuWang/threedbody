
#ifndef INC_3DBODY_3DBODY_INCLUDE_LAYOUT_CONTENTBROSWER_H_
#define INC_3DBODY_3DBODY_INCLUDE_LAYOUT_CONTENTBROSWER_H_

#include <filesystem>
#include <imgui.h>
#include "include/mesh/Texture.h"

namespace gf {

//fixme: maybe better if move this class to config.
class FileDirectoryIcon {
 public:
  static FileDirectoryIcon *getInstance() {
	if (instance_==nullptr) {
	  instance_ = new FileDirectoryIcon();
	}
	return instance_;
  }

  Ref<Texture2D> setupIcons(const fs::directory_entry &entry) const;

 private:
  FileDirectoryIcon();

 public:
  Ref<Texture2D> directoryIcon;

  Ref<Texture2D> fileIcon;
  Ref<Texture2D> pdfFileIcon;
  Ref<Texture2D> wordFileIcon;
  Ref<Texture2D> txtFileIcon;
  Ref<Texture2D> cppFileIcon;
  Ref<Texture2D> pptFileIcon;
  Ref<Texture2D> rarFileIcon;
  Ref<Texture2D> excelFileIcon;
  Ref<Texture2D> iniFileIcon;
  Ref<Texture2D> defaultFileIcon;

 private:
  static FileDirectoryIcon *instance_;
};

class ContentBrowser {
 public:
  ContentBrowser();

  void render(bool * open = new bool(true));
 private:
  fs::path currentDirectory_;
};
}

#endif //INC_3DBODY_3DBODY_INCLUDE_LAYOUT_CONTENTBROSWER_H_
