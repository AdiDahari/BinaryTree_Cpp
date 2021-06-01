#include "BinaryTree.hpp"
using namespace std;
using namespace ariel;

template <typename T>
void BinaryTree<T>::tree_copy(const Node<T> *src_root, Node<T> *dest_root)
{
    if (src_root->left != nullptr)
    {
        dest_root->left = new Node(src_root->left->val);
        tree_copy(dest_root->left, src_root->left);
    }

    if (src_root->right != nullptr)
    {
        dest_root->right = new Node(src_root->right->val);
        tree_copy(dest_root->right, src_root->right);
    }
}

template <typename T>
BinaryTree<T> &BinaryTree<T>::add_root(const T &v)
{
    if (root != nullptr)
    {
        root.val = v;
    }
    else
    {
        root = new Node(v);
    }
}

template <typename T>
BinaryTree<T> &BinaryTree<T>::add_left(const T &s, const T &n)
{
    if (this->root == nullptr)
    {
        throw "Root hasn't been initialized yet\n";
    }
    for (inOrder_itr i = begin(); i != end(); ++i)
    {
        if (*i == s)
        {
            if (i->left != nullptr)
            {
                *(i->left) = n;
            }
            else
            {
                i->left = new Node(n);
            }
            return *this;
        }
    }
    throw "Source value does not exist in tree\n";
}

template <typename T>
BinaryTree<T> &BinaryTree<T>::add_right(const T &s, const T &n)
{
    if (this->root == nullptr)
    {
        throw "Root hasn't been initialized yet\n";
    }
    for (inOrder_itr i = begin(); i != end(); ++i)
    {
        if (*i == s)
        {
            if (i->right != nullptr)
            {
                *(i->right) = n;
            }
            else
            {
                i->right = new Node(n);
            }
            return *this;
        }
    }
    throw "Source value does not exist in tree\n";
}

template <typename T>
void BinaryTree<T>::delete_nodes(Node<T> *root)
{
    if (root != nullptr)
    {
        delete_nodes(root->left);
        delete_nodes(root->right);
        delete root;
    }
}
