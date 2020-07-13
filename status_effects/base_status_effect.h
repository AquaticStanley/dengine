#pragma once

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

    void tick(const std::unique_ptr<GameObject> object) {
        static_cast<Derived*>(this)->tick(object);
        duration_ -= 1;
        potency_ += potency_change_rate_;
    }

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
