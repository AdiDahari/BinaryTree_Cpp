#pragma once
#include "Node.hpp"
#include <iostream>
#include <string>
// #include <stack>
// using namespace std;
namespace ariel
{

    template <typename T>
    class preOrder_itr
    {
        Node<T> *ptr;

    public:
        preOrder_itr(Node<T> *root = nullptr) : ptr(root){};

        T &operator*() const
        {
            return ptr->val;
        }

        T *operator->() const
        {
            return &(ptr->val);
        }

        preOrder_itr &operator++()
        {
            if (ptr->left != nullptr)
            {
                ptr = ptr->left;
            }
            else if (ptr->right != nullptr)
            {
                ptr = ptr->right;
            }
            // create the following tree
            //                    1
            //              2          3
            //         4        5
            //               10   11
            //             20       23
            //           50  60
            else
            {
                while (ptr->parent != nullptr && ptr->parent->right == nullptr)
                {
                    ptr = ptr->parent;
                    while (ptr->parent != nullptr && (ptr == ptr->parent->right || ptr->parent->right == nullptr))
                    {
                        ptr = ptr->parent;
                    }
                }
                while (ptr->parent != nullptr && ptr->parent->right == ptr)
                {
                    ptr = ptr->parent;
                    while (ptr->parent != nullptr && ptr->parent->right == nullptr)
                    {
                        ptr = ptr->parent;
                    }
                }
                if (ptr->parent == nullptr)
                {
                    ptr = nullptr;
                }
                else
                {
                    ptr = ptr->parent->right;
                }
            }

            return *this;
        }

        preOrder_itr operator++(int)
        {
            preOrder_itr i = *this;
            ++*this;
            return i;
        }

        bool operator==(const preOrder_itr &other) const
        {
            return ptr == other.ptr;
        }

        bool operator!=(const preOrder_itr &other) const
        {
            return ptr != other.ptr;
        }
    };

    template <typename T>
    class postOrder_itr
    {
        Node<T> *ptr;

    public:
        postOrder_itr(Node<T> *root = nullptr) : ptr(root)
        {
            if (root != nullptr)
            {
                while (ptr->left != nullptr || ptr->right != nullptr)
                {
                    if (ptr->left != nullptr)
                    {
                        ptr = ptr->left;
                    }
                    else
                    {
                        ptr = ptr->right;
                    }
                }
            }
        }
        T &operator*() const
        {
            return ptr->val;
        }

        T *operator->() const
        {
            return &(ptr->val);
        }

        postOrder_itr &operator++()
        {
            if (ptr != nullptr)
            {
                Node<T> *tmp = ptr;
                if (ptr->parent != nullptr)
                {
                    ptr = ptr->parent;
                    if (ptr->right != nullptr && ptr->right != tmp)
                    {
                        ptr = ptr->right;
                        while (ptr->left != nullptr || ptr->right != nullptr)
                        {
                            if (ptr->left != nullptr)
                            {
                                ptr = ptr->left;
                            }
                            else
                            {
                                ptr = ptr->right;
                            }
                        }
                    }
                }
                else
                {
                    ptr = ptr->parent;
                }
            }
            return *this;
        }
        postOrder_itr operator++(int)
        {
            postOrder_itr i = *this;
            ++*this;
            return i;
        }

        bool operator==(const postOrder_itr &other) const
        {
            return ptr == other.ptr;
        }
        bool operator!=(const postOrder_itr &other) const
        {
            return ptr != other.ptr;
        }
    };

    template <typename T>
    class inOrder_itr
    {
        Node<T> *ptr;

    public:
        inOrder_itr(Node<T> *root = nullptr) : ptr(root)
        {
            if (root != nullptr)
            {
                while (ptr->left != nullptr)
                {
                    ptr = ptr->left;
                }
            }
        }

        T &operator*() const
        {
            return ptr->val;
        }

        T *operator->() const
        {
            return &(ptr->val);
        }
        uint get_level()
        {
            return ptr->level;
        }

        inOrder_itr &operator++()
        {

            if (ptr != nullptr)
            {

                if (ptr->right != nullptr)
                {

                    ptr = ptr->right;
                    while (ptr->left != nullptr)
                    {
                        ptr = ptr->left;
                    }
                }
                else
                {
                    while (ptr->parent != nullptr && ptr == ptr->parent->right)
                    {
                        ptr = ptr->parent;
                    }
                    ptr = ptr->parent;
                }
            }
            return *this;
        }
        inOrder_itr operator++(int)
        {
            const inOrder_itr i = *this;
            ++*this;
            return i;
        }

        bool operator!=(const inOrder_itr &other) const
        {
            return ptr != other.ptr;
        }

        bool operator==(const inOrder_itr &other) const
        {
            return ptr == other.ptr;
        }
    };
}