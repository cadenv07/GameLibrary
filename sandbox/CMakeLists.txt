add_executable(Sandbox main.cpp)

target_link_libraries(Sandbox PRIVATE GameLibrary::GameLibrary)

target_include_directories(Sandbox PRIVATE
        CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/sandbox/include"
)