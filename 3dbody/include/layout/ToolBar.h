
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
  createToolBar(const TOOL_BAR_TYPE &tool_bar_type) {
	if (tool_bar_type & TOOL_BAR_TYPE::DEFAULT) {
	  createDefaultToolBar();
	} else if (tool_bar_type & TOOL_BAR_TYPE::SLAM) {
	  createSlamToolBar();
	} else if (tool_bar_type & TOOL_BAR_TYPE::SHAPE_ANALYSIS) {
	  createShapeAnalysisToolBar();
	} else if (tool_bar_type & TOOL_BAR_TYPE::FLUID_SIMULATION) {
	  createFluidSimulationToolBar();
	} else if (tool_bar_type & TOOL_BAR_TYPE::MOLECULAR_SIMULATION) {
	  createMolecularSimulationToolBar();
	} else if (tool_bar_type & TOOL_BAR_TYPE::MODEL_EDIT) {
	  createModelEditToolBar();
	} else if (tool_bar_type & TOOL_BAR_TYPE::MBD_DESIGN) {
	  createMbdDesignToolBar();
	} else if (tool_bar_type & TOOL_BAR_TYPE::MODEL_DYNAMICS) {
	  createModelDynamicsToolBar();
	} else if (tool_bar_type & TOOL_BAR_TYPE::PLACE_HOLDER) {
	  createPlaceHolderToolBar();
	} else {
	  createDefaultToolBar();
	}
  }

 private:

  static void createDefaultToolBar() {

  }

  static void createSlamToolBar() {
	//TODO: implement this.
  }

  static void createShapeAnalysisToolBar() {
	//TODO: implement this.
  }

  static void createFluidSimulationToolBar() {
	//TODO: implement this.
  }

  static void createMolecularSimulationToolBar() {
	//TODO: implement this.
  }

  static void createModelEditToolBar() {
	//TODO: implement this.
  }

  static void createMbdDesignToolBar() {
	//TODO: implement this.
  }

  static void createModelDynamicsToolBar() {
	//TODO: implement this.
  }

  static void createPlaceHolderToolBar() {
	//TODO: implement this.
  }

};

}

#endif //INC_3DBODY_3DBODY_INCLUDE_LAYOUT_TOOLBAR_H_
