#include "Model.h"

#include <format>
#include <stdexcept>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

namespace
{
    Mesh ConvertMesh(aiMesh* externalMesh, const aiScene* scene)
    {
        Mesh mesh;
        for (unsigned int i = 0; i < externalMesh->mNumVertices; i++)
        {
            auto position = externalMesh->mVertices[i];
            auto normals = externalMesh->mNormals[i];
            auto uvs = externalMesh->mTextureCoords[0][i];
            mesh.meshData.vertices.push_back({
                {position.x, position.y, position.z},
                {normals.x, normals.y, normals.z},
                {uvs.x, uvs.y} });
        }
        for (unsigned int i = 0; i < externalMesh->mNumFaces; i++)
        {
            aiFace face = externalMesh->mFaces[i];
            mesh.meshData.indices.insert(
                mesh.meshData.indices.end(),
                face.mIndices,
                face.mIndices + face.mNumIndices);
        }
        if (externalMesh->mMaterialIndex >= 0)
        {
            aiMaterial* material = scene->mMaterials[externalMesh->mMaterialIndex];
            aiString path;
            material->GetTexture(aiTextureType_DIFFUSE, 0, &path);
            mesh.texturePath = path.C_Str();
        }
        return mesh;
    }

    Model ProcessNode(aiNode* node, const aiScene* scene)
    {
        Model model;
        for (unsigned int i = 0; i < node->mNumMeshes; i++)
        {
            aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
            model.meshes.push_back(ConvertMesh(mesh, scene));
        }
        for (unsigned int i = 0; i < node->mNumChildren; i++)
        {
            model.children.push_back(ProcessNode(node->mChildren[i], scene));
        }
        return model;
    }
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
