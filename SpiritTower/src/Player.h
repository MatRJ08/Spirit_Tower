#pragma once
#ifndef SPIRITTOWER_PLAYER_H
#define SPIRITTOWER_PLAYER_H


class Player{
public:
    Player();
    int getHealth();
    int getXPosition();
    int getYPosition();
    void setHealth(int hp);
    void setXPosition(int xP);
    void setYPosition(int yP);
    void takeDamage(int damage);
private:
    int health;
    int xPosition;
    int yPosition;

};

#endif //SPIRITTOWER_PLAYER_H
