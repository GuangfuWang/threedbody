

#ifndef INC_3DBODY_3DBODY_INCLUDE_LAYOUT_TOOLS_H_
#define INC_3DBODY_3DBODY_INCLUDE_LAYOUT_TOOLS_H_

namespace gf {

enum TOOL_TYPE {
  DEFAULT              = 0,
  SLAM                 = 1 << 0,
  SHAPE_ANALYSIS       = 1 << 1,
  FLUID_SIMULATION     = 1 << 2,
  MOLECULAR_SIMULATION = 1 << 3,
  MODEL_EDIT           = 1 << 4,
  MBD_DESIGN           = 1 << 5,
  MODEL_DYNAMICS       = 1 << 6,
  PLACE_HOLDER         = 1 << 7
};

}

#endif //INC_3DBODY_3DBODY_INCLUDE_LAYOUT_TOOLS_H_
