#include "controller.h"

GameController::GameController() {
    specterList = new LinkedList<Specter>();
    player = new Player();
    player->setHealth(100);
}

void GameController::updateEnemy(std::string name, int xP, int yP) {
    if(specterList->getSize() > 0){
        Specter current;
        for(int i = 0; i < specterList->getSize(); i++){
            current = specterList->getNodeInIndex(i)->nodeData;
            if(name == current.getName()){
                current.setXPosition(xP);
                current.setYPosition(yP);
                break;
            }
        }
    }
}

void GameController::updatePlayer(int xP, int yP, int HP) {
    player->setYPosition(xP);
    player->setXPosition(yP);
    //player->setHealth(HP);

}

void GameController::printGameData() {
    while(true) {
        std::cout << "\n\nPlayer:\n" << "X:" << player->getXPosition() << ", Y:" << player->getYPosition() <<
                  ", HP:" << player->getHealth() << std::endl;
        if (specterList->getSize() > 0) {
            Specter current;
            for (int i = 0; i < specterList->getSize(); i++) {
                current = specterList->getNodeInIndex(i)->nodeData;
                std::cout << "Enemy " << current.getName() << ":\n" << "X:" << current.getXPosition() << ", Y:" <<
                          current.getYPosition() << std::endl;
            }
        }
    }

}

void GameController::reducePlayerHealth(int damage) {
    player->takeDamage(damage);
}

int GameController::getPlayerHP() {
    return player->getHealth();
}

void GameController::createEnemy(std::string name, int xP, int yP) {
    Specter Espectro = Specter(name, xP, yP);
    specterList->addNodeLast(Espectro);

}

