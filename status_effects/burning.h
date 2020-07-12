#pragma once

#include "base_status_effect.h"

namespace effects {

class Burning : public BaseStatusEffect<Burning> {
public:
    void apply_status_effect(const std::unique_ptr<GameObject> object) {
        // object->set_status<Burning>(*this);
    }
};

}
