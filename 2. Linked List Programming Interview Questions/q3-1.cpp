/**
 * [Question]
 * - 片方向連結リストを反転するにはどうすればよいですか？
 * 
 * [Solution]
 * - tail からポインタのアドレスをつなぎ変えていく
 *     - 再帰関数で実装
 */

#include <iostream>
#include <vector>
#include "SinglyLinkedList.hpp"

/**
 * @fn
 * 片方向連結リストを反転する
 * e.g. zのポインタを繋ぎかえる際の例
 *      y   ->   z   ->   x   ->
 *    node1 -> node2 -> node3 -> ...
 * => node1 <- node2 -> node3 -> ...
 * @param (sl) 反転する連結リスト
 * @param (y) ポインタを繋ぎかえる際の，つなぎ変え先ノード．元の順で常にzよりひとつ前．
 * @param (z) ポインタを繋ぎかえるノード．zはyとxの間．
 * @param (x) 次にポインタを繋ぎかえるノード．元の順でzの次．
 * @return
 */ 
void reverse_list(SinglyLinkedList &sl, singly_node_t *origin_head, singly_node_t *y, singly_node_t *z, singly_node_t *x)
{
    // デバッグ用表示
    std::cout << "(y, z, x) = (";
    if (y != NULL) std::cout << y->key << ", ";
    else std::cout << "NULL, ";
    if (z != NULL) std::cout << z->key << ", ";
    else std::cout << "NULL, ";
    if (x != NULL) std::cout << x->key;
    else std::cout << "NULL";
    std::cout << ")" << std::endl;

    /* ベースケース: つなぎかえる対象がなくなれば終了 */
    if (z == NULL)
    {
        // コーナーケース: 最後のノードを head にして終わり
        sl.head = y;
        return;
    }

    // コーナーケース: 最初の head を tail に変える
    if (y == origin_head)
    {
        sl.tail = origin_head;
        sl.tail->next = NULL;
    }

    /* ポインタのつなぎ変え */
    z->next = y;
    // ポインタのスライド
    y = z;
    z = x;
    if (x == NULL) x = NULL;
    else x = x->next;
    reverse_list(sl, origin_head, y, z, x);
}

int main()
{
    /* INPUT */
    std::vector<int> v = {30, 88, 1, 25, 17, 20};
    SinglyLinkedList sl;
    for (int i = 0; i < v.size(); i++)
        sl.push_back(v[i]);
    std::cout << "BEFORE: ";
    sl.print();

    /* SOLVE */
    singly_node_t *x, *y, *z;
    y = sl.head;
    z = y->next;
    if (z == NULL) x = NULL;
    else x = z->next;

    singly_node_t *origin_head;
    origin_head = sl.head;

    reverse_list(sl, origin_head, y, z, x);

    // 結果表示
    std::cout << "AFTER: ";
    sl.print();

    return 0;
}
