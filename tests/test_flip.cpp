#include <catch2/catch.hpp>
#include <my_tiny_renderer/MyGL.hpp>

TEST_CASE("flip_image")
{
    const char* input_path = "flip/vim.png";
    const char* output_path1 = "flip/vim_flip_hor.png";
    const char* output_path2 = "flip/vim_flip_vert.png";

    png::image<png::rgb_pixel> image(input_path);

    REQUIRE_NOTHROW(MyGL::FlipImageHor(image));
    image.write(output_path1);

    REQUIRE_NOTHROW(MyGL::FlipImageVert(image));
    image.write(output_path2);
}
