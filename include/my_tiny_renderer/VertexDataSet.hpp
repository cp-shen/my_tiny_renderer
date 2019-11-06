//
// Created by scp on 2019/11/4.
//

#ifndef VERTEX_GROUP_HPP
#define VERTEX_GROUP_HPP

#include <my_tiny_renderer/Math.hpp>
#include <my_tiny_renderer/VertexAttribSpecifier.hpp>
#include <vector>
#include <map>

class VertexDataSet {
    std::vector<float> data;
    unsigned vertexCount;
    VertexAttribSpecifier attribSpecifier;
};


#endif //VERTEX_GROUP_HPP
