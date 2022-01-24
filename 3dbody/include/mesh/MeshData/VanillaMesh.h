#ifndef INC_3DBODY_3DBODY_INCLUDE_MESH_MESH_H_
#define INC_3DBODY_3DBODY_INCLUDE_MESH_MESH_H_

#include "assimp/postprocess.h"
#include "include/scene/SceneCamera.h"
#include "include/mesh/VertexHolderData/VanillaVertexHolder.h"
#include "include/render/RenderVertexIndexBuffer/VertexIndexBufferBase.h"
#include "def.h"
#include "include/mesh/MeshData/MeshBase.h"

namespace gf {

    class VanillaMesh : public MeshBase {
    public:
        VanillaMesh() = default;

        virtual ~VanillaMesh();

        bool load(const string &filepath) override;

        void addVertex(VertexHolderBase vertex) { mVertices[mVertexSize++] = vertex; }

        void addVertexIndex(RenderIndexType vertex_idx) { mIndices[mIndexSize++] = vertex_idx; }

        IndexBuffer getVertexIndices() { return mIndices; }

        void update(Shader *shader) override {
            shader->setVec3(mColor, "albedo");
            shader->setF1(mRoughness, "roughness");
            shader->setF1(mMetallic, "metallic");
            shader->setF1(1.0f, "ao");
        }

        void init();

        void createBuffers();

        void deleteBuffers();

        void render();

        void bind();

        void unbind();

        Vec mColor = {1.0f, 0.0f, 0.0f};
    private:
        void deleteData();

    private:
        bool           inited           = false;
        const uint32_t cMeshImportFlags =
                               aiProcess_CalcTangentSpace |
                               aiProcess_Triangulate |
                               aiProcess_SortByPType |
                               aiProcess_GenNormals |
                               aiProcess_GenUVCoords |
                               aiProcess_OptimizeMeshes |
                               aiProcess_ValidateDataStructure;

    };

}

#endif //INC_3DBODY_3DBODY_INCLUDE_MESH_MESH_H_
