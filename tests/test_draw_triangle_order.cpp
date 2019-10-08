#include <catch2/catch.hpp>
#include <my_tiny_renderer/Color.hpp>
#include <my_tiny_renderer/MyGL.hpp>

TEST_CASE("draw_triangle_order")
{
    glm::vec2 triangle0[] = {
        glm::vec2(0, 0),
        glm::vec2(255, 255),
        glm::vec2(255, 0),
    };
    glm::vec2 triangle1[] = {
        glm::vec2(0, 0),
        glm::vec2(255, 255),
        glm::vec2(0, 255),
    };

    const unsigned image_size = 256;

    png::image<png::rgb_pixel> image1(image_size, image_size);
    REQUIRE_NOTHROW(MyGL::DrawTriangle(triangle0[0], triangle0[1], triangle0[2],
                                       image1, Color::Red.Pixel()));
    REQUIRE_NOTHROW(MyGL::DrawTriangle(triangle1[0], triangle1[1], triangle1[2],
                                       image1, Color::Green.Pixel()));

    png::image<png::rgb_pixel> image2(image_size, image_size);
    REQUIRE_NOTHROW(MyGL::DrawTriangle(triangle1[0], triangle1[1], triangle1[2],
                                       image2, Color::Green.Pixel()));
    REQUIRE_NOTHROW(MyGL::DrawTriangle(triangle0[0], triangle0[1], triangle0[2],
                                       image2, Color::Red.Pixel()));

    for (unsigned i = 0; i < image_size; i++) {
        for (unsigned j = 0; j < image_size; j++) {
            REQUIRE((int)image1.get_pixel(i, j).red == (int)image2.get_pixel(i,j).red);
            REQUIRE((int)image1.get_pixel(i, j).green == (int)image2.get_pixel(i,j).green);
            REQUIRE((int)image1.get_pixel(i, j).blue == (int)image2.get_pixel(i,j).blue);
        }
    }
}
