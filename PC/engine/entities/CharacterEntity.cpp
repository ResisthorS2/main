#include "character_entity.h"

void CharacterEntity::setHealth(int health) {
    this->health = health;
}

int CharacterEntity::getHealth() {
    return health;
}

void CharacterEntity::setMaxHealth(int max) {
    this->maxHealth = max;
}

int CharacterEntity::getMaxHealth() {
    return maxHealth;
}

void CharacterEntity::heal(int health) {
    this->health += health;
    if (this->health > maxHealth) this->health = maxHealth;
}

void CharacterEntity::hurt(int damage) {
    health -= damage;
}

void CharacterEntity::setDamage(int damage) {
    this->damage = damage;
}

int CharacterEntity::attack() {
    return damage;
}

bool CharacterEntity::isDead() {
    return health <= 0;
}