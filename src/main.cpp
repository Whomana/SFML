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
        /*
        */
        //Update Game
        game.update();
        //game.initPlayer();
        //Render Game
        game.render();
    }
}
