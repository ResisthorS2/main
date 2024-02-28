#include "movable_entity.h"

bool MovableEntity::hasMoved() {
    return moved;
}

void MovableEntity::stopMove() {
    moved = false;
}

void MovableEntity::move(Direction direction) {
    switch (direction)
    {
    case Direction::Down :
        y--;
        break;
    case Direction::Up :
        y++;
        break;
    case Direction::Left :
        x--;
        break;
    case Direction::Right :
        x++;
        break;
    }
}

void MovableEntity::moveLeft() {
    move(Direction::Left);
}

void MovableEntity::moveRight() {
    move(Direction::Right);
}

void MovableEntity::moveUp() {
    move(Direction::Up);
}

void MovableEntity::moveDown() {
    move(Direction::Down);
}

void MovableEntity::setDirection(Direction direction) {
    this->direction = direction;
}

Direction MovableEntity::getDirection() {
    return direction;
}

int MovableEntity::getSpeed() {
    return speed;
}

void MovableEntity::setSpeed(int speed) {
    this->speed = speed;
}