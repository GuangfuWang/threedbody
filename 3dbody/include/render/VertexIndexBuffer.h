#ifndef INC_3DBODY_RENDER_BASE_H
#define INC_3DBODY_RENDER_BASE_H

#include "include/mesh/VertexHolder.h"

namespace gf {

class VertexIndexBuffer {
 public:
  VertexIndexBuffer() : mVBO{0}, mVAO{0}, mIBO{0} {}

  virtual void createBuffers(const std::vector<VertexHolder> &vertices, const std::vector<unsigned int> &indices) = 0;

  virtual void deleteBuffers() = 0;

  virtual void bind() = 0;

  virtual void unbind() = 0;

  virtual void draw(int index_count) = 0;

 protected:
  GLuint mVBO;
  GLuint mVAO;
  GLuint mIBO;
};

class OpenGL_VertexIndexBuffer : public VertexIndexBuffer {
 public:
  OpenGL_VertexIndexBuffer() : VertexIndexBuffer() {}

  void createBuffers(const std::vector<VertexHolder> &vertices, const std::vector<unsigned int> &indices) override;

  void deleteBuffers() override;

  void bind() override;

  void unbind() override;

  void draw(int index_count) override;

};

}

#endif
