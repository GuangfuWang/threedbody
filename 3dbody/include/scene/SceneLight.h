//
// Created by lenovo on 2021/11/19.
//

#ifndef INC_3DBODY_SCENE_LIGHT_H
#define INC_3DBODY_SCENE_LIGHT_H

#include "include/scene/SceneCamera.h"
#include "include/shader/Shader.h"

namespace gf {

class Light : public EventHandleBase {
 public:

  Light() {
    mColor = glm::vec3(1.0f, 1.0f, 1.0f);
    mPosition = {1.5f, 3.5f, 3.0f};
    mStrength = 100.0f;
  }

  ~Light() {}

  void update(Shader *shader) override {
    shader->set_vec3(mPosition, "lightPosition");
    shader->set_vec3(mColor * mStrength, "lightColor");
  }

  glm::vec3 mPosition;

  glm::vec3 mColor;

  float mStrength;

};

}

#endif //INC_3DBODY_SCENE_LIGHT_H
