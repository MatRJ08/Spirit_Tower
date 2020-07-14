#pragma once
#ifndef SPIRITTOWER_LINKEDLIST_H
#define SPIRITTOWER_LINKEDLIST_H
#include<stdlib.h>

template <class T>
struct ListNode{
    T nodeData;
    ListNode* next;
};

template <class T>
class LinkedList{
public:
    LinkedList<T>();
    ListNode<T>* getHead();
    int getSize();
    bool isEmpty();
    ListNode<T>* getNodeInIndex(int index);
    void addNodeLast(T data);
private:
    ListNode<T>* head;
    int size;
};

#endif //SPIRITTOWER_LINKEDLIST_H
