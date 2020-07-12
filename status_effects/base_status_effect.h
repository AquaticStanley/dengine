#pragma once

#include "../GameObject.h"
#include <memory>
#include <cstdlib>

class GameObject;

namespace effects {

template <class Derived>
class BaseStatusEffect {
public:
    ~BaseStatusEffect() {}
    void apply_status_effect(const std::unique_ptr<GameObject> object) {
        static_cast<Derived*>(this)->apply_status_effect(object);
    }

    bool operator >(const BaseStatusEffect<Derived>& rhs) {
        if(abs(potency_ * duration_) > abs(rhs.potency_ * rhs.duration_)) {
            return true;
        }
    }

    bool operator <(const BaseStatusEffect<Derived>& rhs) {
        return !(this->operator<(rhs));
    }

    bool operator ==(const BaseStatusEffect<Derived>& rhs) {
        return abs(potency_ * duration_) == abs(rhs.potency_ * rhs.duration_);
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
