#pragma once

#include "../GameObject.h"
#include <memory>

namespace surfaces {

class AbstractSurface {
public:
    virtual ~AbstractSurface() {}
    virtual void apply_surface_effect(const std::unique_ptr<GameObject> object) = 0;  // Should set damage/healing and effect on object
protected:
    uint16_t size_;                 // How many tiles away from the originating tile this surface takes up
    uint16_t duration_;             // How many turns this surface lasts
    int potency_;                   // Potency if we were standing directly on the originating tile
    double potency_distance_decay_; // Multiplier applied to the potency every tile away from the originating tile
    int potency_change_rate_;       // How the potency changes from turn to turn
};

}
