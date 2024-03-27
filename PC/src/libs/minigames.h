
#ifndef MINIGAMES_H
#define MINIGAMES_H
#include <iostream>
#include <cmath>
#include <ctime>
#include "../libs/engine.h"

class MiniGame
{
    public:
        int play_resistanceGame();
        int play_proceduralGame(int key[6], int cell__type, Engine* engine);
        int play_laboGame(int key[6], int cell__type, Engine* engine);
        //ajouter votre fonction ici
};



#endif