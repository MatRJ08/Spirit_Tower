//
// Created by ashley on 11/7/20.
//

#include "Espectros.h"
using namespace std;

Espectros::Espectros() {


    /*---------------------------------------------------------------------------------------------------
                                    *CARACTERISITCAS DE ESPECTROS*
     ----------------------------------------------------------------------------------------------------*/
    //Se generarán aleatoriamente la cantidad de caracteristicas de los espectros

    veloc_ruta = rand() % 3 + 1;
    veloc_pers = rand() % 3 + 1;
    radio_vision = rand() % 3 + 1;
    id = rand() % 3 + 0;


    //Atributos asociados a los espectros

    vel_ruta = veloc_ruta;
    vel_persecucion = veloc_pers;
    vision = radio_vision;
    total = vel_ruta + vel_persecucion + vision;

}
//Esta función calculará toda la resistencia del ogro según los atributos asociados
void Espectros::ID(int id){
    //ID para diferenciar a los ogros

    switch(id){
        case 0:
            cout << "Gris" << endl;
            break;
        case 1:
            cout << "Rojo" << endl;
            break;
        case 2:
            cout << "Azul" << endl;
            break;

    }
}

/*--------------------------------------------------------------------------------
                       *IMPRIMIR ESTADISITICAS DE ESTUDIANTES*
----------------------------------------------------------------------------------*/

//Función para imprimir todas las caracteristicas de cada uno de los estudiantes
void  Espectros::Estadisticas (){


    cout << "--------------------------- " << "\n";
    cout <<"Velocidad de ruta: "<< get_vel_ruta() << "\n";
    cout <<"Velocidad de persecucion: "<< get_vel_persecucion() << "\n";
    cout <<"Radio de vision: " << get_vision() << "\n";
    cout <<"Total: "<< get_total() << "\n";


}

/*--------------------------------------------------
                *GETTERS AND SETTERS*
----------------------------------------------------*/


int Espectros::get_vel_ruta() const{
    return vel_ruta;
}
void Espectros::set_vel_ruta(int velderuta){
    vel_ruta = velderuta;
}


int Espectros::get_vel_persecucion() const{
    return vel_persecucion;
}
void Espectros::set_vel_persecucion(int veldepers){
    vel_persecucion= veldepers;
}


int Espectros::get_vision() const{
    return vision;
}
void Espectros::set_vision(int vision_){
    vision = vision_;
}


int Espectros::getEsI() const {
    return es_i;
}
int Espectros::get_total() const {
    return total;
}



