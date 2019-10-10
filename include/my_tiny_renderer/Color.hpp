#ifndef COLOR_HPP
#define COLOR_HPP

#include <glm/glm.hpp>
#include <png++/png.hpp>

class Color {
private:
    glm::vec3 _value;

public:
    Color();
    Color(glm::vec3 rgb);
    Color(const Color& other) = default;
    virtual ~Color() = default;

    glm::vec3 Value() const;
    png::rgb_pixel Pixel() const;
    void Set(glm::vec3 rgb);

    Color operator+(const Color& other);
    Color operator*(const Color& other);
    Color operator*(const float& scale);

    static Color White;
    static Color Black;
    static Color Red;
    static Color Green;
    static Color Blue;
};

#endif /* COLOR_H */
