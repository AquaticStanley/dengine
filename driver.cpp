#include <iostream>
#include "surfaces/fire.h"
#include "surfaces/normal.h"
#include "GameObject.h"
#include "status_effects/status_effects.h"
#include "map/tile.h"
#include "abilities/abstract_ability.h"
#include "abilities/fireball.h"
#include "abilities/rain.h"

int main() {
	// std::cout << "Test" << std::endl;
 //    GameObject object(200);
 //    surfaces::Fire fire;
 //    fire.apply_surface_effect(object);
 //    // effects::Burning burning;
 //    // object.set_status(burning);

 //    // std::cout << object.get_status_effect<effects::Burning>() << std::endl;
 //    std::optional<effects::Burning>& obj_burning = object.get_status_effect<effects::Burning>();
 //    std::cout << obj_burning->duration() << std::endl;
 //    std::cout << object.hp() << std::endl;
 //    object.trigger_status_effects();
 //    std::cout << obj_burning->duration() << std::endl;
 //    if(obj_burning.has_value()) {
 //        std::cout << "Didn't remove effect like I should have :(" << std::endl;
 //    }

 //    std::cout << object.hp() << std::endl;
    abilities::Fireball fireball;
    abilities::Rain rain;

    map::Map game_map(sf::Vector2i{8,8});
    std::cout << game_map.to_str() << std::endl;

    std::cout << "Sending fireball with size 3 to position 2,3" << std::endl;
    fireball.apply_ability_effect(game_map, sf::Vector2i{0,0}, sf::Vector2i{2, 3});
    std::cout << game_map.to_str() << std::endl;

    std::cout << "Sending rain with size 2 to position 5,4" << std::endl;
    rain.apply_ability_effect(game_map, sf::Vector2i{0,0}, sf::Vector2i{5,4});
    std::cout << game_map.to_str() << std::endl;
}
