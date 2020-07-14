#include <iostream>
#include "surfaces/fire.h"
#include "surfaces/normal.h"
#include "GameObject.h"
#include "status_effects/status_effects.h"
#include "map/tile.h"

int main() {
	std::cout << "Test" << std::endl;
    GameObject object(200);
    surfaces::Fire fire;
    fire.apply_surface_effect(object);
    // effects::Burning burning;
    // object.set_status(burning);

    // std::cout << object.get_status_effect<effects::Burning>() << std::endl;
    std::optional<effects::Burning>& obj_burning = object.get_status_effect<effects::Burning>();
    std::cout << obj_burning->duration() << std::endl;
    std::cout << object.hp() << std::endl;
    object.trigger_status_effects();
    std::cout << obj_burning->duration() << std::endl;
    if(obj_burning.has_value()) {
        std::cout << "Didn't remove effect like I should have :(" << std::endl;
    }

    std::cout << object.hp() << std::endl;
}
