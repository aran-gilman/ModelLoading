#include "MeshData.h"

#include "VectorConstants.h"

MeshData CreateQuad()
{
    using namespace constants;

    MeshData mesh;
    mesh.vertices = {
        {{  0.5f,  0.5f, 0.0f }, vec3::Forward, vec2::One },  // top right
        {{  0.5f, -0.5f, 0.0f }, vec3::Forward, vec2::Right },  // bottom right
        {{ -0.5f, -0.5f, 0.0f }, vec3::Forward, vec2::Zero },  // bottom left
        {{ -0.5f,  0.5f, 0.0f }, vec3::Forward, vec2::Up },  // top left 
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
    using namespace constants::vec3;

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
        {f, Forward},
        {h, Forward},
        {g, Forward},
        {e, Forward},

        // Right
        {b, Right},
        {d, Right},
        {h, Right},
        {f, Right},

        // Back
        {a, Back},
        {c, Back},
        {d, Back},
        {b, Back},

        // Left
        {e, Left},
        {g, Left},
        {c, Left},
        {a, Left},

        // Top
        {b, Up},
        {f, Up},
        {e, Up},
        {a, Up},

        // Bottom
        {h, Down},
        {d, Down},
        {c, Down},
        {g, Down},
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
