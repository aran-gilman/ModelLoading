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

MeshData CreateCube()
{
    MeshData mesh;
    mesh.vertices = {
        {{  0.5f,  0.5f, 0.5f }},
        {{  0.5f, -0.5f, 0.5f }},
        {{ -0.5f, -0.5f, 0.5f }},
        {{ -0.5f,  0.5f, 0.5f }},
    };
    mesh.indices = {   
        0, 1, 3,
        1, 2, 3,
    };
    return mesh;
}
