#ifndef CELL_H
#include "cell.h"
#endif


#include <iostream>
#include <sstream>





using namespace std;


Cell::Cell()
{

    this->type = VIDE;
    this->setImageCell(this);
    cell_north = new Cell;
    cell_south = new Cell;
    cell_east = new Cell;
    cell_west = new Cell;
    cell_north = NULL;
    cell_south = NULL;
    cell_east = NULL;
    cell_west = NULL;
    locked = UNLOCKED;
}

Cell::Cell(int type)
{
    
    cell_north = new Cell;
    cell_south = new Cell;
    cell_east = new Cell;
    cell_west = new Cell;
    cell_north = NULL;
    cell_south = NULL;
    cell_east = NULL;
    cell_west = NULL;
    this->type = (type%10)*10;
    if(type > 10)
    {
        this->locked = LOCKED;
    }
    else
    {
        this->locked = UNLOCKED;
    }

    if(this->type > 1)
    {
        enterFrom = new int[2];
        switch(this->type)
        {
            case DOORNORTH:
                enterFrom[0] = 0; enterFrom[1] = 1;
                break;
            case DOORSOUTH:
                enterFrom[0] = 2; enterFrom[1] = 1;
                break;
            case DOOREAST:
                enterFrom[0] = 1; enterFrom[1] = 2;
                break;
            case DOORWEST:
                enterFrom[0] = 1; enterFrom[1] = 0;
                break;
        }
        this->setImageCell(this);
    }
    
}

Cell::~Cell()
{
    //std::cout << "destruction d'une cellule" << std::endl;
}



void Cell::setImageCell(Cell *cell)
{
    std::string typeColor;


    
    for(int i=0; i<3; i++)
    {
        for(int y=0; y<3; y++)
            {
                if(this->type == VIDE)
                {
                    imageCell[i][y] = " ";
                }
                else
                {
                    imageCell[i][y] = typeColor+"X";
                    //std::cout << "imageCell[i][y] : " << imageCell[i][y] << RESET << std::endl;
                }
            }
    }

    //printCell();
}


int Cell::getType()
{
    
    std::cout << "type" << type << std::endl;
    return this->type;
}

std::string Cell::printCellTerminal(int line)
{
    std::ostringstream os;
    
    os << imageCell[line][0];
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


void Cell::setType(int type)
{
    this->type = type;
    this->setImageCell(this);
}

void Cell::setLocked(int locked)
{
    this->locked = locked;
}

void Cell::setCellAround(int orientation, Cell* cell)
{
    switch (orientation)
    {
        case north:
            this->cell_north = cell;
            break;
        case south:
            this->cell_south = cell;
            break;
        case east:
            this->cell_east = cell;
            break;
        case west:
            this->cell_west = cell;
            break;
    }
}

int Cell::getLocked()
{
    return this->locked;
}

Cell* Cell::getCellAround(int orientation)
{
    switch (orientation)
    {
        case north:
            return this->cell_north;
            break;
        case south:
            return this->cell_south;
            break;
        case east:
            return this->cell_east;
            break;
        case west:
            return this->cell_west;
            break;
    }
}

void Cell::cpyEnterFrom(int *enterFrom)
{
    enterFrom[0] = this->enterFrom[0];
    enterFrom[1] = this->enterFrom[1];
}

