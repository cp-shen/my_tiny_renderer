#include <catch2/catch.hpp>
#include <external/tinyobjloader-1.0.7/tiny_obj_loader.h>
#include <my_tiny_renderer/MyGL.hpp>

TEST_CASE("Draw Wireframe")
{
    const char* filename = "test_draw_wireframe.png";
    const int image_height = 800;
    const int image_width = 800;

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

    if (!ret) {
        exit(1);
    }

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

                int x0 = (vx0 + 1.) * image_width / 2.;
                int y0 = (vy0 + 1.) * image_height / 2.;
                int x1 = (vx1 + 1.) * image_width / 2.;
                int y1 = (vy1 + 1.) * image_height / 2.;

                REQUIRE((x0 >= 0 && x0 < image_width));
                REQUIRE((y0 >= 0 && y0 < image_height));

                REQUIRE((x1 >= 0 && x1 < image_width));
                REQUIRE((y1 >= 0 && y1 < image_height));

                // Draw Wireframe
                REQUIRE_NOTHROW(MyGL::DrawLine(x0, y0, x1, y1, image, pixel_white));
            }
            index_offset += fv;

            // per-face material
            // shapes[s].mesh.material_ids[f];
        }
    }

    image.write(filename);
}
