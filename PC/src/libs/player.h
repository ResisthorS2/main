
#ifndef PLAYER_H
#define PLAYER_H


#include "globalVar.h"

class Player
{
    public:
        Player();
        ~Player();
        void addObjects(int object);
        /**
         * @brief Méthode pour obtenir l'orientation de la cellule active
         * @return L'orientation de la cellule active : int{NONE=-1, north=0, south=1, east=2, west=3}
         */
        int getOrientation();

        /**
         * @brief Méthode pour définir l'orientation de la cellule active
         * @param orientation L'orientation à définir : int{NONE=-1, north=0, south=1, east=2, west=3}
         */
        void setOrientation(int orientation);

        int *getObjects();
        int orientation; // Orientation de la cellule active int{NONE=-1, north=0, south=1, east=2, west=3}
        int *objects;
    private:
        
        
};
#endif