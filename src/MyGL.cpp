#include <my_tiny_renderer/MyGL.hpp>

void MyGL::DrawLine (
            int x0,
            int y0,
            int x1,
            int y1,
            png::image<png::rgb_pixel>& image,
            png::rgb_pixel& color)
{
    int deltaX = std::abs(x0 - x1);
    int deltaY = std::abs(y0 - y1);
    bool transposed = deltaX < deltaY;

    if (transposed) {
        std::swap(x0, y0);
        std::swap(x1, y1);
    }

    if (x0 > x1) {
        std::swap(x0, x1);
        std::swap(y0, y1);
    }

    for (int x = x0; x <= x1; x++) {
        float t = (x - x0) / (float) (x1 - x0);
        int y = y0 + t * (y1 - y0);

        if (transposed) {
            image.set_pixel(y, x, color);
        }
        else {
            image.set_pixel(x, y, color);
        }
    }

}
