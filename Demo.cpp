#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "sources/BinaryTree.hpp"
using namespace ariel;
using namespace std;
ostream &print_counting_tree(ostream &os, int lim)
{
    BinaryTree<int> int_tree;
    int_tree.add_root(1);
    for (int i = 1; i < (lim + 1) / 2; ++i)
    {
        int_tree.add_right(i, 2 * i).add_left(i, 2 * i + 1);
    }
    if (lim % 2 == 0)
    {
        int_tree.add_right(lim / 2, lim);
    }
    os << int_tree << endl
       << endl;
    os << "Preorder Traversal of the tree is:" << endl;
    for (auto i = int_tree.begin_preorder(); i != int_tree.end_preorder(); ++i)
    {
        os << *i << " ";
    }
    os << endl;
    os << "Inorder Traversal of the tree is:" << endl;
    for (auto i = int_tree.begin(); i != int_tree.end(); ++i)
    {
        os << *i << " ";
    }
    os << endl;
    os << "Postorder Traversal of the tree is:" << endl;
    for (auto i = int_tree.begin_postorder(); i != int_tree.end_postorder(); ++i)
    {
        os << *i << " ";
    }
    os << endl;

    return os;
}

ostream &print_string_tree(ostream &os, string &s)
{
    string word;
    vector<string> v;
    istringstream ss(s);
    while (ss >> word)
    {
        v.push_back(word);
    }
    BinaryTree<string> string_tree;
    string_tree.add_root(v[0]);
    uint count = 0;
    for (uint i = 1; i < v.size() - 1; i += 2, ++count)
    {
        string_tree.add_right(v[count], v[i]).add_left(v[count], v[i + 1]);
    }
    if (v.size() % 2 == 0)
    {
        string_tree.add_right(v[count], v[v.size() - 1]);
    }
    os << string_tree << endl
       << endl;
    os << "Preorder Traversal of the tree is:" << endl;
    for (auto i = string_tree.begin_preorder(); i != string_tree.end_preorder(); ++i)
    {
        os << *i << " ";
    }
    os << endl;
    os << "Inorder Traversal of the tree is:" << endl;
    for (auto i = string_tree.begin(); i != string_tree.end(); ++i)
    {
        os << *i << " ";
    }
    os << endl;
    os << "Postorder Traversal of the tree is:" << endl;
    for (auto i = string_tree.begin_postorder(); i != string_tree.end_postorder(); ++i)
    {
        os << *i << " ";
    }
    os << endl;
    return os;
}
ostream &print_char_tree(ostream &os, string s)
{
    BinaryTree<char> char_tree;
    vector<char> v;
    for (uint i = 0; i < s.length(); i++)
    {
        v.push_back(s.at(i));
        cout << s.at(i);
    }
    char_tree.add_root(v[0]);
    uint count = 0;
    for (uint i = 1; i < v.size() - 1; i += 2, ++count)
    {
        char_tree.add_right(v[count], v[i]).add_left(v[count], v[i + 1]);
    }
    if (v.size() % 2 == 0)
    {
        char_tree.add_right(v[count], v[v.size() - 1]);
    }
    os << char_tree << endl
       << endl;

    os << "Preorder Traversal of the tree is:" << endl;
    for (auto i = char_tree.begin_preorder(); i != char_tree.end_preorder(); ++i)
    {
        os << *i << " ";
    }
    os << endl;
    os << "Inorder Traversal of the tree is:" << endl;
    for (auto i = char_tree.begin(); i != char_tree.end(); ++i)
    {
        os << *i << " ";
    }
    os << endl;
    os << "Postorder Traversal of the tree is:" << endl;
    for (auto i = char_tree.begin_postorder(); i != char_tree.end_postorder(); ++i)
    {
        os << *i << " ";
    }
    os << endl;
    return os;
}

int main()
{
    int choice;
    string s, line;
    cout << "Please select the desired option by inserting it's number:" << endl;
    cout << "1.Counting Tree (by a given limit)\n2.String Tree\n3.Char Tree\n"
         << endl;
    cout << "Otherwise: Quit\n\n";
    cout << "Option: ";
    cin >> choice;
    cin.ignore();
    switch (choice)
    {
    case 1:
    {
        cout << "enter a limit for the count: ";
        int lim = 0;
        cin >> lim;
        cout << endl;
        print_counting_tree(cout, lim);
        break;
    }
    case 2:
    {
        cout << "enter strings seperated by spaces with no duplications: ";

        getline(cin, line);
        if (line.size() > 0)
        {
            print_string_tree(cout, line);
        }
        break;
    }
    case 3:
    {
        cout << "enter a string with no duplications or whitespaces: ";
        cin >> s;
        print_char_tree(cout, s);
        cout << endl;
        break;
    }

        return 0;
    }
}