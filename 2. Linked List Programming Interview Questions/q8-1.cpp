/**
 * [Question]
 * - スタックを使用して、2つの連結リストの合計を出すにはどうすればよいですか？
 * 
 * e.g.
 * Input:
 *      First List: 5->6->3  // represents number 563
 *      Second List: 8->4->2 //  represents number 842
 * Output
 *      Resultant list: 1->4->0->5  // represents number 1405
 * 
 * [Solution]
 * - あるひとつのリストにおいて，前から順に取り出す
 *      - 現在の値を10倍して，取り出した値を1の位として足す
 * - 上記を両リスト分実施し，足せば良い
 */

#include <iostream>
#include <vector>
#include "SinglyLinkedList.hpp"

int get_num(SinglyLinkedList sl)
{
    int num = 0;
    if (sl.head != NULL)
    {
        singly_node_t *x = sl.head;
        while (x != NULL)
        {
            // 値を更新
            num *= 10;
            num += x->key;

            // 次のノードに更新
            x = x->next;
        }
    }
    return num;
}

int main()
{
    /* INPUT */
    std::vector<int> v1 = {5, 6, 3};
    std::vector<int> v2 = {8, 4, 2};
    SinglyLinkedList sl1, sl2;
    for (int i = 0; i < v1.size(); i++)
        sl1.push_back(v1[i]);
    for (int i = 0; i < v2.size(); i++)
        sl2.push_back(v2[i]);

    /* SOLVE */
    int num1 = get_num(sl1);
    int num2 = get_num(sl2);
    int ans = num1 + num2;
    std::cout << ans << std::endl;

    return 0;
}
