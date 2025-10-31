#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class BinaryTree {
public:
    Node* root;
    BinaryTree() {
        root = nullptr;
    }

    Node* createNode(int val) {
        return new Node(val);
    }

    int subtreeSum(Node* node) {
        if (node == nullptr) return 0;
        return node->data + subtreeSum(node->left) + subtreeSum(node->right);
    }

    bool findSubtree(Node* node, int target) {
        if (node == nullptr) return false;
        int sum = subtreeSum(node);
        if (sum == target) {
            DisplayTree(node, 0);
            return true;
        }
        return findSubtree(node->left, target) || findSubtree(node->right, target);
    }

    void DisplayTree(Node* node, int space) {
        if (node == nullptr) return;
        space += 5;
        DisplayTree(node->right, space);
        cout << endl;
        for (int i = 5; i < space; i++) cout << " ";
        cout << node->data << endl;
        DisplayTree(node->left, space);
    }
};

int main() {
    BinaryTree TREE;
    TREE.root = TREE.createNode(5);
    TREE.root->left = TREE.createNode(3);
    TREE.root->right = TREE.createNode(8);
    TREE.root->left->left = TREE.createNode(2);
    TREE.root->left->right = TREE.createNode(4);
    TREE.root->right->left = TREE.createNode(6);
    TREE.root->right->right = TREE.createNode(10);

    int target;
    cout << "Enter target sum: ";
    cin >> target;

    if (!TREE.findSubtree(TREE.root, target))
        cout << "subtree not found with sum " << target << "." << endl;

    return 0;
}
