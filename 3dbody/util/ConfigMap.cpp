#include "util/ConfigMap.h"
#include "util/StringHelper.h"
#include "util/Log.h"
#include <fstream>

namespace gf {

    BasicInfoMap *BasicInfoMap::instance = nullptr;
    ConfigMap    *ConfigMap::instance    = nullptr;

    BasicInfoMap::BasicInfoMap() {
        init();
    }

    Ref_Unique<BasicInfoMap> BasicInfoMap::getInstance() {
        if (instance == nullptr) {
            instance = new BasicInfoMap();
        }
        Ref_Unique<BasicInfoMap> ret(instance);
        return ret;
    }

    void BasicInfoMap::init() {
        std::ifstream ifs("./../config/config.ini");
        if (ifs.is_open()) {
            if (ifs.bad()) {
                GF_CORE_ERROR("Error: cannot open config.ini file...");
                GF_CORE_ERROR("Default basic info will be used");
                softwareName     = "3D Body";
                softwareVersion  = "2.1.0";
                authors          = "Guangfu Wang";
                authorsEmail     = "thuwgf@mail.com";
                contributors     = "";
                facilities       = "Bigdata-Department, Chine Mining Group";
                introductionInfo = "";
                officialSites    = "https://www.place_holder.com";
                wikiSites        = "https://www.place_holder.com";
                dateOfCreation   = "2021-11-20";

                versionMajor = 2;
                versionMinor = 1;
                versionPatch = 0;

                LTSVersion = true;
                openSource = true;
                return;
            }

            string temp;
            while (std::getline(ifs, temp)) {
                if (temp.size() < 1)continue;
                int hashIdx = temp.find_first_of('#');
                temp = temp.substr(0, hashIdx);
                temp = trim(temp);
                if (temp.size() < 1)continue;
                if (temp[0] == '$') {
                    int idx = temp.find("");
                }
            }

            ifs.close();
        }

    }

    ConfigMap::ConfigMap() :
            filterInputFormat(nullptr),
            filterOutputFormat(nullptr) {

        if (input_format_.empty()) {
            input_format_.reserve(55);
            input_format_.emplace_back(".fbx");
            input_format_.emplace_back(".obj");
            input_format_.emplace_back(".ply");
            input_format_.emplace_back(".stl");
            input_format_.emplace_back(".blend");
            input_format_.emplace_back(".3d");
            input_format_.emplace_back(".3ds");
            input_format_.emplace_back(".3mf");
            input_format_.emplace_back(".ac");
            input_format_.emplace_back(".ac3d");
            input_format_.emplace_back(".acc");
            input_format_.emplace_back(".amj");
            input_format_.emplace_back(".ase");
            input_format_.emplace_back(".ask");
            input_format_.emplace_back(".b3d");
            input_format_.emplace_back(".bvh");
            input_format_.emplace_back(".cms");
            input_format_.emplace_back(".cob");
            input_format_.emplace_back(".dae");
            input_format_.emplace_back(".dxf");
            input_format_.emplace_back(".enff");
            input_format_.emplace_back(".hmb");
            input_format_.emplace_back(".irr");
            input_format_.emplace_back(".lwo");
            input_format_.emplace_back(".lws");
            input_format_.emplace_back(".lxo");
            input_format_.emplace_back(".m3d");
            input_format_.emplace_back(".md2");
            input_format_.emplace_back(".md3");
            input_format_.emplace_back(".md5");
            input_format_.emplace_back(".mdc");
            input_format_.emplace_back(".mdl");
            input_format_.emplace_back(".VanillaMesh");
            input_format_.emplace_back(".mot");
            input_format_.emplace_back(".ms3d");
            input_format_.emplace_back(".ndo");
            input_format_.emplace_back(".nff");
            input_format_.emplace_back(".off");
            input_format_.emplace_back(".ogex");
            input_format_.emplace_back(".pmx");
            input_format_.emplace_back(".prj");
            input_format_.emplace_back(".q3o");
            input_format_.emplace_back(".q3s");
            input_format_.emplace_back(".raw");
            input_format_.emplace_back(".scn");
            input_format_.emplace_back(".sib");
            input_format_.emplace_back(".smd");
            input_format_.emplace_back(".stp");
            input_format_.emplace_back(".ter");
            input_format_.emplace_back(".uc");
            input_format_.emplace_back(".vta");
            input_format_.emplace_back(".x");
            input_format_.emplace_back(".x3d");
            input_format_.emplace_back(".xgl");
            input_format_.emplace_back(".zgl");

            GF_CORE_INFO(input_format_[0]);
        }
        if (output_format_.empty()) {
            output_format_.reserve(9);
            output_format_.emplace_back(".dae");
            output_format_.emplace_back(".stl");
            output_format_.emplace_back(".obj");
            output_format_.emplace_back(".ply");
            output_format_.emplace_back(".x");
            output_format_.emplace_back(".3ds");
            output_format_.emplace_back(".json");
            output_format_.emplace_back(".assbin");
            output_format_.emplace_back(".step");
        }
        if (filterInputFormat == nullptr) {
            unsigned int num = input_format_.size();
            filterInputFormat = new nfdfilteritem_t[num];
            int       idx = 0;
            for (auto &each: input_format_) {
                filterInputFormat[idx++] = cvtFilter(each);
            }
        }
        if (filterOutputFormat == nullptr) {
            unsigned int num = output_format_.size();
            filterOutputFormat = new nfdfilteritem_t[num];
            int       idx = 0;
            for (auto &each: output_format_) {
                filterOutputFormat[idx++] = cvtFilter(each);
            }
        }

        fs::path curr = getRootDir();
        root_dir_        = curr.string();
        curr /= "resources";
        resource_dir_    = curr.string();
        curr             = curr.parent_path();
        curr /= "scripts";
        script_dir_      = curr.string();
        curr             = curr.parent_path();
        curr /= "tests";
        test_dir_        = curr.string();
        curr             = curr.parent_path();
        curr /= "3dbody";
        source_code_dir_ = curr.string();
    }

    ConfigMap *ConfigMap::getInstance() {
        if (instance == nullptr) {

            instance = new ConfigMap();
        }
        return instance;
    }

    void ConfigMap::loadFormat(std::ifstream &ifs) {

    }

    ConfigMap::~ConfigMap() {

    }
}
