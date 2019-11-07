#ifndef LIGHT_HPP
#define LIGHT_HPP

#include <glm/glm.hpp>
#include <my_tiny_renderer/Color.hpp>

class Light {
private:
public:
    Light();
    virtual ~Light() = 0;

    Color color;
};

class DirectionalLight : public Light {
private:
    glm::vec3 _direction;
public:
    DirectionalLight();
    ~DirectionalLight() override = default;

    float intensity;
    glm::vec3 Direction() const;
    void SetDirection(glm::vec3 dir);
};

#endif /* LIGHT_HPP */
