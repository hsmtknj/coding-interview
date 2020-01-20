/**
 * [Question]
 * - 与えられた二分木で通りがけ順の走査を行うにはどうすればよいですか？
 * 
 * [Solution]
 * - 中間順で走査
 *      - 左の部分木を探索し終えたら表示
 *      - 再帰関数で実装
 * 
 * [Note]
 * - 二分探索木では中間順は昇順になる
 */

#include <iostream>
#include <vector>
#include "BinarySearchTree.hpp"

void inorder(node_t *x)
{
    // ベースケース
    if (x == NULL)
        return;

    inorder(x->left);
    std::cout << x->key << " ";
    inorder(x->right);
}

int main()
{
    /* INPUT */
    std::vector<int> v = {30, 88, 17, 1, 20, 25};
    BinarySearchTree tree;
    for (int i = 0; i < v.size(); i++)
        tree.insert_node(v[i]);

    /* SOLVE */
    inorder(tree.root);


    return 0;
}