#ifndef LIGHT_HPP
#define LIGHT_HPP

#include <glm/glm.hpp>

class Light {
private:
public:
    Light ();
    virtual ~Light () = 0;
};

class DirectionalLight {
    public:
        DirectionalLight();
        virtual ~DirectionalLight();
        glm::vec3 direction;
};

#endif /* LIGHT_HPP */
