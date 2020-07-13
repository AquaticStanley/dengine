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
    } else if constexpr(std::is_same<StatusEffect, effects::Wet>::value) {
        // If burning, set not burning
        if(auto& burning = std::get<std::optional<effects::Burning>>(status_effects_)) {
            burning.reset();
        }
        else {
            auto& wet = std::get<std::optional<effects::Wet>>(status_effects_);
            if(!wet || (*wet) < effect) {
                wet = effect;
            }
        }
    }
}

template <class StatusEffect>
void GameObject::trigger_status_effect() {
    auto& status_effect = std::get<std::optional<StatusEffect>>(status_effects_);
    if(status_effect.has_value()) {
        static_cast<effects::BaseStatusEffect<StatusEffect>>(*status_effect).tick(*this);
    }
}
