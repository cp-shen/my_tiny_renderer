//
// Created by scp on 2019/11/4.
//

#include <my_tiny_renderer/VertexDataSet.hpp>

VertexDataSet::VertexDataSet()
    : _data()
    , _vertexCount(0)
    , _attribSpecifier()
{

}

VertexDataSet::VertexDataSet(unsigned vertCount, float *data, unsigned size)
    : _data()
    , _vertexCount(vertCount)
    , _attribSpecifier()
{
    for(unsigned i = 0; i < size; i++) {
        _data.push_back(*data);
        data++;
    }
}


VertexDataSet::~VertexDataSet() = default;

unsigned VertexDataSet::GetVertexCount() const {
    return _vertexCount;
}

VertexAttribSpecifier& VertexDataSet::AttribSpecifier() {
    return _attribSpecifier;
}
