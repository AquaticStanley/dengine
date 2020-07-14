#pragma once

#include "abstract_surface.h"
#include "../status_effects/burning.h"

namespace surfaces {

class Fire : public AbstractSurface {
public:
    virtual void apply_surface_effect(GameObject& object);
};

}
