#pragma once

#include "base_status_effect.h"

namespace effects {

class Wet : public BaseStatusEffect<Wet> {
public:
    void apply_status_effect(const std::unique_ptr<GameObject> object) {
        // object->set_status<Wet>(*this);
    }
};

}