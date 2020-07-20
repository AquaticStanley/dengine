#pragma once

#include <string>
#include "damage_types.h"

namespace data {

struct GameObjectData {
public:
    using Resistances = std::unordered_map<damage_types::DamageType, double>;

public:
    GameObjectData(int hp, int movement, std::string name, const Resistances& resistances = Resistances())
    : hp_(hp)
    , movement_(movement)
    , name_(name)
    , resistances_(resistances)
    {}

    int hp_;
    int movement_;
    std::string name_;
    Resistances resistances_;
};

}
