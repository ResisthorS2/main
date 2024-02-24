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
    this->type = VIDE;
    this->locked = UNLOCKED;
    this->setImageCell(type, locked);
}

Cell::Cell(int type, int locked, int c_x, int c_y)
{
    this->type = COULOIR;
    this->locked = locked;
    this->coordonne.x = c_x;
    this->coordonne.y = c_y;
    this->setImageCell(type, locked);
}



void Cell::setImageCell(int type, int locked)
{
    string color;
    
    if(type == VIDE)
    {
        color = BLACK;
    }

    if(type == COULOIR)
    {
        color == WHITE;
    }

    if(type == CLASSE)
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

int Cell::getType()
{
    return this->type;
}

std::string Cell::printCell(int line)
{
    std::string cell_line = imageCell[line][0];;
    for(int i=1; i<3; i++)
    {
        cell_line += imageCell[line][i];
    }

    return cell_line;
}
