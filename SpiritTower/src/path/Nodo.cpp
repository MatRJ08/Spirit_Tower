//
// Created by ashley on 21/10/19.
//

#include "Nodo.h"



Nodo::Nodo(string dato)
{
    this->_dato = dato;
    this->_next = nullptr;
}
void Nodo::set_Dato(string dato){
    this->_dato = dato;
}
void Nodo::set_Next(Nodo* next){
    this->_next = next;
}
string Nodo::get_Dato(){
    return this->_dato;
}

Nodo* Nodo::get_Next(){
    return this->_next;
}
void Nodo::print_Nodo(){
    cout<<"{ Dato: "<< this->_dato<<"}"<<endl;
}