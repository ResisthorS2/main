#include "../src/libs/player.h"
#include <iostream>


Player::Player()
{
    objects = new int[6];
    objects[0] = 3018;
    for(int i = 1; i < 6; i++)
    {
        objects[i] = -1;
    }

    orientation = north;
}

Player::~Player()
{
    delete objects;
}

void Player::addObjects(int object)
{
    for(int i = 0; i < 6; i++)
    {
        if(objects[i] == -1)
        {
            objects[i] = object;
            break;
        }
    }
}

int Player::getOrientation()
{
    return orientation;
}

void Player::setOrientation(int orientation)
{

    this->orientation = orientation;
}



