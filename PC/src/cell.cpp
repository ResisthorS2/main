
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

    if(type > 10) //Si type est supérieur à 10, alors la cellule est vérouillée
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
    //definition des couleurs pour les prints des cellules
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
        int x_door[] = {0, 2, 1, 1}; //ici c'est pour les portes c'est les coordonnées pour la lignes 107. l'ordre des listes est [Porte Nord, Porte Sud, Porte Est, Porte Ouest]
        int y_door[] = {1, 1, 2, 0}; // même chose ici mais pour la coordonnée de la pour en y

        imageCell[x_door[type-2]][y_door[type-2]] = BLUE+"X"; //puisque mes x_door et y_door vont de i[0 à 4] et que type va de 2 à 5, je fais type-2 pour que ça corresponde à l'index de mes listes
    }
}


int *Cell::getType()
{   
    //std::cout << "type :" << this->type << std::endl;
    return &this->type;
}

std::string Cell::printCellTerminal(int line)
{
    
    // pour l'impression des cellules je fais une ligne à la fois puisque chaque case a 3 lignes
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
    
    // ici c'est une fonction qui print une cellule pour du debug
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
    // la fonction est pour set une case autour de la case actuelle
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


Cell *Cell::enterCell(int orientation, int key[1]) //Fonction super importante.
{
    int inverseOrientation[] = {south, north, west, east}; //tableau pour regarder l'orientation inverse du joueur. Exemple: si le joueur est orienté vers le nord, inverseOrientation[north] = south
    
    if(type == COULOIR) // pas besoin de faire la vérif puisque c'est un couloir
    {
        return this;
    }
    
    if(this->locked == UNLOCKED)
    {   
        if(inverseOrientation[orientation] == (this->type-2)) //Vérification si la porte est dans la direction du joueur pour ne pas qu'il sorte par un mur
        {
            return this;
        }
        return NULL;
        
    }
    else
    {
        if(key[0] == keyToUnlock) //Vérification si le joueur a la clé pour dévérouiller la porte
        {
            if(inverseOrientation[orientation] == (this->type-2))//Vérification si la porte est dans la direction du joueur pour ne pas qu'il sorte par un mur
            {
                this->locked = UNLOCKED;
                return this;
            }
            else{return NULL;}

        }

    }
    return NULL; //Si le joueur n'a pas la clé pour dévérouiller la porte ou que la case est vide
}

void Cell::setKeyToUnlock(int keyToUnlock)
{
    this->keyToUnlock = keyToUnlock;
}

int Cell::getKeyToUnlock()
{
    return this->keyToUnlock;
}




