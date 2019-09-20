# include "ball.hpp"

Ball::Ball()
: currVelocity(0.f, 0.f), maxSpeed(20.f), texture(new sf::Texture())
{
    texture->loadFromFile("../img/ball.png");
    ball.setTexture(*texture);
    ball.setTextureRect( sf::IntRect(0, 0, 840, 840));
    ball.scale(.15, .15);
};