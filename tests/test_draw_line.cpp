#include <catch2/catch.hpp>
#include <my_tiny_renderer/MyGL.hpp>

TEST_CASE("draw_line")
{
    png::rgb_pixel pixel_red(255, 0, 0);
    png::rgb_pixel pixel_white(255, 255, 255);
    unsigned image_size = 128;
    const char* image_name = "a.png";

    SECTION("draw_line_1") {
        image_name = "test_draw_line_1.png";
        image_size = 128;
        png::image<png::rgb_pixel> image(image_size, image_size);

        REQUIRE_NOTHROW(MyGL::DrawLine(13, 20, 80, 40, image, pixel_white));
        REQUIRE_NOTHROW(MyGL::DrawLine(20, 13, 40, 80, image, pixel_red));
        REQUIRE_NOTHROW(MyGL::DrawLine(80, 40, 13, 20, image, pixel_red));

        REQUIRE_NOTHROW(MyGL::DrawLine(0, 0, 0, 0, image, pixel_white));
        REQUIRE_NOTHROW(MyGL::DrawLine(0, 0, 0, 0, image, pixel_red));

        image.write(image_name);
    }

    SECTION("draw_line_2") {
        image_name = "test_draw_line_2.png";
        image_size = 800;
        png::image<png::rgb_pixel> image(image_size, image_size);

        REQUIRE_NOTHROW(MyGL::DrawLine(461, 788, 495, 776, image, pixel_red));

        //image.write(image_name);
    }
}
