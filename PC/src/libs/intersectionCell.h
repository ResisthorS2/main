

#ifndef INTERSECTION_H
#define INTERSECTION_H
#include "cell.h"


/**
 * @class Intersection
 * @brief Classe représentant une intersection, hérite de la classe Cell
 */



class IntersectionCell : public Cell
{
    public:
        /**
         * @brief Constructeur par défaut de la classe Intersection
         */
        IntersectionCell(int type);;

        Cell *enterCell(int *orientation, int key[maxRoom], Engine *engine, int direction = RIGHT) override;
};

#endif
