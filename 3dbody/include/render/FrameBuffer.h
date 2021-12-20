
#ifndef INC_3DBODY_3DBODY_INCLUDE_RENDER_FRAMEBUFFER_H_
#define INC_3DBODY_3DBODY_INCLUDE_RENDER_FRAMEBUFFER_H_

#include <cstdint>
#include "util/Log.h"
#include "def.h"

namespace gf {

    class FrameBuffer {
    public:
        FrameBuffer() : mFBO{0}, mDepthId{0} {}

        virtual void createBuffers(int32_t width, int32_t height) = 0;

        virtual void deleteBuffers() = 0;

        virtual void bind() = 0;

        virtual void unbind() = 0;

        virtual uint32_t getTexture() = 0;

    protected:
        uint32_t mFBO     = 0;
        uint32_t mTexId   = 0;
        uint32_t mDepthId = 0;
        int32_t  mWidth   = 0;
        int32_t  mHeight  = 0;
    };

    class GF_DEPRECATED_MSG("Use OpenGL_AntiAliasingFrameBuffer instead!") OpenGL_FrameBuffer : public FrameBuffer {
    public:

        GF_DEPRECATED void createBuffers(int32_t width, int32_t height) override;

        GF_DEPRECATED void deleteBuffers() override;

        GF_DEPRECATED void bind() override;

        GF_DEPRECATED void unbind() override;

        GF_DEPRECATED uint32_t getTexture() override;
    };

    class OpenGL_AntiAliasingFrameBuffer final : public FrameBuffer {
    public:

        void createBuffers(int32_t width, int32_t height) override;

        void deleteBuffers() override;

        void bind() override;

        void unbind() override;

        uint32_t getTexture() override;

    public:
        uint32_t intermediateFBO;
        uint32_t screenTexture;
    };

}

#endif //INC_3DBODY_3DBODY_INCLUDE_RENDER_FRAMEBUFFER_H_
