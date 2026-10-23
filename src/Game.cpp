#include <gamelibrary/Game.h>

namespace GameLibrary {
    Game::Game(const GameConfig &config) {
        glfw_ = std::make_unique<GLFWInstance>(config.instanceConfig);
        monitor_ = std::make_unique<Monitor>();
        window_ = std::make_unique<Window>(monitor_.get(), config.windowConfig);
    }
}
