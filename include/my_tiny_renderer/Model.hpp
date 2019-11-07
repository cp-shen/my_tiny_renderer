//
// Created by scp on 2019/11/7.
//

#ifndef MODEL_HPP
#define MODEL_HPP

#include <my_tiny_renderer/VertexDataSet.hpp>
#include <my_tiny_renderer/Transform.hpp>

class Model {
public:
    Model();
    virtual ~Model();

    Transform transform;
    VertexDataSet vertexData;
    std::vector<unsigned> indexData;
    //TODO: add materials
};


#endif //MODEL_HPP
