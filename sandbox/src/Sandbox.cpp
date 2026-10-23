#include <Sandbox.h>

#include <../../include/gamelibrary/display/Window.h>
#include <iostream>

Sandbox::Sandbox(const GameLibrary::GameConfig &config) : Game(config) {
    while (!window_.shouldClose()) {
        glfwPollEvents();
    }
}

int main() {
    Sandbox sandbox{};
    return 0;
}