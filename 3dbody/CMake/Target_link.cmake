# Author: Guangfu Wang.
# Date: 2021-11-19.
# LICENSE: BSD.


macro(target_deps_link)
    target_link_libraries(${PROJECT_NAME} PUBLIC libglfw3.a)

    target_link_libraries(${PROJECT_NAME}
            PUBLIC
            ${PROJECT_SOURCE_DIR}/thirdparty/Assimp/libassimp.a)

    if (${CMAKE_HOST_WIN32})
        target_link_libraries(${PROJECT_NAME} PUBLIC -lopengl32)
    endif ()
endmacro()