//
// Created by scp on 2019/11/7.
//

#include "my_tiny_renderer/Transform.hpp"

Transform::Transform()
    : scale(0, 0, 0)
    , rotation(1, 0, 0, 0)
    , translation(0, 0, 0)
{ }

Transform::~Transform() = default;

glm::mat4 Transform::ToMatrix() const {
    auto mat = glm::scale(glm::identity<glm::mat4>(), scale);
    mat = glm::mat4_cast(rotation) * mat;
    mat = glm::translate(mat, translation);
    return mat;
}
