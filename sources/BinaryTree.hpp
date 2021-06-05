#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "iterator.hpp"
#include "Node.hpp"
const int CNT = 5;
namespace ariel
{
    template <typename T>
    class BinaryTree
    {
    private:
        uint max_level = 0;
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

        void tree_copy(Node<T> *dest, const Node<T> *src)
        {
            if (src->left != nullptr)
            {
                dest->left = new Node<T>(src->left->val);
                dest->left->parent = dest;
                dest->left->level = dest->level + 1;
                tree_copy(dest->left, src->left);
            }

            if (src->right != nullptr)
            {
                dest->right = new Node<T>(src->right->val);
                dest->right->parent = dest;
                dest->right->level = dest->level + 1;
                tree_copy(dest->right, src->right);
            }
        }

        void delete_nodes(Node<T> *root)
        {
            if (root != nullptr)
            {
                delete_nodes(root->left);
                delete_nodes(root->right);
            }
            delete root;
        }

    public:
        BinaryTree() : root(nullptr) {}
        BinaryTree(const BinaryTree &other)
        {
            root = new Node<T>(other.root->val);
            max_level = other.max_level;
            tree_copy(root, other.root);
        }
        BinaryTree(BinaryTree &&other) noexcept
        {
            root = other.root;
            max_level = other.max_level;
            other.root = nullptr;
        }

        ~BinaryTree() { delete_nodes(root); };
        BinaryTree &operator=(const BinaryTree<T> &other)
        {
            if (this != &other)
            {
                delete_nodes(root);
                root = new Node<T>(other.root->val);
                max_level = other.max_level;
                tree_copy(root, other.root);
            }
            return *this;
        }
        BinaryTree &operator=(BinaryTree<T> &&other) noexcept
        {
            if (this != &other)
            {

                delete_nodes(root);

                root = other.root;
                max_level = other.max_level;
                other.root = nullptr;
            }
            return *this;
        }
        BinaryTree &add_root(const T v)
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
        }
        BinaryTree &add_left(T s, T n)
        {
            if (root == nullptr)
            {
                throw "Root hasn't been initialized yet\n";
            }
            Node<T> *src = find_node(root, s);
            if (src != nullptr)
            {
                if (src->left != nullptr)
                {
                    src->left->val = n;
                }
                else
                {
                    src->left = new Node<T>(n);
                    src->left->parent = src;
                    src->left->level = src->level + 1;
                    if (src->left->level > max_level)
                    {
                        max_level = src->left->level;
                    }
                }
                return *this;
            }
            throw "Source value does not exist in tree\n";
        }
        BinaryTree &add_right(T s, T n)
        {
            if (root == nullptr)
            {
                throw "Root hasn't been initialized yet\n";
            }
            Node<T> *src = find_node(root, s);
            if (src != nullptr)
            {
                if (src->right != nullptr)
                {
                    src->right->val = n;
                }
                else
                {
                    src->right = new Node<T>(n);
                    src->right->parent = src;
                    src->right->level = src->level + 1;
                    if (src->right->level > max_level)
                    {
                        max_level = src->right->level;
                    }
                }
                return *this;
            }
            throw "Source value does not exist in tree\n";
        }

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

        const Node<T> *get_root() const { return root; }

        friend std::ostream &operator<<(std::ostream &os, const BinaryTree &t)
        {

            return BinaryTree::print(t.get_root(), os);
        }
        /*
        print method idea taken from GeeksForGeeks:
        https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/

        */
        static std::ostream &print(const Node<T> *root, std::ostream &os)
        {
            using namespace std;

            print_util(os, root, 0);

            return os;
        }

        static void print_util(std::ostream &os, const Node<T> *base, int space)
        {
            using namespace std;
            if (base)
            {
                space += CNT;
                print_util(os, base->right, space);
                os << endl;
                for (int i = CNT; i < space; i++)
                {
                    os << " ";
                }
                os << base->val << "\n";
                print_util(os, base->left, space);
            }
        }
    };
}
