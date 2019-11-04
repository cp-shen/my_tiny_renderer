//
// Created by scp on 2019/11/4.
//

#include <my_tiny_renderer/Camera.hpp>

Camera::Camera() : position(), rotation() {
    position = glm::vec3(0.f);
    rotation = glm::quat(1, 0, 0, 0);

    fov = glm::radians(45.0f);
    aspect = 4.0f / 3.0f;
    near = 0.1f;
    far = 100.0f;
}

glm::mat4 Camera::ProjectionMatrix() const {
    return glm::perspective(fov, aspect, near, far);
}

glm::mat4 Camera::ViewMatrix() const {
    auto forward = glm::rotate(glm::normalize(rotation), glm::vec3(0, 0, 1));
    auto target = position + forward;
    auto up = glm::rotate(glm::normalize(rotation), glm::vec3(0, 1, 0));
    return glm::lookAt(position, target, up);
}

//TODO: void Camera::SetAspectByWindow(const Window &window) { }
