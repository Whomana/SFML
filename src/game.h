#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>

#define XVEL 10.f
#define YVEL 10.f
#define JVEL 20.f

#define WINDOWW 0
#define WINDOWH 1
/*
 * Class that acts as Game Engine.
 * Wrapper Class.
 */
class Game {
private:

  //Window
  sf::RenderWindow* window_;
  sf::VideoMode videoMode_;
  int windowSize[2];
  //Event
  std::optional<sf::Event> event_;
  //Game Logic

  //Game Objects
  //Player
  sf::RectangleShape player;
  sf::Vector2f playerSize;
  sf::Vector2f playerOrigin;
  sf::Vector2f playerPos;

  //Enemies
  std::vector<sf::RectangleShape> enemies;
  sf::RectangleShape enemy;
  sf::Vector2f enemyPos;
  sf::Vector2f enemySize;
  uint8_t numberEnemies;

  //Variables


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
  void playerInput();
  void initPlayer();

  void spawnEnemy();
  void initEnemy(sf::Vector2f enemyPos);

  void pollEvents();
  void update();
  void updateEnemies();
  void renderPlayer();
  void renderEnemies();
  void render();
};

#endif //GAME_H