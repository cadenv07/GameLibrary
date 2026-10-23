#include <gamelibrary/glfw/GLFWInstance.h>

namespace GameLibrary {
    GLFWInstance::GLFWInstance(const GLFWInstanceConfig &config) {
        glfwInitHints(config);
        if (!glfwInit()) {
            throw std::runtime_error("Failed to initialize GLFW");
        }
    }

    GLFWInstance::~GLFWInstance() {
        glfwTerminate();
    }
}
