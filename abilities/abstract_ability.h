#pragma once

#include <memory>
#include <SFML/System.hpp>
#include "../map/map.h"

namespace abilities {

class AbstractAbility {
public:
    virtual ~AbstractAbility() {}

    virtual void apply_ability_effect(map::Map& map, const sf::Vector2i& origin, const sf::Vector2i& destination) = 0;

protected:
    int potency_;
    int min_range_;
    int max_range_;
    int size_;
    int cooldown_;
};

}
