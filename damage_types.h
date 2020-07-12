#pragma once

namespace damage_types {

    enum class DamageType {
        Fire,
        Water
    };

    template <class... Types>
    using DamageTypes = std::tuple<Types...>;
}
