/***************************************************\
* @file WindowConfig.h
* @brief Header file for the WindowConfig struct,
* for the creation of windows in the game.
*
* @author cadenv07
* @date 10/22/26
\***************************************************/

#pragma once

#include <string>
#include <glm/glm.hpp>
#include <gamelibrary/config/glfw/GLFWConfig.h>

namespace GameLibrary {
    /**
     * @struct WindowConfig
     *
     * @brief Contains config information for the creation of a window.
     */
    struct WindowConfig {
        /** @brief The name to assign to the window title. */
        std::string name_ = "Game Library Window";
        /** @brief The dimensions of the window to create. */
        glm::ivec2 size_ = glm::ivec2(800, 600);

        /** @brief Whether to make the window fullscreen. */
        bool fullscreen_ = false;

        /** @brief Config for creating the GLFW window */
        GLFWWindowConfig glfwWindow = {};
    };
}