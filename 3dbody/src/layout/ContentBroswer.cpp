
#include "include/layout/ContentBroswer.h"
#include "util/ConfigMap.h"

namespace gf{


ContentBrowser::ContentBrowser()
	: m_CurrentDirectory(ConfigMap::getInstance()->root_dir_)
{
  std::filesystem::path resource=std::filesystem::path(ConfigMap::getInstance()->resource_dir_);
  resource/="icons";
  resource/="icon_others";

  resource/="folder.png";
  m_DirectoryIcon = Texture2D::Create(resource.string());
  resource=resource.parent_path();
  resource/="file-star.png";
  m_FileIcon = Texture2D::Create(resource.string());
}

void ContentBrowser::OnImGuiRender()
{
  ImGui::Begin("Content Browser");

  if (m_CurrentDirectory != std::filesystem::path(ConfigMap::getInstance()->root_dir_))
  {
	if (ImGui::Button("<-"))
	{
	  m_CurrentDirectory = m_CurrentDirectory.parent_path();
	}
  }

  static float padding = 16.0f;
  static float thumbnailSize = 128.0f;
  float cellSize = thumbnailSize + padding;

  float panelWidth = ImGui::GetContentRegionAvail().x;
  int columnCount = (int)(panelWidth / cellSize);
  if (columnCount < 1)
	columnCount = 1;

  ImGui::Columns(columnCount, 0, false);

  for (auto& directoryEntry : std::filesystem::directory_iterator(m_CurrentDirectory))
  {
	const auto& path = directoryEntry.path();
	auto relativePath = std::filesystem::relative(path, ConfigMap::getInstance()->root_dir_);
	std::string filenameString = relativePath.filename().string();

	ImGui::PushID(filenameString.c_str());
	Ref<Texture2D> icon = directoryEntry.is_directory() ? m_DirectoryIcon : m_FileIcon;
	ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0, 0, 0, 0));
	ImGui::ImageButton((ImTextureID)icon->GetRendererID(), { thumbnailSize, thumbnailSize }, { 0, 1 }, { 1, 0 });

	if (ImGui::BeginDragDropSource())
	{
	  const wchar_t* itemPath = relativePath.c_str();
	  ImGui::SetDragDropPayload("CONTENT_BROWSER_ITEM", itemPath, (wcslen(itemPath) + 1) * sizeof(wchar_t));
	  ImGui::EndDragDropSource();
	}

	ImGui::PopStyleColor();
	if (ImGui::IsItemHovered() && ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left))
	{
	  if (directoryEntry.is_directory())
		m_CurrentDirectory /= path.filename();

	}
	ImGui::TextWrapped(filenameString.c_str());

	ImGui::NextColumn();

	ImGui::PopID();
  }

  ImGui::Columns(1);

  ImGui::SliderFloat("Thumbnail Size", &thumbnailSize, 16, 512);
  ImGui::SliderFloat("Padding", &padding, 0, 32);

  // TODO: status bar
  ImGui::End();
}

}

