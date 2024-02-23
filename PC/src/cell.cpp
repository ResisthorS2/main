#ifndef CELL_H
#include "cell.h"
#endif


#include <iostream>

#define RESET   "\x1b[0m"
#define BLACK   "\x1b[30m"      /* Black */
#define RED     "\x1b[31m"      /* Red */
#define GREEN   "\x1b[32m"      /* Green */
#define YELLOW  "\x1b[33m"      /* Yellow */
#define BLUE    "\x1b[34m"      /* Blue */
#define MAGENTA "\x1b[35m"      /* Magenta */
#define CYAN    "\x1b[36m"      /* Cyan */
#define WHITE   "\x1b[37m"      /* White */

using namespace std;


Cell::Cell()
{
    this->type = TypeCell::vide;
    this->locked = UNLOCKED;
    this->setImageCell(type, locked);
}

Cell::Cell(TypeCell type, int locked)
{
    this->type = TypeCell::couloir;
    this->locked = locked;
    this->setImageCell(type, locked);
}


void Cell::setImageCell(TypeCell type, int locked)
{
    string color;
    
    if(type == TypeCell::vide)
    {
        color = BLACK;
    }

    if(type == TypeCell::couloir)
    {
        color == WHITE;
    }

    if(type == TypeCell::classe)
    {
        if(locked == LOCKED)
        {
            color == RED;
        }

        if(locked == UNLOCKED)
        {
            color == GREEN;
        }
    }

    for(int i=0; i<3; i++)
    {
        for(int y=0; y<3; y++)
            {
                imageCell[i][y] = color+"X";
            }
    }
}

int Cell::isLocked()
{
    return this->locked;
}

bool Cell::setLocked(int locked)
{
    this->locked = locked;
    this->setImageCell(this->type, this->locked);
    return true;
}

TypeCell Cell::getType()
{
    return this->type;
}