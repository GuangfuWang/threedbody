
#include "include/layout/ThreeDBodyWindow.h"
#include "include/scene/SceneCamera.h"

namespace gf {

bool ThreeDBodyWindow::init(int width, int height, const string &title) {
  this->mWidth  = width;
  this->mHeight = height;
  this->mTitle  = title;

  mRenderCtx->init(this);

  mUICtx->init(this);

  mSceneView = std::make_unique<SceneView>();

  mContentBrowser = std::make_unique<ContentBrowser>();

  mPropertyPanel = std::make_unique<Property_Panel>();

  mPropertyPanel->setMeshLoadCallback(
	  [this](std::string filepath) { mSceneView->loadMesh(filepath); });

  return mIsRunning;
}

ThreeDBodyWindow::~ThreeDBodyWindow() {
  mUICtx->end();

  mRenderCtx->end();
}

void ThreeDBodyWindow::onResize(int width, int height) {
  this->mWidth  = width;
  this->mHeight = height;

  mSceneView->resize(width, height);
  render();
}

void ThreeDBodyWindow::onScroll(double delta) {
  mSceneView->onMouseWheel(delta);
}

void ThreeDBodyWindow::onMouseButton(unsigned char code) {

}

void ThreeDBodyWindow::onKey(int key, int scancode, int action, int mods) {
  if (action==GLFW_PRESS) {

  }
}

void ThreeDBodyWindow::onClose() {
  mIsRunning = false;
}

void ThreeDBodyWindow::render() {
  // Clear the view
  mRenderCtx->preRender();

  // Initialize UI components
  mUICtx->preRender();

  // render scene to framebuffer and add it to scene view
  mSceneView->render();

  if (this->contentBrowserOpen){
	mContentBrowser->render(&(this->contentBrowserOpen));
  }

  mPropertyPanel->render(mSceneView.get());

  // Render the UI
  mUICtx->postRender();

  // Render end, swap buffers
  mRenderCtx->postRender();

  //handleInput();
}

void ThreeDBodyWindow::handleInput() {
  // TODO: move this and Camera to scene UI component?

  if (glfwGetKey(mWindow, GLFW_KEY_W)==GLFW_PRESS) {
	mSceneView->onMouseWheel(-0.4f);
  }

  if (glfwGetKey(mWindow, GLFW_KEY_S)==GLFW_PRESS) {
	mSceneView->onMouseWheel(0.4f);
  }

  if (glfwGetKey(mWindow, GLFW_KEY_F)==GLFW_PRESS) {
	mSceneView->resetView();
  }

  double x, y;
  glfwGetCursorPos(mWindow, &x, &y);

  mSceneView->onMouseMove(x, y, MouseInput::getPressedButton(mWindow));
}

}

