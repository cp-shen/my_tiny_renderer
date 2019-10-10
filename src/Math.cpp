#include <my_tiny_renderer/Math.hpp>

float Math::EdgeFunction(glm::vec2 a, glm::vec2 b, glm::vec2 p) {
    // the 3 vertices should be counter clockwise
    return (b.x - a.x) * (p.y - a.y) - (b.y - a.y) * (p.x - a.x);
}
