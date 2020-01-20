/**
 * [Question]
 * - 与えられた二分木で行きがけ順の走査を行うにはどうすればよいですか？
 * 
 * [Solution]
 * - 先行順で走査
 *      - そのノードに到達したときに処理 (表示) を行う
 *      - その後，左部分木・右部分木を探索
 * 
 * [Note]
 * - leaf より先に root を見つけたいときに preorder を使うと良い
 */

#include <iostream>
#include <vector>
#include "BinarySearchTree.hpp"

void preorder(node_t *x)
{
    // ベースケース
    if (x == NULL)
        return;

    // 値表示
    std::cout << x->key << " ";

    // 再帰関数
    preorder(x->left);
    preorder(x->right);
}

int main()
{
    /* INPUT */
    std::vector<int> v = {30, 88, 17, 25, 20};
    BinarySearchTree tree;
    for (int i = 0; i < v.size(); i++)
        tree.insert_node(v[i]);

    /* SOLVE */
    preorder(tree.root);

    return 0;
}
