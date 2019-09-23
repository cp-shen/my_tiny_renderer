#include <catch2/catch.hpp>
#include <my_tiny_renderer/MyGL.hpp>

TEST_CASE("Draw Line")
{
    png::image<png::rgb_pixel> image(128, 128);
    png::rgb_pixel pixel_red(255, 0, 0);
    png::rgb_pixel pixel_white(255, 255, 255);

    REQUIRE_NOTHROW(MyGL::DrawLine(13, 20, 80, 40, image, pixel_white));
    REQUIRE_NOTHROW(MyGL::DrawLine(20, 13, 40, 80, image, pixel_red));
    REQUIRE_NOTHROW(MyGL::DrawLine(80, 40, 13, 20, image, pixel_red));

    REQUIRE_NOTHROW(MyGL::DrawLine(0, 0, 0, 0, image, pixel_white));
    REQUIRE_NOTHROW(MyGL::DrawLine(0, 0, 0, 0, image, pixel_red));

    image.write("test_draw_line.png");
}
