#include <iostream>
#include <string>
using namespace std;

class Product {
public:
    string title;
    int cost;
    Product* next;

    Product(string t, int c) {
        title = t;
        cost = c;
        next = nullptr;
    }
};

class Cart {
private:
    Product* head;

public:
    Cart() {
        head = nullptr;
    }

    void addToFront(string title, int cost) {
        Product* newProd = new Product(title, cost);
        newProd->next = head;
        head = newProd;
    }

    void addToBack(string title, int cost) {
        Product* newProd = new Product(title, cost);
        if (head == nullptr) {
            head = newProd;
            return;
        }
        Product* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newProd;
    }

    void insertAfter(string afterTitle, string title, int cost) {
        Product* temp = head;
        while (temp != nullptr) {
            if (temp->title == afterTitle) {
                Product* newProd = new Product(title, cost);
                newProd->next = temp->next;
                temp->next = newProd;
                return;
            }
            temp = temp->next;
        }
    }

    void searchItem(string title) {
        Product* temp = head;
        while (temp != nullptr) {
            if (temp->title == title) {
                cout << title << " is available with price $" << temp->cost << endl;
                return;
            }
            temp = temp->next;
        }
        cout << title << " is not found in the cart!" << endl;
    }

    void showCart() {
        Product* temp = head;
        cout << "\nYour Shopping Cart:\n";
        while (temp != nullptr) {
            cout << temp->title << " - $" << temp->cost << endl;
            temp = temp->next;
        }
    }
};

int main() {
    Cart myCart;
    myCart.addToFront("Smartwatch", 200);
    myCart.addToBack("Keyboard", 80);
    myCart.insertAfter("Phone", "Monitor", 300);
    myCart.searchItem("Tablet");
    myCart.showCart();
    return 0;
}

