#include <my_tiny_renderer/MyGL.hpp>
#include <my_tiny_renderer/Box.hpp>
#include <sstream>

void MyGL::DrawLine (
            int x0,
            int y0,
            int x1,
            int y1,
            png::image<png::rgb_pixel>& image,
            png::rgb_pixel& color)
{
    bool steep = false;
    if (std::abs(x0 - x1) < std::abs(y0 - y1)) {
        std::swap(x0, y0);
        std::swap(x1, y1);
        steep = true;
    }

    if (x0 > x1) {
        std::swap(x0, x1);
        std::swap(y0, y1);
    }

    int dx = x1 - x0;
    int dy = y1 - y0;
    int derror = std::abs(dy) * 2;
    int error = 0;
    int y = y0;

    for (int x = x0; x <= x1; x++) {
        if (steep)
            image.set_pixel(y, x, color);
        else
            image.set_pixel(x, y, color);

        error += derror;
        if (error >= dx) {
            y += (dy > 0 ? 1 : -1);
            error -= dx * 2;
        }
    }
}

void MyGL::FlipImageVert(png::image<png::rgb_pixel>& image)
{
    for (size_t row_idx = 0; row_idx < image.get_height() / 2; row_idx++) {
        size_t row_idx2 = image.get_height() - row_idx - 1;

        auto& buf = image.get_pixbuf();
        auto tmp = buf.get_row(row_idx);

        buf.put_row(row_idx, buf.get_row(row_idx2));
        buf.put_row(row_idx2, tmp);
    }
}

void MyGL::FlipImageHor(png::image<png::rgb_pixel>& image)
{
    for (size_t row = 0; row < image.get_height(); row++) {
        for (size_t col = 0; col < image.get_width() / 2; col++) {
            size_t col_to_swap = image.get_width() - col - 1;
            auto tmp = image[row][col];
            image[row][col] = image[row][col_to_swap];
            image[row][col_to_swap] = tmp;
        }
    }
}
