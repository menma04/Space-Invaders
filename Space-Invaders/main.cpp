#include"header/GameService.h"
int main()
{
    GameService gameservice;
    gameservice.ignite();

    while (gameservice.isRunning()) {
        gameservice.update();
        gameservice.render();
    }
    return 0;
}