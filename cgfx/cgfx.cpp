#include "cgfx.h"

#include "jleGameEngine.h"
#include "jleRendering.h"

#include <glm/ext/matrix_transform.hpp>

#include <random>

void
cgfx::start()
{

    _pbrCube = makePbrCube();

    generateCubePositions();
    loadScene<jleScene>(GAME_RESOURCES_DIRECTORY + "/scenes/scene.scn");
}

void
cgfx::update(float dt)
{
    if (gCore->input().keyboard->keyPressed('Q')) {
        generateCubePositions();
    }

    for (auto &&cube : _staticCubes) {
        // gEngine->rendering().rendering3d().sendExampleCube(cube);
    }

    auto model = glm::mat4{1.f};
    model = glm::translate(model, glm::vec3{200, 0, 0});
    model = glm::scale(model, glm::vec3{25.f});

    gEngine->rendering().rendering3d().sendMesh(_pbrCube, model, INT32_MAX);
}
void
cgfx::generateCubePositions()

{
    _staticCubes.clear();

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
}
std::shared_ptr<jleMesh>
cgfx::makePbrCube()
{
    // clang-format off
    const std::vector<float> positions = {
        // A cube has 8 vertices, but we have three copies of each one to account for normals:
        -0.5, -0.5, -0.5,  //0 0
        -0.5, -0.5, -0.5,  //0 1
        -0.5, -0.5, -0.5,  //0 2
        //
        -0.5, -0.5,  0.5,  //1 3
        -0.5, -0.5,  0.5,  //1 4
        -0.5, -0.5,  0.5,  //1 5
        //
        -0.5,  0.5, -0.5,  //2 6
        -0.5,  0.5, -0.5,  //2 7
        -0.5,  0.5, -0.5,  //2 8
        //
        -0.5,  0.5,  0.5,  //3 9
        -0.5,  0.5,  0.5,  //3 10
        -0.5,  0.5,  0.5,  //3 11
        //
        0.5, -0.5, -0.5,  //4 12
        0.5, -0.5, -0.5,  //4 13
        0.5, -0.5, -0.5,  //4 14
        //
        0.5, -0.5,  0.5,  //5 15
        0.5, -0.5,  0.5,  //5 16
        0.5, -0.5,  0.5,  //5 17
        //
        0.5,  0.5, -0.5,  //6 18
        0.5,  0.5, -0.5,  //6 19
        0.5,  0.5, -0.5,  //6 20
        //
        0.5,  0.5,  0.5,  //7 21
        0.5,  0.5,  0.5,  //7 22
        0.5,  0.5,  0.5,  //7 23
    };

    const std::vector<unsigned int> faces = {
        // ... and 12 triangular faces,
        // defined by the following vertex indices:
        0, 9, 6, // 0 3 2
        0, 3, 9, // 0 1 3
        //
        1, 7, 18, // 0 2 6
        1, 18, 12, // 0 6 4
        //
        13, 19, 15, // 4 6 5
        15, 19, 21, // 5 6 7
        //
        16, 22, 10, // 5 7 3
        16, 10, 4, // 5 3 1
        //
        8, 11, 23, // 2 3 7
        8, 23, 20, // 2 7 6
        //
        2, 14, 5, // 0 4 1
        5, 14, 17 // 1 4 5
    };
    // clang-format on

    // Dynamically calculate the normals for the cube.
    // Add them to a normals map based on index, such
    // that all vertex points gets the correct normal.

    std::map<unsigned int, glm::vec3> normalsMap;

    for (int i = 0; i < faces.size(); i += 3) {
        auto a = faces[i];
        auto b = faces[i + 1];
        auto c = faces[i + 2];
        // Fetch the points from the positions vector
        glm::vec3 p1 = {positions[a * 3 + 0], positions[a * 3 + 1], positions[a * 3 + 2]};
        glm::vec3 p2 = {positions[b * 3 + 0], positions[b * 3 + 1], positions[b * 3 + 2]};
        glm::vec3 p3 = {positions[c * 3 + 0], positions[c * 3 + 1], positions[c * 3 + 2]};
        auto normal = glm::cross(p2 - p1, p3 - p1);
        normalsMap[a] = normal;
        normalsMap[b] = normal;
        normalsMap[c] = normal;
    }

    // Push the normal vectors into a vector of floats
    std::vector<float> normals;
    for (auto &&normal : normalsMap) {
        normals.push_back(normal.second.x);
        normals.push_back(normal.second.y);
        normals.push_back(normal.second.z);
    }

    auto cube = std::make_shared<jleMesh>();

    cube->makeMesh(positions, normals, {}, faces);

    return cube;
}
