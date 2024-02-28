
#ifndef CELL_H
#include "cell.h"
#endif

#define PLAYER_H
class Player : public Cell
{
    public:
        Player();
        ~Player();
        int getOrientation();
        void setImageCell(Cell *cell) override;
        void operator=(Cell* cell);
    private:
        int orientation;
        int type;
        Cell* cell_north;
        Cell* cell_south;
        Cell* cell_east;
        Cell* cell_west;
        int *enterFrom; /** @brief Tu peux entrer quand tu proviens de ____ NONE=-1, north=0, south=1, east=2, west=3 */
        int locked; /** @brief 0 = UNLOCKED, 1 = LOCKED */
        int keyToUnlock;
        //Minigame minigame[];
};