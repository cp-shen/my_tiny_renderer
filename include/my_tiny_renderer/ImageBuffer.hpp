//
// Created by scp on 2019/11/7.
//

#ifndef IMAGE_BUFFER_HPP
#define IMAGE_BUFFER_HPP

#include <my_tiny_renderer/RenderTarget.hpp>
#include <my_tiny_renderer/Image.hpp>
#include <memory>

class ImageBuffer : public RenderTarget {
private:
    std::unique_ptr<IImage> image;
public:
    ImageBuffer(unsigned w, unsigned h);
    ~ImageBuffer() override;
    void Render(const Scene& scene, const Camera& camera) override;
};


#endif //IMAGE_BUFFER_HPP
