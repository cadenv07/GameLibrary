#include <gamelibrary/app/Window.h>

#include <stdexcept>

namespace GameLibrary {
    Window::Window(const WindowConfig &config) {
        glfwInitHints(config);

        if (!glfwInit()) {
            throw std::runtime_error(
                "Failed to initialize GLFW"
            );
        }

        name_ = config.name_;
        size_.x = config.size_.x;
        size_.y = config.size_.y;

        //Initialize window hints
        glfwWindowHints(config);

        window_ = glfwCreateWindow(size_.x, size_.y, name_.c_str(), nullptr, nullptr);

        glfwMakeContextCurrent(window_);
    }

    GLFWwindow* Window::window() const {
        return window_;
    }
}
