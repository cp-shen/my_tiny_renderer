#ifndef MY_GL_HPP
#define MY_GL_HPP

#include <png++/png.hpp>
#include <glm/glm.hpp>

/**
 * \brief containing static methods to draw
 */
class MyGL {
private:
    MyGL();
    virtual ~MyGL();
public:
    /**
     * \brief draw a line using Bresenham's line algorithm
     * \param[in]  x0
     * \param[in]  y0
     * \param[in]  x1
     * \param[in]  y1
     * \param[in]  image
     * \param[in]  color
     * \exception
     * TODO: implement diamond exit rule
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
     * \brief draw a triangle using line-sweeping method and
     *   top-left rasterization rule
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

#endif /* MY_GL_HPP */
