#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Graphics {
public:
    Graphics(sf::RenderWindow* window) : window_(window) {}

    void draw(sf::Vector2f position, sf::Vector2f hitbox, sf::Color color);
    void draw(sf::Vector2f position, sf::Sprite);

    sf::Vector2f translatePosition(sf::Vector2f position);

private:
    sf::RenderWindow* window_;
};
