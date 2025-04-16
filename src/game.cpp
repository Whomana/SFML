//
// Created by Alp on 15.04.2025.
//

#include "Game.h"
//Private functions
void Game::initVar() {
  this->window_ = nullptr;
}

void Game::initWindow() {
  this->videoMode_.size.x = 1920;
  this->videoMode_.size.y = 1080;
  this->window_ = new sf::RenderWindow(videoMode_, "Funktioniert", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
  this->window_->setFramerateLimit(60);
}
//Constructor destructor
Game::Game() {
  this->initVar();
  this->initWindow();
}

//Accessors
bool Game::getWindowIsOpen() const {
  return this->window_->isOpen();
}

void Game::pollEvents() {

  while (event_ = this->window_->pollEvent()) {

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
}
void Game::render() {
  //Renders game Object
  this->window_->clear();

  this->window_->display();
}

