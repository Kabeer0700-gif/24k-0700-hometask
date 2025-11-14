#include <iostream>
using namespace std;

class Node {
public:
    int key, height;
    Node* left;
    Node* right;

    Node(int k) {
        key = k;
        height = 1;
        left = right = NULL;
    }
};

class AVLTree {
public:
    Node* root;

    AVLTree() {
        root = NULL;
    }

    int height(Node* n) {
        return n ? n->height : 0;
    }

    int getBalance(Node* n) {
        return n ? height(n->left) - height(n->right) : 0;
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* t = x->right;

        x->right = y;
        y->left = t;

        y->height = 1 + max(height(y->left), height(y->right));
        x->height = 1 + max(height(x->left), height(x->right));

        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* t = y->left;

        y->left = x;
        x->right = t;

        x->height = 1 + max(height(x->left), height(x->right));
        y->height = 1 + max(height(y->left), height(y->right));

        return y;
    }

    Node* insert(Node* node, int key) {
        if (!node) return new Node(key);

        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = getBalance(node);

     
        if (balance > 1 && key < node->left->key)
            return rightRotate(node);

      
        if (balance < -1 && key > node->right->key)
            return leftRotate(node);

    
        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

      
        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

  
    void rotateRootLeft() {
        root = leftRotate(root);
    }

    void preorder(Node* node) {
        if (!node) return;
        cout << node->key << " ";
        preorder(node->left);
        preorder(node->right);
    }
};

int main() {
    AVLTree Avl;

    int array[] = {50, 30, 70, 20, 40, 60, 80};
    for (int x : array)
        Avl.root = Avl.insert(Avl.root, x);

    Avl.root = Avl.insert(Avl.root, 55);

    cout << "Before Left Rotation: ";
    Avl.preorder(Avl.root);
    cout << endl;

  
    Avl.rotateRootLeft();

    cout << "After Left Rotation on Root: ";
    Avl.preorder(Avl.root);

    return 0;
}
