
#ifndef INC_3DBODY_3DBODY_INCLUDE_MESH_VERTEXHOLDER_H_
#define INC_3DBODY_3DBODY_INCLUDE_MESH_VERTEXHOLDER_H_

#include "pch.hpp"
#include "include/mesh/VertexHolderData/VertexHolderBase.h"

namespace gf {

    class VanillaVertexHolder final: public VertexHolderBase {

    public:
        VanillaVertexHolder() : mNormal() {
            mPos = Vec();
        }

        VanillaVertexHolder(const Vec &pos, const Vec &normal)
                : mNormal(normal) {
            mPos = Vec();
        }

        ~VanillaVertexHolder() = default;

        Vec mNormal;
    };

    class VanillaVertexHolderWONormal final: public VertexHolderBase {
    public:
        VanillaVertexHolderWONormal() {
            mPos = Vec();
        }

        VanillaVertexHolderWONormal(const Vec &pos, const Vec &normal) {
            mPos = Vec();
        }

        ~VanillaVertexHolderWONormal() = default;
    };

}

#endif //INC_3DBODY_3DBODY_INCLUDE_MESH_VERTEXHOLDER_H_
