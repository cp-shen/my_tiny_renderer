//
// Created by scp on 2019/11/7.
//

#include "my_tiny_renderer/Image.hpp"

IImage::IImage() = default;

IImage::~IImage() = default;

PngImage::PngImage() = default;

PngImage::PngImage(unsigned w, unsigned h)
    : IImage()
    , png::image<png::rgb_pixel>(w, h)
{ }

PngImage::~PngImage() = default;


void PngImage::FlipVert() {
    for (size_t row_idx = 0; row_idx < get_height() / 2; row_idx++) {
        size_t row_idx2 = get_height() - row_idx - 1;

        auto& buf = get_pixbuf();
        auto tmp = buf.get_row(row_idx);

        buf.put_row(row_idx, buf.get_row(row_idx2));
        buf.put_row(row_idx2, tmp);
    }
}

void PngImage::FlipHor() {
    for (size_t row = 0; row < get_height(); row++) {
        for (size_t col = 0; col < get_width() / 2; col++) {
            size_t col_to_swap = get_width() - col - 1;
            auto tmp = this[row][col];
            this[row][col] = this[row][col_to_swap];
            this[row][col_to_swap] = tmp;
        }
    }
}
