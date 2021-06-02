#pragma once
namespace ariel
{
    template <typename T>
    struct Node
    {
        T val;
        Node *left;
        Node *right;
        Node *parent;

        Node(const T &v) : val(v), left(nullptr), right(nullptr), parent(nullptr) {}
        Node() : left(nullptr), right(nullptr), parent(nullptr) {}
    };
}