#include "burning.h"
#include "../GameObject.h"

namespace effects {

void Burning::apply_status_effect(const std::unique_ptr<GameObject> object) {
    object->set_status<Burning>(*this);
}

void Burning::tick(const std::unique_ptr<GameObject> object) {
    // Apply burning damage
    object->take_damage<damage_types::DamageType::Fire>(potency);
}

}
