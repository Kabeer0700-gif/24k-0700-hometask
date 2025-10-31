#include <iostream>
#include <string>
using namespace std;

class TourPakageSystem {
public:
    string name;
    TourPakageSystem* left;
    TourPakageSystem* right;

    TourPakageSystem(string n) {
        name = n;
        left = right = nullptr;
    }
};

class TourTree {
private:
    TourPakageSystem* root;

    void display(TourPakageSystem* node, int space) {
        if (node == nullptr) return;
        space += 5;
        display(node->right, space);
        cout << endl;
        for (int i = 5; i < space; i++) cout << " ";
        cout << node->name << endl;
        display(node->left, space);
    }

    TourPakageSystem* add(TourPakageSystem* node, string parent, string name, char side) {
        if (node == nullptr) return nullptr;
        if (node->name == parent) {
            if (side == 'L' && node->left == nullptr)
                node->left = new TourPakageSystem(name);
            else if (side == 'R' && node->right == nullptr)
                node->right = new TourPakageSystem(name);
            else
                cout << "Unable to add. Child already exists" <<endl;
            return node;
        }
        add(node->left, parent, name, side);
        add(node->right, parent, name, side);
        return node;
    }

public:
    TourTree() {
        root = nullptr;
    }

    void createRoot(string name) {
        if (root == nullptr)
            root = new TourPakageSystem(name);
        else
            cout << "Root exists already unable to add new root" <<endl;
    }

    void addPackage(string parent, string name, char side) {
        if (root == nullptr) {
            cout << "Root Not created.";
            return;
        }
        add(root, parent, name, side);
    }

    void displayTree() {
        if (root == nullptr) cout << "No packages to display." <<endl;
        else display(root, 0);
    }
};

int main() {
    TourTree tree;
    int choice;
    string name, parent;
    char side;

    cout << "===== TOUR PACKAGE MANAGEMENT SYSTEM =====" <<endl;
    do {
        cout << "\n1. Create Root Package"
             << "\n2. Add New Package "
             << "\n3. View  All Packages"
             << "\n4. Exit"
             << "\nEnter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            cout << "Enter root package name: ";
            getline(cin, name);
            tree.createRoot(name);
            break;
        case 2:
            cout << "Enter parent package name: ";
            getline(cin, parent);
            cout << "Enter new package name: ";
            getline(cin, name);
            cout << "Enter side (L/R): ";
            cin >> side;
            cin.ignore();
            tree.addPackage(parent, name, side);
            break;
        case 3:
            tree.displayTree();
            break;
        case 4:
            cout << "Exiting program." <<endl;
            break;
        default:
            cout << "Invalid choice." <<endl;
        }
    } while (choice != 4);
    return 0;
}
