#pragma once

#include <memory>
#include "../GameObject.h"
#include "../surfaces/abstract_surface.h"

namespace map {

class Tile {
public:
    template <class T>
    using observer_ptr = T*;
public:
    void collide_with_surface(std::unique_ptr<surfaces::AbstractSurface>& rhs) {
        auto this_surface_type = surface_->surface_type();
        auto rhs_surface_type = rhs->surface_type();

        // If surfaces are the same, apply surface with higher severity
        if(this_surface_type == rhs_surface_type) {
            if(surface_->potency() == 0 && rhs->potency() == 0) {
                if(surface_->duration() < rhs->duration()) {
                    surface_.swap(rhs);
                    return;
                }
            } else {
                if(abs(surface_->potency() * surface_->duration()) < abs(rhs->potency() * rhs->duration())) {
                    surface_.swap(rhs);
                    return;
                }
            }
        }

        // Jump table for surface collision handling
        switch(this_surface_type) {
        case surfaces::SurfaceType::Normal:
            surface_.swap(rhs);
            break;

        case surfaces::SurfaceType::Fire:
            switch(rhs_surface_type) {
            case surfaces::SurfaceType::Water:
                surface_ = std::make_unique<surfaces::NormalSurface>();
                break;

            default:
                break;
            }

        case surfaces::SurfaceType::Water:
            switch(rhs_surface_type) {
                case surfaces::SurfaceType::Fire:
                    surface_ = std::make_unique<surfaces::NormalSurface>();
                    break;

                default:
                    break;
            }
            break;

        default:
            break;
        }
    }

    observer_ptr<GameObject> get_contained_object() {
        return object_;
    }

private:
    observer_ptr<GameObject> object_;
    std::unique_ptr<surfaces::AbstractSurface> surface_;
};

}
