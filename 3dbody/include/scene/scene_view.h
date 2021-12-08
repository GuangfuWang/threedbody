
#ifndef INC_3DBODY_3DBODY_INCLUDE_SCENE_SCENE_VIEW_H_
#define INC_3DBODY_3DBODY_INCLUDE_SCENE_SCENE_VIEW_H_

#include "include/render/opengl_buffer_manager.h"
#include "include/scene/scene_light.h"
#include "include/mesh/mesh.h"

namespace gf{

class SceneView
{
 public:
  SceneView() :
      mCamera(nullptr), mFrameBuffer(nullptr), mShader(nullptr),
      mLight(nullptr), mSize(800, 600)
  {
    mFrameBuffer = std::make_unique<OpenGL_FrameBuffer>();
    mFrameBuffer->create_buffers(800, 600);
    mShader = std::make_unique<Shader>();
    mShader->load("resources/shaders/vertex_shader/vertex_shader.glsl",
                  "resources/shaders/fragment_shader/fs_pbr.glsl");
    mLight = std::make_unique<Light>();

    mCamera = std::make_unique<Camera>(glm::vec3(0, 0, 3), 45.0f, 1.3f, 0.1f, 100.0f);

  }

  ~SceneView()
  {
    mShader->unload();
  }

  Light* get_light() { return mLight.get(); }

  void resize(int32_t width, int32_t height);


  void render();

  void load_mesh(const std::string& filepath);

  void set_mesh(std::shared_ptr<Mesh> mesh)
  {
    mMesh = mesh;
  }

  std::shared_ptr<Mesh> get_mesh() { return mMesh; }

  void on_mouse_move(double x, double y, EInputButton button);

  void on_mouse_wheel(double delta);

  void reset_view()
  {
    mCamera->reset();
  }

 private:
  std::unique_ptr<Camera> mCamera;
  std::unique_ptr<OpenGL_FrameBuffer> mFrameBuffer;
  std::unique_ptr<Shader> mShader;
  std::unique_ptr<Light> mLight;
  std::shared_ptr<Mesh> mMesh;
  glm::vec2 mSize;
};
}

#endif //INC_3DBODY_3DBODY_INCLUDE_SCENE_SCENE_VIEW_H_
