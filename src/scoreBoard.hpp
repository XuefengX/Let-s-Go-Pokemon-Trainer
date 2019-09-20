#pragma once

#include<SFML/Graphics.hpp>
#include<string>

class ScoreBoard{
    public:
    std::string text;
    std::string score;
    sf::Text board;
    sf::Font font;

    ScoreBoard(int s)
    :board()
    {
        font.loadFromFile("../resource/arial.ttf");
        text = "Catch a pokemon\nscore + 10\nRun into a pokemon\nscore - 10\n\nScore: ";
        score = std::to_string(s);
        board.setString(text+score);
        board.setPosition(870.f, 120.f);
        board.setCharacterSize(30);
        board.setFillColor(sf::Color::White);
        board.setStyle(sf::Text::Bold);
        board.setFont(font);
    }

    private:
};