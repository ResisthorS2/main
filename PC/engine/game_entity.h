#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H

class GameEntity {
public:
    void teleport(int x, int y);
    void setDimension(int width, int height);
    void setOffset(int x, int y);
    int getX();
    int getY();
    int getWidth();
    int getHeight();
protected:
    int x;
    int y;
    int width;
    int height;
    int offsetX;
    int offsetY;
};

#endif