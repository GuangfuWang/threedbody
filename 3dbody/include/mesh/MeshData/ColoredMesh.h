
#ifndef INC_3DBODY_COLOREDMESH_H
#define INC_3DBODY_COLOREDMESH_H

#include "MeshBase.h"

namespace gf {

    class ColoredMesh : public MeshBase {
    public:
        void update(Shader *shader) override ;

        bool load(const string &filepath) override;

        void init();

        void createBuffers();

        void deleteBuffers();

        ~ColoredMesh() override;

    private:
        bool inited = false;
    };



}


#endif //INC_3DBODY_COLOREDMESH_H
