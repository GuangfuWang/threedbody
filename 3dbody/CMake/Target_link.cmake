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

    elseif (${CMAKE_HOST_UNIX})
        target_link_libraries(${PROJECT_NAME} PUBLIC
                "/usr/lib/x86_64-linux-gnu/libboost_python-py35.so")
        target_link_libraries(${PROJECT_NAME} PUBLIC
                "/usr/lib/x86_64-linux-gnu/libstdc++.so.6")
        target_link_libraries(${PROJECT_NAME} PUBLIC
                /usr/lib/x86_64-linux-gnu/libpython3.5m.so)

        ## FIXME: here should consider different versions of linux os.
        ## FIXME: only ubuntu 16.04 is tested under this absolute linking commands.

    elseif(${CMAKE_HOST_APPLE})


    endif ()
endmacro()