#pragma once

namespace effects {

template <class Derived>
void BaseStatusEffect<Derived>::apply_status_effect(GameObject& object) {
    static_cast<Derived*>(this)->apply_status_effect(object);
}

template <class Derived>
void BaseStatusEffect<Derived>::tick(GameObject& object) {
    std::cout << "test" << std::endl;
    static_cast<Derived*>(this)->tick(object);
    duration_ -= 1;
    potency_ += potency_change_rate_;
}

}