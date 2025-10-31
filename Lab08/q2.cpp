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

    int noOfNodes(Node* node) {
        if (node == nullptr) return 0;
        return 1 + noOfNodes(node->left) + noOfNodes(node->right);
    }

    int noOfLeafNode(Node* node) {
        if (node == nullptr) return 0;
        if (node->left == nullptr && node->right == nullptr) return 1;
        return noOfLeafNode(node->left) + noOfLeafNode(node->right);
    }

    int height(Node* node) {
        if (node == nullptr) return 0;
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        return 1 + max(leftHeight, rightHeight);
    }
};

int main() {
    BinaryTree T;

    T.root = T.createNode(1);
    T.root->left = T.createNode(2);
    T.root->right = T.createNode(3);
    T.root->left->left = T.createNode(4);
    T.root->left->right = T.createNode(5);
    T.root->right->right = T.createNode(6);

    cout << "Total Nodes: " << T.noOfNodes(T.root) << endl;
    cout << "Leaf Nodes: " << T.noOfLeafNode(T.root) << endl;
    cout << "Height of Tree: " << T.height(T.root) << endl;

    return 0;
}
