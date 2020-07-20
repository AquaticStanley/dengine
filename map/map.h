#pragma once

#include <exception>
#include <memory>
#include "tile.h"
#include "../sf_helpers.h"

namespace map {

class Map {
public:
    template <class T>
    using observer_ptr = T*;

    using coordinate_set = std::unordered_set<sf::Vector2i, helpers::hash_vector>;
public:
    Map(const sf::Vector2i& dimensions)
    : width_(dimensions.x)
    , length_(dimensions.y)
    , map_(new Tile[dimensions.x*dimensions.y])
    {}

    coordinate_set get_object_move_tiles(const sf::Vector2i& object_coordinates) {
        coordinate_set coordinates;
        if(auto& object = get_tile(object_coordinates).get_contained_object()) {
            int remaining_movement = object->get_remaining_movement();

            // Get the tiles that this object can travel to
        }
    }

    bool move_object_from_to(const sf::Vector2i& origin, const sf::Vector2i& destination) {
        observer_ptr<GameObject> origin_object = get_tile(origin).get_contained_object();
        if(auto& dest_object = get_tile(destination).get_contained_object(); dest_object == nullptr) {
            // Get how many tiles were moved
            sf::Vector2i movement_vec = destination - origin;
            int movement_used = abs(movement_vec.x) + abs(movement_vec.y);
            dest_object = origin_object;
            dest_object->reduce_remaining_movement_by(movement_used);
            origin_object = nullptr;
            return true;
        }
        return false;
    }

    bool tile_exists(const sf::Vector2i& coordinates) const {
        return coordinates.x >= 0 && coordinates.x < width_ && coordinates.y >= 0 && coordinates.y < length_;
    }

    Tile& get_tile(const sf::Vector2i& coordinates) {
        return map_[coordinates.x + (coordinates.y * width_)];
    }

    std::string to_str() {
        std::string s = "";
        for(int len = length_- 1; len >= 0; --len) {
            for(int wid = 0; wid < width_; ++wid) {
                s += get_tile(sf::Vector2i{wid, len}).to_str() + " ";
            }
            s += "\n";
        }
        return s;
    }

private:
    int width_;
    int length_;
    std::unique_ptr<Tile[]> map_;
};

}
