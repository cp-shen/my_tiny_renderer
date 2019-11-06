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
    std::vector<float> _data;
    unsigned _vertexCount;
    VertexAttribSpecifier _attribSpecifier;

public:
    VertexDataSet(unsigned vertCount, float *data, unsigned size);

    VertexDataSet();

    ~VertexDataSet();

    unsigned GetVertexCount() const;

    VertexAttribSpecifier& AttribSpecifier();
};


#endif //VERTEX_GROUP_HPP
