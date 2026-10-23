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
         */
        explicit Window(const WindowConfig& config = {});

        /**
         * @brief Returns the current active GLFWwindow pointer.
         *
         * @return The pointer of the currently active window.
         */
        [[nodiscard]] GLFWwindow* window() const;
    private:
        /** @brief Pointer to the current GLFWwindow object. */
        GLFWwindow* window_ = nullptr;

        /** @brief The stored name of the window. */
        std::string name_{};
        /** @brief The stored size of the window. */
        glm::ivec2 size_{};
    };
}