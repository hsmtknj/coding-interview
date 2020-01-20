/**
 * [Question]
 * - 再帰を使わずに通りがけ順で、与えられた二分木の全てのノードを表示するにはどうすればよいですか？
 * 
 * [Solution]
 * - スタックで実装
 * - ルートを加えて，左端まで進む
 *      - 左端まで進んだら表示しながら右を持っているノードまで進む
 *      - 右を持っているノードに出会ったらスタックに加えて，また左端まで進む
 * 
 * [Reference]
 * - <https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/>
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

    /* SOLVE */
    std::stack<node_t *> sta;
    sta.push(tree.root);
    while (!sta.empty())
    {
        // 現在ノードの位置を取得
        node_t *current_node = sta.top();

        // 現在ノードにまだ左があればスタックに追加
        if (current_node->left != NULL)
        {
            sta.push(current_node->left);
        }
        // 左端に行き着いたら場合
        else if (current_node->left == NULL)
        {
            // 右を持っているノードまで遡る
            while (!sta.empty())
            {
                current_node = sta.top();

                std::cout << current_node->key << " ";
                sta.pop();

                // 右を持っているノードに出会ったら，右ノードを加えてwhileから抜ける
                if (current_node->right != NULL)
                {
                    sta.push(current_node->right);
                    break;
                }
            }

        }
    }

    return 0;
}