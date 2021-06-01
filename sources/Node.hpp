#pragma once
namespace ariel
{
    template <typename T>
    struct Node
    {
        T val;
        Node<T> *left;
        Node<T> *right;
        Node<T> *parent;
        Node(const T &v, Node<T> *l = nullptr, Node<T> *r = nullptr, Node<T> *p = nullptr) : val(v), left(l), right(r), parent(p) {}
        Node() = default;
        ~Node(){};
        bool operator==(const Node &other) const
        {
            return (val == other.val && left == other.left && right == other.right);
        }

        bool operator!=(const Node &other)
        {
            return (val != other.val || left != other.left || right != other.right);
        }
        Node<T> *find_node(Node<T> *root, const T &v)
        {
            if (root == nullptr)
                return nullptr;
            if (root->val == v)
                return root;
            Node<T> *l = find_node(root->left, v);
            if (l != nullptr)
                return l;
            Node<T> *r = find_node(root->right, v);
            if (r != nullptr)
                return r;
            return nullptr;
        }
    };
}