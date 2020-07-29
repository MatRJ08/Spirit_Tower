//
// Created by ashley on 14/7/20.
//

#include "Criaturas.h"

Criaturas::Criaturas(Espectros est){
    estud=est;
    cout << "  Velocidad de ruta " <<estud.get_vel_ruta() << "  Velocidad de pers " <<estud.get_vel_persecucion() << "  Vision " <<estud.get_vision() << endl;
}