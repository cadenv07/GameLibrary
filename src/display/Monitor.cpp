#include <gamelibrary/display/Monitor.h>

namespace GameLibrary {
    Monitor::Monitor() {
        currentMonitor_ = 0;
        monitors_ = glfwGetMonitors(&numMonitors_);
        primaryMonitor_ = glfwGetPrimaryMonitor();
        videoModes_ = glfwGetVideoModes(monitors_[currentMonitor_], &numVideoModes_);
    }

    void Monitor::setMonitor(const int monitor) {
        currentMonitor_ = monitor;
    }

    void Monitor::setGammaRamp(const GLFWgammaramp &ramp, int monitor) const {
        if (monitor < 0) monitor = currentMonitor_;
        if (monitor > numMonitors_) {
            throw std::invalid_argument("Inputted monitor out of bounds");
        }
        glfwSetGammaRamp(monitors_[monitor], &ramp);
    }

    void Monitor::setGamma(const float gamma, int monitor) const {
        if (monitor < 0) monitor = currentMonitor_;
        if (monitor > numMonitors_) {
            throw std::invalid_argument("Inputted monitor out of bounds");
        }
        glfwSetGamma(monitors_[monitor], gamma);
    }

    int Monitor::getWidth(int monitor) const {
        if (monitor < 0) monitor = currentMonitor_;
        if (monitor > numMonitors_) {
            throw std::invalid_argument("Inputted monitor out of bounds");
        }
        int width = 0;
        glfwGetMonitorPhysicalSize(monitors_[monitor], &width, nullptr);
        return width;
    }

    int Monitor::getHeight(int monitor) const {
        if (monitor < 0) monitor = currentMonitor_;
        if (monitor > numMonitors_) {
            throw std::invalid_argument("Inputted monitor out of bounds");
        }
        int height = 0;
        glfwGetMonitorPhysicalSize(monitors_[monitor], nullptr, &height);
        return height;
    }

    float Monitor::scaleX(int monitor) const {
        if (monitor < 0) monitor = currentMonitor_;
        if (monitor > numMonitors_) {
            throw std::invalid_argument("Inputted monitor out of bounds");
        }
        float scaleX = 0;
        glfwGetMonitorContentScale(monitors_[monitor], &scaleX, nullptr);
        return scaleX;
    }

    float Monitor::scaleY(int monitor) const {
        if (monitor < 0) monitor = currentMonitor_;
        if (monitor > numMonitors_) {
            throw std::invalid_argument("Inputted monitor out of bounds");
        }
        float scaleY = 0;
        glfwGetMonitorContentScale(monitors_[monitor], nullptr, &scaleY);
        return scaleY;
    }

    int Monitor::getX(int monitor) const {
        if (monitor < 0) monitor = currentMonitor_;
        if (monitor > numMonitors_) {
            throw std::invalid_argument("Inputted monitor out of bounds");
        }
        int x = 0;
        glfwGetMonitorPos(monitors_[monitor], &x, nullptr);
        return x;
    }

    int Monitor::getY(int monitor) const {
        if (monitor < 0) monitor = currentMonitor_;
        if (monitor > numMonitors_) {
            throw std::invalid_argument("Inputted monitor out of bounds");
        }
        int y = 0;
        glfwGetMonitorPos(monitors_[monitor], nullptr, &y);
        return y;
    }

    int Monitor::workWidth(int monitor) const {
        if (monitor < 0) monitor = currentMonitor_;
        if (monitor > numMonitors_) {
            throw std::invalid_argument("Inputted monitor out of bounds");
        }
        int width = 0;
        glfwGetMonitorWorkarea(monitors_[monitor], nullptr, nullptr, &width, nullptr);
        return width;
    }

    int Monitor::workHeight(int monitor) const {
        if (monitor < 0) monitor = currentMonitor_;
        if (monitor > numMonitors_) {
            throw std::invalid_argument("Inputted monitor out of bounds");
        }
        int height = 0;
        glfwGetMonitorWorkarea(monitors_[monitor], nullptr, nullptr, nullptr, &height);
        return height;
    }

    int Monitor::workX(int monitor) const {
        if (monitor < 0) monitor = currentMonitor_;
        if (monitor > numMonitors_) {
            throw std::invalid_argument("Inputted monitor out of bounds");
        }
        int x = 0;
        glfwGetMonitorWorkarea(monitors_[monitor], &x, nullptr, nullptr, nullptr);
        return x;
    }

    int Monitor::workY(int monitor) const {
        if (monitor < 0) monitor = currentMonitor_;
        if (monitor > numMonitors_) {
            throw std::invalid_argument("Inputted monitor out of bounds");
        }
        int y = 0;
        glfwGetMonitorWorkarea(monitors_[monitor], nullptr, &y, nullptr, nullptr);
        return y;
    }

    const char *Monitor::getName(int monitor) const {
        if (monitor < 0) monitor = currentMonitor_;
        if (monitor > numMonitors_) {
            throw std::invalid_argument("Inputted monitor out of bounds");
        }
        return glfwGetMonitorName(monitors_[monitor]);
    }

    GLFWvidmode Monitor::getVideoMode(const int mode) const {
        if (mode < 0 || mode > numVideoModes_) {
            throw std::invalid_argument("Inputted mode out of bounds");
        }
        return videoModes_[mode];
    }

    GLFWmonitor* Monitor::getPrimaryMonitor() const {
        return primaryMonitor_;
    }

    GLFWmonitor* Monitor::getMonitor(int monitor) const {
        if (monitor < 0) monitor = currentMonitor_;
        if (monitor > numMonitors_) {
            throw std::invalid_argument("Inputted monitor out of bounds");
        }
        return monitors_[monitor];
    }
}
