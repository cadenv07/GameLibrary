#include <gamelibrary/Game.h>

namespace GameLibrary {
    Game::Game(const GameConfig &config) {
        glfw_ = std::make_unique<GLFWInstance>(config.instanceConfig);
        monitor_ = std::make_unique<Monitor>();
        window_ = std::make_unique<Window>(monitor_.get(), config.windowConfig);
    }

    void Game::run() {
        while (!window_->shouldClose()) {
            glfwPollEvents();
            for (const auto& update : updateFunctions_) {
                update(0.0);
            }
            for (const auto& render : renderFunctions_) {
                render(0.0);
            }
            for (const auto& input : inputFunctions_) {
                input();
            }
            glfwSwapBuffers(window_->window());
        }
    }
}
