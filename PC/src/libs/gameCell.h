#ifndef GAMECELL_H
#define GAMECELL_H
#include "cell.h"
#include "player.h"


class GameCell : public Cell
{
    public:
        GameCell();
        GameCell(int type);
        ~GameCell();
        Cell *enterCell(int *orientation, int key[6], int direction = RIGHT) override;
        void l3022(int key[6], int cell_type);
        void l3019(int key[6], int cell_type);
        void l3018(int key[6], int cell_type);
        void l3041(int key[6], int cell_type);
        void l3016(int key[6], int cell_type);
        void l3024(int key[6], int cell_type);
        void setImageCell(Cell *cell, int key[6]) override;
        int *locked;
    private:
        int *key_to_unlock;
};

#endif