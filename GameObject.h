#pragma once

#include <optional>
#include <tuple>
#include <unordered_map>
#include <type_traits>
#include "status_effects/status_effects.h"
#include "damage_types.h"
#include <iostream>

class GameObject {
public:
    using Resistances = std::unordered_map<damage_types::DamageType, double>;

    template <class... StatusEffects>
    using StatusEffects = std::tuple<std::optional<StatusEffects>...>;
public:
    GameObject(int hp, const Resistances& resistances = Resistances())
    : hp_(hp)
    , resistances_(resistances)
    {}

public:
    template <damage_types::DamageType type>
    void take_damage(int damage);

    // Interactions between status effects should go here.
    template <class StatusEffect>
    void set_status(StatusEffect effect);

    void trigger_status_effects();

public:
    // Debugging
    int hp() const { return hp_; }

    template <class StatusEffect>
    std::optional<StatusEffect>& get_status_effect() {
        return std::get<std::optional<StatusEffect>>(status_effects_);
    }

private:
    template <class StatusEffect>
    void trigger_status_effect();

private:
    int hp_;
    StatusEffects<effects::Burning, effects::Wet> status_effects_;
    Resistances resistances_;
};

#include "GameObject.hpp"
