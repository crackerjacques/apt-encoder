add_library(aptcode
    aptcode.c
)

target_include_directories(aptcode 
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/image
)