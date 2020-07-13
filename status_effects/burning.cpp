#include "../GameObject.h"
#include "burning.h"

namespace effects {

void Burning::apply_status_effect(GameObject& object) {
    object.set_status<Burning>(*this);
}

void Burning::tick(GameObject& object) {
    // Apply burning damage
    object.take_damage<damage_types::DamageType::Fire>(potency_);
}

}
