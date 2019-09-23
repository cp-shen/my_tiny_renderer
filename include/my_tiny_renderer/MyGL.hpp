#ifndef MYGL_H
#define MYGL_H

#include <png++/png.hpp>

/**
 * \brief conataining static methods to draw
 */
class MyGL {
private:
public:
    MyGL();
    virtual ~MyGL();
    /**
     * \brief
     * \param[in]  x0
     * \param[in]  y0
     * \param[in]  x1
     * \param[in]  y1
     * \param[in]  image
     * \param[in]  color
     * \exception
     */
    static void DrawLine(
            int x0,
            int y0,
            int x1,
            int y1,
            png::image<png::rgb_pixel>& image,
            png::rgb_pixel& color
            );

    //TODO: should not place this method here
    //TODO: support image types other than rgb_pixel
    static void FlipImageVert(png::image<png::rgb_pixel>& image);
};

#endif /* MYGL_H */
