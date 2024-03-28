
#ifndef MINIGAMES_H
#define MINIGAMES_H
#include <iostream>
#include <cmath>
#include <ctime>
#include "player.h"
#include "engine.h"
class MiniGame
{
    public:
        int play_resistanceGame(int key[6], int cell_type, Engine* engine);
        int play_oscilloscopeGame(int key[6], int cell_type, Engine* engine);
        int play_solderGame(int key[6], int cell_type, Engine* engine);
        int play_laboGame(int key[6], int cell__type, Engine* engine);
        int play_proceduralGame(int key[6], int cell__type, Engine* engine);
        //ajouter votre fonction ici
};



#endif