#include "include/scene/SceneProperty.h"

namespace gf{

void SceneProperty::update(Shader *shader) {
	shader->set_f1(metallic_,"metallic");
	shader->set_f1(roughness_,"roughness");
}


}
