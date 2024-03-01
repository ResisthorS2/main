#ifndef ACTIVECELL_H
#define ACTIVECELL_H

#include "cell.h"

//direction
#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

/**
 * @class ActiveCell
 * @brief Classe représentant une cellule active, hérite de la classe Cell
 */
class ActiveCell : public Cell
{
    public:
        /**
         * @brief Constructeur par défaut de la classe ActiveCell
         */
        ActiveCell();

        /**
         * @brief Destructeur de la classe ActiveCell
         */
        ~ActiveCell();

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

        /**
         * @brief Méthode pour définir l'image de la cellule active
         * @param cell La cellule active dont l'image doit être définie : ActiveCell*
         */
        void setImageCell(ActiveCell *cell);

        /**
         * @brief Méthode pour déplacer la cellule active
         * @param direction La direction du déplacement : int{LEFT=0, RIGHT=1, UP=2, DOWN=3}
         */
        void move(int direction);

        /**
         * @brief Méthode pour copier une cellule dans la cellule active
         * @param cell La cellule à copier : Cell*
         */
        void cpyCell(Cell* cell);

        /**
         * @brief Méthode pour obtenir une cellule voisine de la cellule active
         * @param orientation L'orientation de la cellule voisine à obtenir : int{NONE=-1, north=0, south=1, east=2, west=3}
         * @return pointeur Cell* si la cellule voisine existe, NULL sinon
         */
        Cell *getCellAround(int orientation);

        /**
         * @brief Méthode pour obtenir la clé de la cellule active
         * @return La clé de la cellule active : int
         */
        int getKey();

    private:
        Cell* cell_north; // Cellule voisine au nord
        Cell* cell_south; // Cellule voisine au sud
        Cell* cell_east; // Cellule voisine à l'est
        Cell* cell_west; // Cellule voisine à l'ouest
        int orientation; // Orientation de la cellule active int{NONE=-1, north=0, south=1, east=2, west=3}
        int *type; // Type de la cellule active : int{VIDE=0, COULOIR=1, DOORNORTH=2, DOORSOUTH=3, DOOREAST=4, DOORWEST=5}
        int *locked; // État de verrouillage de la cellule active : int{UNLOCKED=0, LOCKED=1}
        std::string ***imageCell; // Image de la cellule active : int[3][3]
        int keys[1] = {1}; // Clé de la cellule active
};
#endif