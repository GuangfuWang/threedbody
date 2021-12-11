#ifndef GLEW_STATIC
#define GLEW_STATIC
#endif
#include <GL/glew.h>
#include "include/render/VertexIndexBuffer.h"

namespace gf {
void OpenGL_VertexIndexBuffer::createBuffers(const std::vector<VertexHolder> &vertices,
											 const std::vector<unsigned int> &indices) {
  glGenVertexArrays(1, &mVAO);

  glGenBuffers(1, &mIBO);
  glGenBuffers(1, &mVBO);

  glBindVertexArray(mVAO);

  glBindBuffer(GL_ARRAY_BUFFER, mVBO);
  glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(VertexHolder), vertices.data(), GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size()*sizeof(GLuint), indices.data(), GL_STATIC_DRAW);

  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexHolder), (void *)0);

  glEnableVertexAttribArray(1);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(VertexHolder), (void *)offsetof(VertexHolder, mNormal));

  glBindVertexArray(0);

}

void OpenGL_VertexIndexBuffer::deleteBuffers() {
  glDisableVertexAttribArray(0);
  glDisableVertexAttribArray(1);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
  glDeleteBuffers(1, &mIBO);
  glDeleteBuffers(1, &mVBO);
  glDeleteVertexArrays(1, &mVAO);
}

void OpenGL_VertexIndexBuffer::bind() {
  glBindVertexArray(mVAO);
}

void OpenGL_VertexIndexBuffer::unbind() {
  glBindVertexArray(0);
}

void OpenGL_VertexIndexBuffer::draw(int index_count) {
  bind();
  // the vertices as line loop
  glDrawElements(GL_TRIANGLES, index_count, GL_UNSIGNED_INT, nullptr);

  unbind();
}

}