#pragma once

#include<SFML/Graphics.hpp>
#include<string>

class GameOver{
    public:
    sf::Sprite sprite;

    GameOver()
    :texture()
    {
        texture.loadFromFile("../img/end.png", sf::IntRect(0, 214, 246, 154));
        sprite.setTexture(texture);
        sprite.setPosition(600.f, 720.f);
        sprite.setOrigin(123.f, 77.f);
        sprite.setScale(4.5f, 4.5f);
    }


    private:
    std::string text;
    sf::Texture texture;
};


class EndText{
    public:
    std::string text;
    sf::Text box;
    sf::Font font;

    EndText(int s)
    :box()
    {
        font.loadFromFile("../resource/arial.ttf");
        text = "    Game Over!\nYour Score is: ";
        box.setString(text + std::to_string(s));
        box.setCharacterSize(60);
        box.setPosition(500.f, 720.f);
        box.setOrigin(123.f, 77.f);
        box.setFillColor(sf::Color::Blue);
        box.setStyle(sf::Text::Bold);
        box.setFont(font);
    }
};