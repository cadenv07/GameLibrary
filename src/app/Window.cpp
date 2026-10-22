#include <gamelibrary/app/Window.h>

#include <GLFW/glfw3.h>

namespace GameLibrary {
    Window::Window(const WindowConfig &config) {
        name_ = config.name_;
        size_.x = config.size_.x;
        size_.y = config.size_.y;

        glfwWindowHint(GLFW_NO_API, config.NO_API);
    }
}
