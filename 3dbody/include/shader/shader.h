
#ifndef INC_3DBODY_3DBODY_INCLUDE_SHADER_SHADER_H_
#define INC_3DBODY_3DBODY_INCLUDE_SHADER_SHADER_H_

#include "pch.hpp"

namespace gf {

class Shader {

 private:
  unsigned int mProgramId;

  unsigned int get_compiled_shader(unsigned int shader_type, const std::string &shader_source);

 public:
  Shader() = default;

  // Load a vertex and a fragment shader from file
  bool load(const std::string &vertexshader_file, const std::string &fragmentshader_file);

  // Use the program
  void use();

  // Delete the program
  void unload();

  unsigned int get_program_id() { return mProgramId; }

  void set_mat4(const glm::mat4 &mat4, const std::string &name);

  void set_i1(int v, const std::string &name);
  void set_f1(float v, const std::string &name);
  void set_f3(float a, float b, float c, const std::string &name);

  void set_vec3(const glm::vec3 &vec3, const std::string &name);
  void set_vec4(const glm::vec4 &vec4, const std::string &name);

};

}

#endif //INC_3DBODY_3DBODY_INCLUDE_SHADER_SHADER_H_
