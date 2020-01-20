/**
 * [Question]
 * - ソートされていない連結リストにおいて、重複したノードを排除するにはどうすればよいですか？
 * 
 * [Solution]
 * - 連結リストを前から順に走査する
 *      - 連想配列を用意し，既出かどうかを確認する
 *        - 既出の場合は削除してポインタをつなぎかえる
 *        - 既出でない場合，そのまま走査を続ける
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include "SinglyLinkedList.hpp"

void delete_duplication(SinglyLinkedList &sl)
{
    // ノードが空のときや1つのときは何もしないで終了
    if (sl.head == NULL)
        return;
    if (sl.head->next == NULL)
        return;
    
    // ノードが2つ以上のときに重複削除の処理を実施
    singly_node_t *y, *z, *x;
    y = sl.head;
    z = y->next;
    x = z->next;

    std::unordered_map<std::string, int> map;
    std::string first = std::to_string(sl.head->key);
    map[first] = 1;

    while (z != NULL)
    {
        std::string tgt_s = std::to_string(z->key);

        // 対象となる要素が初めて出てきた場合は連想配列に登録
        if (map.count(tgt_s) == 0)
        {
            map[tgt_s] = 1;

            // 対象を次に移す
            y = z;
            z = x;
            if (x == NULL) x = NULL;
            else x = x->next;

            continue;
        }
        // 対象となる要素が既出の場合は削除してポインタのつなぎ変えを実施
        else
        {
            map[tgt_s]++;

            // ポインタのつなぎ変え
            y->next = x;
            
            // メモリの解放
            singly_node_t *deletion_node = z;
            delete deletion_node;

            // 対象を次に移す（yはそのまま）
            z = x;
            if (x == NULL) x = NULL;
            else x = x->next;
        }
    }
}

int main()
{
    /* INPUT */
    std::vector<int> v = {30, 210, 88, 1, 4, 30, 4, 55, 210};
    SinglyLinkedList sl;
    for (int i = 0; i < v.size(); i++)
        sl.push_back(v[i]);

    /* SOLVE */
    delete_duplication(sl);

    sl.print();

    return 0;
}