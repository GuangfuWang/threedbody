
#ifndef INC_3DBODY_3DBODY_INCLUDE_SCENE_SCENEVIEW_H_
#define INC_3DBODY_3DBODY_INCLUDE_SCENE_SCENEVIEW_H_

#include "def.h"
#include <imgui.h>
#include "include/scene/SceneLight.h"
#include "include/mesh/Mesh.h"
#include "include/render/FrameBuffer.h"
#include "util/ConfigMap.h"

namespace gf {

class SceneView {
 public:
  SceneView() :
	  mCamera(nullptr), mFrameBuffer(nullptr), mShader(nullptr),
	  mLight(nullptr), mSize(800, 600) {
	mFrameBuffer = std::make_unique<OpenGL_FrameBuffer>();
	mFrameBuffer->createBuffers(800, 600);
	mShader = std::make_unique<Shader>();
	mShader->load(ConfigMap::getInstance()->resource_dir_+"/shaders/vertex_shader/vertex_shader.glsl",
                  ConfigMap::getInstance()->resource_dir_+"/shaders/fragment_shader/fs_pbr.glsl");
	mLight = std::make_unique<Light>();

	mCamera = std::make_unique<SceneCamera>(
		glm::vec3(0, 0, 3),
		45.0f,
		mSize.x, mSize.y,
		0.1f, 100.0f);

  }

  ~SceneView() {
	mShader->unload();
  }

  Light *getLight() { return mLight.get(); }

  Camera *getCamera() { return (Camera *)mCamera.get(); }

  Shader *getShader() { return mShader.get(); }

  FrameBuffer *getFrameBuffer() { return mFrameBuffer.get(); }

  void resize(int32_t width, int32_t height);

  void render();

  void loadMesh(const string &filepath);

  void setMesh(Ref<Mesh> mesh) {
	mMesh = mesh;
  }

  Ref<Mesh> getMesh() { return mMesh; }

//  void onMouseMove(double x, double y, MOUSE_BUTTON button);
//
//  void onMouseWheel(double delta);

  void resetView() {
//	mCamera->reset();
  }

 private:
  Ref_Unique<SceneCamera>        mCamera;
  Ref_Unique<OpenGL_FrameBuffer> mFrameBuffer;
  Ref_Unique<Shader>             mShader;
  Ref_Unique<Light>              mLight;
  Ref<Mesh>                      mMesh;
  glm::vec2                      mSize;
};
}

#endif //INC_3DBODY_3DBODY_INCLUDE_SCENE_SCENEVIEW_H_
