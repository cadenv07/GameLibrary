/***************************************************\
* @file Window.h
* @brief [fill out description]
*
* [fill out description]
*
* @author cadenv07
* @date 10/22/26
\***************************************************/

#pragma once

#include <gamelibrary/config/app/WindowConfig.h>

namespace GameLibrary {
    struct GLFWwindow;

    /**
     * @class Window
     *
     * @brief Stores basic information for adding a window to the game.
     */
    class Window {
    public:
        explicit Window(const WindowConfig& config = {});
    private:
        GLFWwindow* window_ = nullptr;

        std::string name_{};
        glm::ivec2 size_{};
    };
}