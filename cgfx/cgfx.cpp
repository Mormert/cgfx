#include "cgfx.h"

#include "jleGameEngine.h"
#include "jleRendering.h"

#include <glm/ext/matrix_transform.hpp>

#include <random>

void
cgfx::start()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrTrans(-2500.f, 2500.f);
    std::uniform_int_distribution<> distrScale(5.f, 15.f);
    std::uniform_int_distribution<> distrRot(-90.f, 90.f);

    // Creates cubes with some random position, scale and rotation!
    for (int i = 0; i < 25000; i++) {
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3{distrTrans(gen), distrTrans(gen), distrTrans(gen)});
        model = glm::scale(model, glm::vec3((float)distrScale(gen), (float)distrScale(gen), (float)distrScale(gen)));
        model = glm::rotate(model, (float)distrRot(gen), glm::vec3{1.0f, 0.f, 0.f});
        model = glm::rotate(model, (float)distrRot(gen), glm::vec3{0.0f, 1.f, 0.f});
        model = glm::rotate(model, (float)distrRot(gen), glm::vec3{0.0f, 0.f, 1.f});
        _staticCubes.push_back(model);
    }

    loadScene<jleScene>(GAME_RESOURCES_DIRECTORY + "/scenes/scene.scn");
}

void
cgfx::update(float dt)
{
    for (auto &&cube : _staticCubes) {
        gEngine->rendering().rendering3d().sendExampleCube(cube);
    }
}
