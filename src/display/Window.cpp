#include <gamelibrary/display/Window.h>

namespace GameLibrary {
    Window::Window(const Monitor* monitor, const WindowConfig& config) : monitor_(monitor){
        name_ = config.name_;
        size_.x = config.size_.x;
        size_.y = config.size_.y;

        //Initialize window hints
        glfwWindowHints(config.glfwWindow);

        GLFWmonitor* windowMonitor = nullptr;
        if (config.fullscreen_) windowMonitor = monitor->getPrimaryMonitor();
        window_ = glfwCreateWindow(size_.x, size_.y, name_.c_str(), windowMonitor, nullptr);

        glfwMakeContextCurrent(window_);
        glfwSwapInterval(1);
    }

    Window::~Window() {
        glfwDestroyWindow(window_);
    }

    void Window::requestClose() const {
        glfwSetWindowShouldClose(window_, GLFW_TRUE);
    }

    void Window::setWidth(const int width) {
        size_.x = width;
        glfwSetWindowSize(window_, size_.x, size_.y);
    }

    void Window::setHeight(const int height) {
        size_.y = height;
        glfwSetWindowSize(window_, size_.x, size_.y);
    }

    void Window::setSize(const int width, const int height) {
        setWidth(width);
        setHeight(height);
    }

    void Window::setX(const int x) {
        position_.x = x;
        glfwSetWindowPos(window_, position_.x, position_.y);
    }

    void Window::setY(const int y) {
        position_.y = y;
        glfwSetWindowPos(window_, position_.x, position_.y);
    }

    void Window::setPosition(const int x, const int y) {
        setX(x);
        setY(y);
    }

    GLFWwindow* Window::window() const {
        return window_;
    }

    int Window::width() const {
        int width = 0;
        glfwGetWindowSize(window_, &width, nullptr);
        return width;
    }

    int Window::height() const {
        int height = 0;
        glfwGetWindowSize(window_, nullptr, &height);
        return height;
    }

    int Window::x() const {
        int x = 0;
        glfwGetWindowPos(window_, &x, nullptr);
        return x;
    }

    int Window::y() const {
        int y = 0;
        glfwGetWindowPos(window_, nullptr, &y);
        return y;
    }

    bool Window::shouldClose() const {
        return glfwWindowShouldClose(window_);
    }

    int Window::getPlatform() {
        return glfwGetPlatform();
    }

    bool Window::platformSupported(const GLint glfwPlatform) {
        return glfwPlatformSupported(glfwPlatform);
    }
}
