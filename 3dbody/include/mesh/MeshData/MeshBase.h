#ifndef INC_3DBODY_MESHBASE_H
#define INC_3DBODY_MESHBASE_H

#include "def.h"
#include "include/event_handling/ModelChangeInterface.h"
#include "include/render/RenderVertexIndexBuffer/VertexIndexBufferBase.h"

namespace gf {

    class MeshBase : public ModelChangeInterface {
    public:
        void update(Shader *shader) override {
            shader->setF1(mRoughness, "roughness");
            shader->setF1(mMetallic, "metallic");
            shader->setF1(1.0f, "ao");
        }

        virtual bool load(const std::string &filepath) {}

        virtual ~MeshBase() = default;

    public:
        Vec                                sceneCenter = {0.0f, 0.0f, 0.0f};
        Vec                                sceneMinBox = {std::numeric_limits<float>::max(),
                                                          std::numeric_limits<float>::max(),
                                                          std::numeric_limits<float>::max()};
        Vec                                sceneMaxBox = {std::numeric_limits<float>::min(),
                                                          std::numeric_limits<float>::min(),
                                                          std::numeric_limits<float>::min()};
        float                              mRoughness  = 0.2f;
        float                              mMetallic   = 0.1f;
        Ref_Unique <VertexIndexBufferBase> mRenderBufferMgr;
        VertexBuffer                       mVertices;
        IndexBuffer                        mIndices;
        unsigned int                       mVertexSize;
        unsigned int                       mIndexSize;
    };

}


#endif //INC_3DBODY_MESHBASE_H
