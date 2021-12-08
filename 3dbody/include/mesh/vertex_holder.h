

#ifndef INC_3DBODY_3DBODY_INCLUDE_MESH_VERTEX_HOLDER_H_
#define INC_3DBODY_3DBODY_INCLUDE_MESH_VERTEX_HOLDER_H_

#include "pch.hpp"

namespace gf {

class VertexHolder {

 public:
  VertexHolder() : mPos(), mNormal() {}

  VertexHolder(const glm::vec3 &pos, const glm::vec3 &normal)
      : mPos(pos), mNormal(normal) {
  }

  ~VertexHolder() = default;

  glm::vec3 mPos;

  glm::vec3 mNormal;

  // TODO
  // glm::vec2 mUV;
};

}

#endif //INC_3DBODY_3DBODY_INCLUDE_MESH_VERTEX_HOLDER_H_
