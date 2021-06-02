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
        Node<T> *find_node(Node<T> *curr, T v)
        {
            if (curr->val == v)
            {
                return curr;
            }
            Node<T> *search = nullptr;
            if (search == nullptr && curr->left != nullptr)
            {
                search = find_node(curr->left, v);
            }
            if (search == nullptr && curr->right != nullptr)
            {
                search = find_node(curr->right, v);
            }
            return search;
        }

        void tree_copy(const Node<T> &src_root, Node<T> &dest_root)
        {
            if (src_root.left != nullptr)
            {
                dest_root.left = new Node(src_root.left->val);
                tree_copy(*dest_root.left, *src_root.left);
            }

            if (src_root.right != nullptr)
            {
                dest_root.right = new Node(src_root.right->val);
                tree_copy(*dest_root.right, *src_root.right);
            }
        };
        void delete_nodes(Node<T> *root)
        {
            if (root != nullptr)
            {
                delete_nodes(root->left);
                delete_nodes(root->right);
                delete root;
            }
        };

    public:
        BinaryTree() : root(nullptr){};
        BinaryTree(const BinaryTree &other)
        {
            if (other.root != nullptr)
            {
                root = new Node<T>(other.root->val);
                tree_copy(*root, *other.root);
                delete_nodes(other.root);
            }
        }
        BinaryTree(BinaryTree &&other) noexcept
        {
            root = other.root;
            other.root = nullptr;
        }

        ~BinaryTree() { delete_nodes(root); };
        BinaryTree &operator=(const BinaryTree &other)
        {
            if (this == &other)
            {
                return *this;
            }
            if (root != nullptr)
            {
                delete_nodes(root);
            }
            root = new Node(other.root->val);
            tree_copy(*other.root, *root);
            return *this;
        }
        BinaryTree &operator=(BinaryTree &&other) noexcept
        {
            if (root != nullptr)
            {
                delete_nodes(root);
            }
            root = other.root;
            other.root = nullptr;
        }
        BinaryTree &add_root(const T &v)
        {
            if (root != nullptr)
            {
                root->val = v;
            }
            else
            {
                root = new Node<T>(v);
            }
            return *this;
        };
        BinaryTree &add_left(T s, T n)
        {
            if (this->root == nullptr)
            {
                throw "Root hasn't been initialized yet\n";
            }
            Node<T> *src = find_node(root, s);
            if (src != nullptr)
            {
                src->left = new Node<T>(n);
                src->left->parent = src;
                return *this;
            }
            throw "Source value does not exist in tree\n";
        };
        BinaryTree &add_right(T s, T n)
        {
            if (this->root == nullptr)
            {
                throw "Root hasn't been initialized yet\n";
            }
            Node<T> *src = find_node(root, s);
            if (src != nullptr)
            {
                src->right = new Node<T>(n);
                src->right->parent = src;

                return *this;
            }
            throw "Source value does not exist in tree\n";
        };
        friend std::ostream &operator<<(std::ostream &os, const BinaryTree &t)
        {
            return os;
        };

        auto begin()
        {
            return begin_inorder();
        }

        auto end()
        {
            return end_inorder();
        }

        auto begin_preorder()
        {
            return preOrder_itr<T>{root};
        }

        auto end_preorder()
        {
            return preOrder_itr<T>{};
        }

        auto begin_inorder()
        {
            return inOrder_itr<T>{root};
        }

        auto end_inorder()
        {
            return inOrder_itr<T>{};
        }

        auto begin_postorder()
        {
            return postOrder_itr<T>{root};
        }

        auto end_postorder()
        {
            return postOrder_itr<T>{};
        }
    };
}
