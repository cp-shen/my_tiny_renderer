//
// Created by scp on 2019/11/7.
//

#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>


class Transform {
public:
    Transform();
    virtual  ~Transform();

    glm::mat4 ToMatrix() const;

    glm::vec3 scale;
    glm::quat rotation;
    glm::vec3 translation;
};


#endif //TRANSFORM_HPP
