/**
 * [Question]
 * - 1つのパスの中で片方向連結リストの真ん中の要素を探すにはどうすればよいですか？
 * 
 * [Solution]
 * - 2つのポインタで走査する
 *     - 1つずつ進むポインタと一気に2つ進むポインタ
 *     - 2つ進むポインタが最後まで到達したときに1つ進むポインタが真ん中を指す
*/

#include <iostream>
#include <vector>
#include "SinglyLinkedList.hpp"

singly_node_t* get_mid_node(SinglyLinkedList &sl)
{
    // 空の場合
    if (sl.head == NULL) return NULL;
    // ノードが1つの場合
    else if (sl.head->next == NULL) return sl.head;
    // ノードが2つ以上の場合
    else
    {
        // 探索用ノードを宣言
        singly_node_t *one_step, *two_step;
        one_step = sl.head;
        two_step = sl.head->next;

        // 2つ進む探索ノードが最後に到達するまで探索を繰り返す
        while (two_step != NULL)
        {
            one_step = one_step->next;
            for (int i = 0; i < 2; i++)
            {
                if (two_step == NULL) break;
                else two_step = two_step->next;
            }
        }
        return one_step;
    }
}

int main()
{
    /* INPUT */
    std::vector<int> v = {30, 88, 25, 17, 20, 16, 88};
    SinglyLinkedList sl;
    for (int i = 0; i < v.size(); i++) sl.push_back(v[i]);

    /* SOLVE */
    singly_node_t *ans = get_mid_node(sl);
    std::cout << ans->key << std::endl;

    return 0;
}