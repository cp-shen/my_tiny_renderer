#include <catch2/catch.hpp>
#include <my_tiny_renderer/Color.hpp>
#include <my_tiny_renderer/MyGL.hpp>
#include <tinyobjloader-1.0.7/tiny_obj_loader.h>

TEST_CASE("draw_human_head")
{
    const int image_height = 512;
    const int image_width = 512;

    png::image<png::rgb_pixel> image(image_width, image_height);
    png::rgb_pixel pixel_white(255, 255, 255);

    std::string inputfile = "models/african_head/african_head.obj";
    tinyobj::attrib_t attrib;
    std::vector<tinyobj::shape_t> shapes;
    std::vector<tinyobj::material_t> materials;

    std::string warn;
    std::string err;

    bool ret = tinyobj::LoadObj(&attrib, &shapes, &materials, &warn, &err,
                                inputfile.c_str());

    if (!warn.empty()) {
        std::cout << warn << std::endl;
    }

    if (!err.empty()) {
        std::cerr << err << std::endl;
    }

    assert(ret == true); // obj loading success

    SECTION("draw_wireframe")
    {
        const char* image_name = "human_head_wireframe.png";
        // Loop over shapes
        for (size_t s = 0; s < shapes.size(); s++) {
            // Loop over faces(polygon)
            size_t index_offset = 0;
            for (size_t f = 0; f < shapes[s].mesh.num_face_vertices.size(); f++) {
                int fv = shapes[s].mesh.num_face_vertices[f];

                // Loop over vertices in the face.
                for (size_t v = 0; v < fv; v++) {
                    // access to vertex
                    tinyobj::index_t idx = shapes[s].mesh.indices[index_offset + v];
                    tinyobj::real_t vx0 = attrib.vertices[3 * idx.vertex_index + 0];
                    tinyobj::real_t vy0 = attrib.vertices[3 * idx.vertex_index + 1];

                    tinyobj::index_t idx_next =
                        shapes[s].mesh.indices[index_offset + (v + 1) % fv];
                    tinyobj::real_t vx1 = attrib.vertices[3 * idx_next.vertex_index + 0];
                    tinyobj::real_t vy1 = attrib.vertices[3 * idx_next.vertex_index + 1];

                    int x0 = (vx0 + 1.) * (image_width / 2. - 1.);
                    int y0 = (vy0 + 1.) * (image_height / 2. - 1.);
                    int x1 = (vx1 + 1.) * (image_width / 2. - 1.);
                    int y1 = (vy1 + 1.) * (image_height / 2. - 1.);

                    REQUIRE(x0 >= 0);
                    REQUIRE(x0 < image_width);
                    REQUIRE(y0 >= 0);
                    REQUIRE(y0 < image_height);

                    REQUIRE(x1 >= 0);
                    REQUIRE(x1 < image_width);
                    REQUIRE(y1 >= 0);
                    REQUIRE(y1 < image_height);

                    // Draw Wireframe
                    REQUIRE_NOTHROW(MyGL::DrawLine(x0, y0, x1, y1, image, pixel_white));
                }
                index_offset += fv;
            }
        }
        MyGL::FlipImageVert(image);
        image.write(image_name);
    }

    SECTION("draw_with_rand_color")
    {
        const char* image_name = "human_head_rand_color.png";
        // Loop over shapes
        for (size_t s = 0; s < shapes.size(); s++) {
            // Loop over faces(polygon)
            size_t index_offset = 0;
            for (size_t f = 0; f < shapes[s].mesh.num_face_vertices.size(); f++) {
                int fv = shapes[s].mesh.num_face_vertices[f];

                // load tiangle vetex data
                tinyobj::index_t idx_0 = shapes[s].mesh.indices[index_offset + 0];
                tinyobj::index_t idx_1 = shapes[s].mesh.indices[index_offset + 1];
                tinyobj::index_t idx_2 = shapes[s].mesh.indices[index_offset + 2];

                tinyobj::real_t vx0 = attrib.vertices[3 * idx_0.vertex_index + 0];
                tinyobj::real_t vy0 = attrib.vertices[3 * idx_0.vertex_index + 1];
                tinyobj::real_t vx1 = attrib.vertices[3 * idx_1.vertex_index + 0];
                tinyobj::real_t vy1 = attrib.vertices[3 * idx_1.vertex_index + 1];
                tinyobj::real_t vx2 = attrib.vertices[3 * idx_2.vertex_index + 0];
                tinyobj::real_t vy2 = attrib.vertices[3 * idx_2.vertex_index + 1];

                float x0 = (vx0 + 1.) * (image_width / 2. - 1.);
                float y0 = (vy0 + 1.) * (image_height / 2. - 1.);
                float x1 = (vx1 + 1.) * (image_width / 2. - 1.);
                float y1 = (vy1 + 1.) * (image_height / 2. - 1.);
                float x2 = (vx2 + 1.) * (image_width / 2. - 1.);
                float y2 = (vy2 + 1.) * (image_height / 2. - 1.);

                REQUIRE(x0 >= 0);
                REQUIRE(x0 < image_width);
                REQUIRE(y0 >= 0);
                REQUIRE(y0 < image_height);

                REQUIRE(x1 >= 0);
                REQUIRE(x1 < image_width);
                REQUIRE(y1 >= 0);
                REQUIRE(y1 < image_height);

                REQUIRE(x2 >= 0);
                REQUIRE(x2 < image_width);
                REQUIRE(y2 >= 0);
                REQUIRE(y2 < image_height);

                glm::vec2 t0, t1, t2;
                t0 = {x0, y0};
                t1 = {x1, y1};
                t2 = {x2, y2};

                png::rgb_pixel pixel (rand() % 255, rand() % 255, rand() % 255);
                REQUIRE_NOTHROW(MyGL::DrawTriangle(t0, t1, t2, image, pixel));
                index_offset += fv;
            }
        }
        MyGL::FlipImageVert(image);
        image.write(image_name);
    }
}
