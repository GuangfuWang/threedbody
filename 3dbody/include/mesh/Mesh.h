#ifndef INC_3DBODY_3DBODY_INCLUDE_MESH_MESH_H_
#define INC_3DBODY_3DBODY_INCLUDE_MESH_MESH_H_

#include "include/scene/SceneCamera.h"
#include "include/mesh/VertexHolder.h"
#include "include/render/RenderBase.h"

namespace gf {

class Mesh : public EventHandleBase {

 public:

  Mesh() = default;

  virtual ~Mesh();

  bool load(const std::string &filepath);

  void add_vertex(const VertexHolder &vertex) { mVertices.push_back(vertex); }

  void add_vertex_index(unsigned int vertex_idx) { mVertexIndices.push_back(vertex_idx); }

  std::vector<unsigned int> get_vertex_indices() { return mVertexIndices; }

  void update(Shader *shader) override {
    // pbr color
    shader->set_vec3(mColor, "albedo");

    shader->set_f1(mRoughness, "roughness");
    shader->set_f1(mMetallic, "metallic");
    shader->set_f1(1.0f, "ao");

  }

  glm::vec3 mColor = {1.0f, 0.0f, 0.0f};
  float mRoughness = 0.2f;
  float mMetallic = 0.1f;

  void init();

  void create_buffers();

  void delete_buffers();

  void render();

  void bind();

  void unbind();

 private:

  // Buffers manager
  std::unique_ptr<VertexIndexBuffer> mRenderBufferMgr;

  // Vertices and indices
  std::vector<VertexHolder> mVertices;
  std::vector<unsigned int> mVertexIndices;

};

}

#endif //INC_3DBODY_3DBODY_INCLUDE_MESH_MESH_H_
