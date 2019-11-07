//
// Created by scp on 2019/11/7.
//

#include "my_tiny_renderer/ImageBuffer.hpp"

ImageBuffer::ImageBuffer(unsigned w, unsigned h) {
    image = std::make_unique<PngImage>(w, h);
}

ImageBuffer::~ImageBuffer() = default;

void ImageBuffer::Render(const Scene &scene, const Camera &camera) {
    //TODO
}
