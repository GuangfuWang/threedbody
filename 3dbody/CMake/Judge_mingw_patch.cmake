# Author: Guangfu Wang.
# Date: 2021-11-19.
# LICENSE: BSD.

macro(judge_mingw)

    set(MINGW_INCLUDE_DIR_TEMP ${CMAKE_CXX_COMPILER})

    # find compiler path and set its include path.
    string(REPLACE "/bin/g++.exe" "" MINGW_INCLUDE_DIR_TEMP ${MINGW_INCLUDE_DIR_TEMP})
    string(APPEND MINGW_INCLUDE_DIR_TEMP "/include")
    set(MINGW_TEMP_STR ${MINGW_INCLUDE_DIR_TEMP})
    string(APPEND MINGW_TEMP_STR "/boost")

    # Using boost lib to judge if your mingw is from given patch.
    if (NOT EXISTS ${MINGW_TEMP_STR})
        message(WARNING "You are Not using given mingw patch.")
        message(WARNING "Some dependencies may be missing.")
        set(MINGW_INCLUDE_DIR "")
        return()
    endif ()

    # Given patch, then set parent variable.
    message(STATUS "You are using given mingw patch.")
    set(${MINGW_INCLUDE_DIR} ${MINGW_INCLUDE_DIR_TEMP})
endmacro()

function(mingw_patch MINGW_INCLUDE_DIR)
    if (${CMAKE_HOST_WIN32})
        include(${PROJECT_SOURCE_DIR}/3dbody/CMake/Judge_mingw_patch.cmake)
        judge_mingw(MINGW_INCLUDE_DIR)
        message(STATUS "Additional Path: ${MINGW_INCLUDE_DIR}")
        set(MINGW_INCLUDE_DIR ${MINGW_INCLUDE_DIR} PARENT_SCOPE)
    elseif (${CMAKE_HOST_UNIX})
        message(STATUS "OS: ${CMAKE_HOST_SYSTEM}")
    endif ()
endfunction()