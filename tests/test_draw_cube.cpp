//
// Created by scp on 2019/11/7.
//

#include <catch2/catch.hpp>

static std::vector<float> cubeVertPosData{
        0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
        0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f,
};

static std::vector<int> cubeIdxData{
        7, 3, 2, 7, 2, 6, 6, 2, 5, 5, 2, 1, 4, 5, 1, 4, 1, 0,
        7, 4, 3, 3, 4, 0, 4, 7, 6, 4, 6, 5, 3, 0, 2, 2, 0, 1,
};

static std::vector<float> triVertPosData{
        -1.0f, -1.0f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
};

static std::vector<float> triVertUvData{
        0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
};

static std::vector<int> triIdxData{0, 1, 2};

TEST_CASE("draw_cube") {
    //TODO
}
