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

        // Right
        {b},
        {d},
        {h},
        {f},

        // Back
        {a},
        {c},
        {d},
        {b},

        // Left
        {e},
        {g},
        {c},
        {a},

        // Top
        {b},
        {f},
        {e},
        {a},

        // Bottom
        {h},
        {d},
        {c},
        {g},
    };

    mesh.indices = {
        // Front
        0, 1, 3,
        1, 2, 3,

        // Right
        4, 5, 7,
        5, 6, 7,

        // Back
        8, 9, 11,
        9, 10, 11,

        // Left
        12, 13, 15,
        13, 14, 15,

        // Top
        16, 17, 19,
        17, 18, 19,

        // Bottom
        20, 21, 23,
        21, 22, 23,
    };
    return mesh;
}
