#pragma once

#include "abstract_ability.h"
#include "../surfaces/water.h"

namespace abilities {

class Rain : public AbstractAbility {
public:
    Rain()
    : AbstractAbility(0, 0, 5, 2, 5)
    {}

    virtual void apply_ability_effect(map::Map& map, const sf::Vector2i& origin, const sf::Vector2i& destination) {
        (void)origin;
        // Get all tiles in area of effect
        auto coords = default_pattern_coordinate_list(map, destination, size_);
        // std::cout << coords << std::endl;
        for(auto& coord : coords) {
            // Get tile
            map::Tile& tile = map.get_tile(coord);

            // Set status effect
            if(observer_ptr<GameObject> object = tile.get_contained_object()) {
                object->set_status<effects::Wet>(effects::Wet());
            }

            // Set surface
            tile.collide_with_surface(std::make_unique<surfaces::Water>());
        }
    }
};

}