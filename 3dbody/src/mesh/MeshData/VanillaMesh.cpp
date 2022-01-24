#ifndef GLEW_STATIC
#define GLEW_STATIC
#endif

#include "GL/glew.h"

#include "include/mesh/MeshData/VanillaMesh.h"
#include "include/render/RenderVertexIndexBuffer/OpenGLVanillaVertexIndexBuffer.h"
#include "assimp/Importer.hpp"
#include "assimp/scene.h"

namespace gf {
    void VanillaMesh::init() {
        if (!inited) {
            mRenderBufferMgr = createUniqueRef<gf::OpenGL_VanillaVertexIndexBuffer>();
            inited = true;
        }
        createBuffers();
    }

    VanillaMesh::~VanillaMesh() {
        deleteBuffers();
    }

    bool VanillaMesh::load(const string &filepath) {
        Assimp::Importer Importer;
        const aiScene    *pScene = Importer.ReadFile(filepath.c_str(),
                                                     cMeshImportFlags);
        deleteData();

        if (pScene && pScene->HasMeshes()) {

            auto  *mesh        = pScene->mMeshes[0];
            float one_of_verts = (float) 1 / mesh->mNumVertices;

            VanillaVertexHolder *pointerVanillaMesh = MALLOC_BY_TYPE(mesh->mNumVertices, VanillaVertexHolder);
            mVertices = static_cast<VertexHolderBase *>(pointerVanillaMesh);

            for (uint32_t i = 0; i < mesh->mNumVertices; i++) {
                VanillaVertexHolder vh;
                vh.mPos    = {mesh->mVertices[i].x, mesh->mVertices[i].y, mesh->mVertices[i].z};
                vh.mNormal = {mesh->mNormals[i].x, mesh->mNormals[i].y, mesh->mNormals[i].z};

                addVertex(vh);

                sceneCenter.x += (float) mesh->mVertices[i].x * one_of_verts;
                sceneCenter.y += (float) mesh->mVertices[i].y * one_of_verts;
                sceneCenter.z += (float) mesh->mVertices[i].z * one_of_verts;

                sceneMinBox.x = std::min(mesh->mVertices[i].x, sceneMinBox.x);
                sceneMinBox.y = std::min(mesh->mVertices[i].y, sceneMinBox.x);
                sceneMinBox.z = std::min(mesh->mVertices[i].z, sceneMinBox.x);

                sceneMaxBox.x = std::max(mesh->mVertices[i].x, sceneMaxBox.x);
                sceneMaxBox.y = std::max(mesh->mVertices[i].y, sceneMaxBox.x);
                sceneMaxBox.z = std::max(mesh->mVertices[i].z, sceneMaxBox.x);
            }

            for (size_t i = 0; i < mesh->mNumFaces; i++) {
                aiFace face = mesh->mFaces[i];

                for (size_t j = 0; j < face.mNumIndices; j++)
                    addVertexIndex(face.mIndices[j]);
            }

            init();
            return true;
        }
        return false;
    }

    void VanillaMesh::createBuffers() {
        mRenderBufferMgr->createBuffers(mVertices, mIndices);
    }

    void VanillaMesh::deleteBuffers() {
        mRenderBufferMgr->deleteBuffers();
    }

    void VanillaMesh::bind() {
        mRenderBufferMgr->bind();
    }

    void VanillaMesh::unbind() {
        mRenderBufferMgr->unbind();
    }

    void VanillaMesh::render() {
        mRenderBufferMgr->draw((int) mIndexSize);
    }

    void VanillaMesh::deleteData() {
        if (mVertexSize > 0) {
            mVertexSize = 0;
            mIndexSize  = 0;
            if (mVertices) {
                free(mVertices);
                mVertices = NULL;
            }
            if (mIndices) {
                free(mIndices);
                mIndices = NULL;
            }
        }
    }
}

