
#ifndef MINIGAMES_H
#define MINIGAMES_H
#include <iostream>
#include <cmath>
#include <ctime>
#include "player.h"
class MiniGame
{
    public:
        int play_resistanceGame(int key[6], int cell_type);
        int play_oscilloscopeGame(int key[6], int cell_type);
        int play_solderGame(int key[6], int cell_type);
        //ajouter votre fonction ici
};



#endif