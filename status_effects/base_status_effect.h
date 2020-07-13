#pragma once

#include <memory>
#include <cstdlib>
#include <iostream>

class GameObject;

namespace effects {

template <class Derived>
class BaseStatusEffect {
public:
    BaseStatusEffect(uint16_t duration, int potency, int potency_change_rate)
    : duration_(duration)
    , potency_(potency)
    , potency_change_rate_(potency_change_rate)
    {}

    ~BaseStatusEffect() {}

    void apply_status_effect(GameObject& object);

    void tick(GameObject& object);

    // This determines whether this instance of an effect should override another
    bool operator >(const BaseStatusEffect<Derived>& rhs) {
        if(potency_ == 0 && rhs.potency_ == 0) {
            return duration_ > rhs.duration_;
        } else {
            return abs(potency_ * duration_) > abs(rhs.potency_ * rhs.duration_);
        }
    }

    bool operator <(const BaseStatusEffect<Derived>& rhs) {
        return !(this->operator<(rhs));
    }

    bool operator ==(const BaseStatusEffect<Derived>& rhs) {
        if(potency_ == 0 && rhs.potency_ == 0) {
            return duration_ == rhs.duration_;
        } else {
            return abs(potency_ * duration_) == abs(rhs.potency_ * rhs.duration_);
        }
    }

    bool operator !=(const BaseStatusEffect<Derived>& rhs) {
        return !(this->operator==(rhs));
    }

protected:
    uint16_t duration_;
    int potency_;
    int potency_change_rate_;
};

}

#include "base_status_effect.hpp"
