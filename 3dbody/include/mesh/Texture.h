//
// Created by bigdata-wgf on 2021/12/9.
//

#ifndef INC_3DBODY_3DBODY_INCLUDE_MESH_TEXTURE_H_
#define INC_3DBODY_3DBODY_INCLUDE_MESH_TEXTURE_H_

#include <memory>

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

}

#endif //INC_3DBODY_3DBODY_INCLUDE_MESH_TEXTURE_H_
