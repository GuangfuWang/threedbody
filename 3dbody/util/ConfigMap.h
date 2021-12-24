
#ifndef INC_3DBODY_CONFIGMAP_H
#define INC_3DBODY_CONFIGMAP_H

#include <filesystem>
#include <string>
#include <array>
#include "def.h"
#include <include/nfd.h>

namespace gf {

    inline fs::path getRootDir() {
        fs::path curr = fs::current_path().parent_path();
        return curr;
    }


    class BasicInfoMap {
    public:
        virtual ~BasicInfoMap() {}

        BasicInfoMap(const BasicInfoMap &) = delete;

        void operator=(const BasicInfoMap &copy) = delete;

        Ref_Unique<BasicInfoMap> getInstance();

    private:
        BasicInfoMap();

        void init();

    public:
        string softwareName;
        string softwareVersion;
        string authors;
        string authorsEmail;
        string contributors;
        string facilities;
        string introductionInfo;
        string officialSites;
        string wikiSites;
        string dateOfCreation;

        unsigned int versionMajor;
        unsigned int versionMinor;
        unsigned int versionPatch;
        bool         LTSVersion;
        bool         openSource;

    private:
        static BasicInfoMap *instance;
    };


    class ImportExportFormatMap {

    };


    class WindowSettingsMap {

    };


    class WorkbenchMap {

    };


    class LoggingMap {

    };


    class MonitoringMap {

    };

    class PanelsMap {

    };

    class DirMap{

    };

    class LanguageMap{

    };

    class ConfigMap {
    public:
        static ConfigMap *getInstance();

    private:
        ConfigMap();

        ~ConfigMap();

        ///TODO: Use config.ini for implementation.
        static void loadFormat(std::ifstream &ifs);

    public:
        ConfigMap(ConfigMap const &) = delete;

        void operator=(ConfigMap const &) = delete;

        std::string root_dir_;
        std::string source_code_dir_;
        std::string resource_dir_;
        std::string script_dir_;
        std::string test_dir_;

        std::vector<const char *> input_format_;
        std::vector<const char *> output_format_;

        nfdu8filteritem_t *filterInputFormat;
        nfdu8filteritem_t *filterOutputFormat;

    private:
        static ConfigMap *instance;
    };

}

#endif //INC_3DBODY_CONFIGMAP_H
