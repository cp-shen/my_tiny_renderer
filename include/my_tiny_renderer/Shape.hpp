#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <glm/glm.hpp>
#include <vector>

class Shape {
protected:
    std::vector<glm::vec3> vertices;
public:
    explicit Shape(size_t size);
    virtual ~Shape() = 0;
    Shape(const Shape& other) = default;

    glm::vec3& operator[](size_t idx);
    const glm::vec3& operator[](size_t idx) const;
};

class Triangle : Shape {
private:
public:
    Triangle(glm::vec3 v0, glm::vec3 v1, glm::vec3 v2);
    glm::vec3 Normal() const;
    ~Triangle() override = default;
};

#endif /* SHAPE_HPP */
