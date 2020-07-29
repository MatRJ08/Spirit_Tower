//
// Created by ashley on 21/10/19.
//

#ifndef SPIRIT_TOWER_LISTA_H
#define SPIRIT_TOWER_LISTA_H


//Bibliotecas
#include <fstream>
#include <string>
#include <cstdlib>
#include <iostream>
#include "Nodo.h"

using namespace std;

//!
//! \brief The Lista class
//!
class Lista
{
    Nodo *front; //!< Primer nodo de la lista
    int _size; //!< Tamaño de la lista

    //! \brief remove_swapping
    //! \param prev
    //! \param aux
    //!
    string remove_swapping(Nodo *prev, Nodo *aux);

public:

    //!
    //! \brief Lista
    //!
    Lista();

    //!
    //! \brief push_back
    //! \param dato
    //!
    void push_back(string dato);

    //!
    //! \brief push_front
    //! \param dato
    //!
    void push_front(string dato);

    //!
    //! \brief pop_back
    //! \return
    //!
    string pop_back();

    //!
    //! \brief pop_front
    //! \return
    //!
    string pop_front();

    //!
    //! \brief get
    //! \param dato
    //! \return
    //!
    string get(string dato);

    //!
    //! \brief get_index
    //! \param index
    //! \return
    //!
    string get_index(int index);

    //!
    //! \brief insert
    //! \param index
    //! \param dato
    //!
    void insert(int index, string dato);

    //!
    //! \brief remove
    //! \param dato
    //! \return
    //!
    string remove(string dato);

    //!
    //! \brief remove_at
    //! \param index
    //! \return
    //!
    string remove_at(int index);

    //!
    //! \brief size
    //! \return
    //!
    int size();

    //!
    //! \brief print_lista
    //!
    void print_lista();

    //!
    //! \brief empty
    //! \return
    //!
    bool empty(){
        return !front;
    }

    //!
    //! \brief contains
    //! \param elem
    //! \return
    //!
    bool contains(string elem);
};

#endif //SPIRIT_TOWER_LISTA_H