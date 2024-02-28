#ifndef CHARACTER_ENTITY_H
#define CHARACTER_ENTITY_H

#include "movable_entity.h"

class CharacterEntity : public MovableEntity {
public:
    void setHealth(int health);
    int getHealth();
    void setMaxHealth(int max);
    int getMaxHealth();
    void heal(int health);
    void hurt(int damage);
    void setDamage(int damage);
    int attack();
    bool isDead();
protected:
    int health;
    int maxHealth;
    int damage;
};

#endif