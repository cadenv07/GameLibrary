file(GLOB_RECURSE SOURCES
    CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

add_executable(Sandbox ${SOURCES})

target_link_libraries(Sandbox PRIVATE GameLibrary::GameLibrary)

target_include_directories(Sandbox PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)