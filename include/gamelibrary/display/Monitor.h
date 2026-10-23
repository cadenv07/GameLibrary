/***************************************************\
* @file Monitor.h
* @brief Header file containing a class for the
* handling of monitor information.
*
* @author cadenv07
* @date 10/23/26
\***************************************************/

#pragma once

#include <gamelibrary/config/glfw/GLFWConfig.h>

#include <stdexcept>

namespace GameLibrary {
    /**
     * @class Monitor
     *
     * @brief Contains getters and setters for handling monitors given by the system.
     */
    class Monitor {
    public:
        /**
         * @brief Initializes the list of monitors and video modes.
         */
        Monitor();

        /**
         * @brief Updates the value for the current active monitor.
         *
         * @param[in] monitor The monitor to set as the active monitor.
         */
        void setMonitor(int monitor);

        /**
         * @brief Updates the gamma ramp for a specific monitor.
         *
         * @param[in] ramp The new gamma ramp to use.
         * @param[in] monitor The monitor to update the gamma ramp of.
         *
         * @throws std::invalid_argument If the inputted monitor greater than the number of monitors listed.
         *
         * @note If monitor < 0, the current monitor is used instead.
         */
        void setGammaRamp(const GLFWgammaramp& ramp, int monitor = -1) const;

        /**
         * @brief Updates the gamma value for a specific monitor
         *
         * @param[in] gamma The new gamma value to use.
         * @param[in] monitor The monitor to update the gamma value of.
         *
         * @throws std::invalid_argument If the inputted monitor greater than the number of monitors listed.
         *
         * @note If monitor < 0, the current monitor is used instead.
         */
        void setGamma(float gamma, int monitor = -1) const;

        /**
         * @brief Returns the approximate width in millimeters of the monitor.
         *
         * @param[in] monitor The monitor to retrieve data from.
         *
         * @return The approximate width in millimeters of the monitor.
         *
         * @throws std::invalid_argument If the inputted monitor greater than the number of monitors listed.
         *
         * @note If monitor < 0, the current monitor is used instead.
         */
        [[nodiscard]] int getWidth(int monitor = -1) const;

        /**
         * @brief Returns the approximate height in millimeters of the monitor.
         *
         * @param[in] monitor The monitor to retrieve data from.
         *
         * @return The approximate height in millimeters of the monitor.
         *
         * @throws std::invalid_argument If the inputted monitor greater than the number of monitors listed.
         *
         * @note If monitor < 0, the current monitor is used instead.
         */
        [[nodiscard]] int getHeight(int monitor = -1) const;

        /**
         * @brief Returns the X value of the content scale of the monitor.
         *
         * @param[in] monitor The monitor to retrieve data from.
         *
         * @return The X value of the content scale of the monitor.
         *
         * @throws std::invalid_argument If the inputted monitor greater than the number of monitors listed.
         *
         * @note If monitor < 0, the current monitor is used instead.
         */
        [[nodiscard]] float scaleX(int monitor = -1) const;

        /**
         * @brief Returns the Y value of the content scale of a monitor.
         *
         * @param[in] monitor The monitor to retrieve data from.
         *
         * @return The Y value of the content scale of the monitor.
         *
         * @throws std::invalid_argument If the inputted monitor greater than the number of monitors listed.
         *
         * @note If monitor < 0, the current monitor is used instead.
         */
        [[nodiscard]] float scaleY(int monitor = -1) const;

        /**
         * @brief Returns the X position a monitor on a virtual desktop.
         *
         * @param[in] monitor The monitor to retrieve data from.
         *
         * @return The X position of the monitor.
         *
         * @throws std::invalid_argument If the inputted monitor greater than the number of monitors listed.
         *
         * @note If monitor < 0, the current monitor is used instead.
         */
        [[nodiscard]] int getX(int monitor = -1) const;

        /**
         * @brief Returns the Y position of a monitor on a virtual desktop.
         *
         * @param[in] monitor The monitor to retrieve data from.
         *
         * @return The Y position of the monitor.
         *
         * @throws std::invalid_argument If the inputted monitor greater than the number of monitors listed.
         *
         * @note If monitor < 0, the current monitor is used instead.
         */
        [[nodiscard]] int getY(int monitor = -1) const;

        /**
         * @brief Returns the width of the work area of a monitor.
         *
         * @param[in] monitor The monitor to retrieve data from.
         *
         * @return The width of the work area of the monitor.
         *
         * @throws std::invalid_argument If the inputted monitor greater than the number of monitors listed.
         *
         * @note If monitor < 0, the current monitor is used instead.
         */
        [[nodiscard]] int workWidth(int monitor = -1) const;

        /**
         * @brief Returns the height of the work area of a monitor.
         *
         * @param[in] monitor The monitor to retrieve data from.
         *
         * @return The height of the work area of the monitor.
         *
         * @throws std::invalid_argument If the inputted monitor greater than the number of monitors listed.
         *
         * @note If monitor < 0, the current monitor is used instead.
         */
        [[nodiscard]] int workHeight(int monitor = -1) const;

        /**
         * @brief Returns the starting X position of the work area on a monitor.
         *
         * @param[in] monitor The monitor to retrieve data from.
         *
         * @return The starting X position of the work area on the monitor.
         *
         * @throws std::invalid_argument If the inputted monitor greater than the number of monitors listed.
         *
         * @note If monitor < 0, the current monitor is used instead.
         */
        [[nodiscard]] int workX(int monitor = -1) const;

        /**
         * @brief Returns the starting Y position of the work area on a monitor.
         *
         * @param[in] monitor The monitor to retrieve data from.
         *
         * @return The starting Y position of the work area on the monitor.
         *
         * @throws std::invalid_argument If the inputted monitor greater than the number of monitors listed.
         *
         * @note If monitor < 0, the current monitor is used instead.
         */
        [[nodiscard]] int workY(int monitor = -1) const;

        /**
         * @brief Returns the name of a monitor.
         *
         * @param[in] monitor The monitor to retrieve data from.
         *
         * @return The name of the monitor.
         *
         * @throws std::invalid_argument If the inputted monitor greater than the number of monitors listed.
         *
         * @note If monitor < 0, the current monitor is used instead.
         */
        [[nodiscard]] const char* getName(int monitor = -1) const;

        /**
         * @brief Returns a requested GLFW video mode.
         *
         * @param[in] mode The video mode to retrieve.
         *
         * @return The GLFW video mode.
         *
         * @throws std::invalid_argument If the inputted mode is out of bounds.
         */
        [[nodiscard]] GLFWvidmode getVideoMode(int mode) const;

        /**
         * @brief Returns the primary monitor.
         *
         * @return A GLFW pointer to the primary monitor.
         */
        [[nodiscard]] GLFWmonitor* getPrimaryMonitor() const;

        /**
         * @brief Returns the GLFW pointer of a monitor.
         *
         * @param[in] monitor The monitor to retrieve data from.
         *
         * @return The GLFW pointer of the monitor.
         *
         * @throws std::invalid_argument If the inputted monitor greater than the number of monitors listed.
         *
         * @note If monitor < 0, the current monitor is used instead.
         */
        [[nodiscard]] GLFWmonitor* getMonitor(int monitor = -1) const;
    private:
        /** @brief A list of the video modes provided. */
        const GLFWvidmode* videoModes_{};
        /** @brief A list of the monitors provided. */
        GLFWmonitor** monitors_{};
        /** @brief A pointer to the primary monitor. */
        GLFWmonitor* primaryMonitor_{};

        /** @brief An index for the current monitor in the list of monitors */
        int currentMonitor_{};
        /** @brief The number of video modes provided. */
        int numVideoModes_{};
        /** @brief The number of monitors provided */
        int numMonitors_{};
    };
}