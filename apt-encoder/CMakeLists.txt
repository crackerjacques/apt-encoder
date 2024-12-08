add_executable(apt_encoder
    main.c
    audioset.c
    wavwrite.c
)

target_include_directories(apt_encoder 
    PRIVATE 
        ${CMAKE_SOURCE_DIR}/image
        ${CMAKE_SOURCE_DIR}/aptcode
)

find_package(Threads REQUIRED)
find_package(ALSA REQUIRED)

target_link_libraries(apt_encoder 
    PRIVATE
        image
        aptcode
        Threads::Threads
        ALSA::ALSA
        m
        readline
        termcap
)

# Install
install(TARGETS apt_encoder
    RUNTIME DESTINATION bin
)
