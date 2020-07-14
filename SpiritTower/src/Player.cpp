#include "Player.h"

Player::Player() {
    xPosition = 0;
    yPosition = 0;
    health = 100;
}

int Player::getYPosition() {
    return yPosition;
}

int Player::getXPosition() {
    return xPosition;
}

int Player::getHealth() {
    return health;
}

void Player::setYPosition(int yP) {
    yPosition = yP;
}

void Player::setXPosition(int xP) {
    xPosition = xP;
}

void Player::setHealth(int hp) {
    health = hp;
}

void Player::takeDamage(int damage) {
    health -= damage;
}