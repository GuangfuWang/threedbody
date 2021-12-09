
#ifndef INC_3DBODY_3DBODY_INCLUDE_LAYOUT_TOOLBAR_H_
#define INC_3DBODY_3DBODY_INCLUDE_LAYOUT_TOOLBAR_H_

namespace gf {

enum TOOL_BAR_TYPE {
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

class ToolBar {
 public:
  static void
  create_tool_bar(const TOOL_BAR_TYPE &tool_bar_type) {
	if (tool_bar_type & TOOL_BAR_TYPE::DEFAULT) {
	  create_default_tool_bar();
	} else if (tool_bar_type & TOOL_BAR_TYPE::SLAM) {
	  create_slam_tool_bar();
	} else if (tool_bar_type & TOOL_BAR_TYPE::SHAPE_ANALYSIS) {
	  create_shape_analysis_tool_bar();
	} else if (tool_bar_type & TOOL_BAR_TYPE::FLUID_SIMULATION) {
	  create_fluid_simulation_tool_bar();
	} else if (tool_bar_type & TOOL_BAR_TYPE::MOLECULAR_SIMULATION) {
	  create_molecular_simulation_tool_bar();
	} else if (tool_bar_type & TOOL_BAR_TYPE::MODEL_EDIT) {
	  create_model_edit_tool_bar();
	} else if (tool_bar_type & TOOL_BAR_TYPE::MBD_DESIGN) {
	  create_mbd_design_tool_bar();
	} else if (tool_bar_type & TOOL_BAR_TYPE::MODEL_DYNAMICS) {
	  create_model_dynamics_tool_bar();
	} else if (tool_bar_type & TOOL_BAR_TYPE::PLACE_HOLDER) {
	  create_place_holder_tool_bar();
	} else {
	  create_default_tool_bar();
	}
  }

 private:

  static void create_default_tool_bar() {

  }

  static void create_slam_tool_bar() {
	//TODO: implement this.
  }

  static void create_shape_analysis_tool_bar() {
	//TODO: implement this.
  }

  static void create_fluid_simulation_tool_bar() {
	//TODO: implement this.
  }

  static void create_molecular_simulation_tool_bar() {
	//TODO: implement this.
  }

  static void create_model_edit_tool_bar() {
	//TODO: implement this.
  }

  static void create_mbd_design_tool_bar() {
	//TODO: implement this.
  }

  static void create_model_dynamics_tool_bar() {
	//TODO: implement this.
  }

  static void create_place_holder_tool_bar() {
	//TODO: implement this.
  }

};

}

#endif //INC_3DBODY_3DBODY_INCLUDE_LAYOUT_TOOLBAR_H_
