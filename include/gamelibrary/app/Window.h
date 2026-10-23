/***************************************************\
* @file Window.h
* @brief Basic header file for storing information
* related to creating windows for the game.
*
* @author cadenv07
* @date 10/22/26
\***************************************************/

#pragma once

#include <gamelibrary/config/app/WindowConfig.h>
#include <stdexcept>

namespace GameLibrary {
    /**
     * @class Window
     *
     * @brief Stores basic information for adding a window to the game.
     */
    class Window {
    public:
        /**
         * @brief Constructs a new GLFW window.
         *
         * @param[in] config Configuration of the window to create.
         *
         * @throws std::runtime_error If glfwInit() fails to initialize a GLFW context.
         */
        explicit Window(const WindowConfig& config = {});

        /**
         * @brief Destroys the active window and terminates the GLFW context.
         */
        ~Window();

        /**
         * @brief Marks the current window for closing.
         */
        void requestClose() const;

        void setWidth(int width);
        void setHeight(int height);
        void setSize(int width, int height);
        void setX(int x);
        void setY(int y);
        void setPosition(int x, int y);

        /**
         * @brief Returns the current active GLFWwindow pointer.
         *
         * @return The pointer of the currently active window.
         */
        [[nodiscard]] GLFWwindow* window() const;

        /**
         * @brief Returns the current width of the window.
         *
         * @return The width of the window.
         */
        [[nodiscard]] int width() const;

        /**
         * @brief Returns the current height of the window.
         *
         * @return The current height of the window.
         */
        [[nodiscard]] int height() const;

        /**
         * @brief Returns the current X-position of the window.
         *
         * @return The current X-position of the window.
         */
        [[nodiscard]] int x() const;

        /**
         * @brief Returns the current Y-position of the window.
         *
         * @return The current Y-position of the window.
         */
        [[nodiscard]] int y() const;

        /**
         * @brief Returns if the current window has been requested to close.
         *
         * @return True if the window has been requested to close, false otherwise.
         */
        [[nodiscard]] bool shouldClose() const;

        /**
         * @brief Returns the platform the current GLFW context has been constructed with.
         *
         * @return The current context's platform.
         */
        [[nodiscard]] static int getPlatform();

        /**
         * @brief Tests if the current environment supports a specific platform.
         *
         * @param[in] glfwPlatform The platform to test for support.
         *
         * @return True if the platform is supported, false otherwise.
         */
        [[nodiscard]] static bool platformSupported(GLint glfwPlatform);
    private:
        /** @brief Pointer to the current GLFWwindow object. */
        GLFWwindow* window_ = nullptr;

        /** @brief The stored name of the window. */
        std::string name_{};
        /** @brief The stored size of the window. */
        glm::ivec2 size_{};
        /** @brief The stored position of the window. */
        glm::ivec2 position_{};
    };
}