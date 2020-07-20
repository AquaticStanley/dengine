#include "../GameObject.h"
#include "poison.h"

namespace surfaces {

void Poison::apply_surface_effect(GameObject& object) {
    object.set_status<effects::Poison>(effects::Poison(potency_));
    object.take_damage<damage_types::DamageType::Poison>(potency_);
}

}