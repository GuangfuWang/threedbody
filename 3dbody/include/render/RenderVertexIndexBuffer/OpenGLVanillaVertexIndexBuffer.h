#ifndef INC_3DBODY_OPENGLVANILLAVERTEXINDEXBUFFER_H
#define INC_3DBODY_OPENGLVANILLAVERTEXINDEXBUFFER_H

#include "VertexIndexBufferBase.h"

namespace gf {

    class OpenGL_VanillaVertexIndexBuffer final : public VertexIndexBufferBase {
    public:
        OpenGL_VanillaVertexIndexBuffer() : VertexIndexBufferBase() {}

        void createBuffers(VertexBuffer vertices,
                           IndexBuffer indices) override;

        void deleteBuffers() override;

        void bind() override;

        void unbind() override;

        void draw(int index_count) override;

    };

    class OpenGL_VanillaVertexIndexBufferWONormal final : public VertexIndexBufferBase {
    public:
        OpenGL_VanillaVertexIndexBufferWONormal() : VertexIndexBufferBase() {}

        void createBuffers(VertexBuffer vertices,
                           IndexBuffer indices) override;

        void deleteBuffers() override;

        void bind() override;

        void unbind() override;

        void draw(int index_count) override;

    };


}


#endif //INC_3DBODY_OPENGLVANILLAVERTEXINDEXBUFFER_H
