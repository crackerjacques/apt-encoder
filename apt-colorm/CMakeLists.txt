add_executable(apt-colorm
    apt-colorm.c
)

target_include_directories(apt-colorm 
    PRIVATE 
        ${CMAKE_SOURCE_DIR}/image
        ${CMAKE_SOURCE_DIR}/aptcode
)

target_link_libraries(apt-colorm
    PRIVATE
        image
        aptcode
)
