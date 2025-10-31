#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

class BinaryTree
{
public:
    Node *root;
    BinaryTree()
    {
        root = nullptr;
    }

    Node *createNode(int val)
    {
        return new Node(val);
    }

    bool isFull(Node *node)
    {
        if (node == nullptr)
            return true;
        if ((node->left == nullptr && node->right == nullptr))
            return true;
        if (node->left && node->right)
            return isFull(node->left) && isFull(node->right);
        return false;
    }
};

int main()
{
    BinaryTree TREE;
    TREE.root = TREE.createNode(1);
    TREE.root->left = TREE.createNode(2);
    TREE.root->right = TREE.createNode(3);
    TREE.root->left->left = TREE.createNode(4);
    TREE.root->left->right = TREE.createNode(5);
    TREE.root->right->left = TREE.createNode(6);
    TREE.root->right->right = TREE.createNode(7);

    if (TREE.isFull(TREE.root))
        cout << "It is a full binary TREE." << endl;
    else
        cout << "The TREE is not a full binary TREE." << endl;

    return 0;
}
