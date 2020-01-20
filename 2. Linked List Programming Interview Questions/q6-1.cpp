/**
 * [Question]
 * - 片方向連結リストの長さを調べるにはどうすればよいですか？
 * 
 * [Solution]
 * - NULLになるまで前から順に走査
 */

#include <iostream>
#include <vector>
#include "SinglyLinkedList.hpp"

int get_list_length(SinglyLinkedList sl)
{
    int list_length;
    singly_node_t *x = sl.head;
    list_length = 0;
    while (x != NULL)
    {
        list_length++;
        x = x->next;
    }
    return list_length;
}

int main()
{
    /* INPUT */
    std::vector<int> v = {30, 88, 27, 20, 25, 1};
    SinglyLinkedList sl;
    for (int i = 0; i < v.size(); i++)
        sl.push_back(v[i]);

    /* SOLVE */
    int list_length = get_list_length(sl);
    std::cout << list_length << std::endl;

    return 0;
}