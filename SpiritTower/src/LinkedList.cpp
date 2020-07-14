#include "LinkedList.h"
#include<iostream>


template <class T>
LinkedList<T>::LinkedList(){
    size = 0;
    head = nullptr;
}

template <class T>
ListNode<T>* LinkedList<T>::getHead() {
    return head;
}

template <class T>
ListNode<T>* LinkedList<T>::getNodeInIndex(int index){
    if(isEmpty()){
        return NULL;


    } else{
        ListNode<T>* current = head;
        for(int i = 0; i < index; i++){
            current = current->next;
        }

        return current;
    }


}

template <class T>
void LinkedList<T>::addNodeLast(T data) {
    ListNode<T>* newNode = new ListNode<T>();
    newNode->nodeData = data;
    newNode->next = nullptr;

    if (head == nullptr){
        head = newNode;
        size++;
    } else{
        ListNode<T>* current = head;
        while (current->next != nullptr){
            current = current->next;
        }

        current->next = newNode;
        size++;
    }
}

template <class T>
int LinkedList<T>::getSize() {
    return size;
}

template <class T>
bool LinkedList<T>::isEmpty() {
    return size == 0;
}

/*
void listTest(){
    LinkedList<int>* list = new LinkedList<int>();

    list->addNodeLast(1);
    list->addNodeLast(2);
    list->addNodeLast(3);
    list->addNodeLast(4);
    list->addNodeLast(5);
    list->addNodeLast(6);
    list->addNodeLast(7);

    std::cout << list->getHead()->nodeData << std::endl;

    for(int i = 0; i < list->getSize(); i++){
        std::cout << list->getNodeInIndex(i)->nodeData << std::endl;
    }
}*/