//
// Created by ashley on 11/7/20.
//

#include "Evolucionador.h"


#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <iostream>



using namespace std;

Evolucionador::Evolucionador() {

}


//Se reciben los espectros creados en la primera generación para las siguientes generaciones
//Esta será la función de fitness para calcular a los mejores de cada generación
//Esto lo toma contando la resistencia total de cada uno de los estudiantes
int* Evolucionador::Obtener_Resistencia(Espectros  arreglo[]){

    int res[3];
    for(int i=0; i < 3; i++){
        res[i] = (arreglo[i].get_total());
    }
    Seleccion(res, arreglo);

    return res;
}

//Se escogen los dos mejores estudiantes de la primera generación que fungiran como padres de la siguiente
Espectros* Evolucionador::Seleccion(int* chequear_resistencia, Espectros* espectros){
    int aux_mayor = chequear_resistencia[0];
    int aux_seg_mayor = chequear_resistencia[0];

    for (int s = 0; s < 3; s++){
        if(aux_mayor <= chequear_resistencia[s])
        {
            aux_seg_mayor=aux_mayor;
            aux_mayor=chequear_resistencia[s];
        }
    }

    //Obtengo los dos mejores estudiantes de la generación
    int index_1 = Index(chequear_resistencia, aux_mayor);
    int index_2 = Index(chequear_resistencia, aux_seg_mayor);

    //Envio los dos estudiantes con mejor fitness/resistencia
    Cruce(espectros[index_1], espectros[index_2]);


}


Espectros*  Evolucionador::Cruce(Espectros padre1, Espectros padre2){

    //Un nuevo objeto estudiante para la creación de uno nuevo



    //Gen que será mutado en el proceso
    int mutante = Mutacion();


    //De aquí se obtiene la nueva generación
    //Los nuevos hijos heredan genes de ambos padres, según una determinada configuración de genes
    //Esto se hace para los 10 hijos

    for (int hijo = 0; hijo<3; hijo++) {

        switch (hijo) {
            //Hijo 1
            case 0: {
                nuevoes[hijo].set_vel_ruta(padre1.get_vel_ruta());
                nuevoes[hijo].set_vel_persecucion(padre2.get_vel_persecucion());
                nuevoes[hijo].set_vision(padre1.get_vision());
                if (mutante == 0) {

                    cout << ("Habrá Mutación")<< endl;
                    nuevoes[hijo].set_vel_ruta(6);
                    nuevoes[hijo].set_vision(7);
                }
                nuevoes[hijo].Estadisticas();
                break;
            }

                //Hijo 2
            case 1: {
                nuevoes[hijo].set_vel_ruta(padre2.get_vel_ruta());
                nuevoes[hijo].set_vel_persecucion(padre1.get_vel_persecucion());
                nuevoes[hijo].set_vision(padre2.get_vision());
                if (mutante == 1) {

                    cout << ("Habrá Mutación")<< endl;
                    nuevoes[hijo].set_vel_ruta(6);
                    nuevoes[hijo].set_vision(7);
                }
                nuevoes[hijo].Estadisticas();
                break;
            }

                //Hijo 3
            case 2: {
                nuevoes[hijo].set_vel_ruta(padre1.get_vel_ruta());
                nuevoes[hijo].set_vel_persecucion(padre2.get_vel_persecucion());
                nuevoes[hijo].set_vision(padre2.get_vision());
                if (mutante == 2) {

                    cout << ("Habrá Mutación") << endl;
                    nuevoes[hijo].set_vel_ruta(6);
                    nuevoes[hijo].set_vision(7);
                }
                nuevoes[hijo].Estadisticas();
                break;
            }
        }
    }

    return nuevoes;


}


Espectros* Evolucionador::get_nueva_gen(){
    return nuevoes;
}



//Función para encargarse de escoger el gen (caracterisitca) a mutar y enviarla a la función de creación
int Evolucionador::Mutacion(){
    //Se selecciona uno de los hijos a los cuales se les hará mutación
    int gen_mutado = rand() % 3 ;
    return  gen_mutado;
}

//Función para obtener el elemento de un array por medio de un índice
int Evolucionador::Index(int* arr, int t){

    if (arr == NULL) {
        return -1;
    }

    int len = sizeof(arr);

    int i = 0;

    while (i < len) {
        if (arr[i] == t) {
            return i;
        }
        else {
            i = i + 1;
        }
    }
    return -1;
}



