#include "../libs/gameCell.h"
#include "../libs/minigames.h"



MiniGame minigame;

GameCell::GameCell(int type)
{
    std::cout << "Constructeur GameCell" << std::endl;
    cell_north = new Cell;
    cell_south = new Cell;
    cell_east = new Cell;
    cell_west = new Cell;
    this->type = type;
    std::cout << "Type : " << type << std::endl;
    key_to_unlock = new int;
    *key_to_unlock = type;
    locked = new int;
    *locked = LOCKED;
    int null[] = {-1,-1,-1,-1,-1,-1};
    if(type == 3016)
    {
        *locked = UNLOCKED;
    }
    this->setImageCell(this, null);

}

GameCell::~GameCell()
{
    delete cell_north;
    delete cell_south;
    delete cell_east;
    delete cell_west;
    delete key_to_unlock;
    delete locked;

    int null[] = {-1,-1,-1,-1,-1,-1};
    this->setImageCell(this, null);
}

Cell *GameCell::enterCell(int *orientation, int key[6], int direction)
{
    int inverseOrientation[] = {south, west, north, east};
    
    std::cout << "int key[6]->object "<< key << "  " << this->key_to_unlock << std::endl;
    for(int i=0; i<6; i++)
    {
        if(key[i] == *key_to_unlock)
        {
            *locked = UNLOCKED;
            break;
        }
    }
    std::cout << "La porte est fermée" << std::endl;
    if(*locked == UNLOCKED)
    {
       
        switch(type)
        {
            case(3022):
                l3022(key, this->type);
                break;
            case(3019):
                l3019(key, this->type);
                break;
            case(3018):
                l3018(key, this->type);
                break;
            case(3041):
                l3041(key, this->type);
                break;
            case(3016):
                l3016(key, this->type);
                break;
            case(3024):
                l3024(key, this->type);
                break;
        }
    }


    *orientation = inverseOrientation[*orientation];
    return this->getCellAround(*orientation);


}

void GameCell::setImageCell(Cell *cell, int key[6])
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

    typeColor = RED;
    if(type == LOCKED)
    {
        for(int i=0; i<6; i++)
        {
            if(key[i] == *key_to_unlock)
            {
                typeColor = GREEN;
                *locked = UNLOCKED;
            }
        }
    }


    for(int i=0; i<3; i++)
    {
        for(int y=0; y<3; y++)
            {
                {
                    imageCell[i][y] = typeColor+"0";
                }
            }
    }

    switch (this->type)
    {
        case 3022:
            imageCell[1][2] = BLUE+"X";
            break;
        case 3019:
            imageCell[1][0] = BLUE+"X";
            break;
        case 3018:
            imageCell[1][0] = BLUE+"X";
            break;
        case 3041:
            imageCell[1][2] = BLUE+"X";
            break;
        case 3016:
            imageCell[1][0] = BLUE+"X";
            break;
        case 3024:
            imageCell[1][2] = BLUE+"X";
            break;
    
    }
}

void GameCell::l3022(int key[6], int cell_type)
{
    system("cls");
    std::cout << "Jeu local 3022" << std::endl;
    minigame.play_solderGame(key, this->type);
    
}

void GameCell::l3019(int key[6], int cell_type)
{
    system("cls");
    std::cout << "Jeu local 3019" << std::endl;
    char wait;
    std::cin >> wait;
}

void GameCell::l3018(int key[6], int cell_type)
{
    system("cls");
    std::cout << "Jeu local 3018" << std::endl;
    minigame.play_resistanceGame(key, this->type);
}

void GameCell::l3041(int key[6], int cell_type)
{
    
    system("cls");
    std::cout << "Jeu local 3041" << std::endl;
    char wait;
    std::cin >> wait;
}

void GameCell::l3016(int key[6], int cell_type)
{
    system("cls");
    std::cout << "Jeu local 3016" << std::endl;
    minigame.play_oscilloscopeGame(key, this->type);
}

void GameCell::l3024(int key[6], int cell_type)
{
    system("cls");
    std::cout << "Jeu local 3024" << std::endl;
    char wait;
    std::cin >> wait;
}

