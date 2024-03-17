#include "intersection.h"
#include "cell.h"
#include <iostream>




Intersection::Intersection(int type) : Cell(type)
{
    std::cout << "Constructeur Intersection" << std::endl;
}

Cell *Intersection::enterCell(int *orientation, int key[maxRoom], int direction)
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
        default:
            direction = RIGHT;
            break;
    }

    


    //orientation int{NONE=-1, north=0, south=1, east=2, west=3}
    int directionPossible[] = {north, east, south, west};
    int inverseOrientation[] = {south, west, north, east};
    std::cout << "orientation : " << *orientation << std::endl;
    std::cout << "direction : " << direction << std::endl;



    switch (direction)
    {
        case LEFT:
            *orientation-=1;
            printf("orientation XXX: %d\n", *orientation);
            if(*orientation < 0)
                *orientation = 3;
            break;
        
        
        case RIGHT:
            *orientation+=1;
            if(*orientation > 3)
                *orientation = 0;
                break;
    }

    
    /*for(int i = 0; i < 4; i++)
    {   
 
        if((this->getCellAround(directionPossible[i])) != NULL)  //s'il existe une case à côté
            {
                if(((this->getCellAround((directionPossible[i])))->enterCell(orientation, key)) != NULL) // regarde s'il peut se déplacer dans la case
                {
                    Cell *c = (this->getCellAround(directionPossible[i]))->enterCell(&directionPossible[i], key);
                    if(c != NULL)
                    {
                        
                        std::cout << directionPossible[i] << " : " << std::endl;
                        c->printCell();
                    }
                    else
                    {
                        std::cout << directionPossible[i] << " : NULL" << std::endl;
                    }
                    
                }
            }
        
        
    }*/
    
    std::cout << "orientation : " << *orientation << std::endl;
    Cell *cell = this->getCellAround(*orientation);
    if (cell != nullptr) {
        cell = cell->enterCell(orientation, key);
        if (cell != nullptr && !dynamic_cast<Intersection*>(cell)) {
            cell->printCell();
            return cell;
        }
    }
    return NULL;
    
}