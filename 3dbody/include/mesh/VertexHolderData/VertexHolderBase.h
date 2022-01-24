
#ifndef INC_3DBODY_VERTEXHOLDERBASE_H
#define INC_3DBODY_VERTEXHOLDERBASE_H

#include "def.h"

namespace gf {

    class VertexHolderBase {
    public:
        Vec mPos;

        virtual ~VertexHolderBase() = default;
    };

    typedef VertexHolderBase* VertexBuffer;

}

#endif //INC_3DBODY_VERTEXHOLDERBASE_H
