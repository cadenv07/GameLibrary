#include <gamelibrary/graphics/Camera.h>

namespace GameLibrary {
    Camera::Camera(const glm::vec3 &position, const float aspect, const float fov, const float nearPlane, const float farPlane)
        : position_(position), aspect_(aspect), nearPlane_(nearPlane), farPlane_(farPlane){}
    Camera::Camera(const float aspect, const float fov, const float nearPlane, const float farPlane) {
        Camera(glm::vec3{0.0f}, aspect, fov, nearPlane, farPlane);
    }

    void Camera::setPerspective(const float aspect, const float fov, const float nearPlane, const float farPlane) {
        setAspect(aspect);
        setFov(fov);
        setNearPlane(nearPlane);
        setFarPlane(farPlane);
    }

    void Camera::getPerspective(float &aspect, float &fov, float &nearPlane, float &farPlane) const {
        aspect = aspect_;
        fov = fov_;
        nearPlane = nearPlane_;
        farPlane = farPlane_;
    }

    void Camera::setAspect(const float aspect) {
        if (aspect < 0.0f) {
            throw std::invalid_argument("Aspect ratio must be non-negative");
        }
        aspect_ = aspect;
    }

    void Camera::setFov(const float fov) {
        if (fov < 0.0f || fov > 180.0f) {
            throw std::invalid_argument("FOV must be between 0 and 180 degrees");
        }
        fov_ = fov;
    }

    void Camera::setNearPlane(const float nearPlane) {
        if (nearPlane < 0.0f || nearPlane > farPlane_) {
            throw std::invalid_argument("Near plane must be between 0 and the far plane");
        }
        nearPlane_ = nearPlane;
    }

    void Camera::setFarPlane(const float farPlane) {
        if (farPlane < nearPlane_) {
            throw std::invalid_argument("Far plane must be greater than the near plane");
        }
        farPlane_ = farPlane;
    }

    void Camera::setPosition(const glm::vec3 &position) {
        position_ = position;
    }

    void Camera::setOffset(const glm::vec3 &offset) {
        offset_ = offset;
    }

    void Camera::setOrientation(const glm::quat &orientation) {
        orientation_ = orientation;
        updateAngles();
    }

    void Camera::setRotation(const float pitch, const float yaw, const float roll) {
        orientation_ = glm::angleAxis(glm::radians(pitch), up());
        orientation_ *= glm::angleAxis(glm::radians(yaw), right());
        orientation_ *= glm::angleAxis(glm::radians(roll), forward());
    }

    void Camera::setPitch(const float pitch) {
        pitch_ = pitch;
        setRotation(pitch_, yaw_, roll_);
    }

    void Camera::setYaw(const float yaw) {
        yaw_ = yaw;
        setRotation(pitch_, yaw_, roll_);
    }

    void Camera::setRoll(const float roll) {
        roll_ = roll;
        setRotation(pitch_, yaw_, roll_);
    }

    void Camera::updateAngles() {
        const glm::vec3 angles = glm::eulerAngles(orientation_);
        pitch_ = glm::degrees(angles.x);
        yaw_ = glm::degrees(angles.y);
        roll_ = glm::degrees(angles.z);
    }

    void Camera::move(const glm::vec3 &distance) {
        position_ += distance;
    }

    void Camera::rotate(const glm::quat &rotate) {
        orientation_ *= glm::normalize(rotate);
    }

    void Camera::rotate(const float pitch, const float yaw, const float roll) {
        orientation_ *= glm::angleAxis(glm::radians(pitch), up());
        orientation_ *= glm::angleAxis(glm::radians(yaw), right());
        orientation_ *= glm::angleAxis(glm::radians(roll), forward());
    }

    void Camera::offset(const glm::vec3 &distance) {
        offset_ += distance;
    }

    void Camera::lookAt(const glm::vec3 &position) {
        const glm::vec3 direction = glm::normalize(cameraPosition() - position);
        if (glm::dot(direction, direction) < 1e-12f) {
            throw std::invalid_argument("Target position cannot equal the cameras current position");
        }
        if (glm::dot(glm::cross(direction, worldUp_), glm::cross(direction, worldUp_)) < 1e-12f) {
            throw std::invalid_argument("Forward vector cannot be parallel to the up vector");
        }
        orientation_ = glm::normalize(glm::quatLookAtRH(direction, worldUp_));
        updateAngles();
    }

    void Camera::setDistance(const float distance) {
        if (distance <= 0.0f) {
            throw std::invalid_argument("Distance must be non-negative");
        }
        distance_ = distance;
    }

    glm::mat4 Camera::getViewMatrix() const {
        return glm::lookAt(cameraPosition(), cameraPosition() + forward(), worldUp_);
    }

    glm::mat4 Camera::getProjectionMatrix() const {
        return glm::perspectiveRH_ZO(glm::radians(fov_), aspect_, nearPlane_, farPlane_);
    }

    glm::vec3 Camera::getPosition() const {
        return position_;
    }

    glm::vec3 Camera::getOffset() const {
        return offset_;
    }

    glm::quat Camera::getOrientation() const {
        return orientation_;
    }

    glm::vec3 Camera::cameraPosition() const {
        return position_ + offset_ + -distance_ * forward();
    }

    glm::vec3 Camera::up() const {
        return worldUp_;
    }

    glm::vec3 Camera::forward() const {
        return worldForward_ * orientation_;
    }

    glm::vec3 Camera::right() const {
        return worldRight_ * orientation_;
    }

    float Camera::x() const {
        return position_.x;
    }

    float Camera::y() const {
        return position_.y;
    }

    float Camera::z() const {
        return position_.z;
    }

    float Camera::offsetX() const {
        return offset_.x;
    }

    float Camera::offsetY() const {
        return offset_.y;
    }

    float Camera::offsetZ() const {
        return offset_.z;
    }

    float Camera::getDistance() const {
        return distance_;
    }

    float Camera::aspect() const {
        return aspect_;
    }

    float Camera::fov() const {
        return fov_;
    }

    float Camera::nearPlane() const {
        return nearPlane_;
    }

    float Camera::farPlane() const {
        return farPlane_;
    }

    float Camera::getPitch() const {
        return pitch_;
    }

    float Camera::getYaw() const {
        return yaw_;
    }

    float Camera::getRoll() const {
        return roll_;
    }
}
