/**
 * [Question]
 * - 再帰を使わずに片方向連結リストを反転するにはどうすればよいですか？　
 * 
 * [Solution]
 * - q3-1 を while() で実装
 */

#include <iostream>
#include <vector>
#include "SinglyLinkedList.hpp"

int main()
{
    /* INPUT */
    std::vector<int> v = {30, 88, 17, 1, 20, 25};
    SinglyLinkedList sl;
    for (int i = 0; i < v.size(); i++)
        sl.push_back(v[i]);

    std::cout << "BEFORE: ";
    sl.print();


    /* SOLVE */
    // つなぎ変え用ポインタの初期化
    singly_node_t *y, *z, *x;
    y = sl.head;
    z = y->next;
    if (z == NULL) x = NULL;
    else x = z->next;

    // もともと head だったものを保持
    singly_node_t *origin_head = sl.head;

    // 先頭から順にポインタをつなぎ変えていく
    while (z != NULL)
    {
        // コーナーケース: もともと head だったものを tail に更新
        if (y == origin_head)
        {
            sl.tail = origin_head;
            sl.tail->next = NULL;
        }

        // ポインタのつなぎ変え
        z->next = y;

        // つなぎ変えポインタをひとつ進める
        y = z;
        z = x;
        if (x == NULL) x = NULL;
        else x = x->next;

        // コーナーケース: つなぎ変えが終わったら最後を head に更新
        if (z == NULL)
            sl.head = y;

    }

    std::cout << "AFTER: ";
    sl.print();

    return 0;
}