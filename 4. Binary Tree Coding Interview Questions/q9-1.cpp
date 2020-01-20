/**
 * [Question]
 * - 与えられた二分木の葉のノードの数を数えるにはどうすればよいですか？
 * 
 * [Solution]
 * - postorder で leaf に出会ったらカウントする
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

void postorder(node_t *x, int &cnt)
{
    // ベースケース
    if (x == NULL)
        return;
    
    // 再帰関数
    postorder(x->left, cnt);
    postorder(x->right, cnt);

    // 葉なら表示
    if (is_leaf(x))
        cnt++;
}

int main()
{
    /* INPUT */
    std::vector<int> v = {30, 88, 17, 1, 25, 20};
    BinarySearchTree tree;
    for (int i = 0; i < v.size(); i++)
        tree.insert_node(v[i]);

    /* SOLVE */
    int cnt = 0;
    postorder(tree.root, cnt);
    std::cout << cnt << std::endl;

    return 0;
}