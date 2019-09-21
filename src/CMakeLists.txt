# cmake file for src/

file(GLOB_RECURSE sourcefiles
    ${CURRENT_SOURCE_DIR}/*.cpp
    )

add_library(MyTinyRenderer SHARED
    ${sourcefiles}
    )

target_include_directories(MyTinyRenderer
    PUBLIC ${MyTinyRenderer_SOURCE_DIR}/include
    )

target_link_libraries(MyTinyRenderer
    PUBLIC png)
