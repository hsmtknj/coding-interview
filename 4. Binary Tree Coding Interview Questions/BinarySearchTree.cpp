#include "BinarySearchTree.hpp"

BinarySearchTree::BinarySearchTree()
{
    this->root = NULL;
}

BinarySearchTree::~BinarySearchTree()
{
    // TODO: メモリ解放: delete()
}

void BinarySearchTree::insert_node(int key)
{
    // 挿入するノードの宣言と初期化
    node_t *z = new node_t();
    z->key = key;
    z->parent = NULL;
    z->left = NULL;
    z->right = NULL;

    // ノードの挿入
    if (this->root == NULL)
    {
        this->root = z;
    }
    else
    {
        node_t *x; // 先を探索するノード
        node_t *y; // 探索前に保持しておくノード
        x = root;
        y = NULL;
        while (x != NULL)
        {
            // 探索前にのdーを保持
            y = x;

            // 小さい場合は左に移動
            if (key <= x->key)
                x = x->left;
            // 大きい場合は右に移動
            else
                x = x->right;
        }
        // ノードの登録
        if (key <= y->key)
        {
            y->left = z;
            z->parent = y;
        }
        else
        {
            y->right = z;
            z->parent = y;
        }
    }
}

bool BinarySearchTree::search_node(int key)
{
    bool flag_existance = false;

    if (this->root == NULL)
        flag_existance = false;
    else
    {
        node_t *x = this->root;
        while (x != NULL)
        {
            // 一致するものがあれば終了
            if (key == x->key)
            {
                flag_existance = true;
                break;
            }

            // なければ次のノードを探索
            if (key <= x->key)
                x = x->left;
            else
                x = x->right;
        }
    }
    return flag_existance;
}

bool BinarySearchTree::delete_node(int key)
{
    bool flag_deletion = false;

    if (this->root == NULL)
        flag_deletion = false;
    else
    {
        node_t *x = root;
        while (x != NULL)
        {
            // 消したいノードが見つかれば削除
            if (x->key == key)
            {
                // ノード削除関数
                this->_remove_node(x);
                flag_deletion = true;
                break;
            }

            // なければ次のノード探索
            if (key <= x->key)
                x = x->left;
            else
                x = x->right;
        }
    }

    return flag_deletion;
}

void BinarySearchTree::_remove_node(node_t *z)
{
    node_t *deletion_node = z;
    node_t *y;
    int deletion_key;

    while (deletion_node != NULL)
    {
        // 削除対象ノードの親ノードを保持
        y = deletion_node->parent;
        deletion_key = deletion_node->key;

        // (1) 削除対象ノードがひとつも子を持っていないとき
        // -> そのまま削除
        if (deletion_node->left == NULL && deletion_node->right == NULL)
        {
            // 削除対象がルートだったとき
            if (deletion_node == this->root)
            {
                this->root = NULL;
            }
            // 削除対象がルートでないとき
            else
            {
                if (deletion_key <= y->key)
                    y->left = NULL;
                else
                    y->right = NULL;
            }
            delete deletion_node;
            deletion_node = NULL;
        }
        // (2) 削除対象ノードの子がひとつでそれが左のとき
        else if (deletion_node->left != NULL && deletion_node->right == NULL)
        {
            // 削除対象がルートだったとき
            if (deletion_node == this->root)
            {
                this->root = deletion_node->left;
            }
            // 削除対象がルートでないとき
            else
            {
                // つなぎ変え (削除対象が親の左の子か右の子かで場合分け)
                if (deletion_key <= y->key)
                {
                    y->left = deletion_node->left;
                    deletion_node->left->parent = y;
                }
                else
                {
                    y->right = deletion_node->left;
                    deletion_node->left->parent = y;
                }
            }
            delete deletion_node;
            deletion_node = NULL;
        }
        // (2) 削除対象ノードの子がひとつでそれが右のとき
        else if (deletion_node->left == NULL && deletion_node->right != NULL)
        {
            if (deletion_node == this->root)
            {
                this->root = deletion_node->right;
            }
            else
            {
                // つなぎ変え (削除対象が親の左の子か右の子かで場合分け)
                if (deletion_key <= y->key)
                {
                    y->left = deletion_node->right;
                    deletion_node->right->parent = y;
                }
                else
                {
                    y->right = deletion_node->right;
                    deletion_node->right->parent = y;
                }
            }
            delete deletion_node;
            deletion_node = NULL;
        }
        // (3) 削除対象ノードが左右どちらにも子を持つとき
        else if (deletion_node->left != NULL && deletion_node->right != NULL)
        {
            // 削除対象の左部分木で最も大きいノードを探索する
            node_t *left_max_n, *n;
            n = deletion_node->left;
            while (n != NULL)
            {
                left_max_n = n;
                n = n->right;
            }
            deletion_node->key = left_max_n->key;
            deletion_node = left_max_n;
        }
    }
}

void BinarySearchTree::show_node()
{
    // 昇順で値を表示（中間順）
    if (this->root == NULL)
        std::cout << "NULL" << std::endl;
    else
    {
        this->_show_inorder(this->root);
        std::cout << std::endl;
    }
}

void BinarySearchTree::_show_inorder(node_t *x)
{
    if (x == NULL)
        return;
    this->_show_inorder(x->left);
    std::cout << x->key << " ";
    this->_show_inorder(x->right);
}