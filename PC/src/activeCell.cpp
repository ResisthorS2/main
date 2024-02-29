
#include "cell.h"



#include "activeCell.h"


#define move180



ActiveCell::ActiveCell()
{
    orientation = east;

}

ActiveCell::~ActiveCell()
{
    delete cell_north;
    delete cell_south;
    delete cell_east;
    delete cell_west;
}

int ActiveCell::getOrientation()
{
    return orientation;
}

void ActiveCell::setImageCell(ActiveCell *cell)
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

    if(orientation != NONE)
    {   
        //printf("orientation : %d\n", orientation);
        switch (orientation)
        {
            
            case north:
                *imageCell[0][1] = YELLOW+"^";
                *imageCell[1][1] = YELLOW+"|";
                break;
            case south:
                *imageCell[2][1] = YELLOW+"v";
                *imageCell[1][1] = YELLOW+"|";
                break;
            case east:
                *imageCell[1][2] = YELLOW+">";
                *imageCell[1][1] = YELLOW+"-";
                break;
            case west:
                *imageCell[1][0] = YELLOW+"<";
                *imageCell[1][1] = YELLOW+"-";
                break;
        }
    }
}

void ActiveCell::cpyCell(Cell* cell)
{
    if (cell != nullptr) {
        this->type = cell->getType();
        this->locked = cell->getLocked();
        this->cell_north = cell->getCellAround(north);
        this->cell_south = cell->getCellAround(south);
        this->cell_east = cell->getCellAround(east);
        this->cell_west = cell->getCellAround(west);
        if(cell_north == NULL)
        {
            //printf("cell_north = NULL\n");
        }
        if(cell_south == NULL)
        {
            //printf("cell_south = NULL\n");
        }
        if(cell_east == NULL)
        {
            //printf("cell_east = NULL\n");
        }
        if(cell_west == NULL)
        {
            //printf("cell_west = NULL\n");
        }

        this->imageCell = new std::string**[3];
        for(int i = 0; i < 3; i++) {
            this->imageCell[i] = new std::string*[3];
            for(int j = 0; j < 3; j++) {
                this->imageCell[i][j] = &cell->imageCell[i][j];
            }
        }
        this->setImageCell(this);
    }
}


void ActiveCell::move(int direction)
{
    int directionPossible[] = {north, east, south, west};
    int index;


    for(int i=0; i<4; i++)
    {
        if(this->getOrientation() == directionPossible[i])
        {
            index = i;
        }
    }

    switch (direction)
    {
        case LEFT:
            index--;
            if(index < 0)
                index = 3;
            this->orientation = directionPossible[index];
            break;
        
        
        case RIGHT:
            this->orientation = index++;
            if(index > 3)
                index = 0;
            this->orientation = directionPossible[index];
            break;
        
        
        case UP:
        {
            //std::cout << "type: " << *type << std::endl;
            if(*this->type > 1)
            {
                
                if(orientation != (*this->type-2))
                {
                    return;
                }
            }
            if((this->getCellAround(this->orientation)) != NULL)  //s'il a une case à côté
            {
                //std::cout << "cell around n'est pas null" << std::endl;
                if(((this->getCellAround((this->orientation)))->enterCell(this->orientation, this->keys)) != NULL) //si nous n'avons pas la clé
                {
                    Cell *cell = (this->getCellAround(this->orientation))->enterCell(this->orientation, this->keys);
                    this->cpyCell(cell);
                    //std::cout << "cell orientation = " << this->getCellAround(this->getOrientation()) << std::endl;
                }
            }
            break;;
        }


        case DOWN:
            switch (this->getOrientation())
            {
                case north:
                    this->setOrientation(south);
                    break;
                case south:
                    this->setOrientation(north);
                    break;
                case east:
                    this->setOrientation(west);
                    break;
                case west:
                    this->setOrientation(east);
                    break;
            }
            break;
    }
    this->setImageCell(this);
}

void ActiveCell::setOrientation(int orientation)
{
    this->orientation = orientation;
}

Cell *ActiveCell::getCellAround(int orientation)
{
    switch (orientation)
    {
        case north:
            return cell_north;
            break;
        case south:
            return cell_south;
            break;
        case east:
            return cell_east;
            break;
        case west:
            return cell_west;
            break;
    }
    return NULL;
}

int ActiveCell::getKey()
{
    return keys[0];
}


