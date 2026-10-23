/***************************************************\
* @file Game.h
* @brief The basic entry point for any game.
*
* @author cadenv07
* @date 10/22/26
\***************************************************/

#pragma once

#include <gamelibrary/config/GameConfig.h>

#include "display/Window.h"
#include "glfw/GLFWInstance.h"

namespace GameLibrary {
    /**
     * @class Game
     *
     * @brief The main class of the game engine, contains abstract methods for
     * the running of a game.
     *
    * @details Applications using this engine should have their main class extend this one.
     */
    class Game {
    public:
        /**
         * @brief Constructs a new game instance.
         *
         * @param[in] config A config object detailing how to construct the game instance.
         */
        explicit Game(const GameConfig& config = {});
    protected:
        /** @brief The main application window. */
        GLFWInstance glfw_;
        Window window_;
    };
}
