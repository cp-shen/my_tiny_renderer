//
// Created by scp on 2019/11/4.
//

#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>

class Camera {
public:
    Camera();
    virtual ~Camera() = default;

    glm::mat4 ProjectionMatrix() const;
    glm::mat4 ViewMatrix() const;
    //TODO: void SetAspectByWindow(const Window& window);

    float fov; // field of view in radians
    float aspect; // width / height
    float near;
    float far;

    glm::vec3 position;
    glm::quat rotation;
};

#endif //CAMERA_HPP
