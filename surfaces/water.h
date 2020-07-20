#pragma once

#include "abstract_surface.h"
#include "../surfaces/fire.h"

namespace surfaces {

class Water : public AbstractSurface {
public:
    Water(int potency = 0) : AbstractSurface(potency) {}
    virtual void apply_surface_effect(GameObject& object) { (void)object; }
    virtual SurfaceType surface_type() const { return SurfaceType::Water; }
};

}