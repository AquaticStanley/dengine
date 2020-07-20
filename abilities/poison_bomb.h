#pragma once

#include "abstract_ability.h"

namespace abilities {

class PoisonBomb : public AbstractAbility {
public:
    PoisonBomb()
    : AbstractAbility(100, 0, 5, 2, 5)
    {}

    virtual void apply_ability_effect(map::Map& map, const sf::Vector2i& origin, const sf::Vector2i& destination) {
        (void)origin;
        // Get all tiles in area of effect
        auto coords = default_pattern_coordinate_list(map, destination, size_);
        for(auto& coord : coords) {
            // Get tile
            map::Tile& tile = map.get_tile(coord);

            // Deal damage and set status effect
            if(observer_ptr<GameObject> object = tile.get_contained_object()) {
                object->take_damage<damage_types::DamageType::Poison>(potency_);
                object->set_status<effects::Poison>(effects::Poison());
            }

            // Set surface
            tile.collide_with_surface(std::make_unique<surfaces::Poison>());
        }
    }
};

}