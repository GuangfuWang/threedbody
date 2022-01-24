
#ifndef INC_3DBODY_OPENGLCOLOREDVERTEXINDEXBUFFER_H
#define INC_3DBODY_OPENGLCOLOREDVERTEXINDEXBUFFER_H

#include "VertexIndexBufferBase.h"
#include "include/mesh/VertexHolderData/ColoredVertexHolder.h"

namespace gf{

    class OpenGL_ColoredVertexIndexBuffer final: public VertexIndexBufferBase{
    public:
        OpenGL_ColoredVertexIndexBuffer() : VertexIndexBufferBase() {}

        void createBuffers(VertexBuffer vertices,
                           IndexBuffer indices) override;

        void deleteBuffers() override;

        void bind() override;

        void unbind() override;

        void draw(int index_count) override;
    };

    class OpenGL_ColoredVertexIndexBufferWONormal final:public VertexIndexBufferBase{
    public:
        OpenGL_ColoredVertexIndexBufferWONormal() : VertexIndexBufferBase() {}

        void createBuffers(VertexBuffer vertices,
                           IndexBuffer indices) override;

        void deleteBuffers() override;

        void bind() override;

        void unbind() override;

        void draw(int index_count) override;
    };


}


#endif //INC_3DBODY_OPENGLCOLOREDVERTEXINDEXBUFFER_H
