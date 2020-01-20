#ifndef INCLUDED_SINGLYLINKEDLIST_H
#define INCLUDED_SINGLYLINKEDLIST_H

#include <iostream>

/* 片方向連結リストのノード */
typedef struct singly_node_t
{
    int key;
    singly_node_t *next;
} singly_node_t;

/* 片方向連結リストのクラス */
class SinglyLinkedList
{
    public:
        SinglyLinkedList();
        ~SinglyLinkedList();

    /* Variable */
    public:
        singly_node_t *head, *tail;

    /* Function */
    public:
        void push_front(int key);
        void push_back(int key);
        void delete_head();
        void print();
};

#endif