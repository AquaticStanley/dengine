#pragma once

#include "base_status_effect.h"
#include "../damage_types.h"

namespace effects {

class Burning : public BaseStatusEffect<Burning> {
public:
    void apply_status_effect(const std::unique_ptr<GameObject> object);

    void tick(const std::unique_ptr<GameObject> object);
};

}
