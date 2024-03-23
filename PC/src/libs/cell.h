#ifndef CELL_H
#define CELL_H



#include <iostream>

#define LOCKED 1
#define UNLOCKED 0

#define VIDE 0  
#define COULOIR 1  
#define DOORNORTH 2  
#define DOORSOUTH 3  
#define DOOREAST 4  
#define DOORWEST 5  
#define INTERSECTION 6

#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3


const int NONE=-1;
const int north=0;
const int east=1;
const int south=2;
const int west=3;
const int maxRoom=50;

/**
 * @class Cell
 * @brief Classe représentant une cellule, peut être une cellule vide, un couloir, une porte, etc.
 */
class Cell
{
    public:
        /**
         * @brief Constructeur par défaut de la classe Cell
         */
        Cell();

        /**
         * @brief Constructeur de la classe Cell avec un type spécifique
         * @param type Le type de la cellule à créer : int{VIDE=0, COULOIR=1, DOORNORTH=2, DOORSOUTH=3, DOOREAST=4, DOORWEST=5}
         */
        Cell(int type);

        /**
         * @brief Destructeur de la classe Cell
         */
        virtual ~Cell();

        /**
         * @brief Méthode pour obtenir le type de la cellule
         * @return Le type de la cellule : int{VIDE=0, COULOIR=1, DOORNORTH=2, DOORSOUTH=3, DOOREAST=4, DOORWEST=5}
         */
        int *getType();

        /**
         * @brief Méthode pour définir le type de la cellule
         * @param type Le type à définir : int{VIDE=0, COULOIR=1, DOORNORTH=2, DOORSOUTH=3, DOOREAST=4, DOORWEST=5}
         */
        void setType(int type);

        /**
         * @brief Méthode pour définir l'image de la cellule
         * @param cell La cellule dont l'image doit être définie : Cell*
         */
        virtual void setImageCell(Cell *cell);

        /**
         * @brief Méthode pour imprimer la cellule
         */
        void printCell();

        /**
         * @brief Méthode pour définir l'état de verrouillage de la cellule
         * @param locked L'état de verrouillage à définir : int{UNLOCKED=0, LOCKED=1}
         */
        void setLocked(int locked);

        /**
         * @brief Méthode pour obtenir l'état de verrouillage de la cellule
         * @return L'état de verrouillage de la cellule : int{UNLOCKED=0, LOCKED=1}
         */
        int *getLocked();

        /**
         * @brief Méthode pour définir une cellule voisine
         * @param orientation L'orientation de la cellule voisine à définir : int{NONE=-1, north=0, south=1, east=2, west=3}
         * @param cell La cellule voisine à définir : Cell*
         */
        void setCellAround(int orientation, Cell* cell);

        /**
         * @brief Méthode pour obtenir une cellule voisine
         * @param orientation L'orientation de la cellule voisine à obtenir : int{NONE=-1, north=0, south=1, east=2, west=3}
         * @return Pointeur vers la cellule voisine dans l'orientation spécifiée ou NULL si aucune cellule n'est présente dans cette orientation
         */
        Cell *getCellAround(int orientation);

        /**
         * @brief Méthode pour copier une cellule
         * @param enterFrom La cellule à copier
         */
        void cpyEnterFrom(int *enterFrom);

        /**
         * @brief Méthode pour entrer dans une cellule
         * @param orientation L'orientation de l'entrée : int{NONE=-1, north=0, south=1, east=2, west=3}
         * @param key La clé pour entrer dans la cellule : int[maxRoom]
         * @return Pointeur vers la cellule entrée
         */
        virtual Cell *enterCell(int *orientation, int key[maxRoom], int direction = RIGHT);

        /**
         * @brief Méthode pour obtenir la cellule d'entrée
         * @return Pointeur vers la cellule d'entrée
         */
        int *getEnterFrom();

        /**
         * @brief Méthode pour définir la clé pour déverrouiller la cellule
         * @param keyToUnlock La clé pour déverrouiller la cellule : int
         */
        void setKeyToUnlock(int keyToUnlock);

        /**
         * @brief Méthode pour obtenir la clé pour déverrouiller la cellule
         * @return La clé pour déverrouiller la cellule
         */
        int getKeyToUnlock();
        std::string imageCell[3][3]; ///< Image de la cellule active : std::string*[3][3]

    protected:
        
        int type; // Type de la cellule : int{VIDE=0, COULOIR=1, DOORNORTH=2, DOORSOUTH=3, DOOREAST=4, DOORWEST=5}
        Cell* cell_north; // Cellule voisine au nord
        Cell* cell_south; // Cellule voisine au sud
        Cell* cell_east; // Cellule voisine à l'est
        Cell* cell_west; // Cellule voisine à l'ouest
        int locked; // État de verrouillage de la cellule : int{UNLOCKED=0, LOCKED=1}
        int keyToUnlock; // Clé pour déverrouiller la cellule : int
};
#endif