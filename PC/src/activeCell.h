
#ifndef ACTIVECELL_H
#define ACTIVECELL_H


#include "cell.h"




//direction
#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

class ActiveCell : public Cell
{
    public:
        ActiveCell();
        ~ActiveCell();
        int getOrientation();
        void setOrientation(int orientation);
        void setImageCell(ActiveCell *cell);
        void move(int direction);
        void cpyCell(Cell* cell);
        Cell *getCellAround(int orientation);
    private:
        Cell* cell_north;
        Cell* cell_south;
        Cell* cell_east;
        Cell* cell_west;
        int orientation; /** @brief  north=0, south=1, east=2, west=3 */
        int *type;
        int *locked;
        std::string ***imageCell;
        
};
#endif