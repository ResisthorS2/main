
#include "cell.h"


#include <iostream>
#include <sstream>





using namespace std;


Cell::Cell()
{
    enterFrom = new int[2];
    this->type = VIDE;
    locked = UNLOCKED;
    this->setImageCell(this);
    cell_north = NULL;
    cell_south = NULL;
    cell_east = NULL;
    cell_west = NULL;
    enterFrom = NULL;
}

Cell::Cell(int type)
{
    
    cell_north = new Cell;
    cell_south = new Cell;
    cell_east = new Cell;
    cell_west = new Cell;
    if(type > 10)
    {
        this->type = (type-10);
        this->locked = LOCKED;
    }
    else
    {
        this->type = type;
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
    }

    this->setImageCell(this);
    
}

Cell::~Cell()
{
    std::cout << "destruction d'une cellule" << std::endl;
    delete cell_north;
    delete cell_south;
    delete cell_east;
    delete cell_west;
    delete enterFrom;
}



void Cell::setImageCell(Cell *cell)
{
    std::string RESET  = "\x1b[0m";
    std::string BLACK  = "\x1b[30m";      /* Black */
    std::string RED    = "\x1b[31m";      /* Red */
    std::string GREEN  = "\x1b[32m";      /* Green */
    std::string YELLOW = "\x1b[33m";      /* Yellow */
    std::string BLUE   = "\x1b[34m";      /* Blue */
    std::string MAGENTA = "\x1b[35m";      /* Magenta */
    std::string CYAN   = "\x1b[36m";      /* Cyan */
    std::string WHITE  = "\x1b[37m";      /* White */
    std::string typeColor;


    if(*cell->getLocked() == LOCKED)
    {
        typeColor = RED;
    }
    else
    {
        typeColor = GREEN;
    }

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


int *Cell::getType()
{
    
    //std::cout << "type :" << this->type << std::endl;
    return &this->type;
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
            printf("North\n");
            this->cell_north = cell;
            break;
        case south:
            printf("South\n");
            this->cell_south = cell;
            break;
        case east:
            printf("East\n");
            this->cell_east = cell;
            break;
        case west:
            printf("West\n");
            this->cell_west = cell;
            break;
    }
}

int *Cell::getLocked()
{
    return &this->locked;
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
        printf("East\n");
            return this->cell_east;
            break;
        case west:
            return this->cell_west;
            break;
    }
}

void Cell::cpyEnterFrom(int *enterFrom)
{
    if(this->enterFrom != NULL)
    {
        enterFrom[0] = this->enterFrom[0];
        enterFrom[1] = this->enterFrom[1];
    }
    
    
}

Cell *Cell::enterCell()
{
    if(this->locked == UNLOCKED)
    {   
        printf("Unlocked\n");
        return this;
    }
    else
    {
        printf("Locked\n");
        return NULL;
    }
}

int *Cell::getEnterFrom()
{
    return this->enterFrom;
}



