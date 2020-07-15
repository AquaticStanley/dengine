#pragma once

#include <exception>
#include <memory>
#include "tile.h"

namespace map {

class Map {
public:
    template <class T>
    using observer_ptr = T*;
public:
    Map(const sf::Vector2i& dimensions)
    : width_(dimensions.x)
    , length_(dimensions.y)
    , map_(new Tile[dimensions.x*dimensions.y])
    {}

    bool move_object_from_to(const sf::Vector2i& origin, const sf::Vector2i& destination) {
        observer_ptr<GameObject> origin_object = get_tile(origin).get_contained_object();
        if(auto dest_object = get_tile(destination).get_contained_object(); dest_object == nullptr) {
            dest_object = origin_object;
            origin_object = nullptr;
            return true;
        }
        return false;
    }

    bool tile_exists(const sf::Vector2i& coordinates) const {
        return coordinates.x < 0 || coordinates.x >= width_ || coordinates.y < 0 || coordinates.y >= length_;
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
