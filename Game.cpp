//
// Created by ashley on 14/7/20.
//

#include "Game.h"
#include "Criaturas.h"

Espectros * Game::generar_gen() {

    cout << "---------------------------" << endl;
    cout << "Piso 1 - Grises" << endl;
    PrimeraGen[0].Estadisticas();
    PrimeraGen[1].Estadisticas();
    PrimeraGen[2].Estadisticas();
    cout << "---------------------------" << endl;
    cout << "Piso 2 - Rojos" << endl;
    gen->Evolucion(PrimeraGen);
    cout << "---------------------------" << endl;
    cout << "Piso 2 - Azules" << endl;
    gen->Evolucion(PrimeraGen);



}
