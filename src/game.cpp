//
// Created by Alp on 15.04.2025.
//

#include "Game.h"
#include "SFML/Audio/Listener.hpp"
//Private functions
void Game::initVar() {
//Window
  this->window_ = nullptr;
  this->windowSize[WINDOWW] = 800;
  this->windowSize[WINDOWH] = 1080;
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
  this->numberEnemies = 24;
  this->enemyPos.x = 100.f;
  this->enemyPos.y = 200.f;

}

void Game::initWindow() {
  this->videoMode_.size.x = windowSize[WINDOWW];
  this->videoMode_.size.y = windowSize[WINDOWH];
  this->window_ = new sf::RenderWindow(videoMode_, "Funktioniert", sf::Style::Close | sf::Style::Titlebar);
  this->window_->setFramerateLimit(60);
}

void Game::initPlayer() {
  this->player.setSize(playerSize);
  this->player.setOrigin(playerOrigin);
  this->player.setFillColor(sf::Color::White);
  //this->player.setOutlineColor(sf::Color::White);
  this->player.setOutlineThickness(10.0f);
  this->player.setPosition(sf::Vector2f(playerPos));
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

void Game::initEnemy(const sf::Vector2f enemyPos) {
  this->enemy.setSize(enemySize);
  this->enemy.setFillColor(sf::Color::Red);
  this->enemy.setOutlineColor(sf::Color::White);
  this->enemy.setOutlineThickness(1.f);
  this->enemy.setPosition(enemyPos);
}

//Constructor destructor
Game::Game() {
  this->initVar();
  this->initWindow();
  this->initPlayer();
  this->initEnemy(enemyPos);
  this->updateEnemies();
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


void Game::update() {
  this->pollEvents();
  this->playerInput();
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

  //Draw Game
  this->window_->display();
}