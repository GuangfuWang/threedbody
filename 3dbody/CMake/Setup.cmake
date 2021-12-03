# Author: Guangfu Wang.
# Date: 2021-11-19.
# LICENSE: BSD.

macro(setups)
    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_EXTENSIONS OFF)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)

    #    set(CMAKE_AUTOMOC ON)
    #    set(CMAKE_AUTOUIC ON)
    #    set(CMAKE_AUTORCC ON)

    if (NOT ${CMAKE_BUILD_TYPE})
        message(STATUS "Build Type Not set, by default it will be debug")
        set(CMAKE_BUILD_TYPE "Debug")
    endif ()

    if (${CMAKE_BUILD_TYPE} STREQUAL "Release")
        message(STATUS "Build type: Release")
        set(CMAKE_CXX_FLAGS "-O3 -funroll-loops -msse2 -mavx -march=native
            -Wno-deprecated-declarations -fPIC -static-libgcc -static-libstdc++")
        set(CMAKE_C_FLAGS "-O3 -funroll-loops -msse2 -mavx -march=native
            -Wno-deprecated-declarations -fPIC -static-libgcc -static-libstdc++")
        set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
        set(CMAKE_BUILD_TYPE Release CACHE STRING
                "Setting built type to ${CMAKE_BUILD_TYPE}")
    elseif (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
        message(STATUS "Build type: Debug")
    else ()
        #
    endif ()

    message(STATUS "OS: ${CMAKE_HOST_SYSTEM}")

    if (WIN32)
        add_definitions("-DGF_WIN")
    elseif (Unix)
        add_definitions("-DGF_LINUX")
    elseif (${CMAKE_HOST_APPLE})
        add_definitions("-DGF_MAC")
    endif ()

endmacro()