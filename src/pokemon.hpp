# pragma once

# include <SFML/Graphics.hpp>
# include <SFML/System.hpp>
# include <string>
# include <vector>


struct SinglePokemon{
    std::string filePath;
    sf::IntRect rect;
    sf::Vector2f scale;
    sf::Vector2f origin;
};

const std::vector<SinglePokemon> PokemonList = {
    {
        "../img/pikachu.png",
        sf::IntRect(0, 0, 38, 41),
        sf::Vector2f(2.5f, 2.5f),
        sf::Vector2f(19.f, 20.f)
    },
    {
        "../img/Mew.png",
        sf::IntRect(0, 0, 74, 66),
        sf::Vector2f(2.1f, 2.1f),
        sf::Vector2f(37.f, 33.f)
    },
    {
        "../img/eevee.png",
        sf::IntRect(12, 0, 40, 53),
        sf::Vector2f(2.1f, 2.1f),
        sf::Vector2f(20.f, 26.f)
    },
    {
        "../img/Charmander.png",
        sf::IntRect(0, 0, 38, 38),
        sf::Vector2f(2.5f, 2.5f),
        sf::Vector2f(16.f, 16.f)
    },
    {
        "../img/Bulbasaur.png",
        sf::IntRect(0, 0, 36, 33),
        sf::Vector2f(2.5f, 2.5f),
        sf::Vector2f(18.f, 27.f)
    },
    {
        "../img/Squirtle.png",
        sf::IntRect(0, 0, 56, 60),
        sf::Vector2f(2.2f, 2.2f),
        sf::Vector2f(28.f, 30.f)
    },
    {
        "../img/Jigglypuff.png",
        sf::IntRect(14, 10, 40, 40),
        sf::Vector2f(2.f, 2.f),
        sf::Vector2f(20.f, 20.f)
    }
};

class Pokemon{
    public:
    sf::Sprite sprite;

    Pokemon()
    :texture(new sf::Texture())
    {
        texture->loadFromFile("../img/pikachu.png", sf::IntRect(0, 0, 38, 41));
        sprite.setTexture(*texture);
        sprite.setOrigin(19.f, 20.f);
        sprite.scale(2.5, 2.5);
        sprite.setPosition(460.f, 460.f);
    }

    Pokemon(SinglePokemon pokemon) 
    :texture(new sf::Texture())
    {
        texture->loadFromFile(pokemon.filePath, pokemon.rect);
        sprite.setTexture(*texture);
        sprite.setOrigin(pokemon.origin.x, pokemon.origin.y);
        sprite.scale(pokemon.scale.x, pokemon.scale.y);
    }

    private:
    std::unique_ptr<sf::Texture> texture;
};