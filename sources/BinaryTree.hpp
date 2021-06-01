#pragma once
#include <iostream>
#include "iterator.hpp"
#include "Node.hpp"

namespace ariel
{
    template <typename T>
    class BinaryTree
    {
    private:
        Node<T> *root;
        void tree_copy(const Node<T> *src_root, Node<T> *dest_root);
        void delete_nodes(Node<T> *root);

    public:
        BinaryTree<T>() : root(nullptr){};
        BinaryTree<T>(const BinaryTree<T> &other)
        {
            if (other.root != nullptr)
            {
                root = new Node<T>(other.root->val);
                tree_copy(*root, *other.root);
            }
        }

        ~BinaryTree<T>() { delete_nodes(root); };
        BinaryTree<T> &add_root(const T &v);
        BinaryTree<T> &add_left(const T &s, const T &n);
        BinaryTree<T> &add_right(const T &s, const T &n);
        friend std::ostream &operator<<(std::ostream &os, const BinaryTree &t)
        {
            return os;
        };

        inOrder_itr<T> begin()
        {
            return begin_inorder();
        }

        inOrder_itr<T> end()
        {
            return end_inorder();
        }

        preOrder_itr<T> begin_preorder()
        {
            return preOrder_itr{root};
        }

        preOrder_itr<T> end_preorder()
        {
            return preOrder_itr{};
        }

        inOrder_itr<T> begin_inorder()
        {
            return inOrder_itr{root};
        }

        inOrder_itr<T> end_inorder()
        {
            return inOrder_itr{};
        }

        postOrder_itr<T> begin_postorder()
        {
            return postOrder_itr{root};
        }

        postOrder_itr<T> end_postorder()
        {
            return postOrder_itr{};
        }
    };
}
