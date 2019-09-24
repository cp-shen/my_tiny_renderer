#ifndef BOX_H
#define BOX_H

#include <glm/glm.hpp>

class Box {
private:
    glm::vec2 _minPoint;
    glm::vec2 _maxPoint;
public:
    Box (unsigned w, unsigned h);
    virtual ~Box ();
    bool CheckPointInBox(glm::vec2 point);
    bool CheckPointOnEgde(glm::vec2 point);
};

#endif /* BOX_H */
