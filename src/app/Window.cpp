#include <gamelibrary/app/Window.h>

#include <stdexcept>

namespace GameLibrary {
    Window::Window(const WindowConfig &config) {
        if (!glfwInit()) {
            throw std::runtime_error(
                "Failed to initialize GLFW"
            );
        }

        name_ = config.name_;
        size_.x = config.size_.x;
        size_.y = config.size_.y;

        //Initialize window hints
        initializeHints(config);

        window_ = glfwCreateWindow(size_.x, size_.y, name_.c_str(), nullptr, nullptr);
    }
}
