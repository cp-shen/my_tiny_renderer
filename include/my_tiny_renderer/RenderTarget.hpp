//
// Created by scp on 2019/11/7.
//

#ifndef RENDER_TARGET_HPP
#define RENDER_TARGET_HPP

#include <my_tiny_renderer/Camera.hpp>
#include <my_tiny_renderer/Scene.hpp>


class RenderTarget {
public:
    RenderTarget();
    virtual ~RenderTarget() = 0;
    virtual void Render(const Scene& scene, const Camera& camera) = 0;
};


#endif //RENDER_TARGET_HPP
