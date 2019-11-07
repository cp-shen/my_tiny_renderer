//
// Created by scp on 2019/11/7.
//

#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>
#include <my_tiny_renderer/Model.hpp>

class Scene {
public:
    Scene();
    virtual ~Scene();
    std::vector<Model> models;
};


#endif //SCENE_HPP
