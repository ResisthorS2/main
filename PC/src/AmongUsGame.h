#ifndef AMONG_US_GAME_H
#define AMONG_US_GAME_H

#include "../engine/Game.h"
#include "Player.h"

class AmongUsGame : public Game
{
private:
    Player player;
public:
    AmongUsGame();
    ~AmongUsGame();
    void initialize();
    void update();
    //void draw();
    void conclude();
};


#endif