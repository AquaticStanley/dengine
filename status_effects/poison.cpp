#include "../GameObject.h"
#include "poison.h"

namespace effects {

void Poison::apply_status_effect(GameObject& object) {
    object.set_status<Poison>(*this);
}

void Poison::tick(GameObject& object) {
    // Apply poison damage
    object.take_damage<damage_types::DamageType::Poison>(potency_);
}

}