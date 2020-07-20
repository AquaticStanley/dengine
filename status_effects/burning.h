#pragma once

#include "base_status_effect.h"
#include "../damage_types.h"
#include <iostream>

namespace effects {

class Burning : public BaseStatusEffect<Burning> {
public:
    Burning(int potency) : BaseStatusEffect<Burning>(2, potency, 0) {}
    void apply_status_effect(GameObject& object);

    void tick(GameObject& object);

    std::string to_str() const { return "Burning"; }
};

}
