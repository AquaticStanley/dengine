#pragma once

#include "abstract_ability.h"

namespace abilities {

class Fireball : public AbstractAbility {
public:
    virtual void apply_ability_effect(Map& map) {}
}

}