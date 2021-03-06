#pragma once

#include "abstract_surface.h"
#include "../status_effects/poison.h"

namespace surfaces {

class Poison : public AbstractSurface {
public:
    Poison(int potency) : AbstractSurface(potency) {}
    virtual void apply_surface_effect(GameObject& object);
    virtual SurfaceType surface_type() const { return SurfaceType::Poison; }
};

}