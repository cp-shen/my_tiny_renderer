#ifndef MATH_HPP
#define MATH_HPP

#include <glm/glm.hpp>

class Math {
public:
    Math () = default;
    virtual ~Math () = default;

    static float EdgeFunction(glm::vec2 a, glm::vec2 b, glm::vec2 c);
};

#endif /* MATH_HPP */
