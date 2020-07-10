#include "controller.h"

void GameController::setPlayerHP(int HP) {
    playerHP = HP;
}

void GameController::setPlayerX(int X) {
    playerX = X;
}

void GameController::setPlayerY(int Y) {
    playerY = Y;
}

int GameController::getPlayerHP() {
    return playerHP;

}
int GameController::getPlayerX() {
    return playerX;

}
int GameController::getPlayerY() {
    return playerY;

}

void GameController::reducePlayerHealth(int damage) {
    playerHP -= damage;
}

GameController::GameController() {
    playerX = 0;
    playerY = 0;
    playerHP = 0;

}