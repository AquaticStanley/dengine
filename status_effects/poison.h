#pragma once

#include "base_status_effect.h"
#include "../damage_types.h"
#include <iostream>

namespace effects {

class Poison : public BaseStatusEffect<Poison> {
public:
    Poison(int potency) : BaseStatusEffect<Poison>(3, potency, potency/-3) {}
    void apply_status_effect(GameObject& object);

    void tick(GameObject& object);

    std::string to_str() const { return "Poisoned"; }
};

}
