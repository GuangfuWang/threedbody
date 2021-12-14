//
// Created by bigdata-wgf on 2021/12/10.
//

#ifndef INC_3DBODY_3DBODY_INCLUDE_SCENE_SCENEPROPERTY_H_
#define INC_3DBODY_3DBODY_INCLUDE_SCENE_SCENEPROPERTY_H_

#include "include/event_handling/EventBase.h"

namespace gf {

/**
 * @brief this class is used to setting all rendering related parameters.
 */

class SceneProperty : public EventHandleInterface {

 public:
  void update(Shader *shader) override;

 private:
  float metallic_;
  float roughness_;

};

}

#endif //INC_3DBODY_3DBODY_INCLUDE_SCENE_SCENEPROPERTY_H_
