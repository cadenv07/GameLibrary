#include <Sandbox.h>

#include <gamelibrary/app/Window.h>

Sandbox::Sandbox(const GameLibrary::GameConfig &config) : Game(config) {
    while (!glfwWindowShouldClose(window_.window())) {
        glfwPollEvents();
    }
}

int main() {
    Sandbox sandbox{};
    return 0;
}