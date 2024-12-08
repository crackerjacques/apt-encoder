add_library(image
    image.c
)

target_include_directories(image 
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/aptcode
)