#pragma once

#include "abstract_surface.h"

namespace surfaces {

class Fire : public AbstractSurface {
public:
    virtual void apply_surface_effect(const std::unique_ptr<GameObject> object) {}
};

}