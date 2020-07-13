#include "GameObject.h"

void GameObject::trigger_status_effects() {
    std::apply([this](auto& ...status_effect) {
        (..., trigger_status_effect<typename std::decay<decltype(status_effect)>::type::value_type>());
    }, status_effects_);
}
