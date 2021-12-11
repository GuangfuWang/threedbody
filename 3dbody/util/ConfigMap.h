
#ifndef INC_3DBODY_CONFIGMAP_H
#define INC_3DBODY_CONFIGMAP_H

#include <filesystem>
#include <string>
#include <array>
#include "def.h"

namespace gf {

inline fs::path getRootDir() {
  fs::path curr = fs::current_path().parent_path();
  return curr;
}

class ConfigMap {
 public:
  static ConfigMap *getInstance() ;
private:
  ConfigMap() ;
  ~ConfigMap();

  ///TODO: Use config.conf for implementation.
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

 private:
  static ConfigMap* instance;
};

}

#endif //INC_3DBODY_CONFIGMAP_H
