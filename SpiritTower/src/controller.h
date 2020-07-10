//
// Created by AdrCh on 7/8/2020.
//

#ifndef SPIRITTOWER_CONTROLLER_H
#define SPIRITTOWER_CONTROLLER_H

/**
 * Clase temporal para almacenar datos del jugador y realizar pruebas
 */
class GameController{

public:

    void setPlayerX(int X);
    int getPlayerX();
    void setPlayerY(int Y);
    int getPlayerY();
    void setPlayerHP(int HP);
    int getPlayerHP();
    void reducePlayerHealth(int damage);

    GameController();

private:
    int playerX;
    int playerY;
    int playerHP;

};

#endif //SPIRITTOWER_CONTROLLER_H
