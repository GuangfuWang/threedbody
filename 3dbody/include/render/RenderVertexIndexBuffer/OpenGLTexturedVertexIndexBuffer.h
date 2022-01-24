#ifndef INC_3DBODY_OPENGLTEXTUREDVERTEXINDEXBUFFER_H
#define INC_3DBODY_OPENGLTEXTUREDVERTEXINDEXBUFFER_H

#include "VertexIndexBufferBase.h"

namespace gf{

    class OpenGL_TexturedVertexIndexBuffer final :public VertexIndexBufferBase{
    public:
        OpenGL_TexturedVertexIndexBuffer() : VertexIndexBufferBase() {}

        void createBuffers(VertexBuffer vertices,
                           IndexBuffer indices) override;

        void deleteBuffers() override;

        void bind() override;

        void unbind() override;

        void draw(int index_count) override;
    };

    class OpenGL_TexturedVertexIndexBufferWONormal final :public VertexIndexBufferBase{
    public:
        OpenGL_TexturedVertexIndexBufferWONormal() : VertexIndexBufferBase() {}

        void createBuffers(VertexBuffer vertices,
                           IndexBuffer indices) override;

        void deleteBuffers() override;

        void bind() override;

        void unbind() override;

        void draw(int index_count) override;
    };

}

#endif //INC_3DBODY_OPENGLTEXTUREDVERTEXINDEXBUFFER_H
