#include "game_entity.h"

void GameEntity::teleport(int x, int y) {
    this->x = x;
    this->y = y;
}

void GameEntity::setDimension(int width, int height) {
    this->width = width;
    this->height = height;
}

void GameEntity::setOffset(int x, int y) {
    this->offsetX = x;
    this->offsetY = y;
}

int GameEntity::getX() {
    return x;
}

int GameEntity::getY() {
    return y;
}

int GameEntity::getWidth() {
    return width;
}

int GameEntity::getHeight() {
    return height;
}