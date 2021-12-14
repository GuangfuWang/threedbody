#include "include/scene/SceneProperty.h"

namespace gf {

void SceneProperty::update(Shader *shader) {
  shader->setF1(metallic_, "metallic");
  shader->setF1(roughness_, "roughness");
}

}
