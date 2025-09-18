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

    void addTail(string title, int cost) {
        Product* newProd = new Product(title, cost);
        if (!head) {
            head = newProd;
            return;
        }
        Product* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newProd;
    }

    void deleteFront() {
        if (!head) {
            cout << "Cart is empty\n";
            return;
        }
        Product* temp = head;
        head = head->next;
        delete temp;
    }

    void searchByTitle(string title) {
        Product* temp = head;
        while (temp) {
            if (temp->title == title) {
                cout << temp->title << " - $" << temp->cost << endl;
                return;
            }
            temp = temp->next;
        }
        cout << title << " not found\n";
    }

    void searchByIndex(int pos) {
        Product* temp = head;
        int count = 1;
        while (temp) {
            if (count == pos) {
                cout << temp->title << " - $" << temp->cost << endl;
                return;
            }
            count++;
            temp = temp->next;
        }
        cout << "Position " << pos << " not found\n";
    }

    void showCart() {
        if (!head) {
            cout << "Cart is empty\n";
            return;
        }
        Product* temp = head;
        cout << "Shopping Cart:\n";
        while (temp) {
            cout << temp->title << " - $" << temp->cost << endl;
            temp = temp->next;
        }
    }
};

int main() {
    Cart myCart;
    myCart.addTail("Book", 25);
    myCart.addTail("Pen", 5);
    myCart.addTail("Notebook", 15);
    myCart.addTail("Bag", 60);

    myCart.showCart();
    cout << "---\n";

    myCart.deleteFront();
    myCart.showCart();
    cout << "---\n";

    myCart.searchByTitle("Notebook");
    myCart.searchByIndex(2);

   myCart.showCart();
    cout << "---\n";
    return 0;
}
