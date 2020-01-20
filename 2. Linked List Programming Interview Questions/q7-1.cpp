/**
 * [Question]
 * - 片方向連結リストにおいて、最後から3番目のノードを探すにはどうすればよいですか？
 * 
 * [Solution]
 * - ポインタノードを3つ用意する
 *      - x1, x2, x3 で x3 の方が先を指し続けるとする
 *      - x3 の次が NULL になったときの x1 が最後から3番目のノードとなる
 */

#include <iostream>
#include <vector>
#include "SinglyLinkedList.hpp"

singly_node_t* get_third_node_from_last(SinglyLinkedList sl)
{
    singly_node_t *third_node;

    // ノードが3つ存在するか確認する
    singly_node_t *x = sl.head;
    bool third_node_exist = true;
    for (int i = 0; i < 3; i++)
    {
        if (x == NULL)
        {
            third_node_exist = false;
            break;
        }
        else
        {
            x = x->next;
        }
    }

    // ノードが3つないとき
    if (third_node_exist == false)
        third_node = NULL;
    // ノードが3つあるとき
    else
    {
        singly_node_t *x1, *x2, *x3;
        x1 = sl.head;
        x2 = x1->next;
        x3 = x2->next;
        while (x3->next != NULL)
        {
            x1 = x1->next;
            x2 = x2->next;
            x3 = x3->next;
        }
        third_node = x1;
    }
    
    return third_node;
}

int main()
{
    /* INPUT */
    std::vector<int> v = {20, 12, 1, 10};
    SinglyLinkedList sl;
    for (int i = 0; i < v.size(); i++)
        sl.push_back(v[i]);

    /* SOLVE */
    singly_node_t *ans = get_third_node_from_last(sl);
    if (ans == NULL)
        std::cout << "NULL" << std::endl;
    else
        std::cout << ans->key << std::endl;

    return 0;
}