#include "../GameObject.h"
#include "fire.h"

namespace surfaces {

void Fire::apply_surface_effect(GameObject& object) {
    object.set_status<effects::Burning>(effects::Burning());
    object.take_damage<damage_types::DamageType::Fire>(potency_);
}

}