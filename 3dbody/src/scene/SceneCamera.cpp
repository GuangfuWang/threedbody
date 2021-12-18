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
        GF_CORE_INFO("Panning...");
        float delta_x = x - mCurrentMonitorPos.x;
        float delta_y = y - mCurrentMonitorPos.y;
        if (delta_x < mSensitivity && delta_y < mSensitivity) {
            mCurrentMonitorPos.x = x;
            mCurrentMonitorPos.y = y;
        }
        Vec monitorX = glm::cross(mCurrentFocus, mUp);
        monitorX = glm::normalize(monitorX) * delta_x * mPanSpeed;
        mPosition += monitorX + mUp * delta_y * mPanSpeed;
        updateViewMatrix();
        mCurrentMonitorPos.x = x;
        mCurrentMonitorPos.y = y;
    }

    void SceneCamera::onRotateMovement(const double &x, const double &y) {
        GF_CORE_INFO("Rotating...");
        float delta_x = x - mCurrentMonitorPos.x;
        float delta_y = y - mCurrentMonitorPos.y;

        if (delta_x < mSensitivity && delta_y < mSensitivity) {
            mCurrentMonitorPos.x = x;
            mCurrentMonitorPos.y = y;
        }
        delta_x *= mRotateSpeed;
        delta_y *= mRotateSpeed;

        Quaternion rotateAngle = Quaternion(0.0f, -delta_x, -delta_y, 0.0f);
        mUp           = glm::rotate(rotateAngle, mUp);
        mCurrentFocus = glm::rotate(rotateAngle, mCurrentFocus);
        mPosition     = mSceneCenter - mCurrentFocus;

        updateViewMatrix();
        mCurrentMonitorPos.x = x;
        mCurrentMonitorPos.y = y;
    }

    void SceneCamera::onZoomMovement(const double &wheelOffset) {
        mPosition += glm::normalize(mCurrentFocus) * (float) wheelOffset * mZoomSpeed;
        updateViewMatrix();
    }

    Mat4 SceneCamera::computeViewMatrix(const Vec &eye,
                                        const Vec &currentFocus,
                                        const Vec &up) {
        return glm::lookAt(eye, glm::normalize(currentFocus), up);
    }

    void SceneCamera::updateViewMatrix() {
        mViewMatrix = computeViewMatrix(mPosition, mCurrentFocus, mUp);
        mViewMatrix = glm::inverse(mViewMatrix);
    }

    void SceneCamera::setScenePositionInfo(
            const Vec &sceneCenter,
            const Vec &sceneMinBox,
            const Vec &sceneMaxBox) {

//        mPosition.x = sceneCenter.x;
//        mPosition.y = sceneCenter.y;
//        mPosition.z = sceneCenter.z;
//
//        mCurrentFocus = sceneCenter - mPosition;
//        mSceneCenter  = sceneCenter;
//        mSceneMinBox  = sceneMinBox;
//        mSceneMaxBox  = sceneMaxBox;
        updateViewMatrix();
    }

}
