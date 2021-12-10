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

  void render();
 private:
  std::filesystem::path m_CurrentDirectory;

  Ref<Texture2D> m_DirectoryIcon;
  Ref<Texture2D> m_FileIcon;

  Ref<Texture2D> m_PDFFileIcon;
  Ref<Texture2D> m_WORDFileIcon;
  Ref<Texture2D> m_TXTFileIcon;
  Ref<Texture2D> m_CPPFileIcon;
  Ref<Texture2D> m_PPTFileIcon;
  Ref<Texture2D> m_RARFileIcon;
  Ref<Texture2D> m_EXCELFileIcon;
  Ref<Texture2D> m_INIFileIcon;
  Ref<Texture2D> m_DEFAULTFileIcon;
};
}

#endif //INC_3DBODY_3DBODY_INCLUDE_LAYOUT_CONTENTBROSWER_H_
