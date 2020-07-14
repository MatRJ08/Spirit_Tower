#pragma once
#ifndef SPIRITTOWER_CONTROLLER_H
#define SPIRITTOWER_CONTROLLER_H

#include "Player.h"
#include "Specter.h"
#include "LinkedList.cpp"
/**
 * Clase temporal para almacenar datos del jugador y realizar pruebas
 */
class GameController{

public:

    void updatePlayer(int xP, int yP, int HP);
    void reducePlayerHealth(int damage);
    int getPlayerHP();
    void updateEnemy(std::string name, int xP, int yP);
    void printGameData();
    void createEnemy(std::string name, int xP, int yP);
    GameController();

private:
    LinkedList<Specter>* specterList;
    Player* player;

};

#endif //SPIRITTOWER_CONTROLLER_H
