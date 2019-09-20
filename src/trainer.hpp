# pragma once

# include <SFML/System.hpp>
# include <SFML/Graphics.hpp>
# include <vector>
# include <memory>

class Trainer{
    public:
    //sf::Vector2f position;
    sf::Sprite sprite;
    sf::IntRect mask;

    Trainer()
    :mask(0, 0, 14, 22), texture()
    {
        texture.loadFromFile("../img/player.png");
        sprite.setTexture(texture);
        sprite.setTextureRect(mask);
        sprite.setOrigin(7.f, 11.f);
        sprite.scale(5.0, 5.0);
        sprite.setPosition(450.f, 1300.f);
    }
    
    void moveLeft(int top){
        mask.left = 30;
        mask.top = top;
        sprite.setScale(5.0, 5.0);
        sprite.setTextureRect(mask);
        sprite.move(-7.f, 0.f);
    }

    void moveRight(int top){
        mask.left = 30;
        mask.top = top;
        sprite.setTextureRect(mask);
        sprite.setScale(-5.0, 5.0);
        sprite.move(7.f, 0.f);
    }

    void moveUp(int top){
        mask.left = 14;
        mask.top = top;
        sprite.setTextureRect(mask);
        sprite.move(0.f, -7.f);
    }

    void moveDown(int top){
        mask.left = 0;
        mask.top = top;
        sprite.setTextureRect(mask);
        sprite.move(0.f, 7.f);
    }


    private:
    sf::Texture texture;
};