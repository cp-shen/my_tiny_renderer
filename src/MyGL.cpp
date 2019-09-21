#include <my_tiny_renderer/MyGL.hpp>

void MyGL::DrawLine(
            int x0,
            int y0,
            int x1,
            int y1,
            png::image<png::rgb_pixel>& image,
            png::rgb_pixel& color)
{
    int deltaX = std::abs(x0 - x1);
    int deltaY = std::abs(y0 - y1);
}
