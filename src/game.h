#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

#ifndef GAME_H
#define GAME_H
/*
 * Class that acts as Game Engine.
 * Wrapper Class.
 */
class Game {
private:
  //Window
  sf::RenderWindow* window_;
  sf::VideoMode videoMode_;
  std::optional<sf::Event> event_;
  //Private Functions
  void initVar();
  void initWindow();

public:
  //Constructor Destructor
  Game();
  virtual ~Game();
  //Accessors
  bool getWindowIsOpen() const;
  //Functions
  void pollEvents();
  void update();
  void render();
};



#endif //GAME_H
