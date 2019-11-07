#include <catch2/catch.hpp>
#include <my_tiny_renderer/Image.hpp>

static bool rgb_equal(const png::rgb_pixel& p1, const png::rgb_pixel& p2) {
    return p1.blue == p2.blue && p1.green == p2.green && p1.red == p2.red;
}

static bool image_equal(const PngImage& i1, const PngImage& i2) {
     if (i1.get_height() == i2.get_height() && i1.get_width() == i2.get_width()) {
         for(size_t row = 0; row < i1.get_width(); row++ ) {
             for(size_t col = 0; col < i2.get_width(); col++ ) {
                 if (!rgb_equal(i1[row][col],i2[row][col]))
                     return false;
             }
         }
     }
     return true;
}

TEST_CASE("flip_image")
{
    const char* input_path = "flip/vim.png";
    const char* output_path1 = "flip/vim_flip_hor.png";
    const char* output_path2 = "flip/vim_flip_vert.png";

    PngImage image1(input_path);
    PngImage image2(input_path);
    PngImage image3(input_path);

    image2.FlipVert();
    image2.FlipVert();
    image3.FlipHor();
    image3.FlipHor();

    REQUIRE(image_equal(image1, image2));
    REQUIRE(image_equal(image1, image3));

    REQUIRE_NOTHROW(image1.FlipHor());
    image1.write(output_path1);

    REQUIRE_NOTHROW(image1.FlipVert());
    image1.write(output_path2);
}
