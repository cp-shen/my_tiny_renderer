#include <my_tiny_renderer/Color.hpp>
#include <algorithm>

Color::Color()
    : _value(0.f)
{ }

Color::Color(glm::vec3 rgb)
    : Color()
{
    Set(rgb);
}

Color::~Color() { }

glm::vec3 Color::Value() const
{
    return _value;
}

png::rgb_pixel Color::Pixel() const
{
    return png::rgb_pixel(_value.r * 255, _value.g * 255, _value.b * 255);
}

void Color::Set(glm::vec3 rgb)
{
    _value.r = std::max(std::min(rgb.r, 1.0f), 0.0f);
    _value.g = std::max(std::min(rgb.g, 1.0f), 0.0f);
    _value.b = std::max(std::min(rgb.b, 1.0f), 0.0f);
}

Color Color::White = Color({1.f, 1.f, 1.f});
Color Color::Black = Color({0.f, 0.f, 0.f});
Color Color::Red = Color({1.f, 0.f, 0.f});
Color Color::Green = Color({0.f, 1.f, 0.f});
Color Color::Blue = Color({0.f, 0.f, 1.f});
