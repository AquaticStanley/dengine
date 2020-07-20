#pragma once

#include "abstract_surface.h"
#include "../status_effects/burning.h"

namespace surfaces {

class Fire : public AbstractSurface {
public:
    Fire(int potency) : AbstractSurface(potency) {}
    virtual void apply_surface_effect(GameObject& object);
    virtual SurfaceType surface_type() const { return SurfaceType::Fire; }
};

}
