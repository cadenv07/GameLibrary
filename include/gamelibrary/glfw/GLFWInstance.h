/***************************************************\
* @file GLFWInstance.h
* @brief Header file containing a class for the
* creation and destruction of a GLFW instance.
*
* @author cadenv07
* @date 10/23/26
\***************************************************/

#pragma once

#include <gamelibrary/config/glfw/GLFWConfig.h>

#include <stdexcept>

namespace GameLibrary {
    /**
     * @class GLFWInstance
     *
     * @brief Handles the creation and destruction of the GLFW context.
     */
    class GLFWInstance {
    public:
        /**
         * @brief Constructs a new GLFW context.
         *
         * @param[in] config Configuration object for how to construct the GLFW context.
         *
         * @throws std::runtime_error If glfwInit() fails to initialize GLFW.
         */
        explicit GLFWInstance(const GLFWInstanceConfig& config = {});

        /**
         * @brief Destroys the active GLFW context.
         */
        ~GLFWInstance();
    };
}