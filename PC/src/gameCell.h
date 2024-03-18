#ifndef GAMECELL_H
#define GAMECELL_H
#include "cell.h"


class GameCell : public Cell
{
    public:
        GameCell();
        GameCell(int type);
        ~GameCell();
        Cell *enterCell(int *orientation, int key[maxRoom], int direction = RIGHT) override;
        void l3022();
        void l3019();
        void l3018();
        void l3041();
        void l3016();
        void l3024();
        void setImageCell(Cell *cell) override;
};

#endif