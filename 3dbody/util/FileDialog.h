

#ifndef INC_3DBODY_3DBODY_UTIL_FILEDIALOG_H_
#define INC_3DBODY_3DBODY_UTIL_FILEDIALOG_H_

#include <include/nfd.h>
#include "util/ConfigMap.h"
#include "util/Log.h"

namespace gf {

enum FILE_DIALOG_RESULT {
  FILE_OPEN_ERROR  = NFD_ERROR,
  FILE_OPEN_OK     = NFD_OKAY,
  FILE_OPEN_CANCEL = NFD_CANCEL
};

enum FILE_SAVE_RESULT {
  FILE_SAVE_ERROR  = NFD_ERROR,
  FILE_SAVE_OK     = NFD_OKAY,
  FILE_SAVE_CANCEL = NFD_CANCEL
};

class FileDialog {
 public:
  FILE_DIALOG_RESULT fileOpenDialog(nfdu8filteritem_t *filter, string &load_file, unsigned int count,
									char *path = ConfigMap::getInstance()->root_dir_.data()) {
	char        *outPath;
	nfdresult_t result = NFD_OpenDialog(&outPath,
										filter, count,
										path);
	if (result==NFD_OKAY) {
	  load_file = string(outPath);
	  NFD_Quit();
	  return FILE_OPEN_OK;
	} else if (result==NFD_CANCEL) {
	  load_file = "";
	  NFD_Quit();
	  return FILE_OPEN_CANCEL;
	} else {
	  NFD_Quit();
	  GF_CORE_ERROR("Error when loading specified file format...");
	  load_file = "";
	  return FILE_OPEN_ERROR;
	}
  }

  FILE_DIALOG_RESULT fileSaveDialog() {
	return FILE_OPEN_OK;
  }

  FILE_DIALOG_RESULT fileLoadModel(string &load_file) {
	return fileOpenDialog(
		ConfigMap::getInstance()->filterInputFormat,
		load_file,
		ConfigMap::getInstance()->input_format_.size());
  }

  static void fileFilterConverter(const vector<const char *> &in_format, nfdfilteritem_t &out_format) {

  }
};

}

#endif //INC_3DBODY_3DBODY_UTIL_FILEDIALOG_H_
