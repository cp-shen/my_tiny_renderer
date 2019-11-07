#include <catch2/catch.hpp>
#include <my_tiny_renderer/Color.hpp>
#include <my_tiny_renderer/MyGL.hpp>
#include <my_tiny_renderer/Image.hpp>

TEST_CASE("draw_triangle")
{
    const char* output_path = "test_draw_triangle.png";
    const unsigned image_size = 256;
    PngImage image(image_size, image_size);

    glm::vec2 triangle0[] = {
        glm::vec2(10, 70),
        glm::vec2(50, 160),
        glm::vec2(70, 80),
    };
    glm::vec2 triangle1[] = {
        glm::vec2(180, 50),
        glm::vec2(150, 1),
        glm::vec2(70, 180),
    };
    glm::vec2 triangle2[] = {
        glm::vec2(180, 150),
        glm::vec2(120, 160),
        glm::vec2(130, 180),
    };

    REQUIRE_NOTHROW(MyGL::DrawTriangle(triangle0[0], triangle0[1], triangle0[2],
                                       image, Color::Red.Pixel()));
    REQUIRE_NOTHROW(MyGL::DrawTriangle(triangle1[0], triangle1[1], triangle1[2],
                                       image, Color::White.Pixel()));
    REQUIRE_NOTHROW(MyGL::DrawTriangle(triangle2[0], triangle2[1], triangle2[2],
                                       image, Color::Green.Pixel()));

    image.FlipVert();
    image.write(output_path);
}
