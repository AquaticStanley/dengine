#pragma once

#include "abstract_ability.h"

namespace abilities {

class Fireball : public AbstractAbility {
public:
    virtual void apply_ability_effect(map::Map& map, const sf::Vector2i& origin, const sf::Vector2i& destination) {
        (void)origin;
        // Get all tiles in area of effect
        auto coords = default_pattern_coordinate_list(map, destination, size_);
        for(auto& coord : coords) {
            // Get tile
            map::Tile& tile = map.get_tile(coord);

            // Deal damage
            if(observer_ptr<GameObject> object = tile.get_contained_object()) {
                object->take_damage<damage_types::DamageType::Fire>(potency_);
            }

            // Set surface
            map.get_tile(coord).collide_with_surface(std::make_unique<surfaces::Fire>());
        }
    }
};

}
