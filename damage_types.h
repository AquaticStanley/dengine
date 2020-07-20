#pragma once

namespace damage_types {

    enum class DamageType {
        Physical,
        Fire,
        Water,
        Poison,
        Explosion
    };

    template <class... Types>
    using DamageTypes = std::tuple<Types...>;
}
