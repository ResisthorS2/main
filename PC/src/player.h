#ifndef PLAYER_H
#define PLAYER_H

#include "../engine/entities/CharacterEntity.h"

class Player : public CharacterEntity {
public:
    Player();
    ~Player();
    void update();
    void addPoints(int points);
    void removePoints(int points);
private:
    int points = 0;
};

#endif