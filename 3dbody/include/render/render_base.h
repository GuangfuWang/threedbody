#ifndef INC_3DBODY_RENDER_BASE_H
#define INC_3DBODY_RENDER_BASE_H

#include "include/layout/window.h"
#include "include/mesh/vertex_holder.h"

namespace gf {

class VertexIndexBuffer {
 public:
  VertexIndexBuffer() : mVBO{0}, mVAO{0}, mIBO{0} {}

  virtual void create_buffers(const std::vector<VertexHolder> &vertices, const std::vector<unsigned int> &indices) = 0;

  virtual void delete_buffers() = 0;

  virtual void bind() = 0;

  virtual void unbind() = 0;

  virtual void draw(int index_count) = 0;

 protected:
  GLuint mVBO;
  GLuint mVAO;
  GLuint mIBO;
};

class FrameBuffer {
 public:
  FrameBuffer() : mFBO{0}, mDepthId{0} {}

  virtual void create_buffers(int32_t width, int32_t height) = 0;

  virtual void delete_buffers() = 0;

  virtual void bind() = 0;

  virtual void unbind() = 0;

  virtual uint32_t get_texture() = 0;

 protected:
  uint32_t mFBO = 0;
  uint32_t mTexId = 0;
  uint32_t mDepthId = 0;
  int32_t mWidth = 0;
  int32_t mHeight = 0;
};

class RenderContext {

 public:

  RenderContext() : mWindow(nullptr) {}

  virtual bool init(GFWindow *window) {
    mWindow = window;
    return true;
  }

  virtual void pre_render() = 0;

  virtual void post_render() = 0;

  virtual void end() = 0;

  virtual void setupWindowIcon(GLFWwindow* glWindow) = 0;

 protected:
  GFWindow *mWindow;


};

}

#endif
