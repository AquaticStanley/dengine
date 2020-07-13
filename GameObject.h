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
    void take_damage(int damage);

    template <class StatusEffect>
    void set_status(StatusEffect effect);

    void trigger_status_effects();

private:
    StatusEffects<effects::Burning, effects::Wet> status_effects_;
    Resistances resistances_;
    int hp_;
};

#include "GameObject.hpp"
