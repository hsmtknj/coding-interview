/**
 * [Question]
 * - 帰りがけ順の走査のアルゴリズムを実装するにはどうすればよいですか？ 
 * 
 * [Solution]
 * - 後行順で走査
 *      - 左部分木・右部分木を探索したあとに表示
 *      - 再帰関数で実装
 * 
 * [Note]
 * - root より先に leaf を見つけたいときに postorder を使うと良い
 */

#include <iostream>
#include <vector>
#include "BinarySearchTree.hpp"

void postorder(node_t *x)
{
    // ベースケース
    if (x == NULL)
        return;

    // 再帰関数
    postorder(x->left);
    postorder(x->right);
    std::cout << x->key << " ";
}

int main()
{
    /* INPUT */
    std::vector<int> v = {30, 88, 17, 1, 25, 20};
    BinarySearchTree tree;
    for (int i = 0; i < v.size(); i++)
        tree.insert_node(v[i]);

    /* SOLVE */
    postorder(tree.root);

    return 0;
}