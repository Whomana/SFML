#include "Game.h"
#include "../cmake-build-debug/_deps/sfml-src/extlibs/headers/glad/include/glad/gl.h"


int main() {
/*
    sf::RectangleShape player(sf::Vector2f(100.0f,100.0f));
    player.setFillColor(sf::Color::Red);
    const auto windowSize = window.getSize();
    player.setPosition(sf::Vector2f(static_cast<float>(windowSize.x) / 2.0f, static_cast<float>(windowSize.y)/2.0f));
    player.setOrigin(sf::Vector2f(50.0f, 50.0f));
    window.setFramerateLimit(60);
*/
    Game game;

    while (game.getWindowIsOpen()) {

        //Movement
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
            player.move(sf::Vector2f(-10.0f,0.0f));
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
            player.move(sf::Vector2f(0.0f,-10.0f));
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
            player.move(sf::Vector2f(0.0f,10.0f));
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){
            player.move(sf::Vector2f(10.0f,0.0f));
        }
        */

        game.update();
        game.render();
    }
}
