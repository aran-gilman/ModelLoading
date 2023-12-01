#include "MeshData.h"

#include <format>
#include <stdexcept>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "VectorConstants.h"

namespace
{
    MeshData ToMeshData(aiMesh* mesh, const aiScene* scene)
    {
        MeshData meshData;
        for (unsigned int i = 0; i < mesh->mNumVertices; i++)
        {
            auto position = mesh->mVertices[i];
            auto normals = mesh->mNormals[i];
            meshData.vertices.push_back({
                {position.x, position.y, position.z},
                {normals.x, normals.y, normals.z}});
        }
        for (unsigned int i = 0; i < mesh->mNumFaces; i++)
        {
            aiFace face = mesh->mFaces[i];
            meshData.indices.insert(
                meshData.indices.end(),
                face.mIndices,
                face.mIndices + face.mNumIndices);
        }
        return meshData;
    }

    Model ProcessNode(aiNode* node, const aiScene* scene)
    {
        Model model;
        for (unsigned int i = 0; i < node->mNumMeshes; i++)
        {
            aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
            model.meshData.push_back(ToMeshData(mesh, scene));
        }
        for (unsigned int i = 0; i < node->mNumChildren; i++)
        {
            model.children.push_back(ProcessNode(node->mChildren[i], scene));
        }
        return model;
    }
}

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

Model LoadModel(const std::string& path)
{
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile(
        path,
        aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_GenNormals);
    if (scene == nullptr || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || scene->mRootNode == nullptr)
    {
        throw std::runtime_error(std::format("Failed to load model: {}", importer.GetErrorString()));
    }
    return ProcessNode(scene->mRootNode, scene);
}
