set(PUBLIC_HEADER_FILES
        ${CMAKE_CURRENT_LIST_DIR}/include/nfd.h
        ${CMAKE_CURRENT_LIST_DIR}/include/nfd.hpp)

set(FileDialog_SRC ${PUBLIC_HEADER_FILES})

if(${CMAKE_HOST_WIN32})
    list(APPEND FileDialog_SRC ${CMAKE_CURRENT_LIST_DIR}/nfd_win.cpp)
endif()

if(${CMAKE_HOST_UNIX})
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
    message("Using GTK version: ${GTK3_VERSION}")
    list(APPEND FileDialog_SRC nfd_gtk.cpp)
endif()

if(${CMAKE_HOST_APPLE})
    find_library(APPKIT_LIBRARY AppKit)
    list(APPEND FileDialog_SRC nfd_cocoa.m)
endif()



