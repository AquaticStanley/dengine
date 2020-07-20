#pragma once

#include <SFML/System.hpp>

namespace helpers {

struct hash_vector {
    size_t operator()(const sf::Vector2i& v) const {
        auto hash1 = std::hash<int>{}(v.x);
        auto hash2 = std::hash<int>{}(v.y);
        return hash1 ^ hash2;
    }
};

}
