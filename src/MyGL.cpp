#include <my_tiny_renderer/MyGL.hpp>
#include <my_tiny_renderer/Box.hpp>
#include <sstream>

void MyGL::DrawLine (
            int x0,
            int y0,
            int x1,
            int y1,
            png::image<png::rgb_pixel>& image,
            png::rgb_pixel color)
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

void MyGL::DrawLine(
        glm::vec2 v0,
        glm::vec2 v1,
        png::image<png::rgb_pixel>& image,
        png::rgb_pixel color)
{
    MyGL::DrawLine(v0.x, v0.y, v1.x, v1.y, image, color);
}

void MyGL::DrawTriangle(
        glm::vec2 t0,
        glm::vec2 t1,
        glm::vec2 t2,
        png::image<png::rgb_pixel>& image,
        png::rgb_pixel color)
{
    // bubble sort the vertices lower-to-upper
    if (t0.y > t1.y) std::swap(t0, t1);
    if (t1.y > t2.y) std::swap(t1, t2);
    if (t0.y > t1.y) std::swap(t0, t1);

    MyGL::DrawLine(t0, t1, image, color);
    MyGL::DrawLine(t0, t2, image, color);
    MyGL::DrawLine(t1, t2, image, color);
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
