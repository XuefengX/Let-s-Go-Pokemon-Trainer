#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class Ball{

    public:
    sf::Vector2f currVelocity;
    sf::Sprite ball;
    float maxSpeed;

    Ball();
    
    private:
    std::unique_ptr<sf::Texture> texture;
};