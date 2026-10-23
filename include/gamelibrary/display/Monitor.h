/***************************************************\
* @file Monitor.h
* @brief [fill out description]
*
* [fill out description]
*
* @author cadenv07
* @date 10/23/26
\***************************************************/

#pragma once

#include <gamelibrary/config/glfw/GLFWConfig.h>

#include <stdexcept>

namespace GameLibrary {
    class Monitor {
    public:
        Monitor();

        void setMonitor(int monitor);
        void setGammaRamp(const GLFWgammaramp& ramp, int monitor = -1) const;
        void setGamma(float gamma, int monitor = -1) const;

        [[nodiscard]] int getWidth(int monitor = -1) const;
        [[nodiscard]] int getHeight(int monitor = -1) const;
        [[nodiscard]] float scaleX(int monitor = -1) const;
        [[nodiscard]] float scaleY(int monitor = -1) const;
        [[nodiscard]] int getX(int monitor = -1) const;
        [[nodiscard]] int getY(int monitor = -1) const;
        [[nodiscard]] int workWidth(int monitor = -1) const;
        [[nodiscard]] int workHeight(int monitor = -1) const;
        [[nodiscard]] int workX(int monitor = -1) const;
        [[nodiscard]] int workY(int monitor = -1) const;

        [[nodiscard]] const char *getName(int monitor = -1) const;

        [[nodiscard]] GLFWvidmode getVideoMode(int mode) const;

        [[nodiscard]] GLFWmonitor* getPrimaryMonitor() const;
        [[nodiscard]] GLFWmonitor* getMonitor(int monitor = -1) const;
    private:
        const GLFWvidmode* videoModes_{};
        GLFWmonitor** monitors_{};
        GLFWmonitor* primaryMonitor_{};

        int currentMonitor_{};
        int numVideoModes_{};
        int numMonitors_{};
    };
}