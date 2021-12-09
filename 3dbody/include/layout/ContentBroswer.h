//
// Created by bigdata-wgf on 2021/12/9.
//

#ifndef INC_3DBODY_3DBODY_INCLUDE_LAYOUT_CONTENTBROSWER_H_
#define INC_3DBODY_3DBODY_INCLUDE_LAYOUT_CONTENTBROSWER_H_

#include <filesystem>
#include "imgui.h"
#include "include/mesh/Texture.h"

namespace gf {

class ContentBrowser {
 public:
  ContentBrowser();

  void OnImGuiRender();
 private:
  std::filesystem::path m_CurrentDirectory;

  Ref<Texture2D> m_DirectoryIcon;
  Ref<Texture2D> m_FileIcon;
};
}

#endif //INC_3DBODY_3DBODY_INCLUDE_LAYOUT_CONTENTBROSWER_H_
