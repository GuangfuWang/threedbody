
#ifndef INC_3DBODY_SCENE_CAMERA_H
#define INC_3DBODY_SCENE_CAMERA_H

#include <glm/gtx/quaternion.hpp>
#include <GLFW/glfw3.h>

#include "def.h"
#include "include/shader/Shader.h"
#include "include/event_handling/EventBase.h"
#include "util/Log.h"
#include "util/Timer.h"

namespace gf {

    class Camera : public EventHandleInterface {

    public:
        enum TYPE {
            PROJECTIVE = 0,
            ORTHOGONAL = 1
        };

    public:

        virtual void update(Shader *shader) = 0;

        virtual void onPanMovement(const double &x, const double &y) = 0;

        virtual void onRotateMovement(const double &x, const double &y) = 0;

        virtual void onZoomMovement(const double &wheelOffset) = 0;

        ///here are functions for editing mode view switching.
        ///currently not used either.
        UnUsed_Func virtual void frontView() {}

        UnUsed_Func virtual void backView() {}

        UnUsed_Func virtual void leftView() {}

        UnUsed_Func virtual void rightView() {}

        UnUsed_Func virtual void upView() {}

        UnUsed_Func virtual void downView() {}

        ///not used currently in this project, if you are lazy to implement your own camera system,
        ///as a convenient interface if you wanna keyboard control of movement.
        UnUsed_Func virtual void onLeftMovement() {}

        UnUsed_Func virtual void onRightMovement() {}

        UnUsed_Func virtual void onUpMovement() {}

        UnUsed_Func virtual void onDownMovement() {}

        UnUsed_Func virtual void onLeftRotateMovement() {}

        UnUsed_Func virtual void onRightRotateMovement() {}

        UnUsed_Func virtual void onUpRotateMovement() {}

        UnUsed_Func virtual void onDownRotateMovement() {}

        /// potentially not used, if you only need implement mouse to control view.
        UnUsed_Func virtual void onZoomMovement() {}

        virtual TYPE getType() { return mType; }

        virtual void setType(const TYPE &type = PROJECTIVE) = 0;

        virtual void setScenePositionInfo(const Vec &sceneCenter,
                                          const Vec &sceneMinBox,
                                          const Vec &sceneMaxBox) = 0;

        virtual void setPanSpeed(const float &panSpeed) { this->mPanSpeed = panSpeed; }

        virtual void setRotateSpeed(const float &rotateSpeed) { this->mRotateSpeed = rotateSpeed; }

        virtual void setSensitivity(const float &sensitivity) { this->mSensitivity = sensitivity; }

        virtual float getPanSpeed() { return mPanSpeed; }

        virtual float getRotateSpeed() { return mRotateSpeed; }

        ///before you call this method, please make sure you have set all scale factors,
        ///otherwise it will not work.
        ///if you setup different scale factors it may show non-uniform scaling.
        virtual void setScaleEnabled(const unsigned char &s) {
            scaleEnabled = s;
            switch (s) {
                case 1: {
                    mViewMatrix = glm::scale(mViewMatrix,
                                             Vec(this->mScaleXFactor, 1.0f, 1.0f));
                    break;
                }
                case 2: {
                    mViewMatrix = glm::scale(mViewMatrix,
                                             Vec(1.0f, this->mScaleYFactor, 1.0f));
                    break;
                }
                case 3: {
                    mViewMatrix = glm::scale(mViewMatrix,
                                             Vec(this->mScaleXFactor, this->mScaleYFactor, 1.0f));
                    break;
                }
                case 4: {
                    mViewMatrix = glm::scale(mViewMatrix,
                                             Vec(1.0f, 1.0f, this->mScaleZFactor));
                    break;
                }
                case 5: {
                    mViewMatrix = glm::scale(mViewMatrix,
                                             Vec(this->mScaleXFactor, 1.0f, this->mScaleZFactor));
                    break;
                }
                case 6: {
                    mViewMatrix = glm::scale(mViewMatrix,
                                             Vec(1.0f, this->mScaleYFactor, this->mScaleZFactor));
                    break;
                }
                case 7: {
                    mViewMatrix = glm::scale(mViewMatrix,
                                             Vec(this->mScaleXFactor, this->mScaleYFactor, this->mScaleZFactor));
                    break;
                }
                default: {
                    mViewMatrix = glm::scale(mViewMatrix, Vec(1.0f, 1.0f, 1.0f));
                    break;
                }
            }
        }

        UnUsed_Func virtual float getSensitivity() { return mSensitivity; }

    public:
        uint32_t windowSizeX;
        uint32_t windowSizeY;

        Vec   mPosition          = {0.0f, 0.0f, 0.0f};
        Vec2f mCurrentMonitorPos = {0.0f, 0.0f};
        Vec   mCurrentFocus      = {0.0f, 0.0f, -1.0f};
        Vec   mUp                = {0.0f, 1.0f, 0.0f};

        Vec mSceneCenter = {0.0f, 0.0f, 0.0f};
        Vec mSceneMinBox = {0.0f, 0.0f, 0.0f};
        Vec mSceneMaxBox = {0.0f, 0.0f, 0.0f};

        ///@note speed should correspond to scene size.
        float mSensitivity = 0.1f;
        float mPanSpeed    = 0.05f;
        float mRotateSpeed = 2.00f;
        float mZoomSpeed   = 2.00f;

        float mAspect;
        float mFOV;
        float mNear;
        float mFar;

        Mat4 mModelMatrix{1.0f};
        Mat4 mViewMatrix;
        Mat4 mProjection;

        ///note scaleEnabled equals to 0 meaning that no scale at all.
        ///if scaleEnabled equals to 1 meaning that scale X is enabled.
        ///if scaleEnabled equals to 2 meaning that scale Y is enabled.
        ///if scaleEnabled equals to 4 meaning that scale Z is enabled.
        ///if scaleEnabled equals to 7 meaning that scale whole is enabled.
        ///you can use operator | to determine which scenario happens.
        ///only 0-7 are used, other values have same meaning as 0.
        unsigned char scaleEnabled = 0;

        float mScaleWholeFactor = 1.0f;
        float mScaleXFactor     = 1.0f;
        float mScaleYFactor     = 1.0f;
        float mScaleZFactor     = 1.0f;

        TYPE mType = TYPE::PROJECTIVE;

    };

    class SceneCamera final : public Camera {

    public:

        SceneCamera(const glm::vec3 &position,
                    float fov,
                    uint32_t width, uint32_t height,
                    float near_, float far_) {
            mPosition = position;
            mAspect   = (float) width / height;
            mNear     = near_;
            mFar      = far_;
            mFOV      = fov;

            windowSizeX = width;
            windowSizeY = height;

            mViewMatrix = glm::translate(glm::mat4(1.0f), mPosition) ;
            mViewMatrix = glm::inverse(mViewMatrix);
            setAspect(width, height);

//	updateViewMatrix();
        }

        SceneCamera(const float &width,
                    const float &height,
                    const Vec &position,
                    float fov_deg = 45.0f,
                    const float &near_ = 0.1f,
                    const float &far_ = 100.0f) {
            mPosition     = position;
            mAspect       = (float) width / height;
            mFOV          = fov_deg;
            mNear         = near_;
            mFar          = far_;
            mCurrentFocus = {0.0f, 0.0f, -1.0f};

            windowSizeX = width;
            windowSizeY = height;

            mModelMatrix = Mat4(1.0f);

            mViewMatrix = glm::translate(glm::mat4(1.0f), mPosition) ;
            mViewMatrix = glm::inverse(mViewMatrix);
            mProjection  = glm::perspective(
                    mFOV,
                    mAspect, mNear, mFar);

        }

        void resizeCameraWindow(const unsigned int &x, const unsigned int &y) {
            windowSizeY = y;
            windowSizeX = x;
            setAspect(windowSizeX, windowSizeY);
        }

        void update(Shader *shader) override;

        void onPanMovement(const double &x, const double &y) override;

        void onRotateMovement(const double &x, const double &y) override;

        void onZoomMovement(const double &wheelOffset) override;

        void setType(const TYPE &type = PROJECTIVE) override {
            if (mType != type) {
                mType = type;
                setAspect(windowSizeX, windowSizeY);
            }
        }

        void resize(const unsigned int &w, const unsigned int &h) {
            windowSizeX = w;
            windowSizeY = h;
            setAspect(w,h);
        }


        void setScenePositionInfo(const Vec &sceneCenter,
                                  const Vec &sceneMinBox,
                                  const Vec &sceneMaxBox) override;

        void updateViewMatrix();

        void toggleProjectionType() {
            if (mType == TYPE::PROJECTIVE) {
                setType(TYPE::ORTHOGONAL);
            } else setType(TYPE::PROJECTIVE);
        }

        void setAspect(const uint32_t &width, const uint32_t &height) {
            float aspect = (float) width / height;
            switch (mType) {
                case TYPE::PROJECTIVE: {
                    mProjection = glm::perspective(mFOV, aspect, mNear, mFar);
                    break;
                }
                case TYPE::ORTHOGONAL: {
                    ///currently hard-code in to here.
                    mProjection = glm::ortho<float>(0.0f, width,
                                                    0.0f, height,
                                                    -0.1f, 100.0f);
                    break;
                }
                default: {
                    mProjection = glm::perspective(mFOV, aspect, mNear, mFar);
                    break;
                }
            }
        }

    private:
        Mat4 computeViewMatrix(const Vec &eye, const Vec &sceneCenter, const Vec &up);

    };

    class MyCamera final : public EventHandleInterface {
    public:

        MyCamera(const glm::vec3 &position, float fov, float aspect, float near_, float far_) {
            mPosition = position;
            mAspect   = aspect;
            mNear     = near_;
            mFar      = far_;
            mFOV      = fov;

            set_aspect(mAspect);

            update_view_matrix();
        }

        void update(Shader *shader) override {
            glm::mat4 model{1.0f};
            shader->setMat4(model, "model");
            shader->setMat4(mViewMatrix, "view");
            shader->setMat4(get_projection(), "projection");
            shader->setVec3(mPosition, "camPos");
        }

        void set_aspect(float aspect) {
            mProjection = glm::perspective(mFOV, aspect, mNear, mFar);
        }

        void set_distance(float offset) {
            mDistance += offset;
            update_view_matrix();
        }

        const glm::mat4 &get_projection() const {
            return mProjection;
        }

        glm::mat4 get_view_projection() const {
            return mProjection * get_view_matrix();
        }

        glm::vec3 get_up() const {
            return glm::rotate(get_direction(), cUp);
        }

        glm::vec3 get_right() const {
            return glm::rotate(get_direction(), cRight);
        }

        glm::vec3 get_forward() const {
            return glm::rotate(get_direction(), cForward);
        }

        glm::quat get_direction() const {
            return glm::quat(glm::vec3(-mPitch, -mYaw, 0.0f));
        }

        glm::mat4 get_view_matrix() const {
            return mViewMatrix;
        }

        void onZoomMovement(double delta) {
            set_distance(delta * 0.5f);

            update_view_matrix();
        }

        void reset() {
            mFocus = {0.0f, 0.0f, 0.0f};
            //mDistance = 5.0f;
            update_view_matrix();
        }


        void onPanMovement(double x, double y) {
            glm::vec2 pos2d{x, y};
            glm::vec2 delta = (pos2d - mCurrentPos2d) * 0.004f;

            float sign = get_up().y < 0 ? -1.0f : 1.0f;
            mYaw += sign * delta.x * cRotationSpeed;
            mPitch += delta.y * cRotationSpeed;

            update_view_matrix();
            mCurrentPos2d = pos2d;
        }

        void onRotateMovement(double x, double y) {
            glm::vec2 pos2d{x, y};

            // TODO: Adjust pan speed for distance
            glm::vec2 delta = (pos2d - mCurrentPos2d) * 0.003f;
            mFocus += -get_right() * delta.x * mDistance;
            mFocus += get_up() * delta.y * mDistance;
            update_view_matrix();
            mCurrentPos2d = pos2d;
        }

        void update_view_matrix() {
            mPosition = mFocus - get_forward() * mDistance;
            GF_CORE_INFO("mPostion: x={:.3f},y={:.3f},z={:.3f}",
                         mPosition.x,mPosition.y,mPosition.z);

            glm::quat orientation = get_direction();
            mViewMatrix = glm::translate(glm::mat4(1.0f), mPosition) * glm::toMat4(orientation);
            mViewMatrix = glm::inverse(mViewMatrix);
        }

    private:
        glm::mat4 mViewMatrix;
        glm::mat4 mProjection = glm::mat4{1.0f};
        glm::vec3 mPosition   = {0.0f, 0.0f, 0.0f};

        glm::vec3 mFocus = {0.0f, 0.0f, 0.0f};

        float mDistance = 5.0f;
        float mAspect;
        float mFOV;
        float mNear;
        float mFar;

        float mPitch = 0.0f;
        float mYaw   = 0.0f;

        glm::vec2 mCurrentPos2d = {0.0f, 0.0f};

        const glm::vec3 cRight   = {1.0f, 0.0f, 0.0f};
        const glm::vec3 cUp      = {0.0f, 1.0f, 0.0f};
        const glm::vec3 cForward = {0.0f, 0.0f, -1.0f};

        const float cRotationSpeed = 2.0f;
    };
}

#endif //INC_3DBODY_SCENE_CAMERA_H
