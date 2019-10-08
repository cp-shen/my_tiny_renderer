#include <my_tiny_renderer/Math.hpp>

float Math::EdgeFunction(glm::vec2 a, glm::vec2 b, glm::vec2 c) {
    return (c.x - a.x) * (b.y - a.y) - (c.y - a.y) * (b.x - a.x);
}
