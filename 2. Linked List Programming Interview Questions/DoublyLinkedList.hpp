#ifndef INCLUDED_DOUBLYLINKEDLIST_H
#define INCLUDED_DOUBLYLINKEDLIST_H

#include <iostream>

/* 双方向連結リストのノード */
typedef struct doubly_node_t
{
    int key;
    doubly_node_t *prev, *next;
} doubly_node_t;

/* 双方向連結リストのクラス */
class DoublyLinkedList
{
    public:
        DoublyLinkedList();
        ~DoublyLinkedList();

    /* Variable */
    public:
        doubly_node_t *head, *tail;

    /* Function */
    public:
        void push_front(int key);
        void push_back(int key);
        void delete_head();
        void delete_tail();
        void print();
};

#endif
