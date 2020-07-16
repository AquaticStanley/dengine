#pragma once

#include "base_status_effect.h"

namespace effects {

class Wet : public BaseStatusEffect<Wet> {
public:
    Wet() : BaseStatusEffect<Wet>(1, 0, 0) {}
    void apply_status_effect(GameObject& object);

    void tick(GameObject& object) { (void)object; }
};

}