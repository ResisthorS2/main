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


const int NONE=-1;
const int north=0;
const int south=1;
const int east=2;
const int west=3;
const int maxRoom=50;






class Cell
{
    public:
        Cell();
        Cell(int type);
        virtual ~Cell();
        /** @brief retourne le type de la Cell @return int{vide = 0, couloir = 1, classe = 2,}*/
        int *getType();
        /** @brief retourne un int selon si la Cell est vérouillée @return 0 = UNLOCKED, 1 = LOCKED */
        void setType(int type);
        virtual void setImageCell(Cell *cell);
        std::string printCellTerminal(int line);
        void printCell();
        std::string imageCell[3][3];
        void setLocked(int locked);
        int *getLocked();
        void setCellAround(int orientation, Cell* cell);
        Cell *getCellAround(int orientation);
        void cpyEnterFrom(int *enterFrom);
        Cell *enterCell(int orientation, int key[maxRoom]);
        int *getEnterFrom();
        void setKeyToUnlock(int keyToUnlock);
        int getKeyToUnlock();

        

    private:
        int type;
        Cell* cell_north;
        Cell* cell_south;
        Cell* cell_east;
        Cell* cell_west;
        int locked; /** @brief 0 = UNLOCKED, 1 = LOCKED */
        int keyToUnlock;
        //Minigame minigame[];
};
#endif
