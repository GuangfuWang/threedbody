cmake_minimum_required(VERSION 3.16)
project(3DBODY)

# basic setups for this project.
include(${PROJECT_SOURCE_DIR}/3dbody/CMake/Setup.cmake)
setups()

# basic options when compiling.
include(${PROJECT_SOURCE_DIR}/3dbody/CMake/Options.cmake)
opts()

# some dependencies setup
set(MINGW_INCLUDE_DIR "")
include(${PROJECT_SOURCE_DIR}/3dbody/CMake/Judge_mingw_patch.cmake)
mingw_patch(MINGW_INCLUDE_DIR)

include(${PROJECT_SOURCE_DIR}/3dbody/CMake/GrabAllSrcFiles.cmake)
include(${PROJECT_SOURCE_DIR}/thirdparty/imgui/IMGUI.cmake)
include(${PROJECT_SOURCE_DIR}/thirdparty/GLEW/glew.cmake)
include(${PROJECT_SOURCE_DIR}/thirdparty/stb_image/stb_image.cmake)
include(${PROJECT_SOURCE_DIR}/thirdparty/spdlog/spdlog.cmake)


include(${PROJECT_SOURCE_DIR}/3dbody/util/util.cmake)


include(${PROJECT_SOURCE_DIR}/3dbody/CMake/Target_define.cmake)
exe_target_define(${OWN_SRC} ${ImGui_src} ${glew_src} ${stb_image_src} ${util_src} ${spdlog_src})

include(${PROJECT_SOURCE_DIR}/3dbody/CMake/Target_include.cmake)
target_deps_include(${MINGW_INCLUDE_DIR})

include(${PROJECT_SOURCE_DIR}/3dbody/CMake/Target_link.cmake)
target_deps_link()

include(${PROJECT_SOURCE_DIR}/3dbody/CMake/Packing.cmake)
Packing()