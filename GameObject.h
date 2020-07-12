#pragma once

#include <optional>
#include <tuple>
#include <unordered_map>
#include <type_traits>
#include "status_effects/status_effects.h"
#include "damage_types.h"

class GameObject {
public:
    using Resistances = std::unordered_map<damage_types::DamageType, double>;

    template <class... StatusEffects>
    using StatusEffects = std::tuple<std::optional<StatusEffects>...>;
public:
    template <damage_types::DamageType type>
    void take_damage(int damage) {
        // Look up resistance, and decrease damage by that amount
        damage *= resistances_[type];
        hp_ -= damage;
    }

    template <class StatusEffect>
    void set_status(StatusEffect effect) {
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

private:
    StatusEffects<effects::Burning, effects::Wet> status_effects_;
    Resistances resistances_;
    int hp_;
};
