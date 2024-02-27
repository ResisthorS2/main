#ifndef CELL_H
#include "cell.h"
#endif


#include <iostream>
#include <sstream>

std::string RESET  = "\x1b[0m";
std::string BLACK  = "\x1b[30m";      /* Black */
std::string RED    = "\x1b[31m";      /* Red */
std::string GREEN  = "\x1b[32m";      /* Green */
std::string YELLOW = "\x1b[33m";      /* Yellow */
std::string BLUE   = "\x1b[34m";      /* Blue */
std::string MAGENTA = "\x1b[35m";      /* Magenta */
std::string CYAN   = "\x1b[36m";      /* Cyan */
std::string WHITE  = "\x1b[37m";      /* White */

using namespace std;


Cell::Cell()
{

    this->type = VIDE;
    this->locked = UNLOCKED;
    this->setImageCell(type, locked);
}

Cell::Cell(int type, int locked, int c_x, int c_y)
{
    /*std::cout << "initialisation d'une cellule" << std::endl;
    std::cout << "type : " << type << std::endl;
    std::cout << "locked : " << locked << std::endl;
    std::cout << "c_x : " << c_x << std::endl;
    std::cout << "c_y : " << c_y << std::endl;*/
    this->type = type;
    this->locked = locked;
    this->coordonne.x = c_x;
    this->coordonne.y = c_y;
    this->setImageCell(type, locked);
}



void Cell::setImageCell(int type, int locked)
{
    
    if(type == VIDE)
    {
        this->typeColor = BLACK;
    }

    if(type == COULOIR)
    {
        this->typeColor = WHITE;
    }

    if(type == CLASSE)
    {
        if(locked == LOCKED)
        {
            this->typeColor = RED;
        }

        if(locked == UNLOCKED)
        {
            this->typeColor = GREEN;
        }
    }

    
    for(int i=0; i<3; i++)
    {
        for(int y=0; y<3; y++)
            {
                if(this->type == VIDE)
                {
                    imageCell[i][y] = " ";
                }
                imageCell[i][y] = "X";
                //std::cout << "imageCell[i][y] : " << *imageCell[i][y] << RESET << std::endl;
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

    std::cout << "type" << type << std::endl;std::cout << "ici"<< std::endl;
    return this->type;
}

std::string Cell::printCellTerminal(int line)
{
    std::ostringstream os;
    
    os << imageCell[line][0];
    std::cout << "printCellTerminal" << std::endl;
    for(int i=1; i<3; i++)
    {
        os << imageCell[line][i];
    }
    
    return os.str();

}


void Cell::printCell()
{
    //std::cout << "printCell" << std::endl;
    for(int i=0; i<3; i++)
    {
        for(int y=0; y<3; y++)
        {
            std::cout << imageCell[i][y];
        }
        std::cout << std::endl;
    }
}
    
