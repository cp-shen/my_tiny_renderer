# cmake file for tests/

file(GLOB_RECURSIVE sourcefiles
    ${CURRENT_SOURCE_DIR}/*.cpp
    )

add_executable(MyTinyRenderer_Tests
    ${sourcefiles}
    )

target_link_libraries(MyTinyRenderer_Tests
    PRIVATE MyTinyRenderer
    )
