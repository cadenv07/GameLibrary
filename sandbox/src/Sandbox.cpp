#include <Sandbox.h>

#include <gamelibrary/app/Window.h>
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