/***************************************************\
* @file Input.h
* @brief Header file for handling input given to the
* main window.
*
* @author cadenv07
* @date 10/25/26
\***************************************************/

#pragma once

#include <GLFW/glfw3.h>
#include <array>
#include <vector>
#include <functional>
#include <stdexcept>

namespace GameLibrary {
    /**
     * @class Input
     *
     * @brief Class for handling user input given to an inputted window.
     *
     * @details Contains methods for automatically
     * detecting input callbacks, static vectors for
     * storing user defined callback functions, and
     * resizable input queues for inputs surviving a few
     * frames after the initial callback.
     */
    class Input {
    public:
        /**
         * @brief Creates a new input reader for an inputted window.
         *
         * @param[in] window The pointer to the GLFW window to read input from.
         */
        explicit Input(GLFWwindow* window);

        /**
         * @brief Handles destroying the modified window input callbacks and user variable.
         */
        ~Input();

        /**
         * @brief Resets the values of all input functions to prepare for the next input frame.
         */
        void consumeEvents();

        /**
         * @brief Sets the number of frames that input should be preserved for before being deleted.
         *
         * @param[in] count The number of frames input should preserve for.
         *
         * @throws std::invalid_argument If the inputted count is less than or equal to zero.
         */
        void setQueueCount(int count);

        /**
         * @brief Returns if a key is currently down.
         *
         * @param[in] key The keycode to test.
         *
         * @return True if the key is down, false otherwise.
         */
        [[nodiscard]] bool isKeyDown(int32_t key) const;

        /**
         * @brief Tests all input queues to see if a key has been pressed within the queued frames.
         *
         * @param[in] key The keycode to test.
         *
         * @return True if the key has been pressed, false otherwise.
         */
        [[nodiscard]] bool isKeyPressed(int32_t key) const;

        /**
         * @brief Tests all input queues to see if a key has been released within the queued frames.
         *
         * @param[in] key The keycode to test.
         *
         * @return True if the key has been released, false otherwise.
         */
        [[nodiscard]] bool isKeyReleased(int32_t key) const;

        /**
         * @brief Returns if a mouse button is currently down.
         *
         * @param[in] button The mouse button code to test.
         *
         * @return True if the mouse button is down, false otherwise.
         */
        [[nodiscard]] bool isMouseButtonDown(int32_t button) const;

        /**
         * @brief Tests all input queues to see if a mouse button has been pressed within the queued frames.
         *
         * @param[in] button The mouse button code to test.
         *
         * @return True if the mouse button has been pressed, false otherwise.
         */
        [[nodiscard]] bool isMouseButtonPressed(int32_t button) const;

        /**
         * @brief Tests all input queues to see if a mouse button has been released within the queued frames.
         *
         * @param[in] button The mouse button code to test.
         *
         * @return True if the mouse button has been released, false otherwise.
         */
        [[nodiscard]] bool isMouseButtonReleased(int32_t button) const;

        /**
         * @brief Returns the current mouse X position.
         *
         * @return The current mouse X position.
         */
        [[nodiscard]] double mouseX() const;

        /**
         * @brief Returns the current mouse Y position.
         *
         * @return The current mouse Y position.
         */
        [[nodiscard]] double mouseY() const;

        /**
         * @brief Returns the difference between the mouse position in the last frame and the current frame.
         *
         * @return The difference in position between frames on the X axis.
         */
        [[nodiscard]] double dx() const;

        /**
         * @brief Returns the difference between the mouse position in the last frame and the current frame.
         *
         * @return The difference in position between frames on the Y axis.
         */
        [[nodiscard]] double dy() const;

        /**
         * @brief Returns the amount the mouse wheel was scrolled last frame.
         *
         * @return The amount of mouse wheel scroll on the X axis.
         */
        [[nodiscard]] double wheelDeltaX() const;

        /**
         * @brief Returns the amount the mouse wheel was scrolled last frame.
         *
         * @return The amount of mouse wheel scroll on the Y axis.
         */
        [[nodiscard]] double wheelDeltaY() const;

        /**
         * @brief Adds a new key callback to be called everytime key input has been received by the window.
         *
         * @param[in] callback The function to add to the callbacks list.
         */
        void addKeyCallback(const std::function<void(GLFWwindow*, int, int, int, int)>& callback);

        /**
         * @brief Adds a new character callback to be called everytime character input has been received by the window.
         *
         * @param[in] callback The function to add to the callbacks list.
         */
        void addCharacterCallback(const std::function<void(GLFWwindow*, unsigned int)>& callback);

        /**
         * @brief Adds a new cursor position callback to be called everytime cursor position input has been received by the window.
         *
         * @param[in] callback The function to add to the callbacks list.
         */
        void addCursorPositionCallback(const std::function<void(GLFWwindow*, double, double)>& callback);

        /**
         * @brief Adds a new mouse button callback to be called everytime mouse button input has been received by the window.
         *
         * @param[in] callback The function to add to the callbacks list.
         */
        void addMouseButtonCallback(const std::function<void(GLFWwindow*, int, int, int)>& callback);

        /**
         * @brief Adds a new mouse entered callback to be called everytime mouse entered input has been received by the window.
         *
         * @param[in] callback The function to add to the callbacks list.
         */
        void addCursorEnterCallback(const std::function<void(GLFWwindow*, int)>& callback);

        /**
         * @brief Adds a new scroll wheel callback to be called everytime scroll wheel input has been received by the window.
         *
         * @param[in] callback The function to add to the callbacks list.
         */
        void addScrollCallback(const std::function<void(GLFWwindow*, double, double)>& callback);
    private:
        /** @brief The window object to link this input handler to */
        GLFWwindow* window_;

        /** @brief List of key callbacks to call everytime key input has been received by the window. */
        std::vector<std::function<void(GLFWwindow*, int, int, int, int)>> keyCallbacks_;
        /** @brief List of character callbacks to call everytime character input has been received by the window. */
        std::vector<std::function<void(GLFWwindow*, unsigned int)>> characterCallbacks_;
        /** @brief List of cursor position callbacks to call everytime cursor position input has been received by the window. */
        std::vector<std::function<void(GLFWwindow*, double, double)>> cursorCallbacks_;
        /** @brief List of mouse button callbacks to call everytime mouse button input has been received by the window. */
        std::vector<std::function<void(GLFWwindow*, int, int, int)>> mouseButtonCallbacks_;
        /** @brief List of cursor enter callbacks to call everytime cursor enter input has been received by the window. */
        std::vector<std::function<void(GLFWwindow*, int)>> cursorEnterCallbacks_;
        /** @brief List of scroll wheel callbacks to call everytime scroll wheel input has been received by the window. */
        std::vector<std::function<void(GLFWwindow*, double, double)>> scrollCallbacks_;

        /**
         * @brief Callback function for handling key inputs received by the window.
         *
         * @param[in] window The window that received the input.
         * @param[in] key The key that was inputted.
         * @param[in] scancode Platform specific unique code for the key.
         * @param[in] action Denotes how the key was inputted.
         * @param[in] mods Any active keyboard modifications during the input.
         */
        static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

        /**
         * @brief Callback function for handling character inputs received by the window.
         *
         * @param[in] window The window that received the input.
         * @param[in] codepoint The character that was inputted.
         */
        static void character_callback(GLFWwindow* window, unsigned int codepoint);

        /**
         * @brief Callback function for handling cursor position inputs received by the window.
         *
         * @param[in] window The window that received the input.
         * @param[in] xPos The X position of the mouse on the screen.
         * @param[in] yPos The Y position of the mouse on the screen.
         */
        static void cursor_position_callback(GLFWwindow* window, double xPos, double yPos);

        /**
         * @brief Callback function for handling mouse button inputs received by the window.
         *
         * @param[in] window The window that received the input.
         * @param[in] button The code for the mouse button inputted.
         * @param[in] action Denotes how the mouse button was inputted.
         * @param[in] mods Any mouse modifications active during the time of input.
         */
        static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

        /**
         * @brief Callback function for handling cursor enter inputs received by the window.
         *
         * @param[in] window The window that received the input.
         * @param[in] entered Records whether the mouse cursor entered or left.
         */
        static void cursor_enter_callback(GLFWwindow* window, int entered);

        /**
         * @brief Callback function for handling scroll wheel inputs received by the window.
         *
         * @param[in] window The window that received the input.
         * @param[in] xOffset The amount the wheel was scrolled the last frame on the X axis.
         * @param[in] yOffset The amount the wheel was scrolled the last frame on the Y axis.
         */
        static void scroll_callback(GLFWwindow* window, double xOffset, double yOffset);

        float mouseX_{0.0f};
        float mouseY_{0.0f};
        float dx_{0.0f};
        float dy_{0.0f};
        float wheelDeltaX_{0.0f};
        float wheelDeltaY_{0.0f};

        std::array<bool, GLFW_KEY_LAST + 1> keysDown_{false};
        std::vector<std::array<bool, GLFW_KEY_LAST + 1>> keysPressed_{false};
        std::vector<std::array<bool, GLFW_KEY_LAST + 1>> keysReleased_{false};
        std::array<bool, GLFW_MOUSE_BUTTON_LAST + 1> mouseButtonsDown_{false};
        std::vector<std::array<bool, GLFW_MOUSE_BUTTON_LAST + 1>> mouseButtonsPressed_{false};
        std::vector<std::array<bool, GLFW_MOUSE_BUTTON_LAST + 1>> mouseButtonsReleased_{false};
    };
}