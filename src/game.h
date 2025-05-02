#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>

#define XVEL 10.f
#define YVEL 10.f
#define JVEL 20.f

#define ENEMYSPEEDUP 3

#define WINDOWW 0
#define WINDOWH 1
/*
 * Class that acts as Game Engine.
 * Wrapper Class.
 */
class Game {
private:
  //Variables
  //Window
  sf::RenderWindow* window_;
  sf::VideoMode videoMode_;
  int windowSize[2];
  //Event
  std::optional<sf::Event> event_;
  //Game Logic
  sf::Clock clock;
  sf::Time moveIntervalEnemy;
  int8_t enemyMoveCounter;
  int8_t enemySteps;
  //Game Objects
  //Player
  sf::RectangleShape player;
  sf::Vector2f playerSize;
  sf::Vector2f playerOrigin;
  sf::Vector2f playerPos;
  bool onKeyPressed;

  t sf::RectangleShape bullet;
  sf::Vector2f bulletPos;
  sf::Vector2f bulletSize;
  sf::Vector2f bulletOrigin;
  sf::Vector2f bulletSpeed;
  std::vector<sf::RectangleShape> bullets;
  //Enemies
  std::vector<sf::RectangleShape> enemies;
  sf::RectangleShape enemy;
  sf::Vector2f enemyPos;
  sf::Vector2f enemySize;
  sf::Vector2f enemyOrigin;
  uint8_t numberEnemies;
  int8_t dir; //move direction
  int8_t dirCheck;
  int8_t stepsToSpeedup;
  const int8_t stepsToSpeedupOld;
  float enemySpeedUp;

  //Obstacles
  sf::RectangleShape obs;
  std::vector<sf::RectangleShape> obsPosition;
  sf::Vector2f obsSize;
  sf::Vector2f obsOrigin;
  sf::Vector2f obsInitPos;
  uint8_t obsPartNum;
  uint8_t obsCount;
  sf::Vector2f obsSpacing;


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
  void initBullet();
  void shoot();
  void bulletRender();
  void moveBullet();

  void spawnEnemy();
  void initEnemy(sf::Vector2f enemyPos);
  void moveEnemies();

  auto initObstacles(sf::Vector2f obsPos) -> void;
  void spawnObstacle();
  void renderObstacles();

  void collisionDetect();

  void pollEvents();
  void update();
  void updateEnemies();
  void renderPlayer();
  void renderEnemies();
  void render();
};

#endif //GAME_H