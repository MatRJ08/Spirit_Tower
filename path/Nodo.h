//
// Created by ashley on 21/10/19.
//

#ifndef SPIRIT_TOWER_NODO_H
#define SPIRIT_TOWER_NODO_H


// Bibliotecas
#include <iostream>
#include <string>


using namespace std;

//! @abstract Nodo de tipo generico para una Lista enlazada

class Nodo
{
    string _dato; //!< Dato T que almacena el nodo
    Nodo* _next; //!< Puntero al sgte nodo de la lista

public:

    //! @brief Constructor
    //! @param [in]dato: Dato que almacena el nodo
    Nodo(string dato);

    //! @brief Asigna un valor al dato que almacena el nodo
    //! @param dato: Dato que se almacenara
    void set_Dato(string dato);

    //! @brief Asigna el sgte nodo
    //! @param next: Nodo que sera colocado como sgte
    void set_Next(Nodo* next);

    //! @brief Retorna el dato almacenado en el nodo
    string get_Dato();

    //! @brief Retorna el sgte nodo de este nodo
    Nodo* get_Next();

    //! @brief Imprime la informacion del nodo en consola
    void print_Nodo();
};

#endif //SPIRIT_TOWER_NODO_H