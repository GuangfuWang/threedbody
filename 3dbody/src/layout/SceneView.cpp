#include "include/layout/ViewPort/SceneView.h"
#include "util/Log.h"


namespace gf {

    void SceneView::resize(int32_t width, int32_t height) {
        mSize.x = width;
        mSize.y = height;
        mFrameBuffer->createBuffers((int32_t) mSize.x, (int32_t) mSize.y);
    }

    void SceneView::loadMesh(const std::string &filepath) {
        if (!mMesh)
            mMesh = std::make_shared<Mesh>();

        mMesh->load(filepath);

    }

    void SceneView::render() {

        mShader->use();

        mLight->update(mShader.get());

        mFrameBuffer->bind();

        if (mMesh) {
            mMesh->update(mShader.get());
            mMesh->render();
        }

        mFrameBuffer->unbind();

        ImGui::Begin("Model View");

        ImVec2 viewportPanelSize = ImGui::GetContentRegionAvail();
        mSize = {viewportPanelSize.x, viewportPanelSize.y};

//  mCamera->setAspect(mSize.x,mSize.y<1?1:mSize.y);
//        if (mMesh) {
//            mCamera->setScenePositionInfo(mMesh->sceneCenter,
//                                          mMesh->sceneMinBox,
//                                          mMesh->sceneMaxBox);
//        }

        mCamera->update(mShader.get());

        // add rendered texture to ImGUI scene window
        uint64_t textureID = mFrameBuffer->getTexture();
        ImGui::Image(reinterpret_cast<void *>(textureID),
                     ImVec2{mSize.x, mSize.y},
                     ImVec2{0, 1},
                     ImVec2{1, 0});

        ImGui::End();
    }
}

