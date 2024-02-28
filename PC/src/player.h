
#ifndef PLAYER_H
#define PLAYER_H


#include "cell.h"




//direction
#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

class Player : public Cell
{
    public:
        Player();
        ~Player();
        int getOrientation();
        void setOrientation(int orientation);
        void setImageCell(Player *cell);
        void move(int direction);
        void cpyCell(Cell* cell);
    private:
        Cell* cell_north;
        Cell* cell_south;
        Cell* cell_east;
        Cell* cell_west;
        int orientation; /** @brief  north=0, south=1, east=2, west=3 */
        int *type;
        int *locked;
        int *enterFrom;
        std::string ***imageCell;
        
};
#endif