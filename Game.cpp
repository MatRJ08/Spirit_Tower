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
    return PrimeraGen;
}

Espectros * Game::generar_gen2() {
    cout << "---------------------------" << endl;
    cout << "Piso 2 - Rojos" << endl;
    gen->Obtener_Resistencia(PrimeraGen);
    return gen->get_nueva_gen();


}

Espectros * Game::generar_gen3() {
    cout << "---------------------------" << endl;
    cout << "Piso 3 - Azules" << endl;
    gen->Obtener_Resistencia(gen->get_nueva_gen());
    return gen->get_nueva_gen();

}
Espectros * Game::generar_gen4() {
    cout << "---------------------------" << endl;
    cout << "Piso 4 - 1 Gris, 1 Azul y 1 Rojo" << endl;
    gen->Obtener_Resistencia(gen->get_nueva_gen());
    return gen->get_nueva_gen();


}
