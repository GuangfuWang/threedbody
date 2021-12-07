# this module is mainly used for package in various platform.


macro(Packing)
    if (${CMAKE_HOST_WIN32})
        message(STATUS "Generating installer for windows")
        if (CMAKE_CL_64)
            message(STATUS "Generating for 64 bit windows")
            #TODO: here implement 64bit installer

        else(CMAKE_CL_64)
            message(STATUS "Generating for 32 bit windows")
            #TODO: here implement 32bit installer.


        endif ()
    elseif(${CMAKE_HOST_APPLE})
        message(STATUS "Generating installer for MacOS")
        #TODO: checking if 32bit or 64 bit matters
        #TODO: here implement packing system.

    elseif(${CMAKE_HOST_UNIX})
        message(STATUS "Generating installer for Unix-like OS")
        #TODO: here implement unix-like os installer, typically consider ubuntu

    else()
        message(WARNING "Unknown OS, please generate installer from source.")

    endif ()
endmacro()