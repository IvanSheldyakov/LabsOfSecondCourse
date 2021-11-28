#include <iostream>

#include "HumanGuessingPlayer.h"
#include "ConsoleController.h"
#include "ConsoleViewer.h"
#include "Game.h"
int main() {


    Game game(new ConsoleViewer, new ConsoleController);
    game.gameloop();
    return 0;
}
