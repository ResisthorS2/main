
#include "cell.h"



#include "player.h"


#define move180



Player::Player()
{
    cell_north = new Cell;
    cell_south = new Cell;
    cell_east = new Cell;
    cell_west = new Cell;
    orientation = north;
}

Player::~Player()
{

}

int Player::getOrientation()
{
    return orientation;
}

void Player::setImageCell(Cell *cell)
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


    if(cell->getLocked() == LOCKED)
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

    if(orientation != NONE)
    {
        switch (orientation)
        {
            case north:
                imageCell[0][1] = YELLOW+"^";
                imageCell[0][0] = YELLOW+"|";
                break;
            case south:
                imageCell[2][1] = YELLOW+"v";
                imageCell[2][2] = YELLOW+"|";
                break;
            case east:
                imageCell[1][2] = YELLOW+">";
                imageCell[2][2] = YELLOW+"-";
                break;
            case west:
                imageCell[1][0] = YELLOW+"<";
                imageCell[2][0] = YELLOW+"-";
                break;
        }
    }
}

void Player::operator=(Cell* cell)
{
    if (this != cell && cell != nullptr) {
        this->type = cell->getType();
        this->setImageCell(cell);
        this->setLocked(cell->getLocked());
        this->setCellAround(north, cell->getCellAround(north));
        this->setCellAround(south, cell->getCellAround(south));
        this->setCellAround(east, cell->getCellAround(east));
        this->setCellAround(west, cell->getCellAround(west));
        cell->cpyEnterFrom(this->enterFrom);
    }
}


void Player::move(int direction)
{
    int directionPossible[] = {north, west, south, east};
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
            break;
        
        
        case RIGHT:
            index++;
            if(index > 3)
                index = 0;
            break;
        
        
        case UP:
        {
            if(this->getCellAround(this->getOrientation()) != NULL)  //s'il a une case à côté
            {
                if(this->getCellAround(this->getOrientation())->enterCell() != NULL) //si nous n'avons pas la clé
                {
                    Cell*cell = this->getCellAround(this->getOrientation());
                    *this=cell->enterCell(); //Appelle de la surcharge de l'opérateur =
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