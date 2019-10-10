#include <my_tiny_renderer/Light.hpp>

Light::Light()
    : color(Color::White)
{ }

Light::~Light() {  }

DirectionalLight::DirectionalLight()
    : Light()
    , _direction(0.f, 0.f, -1.f)
    , intensity(1.f)
{ }

glm::vec3 DirectionalLight::Direction() const
{
    return this->_direction;
}

void DirectionalLight::SetDirection(glm::vec3 dir)
{
    assert(dir != glm::vec3(0.f));
    this->_direction = glm::normalize(dir);
}
