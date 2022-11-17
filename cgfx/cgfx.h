#pragma once

#include "jleGame.h"
#include "jleMesh.h"

class cgfx final : public jleGame
{
public:
    ~cgfx() override = default;

    void start() override;

    void update(float dt) override;

private:
    void generateCubePositions();

    std::shared_ptr<jleMesh> _pbrCube;
    std::shared_ptr<jleMesh> makePbrCube();

    std::vector<glm::mat4> _staticCubes;
};