#include "player.h"

Player::Player() {
    x = 0;
    y = 0;
    width = 0;
    height = 0;
    speed = 1;
    moved = false;
    height = 3;
    damage = 1;
}

Player::~Player() {
    
}

void Player::update() {

}

void Player::addPoints(int points) {
    this->points += points;
}

void Player::removePoints(int points) {
    this->points -= points;
}