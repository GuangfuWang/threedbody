#ifndef GLEW_STATIC
#define GLEW_STATIC
#endif

#include <gl/glew.h>
#include "include/render/FrameBuffer.h"

namespace gf {

    void OpenGL_FrameBuffer::createBuffers(int32_t width, int32_t height) {
        mWidth  = width;
        mHeight = height;

        if (mFBO) {
            deleteBuffers();
        }

        glGenFramebuffers(1, &mFBO);
        glBindFramebuffer(GL_FRAMEBUFFER, mFBO);
        glCreateTextures(GL_TEXTURE_2D, 1, &mTexId);
        glBindTexture(GL_TEXTURE_2D, mTexId);

        glTexImage2D(GL_TEXTURE_2D, 0,
                     GL_RGB, mWidth, mHeight,
                     0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, mTexId, 0);

        glCreateTextures(GL_TEXTURE_2D, 1, &mDepthId);
        glBindTexture(GL_TEXTURE_2D, mDepthId);
        glTexStorage2D(GL_TEXTURE_2D, 1, GL_DEPTH24_STENCIL8, mWidth, mHeight);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_TEXTURE_2D, mDepthId, 0);

        GLenum buffers[4] = {GL_COLOR_ATTACHMENT0};
        glDrawBuffers(mTexId, buffers);
        unbind();
    }

    void OpenGL_FrameBuffer::deleteBuffers() {
        if (mFBO) {
            glDeleteFramebuffers(GL_FRAMEBUFFER, &mFBO);
            glDeleteTextures(1, &mTexId);
            glDeleteTextures(1, &mDepthId);
            mTexId   = 0;
            mDepthId = 0;
        }
    }

    void OpenGL_FrameBuffer::bind() {
        glBindFramebuffer(GL_FRAMEBUFFER, mFBO);
        glViewport(0, 0, mWidth, mHeight);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void OpenGL_FrameBuffer::unbind() {
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }

    uint32_t OpenGL_FrameBuffer::getTexture() {
        return mTexId;
    }

    void OpenGL_AntiAliasingFrameBuffer::createBuffers(int32_t width, int32_t height) {
        mWidth  = width;
        mHeight = height;

        if (mFBO) {
            deleteBuffers();
        }
        if(intermediateFBO){
            deleteBuffers();
        }

        //first multi-sample anti-aliasing frame buffer.
        glGenFramebuffers(1, &mFBO);
        glBindFramebuffer(GL_FRAMEBUFFER, mFBO);

        glGenTextures(1, &mTexId);
        glBindTexture(GL_TEXTURE_2D_MULTISAMPLE, mTexId);
        glTexImage2DMultisample(GL_TEXTURE_2D_MULTISAMPLE, 4, GL_RGB, mWidth, mHeight, GL_TRUE);
        glBindTexture(GL_TEXTURE_2D_MULTISAMPLE, 0);
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D_MULTISAMPLE,
                               mTexId, 0);

        // create a (also multi-sampled) renderbuffer object for depth and stencil attachments
        glGenRenderbuffers(1, &mDepthId);
        glBindRenderbuffer(GL_RENDERBUFFER, mDepthId);
        glRenderbufferStorageMultisample(GL_RENDERBUFFER, 4, GL_DEPTH24_STENCIL8, mWidth, mHeight);
        glBindRenderbuffer(GL_RENDERBUFFER, 0);
        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, mDepthId);

        if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
            GF_CORE_ERROR("ERROR::FRAMEBUFFER:: Framebuffer is not complete!")  ;
        glBindFramebuffer(GL_FRAMEBUFFER, 0);

        // configure second post-processing framebuffer
        glGenFramebuffers(1, &intermediateFBO);
        glBindFramebuffer(GL_FRAMEBUFFER, intermediateFBO);

        // create a color attachment texture
        glGenTextures(1, &screenTexture);
        glBindTexture(GL_TEXTURE_2D, screenTexture);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, mWidth, mHeight,
                     0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, screenTexture,
                               0);  // we only need a color buffer

        if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
            GF_CORE_ERROR("ERROR::FRAMEBUFFER:: Intermediate framebuffer is not complete!") ;
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }

    void OpenGL_AntiAliasingFrameBuffer::deleteBuffers() {
        if (mFBO) {
            glDeleteFramebuffers(GL_FRAMEBUFFER, &mFBO);
            glDeleteTextures(1, &mTexId);
            glDeleteTextures(1, &mDepthId);
            mTexId   = 0;
            mDepthId = 0;
        }
        if (intermediateFBO){
            glDeleteFramebuffers(GL_FRAMEBUFFER,&intermediateFBO);
            glDeleteTextures(1,&screenTexture);
            screenTexture = 0;
        }
    }

    void OpenGL_AntiAliasingFrameBuffer::bind() {
        glBindFramebuffer(GL_FRAMEBUFFER, mFBO);
        glViewport(0, 0, mWidth, mHeight);
        glClearColor(0.5f,0.5f,0.5f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void OpenGL_AntiAliasingFrameBuffer::unbind() {
        glBindFramebuffer(GL_READ_FRAMEBUFFER, mFBO);
        glBindFramebuffer(GL_DRAW_FRAMEBUFFER, intermediateFBO);
        glBlitFramebuffer(0, 0, mWidth, mHeight, 0, 0, mWidth, mHeight,
                          GL_COLOR_BUFFER_BIT, GL_LINEAR);
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
        glViewport(0,0,mWidth,mHeight);
    }

    uint32_t OpenGL_AntiAliasingFrameBuffer::getTexture() {
        return screenTexture;
    }
}
