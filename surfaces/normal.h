#pragma once

#include "abstract_surface.h"

namespace surfaces {

class NormalSurface : public AbstractSurface {
public:
    virtual void apply_surface_effect(GameObject& object) { (void)object; }
    virtual SurfaceType surface_type() const { return SurfaceType::Normal; }
};

}