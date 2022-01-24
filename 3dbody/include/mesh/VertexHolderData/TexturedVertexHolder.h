
#ifndef INC_3DBODY_TEXTUREDVERTEXHOLDER_H
#define INC_3DBODY_TEXTUREDVERTEXHOLDER_H

#include "include/mesh/VertexHolderData/VertexHolderBase.h"

namespace gf {

    class TexturedVertexHolder final : public VertexHolderBase {
    public:
        TexturedVertexHolder() : mNormal(), mTextureCoordinate() {
            mPos = Vec();
        }

        TexturedVertexHolder(const Vec &pos,
                             const Vec &normal,
                             const Vec2i &textureCoordinate) :
                mNormal(normal), mTextureCoordinate(textureCoordinate) {
            mPos = pos;
        }

        ~TexturedVertexHolder() = default;

    public:
        Vec   mNormal;
        Vec2i mTextureCoordinate;
    };

    class TexturedVertexHolderWONormal final : public VertexHolderBase {
    public:
        TexturedVertexHolderWONormal() : mTextureCoordinate() {
            mPos = Vec();
        }

        TexturedVertexHolderWONormal(const Vec &pos,
                                     const Vec2i &textureCoordinate) :
                mTextureCoordinate(textureCoordinate) {
            mPos = pos;
        }

        ~TexturedVertexHolderWONormal() = default;

    public:
        Vec2i mTextureCoordinate;
    };


}

#endif //INC_3DBODY_TEXTUREDVERTEXHOLDER_H
