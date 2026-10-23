/***************************************************\
* @file GameConfig.h
* @brief Header file for the game config struct,
* stores information on how to construct various
* parts of the game.
*
* @author cadenv07
* @date 10/22/26
\***************************************************/

#pragma once

#include <gamelibrary/config/app/WindowConfig.h>

namespace GameLibrary {
    /**
     * @struct GameConfig
     *
     * @brief Stores information on how to construct
     * various parts of the game engine.
     */
    struct GameConfig {
        /** @brief Config for how to construct game windows. */
        WindowConfig windowConfig{};
    };
}