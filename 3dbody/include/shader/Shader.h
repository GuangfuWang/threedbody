
#ifndef INC_3DBODY_3DBODY_INCLUDE_SHADER_SHADER_H_
#define INC_3DBODY_3DBODY_INCLUDE_SHADER_SHADER_H_

#include "pch.hpp"

namespace gf {

    class Shader {

    private:
        unsigned int mProgramId;

        unsigned int getCompiledShader(unsigned int shader_type, const std::string &shader_source);

    public:
        Shader() = default;

        bool load(const std::string &vertexshader_file, const std::string &fragmentshader_file);

        void use();

        void unload();

        unsigned int getProgramId() { return mProgramId; }

        void setMat4(const glm::mat4 &mat4, const std::string &name);

        void setI1(int v, const std::string &name);

        void setF1(float v, const std::string &name);

        void setF3(float a, float b, float c, const std::string &name);

        void setVec3(const glm::vec3 &vec3, const std::string &name);

        void setVec4(const glm::vec4 &vec4, const std::string &name);

    };

}

#endif //INC_3DBODY_3DBODY_INCLUDE_SHADER_SHADER_H_
