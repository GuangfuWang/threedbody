# Author: Guangfu Wang.
# Date: 2021-11-19.
# LICENSE: BSD.


macro(exe_target_define SRC)
    add_executable(${PROJECT_NAME} ${ARGV})
endmacro()

# FOR SHARED LIB YOU NEED TO SPECIFY NAME OF LIB
macro(shared_lib_target_define SRC)
    set(pure_src "")
    foreach (item ${ARGV})
        if (${item} EQUAL ${ARGV0})
            continue()
        endif ()
        list(APPEND pure_src ${item})
    endforeach ()
    add_library(${ARGV0} SHARED ${pure_src})
endmacro()