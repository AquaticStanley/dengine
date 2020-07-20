#include <iostream>
#include "surfaces/fire.h"
#include "surfaces/normal.h"
#include "surfaces/poison.h"
#include "GameObject.h"
#include "status_effects/status_effects.h"
#include "map/tile.h"
#include "abilities/abstract_ability.h"
#include "abilities/fireball.h"
#include "abilities/rain.h"
#include "abilities/poison_bomb.h"

int main() {
    data::GameObjectData data(200, 3, "Troop A");
    GameObject object(data);

    abilities::Fireball fireball(20);
    abilities::Rain rain;
    abilities::PoisonBomb poison_bomb(10);

    map::Map game_map(sf::Vector2i{8,8});
    game_map.get_tile(sf::Vector2i{0,0}).set_contained_object(object);
    game_map.move_object_from_to(sf::Vector2i{0,0}, sf::Vector2i{2,2});
    std::cout << game_map.to_str() << std::endl;
    std::cout << "GameObject hp - " << object.hp() << std::endl;

    std::cout << "Sending fireball with size 3 and potency 20 to position 2,3" << std::endl;
    fireball.apply_ability_effect(game_map, sf::Vector2i{0,0}, sf::Vector2i{2, 3});
    std::cout << game_map.to_str() << std::endl;
    std::cout << "GameObject hp - " << object.hp() << std::endl;
    object.output_status_effects();

    std::cout << "Sending rain with size 2 to position 5,4" << std::endl;
    rain.apply_ability_effect(game_map, sf::Vector2i{0,0}, sf::Vector2i{5,4});
    std::cout << game_map.to_str() << std::endl;
    std::cout << "GameObject hp - " << object.hp() << std::endl;
    object.output_status_effects();

    std::cout << "Sending poison with size 2 and potency 10 to position 2,2" << std::endl;
    poison_bomb.apply_ability_effect(game_map, sf::Vector2i{0,0}, sf::Vector2i{2,2});
    std::cout << game_map.to_str() << std::endl;
    std::cout << "GameObject hp - " << object.hp() << std::endl;
    object.output_status_effects();
}
