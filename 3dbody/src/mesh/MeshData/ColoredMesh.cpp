#include "include/mesh/MeshData/ColoredMesh.h"
#include "include/render/RenderVertexIndexBuffer/OpenGLColoredVertexIndexBuffer.h"

namespace gf {

    bool ColoredMesh::load(const string &filepath) {
        return MeshBase::load(filepath);
    }

    void ColoredMesh::update(Shader *shader) {
        MeshBase::update(shader);
    }

    void ColoredMesh::init() {
        if (!inited) {
            mRenderBufferMgr = createUniqueRef<OpenGL_ColoredVertexIndexBuffer>();
            inited = true;
        }
        createBuffers();
    }

    void ColoredMesh::createBuffers() {
        mRenderBufferMgr->createBuffers(mVertices,mIndices);
    }

    ColoredMesh::~ColoredMesh() {
        deleteBuffers();
    }

    void ColoredMesh::deleteBuffers() {
        if (mRenderBufferMgr){
            mRenderBufferMgr->deleteBuffers();
        }
    }
}
