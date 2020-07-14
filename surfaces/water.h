#pragma once

#include "abstract_surface.h"

namespace surfaces {

class Water : public AbstractSurface {
public:
    virtual void apply_surface_effect(GameObject& object) {}
    virtual SurfaceType surface_type() const { return SurfaceType::Water; }
};

}