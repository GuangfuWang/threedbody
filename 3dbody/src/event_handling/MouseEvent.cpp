#include "include/event_handling/MouseEvent.h"
#include "include/layout/BaseWindow.h"

namespace gf {

    MouseEventHandling *ThreeDBodyMouseEventHandling::instance_     = nullptr;
    bool               ThreeDBodyMouseEventHandling::lButtonPressed = false;
    bool               ThreeDBodyMouseEventHandling::rButtonPressed = false;
    bool               ThreeDBodyMouseEventHandling::lFirstClick    = true;
    bool               ThreeDBodyMouseEventHandling::rFirstClick    = true;

    void onMouseButtonCallback(GLFWwindow *window, int button, int action, int mods) {
        ThreeDBodyMouseEventHandling::getInstance()->onMouseButtonCallback(window, button, action, mods);
    }

    void onMouseWheelCallback(GLFWwindow *window, double xoffset, double yoffset) {
        ThreeDBodyMouseEventHandling::getInstance()->onScrollCallback(window, xoffset, yoffset);
    }

    void onDropFileCallback(GLFWwindow *window, int count, const char **paths) {
        ThreeDBodyMouseEventHandling::getInstance()->onDropFileCallback(window, count, paths);
    }

    void onCursorPosCallback(GLFWwindow *win, double xpos, double ypos) {
        ThreeDBodyMouseEventHandling::getInstance()->onCursorPosCallback(win, xpos, ypos);
    }

    void ThreeDBodyMouseEventHandling::onMouseButtonCallback(GLFWwindow *window, int button, int action, int mods) {

    }

    void ThreeDBodyMouseEventHandling::onCursorPosCallback(GLFWwindow *win, double xpos, double ypos) {

        ///mouse left button used to pan models
        ///mouse right button used to rotate.
        ///mouse left button + ALT modifier used to scale whole model objects.
        ///to scale along certain direction, please use keyboard callback.

        lButtonPressed = !glfwGetMouseButton(win, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE;
        rButtonPressed = !glfwGetMouseButton(win, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_RELEASE;
        if (!lButtonPressed && !rButtonPressed) {
            return;
        }
        x_ = xpos;
        y_ = ypos;
        if (glfwGetMouseButton(win, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
            lButtonPressed = true;
        } else if (glfwGetMouseButton(win, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE) {
            lButtonPressed = false;
        }
        if (glfwGetMouseButton(win, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS) {
            rButtonPressed = true;
        } else if (glfwGetMouseButton(win, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_RELEASE) {
            rButtonPressed = false;
        }
        if (lButtonPressed) {
            auto pWindow = static_cast<BaseWindow *>(glfwGetWindowUserPointer(win));
            if (lFirstClick) {
                pWindow->getSceneView()->getCamera()->setCurrentCursorPos(x_, y_);
                lFirstClick = false;
                return;
            }
            pWindow->getSceneView()->getCamera()->onRotateMovement(x_, y_);
        }

        if (rButtonPressed) {
            auto pWindow = static_cast<BaseWindow *>(glfwGetWindowUserPointer(win));
            if (rFirstClick) {
                pWindow->getSceneView()->getCamera()->setCurrentCursorPos(x_, y_);
                rFirstClick = false;
                return;
            }
            pWindow->getSceneView()->getCamera()->onPanMovement(x_, y_);
        }
        if (!lButtonPressed) {
            lFirstClick = true;
        }
        if (!rButtonPressed) {
            rFirstClick = true;
        }
    }

    void ThreeDBodyMouseEventHandling::onScrollCallback(GLFWwindow *window, double xoffset, double yoffset) {
        auto pWindow = static_cast<BaseWindow *>(glfwGetWindowUserPointer(window));
        pWindow->getSceneView()->getCamera()->onZoomMovement(yoffset);
    }

    void ThreeDBodyMouseEventHandling::onDropFileCallback(GLFWwindow *window, int count, const char **paths) {
        for (int i = 0; i < count; i++) {
            //TODO: here add drop file callback
        }
    }

    MouseEventHandling *ThreeDBodyMouseEventHandling::getInstance() {
        if (instance_ == nullptr) {
            instance_ = new ThreeDBodyMouseEventHandling();
            instance_->x_ = 0;
            instance_->y_ = 0;
#ifdef GF_CUSTOM_CURSOR
            ///implement your custom cursor setup function by setting images and x and y dimension.
            ///then you can pass to getCreateCustomCursor function of GLFW.
            ///to destroy your custom cursor use getStandardCursor(0).
            ///@see GLFW/glfw3.h
#endif
        }
        return instance_;
    }


}

