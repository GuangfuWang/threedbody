
#ifndef INC_3DBODY_3DBODY_INCLUDE_SCENE_SCENEVIEW_H_
#define INC_3DBODY_3DBODY_INCLUDE_SCENE_SCENEVIEW_H_

#include "def.h"
#include "imgui.h"
#include "include/scene/SceneLight.h"
#include "include/mesh/MeshData/VanillaMesh.h"
#include "include/render/RenderFrameBuffer/FrameBuffer.h"
#include "util/ConfigMap.h"

namespace gf {

    class SceneView {
    public:
        SceneView() :
                mCamera(nullptr), mFrameBuffer(nullptr), mShader(nullptr),
                mLight(nullptr), mSize(800, 600) {
            mFrameBuffer = createUniqueRef<OpenGL_AntiAliasingFrameBuffer>();
            mFrameBuffer->createBuffers(800, 600);
            mShader = createUniqueRef<Shader>();
            mShader->load(ConfigMap::getInstance()->resource_dir_ + "/shaders/vertex_shader/vertex_shader.glsl",
                          ConfigMap::getInstance()->resource_dir_ + "/shaders/fragment_shader/fs_pbr.glsl");
            mLight = createUniqueRef<Light>();

            mCamera = createUniqueRef<MyCamera>(Vec(0, 0, 3), 45.0f, 1.33f, 0.1f, 100.0f);
        }

        ~SceneView() {
            mShader->unload();
        }

        Light *getLight() { return mLight.get(); }

        MyCamera *getCamera() { return (MyCamera *) mCamera.get(); }

        Shader *getShader() { return mShader.get(); }

        FrameBuffer *getFrameBuffer() { return mFrameBuffer.get(); }

        void resize(int32_t width, int32_t height);

        void render();

        void loadMesh(const string &filepath);

        void setMesh(Ref<VanillaMesh> mesh) {
            mMesh = mesh;
        }

        Ref<VanillaMesh> getMesh() { return mMesh; }

        void resetView() {
        }

        const ImVec2 getSize() {
            ImVec2 ret{mSize.x, mSize.y};
            return ret;
        }

    private:
        Ref_Unique<MyCamera>                       mCamera;
        Ref_Unique<OpenGL_AntiAliasingFrameBuffer> mFrameBuffer;
        Ref_Unique<Shader>                         mShader;
        Ref_Unique<Light> mLight;
        Ref<VanillaMesh>  mMesh;
        glm::vec2         mSize;
    };
}

#endif //INC_3DBODY_3DBODY_INCLUDE_SCENE_SCENEVIEW_H_
