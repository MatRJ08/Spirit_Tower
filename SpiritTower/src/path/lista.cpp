//
// Created by ashley on 21/10/19.
//

#include "lista.h"
using namespace std;

Lista::Lista(){
    this->front = nullptr;
    this->_size = 0;
}

// Insertar elemento al final de la lista

void Lista::push_back(string dato){
    if(!front){
        this->front = new Nodo(dato);
        this->_size++;
    } else {

        Nodo *aux = front;
        while(aux->get_Next()!= nullptr){
            aux = aux->get_Next();
        }

        aux->set_Next(new Nodo(dato));
        this->_size++;

    }
}
// Insertar elemento al inicio de la lista

void Lista::push_front(string dato){

    Nodo *new_Node = new Nodo(dato);
    if(!front){
        this->front = new_Node;
        this->_size++;
    } else {
        new_Node->set_Next(front);
        this->front = new_Node;
        this->_size++;
    }
}

// Elimina elemento al final de la lista

string Lista::pop_back(){
    if(front){
        Nodo *aux = front,*prev = nullptr;

        while(aux->get_Next()!= nullptr){
            prev = aux;
            aux = aux->get_Next();
        }

        string ans;
        if(prev){
            prev->set_Next(nullptr);
            ans = aux->get_Dato();

            delete(aux);
            this->_size--;

        } else {
            ans = pop_front();
        }
        return ans;
    }
}


// Elimina elemento al inicio de la lista

string Lista::pop_front(){
    if(front){
        Nodo *aux = front;
        front = front->get_Next();
        aux->set_Next(nullptr);

        string ans = aux->get_Dato();

        delete(aux);
        this->_size--;
        return ans;
    }
}

// Inserta un elemento en el indice dado

void Lista::insert(int index,string dato){
    if(index < _size){
        Nodo *prev_Nodo = front,*next_Nodo,*new_Nodo = new Nodo(dato);

        for(int i = 0;i!= index-1;i++){
            prev_Nodo = prev_Nodo->get_Next();
        }

        next_Nodo = prev_Nodo->get_Next();
        prev_Nodo->set_Next(new_Nodo);
        new_Nodo->set_Next(next_Nodo);
        this->_size++;
    }
}

// Elimina un elemento de la lista, dado el dato

string Lista::remove(string dato){

    Nodo *aux = front, *prev = nullptr;
    string ans;
    while(aux && aux->get_Dato() != dato){
        prev = aux;
        aux = aux->get_Next();
    }

    if(aux){
        ans = remove_swapping(prev,aux);
    }
    return ans;
}

// Elimina un elemento de la lista dado su indice

string Lista::remove_at(int index){
    Nodo *aux = front, *prev = nullptr;

    for(int i = 0; i != index;i++){
        prev = aux;
        aux = aux->get_Next();
    }

    return remove_swapping(prev,aux);
}

string Lista::remove_swapping(Nodo *prev,Nodo *aux){
    string ans;
    if(!prev){
        ans = pop_front();
    } else{
        prev->set_Next(aux->get_Next());
        ans = aux->get_Dato();
    }
    this->_size--;
    return ans;
}

/* -------------------------------
 *        SETTERS & GETTERS
 * -------------------------------*/


string Lista::get_index(int index){
    Nodo *aux = front;
    for(int i = 0;i!= index;i++){
        aux = aux->get_Next();
    }
    return aux->get_Dato();
}


string Lista::get(string dato){
    Nodo *aux = front;
    for(int i = 0;i < _size;i++){
        if(aux->get_Dato() == dato)
            break;
        aux = aux->get_Next();
    }

    return aux->get_Dato();
}
int Lista::size(){
    return this->_size;
}

bool Lista::contains(string elem){
    if(front){
        for(Nodo *nodo = front; nodo!= nullptr; nodo = nodo->get_Next()){
            if(nodo->get_Dato() == elem)
                return true;
        }
    }
    return false;
}
void Lista::print_lista(){
    for(Nodo *nodo = front; nodo!= nullptr; nodo = nodo->get_Next()){
        cout<<"[ "<<nodo->get_Dato()<<" ]->";
    }
    cout<<"NULL"<<endl;
}