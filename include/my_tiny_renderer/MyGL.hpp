#ifndef MYGL_H
#define MYGL_H

#include <png++/png.hpp>
#include <glm/glm.hpp>

/**
 * \brief conataining static methods to draw
 */
class MyGL {
private:
    static void _DrawFlatTopTriangle(
            glm::vec2 t0,
            glm::vec2 t1,
            glm::vec2 t2,
            png::image<png::rgb_pixel>& image,
            png::rgb_pixel color
            );

    static void _DrawFlatBottomTriangle(
            glm::vec2 t0,
            glm::vec2 t1,
            glm::vec2 t2,
            png::image<png::rgb_pixel>& image,
            png::rgb_pixel color
            );
public:
    MyGL();
    virtual ~MyGL();
    /**
     * \brief draw a line using Bresenham's line algorithm
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
            png::rgb_pixel color
            );

    static void DrawLine(
            glm::vec2 v0,
            glm::vec2 v1,
            png::image<png::rgb_pixel>& image,
            png::rgb_pixel color
            );

    /**
     * \brief draw a triangle using top-left rasterization rule
     * \details
     * \param[in]  t0
     * \param[in]  t1
     * \param[in]  t2
     * \param[in]  image
     * \param[in]
     * \exception
     */
    static void DrawTriangle(
            glm::vec2 t0,
            glm::vec2 t1,
            glm::vec2 t2,
            png::image<png::rgb_pixel>& image,
            png::rgb_pixel color
            );

    //TODO: should not place this method here
    //TODO: support image types other than rgb_pixel
    static void FlipImageVert(png::image<png::rgb_pixel>& image);
    static void FlipImageHor(png::image<png::rgb_pixel>& image);

};

#endif /* MYGL_H */
