#pragma once

#include "status_effects/status_effects.h"

template <damage_types::DamageType type>
void GameObject::take_damage(int damage) {
    // Look up resistance, and decrease damage by that amount
    damage *= resistances_[type];
    hp_ -= damage;
}

template <class StatusEffect>
void GameObject::set_status(StatusEffect effect) {
    if constexpr(std::is_same<StatusEffect, effects::Burning>::value) {
        // If wet, set not wet
        if(auto& wet = std::get<std::optional<effects::Wet>>(status_effects_)) {
            wet.reset();
        } else {
            auto& burning = std::get<std::optional<effects::Burning>>(status_effects_);
            if(!burning || (*burning) < effect) {
                burning = effect;
            }
        }
    }
}
