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
    Tile() : object_(nullptr), surface_(std::make_unique<surfaces::NormalSurface>()) {}

    void collide_with_surface(std::unique_ptr<surfaces::AbstractSurface> rhs) {
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

            case surfaces::SurfaceType::Poison:
                //Explode
                if(object_) {
                    object_->set_status<effects::Burning>(effects::Burning(surface_->potency()));
                    object_->take_damage<damage_types::DamageType::Explosion>(surface_->potency() + rhs->potency());
                }
                break;

            default:
                break;
            }
            break;

        case surfaces::SurfaceType::Water:
            switch(rhs_surface_type) {
            case surfaces::SurfaceType::Fire:
                surface_ = std::make_unique<surfaces::NormalSurface>();
                break;

            default:
                break;
            }
            break;

        case surfaces::SurfaceType::Poison:
            switch(rhs_surface_type) {
            case surfaces::SurfaceType::Fire:
                // Explode
                if(object_) {
                    object_->set_status<effects::Burning>(effects::Burning(rhs->potency()));
                    object_->take_damage<damage_types::DamageType::Explosion>(surface_->potency() + rhs->potency());
                }
                surface_.swap(rhs);
                break;

            default:
                break;
            }
        default:
            break;
        }
    }

    observer_ptr<GameObject>& get_contained_object() {
        return object_;
    }

    void set_contained_object(GameObject& object) {
        object_ = &object;
    }

    std::string to_str() const {
        switch(surface_->surface_type()) {
        case surfaces::SurfaceType::Water:
            return "W";
            break;
        case surfaces::SurfaceType::Fire:
            return "F";
            break;
        case surfaces::SurfaceType::Normal:
            return ".";
            break;
        case surfaces::SurfaceType::Poison:
            return "P";
            break;
        default:
            return "%";
            break;
        }
    }

private:
    observer_ptr<GameObject> object_;
    std::unique_ptr<surfaces::AbstractSurface> surface_;
};

}
