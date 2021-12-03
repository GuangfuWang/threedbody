# Author: Guangfu Wang.
# Date: 2021-11-19.
# LICENSE: BSD.


macro(target_deps_include MINGW_INCLUDE_DIR)

    if (${CMAKE_HOST_WIN32})
        if (MINGW_INCLUDE_DIR)
            # include boost/glm/GLFW
            target_include_directories(${PROJECT_NAME}
                    PUBLIC ${MINGW_INCLUDE_DIR})
            #            target_link_libraries(${PROJECT_NAME}
            #                    libglfw3.a)

        else ()
            target_include_directories(${PROJECT_NAME}
                    PUBLIC ${PROJECT_SOURCE_DIR}/thirdparty)
        endif ()
    elseif (${CMAKE_HOST_UNIX})

    endif ()

    target_include_directories(${PROJECT_NAME}
            PUBLIC
            ${PROJECT_SOURCE_DIR}/thirdparty/Assimp)

    target_include_directories(${PROJECT_NAME}
            PUBLIC
            ${PROJECT_SOURCE_DIR}/thirdparty/imgui)

    target_include_directories(${PROJECT_NAME}
            PUBLIC
            ${PROJECT_SOURCE_DIR}/thirdparty/stb_image)
    target_include_directories(${PROJECT_NAME}
            PUBLIC
            ${PROJECT_SOURCE_DIR}/thirdparty/GLEW)


endmacro()