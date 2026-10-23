cmake_minimum_required(VERSION 4.1)
project(GameLibrary)

set(CMAKE_CXX_STANDARD 20)

find_package(glfw3 CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glm REQUIRED)

file(GLOB_RECURSE SOURCES
    CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

add_library(GameLibrary STATIC ${SOURCES})
target_link_libraries(GameLibrary PUBLIC glfw glm::glm OpenGL)
add_library(GameLibrary::GameLibrary ALIAS GameLibrary)

target_include_directories(GameLibrary PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

add_subdirectory(sandbox)