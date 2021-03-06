#include "include/event_handling/ApplicationEvent.h"
#include "include/layout/MainWindows/BaseWindow.h"

namespace gf {

    AppEventHandling *ThreeDBodyAppEventHandling::instance_ = nullptr;

    void onWindowSizeCallback(GLFWwindow *window, int width, int height) {
        ThreeDBodyAppEventHandling::getInstance()->onWindowSizeCallback(window, width, height);
    }

    void onWindowCloseCallback(GLFWwindow *window) {
        ThreeDBodyAppEventHandling::getInstance()->onWindowCloseCallback(window);
    }

    void ThreeDBodyAppEventHandling::onWindowSizeCallback(GLFWwindow *window, int width, int height) {
        auto pWindow = static_cast<BaseWindow *>(glfwGetWindowUserPointer(window));
        pWindow->setWidth(width);
        pWindow->setHeight(height);
        float aspect = (float) width/height;
        pWindow->getSceneView()->getCamera()->set_aspect(aspect);
        pWindow->getSceneView()->getCamera()->update(pWindow->getSceneView()->getShader());
        pWindow->render();
    }

    void ThreeDBodyAppEventHandling::onWindowCloseCallback(GLFWwindow *window) {
        BaseWindow *pWindow = static_cast<BaseWindow *>(glfwGetWindowUserPointer(window));
        pWindow->setRunningStatus(false);
    }

    AppEventHandling *ThreeDBodyAppEventHandling::getInstance() {
        if (instance_ == nullptr) {
            instance_ = new ThreeDBodyAppEventHandling();
        }
        return instance_;
    }

}
