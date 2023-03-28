#ifndef CGFX_CSINEWAVE_H
#define CGFX_CSINEWAVE_H

#pragma once

#include "jleComponent.h"
#include "jleMaterial.h"
#include "jleMesh.h"
#include "jleTransform.h"

#include "jleResourceRef.h"

#include <chrono>

class cSineWave : public jleComponent
{
    JLE_REGISTER_COMPONENT_TYPE(cSineWave)
public:
    explicit cSineWave(jleObject *owner = nullptr, jleScene *scene = nullptr) : jleComponent(owner, scene) {}

    template <class Archive>
    void
    serialize(Archive &ar)
    {
        ar(CEREAL_NVP(_magnitudeY), CEREAL_NVP(_position), CEREAL_NVP(_speed));
    }

    void editorUpdate(float dt) override{};

    void start() override{};

    void
    update(float dt) override
    {
        _counter += dt;
        _attachedToObject->getTransform().setLocalPosition(_position +
                                                           glm::vec3{0.f, _magnitudeY * sin(_speed * _counter), 0.f});
    };

protected:
    float _counter{};
    float _magnitudeY{};
    float _speed{};
    glm::vec3 _position{};
};

CEREAL_REGISTER_TYPE(cSineWave)
CEREAL_REGISTER_POLYMORPHIC_RELATION(jleComponent, cSineWave)

#endif // CGFX_CSINEWAVE_H
