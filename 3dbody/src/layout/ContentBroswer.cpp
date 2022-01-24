
#include "include/layout/ContentBroswer/ContentBroswer.h"
#include "util/ConfigMap.h"

#if defined(__GNUC__)
#pragma GCC diagnostic ignored "-Wint-to-pointer-cast"
#endif

namespace gf {

    ContentBrowser::ContentBrowser()
            : currentDirectory_(ConfigMap::getInstance()->root_dir_) {
    }

    void ContentBrowser::render(bool *open) {
        if (!ImGui::Begin("Content Browser", open)) {
            ImGui::End();
            return;
        }

        if (ImGui::Button("Return Back")) {
            currentDirectory_ = currentDirectory_.parent_path();
        }

        static float padding       = 35.0f;
        static float thumbnailSize = 64.0f;
        float        cellSize      = thumbnailSize + padding;

        float panelWidth  = ImGui::GetContentRegionAvail().x;
        int   columnCount = (int) (panelWidth / cellSize);
        if (columnCount < 1)
            columnCount = 1;

        ImGui::Columns(columnCount, nullptr, false);

        for (auto &directoryEntry: fs::directory_iterator(currentDirectory_)) {
            const auto  &path          = directoryEntry.path();
            auto        relativePath   = fs::relative(path, ConfigMap::getInstance()->root_dir_);
            std::string filenameString = directoryEntry.path().filename().string();
#ifdef GF_WIN
            /// on windows os there are some system file that may cause our program crash.
            if (filenameString.find("$RECYCLE.BIN") != std::string::npos)continue;
            if (filenameString.find("Config.Msi") != std::string::npos)continue;
            if (filenameString.find("System Volume Information") != std::string::npos)continue;
#endif
            ImGui::PushID(filenameString.c_str());
            Ref<Texture2D> icon = FileDirectoryIcon::getInstance()->setupIcons(directoryEntry);
            ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0, 0, 0, 0));
            ImGui::ImageButton((ImTextureID) (icon->getRendererID()),
                               {thumbnailSize, thumbnailSize}, {0, 1}, {1, 0});

            if (ImGui::BeginDragDropSource()) {
                const wchar_t *itemPath = relativePath.c_str();
                ImGui::SetDragDropPayload("LoadModel", itemPath,
                                          (wcslen(itemPath) + 1) * sizeof(wchar_t));
                ImGui::EndDragDropSource();
            }

            ImGui::PopStyleColor();
            if (ImGui::IsItemHovered() && ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left)) {
                if (directoryEntry.is_directory())
                    currentDirectory_ /= path.filename();
            }
            ImGui::TextWrapped(filenameString.c_str());

            ImGui::NextColumn();

            ImGui::PopID();
        }

        ImGui::Columns(1);

        // TODO: status bar
        ImGui::End();

    }

    FileDirectoryIcon *FileDirectoryIcon::instance_ = nullptr;

    Ref<Texture2D> FileDirectoryIcon::setupIcons(const fs::directory_entry &entry) const {
        Ref<Texture2D> current_icon;
        if (entry.is_directory()) {
            current_icon = directoryIcon;
        } else {
            if (entry.path().extension() == ".txt")
                current_icon = txtFileIcon;
            else if (entry.path().extension() == ".pdf")
                current_icon = pdfFileIcon;
            else if (entry.path().extension() == ".doc" ||
                     entry.path().extension() == ".docx")
                current_icon = wordFileIcon;
            else if (entry.path().extension() == ".rar" ||
                     entry.path().extension() == ".zip")
                current_icon = rarFileIcon;
            else if (entry.path().extension() == ".pptx" ||
                     entry.path().extension() == ".ppt")
                current_icon = pptFileIcon;
            else if (entry.path().extension() == ".cpp" ||
                     entry.path().extension() == ".c" ||
                     entry.path().extension() == ".cxx")
                current_icon = cppFileIcon;
            else if (entry.path().extension() == ".xls")
                current_icon = excelFileIcon;
            else if (entry.path().extension() == ".ini")
                current_icon = iniFileIcon;
            else if (std::find(ConfigMap::getInstance()->input_format_.begin(),
                               ConfigMap::getInstance()->input_format_.end(),
                               entry.path().extension()) != ConfigMap::getInstance()->input_format_.end())
                current_icon = fileIcon;
            else current_icon = defaultFileIcon;
        }
        return current_icon;
    }

    FileDirectoryIcon::FileDirectoryIcon() {

        fs::path resource = fs::path(ConfigMap::getInstance()->resource_dir_);
        resource /= "icons";
        resource /= "icon_others";

        resource /= "folder.png";
        directoryIcon     = Texture2D::create(resource.string());

        resource = resource.parent_path();
        resource /= "file-star.png";
        fileIcon = Texture2D::create(resource.string());

        resource    = resource.parent_path();
        resource /= "cpp.png";
        cppFileIcon = Texture2D::create(resource.string());

        resource     = resource.parent_path();
        resource /= "word.png";
        wordFileIcon = Texture2D::create(resource.string());

        resource    = resource.parent_path();
        resource /= "txt.png";
        txtFileIcon = Texture2D::create(resource.string());

        resource    = resource.parent_path();
        resource /= "pdf.png";
        pdfFileIcon = Texture2D::create(resource.string());

        resource    = resource.parent_path();
        resource /= "rar.png";
        rarFileIcon = Texture2D::create(resource.string());

        resource    = resource.parent_path();
        resource /= "ppt.png";
        pptFileIcon = Texture2D::create(resource.string());

        resource    = resource.parent_path();
        resource /= "ini.png";
        iniFileIcon = Texture2D::create(resource.string());

        resource      = resource.parent_path();
        resource /= "excel.png";
        excelFileIcon = Texture2D::create(resource.string());

        resource        = resource.parent_path();
        resource /= "file.png";
        defaultFileIcon = Texture2D::create(resource.string());

    }
}

