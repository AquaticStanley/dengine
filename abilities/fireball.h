#pragma once

#include "abstract_ability.h"

namespace abilities {

class Fireball : public AbstractAbility {
public:
    virtual void apply_ability_effect(map::Map& map, const sf::Vector2i& origin, const sf::Vector2i& destination) {
        // Get all tiles in area of effect
        
    }
}

}