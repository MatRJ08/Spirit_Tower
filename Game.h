//
// Created by ashley on 14/7/20.
//

#ifndef SPIRIT_TOWER_GAME_H
#define SPIRIT_TOWER_GAME_H

#include "genetico/Espectros.h"
#include "genetico/Evolucionador.h"
#include "path/lista.h"
#include "path/Nodo.h"

class Game {
private:

    Evolucionador* gen = new Evolucionador();
    //Arreglo inicial de 3 espectros con el que comenzará la población
    Espectros PrimeraGen[3];




public:

    Espectros * generar_gen();

};


#endif //SPIRIT_TOWER_GAME_H
