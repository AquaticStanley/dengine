#pragma once

#include "base_status_effect.h"
#include "../damage_types.h"
#include <iostream>

namespace effects {

class Burning : public BaseStatusEffect<Burning> {
public:
    Burning() : BaseStatusEffect<Burning>(1, 100, 0) {}
    void apply_status_effect(GameObject& object);

    void tick(GameObject& object);

    std::string to_str() const { return "Burning"; }
};

}
