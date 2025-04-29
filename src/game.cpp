//
// Created by Alp on 15.04.2025.
//

#include <algorithm>

#include "Game.h"
#include "SFML/Audio/Listener.hpp"
#include <iostream>
//Private functions
void Game::initVar() {
  //Window
  this->window_ = nullptr;
  this->windowSize[WINDOWW] = 800;
  this->windowSize[WINDOWH] = 1080;
  //GameLogic
  this->clock;
  this->moveIntervalEnemy = sf::seconds(2.f);
  //Player
  this->playerSize.x = 100.f;
  this->playerSize.y = 20.f;
  this->playerOrigin.x = playerSize.x / 2;
  this->playerOrigin.y = playerSize.y / 2;
  this->playerPos.x = static_cast<float>(windowSize[WINDOWW]) / 2.f;
  this->playerPos.y = static_cast<float>(windowSize[WINDOWH]) - (static_cast<float>(windowSize[WINDOWH] / 4.f));
  //Enemies
  this->enemySize.x = 40.f;
  this->enemySize.y = 40.f;
  this->enemyOrigin.x = enemySize.x / 2;
  this->enemyOrigin.y = enemySize.y / 2;
  this->numberEnemies = 24;
  this->enemyPos.x = 100.f;
  this->enemyPos.y = 200.f;
  this->dir = 1;
  this->dirCheck = -1;
  this->stepsToSpeedup = 0;
  this->enemySpeedUp = 5;
  //Obstacles
  this->obsSize.x = 100.f;
  this->obsSize.y = 100.f;
  this->obsOrigin.x = obsSize.x / 2;
  this->obsOrigin.y = obsSize.y / 2;
  this->obsCount = 4;
  this->obsInitPos.x = windowSize[WINDOWW] / 8 + 50;
  this->obsInitPos.y = (windowSize[WINDOWH] / 3) * 2;
  this->obsSpacing = (windowSize[WINDOWW] - obsInitPos.x) / obsCount;


}


void Game::initObstacles(const sf::Vector2f obsPos) {
  this->obs.setSize(obsSize);
  this->obs.setOrigin(obsOrigin);
  this->obs.setFillColor(sf::Color::White);
  this->obs.setPosition(obsPos);
}

void Game::spawnObstacle() {
  /*
   *  @return void
   *  obsCount Number Obstacles
   *  ObsPosition stores Obstacles
   *  ObsInitPos initial position of Obstacles
   *  obsSpacing Space between Obstacles
   */
  for (int i = 0; i < obsCount; i++) {
    this->initObstacles(obsInitPos);
    this->obsPosition.push_back(this->obs);
    this->obsInitPos.x += this->obsSpacing;
    std::cout << this->obs.getPosition().x << std::endl;
  }
}

void Game::renderObstacles() {
  for (auto &e: this->obsPosition) {
    this->window_->draw(e);

  }
}


void Game::initWindow() {
  this->videoMode_.size.x = windowSize[WINDOWW];
  this->videoMode_.size.y = windowSize[WINDOWH];
  this->window_ = new sf::RenderWindow(videoMode_, "Funktioniert", sf::Style::Close | sf::Style::Titlebar);
  this->window_->setFramerateLimit(60);
  std::cout << this->window_->getSize().x;
}

void Game::initPlayer() {
  this->player.setSize(playerSize);
  this->player.setOrigin(playerOrigin);
  this->player.setFillColor(sf::Color::White);
  this->player.setOutlineThickness(10.0f);
  this->player.setPosition(sf::Vector2f(playerPos));
}

void Game::initEnemy(const sf::Vector2f enemyPos) {
  this->enemy.setSize(enemySize);
  this->enemy.setOrigin(enemyOrigin);
  this->enemy.setFillColor(sf::Color::Red);
  this->enemy.setOutlineColor(sf::Color::White);
  this->enemy.setOutlineThickness(1.f);
  this->enemy.setPosition(enemyPos);
}

void Game::moveEnemies() {
  /*
   * @return void
   *
   * moves enemies
   * dir direction to move on x-axis
   * moveIntervalEnemy time Interval till next move of enemy
   */
  if (this->stepsToSpeedup == this->stepsToSpeedupOld && this->moveIntervalEnemy > sf::Time::Zero) {
    this->moveIntervalEnemy -= sf::seconds(0.38f);
    this->stepsToSpeedup = 0;
  }
  //Check for time to move
  if (this->clock.getElapsedTime().asMicroseconds() >= this->moveIntervalEnemy.asMicroseconds()) {
    clock.restart();
    //Move down and update direction
    if ((this->enemies[5].getPosition().x + this->enemies[5].getSize().x >= static_cast<float>(window_->getSize().x) || this->enemies[0].getPosition().x - this->enemies[0].getSize().x <= 0.f) && this->dir == this->dirCheck) {
      for (auto &e: enemies) {
        e.setPosition(sf::Vector2f(e.getPosition().x, e.getPosition().y + enemySpeedUp));
      }
      this->stepsToSpeedup++;

      this->dir *= (-1);
    } else {
      //Move sideways
      for (auto &e : enemies) {
        e.setPosition(sf::Vector2f(e.getPosition().x + this->enemySpeedUp * static_cast<float>(this->dir), e.getPosition().y));
      }
      this->stepsToSpeedup++;
      if (this->enemies[5].getPosition().x + this->enemies[5].getSize().x >= static_cast<float>(window_->getSize().x) || this->enemies[0].getPosition().x - this->enemies[0].getSize().x <= 0.f) {
        this->dirCheck = this->dir;
      }
    }
  }
}


void Game::spawnEnemy() {
  /*
   * @return void
   *
   * Spawns enemies and sets their position
   * Aligns enemies as rectangle
   */
  for (int i = 1; i < 4; i++) {
    for (int j = 0; j < 6; j++) {
      this->initEnemy(enemyPos);
      this->enemies.push_back(this->enemy);
      this->enemyPos.x = this->enemyPos.x + ((static_cast<float>(windowSize[WINDOWW]) - 100.f) / 6.f);
    }
    this->enemyPos.x = 100.f;
    this->enemyPos.y = this->enemyPos.y + 125.f;
  }
}

//Accessors
bool Game::getWindowIsOpen() const {
  return this->window_->isOpen();
}

void Game::playerInput() {
    //Movement

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
    this->player.move(sf::Vector2f(-XVEL,0.0f));
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
    this->player.move(sf::Vector2f(XVEL,0.0f));
  }
  if (this->player.getPosition().x >= static_cast<float>(windowSize[WINDOWW]) - player.getSize().x / 2.f) {
    this->player.setPosition(sf::Vector2f(static_cast<float>(windowSize[WINDOWW]) - player.getSize().x / 2.f, player.getPosition().y));
  } else if (this->player.getPosition().x <= player.getSize().x / 2.f) {
    this->player.setPosition(sf::Vector2f(player.getSize().x / 2.f, player.getPosition().y));
  }
}

void Game::pollEvents() {

  while ((event_ = this->window_->pollEvent())) {

    if (this->event_->is<sf::Event::Closed>()) {
      this->window_->close();
    } else if (auto* keyPressed = this->event_->getIf<sf::Event::KeyPressed>()) {
      if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
        this->window_->close();
      }
    }
  }
}


Game::~Game() {
  delete this->window_;
}

//Constructor destructor
Game::Game() : stepsToSpeedupOld(ENEMYSPEEDUP) {
  this->initVar();
  this->initWindow();
  this->initPlayer();
  this->initEnemy(enemyPos);
  this->updateEnemies();
  this->initObstacles(obsInitPos);
  this->spawnObstacle();
}

void Game::update() {
  this->pollEvents();
  this->playerInput();
  this->moveEnemies();
}

void Game::updateEnemies() {
  this->spawnEnemy();
}

void Game::renderPlayer() {
  this->window_->draw(this->player);
}

void Game::renderEnemies() {
  for (auto &e : this->enemies) {
    this->window_->draw(e);
  }
}

void Game::render() {
  /*
      Renders game Object
  */
  this->window_->clear();


  this->renderPlayer();
  this->renderEnemies();
  this->renderObstacles();

  //Draw Game
  this->window_->display();
}