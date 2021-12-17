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
        if (delta_x > 100 || delta_y > 100) {
            mCurrentMonitorPos.x = x;
            mCurrentMonitorPos.y = y;
            return;
        }
        Vec monitorX = glm::cross(mUp, mCurrentFocus);
        monitorX = glm::normalize(monitorX) * delta_x;
        mPosition += monitorX + mUp * delta_y;
        updateViewMatrix();
        mCurrentMonitorPos.x = x;
        mCurrentMonitorPos.y = y;
    }

    void SceneCamera::onRotateMovement(const double &x, const double &y) {
        GF_CORE_INFO("Rotating...");
        float delta_x = x - mCurrentMonitorPos.x;
        float delta_y = y - mCurrentMonitorPos.y;
        if (delta_x > 100 || delta_y > 100) {
            mCurrentMonitorPos.x = x;
            mCurrentMonitorPos.y = y;
            return;
        }

        updateViewMatrix();
        mCurrentMonitorPos.x = x;
        mCurrentMonitorPos.y = y;
    }

    void SceneCamera::onZoomMovement(const double &wheelOffset) {
        mPosition += mCurrentFocus * (float) wheelOffset;
        updateViewMatrix();
    }

    Mat4 SceneCamera::computeViewMatrix(const Vec &eye,
                                        const Vec &currentFocus,
                                        const Vec &up) {
        return glm::lookAt(eye, currentFocus, up);
    }

    void SceneCamera::updateViewMatrix() {
        computeViewMatrix(mPosition, mCurrentFocus, mUp);
    }

    void SceneCamera::setScenePositionInfo(
            const Vec &sceneCenter,
            const Vec &sceneMinBox,
            const Vec &sceneMaxBox) {

        mCurrentFocus = sceneCenter - mPosition;
        mSceneCenter  = sceneCenter;
        mSceneMinBox  = sceneMinBox;
        mSceneMaxBox  = sceneMaxBox;

    }

}
