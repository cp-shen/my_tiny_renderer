//
// Created by scp on 2019/11/7.
//

#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <png++/png.hpp>

class IImage {
public:
    IImage();
    virtual ~IImage() = 0;
    virtual void FlipVert() = 0;
    virtual void FlipHor() = 0;
};

class PngImage : IImage, png::image<png::rgb_pixel> {
public:
    PngImage(unsigned w, unsigned h);
    PngImage();
    ~PngImage() override;
    void FlipVert() override;
    void FlipHor() override;
};


#endif //IMAGE_HPP
