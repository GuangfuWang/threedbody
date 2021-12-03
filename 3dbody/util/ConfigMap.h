
#ifndef INC_3DBODY_CONFIGMAP_H
#define INC_3DBODY_CONFIGMAP_H

#include <filesystem>
#include <string>

namespace gf {


    inline std::filesystem::path getRootDir() {
        std::filesystem::path curr = std::filesystem::current_path().parent_path();
        return curr;
    }

    class ConfigMap {
    public:

        static void Init();

    public:
        static std::string root_dir_;
        static std::string source_code_dir_;
        static std::string resource_dir_;
        static std::string script_dir_;
        static std::string test_dir_;

        //short key setups
        static std::string open_file_;
        static std::string new_file_;
        static std::string save_file_;
        static std::string save_as_;
        static std::string undo_actions_;
        static std::string exit_;

        static std::string translate_;
        static std::string rotate_;
        static std::string scale_;
        static std::string zoom_in_;
        static std::string zoom_out_;

        static std::string begin_play_;
        static std::string end_play_;
        static std::string pause_play_;

        static std::string simulation_begin_;
        static std::string simulation_pause_;
        static std::string simulation_end_;

        static std::string front_view_;
        static std::string top_view_;
        static std::string left_view_;
        static std::string orthogonal_view_;
        static std::string projective_view_;
        static std::string transparent_view_;

        static std::string edit_mode_;
        static std::string render_mode_;

        static std::string find_pad_;
        static std::string settings_pad_;

        static std::string python_enable_;
        static std::string shell_enable_;


        static unsigned int moniter_width_;
        static unsigned int moniter_height_;


    };

    void ConfigMap::Init() {

        std::filesystem::path curr = getRootDir();
        root_dir_ = curr.string();
        curr /= "resources";
        resource_dir_ = curr.string();
        curr = curr.parent_path();
        curr /= "scripts";
        script_dir_ = curr.string();
        curr = curr.parent_path();
        curr /= "tests";
        test_dir_ = curr.string();
        curr = curr.parent_path();
        curr /= "3dbody";
        source_code_dir_ = curr.string();

    }

}


#endif //INC_3DBODY_CONFIGMAP_H
