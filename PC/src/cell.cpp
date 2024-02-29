
#include "cell.h"


#include <iostream>
#include <sstream>





using namespace std;


Cell::Cell()
{

    this->type = VIDE;
    locked = UNLOCKED;
    this->setImageCell(this);
    cell_north = NULL;
    cell_south = NULL;
    cell_east = NULL;
    cell_west = NULL;
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


    this->setImageCell(this);
    
}

Cell::~Cell()
{
    //std::cout << "destruction d'une cellule" << std::endl;
    delete cell_north;
    delete cell_south;
    delete cell_east;
    delete cell_west;
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

    typeColor = WHITE;
    if(*cell->getLocked() == LOCKED)
    {
        typeColor = RED;
    }
    else if(type != COULOIR)
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
                    imageCell[i][y] = typeColor+"0";
                }
            }
    }

    if(type > 1)
    {
        int x_door[] = {0, 2, 1, 1};
        int y_door[] = {1, 1, 2, 0};


        imageCell[x_door[type-2]][y_door[type-2]] = BLUE+"X";
    }
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
    //printf("orientation : %d\n", orientation);
    switch (orientation)
    {   
        case north:
            if(cell != NULL)
            {
                //printf("North\n");
            }
            this->cell_north = cell;
            break;
        case south:
            if(cell != NULL)
            {
                //printf("South\n");
            }
            this->cell_south = cell;
            break;
        case east:
            if(cell != NULL)
            {
                //printf("East\n");
            }
            this->cell_east = cell;
            break;
        case west:
            if(cell != NULL)
            {
                //printf("West\n");
            }
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
            return this->cell_east;
            break;
        case west:
            return this->cell_west;
            break;
    }
}


Cell *Cell::enterCell(int orientation, int key[1])
{
    int inverseOrientation[] = {south, north, west, east};

    north;
    south;
    east;
    west;
    
    if(type == COULOIR)
    {
        return this;
    }
    
    if(this->locked == UNLOCKED)
    {   
        //printf("Unlocked\n");
        std::cout << "type : " << orientation << std::endl;
        if(inverseOrientation[orientation] == (this->type-2))
        {
            return this;
        }
        return NULL;
        
    }
    else
    {
        //std::cout << "keyToUnlock : " << this->keyToUnlock << " key[i] = " << key[0]<< std::endl;
        if(key[0] == keyToUnlock)
        {
            //std::cout << "keyToUnlock : " << this->keyToUnlock << " key[i] = " << key[0]<< std::endl;
            if(inverseOrientation[orientation] == (this->type-2))
            {
                this->locked = UNLOCKED;
                return this;
            }
            else{return NULL;}

        }

    }
    return NULL;
}

void Cell::setKeyToUnlock(int keyToUnlock)
{
    this->keyToUnlock = keyToUnlock;
}

int Cell::getKeyToUnlock()
{
    return this->keyToUnlock;
}




