/**
 * [Question]
 * - 二分探索木の全ての葉を表示するにはどうすればよいですか？
 * 
 * [Solution]
 * - postorder で leaf に出会ったら表示する
 *      - 葉の判定は子を持たない場合
 */

#include <iostream>
#include <vector>
#include "BinarySearchTree.hpp"

bool is_leaf(node_t *x)
{
    bool flag_leaf;

    if (x == NULL)
        flag_leaf = false;
    else if (x->left == NULL && x->right == NULL)
        flag_leaf = true;
    else
        flag_leaf = false;

    return flag_leaf;
}

void postorder(node_t *x)
{
    // ベースケース
    if (x == NULL)
        return;
    
    // 再帰関数
    postorder(x->left);
    postorder(x->right);

    // 葉なら表示
    if (is_leaf(x))
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