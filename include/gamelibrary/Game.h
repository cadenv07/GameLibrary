/***************************************************\
* @file Game.h
* @brief The basic entry point for any game.
*
* @author cadenv07
* @date 10/22/26
\***************************************************/

#pragma once

#include <gamelibrary/config/GameConfig.h>

#include "app/Window.h"

namespace GameLibrary {
    class Game {
    public:
        explicit Game(const GameConfig& config = {});
    protected:
        Window window_;
    };
}
