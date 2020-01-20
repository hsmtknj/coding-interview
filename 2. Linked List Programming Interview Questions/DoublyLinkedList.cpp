#include "DoublyLinkedList.hpp"

DoublyLinkedList::DoublyLinkedList()
{
    this->head = NULL;
    this->tail = NULL;
}

DoublyLinkedList::~DoublyLinkedList()
{
    // TODO: メモリ解放: delete()
}

void DoublyLinkedList::push_front(int key)
{
    doubly_node_t *z = new doubly_node_t();
    z->key = key;
    z->prev = NULL;
    z->next = NULL;

    if (this->head == NULL)
    {
        this->head = z;
        this->tail = z;
    }
    else
    {
        z->next = this->head;
        this->head->prev = z;
        this->head = z;
    }
    
}

void DoublyLinkedList::push_back(int key)
{
    doubly_node_t *z = new doubly_node_t();
    z->key = key;
    z->prev = NULL;
    z->next = NULL;

    if (this->head == NULL)
    {
        this->head = z;
        this->tail = z;
    }
    else
    {
        z->prev = this->tail;
        this->tail->next = z;
        this->tail = z;
    }
}

void DoublyLinkedList::delete_head()
{
    if (this->head == NULL)
        return;
    else
    {
        doubly_node_t *deletion_node = this->head;
        if (this->head == this->tail)
        {
            this->head = NULL;
            this->tail = NULL;
            delete deletion_node;
        }
        else
        {
            this->head = this->head->next;
            this->head->prev = NULL;
            delete deletion_node;
        }
    }
}

void DoublyLinkedList::delete_tail()
{
    if (this->head == NULL)
        return;
    else
    {
        doubly_node_t *deletion_node = this->tail;
        if (this->head == this->tail)
        {
            this->head = NULL;
            this->tail = NULL;
            delete deletion_node;          
        }
        else
        {
            this->tail = this->tail->prev;
            this->tail->next = NULL;
            delete deletion_node;
        }
    }
}

void DoublyLinkedList::print()
{
    if (this->head == NULL)
    {
        std::cout << "NULL" << std::endl;
    }
    else
    {
        doubly_node_t *x = this->head;
        doubly_node_t *first_node = this->head;
        while (x != NULL)
        {
            std::cout << x->key << "<->";
            x = x->next;
            
            // 循環リスト用終了条件
            if (x == first_node)
            {
                std::cout << "circle";
                break;
            }
        }
        std::cout << std::endl;
    }

}
