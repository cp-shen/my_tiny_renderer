#include <my_tiny_renderer/MyGL.hpp>
#include <my_tiny_renderer/Box.hpp>
#include <my_tiny_renderer/Math.hpp>
#include <algorithm>
#include <stdexcept>

MyGL::MyGL() = default;

MyGL::~MyGL() = default;

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
    //FIXME: remove roundings
    glm::ivec2 iv0 {std::round(v0.x), std::round(v0.y)};
    glm::ivec2 iv1 {std::round(v1.x), std::round(v1.y)};
    MyGL::DrawLine(iv0.x, iv0.y, iv1.x, iv1.y, image, color);
}

void MyGL::DrawTriangle(
        glm::vec2 t0,
        glm::vec2 t1,
        glm::vec2 t2,
        png::image<png::rgb_pixel>& image,
        png::rgb_pixel color)
{
    float val = (t1.y - t0.y) * (t2.x - t1.x) - (t1.x - t0.x) * (t2.y - t1.y);
    if (val == 0)
        throw std::runtime_error("the 3 vertices of a triangle should not be colinear");
    else if (val > 0)
        std::swap(t0, t1); // the 3 vertices should be counter clock-wise

    // Compute triangle bounding box
    int minX = std::floor(std::min({t0.x, t1.x, t2.x}));
    int minY = std::floor(std::min({t0.y, t1.y, t2.y}));
    int maxX = std::floor(std::max({t0.x, t1.x, t2.x}));
    int maxY = std::floor(std::max({t0.y, t1.y, t2.y}));

    glm::vec2 edge01 = t1 - t0;
    glm::vec2 edge02 = t2 - t0;
    glm::vec2 edge12 = t2 - t1;

    glm::ivec2 p(0);

    for (p.y = minY; p.y <= maxY; p.y++) {
        for (p.x = minX; p.x <= maxX; p.x++) {
            bool overlaps = true;
            glm::vec2 p_center = {p.x + .5f, p.y + .5f};

            float w0 = Math::EdgeFunction(t1, t2, p_center);
            float w1 = Math::EdgeFunction(t2, t0, p_center);
            float w2 = Math::EdgeFunction(t0, t1, p_center);

            overlaps &= (w0 == 0 ? ((edge12.y == 0 && edge12.x < 0) || edge12.y < 0) : (w0 > 0));
            overlaps &= (w1 == 0 ? ((edge02.y == 0 && edge02.x < 0) || edge02.y < 0) : (w1 > 0));
            overlaps &= (w2 == 0 ? ((edge01.y == 0 && edge01.x < 0) || edge01.y < 0) : (w2 > 0));

            if (overlaps)
                image.set_pixel(p.x, p.y, color);
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
