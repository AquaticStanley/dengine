#pragma once

#include "base_status_effect.h"

namespace effects {

class Wet : public BaseStatusEffect<Wet> {
public:
    void apply_status_effect(GameObject& object);

    void tick(GameObject& object) { (void)object; }
};

}