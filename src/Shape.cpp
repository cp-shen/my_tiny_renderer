#include <my_tiny_renderer/Shape.hpp>

Shape::Shape(size_t size)
    : vertices(size)
{ }

Shape::~Shape() {  }

glm::vec3& Shape::operator[](size_t idx) {
    return this->vertices[idx];
}

const glm::vec3& Shape::operator[](size_t idx) const {
    return this->vertices[idx];
}

Triangle::Triangle(glm::vec3 v0, glm::vec3 v1, glm::vec3 v2)
    : Shape(3)
{
    this->vertices[0] = v0;
    this->vertices[1] = v1;
    this->vertices[2] = v2;
}

glm::vec3 Triangle::Normal() const
{
    auto vec = glm::cross((*this)[1] - (*this)[0], (*this)[2] - (*this)[1]);
    return glm::normalize(vec);
}
