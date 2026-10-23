#include <gamelibrary/Game.h>

namespace GameLibrary {
    Game::Game(const GameConfig &config) : glfw_(config.instanceConfig), window_(config.windowConfig) {}
}
