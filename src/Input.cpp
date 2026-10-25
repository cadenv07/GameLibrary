#include <gamelibrary/Input.h>

namespace GameLibrary {
    Input::Input(GLFWwindow *window) : window_(window) {
        glfwSetWindowUserPointer(window_, this);
        glfwSetKeyCallback(window_, key_callback);
        glfwSetCharCallback(window_, character_callback);
        glfwSetCursorPosCallback(window_, cursor_position_callback);
        glfwSetMouseButtonCallback(window_, mouse_button_callback);
        glfwSetCursorEnterCallback(window_, cursor_enter_callback);
        glfwSetScrollCallback(window_, scroll_callback);
        setQueueCount(1);
    }

    Input::~Input() {
        glfwSetKeyCallback(window_, nullptr);
        glfwSetCharCallback(window_, nullptr);
        glfwSetCursorPosCallback(window_, nullptr);
        glfwSetMouseButtonCallback(window_, nullptr);
        glfwSetCursorEnterCallback(window_, nullptr);
        glfwSetScrollCallback(window_, nullptr);
        glfwSetWindowUserPointer(window_, nullptr);
    }

    void Input::consumeEvents() {
        dx_ = 0;
        dy_ = 0;
        for (int i = keysPressed_.size()-1; i > 0; i--) {
            keysPressed_[i] = keysPressed_[i - 1];
        }
        for (int i = keysReleased_.size()-1; i > 0; i--) {
            keysReleased_[i] = keysReleased_[i - 1];
        }
        for (int i = mouseButtonsPressed_.size()-1; i > 0; i--) {
            mouseButtonsPressed_[i] = mouseButtonsPressed_[i - 1];
        }
        for (int i = mouseButtonsReleased_.size()-1; i > 0; i--) {
            mouseButtonsReleased_[i] = mouseButtonsReleased_[i - 1];
        }
        keysPressed_[0].fill(false);
        keysReleased_[0].fill(false);
        mouseButtonsPressed_[0].fill(false);
        mouseButtonsReleased_[0].fill(false);
    }

    void Input::setQueueCount(const int count) {
        if (count <= 0) throw std::invalid_argument("Count must be positive");
        keysPressed_.resize(count);
        keysReleased_.resize(count);
        mouseButtonsPressed_.resize(count);
        mouseButtonsReleased_.resize(count);
    }

    bool Input::isKeyDown(const int32_t key) const {
        return keysDown_[key];
    }
    bool Input::isKeyPressed(const int32_t key) const {
        for (auto array : keysPressed_) {
            if (array[key]) {
                return true;
            }
        }
        return false;
    }
    bool Input::isKeyReleased(const int32_t key) const {
        for (auto array : keysReleased_) {
            if (array[key]) {
                return true;
            }
        }
        return false;
    }

    bool Input::isMouseButtonDown(const int32_t button) const {
        return mouseButtonsDown_[button];
    }
    bool Input::isMouseButtonPressed(const int32_t button) const {
        for (auto array : mouseButtonsPressed_) {
            if (array[button]) {
                return true;
            }
        }
        return false;
    }
    bool Input::isMouseButtonReleased(const int32_t button) const {
        for (auto array : mouseButtonsReleased_) {
            if (array[button]) {
                return true;
            }
        }
        return false;
    }

    double Input::mouseX() const{
        return mouseX_;
    }
    double Input::mouseY() const{
        return mouseY_;
    }
    double Input::dx() const {
        return dx_;
    }
    double Input::dy() const {
        return dy_;
    }

    double Input::wheelDeltaX() const {
        return wheelDeltaX_;
    }
    double Input::wheelDeltaY() const {
        return wheelDeltaY_;
    }

    void Input::addKeyCallback(const std::function<void(GLFWwindow *, int, int, int, int)> &callback) {
        keyCallbacks_.push_back(callback);
    }
    void Input::addCharacterCallback(const std::function<void(GLFWwindow *, unsigned int)> &callback) {
        characterCallbacks_.push_back(callback);
    }
    void Input::addCursorPositionCallback(const std::function<void(GLFWwindow *, double, double)> &callback) {
        cursorCallbacks_.push_back(callback);
    }
    void Input::addMouseButtonCallback(const std::function<void(GLFWwindow *, int, int, int)> &callback) {
        mouseButtonCallbacks_.push_back(callback);
    }
    void Input::addCursorEnterCallback(const std::function<void(GLFWwindow *, int)> &callback) {
        cursorEnterCallbacks_.push_back(callback);
    }
    void Input::addScrollCallback(const std::function<void(GLFWwindow *, double, double)> &callback) {
        scrollCallbacks_.push_back(callback);
    }

    void Input::key_callback(GLFWwindow *window, const int key, const int scancode, const int action, const int mods) {
        if (key < 0 || key >= GLFW_KEY_LAST) return;
        auto* input = static_cast<Input*>(glfwGetWindowUserPointer(window));
        if (!input) return;
        if (action == GLFW_PRESS) {
            input->keysDown_[key] = true;
            input->keysPressed_[0][key] = true;
        }
        if (action == GLFW_RELEASE) {
            input->keysDown_[key] = false;
            input->keysReleased_[0][key] = true;
        }
        for (auto callback : input->keyCallbacks_) {
            callback(window, key, scancode, action, mods);
        }
    }

    void Input::character_callback(GLFWwindow *window, const unsigned int codepoint) {
        const auto* input = static_cast<Input*>(glfwGetWindowUserPointer(window));
        if (!input) return;
        for (auto callback : input->characterCallbacks_) {
            callback(window, codepoint);
        }
    }

    void Input::cursor_position_callback(GLFWwindow *window, const double xPos, const double yPos) {
        auto* input = static_cast<Input*>(glfwGetWindowUserPointer(window));
        if (!input) return;
        input->dx_ = xPos - input->mouseX_;
        input->dy_ = yPos - input->mouseY_;
        input->mouseX_ = xPos;
        input->mouseY_ = yPos;
        for (auto callback : input->cursorCallbacks_) {
            callback(window, xPos, yPos);
        }
    }

    void Input::mouse_button_callback(GLFWwindow *window, const int button, const int action, const int mods) {
        if (button < 0 || button >= GLFW_MOUSE_BUTTON_LAST) return;
        auto* input = static_cast<Input*>(glfwGetWindowUserPointer(window));
        if (!input) return;
        if (action == GLFW_PRESS) {
            input->mouseButtonsDown_[button] = true;
            input->mouseButtonsPressed_[0][button] = true;
        }
        if (action == GLFW_RELEASE) {
            input->mouseButtonsDown_[button] = false;
            input->mouseButtonsReleased_[0][button] = true;
        }
        for (auto callback : input->mouseButtonCallbacks_) {
            callback(window, button, action, mods);
        }
    }

    void Input::cursor_enter_callback(GLFWwindow *window, const int entered) {
        const auto* input = static_cast<Input*>(glfwGetWindowUserPointer(window));
        if (!input) return;
        for (auto callback : input->cursorEnterCallbacks_) {
            callback(window, entered);
        }
    }

    void Input::scroll_callback(GLFWwindow *window, const double xOffset, const double yOffset) {
        auto* input = static_cast<Input*>(glfwGetWindowUserPointer(window));
        if (!input) return;
        input->wheelDeltaX_ = xOffset;
        input->wheelDeltaY_ = yOffset;
        for (auto callback : input->scrollCallbacks_) {
            callback(window, xOffset, yOffset);
        }
    }
}
