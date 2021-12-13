#include "include/algorithms/MyContainer.h"

namespace gf {

unsigned int MyContainer::count_ = 0;

unsigned int MyContainer::totalRegistered_ = 0;

unsigned int MyContainer::container_ = 0;

bool MyContainer::noUnregistered = true;

MyContainer *MyContainer::instance_ = nullptr;

MyContainer::MyContainer() {
///do nothing for singleton.
}

}
