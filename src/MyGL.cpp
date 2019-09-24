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
    int image_width = image.get_width();
    int image_height = image.get_height();
    Box box = Box(image_width, image_height);

    bool transposed = std::abs(x1 - x0) < std::abs(y1 - y0);

    if (transposed) {
        std::swap(x0, y0);
        std::swap(x1, y1);
    }

    if (x0 > x1) {
        std::swap(x0, x1);
        std::swap(y0, y1);
    }

    int deltaX = x1 - x0;
    int deltaY = y1 - y0;

    // only one point in the line
    if (x0 == x1) {
        image.set_pixel(x0, y0, color);
        return;
    }

    try {
        int y = y0;
        float error = 0;
        float deltaError = std::abs(deltaY / (float)deltaX);
        for (int x = x0; x <= x1; x++) {
            if (transposed) {
                if(box.CheckPointInBox(glm::vec2(y, x)))
                    image.set_pixel(y, x, color);
                else
                    throw std::runtime_error("draw failure: "
                            + std::to_string(y) + ", " + std::to_string(x) + ", " + std::to_string(transposed));
            }
            else {
                if(box.CheckPointInBox(glm::vec2(x, y)))
                    image.set_pixel(x, y, color);
                else
                    throw std::runtime_error("draw failure: "
                            + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(transposed));
            }
            error += deltaError;
            if (error >= 0.5) {
                y += (deltaY > 0 ? 1 : -1);
                error -= 1;
            }
        }
    }
    catch (const std::exception& e) {
        std::stringstream errStr;
        errStr << e.what() << std::endl;

        errStr << " x0=" + std::to_string(x0);
        errStr << " y0=" + std::to_string(y0);
        errStr << " x1=" + std::to_string(x1);
        errStr << " y1=" + std::to_string(y1);

        std::runtime_error err(errStr.str());
        throw err;
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
