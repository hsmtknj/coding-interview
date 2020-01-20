/**
 * [Question]
 * - 与えられた連結リストがcycleを含んでいた場合、どのようにして確認しますか？
 * 
 * [Solution]
 * - 2つのポインタを用意する
 *     - 1つは1つずつ進むポインタ
 *     - もう1つは2つずつ進むポインタ
 * - 一致すれば circle と言える
 * - 一致せずに 2つ進むポインタが最後まで到達すると circle でないと言える
 */

#include <iostream>
#include <vector>
#include "DoublyLinkedList.hpp"

bool is_circle(DoublyLinkedList &dl)
{
    bool flag_circle = false;

    if (dl.head == NULL)
        flag_circle = false;
    else if (dl.head->next == NULL)
        flag_circle = false;
    else
    {
        doubly_node_t *one_step = dl.head;
        doubly_node_t *two_step = dl.head->next;
        while (two_step != NULL)
        {
            // std::cout << "(one_step, two_step) = (" << one_step->key << ", " << two_step->key << ")" << std::endl;

            // 一致したら循環リスト
            if (one_step != NULL && two_step != NULL && one_step == two_step)
            {
                flag_circle = true;
                break;
            }

            // one_step を更新
            if (one_step->next == NULL)
            {
                one_step = NULL;
                flag_circle = false;
                break;
            }
            else
                one_step = one_step->next;

            // two_step を更新
            for (int i = 0; i < 2; i++)
            {
                if (two_step->next == NULL)
                {
                    two_step = NULL;
                    flag_circle = false;
                    break;
                }
                else
                    two_step = two_step->next;
            }
        }
    }
    return flag_circle;
}

int main()
{
    /* INPUT */
    std::vector v = {30, 88, 17, 25, 20};
    DoublyLinkedList dl;
    for (int i = 0; i < v.size(); i++)
        dl.push_back(v[i]);

    // 循環リスト化する
    dl.tail->next = dl.head;

    /* SOLVE */
    bool ans = is_circle(dl);
    if (ans == true)
        std::cout << "CIRCLE" << std::endl;
    else
        std::cout << "NOT CIRCLE" << std::endl;

    return 0;
}