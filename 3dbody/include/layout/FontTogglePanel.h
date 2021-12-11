

#ifndef INC_3DBODY_3DBODY_INCLUDE_LAYOUT_FONTTOGGLEPANEL_H_
#define INC_3DBODY_3DBODY_INCLUDE_LAYOUT_FONTTOGGLEPANEL_H_

#include <vector>
#include <string>

namespace gf {

class FontTogglePanel {
 public:
  void render();

 private:

  void loadAllFonts();

 private:

  std::vector<std::string> fontList_;

  bool fontLoaded = false;

  float fontSize_;
};

}

#endif //INC_3DBODY_3DBODY_INCLUDE_LAYOUT_FONTTOGGLEPANEL_H_
