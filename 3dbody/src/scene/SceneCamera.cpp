#include "include/scene/SceneCamera.h"
#include <glm/gtx/norm.hpp>

namespace gf {

void SceneCamera::update(Shader *shader) {
  shader->setMat4(mModelMatrix, "model");
  shader->setMat4(mViewMatrix, "view");
  shader->setMat4(mProjection, "projection");
  shader->setVec3(mPosition, "camPos");
}

void SceneCamera::onPanMovement(const double &x, const double &y) {

}
void SceneCamera::onRotateMovement(const double &x, const double &y) {

}
void SceneCamera::onZoomMovement(const double &wheelOffset) {

}
Mat4 SceneCamera::computeViewMatrix(const Vec &eye,
									const Vec &sceneCenter,
									const Vec &up) {
  return glm::lookAt(eye, sceneCenter, up);
}
void SceneCamera::updateViewMatrix() {
  computeViewMatrix(mPosition, mSceneCenter, mUp);
}

}
