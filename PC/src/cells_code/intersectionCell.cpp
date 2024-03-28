#include "../libs/intersectionCell.h"
#include "../libs/cell.h"
#include <iostream>




IntersectionCell::IntersectionCell(int type) : Cell(type)
{
    std::cout << "Constructeur Intersection" << std::endl;
}

Cell *IntersectionCell::enterCell(int *orientation, int key[maxRoom], Engine *engine, int direction)
{
    int lastDir = direction;
    char dir;
    while(1)
    {
        engine->j_msg_rcv = engine->updateComponents(engine->arduino, engine->j_msg_rcv);
        if(engine->j_msg_rcv["btn_up"] == 0)
        {
            dir = 'w';
            break;
        }

        if(engine->j_msg_rcv["btn_left"] == 0)
        {
            dir = 'a';
            break;
        }

        if(engine->j_msg_rcv["btn_right"] == 0)
        {
            dir = 'd';
            break;
        }
    }
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
        cell = cell->enterCell(orientation, key, engine);
        if (cell != nullptr && !dynamic_cast<IntersectionCell*>(cell)) {
            return cell;
        }
    }
    direction = lastDir;
    return NULL;
    
}