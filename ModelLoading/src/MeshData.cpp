#include "MeshData.h"

MeshData CreateQuad()
{
    MeshData mesh;
    mesh.vertices = {
        {{  0.5f,  0.5f, 0.0f }},  // top right
        {{  0.5f, -0.5f, 0.0f }},  // bottom right
        {{ -0.5f, -0.5f, 0.0f }},  // bottom left
        {{ -0.5f,  0.5f, 0.0f }},  // top left 
    };
    mesh.indices = {
        0, 1, 3,
        1, 2, 3,
    };
    return mesh;
}

/*
*
*  a - - - - - b
*   | \     | \
*   | e - - - - - f
*   |   |   |   |
* c - - | - - d |
*     \ |     \ |
*     g - - - - - h
*
*   ASCII art generated with https://1j01.github.io/ascii-hypercube/
*/
MeshData CreateCube()
{
    glm::vec3 a{ -0.5f,  0.5f, -0.5f };
    glm::vec3 b{  0.5f,  0.5f, -0.5f };
    glm::vec3 c{ -0.5f, -0.5f, -0.5f };
    glm::vec3 d{  0.5f, -0.5f, -0.5f };

    glm::vec3 e{ -0.5f,  0.5f,  0.5f };
    glm::vec3 f{  0.5f,  0.5f,  0.5f };
    glm::vec3 g{ -0.5f, -0.5f,  0.5f };
    glm::vec3 h{  0.5f, -0.5f,  0.5f };

    MeshData mesh;
    mesh.vertices = {
        // Front
        {f},
        {h},
        {g},
        {e},
    };
    mesh.indices = {   
        0, 1, 3,
        1, 2, 3,
    };
    return mesh;
}
