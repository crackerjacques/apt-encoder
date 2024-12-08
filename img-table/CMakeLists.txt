add_executable(img-table
    img.c
)

target_include_directories(img-table
    PRIVATE 
        ${CMAKE_SOURCE_DIR}/image
        ${CMAKE_SOURCE_DIR}/aptcode
)

target_link_libraries(img-table
    PRIVATE
        image
        aptcode
        m
)
