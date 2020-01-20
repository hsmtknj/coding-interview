/**
 * [Question]
 * - 再帰を使わずに行きがけ順で、与えられた二分木の走査を行うにはどうすればよいですか？
 * 
 * [Solution]
 * - スタックを使って実装
 *      - 深さ優先探索は先行順になる
 *      - while() でスタックが空になるまで続ける
 */

#include <iostream>
#include <vector>
#include <stack>
#include "BinarySearchTree.hpp"

int main()
{
    /* INPUT */
    std::vector<int> v = {30, 88, 17, 1, 25, 20};
    BinarySearchTree tree;
    for (int i = 0; i < v.size(); i++)
        tree.insert_node(v[i]);
    tree.show_node();

    /* SOLVE */
    std::stack<node_t*> sta;
    sta.push(tree.root);

    while (!sta.empty())
    {
        // スタックから取り出して表示
        node_t *n = sta.top();
        sta.pop();
        std::cout << n->key << " ";

        // 子がいたらスタックに加える
        if (n->right != NULL)
            sta.push(n->right);
        if (n->left != NULL)
            sta.push(n->left);
    }


    return 0;
}