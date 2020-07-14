#include "Specter.h"

Specter::Specter() {

}

Specter::Specter(std::string n, int xP, int yP) {
    name = n;
    xPosition = xP;
    yPosition = yP;
}

void Specter::setHealth(int hp) {
    health = hp;
}

void Specter::setChaseSpeed(int cs) {
    chaseSpeed = cs;
}

void Specter::setPatrolSpeed(int ps) {
    patrolSpeed = ps;
}

void Specter::setXPosition(int xP) {
    xPosition = xP;
}

void Specter::setYPosition(int yP) {
    yPosition = yP;
}

void Specter::setName(std::string n) {
    name = n;
}

int Specter::getHealth() {
    return health;
}

int Specter::getChaseSpeed() {
    return chaseSpeed;
}

int Specter::getViewDistance() {
    return viewDistance;
}

int Specter::getXPosition() {
    return xPosition;
}

int Specter::getYPosition() {
    return yPosition;
}

int Specter::getPatrolSpeed() {
    return patrolSpeed;
}

std::string Specter::getName() {
    return name;
}