#pragma once

#include <optional>
#include <tuple>
#include <unordered_map>
#include <type_traits>
#include "GameObjectData.h"
#include "status_effects/status_effects.h"
#include "damage_types.h"
#include <iostream>

class GameObject {
public:
    using Resistances = std::unordered_map<damage_types::DamageType, double>;

    template <class... StatusEffects>
    using StatusEffects = std::tuple<std::optional<StatusEffects>...>;
public:
    GameObject(const data::GameObjectData& data)
    : data_(data)
    {}

public:
    template <damage_types::DamageType type>
    void take_damage(int damage);

    template <class StatusEffect>
    void set_status(StatusEffect effect);

    void trigger_status_effects();

    void output_status_effects();

public:
    // Debugging
    int hp() const { return data_.hp_; }

    template <class StatusEffect>
    std::optional<StatusEffect>& get_status_effect() {
        return std::get<std::optional<StatusEffect>>(status_effects_);
    }

private:
    template <class StatusEffect>
    void trigger_status_effect();

    template <class StatusEffect>
    void output_status_effect();

private:
    data::GameObjectData data_;
    StatusEffects<effects::Burning, effects::Wet, effects::Poison> status_effects_;
};

#include "GameObject.hpp"
