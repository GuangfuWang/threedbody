#ifndef INC_3DBODY_RENDER_BASE_H
#define INC_3DBODY_RENDER_BASE_H

#include "include/mesh/VertexHolderData/VanillaVertexHolder.h"

namespace gf {

    class VertexIndexBufferBase {
    public:
        VertexIndexBufferBase() : mVBO{0}, mVAO{0}, mIBO{0}, mVertexSize{0}, mIndexSize{0} {}

        virtual void
        createBuffers(VertexBuffer vertices, IndexBuffer indices) = 0;

        virtual void deleteBuffers() = 0;

        virtual void bind() = 0;

        virtual void unbind() = 0;

        virtual void draw(int index_count) = 0;

    protected:
        GLuint mVBO;
        GLuint mVAO;
        GLuint mIBO;

        GLuint mVertexSize;
        GLuint mIndexSize;
    };


}

#endif
