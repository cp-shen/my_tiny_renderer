#include <catch2/catch.hpp>
#include <png++/png.hpp>

TEST_CASE("test_png")
{
    png::image<png::rgb_pixel> image(128, 128);

    for (png::uint_32 y = 0; y < image.get_height(); y++) {
        for (png::uint_32 x = 0; x < image.get_width(); x++) {
            image.set_pixel(x, y, png::rgb_pixel(x, y, x + y));
        }
    }

    image.write("test_png.png");
}
