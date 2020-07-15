//
// Created by ashley on 11/7/20.
//

#ifndef SPIRIT_TOWER_EVOLUCIONADOR_H
#define SPIRIT_TOWER_EVOLUCIONADOR_H

#include "Espectros.h"

class Evolucionador {



public:

    Evolucionador();

    Espectros* Evolucion(Espectros* a);

    int* Obtener_Resistencia(Espectros* arreglo);

    Espectros* Seleccion(int* chequear_resistencia, Espectros[]);

    Espectros* Cruce(Espectros padre1, Espectros padre2);

    int Mutacion();

    int Index (int arr[], int t);

};


#endif //SPIRIT_TOWER_EVOLUCIONADOR_H
