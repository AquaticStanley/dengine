#pragma once

#include <functional>
#include <unordered_set>
#include <memory>
#include <SFML/System.hpp>
#include "../map/map.h"

namespace abilities {

struct hash_vector {
    size_t operator()(const sf::Vector2i& v) const {
        auto hash1 = std::hash<int>{}(v.x);
        auto hash2 = std::hash<int>{}(v.y);
        return hash1 ^ hash2;
    }
};

class AbstractAbility {
public:
    template <class T>
    using observer_ptr = T*;

    using pattern_set = std::unordered_set<sf::Vector2i, hash_vector>;
public:
    AbstractAbility(int potency, int min_range, int max_range, int size, int cooldown)
    : potency_(potency)
    , min_range_(min_range)
    , max_range_(max_range)
    , size_(size)
    , cooldown_(cooldown)
    {}

    virtual ~AbstractAbility() {}

    virtual void apply_ability_effect(map::Map& map, const sf::Vector2i& origin, const sf::Vector2i& destination) = 0;

    pattern_set default_pattern_coordinate_list(const map::Map& map, const sf::Vector2i& origin, int size) {
        pattern_set coordinates;
        if(map.tile_exists(origin)) {
            coordinates.emplace(origin);
            while(size > 0) {
                pattern_set coordinates_to_insert;
                for(auto& coordinate : coordinates) {
                    // Get tiles on all sides of this
                    if(auto up_coord = coordinate + sf::Vector2i{0, 1}; map.tile_exists(up_coord)) {
                        coordinates_to_insert.emplace(up_coord);
                    }
                    if(auto right_coord = coordinate + sf::Vector2i{1, 0}; map.tile_exists(right_coord)) {
                        coordinates_to_insert.emplace(right_coord);
                    }
                    if(auto down_coord = coordinate + sf::Vector2i{0, -1}; map.tile_exists(down_coord)) {
                        coordinates_to_insert.emplace(down_coord);
                    }
                    if(auto left_coord = coordinate + sf::Vector2i{-1, 0}; map.tile_exists(left_coord)) {
                        coordinates_to_insert.emplace(left_coord);
                    }
                }
                for(auto& coordinate : coordinates_to_insert) {
                    coordinates.emplace(coordinate);
                }
                --size;
            }
        }
        return coordinates;
    }

protected:
    int potency_;
    int min_range_;
    int max_range_;
    int size_;
    int cooldown_;
};

}
