#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <memory>
#include "ball.hpp"
#include "pokemon.hpp"
#include "trainer.hpp"
#include "scoreBoard.hpp"
#include "gameOver.hpp"
#include <SFML/Audio.hpp>

int main() {
  srand(time(NULL));

//Audio
sf::Music music;
music.openFromFile("../audio/theme.wav");
music.setVolume(75);
music.play();

  // create the window
  sf::RenderWindow window(sf::VideoMode(1152, 1440), "Let's Go! Pokemon Trainer");
  window.setFramerateLimit(60);
  // Set background
  sf::Texture bgTexture;
  bgTexture.loadFromFile("../img/bg2.png", sf::IntRect(0, 0, 384, 480));
  sf::Sprite bg(bgTexture);
  bg.scale(3, 3);

  //ScoreBoard
  int score = 0;
  ScoreBoard scoreBoard(score);

  // balls
  sf::Clock clock;

  std::vector<Ball> balls;

  // Game Over:
  int gameOver = 0;
  GameOver endScreen{};
  EndText endtext{score};

  // pokemon

  std::vector<Pokemon> pokedex;
  int spawnCounter = 20;

  // Trainer
  Trainer trainer;
  int frameCounter;

  // Vectors
  sf::Vector2f trainerCenter;
  sf::Vector2f mousePosWindow;
  sf::Vector2f aimDir;
  sf::Vector2f aimDirNorm;

  while (window.isOpen()) {
    // check all the window's events that were triggered since the last
    // iteration of the loop
    sf::Event event;
    gameOver++;
    while (window.pollEvent(event)) {
      // "close requested" event: we close the window
      if (event.type == sf::Event::Closed) window.close();
    }

    trainerCenter = sf::Vector2f(trainer.sprite.getPosition());
    mousePosWindow = sf::Vector2f(sf::Mouse::getPosition(window));
    aimDir = mousePosWindow - trainerCenter;
    aimDirNorm = aimDir / (float)sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2));

    float PI = 3.14159265f;
		float deg = atan2(aimDirNorm.y, aimDirNorm.x) * 180 / PI;
		//trainer.sprite.setRotation(deg + 90);

    // update step counter
    if(trainer.sprite.getPosition().x > 150 && sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
      if(frameCounter < 10){
        trainer.moveLeft(0);
        frameCounter++;
      } else if (frameCounter >= 10 && frameCounter < 20) {
        trainer.moveLeft(22);
        frameCounter++;
      } else if (frameCounter >= 20 && frameCounter < 30) {
        trainer.moveLeft(0);
        frameCounter++;
      } else if (frameCounter >= 30 && frameCounter < 40) {
        trainer.moveLeft(43);
        frameCounter++;
      } else if (frameCounter >= 40){
        frameCounter = 0;
        trainer.moveLeft(0);
      }
    }

	    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && trainer.sprite.getPosition().x < window.getSize().x - 150){
      if(frameCounter < 10){
        trainer.moveRight(0);
        frameCounter++;
      } else if (frameCounter >= 10 && frameCounter < 20) {
        trainer.moveRight(22);
        frameCounter++;
      } else if (frameCounter >= 20 && frameCounter < 30) {
        trainer.moveRight(0);
        frameCounter++;
      } else if (frameCounter >= 30 && frameCounter < 40) {
        trainer.moveRight(43);
        frameCounter++;
      } else if (frameCounter >= 40){
        frameCounter = 0;
        trainer.moveRight(0);
      }
      }
			
		  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && trainer.sprite.getPosition().y > 100){
        if(frameCounter < 10){
        trainer.moveUp(0);
        frameCounter++;
      } else if (frameCounter >= 10 && frameCounter < 20) {
        trainer.moveUp(22);
        frameCounter++;
      } else if (frameCounter >= 20 && frameCounter < 30) {
        trainer.moveUp(0);
        frameCounter++;
      } else if (frameCounter >= 30 && frameCounter < 40) {
        trainer.moveUp(43);
        frameCounter++;
      } else if (frameCounter >= 40){
        frameCounter = 0;
        trainer.moveUp(0);
      }
      }
			
		  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && trainer.sprite.getPosition().y < window.getSize().y - 100){
        if(frameCounter < 10){
        trainer.moveDown(0);
        frameCounter++;
      } else if (frameCounter >= 10 && frameCounter < 20) {
        trainer.moveDown(22);
        frameCounter++;
      } else if (frameCounter >= 20 && frameCounter < 30) {
        trainer.moveDown(0);
        frameCounter++;
      } else if (frameCounter >= 30 && frameCounter < 40) {
        trainer.moveDown(43);
        frameCounter++;
      } else if (frameCounter >= 40){
        frameCounter = 0;
        trainer.moveDown(0);
      }
      }
			
  
    
    //pokedex
    if(spawnCounter < 50){
      spawnCounter++;
    }

    if(spawnCounter >= 50 && pokedex.size() < 10){
      pokedex.push_back(Pokemon(PokemonList[rand()%PokemonList.size()]));

      pokedex[pokedex.size()-1].sprite.setPosition(sf::Vector2f((rand()%window.getSize().x), (rand()%window.getSize().y)));
      
      spawnCounter = 0;
    }

    // shoot
    if (clock.getElapsedTime().asSeconds() >= 1.f  && sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
      balls.push_back(Ball());
			balls[balls.size() - 1].ball.setPosition(trainerCenter);
			balls[balls.size() - 1].currVelocity = aimDirNorm * balls[balls.size() - 1].maxSpeed;
      
			
      clock.restart();
		}


		for (int i = 0; i < balls.size(); i++){
			balls[i].ball.move(balls[i].currVelocity);

			//Out of bounds
			if (balls[i].ball.getPosition().x < 0 || balls[i].ball.getPosition().x > window.getSize().x
				|| balls[i].ball.getPosition().y < 0 || balls[i].ball.getPosition().y > window.getSize().y){
				balls.erase(balls.begin() + i);
			} 
      else {
        //pokemon collision
        for (int k = 0; k < pokedex.size(); k++){
          if(balls[i].ball.getGlobalBounds().intersects(pokedex[k].sprite.getGlobalBounds())){
            balls.erase(balls.begin() + i);
            pokedex.erase(pokedex.begin() + k);
            score += 10;
            scoreBoard.board.setString(scoreBoard.text + std::to_string(score));
          } 
        }
      }
    }
    for (int k = 0; k < pokedex.size(); k++){
      if(trainer.sprite.getGlobalBounds().intersects(pokedex[k].sprite.getGlobalBounds())) {
        pokedex.erase(pokedex.begin() + k);
        if(score > 0) score -= 10;
        scoreBoard.board.setString(scoreBoard.text + std::to_string(score));
      }
		}
    
  
    // clear the window with black color
    window.clear(sf::Color::Black);
    window.draw(bg);
    window.draw(scoreBoard.board);
    for (size_t i = 0; i < pokedex.size(); i++){
      window.draw(pokedex[i].sprite);
    }


    window.draw(trainer.sprite);

		for (int i = 0; i < balls.size(); i++){
			window.draw(balls[i].ball);

		}

    if(gameOver >= 1200){
      endtext.box.setString(endtext.text + std::to_string(score));
      window.draw(endScreen.sprite);
      window.draw(endtext.box);
    } 

    // end the current frame
    window.display();
  }

  return 0;
}