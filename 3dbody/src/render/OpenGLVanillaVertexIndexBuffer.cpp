#ifndef GLEW_STATIC
#define GLEW_STATIC
#endif
#include <GL/glew.h>
#include "include/render/RenderVertexIndexBuffer/OpenGLVanillaVertexIndexBuffer.h"

namespace gf{
    void OpenGL_VanillaVertexIndexBuffer::createBuffers(VertexHolderBase* vertices,
                                                        RenderIndexType *indices) {
        glGenVertexArrays(1, &mVAO);

        glGenBuffers(1, &mIBO);
        glGenBuffers(1, &mVBO);

        glBindVertexArray(mVAO);

        glBindBuffer(GL_ARRAY_BUFFER, mVBO);
        glBufferData(GL_ARRAY_BUFFER, mVertexSize*sizeof(VanillaVertexHolder), vertices, GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, mIndexSize*sizeof(GLuint), indices, GL_STATIC_DRAW);

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VanillaVertexHolder), (void *)0);

        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(VanillaVertexHolder), (void *)offsetof(VanillaVertexHolder, mNormal));

        glBindVertexArray(0);

    }

    void OpenGL_VanillaVertexIndexBuffer::deleteBuffers() {
        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        glDeleteBuffers(1, &mIBO);
        glDeleteBuffers(1, &mVBO);
        glDeleteVertexArrays(1, &mVAO);
    }

    void OpenGL_VanillaVertexIndexBuffer::bind() {
        glBindVertexArray(mVAO);
    }

    void OpenGL_VanillaVertexIndexBuffer::unbind() {
        glBindVertexArray(0);
    }

    void OpenGL_VanillaVertexIndexBuffer::draw(int index_count) {
        bind();
        glDrawElements(GL_TRIANGLES, index_count, GL_UNSIGNED_INT, nullptr);
        unbind();
    }

    void OpenGL_VanillaVertexIndexBufferWONormal::createBuffers(VertexBuffer vertices, IndexBuffer indices) {

    }

    void OpenGL_VanillaVertexIndexBufferWONormal::deleteBuffers() {

    }

    void OpenGL_VanillaVertexIndexBufferWONormal::bind() {

    }

    void OpenGL_VanillaVertexIndexBufferWONormal::unbind() {

    }

    void OpenGL_VanillaVertexIndexBufferWONormal::draw(int index_count) {

    }
}