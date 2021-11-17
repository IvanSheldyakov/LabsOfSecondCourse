#include <iostream>

#include "HumanGuessingPlayer.h"
#include "ConsoleController.h"
#include "ConsoleViewer.h"
#include "Game.h"
int main() {


    Game game(new ConsoleController, new ConsoleViewer);
    //std::cout << bot.tryToGuess(a) << std::endl;
    game.gameLoop();
    return 0;
}
