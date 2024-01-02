add_library(json-utils "")

target_sources(json-utils
    PRIVATE ${CMAKE_CURRENT_LIST_DIR}/json.c
    PUBLIC ${CMAKE_CURRENT_LIST_DIR}/json.h
)

target_include_directories(json-utils
    PUBLIC ${CMAKE_CURRENT_LIST_DIR}
)