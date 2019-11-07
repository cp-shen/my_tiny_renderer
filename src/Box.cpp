#include <my_tiny_renderer/Box.hpp>

Box::Box(unsigned w, unsigned h)
    : _minPoint(0, 0)
    , _maxPoint(w, h)
{ }

Box::~Box() = default;

bool Box::CheckPointInBox(glm::vec2 point)
{
    return point.x > _minPoint.x && point.x < _maxPoint.x
        && point.y > _minPoint.y && point.y < _maxPoint.y;
}

bool Box::CheckPointOnEdge(glm::vec2 point)
{
    if (point.x != _minPoint.x || point.x != _maxPoint.x) {
        return false;
    }
    if (point.y != _minPoint.y || point.y != _maxPoint.y) {
        return false;
    }
    return true;
}
