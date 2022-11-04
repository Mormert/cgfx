#pragma once

#include "jleGame.h"

class cgfx final : public jleGame
{
public:
    ~cgfx() override = default;

    void start() override;

    void update(float dt) override;
};