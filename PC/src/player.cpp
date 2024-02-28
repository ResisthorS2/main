
#include "cell.h"



#include "player.h"


#define move180



Player::Player()
{
    orientation = east;
}

Player::~Player()
{
    delete cell_north;
    delete cell_south;
    delete cell_east;
    delete cell_west;
    delete enterFrom;
}

int Player::getOrientation()
{
    return orientation;
}

void Player::setImageCell(Player *cell)
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
                    *imageCell[i][y] = " ";
                }
                else
                {
                    *imageCell[i][y] = typeColor+"X";
                    //std::cout << "imageCell[i][y] : " << imageCell[i][y] << RESET << std::endl;
                }
            }
    }

    if(orientation != NONE)
    {   
        printf("orientation : %d\n", orientation);
        switch (orientation)
        {
            
            case north:
                printf("north\n");
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

void Player::cpyCell(Cell* cell)
{
    if (cell != nullptr) {
        this->type = cell->getType();
        this->locked = cell->getLocked();
        this->cell_north = cell->getCellAround(north);
        this->cell_south = cell->getCellAround(south);
        this->cell_east = cell->getCellAround(east);
        this->cell_west = cell->getCellAround(west);
        this->enterFrom = cell->getEnterFrom();
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


void Player::move(int direction)
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
            std::cout << "Action UP orientation : "<< this->getOrientation() << std::endl;
            if(this->getCellAround(this->orientation) != NULL)  //s'il a une case à côté
            {
                std::cout << "cell around n'est pas null" << std::endl;
                if(this->getCellAround(this->getOrientation())->enterCell() != NULL) //si nous n'avons pas la clé
                {
                    this->cpyCell(this->getCellAround(this->getOrientation())->enterCell());
                    std::cout << "cell orientation = " << this->getCellAround(this->getOrientation()) << std::endl;
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

void Player::setOrientation(int orientation)
{
    this->orientation = orientation;
}


