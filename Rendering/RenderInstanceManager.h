#pragma once

#include "../Templates/Singleton.h"
#include <map>
#include <memory>

#include "Renderer.h"
#include "RaycastRenderer.h"

class RenderInstanceManager final : public Singleton<RenderInstanceManager>
{
private:
    //std::map<const char*, std::shared_ptr<GameRenderer>> _renderers;
    std::vector<std::shared_ptr<GameRenderer>> _renderers;

public:
    RenderInstanceManager(token);
    ~RenderInstanceManager();

    std::shared_ptr<GameRenderer> AddRenderer();

    std::shared_ptr<RaycastRenderer> AddRaycastRenderer();

    void RemoveRenderer();

    void ClearRenderers();

    std::shared_ptr<GameRenderer> GetRenderer(int index);
};