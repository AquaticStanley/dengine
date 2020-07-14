#pragma once

#include <memory>

class GameObject;

namespace surfaces {

class AbstractSurface {
public:
    virtual ~AbstractSurface() {}
    virtual void apply_surface_effect(GameObject& object) = 0;  // Should set damage/healing and effect on object
protected:
    uint16_t duration_;             // How many turns this surface lasts
    int potency_;                   // Potency
    int potency_change_rate_;       // How the potency changes from turn to turn
};

}
