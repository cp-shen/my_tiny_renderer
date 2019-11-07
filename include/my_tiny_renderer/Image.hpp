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

class PngImage : public IImage, public png::image<png::rgb_pixel> {
public:
    PngImage(unsigned w, unsigned h);
    explicit PngImage(const char* filePath);
    PngImage();
    ~PngImage() override;
    void FlipVert() override;
    void FlipHor() override;
};


#endif //IMAGE_HPP
