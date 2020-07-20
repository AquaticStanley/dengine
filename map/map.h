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

    using coordinate_map = std::unordered_map<sf::Vector2i, int, helpers::hash_vector>;
    using coordinate_set = std::unordered_set<sf::Vector2i, helpers::hash_vector>;
public:
    Map(const sf::Vector2i& dimensions)
    : width_(dimensions.x)
    , length_(dimensions.y)
    , map_(new Tile[dimensions.x*dimensions.y])
    {}

    coordinate_set get_object_move_tiles(const sf::Vector2i& object_coordinates) {
        coordinate_set complete_coordinates;
        coordinate_map coordinates_to_test;
        if(auto& object = get_tile(object_coordinates).get_contained_object()) {
            int remaining_movement = object->get_remaining_movement();
            coordinates_to_test[object_coordinates] = remaining_movement;

            while(!coordinates_to_test.empty()) {
                // Get the tiles that this object can travel to
                for(auto& [coordinate, remaining_movement] : coordinates_to_test) {
                    // Get tiles on all sides of this that we can move into and move them into test coords
                    if(auto up_coord = coordinate + sf::Vector2i{0, 1}; tile_exists(up_coord)) {
                        auto& tile = get_tile(up_coord);
                        if(tile.movement_penalty() <= remaining_movement) {
                            coordinates_to_test[up_coord] = remaining_movement - tile.movement_penalty();
                        }
                    }
                    if(auto right_coord = coordinate + sf::Vector2i{1, 0}; tile_exists(right_coord)) {
                        auto& tile = get_tile(right_coord);
                        if(tile.movement_penalty() <= remaining_movement) {
                            coordinates_to_test[right_coord] = remaining_movement - tile.movement_penalty();
                        }
                    }
                    if(auto down_coord = coordinate + sf::Vector2i{0, -1}; tile_exists(down_coord)) {
                        auto& tile = get_tile(down_coord);
                        if(tile.movement_penalty() <= remaining_movement) {
                            coordinates_to_test[down_coord] = remaining_movement - tile.movement_penalty();
                        }
                    }
                    if(auto left_coord = coordinate + sf::Vector2i{-1, 0}; tile_exists(left_coord)) {
                        auto& tile = get_tile(left_coord);
                        if(tile.movement_penalty() <= remaining_movement) {
                            coordinates_to_test[left_coord] = remaining_movement - tile.movement_penalty();
                        }
                    }

                    // Move this coordinate into the master
                    complete_coordinates.emplace(coordinate);

                    // Remove this coordinate from the test map
                    coordinates_to_test.erase(coordinate);
                }
            }
        }
        return complete_coordinates;
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
