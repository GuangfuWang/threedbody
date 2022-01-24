
#ifndef INC_3DBODY_COLOREDVERTEXHOLDER_H
#define INC_3DBODY_COLOREDVERTEXHOLDER_H

#include "def.h"
#include "include/mesh/VertexHolderData/VertexHolderBase.h"

namespace gf {

    class ColoredVertexHolder final : public VertexHolderBase {
    public:
        ColoredVertexHolder() : mNormal(), mColor() {
            mPos = Vec();
        }

        ColoredVertexHolder(const Vec &pos, const Vec &normal, const Vec &color)
                : mNormal(normal), mColor(color) {
            mPos = pos;
        }

        ~ColoredVertexHolder() = default;

        Vec mNormal;
        Vec mColor;
    };


    class ColoredVertexHolderWONormal final : public VertexHolderBase {
    public:
        ColoredVertexHolderWONormal() : mColor() {
            mPos = Vec();
        }

        ColoredVertexHolderWONormal(const Vec &pos, const Vec &color)
                : mColor(color) {
            mPos = pos;
        }

        ~ColoredVertexHolderWONormal() = default;

        Vec mColor;
    };
}

#endif //INC_3DBODY_COLOREDVERTEXHOLDER_H
