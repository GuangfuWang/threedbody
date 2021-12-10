//
// Created by bigdata-wgf on 2021/12/9.
//

#ifndef INC_3DBODY_3DBODY_INCLUDE_MESH_TEXTURE_H_
#define INC_3DBODY_3DBODY_INCLUDE_MESH_TEXTURE_H_

#include <memory>
#include <string>

namespace gf{

template<typename T>
using Ref = std::shared_ptr<T>;

class Texture {
 public:
  virtual ~Texture() = default;

  virtual uint32_t GetWidth() const = 0;
  virtual uint32_t GetHeight() const = 0;
  virtual uint32_t GetRendererID() const = 0;

  virtual void SetData(void *data, uint32_t size) = 0;

  virtual void Bind(uint32_t slot = 0) const = 0;

  virtual bool IsLoaded() const = 0;

  virtual bool operator==(const Texture &other) const = 0;
};

class Texture2D : public Texture {
 public:
  static Ref<Texture2D> Create(uint32_t width, uint32_t height);
  static Ref<Texture2D> Create(const std::string &path);
};

class OpenGLTexture2D final : public Texture2D
{
 public:
  OpenGLTexture2D(uint32_t width, uint32_t height);
  OpenGLTexture2D(const std::string& path);
  virtual ~OpenGLTexture2D();

  uint32_t GetWidth() const override { return m_Width;  }
  uint32_t GetHeight() const override { return m_Height; }
  uint32_t GetRendererID() const override { return m_RendererID; }

  void SetData(void* data, uint32_t size) override;

  void Bind(uint32_t slot = 0) const override;

  bool IsLoaded() const override { return m_IsLoaded; }

  bool operator==(const Texture& other) const override
  {
	return m_RendererID == ((OpenGLTexture2D&)other).m_RendererID;
  }
 private:
  std::string m_Path;
  bool m_IsLoaded = false;
  uint32_t m_Width, m_Height;
  uint32_t m_RendererID;
  unsigned int m_InternalFormat, m_DataFormat;
};

}

#endif //INC_3DBODY_3DBODY_INCLUDE_MESH_TEXTURE_H_
