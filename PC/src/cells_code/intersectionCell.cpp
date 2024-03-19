#include "../libs/intersectionCell.h"
#include "../libs/cell.h"
#include <iostream>




IntersectionCell::IntersectionCell(int type) : Cell(type)
{
    std::cout << "Constructeur Intersection" << std::endl;
}

Cell *IntersectionCell::enterCell(int *orientation, int key[maxRoom], int direction)
{
    std::cout << "EnterCell Intersection" << std::endl;
    char dir;
    std::cin >> dir;
    switch(dir)
    {
        case 'a':
            direction = LEFT;
            break;
        case 'd':
            direction = RIGHT;
            break;
        case 'w':
            direction = UP;
            break;
        default:
            direction = RIGHT;
            break;
    }

    


    //orientation int{NONE=-1, north=0, south=1, east=2, west=3}
    int directionPossible[] = {north, east, south, west};
    int inverseOrientation[] = {south, west, north, east};

    switch (direction)
    {
        case LEFT:
            *orientation-=1;
            if(*orientation < 0)
                *orientation = 3;
            break;
        
        
        case RIGHT:
            *orientation+=1;
            if(*orientation > 3)
                *orientation = 0;
                break;
    }
    
    Cell *cell = this->getCellAround(*orientation);
    if (cell != nullptr) {
        cell = cell->enterCell(orientation, key);
        if (cell != nullptr && !dynamic_cast<IntersectionCell*>(cell)) {
            return cell;
        }
    }
    return NULL;
    
}