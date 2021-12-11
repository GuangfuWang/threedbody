

#ifndef INC_3DBODY_SCENE_CAMERA_H
#define INC_3DBODY_SCENE_CAMERA_H

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/quaternion.hpp>
#include <GLFW/glfw3.h>

#include "include/shader/Shader.h"
#include "include/event_handling/EventBase.h"
#include "include/event_handling/MouseEvent.h"

namespace gf {

class Camera : public EventHandleBase {
 public:

  Camera(const glm::vec3 &position, float fov, float aspect, float near, float far) {
    mPosition = position;
    mAspect = aspect;
    mNear = near;
    mFar = far;
    mFOV = fov;

	setAspect(mAspect);

	updateViewMatrix();
  }

  void update(Shader *shader) override {
    glm::mat4 model{1.0f};
	shader->setMat4(model, "model");
	shader->setMat4(mViewMatrix, "view");
	shader->setMat4(getProjection(), "projection");
	shader->setVec3(mPosition, "camPos");
  }

  void setAspect(float aspect) {
    mProjection = glm::perspective(mFOV, aspect, mNear, mFar);
  }

  void setDistance(float offset) {
    mDistance += offset;
	updateViewMatrix();
  }

  const glm::mat4 &getProjection() const {
    return mProjection;
  }

  glm::mat4 getViewProjection() const {
    return mProjection *getViewMatrix();
  }

  glm::vec3 getUp() const {
    return glm::rotate(getDirection(), cUp);
  }

  glm::vec3 getRight() const {
    return glm::rotate(getDirection(), cRight);
  }

  glm::vec3 getForward() const {
    return glm::rotate(getDirection(), cForward);
  }

  glm::quat getDirection() const {
    return glm::quat(glm::vec3(-mPitch, -mYaw, 0.0f));
  }

  glm::mat4 getViewMatrix() const {
    return mViewMatrix;
  }

  void onMouseWheel(double delta) {
	setDistance(delta*0.5f);

	updateViewMatrix();
  }

  void reset() {
    mFocus = {0.0f, 0.0f, 0.0f};
    //mDistance = 5.0f;
	updateViewMatrix();
  }

  void onMouseMove(double x, double y, MOUSE_INPUT_CODE button) {
    glm::vec2 pos2d{x, y};

    if (button == MOUSE_INPUT_CODE::RIGHT) {
      glm::vec2 delta = (pos2d - mCurrentPos2d) * 0.004f;

      float sign = getUp().y < 0 ? -1.0f : 1.0f;
      mYaw += sign * delta.x * cRotationSpeed;
      mPitch += delta.y * cRotationSpeed;

	  updateViewMatrix();
    } else if (button == MOUSE_INPUT_CODE::MIDDLE) {
      // TODO: Adjust pan speed for distance
      glm::vec2 delta = (pos2d - mCurrentPos2d) * 0.003f;

      mFocus += -getRight() * delta.x * mDistance;
      mFocus += getUp() * delta.y * mDistance;

	  updateViewMatrix();
    }

    mCurrentPos2d = pos2d;
  }

  void updateViewMatrix() {
    mPosition = mFocus - getForward() * mDistance;

    glm::quat orientation = getDirection();
    mViewMatrix = glm::translate(glm::mat4(1.0f), mPosition) * glm::toMat4(orientation);
    mViewMatrix = glm::inverse(mViewMatrix);
  }

 private:
  glm::mat4 mViewMatrix;
  glm::mat4 mProjection = glm::mat4{1.0f};
  glm::vec3 mPosition = {0.0f, 0.0f, 0.0f};

  glm::vec3 mFocus = {0.0f, 0.0f, 0.0f};

  float mDistance = 5.0f;
  float mAspect;
  float mFOV;
  float mNear;
  float mFar;

  float mPitch = 0.0f;
  float mYaw = 0.0f;

  glm::vec2 mCurrentPos2d = {0.0f, 0.0f};

  const glm::vec3 cRight = {1.0f, 0.0f, 0.0f};
  const glm::vec3 cUp = {0.0f, 1.0f, 0.0f};
  const glm::vec3 cForward = {0.0f, 0.0f, -1.0f};

  const float cRotationSpeed = 2.0f;

};
}

#endif //INC_3DBODY_SCENE_CAMERA_H
