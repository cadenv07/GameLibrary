/***************************************************\
* @file Camera.h
* @brief [fill out description]
*
* [fill out description]
*
* @author cadenv07
* @date 10/23/26
\***************************************************/

#pragma once

#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>
#include <stdexcept>

namespace GameLibrary {
    /**
     * @class Camera
     *
     * @brief Contains an extensive set of functions for the creation, modification, and use of a camera.
     */
    class Camera {
    public:
        explicit Camera(const glm::vec3& position = glm::vec3(0.0f), float aspect = 16.0f/9.0f, float fov = 90.0f, float nearPlane = 0.01f, float farPlane = 1000.0f);
        explicit Camera(float aspect = 16.0f/9.0f, float fov = 90.0f, float nearPlane = 0.01f, float farPlane = 1000.0f);

        void setPerspective(float aspect, float fov, float nearPlane, float farPlane);
        void getPerspective(float& aspect, float& fov, float& nearPlane, float& farPlane) const;

        void setAspect(float aspect);
        void setFov(float fov);
        void setNearPlane(float nearPlane);
        void setFarPlane(float farPlane);

        void setPosition(const glm::vec3& position);
        void setOffset(const glm::vec3& offset);
        void setOrientation(const glm::quat& orientation);
        void setRotation(float pitch, float yaw, float roll = 0.0f);
        void setPitch(float pitch);
        void setYaw(float yaw);
        void setRoll(float roll);

        void updateAngles();

        void move(const glm::vec3& distance);
        void rotate(const glm::quat& rotate);
        void rotate(float pitch, float yaw, float roll = 0.0f);
        void offset(const glm::vec3& distance);
        void lookAt(const glm::vec3& position);

        void setDistance(float distance);

        [[nodiscard]] glm::mat4 getViewMatrix() const;
        [[nodiscard]] glm::mat4 getProjectionMatrix() const;

        [[nodiscard]] glm::vec3 getPosition() const;
        [[nodiscard]] glm::vec3 getOffset() const;
        [[nodiscard]] glm::quat getOrientation() const;
        [[nodiscard]] glm::vec3 cameraPosition() const;

        [[nodiscard]] glm::vec3 up() const;
        [[nodiscard]] glm::vec3 forward() const;
        [[nodiscard]] glm::vec3 right() const;

        [[nodiscard]] float x() const;
        [[nodiscard]] float y() const;
        [[nodiscard]] float z() const;
        [[nodiscard]] float offsetX() const;
        [[nodiscard]] float offsetY() const;
        [[nodiscard]] float offsetZ() const;
        [[nodiscard]] float getDistance() const;
        [[nodiscard]] float aspect() const;
        [[nodiscard]] float fov() const;
        [[nodiscard]] float nearPlane() const;
        [[nodiscard]] float farPlane() const;
        [[nodiscard]] float getPitch() const;
        [[nodiscard]] float getYaw() const;
        [[nodiscard]] float getRoll() const;
    private:
        glm::vec3 offset_{0.0f};
        glm::vec3 position_{0.0f};
        glm::quat orientation_{1.0f, 0.0f, 0.0f, 0.0f};

        glm::vec3 worldUp_{0.0f, 1.0f, 0.0f};
        glm::vec3 worldForward_{0.0f, 0.0f, -1.0f};
        glm::vec3 worldRight_{1.0f, 0.0f, 0.0f};

        float aspect_{0.0f};
        float nearPlane_{0.0f};
        float farPlane_{0.0f};
        float fov_{0.0f};

        float distance_{0.0f};

        float pitch_{0.0f};
        float yaw_{0.0f};
        float roll_{0.0f};
    };
}