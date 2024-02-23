#include <iostream>

#define CELL_H

#ifndef MAP_H
#include "map.h"
#endif

#define LOCKED 1
#define UNLOCKED 0


enum class TypeCell
{
    vide = 0,
    couloir = 1,
    classe = 2,
    
};




class Cell
{
    public:
        Cell();
        Cell(TypeCell type, int locked);
        //~Cell();
        /** @brief retourne le type de la Cell @return typeCell{vide = 0, couloir = 1, classe = 2,}*/
        TypeCell getType();
        /** @brief retourne un int selon si la Cell est vérouillée @return 0 = UNLOCKED, 1 = LOCKED */
        int isLocked();
        /** @brief change l'image ASCII de la case @param type type de la Cell en typeCell @param locked int 0 = UNLOCKED, 1 = LOCKED*/
        void setImageCell(TypeCell type, int locked);
        bool setLocked(int locked);
        

    private:
        TypeCell type;
        int locked;
        std::string imageCell[3][3];
        //Piece piece;
        //Minigame minigame[];
};