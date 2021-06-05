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
        uint level;
        Node(const T &v) : val(v), left(nullptr), right(nullptr), parent(nullptr), level(0) {}
        Node() : left(nullptr), right(nullptr), parent(nullptr) {}
    };
}