add_executable(test.exe
    test.c
)

add_subdirectory(json-utils)

target_link_libraries(test.exe
    PRIVATE 
    json-utils
)