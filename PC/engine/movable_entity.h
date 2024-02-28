#ifndef MOVABLE_ENTITY_H
#define MOVABLE_ENTITY_H

#include "game_entity.h"
#include "direction.h"

class MovableEntity : public GameEntity {
public:
    virtual void update() = 0;
    bool hasMoved();
    void stopMove();
    void move(Direction direction);
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    void setDirection(Direction direction);
    Direction getDirection();
    int getSpeed();
    void setSpeed(int speed);
protected:
    int speed;
    bool moved;
    Direction direction = Direction::Down;
};

#endif