#pragma once

#include <memory>

class GameObject;

namespace surfaces {

enum class SurfaceType {
    Normal,
    Fire,
    Water,
    Poison
};

class AbstractSurface {
public:
    virtual ~AbstractSurface() {}
    virtual void apply_surface_effect(GameObject& object) = 0;  // Should set damage/healing and effect on object
    virtual SurfaceType surface_type() const = 0;

    uint16_t duration() const { return duration_; }
    int potency() const { return potency_; }
protected:
    uint16_t duration_;             // How many turns this surface lasts
    int potency_;                   // Potency
    int potency_change_rate_;       // How the potency changes from turn to turn
};

}
