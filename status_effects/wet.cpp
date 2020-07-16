#include "../GameObject.h"
#include "wet.h"

namespace effects {

void Wet::apply_status_effect(GameObject& object) {
    std::cout << "Got here" << std::endl;
    object.set_status<Wet>(*this);
}

}