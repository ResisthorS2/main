#ifndef PLAYER_H
#define PLAYER_H

#include "character_entity.h"

class Player : public CharacterEntity {
public:
    Player();
    void update();
    void addPoints(int points);
    void removePoints(int points);
private:
    int points = 0;
};

#endif