#ifndef INCLUDED_BINARYSEARCHTREE_H
#define INCLUDED_BINARYSEARCHTREE_H

#include <iostream>

/* ノードの構造体 */
typedef struct node_t
{
    int key;
    node_t *parent, *left, *right;
} node_t;


/* 二分木のクラス */
class BinarySearchTree
{
    public:
        BinarySearchTree();
        ~BinarySearchTree();

    /* public: 変数 */
    public:
        node_t *root;

    /* public: 関数 */
    public:
        void insert_node(int key);  // ノード挿入
        bool search_node(int key);  // ノード探索
        bool delete_node(int key);  // ノード削除
        void show_node();           // ノード表示

    /* private: 変数 */
    private:

    /* private: 関数 */
    private:
        void _remove_node(node_t *z);
        void _show_inorder(node_t *z);


};

#endif