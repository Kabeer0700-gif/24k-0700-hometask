
#include <iostream>
using namespace std;

class Node {
public:
    int id;
    int quantity;
    Node* left;
    Node* right;
    Node(int id, int quantity) {
        this->id = id;
        this->quantity = quantity;
        left = right = nullptr;
    }
};

class BinarySearchTree {
public:
    Node* root;
    BinarySearchTree() {
        root = nullptr;
    }

    Node* insert(Node* node, int pid, int qty) {
        if (node == nullptr) return new Node(pid, qty);
        if (pid < node->id)
            node->left = insert(node->left, pid, qty);
        else if (pid > node->id)
            node->right = insert(node->right, pid, qty);
        else
            node->quantity += qty;
        return node;
    }

    void addProduct(int pid, int qty) {
        root = insert(root, pid, qty);
    }

    Node* search(Node* node, int pid) {
        if (node == nullptr || node->id == pid) return node;
        if (pid < node->id) return search(node->left, pid);
        return search(node->right, pid);
    }

    Node* findMaxQuantity(Node* node, Node* maxNode = nullptr) {
        if (node == nullptr) return maxNode;
        if (maxNode == nullptr || node->quantity > maxNode->quantity)
            maxNode = node;
        maxNode = findMaxQuantity(node->left, maxNode);
        maxNode = findMaxQuantity(node->right, maxNode);
        return maxNode;
    }

    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << "Product ID: " << node->id << "  Quantity: " << node->quantity << endl;
        inorder(node->right);
    }
};

int main() {
    BinarySearchTree TREE;

    TREE.addProduct(5, 20);
    TREE.addProduct(3, 15);
    TREE.addProduct(7, 5);
    TREE.addProduct(2, 6);
    TREE.addProduct(4, 2);
    TREE.addProduct(6, 3);
    TREE.addProduct(8, 1);

    TREE.addProduct(6, 22); 

    cout << "All Products:\n";
    TREE.inorder(TREE.root);

    int searchId = 15;
    Node* result = TREE.search(TREE.root, searchId);
    if (result)
        cout << "\nProduct " << searchId << " found with quantity: " << result->quantity << endl;
    else
        cout << "\nProduct " << searchId << " not found.\n";

    Node* maxNode = TREE.findMaxQuantity(TREE.root);
    if (maxNode)
        cout << "\nProduct with highest quantity: ID " << maxNode->id 
             << " (Quantity: " << maxNode->quantity << ")\n";

    return 0;
}
