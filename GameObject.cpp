#include "GameObject.h"

void GameObject::trigger_status_effects() {
    std::apply([this](auto& ...status_effect) {
        (..., trigger_status_effect<typename std::decay<decltype(status_effect)>::type::value_type>());
    }, status_effects_);
}

void GameObject::output_status_effects() {
    std::apply([this](auto& ...status_effect) {
        (..., output_status_effect<typename std::decay<decltype(status_effect)>::type::value_type>());
    }, status_effects_);
}

int GameObject::get_remaining_movement() const {
    return data_.remaining_movement_;
}

void GameObject::reduce_remaining_movement_by(int reduce) {
    data_.remaining_movement_ -= reduce;
}