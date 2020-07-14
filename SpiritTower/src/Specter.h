#pragma once
#ifndef SPIRITTOWER_SPECTER_H
#define SPIRITTOWER_SPECTER_H


#include<iostream>
class Specter{

public:
    Specter();
    Specter(std::string n, int xP, int yP);

    void setHealth(int hp);
    void setPatrolSpeed(int ps);
    void setChaseSpeed(int cs);
    void setViewDistance(int vd);
    void setXPosition(int xP);
    void setYPosition(int yP);
    std::string getName();
    void setName(std::string n);
    int getHealth();
    int getPatrolSpeed();
    int getChaseSpeed();
    int getViewDistance();
    int getXPosition();
    int getYPosition();

private:
    int health;
    int patrolSpeed;
    int chaseSpeed;
    int viewDistance;
    int xPosition;
    int yPosition;
    std::string name;
};

#endif //SPIRITTOWER_SPECTER_H
