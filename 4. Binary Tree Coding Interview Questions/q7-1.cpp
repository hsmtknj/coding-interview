/**
 * [Question]
 * - 再帰を使わずに帰りがけ順で、二分木の走査を行うにはどうすればよいですか？
 * 
 * [Solution]
 * - スタックで実装
 *      - 訪れたノードが leaf かどうか判定する
 *          - leaf であれば表示
 *          - leaf でなければ，左右の子をスタックに追加してからそのノードを leaf にする
 *              - leaf->left = NULL;
 *              - lear->right = NULL;
 * 
 * [Note]
 * - postorder の iterative algorithm は recursive algorithm と比較して難しい
 * - 上記アルゴリズムは構造を破壊するので注意
 * 
 * [Reference]
 * - <https://www.java67.com/2017/05/binary-tree-post-order-traversal-in-java-without-recursion.html>
 */

#include <iostream>
#include <vector>
#include <stack>
#include "BinarySearchTree.hpp"

bool is_leaf(node_t *x)
{
    // ノードが leaf か判定する
    bool flag_leaf;

    if (x == NULL)
        flag_leaf = false;
    else if (x->left == NULL && x->right == NULL)
        flag_leaf = true;
    else
        flag_leaf = false;

    return flag_leaf;
}

int main()
{
    /* INPUT */
    std::vector<int> v = {30, 88, 17, 1, 25, 20};
    BinarySearchTree tree;
    for (int i = 0; i < v.size(); i++)
        tree.insert_node(v[i]);
    
    /* SOLVE */
    std::stack<node_t *> sta;
    node_t *current_node;
    sta.push(tree.root);

    while (!sta.empty())
    {
        // 現在ノードを取り出し
        current_node = sta.top();

        // 葉かどうか判定する
        if (is_leaf(current_node))
        {
            // 葉なら表示して，スタックから削除する
            std::cout << current_node->key << std::endl;
            sta.pop();
        }
        else
        {
            // 葉ではなかった場合子をスタックに追加にして，現在ノードを葉にする
            if (current_node->right != NULL)
            {
                sta.push(current_node->right);
                current_node->right = NULL;
            }            
            if (current_node->left != NULL)
            {
                sta.push(current_node->left);
                current_node->left = NULL;
            }
        }
    }

    return 0;
}