#include <Sandbox.h>

#include <gamelibrary/display/Window.h>
#include <iostream>

Sandbox::Sandbox(const GameLibrary::GameConfig &config) : Game(config) {
    renderFunctions_.emplace_back([&](double dt) {
        glClearColor(1.0f, 0.0f, 1.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    });
}

int main() {
    const GameLibrary::WindowConfig config = {
        .fullscreen_ = false,
        .glfwWindow = {
            .glfwClientApi = GLFW_OPENGL_API,
            .glfwContextVersionMajor = 3,
            .glfwContextVersionMinor = 3,
            .glfwOpenGLProfile = GLFW_OPENGL_CORE_PROFILE
        }
    };
    Sandbox sandbox({.windowConfig = config});
    sandbox.run();
    return 0;
}