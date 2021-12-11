
#ifndef INC_3DBODY_3DBODY_INCLUDE_MESH_TEXTURE_H_
#define INC_3DBODY_3DBODY_INCLUDE_MESH_TEXTURE_H_

#include <memory>
#include <string>

#include "def.h"

namespace gf {

class Texture {
 public:
  virtual ~Texture() = default;

  virtual uint32_t getWidth() const = 0;
  virtual uint32_t getHeight() const = 0;
  virtual uint32_t getRendererID() const = 0;

  virtual void setData(void *data, uint32_t size) = 0;

  virtual void bind(uint32_t slot = 0) const = 0;

  virtual bool isLoaded() const = 0;

  virtual bool operator==(const Texture &other) const = 0;
};

class Texture2D : public Texture {
 public:
  static Ref<Texture2D> create(uint32_t width, uint32_t height);
  static Ref<Texture2D> create(const std::string &path);
};

class OpenGLTexture2D final : public Texture2D {
 public:
  OpenGLTexture2D(uint32_t width, uint32_t height);
  OpenGLTexture2D(const std::string &path);
  virtual ~OpenGLTexture2D();

  uint32_t getWidth() const override { return mWidth; }
  uint32_t getHeight() const override { return mHeight; }
  uint32_t getRendererID() const override { return mRendererID; }

  void setData(void *data, uint32_t size) override;

  void bind(uint32_t slot = 0) const override;

  bool isLoaded() const override { return mIsLoaded; }

  bool operator==(const Texture &other) const override {
	return mRendererID==((OpenGLTexture2D &)other).mRendererID;
  }
 private:
  std::string  mPath;
  bool         mIsLoaded = false;
  uint32_t     mWidth, mHeight;
  uint32_t     mRendererID;
  unsigned int mInternalFormat, mDataFormat;
};

}

#endif //INC_3DBODY_3DBODY_INCLUDE_MESH_TEXTURE_H_
