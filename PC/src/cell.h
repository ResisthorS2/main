#include <iostream>


#define CELL_H



#define LOCKED 1
#define UNLOCKED 0


#define VIDE 0
#define COULOIR 1
#define CLASSE_LOCKED 2
#define CLASSE_UNLOCKED 3



struct Coordinate
{
    int x;
    int y;
};
typedef Coordinate Coordinate;

class Cell
{
    public:
        Cell();
        Cell(int type, int locked, int c_x, int c_y);
        ~Cell();
        /** @brief retourne le type de la Cell @return int{vide = 0, couloir = 1, classe = 2,}*/
        int getType();
        /** @brief retourne un int selon si la Cell est vérouillée @return 0 = UNLOCKED, 1 = LOCKED */
        int isLocked();
        /** @brief change l'image ASCII de la case @param type type de la Cell en int @param locked int 0 = UNLOCKED, 1 = LOCKED*/
        void setImageCell(int type, int locked, int orientation = NULL);
        bool setLocked(int locked);
        std::string printCellTerminal(int line);
        void printCell();
        
        std::string imageCell[3][3];
        std::string getColor();
        

    private:
        int type;
        int locked;
        Coordinate coordonne;
        std::string typeColor;
        //Piece piece;
        //Minigame minigame[];
};
