/**
 * [Question]
 * - 二分探索木を実装するにはどうすればよいですか？
 * 
 * [Solution]
 * <基本構成>
 * - ノードを用意する
 *      - 各ノードは親・左の子・右の子へのポインタを持つ
 *          左の子: 自分より小さいを持つ
 *          右の子: 自分以上の値を持つ
 * - 木の root となるノードを用意し，その親ノードは NULL
 * 
 * <ノードの挿入>
 * - root から leaf まで辿る
 *      - leaf の値を見て左か右かを決定し追加する
 * 
 * <ノードの探索>
 * - root から leaf まで辿る
 *      - leaf まで探索して無ければ終了
 * 
 * <ノードの削除>
 * - 探索と同じ要領で root から leaf まで辿る
 *      - 対象keyを持つノードが見つからなければ終了
 *      - 見つかれば削除
 *          (1) 削除対象ノードが子を持たない
 *              -> そのまま削除
 *          (2) 削除対象ノードが子をひとつ持つ
 *              -> そのまま削除して，子を親の位置に移す
 *          (3) 削除対象ノードが子を2つ持つ
 *              -> 削除して 左部分岐の最大 or 右部分岐の最小ノードを持ってくる
 *                  - 持ってきたノードに対しても (1), (2), (3) いずれかの作業を実施
 * 
 * ※ 上記実装は "BinarySearchTree.cpp" を参照
 */

#include <iostream>
#include <vector>
#include "BinarySearchTree.hpp"

int main()
{
    /* INPUT */
    std::vector<int> v = {30, 88, 12, 25, 17, 1, 77};


    /* SOLVE */
    // 挿入
    BinarySearchTree tree;
    for (int i = 0; i < v.size(); i++)
    {
        tree.insert_node(v[i]);
    }
    std::cout << "=== INSERT ===" << std::endl;
    tree.show_node();
    std::cout << std::endl;

    // 探索
    std::cout << "=== SEARCH ===" << std::endl;
    if (tree.search_node(88))
        std::cout << "88: True" << std::endl;
    else
        std::cout << "88: False" << std::endl;
    if (tree.search_node(1000))
        std::cout << "1000: True" << std::endl;
    else
        std::cout << "1000: False" << std::endl;    
    std::cout << std::endl;

    // 削除
    tree.delete_node(30);
    tree.show_node();

    tree.delete_node(17);
    tree.show_node();

    tree.delete_node(12);
    tree.show_node();

    tree.delete_node(25);
    tree.show_node();

    tree.delete_node(1);
    tree.show_node();

    tree.delete_node(77);
    tree.show_node();

    tree.delete_node(88);
    tree.show_node();

    std::cout << "END" << std::endl;    
    return 0;
}