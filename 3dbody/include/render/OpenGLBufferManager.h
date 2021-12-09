#ifndef INC_3DBODY_OPENGL_BUFFER_MANAGER_H
#define INC_3DBODY_OPENGL_BUFFER_MANAGER_H

#include "pch.hpp"

#include "RenderBase.h"
#include "include/mesh/VertexHolder.h"

namespace gf
{
  class OpenGL_VertexIndexBuffer : public VertexIndexBuffer
  {
  public:
    OpenGL_VertexIndexBuffer() : VertexIndexBuffer()
    {}

    void create_buffers(const std::vector<VertexHolder>& vertices, const std::vector<unsigned int>& indices) override;

    void delete_buffers() override;

    void bind() override;

    void unbind() override;

    void draw(int index_count) override;

  };

  class OpenGL_FrameBuffer : public FrameBuffer
  {
  public:

    void create_buffers(int32_t width, int32_t height) override;

    void delete_buffers() override;

    void bind() override;

    void unbind() override;
    
    uint32_t get_texture() override;
  };
}

#endif
