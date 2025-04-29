#include "Game.h"
#include "../cmake-build-debug/_deps/sfml-src/extlibs/headers/glad/include/glad/gl.h"


int main() {
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
