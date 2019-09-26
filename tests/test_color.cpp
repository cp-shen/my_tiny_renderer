#include <catch2/catch.hpp>
#include <my_tiny_renderer/Color.hpp>

TEST_CASE("test_color")
{
    REQUIRE(Color::Red.Value().r == 1.f);
    REQUIRE(Color::Red.Value().g == 0.f);
    REQUIRE(Color::Red.Value().b == 0.f);

    REQUIRE(Color::Red.Pixel().red == 255);
    REQUIRE(Color::Red.Pixel().green == 0);
    REQUIRE(Color::Red.Pixel().blue == 0);
}
