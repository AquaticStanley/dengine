#pragma once

#include <memory>

namespace abilities {

class AbstractAbility {
public:
    virtual ~AbstractAbility() {}

    // Note: this needs to be changed to take a map and a position.
    virtual void apply_ability_effect(Map& map) {}
protected:
    int potency_;
    int min_range_;
    int max_range_;
    int size_;
    int cooldown_;
};

}
