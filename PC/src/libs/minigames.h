
#ifndef MINIGAMES_H
#define MINIGAMES_H
#include <iostream>
#include <cmath>
#include <ctime>

class MiniGame
{
    public:
        int play_resistanceGame(int key[6], int cell_type);
        int play_oscilloscopeGame(int key[6], int cell_type, Engine* engine);
        int play_solderGame(int key[6], int cell_type, Engine* engine);
        int departLocalASerge();
        int finLocalASerge(int key[6], int cell_type);
        //ajouter votre fonction ici 
};



#endif