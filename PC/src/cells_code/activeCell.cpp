
#include "../libs/cell.h"



#include "../libs/activeCell.h"



#define move180



ActiveCell::ActiveCell()
{
    
    player = new Player;
    cell_north = nullptr;
    cell_south = nullptr;
    cell_east = nullptr;
    cell_west = nullptr;
}

ActiveCell::~ActiveCell()
{

    if(cell_north != nullptr){delete cell_north;}
    if(cell_south != nullptr){delete cell_south;}
    if(cell_east != nullptr){delete cell_east;}
    if(cell_west != nullptr){delete cell_west;}
    printf("delete activeCell\n");

}



void ActiveCell::setImageCell(ActiveCell *cell) //Ici c'est un fonction surloadé. Elle est utilisé pour mettre à jour l'image de la cellule active
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


    if(player->orientation != NONE)
    {   
        //printf("orientation : %d\n", orientation);
        
        switch (player->orientation)
        {
            
            case north:
                *(imageCell[0][1]) = YELLOW+"^"; //Ici la fonction vient remplacer dans les case de l'image active le joueur pour qu'on puisse le voir
                *(imageCell[1][1]) = YELLOW+"|";  //À chaque print de la map chaque case est reregardé pour les remettre normal si le joueur n'y est pas mais ça se fait dans printMap()
                break;
            case south:
                *(imageCell[2][1]) = YELLOW+"v";  //Fait pas le saut, les x et y sont pas dans le sens normal
                *(imageCell[1][1]) = YELLOW+"|";
                break;
            case east:
                *(imageCell[1][2]) = YELLOW+">";
                *(imageCell[1][1]) = YELLOW+"-";
                break;
            case west:
                *(imageCell[1][0]) = YELLOW+"<";
                *(imageCell[1][1]) = YELLOW+"-";
                break;
        }
    }
}

void ActiveCell::cpyCell(Cell* cell)
{
    if (cell != nullptr) {
        //printf("cell is not null\n");
        this->type = cell->getType();
        
        this->locked = cell->getLocked();
        this->cell_north = cell->getCellAround(north);
        this->cell_south = cell->getCellAround(south);
        this->cell_east = cell->getCellAround(east);
        this->cell_west = cell->getCellAround(west);

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                this->imageCell[i][j] = &cell->imageCell[i][j];
            }
        }
    }
    this->setImageCell(this);
}


void ActiveCell::move(int direction, Engine *engine)
{
    std::cout << "move" << std::endl;
    int directionPossible[] = {north, east, south, west}; // ici c'est pour pas faire des switchs cases pour tourner à droite ou à gauche J'ai mis un XXX ou que c'est utilisé
    int index;


    for(int i=0; i<4; i++)
    {
        if(player->orientation == directionPossible[i])
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
        
        

        case DOWN:
            
            
            int inverseOrientation[] = {south, west, north, east};
            player->setOrientation(inverseOrientation[player->orientation]);
            std::cout << "l.137" << player->orientation << std::endl;
            return;
    }


    if(*this->type > 1 && *this->type != 6 && *this->type < 3000)
    {
        std::cout << "l.144" << std::endl;
        if(player->orientation != (*this->type-2)) //TODO
        {
            std::cout << "Vous ne pouvez pas passer par là" << std::endl;
            return;
        }
    }

    
    if(this->getCellAround(index) != NULL)
    {
        std::cout << "l.156"  << std::endl;
        if(*(this->getCellAround(index))->getType() != 6)
        {
            std::cout << "l.159" << std::endl;
            std::cout << "index : " << index << std::endl;
            std::cout << "player->orientation : " << player->orientation << std::endl;
            std::cout << "direction : " << direction << std::endl;
            Cell *cell = (this->getCellAround(index))->enterCell(&index, player->objects, direction);
            if(cell != NULL)
            {
                this->cpyCell(cell);
                
            }
        }

        else
        {
            std::cout << "l.170" << std::endl;
            Cell *cell = (this->getCellAround(player->orientation))->enterCell(&player->orientation, player->objects, direction);
            if(cell != NULL)
            {
                this->cpyCell(cell);
                
            }
        }
        
    }
    else
    {
        std::cout << "l.178" << player->orientation << std::endl;
        return;
    }

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



