#ifndef INC_3DBODY_3DBODY_INCLUDE_MESH_MESH_H_
#define INC_3DBODY_3DBODY_INCLUDE_MESH_MESH_H_

#include "include/scene/SceneCamera.h"
#include "include/mesh/VertexHolder.h"
#include "include/render/VertexIndexBuffer.h"
#include "def.h"

namespace gf {

class Mesh : public EventHandleInterface {

 public:

  Mesh() = default;

  virtual ~Mesh();

  bool load(const std::string &filepath);

  void addVertex(const VertexHolder &vertex) { mVertices.push_back(vertex); }

  void addVertexIndex(unsigned int vertex_idx) { mVertexIndices.push_back(vertex_idx); }

  std::vector<RenderIndexType> getVertexIndices() { return mVertexIndices; }

  void update(Shader *shader) override {
	// pbr color
	shader->setVec3(mColor, "albedo");

	shader->setF1(mRoughness, "roughness");
	shader->setF1(mMetallic, "metallic");
	shader->setF1(1.0f, "ao");

  }

  glm::vec3 mColor     = {1.0f, 0.0f, 0.0f};
  float     mRoughness = 0.2f;
  float     mMetallic  = 0.1f;

  void init();

  void createBuffers();

  void deleteBuffers();

  void render();

  void bind();

  void unbind();

 private:

  // Buffers manager
  Ref_Unique<VertexIndexBuffer> mRenderBufferMgr;

  // Vertices and indices
  vector<VertexHolder>    mVertices;
  vector<RenderIndexType> mVertexIndices;

};

}

#endif //INC_3DBODY_3DBODY_INCLUDE_MESH_MESH_H_
