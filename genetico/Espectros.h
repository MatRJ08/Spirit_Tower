//
// Created by ashley on 11/7/20.
//

#ifndef SPIRIT_TOWER_ESPECTROS_H
#define SPIRIT_TOWER_ESPECTROS_H


#include <cstdlib>
#include <iostream>
#include "../path/lista.h"
#include "../path/Nodo.h"

using namespace std;

class Espectros{

private:


    //Se generarán aleatoriamente la cantidad de caracteristicas de los espectros
    int veloc_ruta;
    int veloc_pers;
    int radio_vision;
    int id;


private:

    int vel_ruta;
    int vel_persecucion;
    int vision;
    int total;
    int es_i;




public:

    Espectros();

    void Estadisticas();

    void ID(int ID);
    int getEsI() const;
    int get_total() const;


    int get_vel_ruta() const;
    void set_vel_ruta(int velderuta);


    int get_vel_persecucion() const;
    void set_vel_persecucion(int veldepers);


    int get_vision() const;
    void set_vision(int vision_);


};


#endif //SPIRIT_TOWER_ESPECTROS_H
