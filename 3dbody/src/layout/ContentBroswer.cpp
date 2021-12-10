
#include "include/layout/ContentBroswer.h"
#include "util/ConfigMap.h"
#include "util/Log.h"
#include "util/StringHelper.h"

namespace gf {

ContentBrowser::ContentBrowser()
	: m_CurrentDirectory(ConfigMap::getInstance()->root_dir_) {
  std::filesystem::path resource = std::filesystem::path(ConfigMap::getInstance()->resource_dir_);
  resource /= "icons";
  resource /= "icon_others";

  resource /= "folder.png";
  m_DirectoryIcon                = Texture2D::Create(resource.string());

  resource   = resource.parent_path();
  resource /= "file-star.png";
  m_FileIcon = Texture2D::Create(resource.string());

  resource      = resource.parent_path();
  resource /= "cpp.png";
  m_CPPFileIcon = Texture2D::Create(resource.string());

  resource       = resource.parent_path();
  resource /= "word.png";
  m_WORDFileIcon = Texture2D::Create(resource.string());

  resource      = resource.parent_path();
  resource /= "txt.png";
  m_TXTFileIcon = Texture2D::Create(resource.string());

  resource      = resource.parent_path();
  resource /= "pdf.png";
  m_PDFFileIcon = Texture2D::Create(resource.string());

  resource      = resource.parent_path();
  resource /= "rar.png";
  m_RARFileIcon = Texture2D::Create(resource.string());

  resource      = resource.parent_path();
  resource /= "ppt.png";
  m_PPTFileIcon = Texture2D::Create(resource.string());

  resource      = resource.parent_path();
  resource /= "ini.png";
  m_INIFileIcon = Texture2D::Create(resource.string());

  resource        = resource.parent_path();
  resource /= "excel.png";
  m_EXCELFileIcon = Texture2D::Create(resource.string());

  resource          = resource.parent_path();
  resource /= "file.png";
  m_DEFAULTFileIcon = Texture2D::Create(resource.string());

}

void ContentBrowser::render() {
  ImGui::Begin("Content Browser");

//  if (m_CurrentDirectory!=std::filesystem::path(ConfigMap::getInstance()->root_dir_)) {
	if (ImGui::Button("<-")) {
	  m_CurrentDirectory = m_CurrentDirectory.parent_path();
	}
//  }

  static float padding       = 35.0f;
  static float thumbnailSize = 64.0f;
  float        cellSize      = thumbnailSize + padding;

  float panelWidth  = ImGui::GetContentRegionAvail().x;
  int   columnCount = (int)(panelWidth/cellSize);
  if (columnCount < 1)
	columnCount = 1;

  ImGui::Columns(columnCount, 0, false);

  for (auto &directoryEntry : std::filesystem::directory_iterator(m_CurrentDirectory)) {
	const auto  &path          = directoryEntry.path();
	auto        relativePath   = std::filesystem::relative(path, ConfigMap::getInstance()->root_dir_);
	std::string filenameString = directoryEntry.path().filename().string();
#ifdef GF_WIN
	if (filenameString.find("$RECYCLE.BIN")!=std::string::npos)continue;
	if (filenameString.find("Config.Msi")!=std::string::npos)continue;
	if (filenameString.find("System Volume Information")!=std::string::npos)continue;
#endif
	ImGui::PushID(filenameString.c_str());
	Ref<Texture2D> icon;
	if (directoryEntry.is_directory()) {
	  icon = m_DirectoryIcon;
	} else {
	  if (directoryEntry.path().extension()==".txt")icon = m_TXTFileIcon;
	  else if (directoryEntry.path().extension()==".pdf")icon = m_PDFFileIcon;
	  else if (directoryEntry.path().extension()==".doc" || directoryEntry.path().extension()==".docx")
		icon = m_WORDFileIcon;
	  else if (directoryEntry.path().extension()==".rar" || directoryEntry.path().extension()==".zip")
		icon = m_RARFileIcon;
	  else if (directoryEntry.path().extension()==".pptx" || directoryEntry.path().extension() ==".ppt")
		icon = m_PPTFileIcon;
	  else if (directoryEntry.path().extension()==".cpp" ||
		  directoryEntry.path().extension()==".c" || directoryEntry.path().extension()==".cxx")
		icon = m_CPPFileIcon;
	  else if (directoryEntry.path().extension()==".xls")icon = m_EXCELFileIcon;
	  else if (directoryEntry.path().extension()==".ini")icon = m_INIFileIcon;
	  else if (std::find(ConfigMap::getInstance()->input_format_.begin(),
						 ConfigMap::getInstance()->input_format_.end(),
						 directoryEntry.path().extension())!=ConfigMap::getInstance()->input_format_.end())
		icon = m_FileIcon;
	  else icon = m_DEFAULTFileIcon;
	}
	ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0, 0, 0, 0));
	ImGui::ImageButton((ImTextureID)(icon->GetRendererID()), {thumbnailSize, thumbnailSize}, {0, 1}, {1, 0});

	if (ImGui::BeginDragDropSource()) {
	  const wchar_t *itemPath = relativePath.c_str();
	  ImGui::SetDragDropPayload("CONTENT_BROWSER_ITEM", itemPath, (wcslen(itemPath) + 1)*sizeof(wchar_t));
	  ImGui::EndDragDropSource();
	}

	ImGui::PopStyleColor();
	if (ImGui::IsItemHovered() && ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left)) {
	  if (directoryEntry.is_directory())
		m_CurrentDirectory /= path.filename();

	}
	ImGui::TextWrapped(filenameString.c_str());

	ImGui::NextColumn();

	ImGui::PopID();
  }

  ImGui::Columns(1);

//  ImGui::SliderFloat("Thumbnail Size", &thumbnailSize, 16, 512);
//  ImGui::SliderFloat("Padding", &padding, 0, 32);

  // TODO: status bar
  ImGui::End();

}

}

