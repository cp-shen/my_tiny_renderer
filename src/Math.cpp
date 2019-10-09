#include <my_tiny_renderer/Math.hpp>

float Math::EdgeFunction(glm::vec2 a, glm::vec2 b, glm::vec2 c) {
    // the 3 vertices should be counter clockwise
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}
