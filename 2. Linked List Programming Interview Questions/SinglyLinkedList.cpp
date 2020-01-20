#include "SinglyLinkedList.hpp"

SinglyLinkedList::SinglyLinkedList()
{
    this->head = NULL;
    this->tail = NULL;
}

SinglyLinkedList::~SinglyLinkedList()
{
    // TODO: メモリ解放: delete()
}

void SinglyLinkedList::push_front(int key)
{
    singly_node_t *z = new singly_node_t();
    z->key = key;
    z->next = NULL;

    if (this->head == NULL)
    {
        this->head = z;
        this->tail = z;
    }
    else
    {
        z->next = this->head;
        this->head = z;
    }
}

void SinglyLinkedList::push_back(int key)
{
    singly_node_t *z = new singly_node_t();
    z->key = key;
    z->next = NULL;

    if (this->head == NULL)
    {
        this->head = z;
        this->tail = z;
    }
    else
    {
        this->tail->next = z;
        this->tail = z;
    }
}

void SinglyLinkedList::delete_head()
{
    if (this->head == NULL)
        return;
    else
    {
        singly_node_t *deletion_node = this->head;
        if (this->head == this->tail)
        {
            this->head = NULL;
            this->tail = NULL;
            delete deletion_node;
        }
        else
        {
            this->head = this->head->next;
            delete deletion_node;
        }
    }
}

void SinglyLinkedList::print()
{
    if (this->head == NULL)
    {
        std::cout << "NULL" << std::endl;
    }
    else
    {
        singly_node_t *x = this->head;
        singly_node_t *first_node = this->head;
        while (x != NULL)
        {
            std::cout << x->key << "->";
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
