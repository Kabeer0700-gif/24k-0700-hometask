#include <iostream>
#include <string>
using namespace std;

class ProductNode {
public:
    int code;
    string title;
    int cost;
    ProductNode* prev;
    ProductNode* next;

    ProductNode(int c, string t, int k) {
        code = c;
        title = t;
        cost = k;
        prev = nullptr;
        next = nullptr;
    }
};

class Cart {
private:
    ProductNode* head;
    ProductNode* tail;

public:
    Cart() {
        head = nullptr;
        tail = nullptr;
    }

    void addToEnd(int code, string title, int cost) {
        ProductNode* newNode = new ProductNode(code, title, cost);
        if (!head) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void addToFront(int code, string title, int cost) {
        ProductNode* newNode = new ProductNode(code, title, cost);
        if (!head) {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void removeFront() {
        if (!head) {
            cout << "Cart is empty\n";
            return;
        }
        ProductNode* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete temp;
    }

    void removeEnd() {
        if (!tail) {
            cout << "Cart is empty\n";
            return;
        }
        ProductNode* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete temp;
    }

    void searchByCode(int code) {
        ProductNode* temp = head;
        while (temp) {
            if (temp->code == code) {
                cout << "Found: " << temp->code << " " << temp->title << " $" << temp->cost << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Item not found\n";
    }

    void updateCost(int code, int newCost) {
        ProductNode* temp = head;
        while (temp) {
            if (temp->code == code) {
                temp->cost = newCost;
                cout << "Updated: " << temp->code << " " << temp->title << " $" << temp->cost << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Item not found\n";
    }

    void displayForward() {
        if (!head) {
            cout << "Cart is empty\n";
            return;
        }
        ProductNode* temp = head;
        cout << "Cart (Front -> End):\n";
        while (temp) {
            cout << temp->code << " " << temp->title << " $" << temp->cost << endl;
            temp = temp->next;
        }
    }

    void displayBackward() {
        if (!tail) {
            cout << "Cart is empty\n";
            return;
        }
        ProductNode* temp = tail;
        cout << "Cart (End -> Front):\n";
        while (temp) {
            cout << temp->code << " " << temp->title << " $" << temp->cost << endl;
            temp = temp->prev;
        }
    }

    void countProducts() {
        int count = 0;
        ProductNode* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        cout << "Total products: " << count << endl;
    }

    void mostExpensive() {
        if (!head) {
            cout << "Cart is empty\n";
            return;
        }
        ProductNode* temp = head;
        ProductNode* maxItem = head;
        while (temp) {
            if (temp->cost > maxItem->cost) maxItem = temp;
            temp = temp->next;
        }
        cout << "Most Expensive: " << maxItem->code << " " << maxItem->title << " $" << maxItem->cost << endl;
    }
};

int main() {
    Cart myCart;
    myCart.addToEnd(1, "Book", 25);
    myCart.addToEnd(2, "Pen", 5);
    myCart.addToEnd(3, "Notebook", 15);
    myCart.addToEnd(4, "Bag", 60);

    myCart.displayForward();
    cout << "---\n";

    myCart.addToFront(5, "WaterBottle", 10);
    myCart.displayForward();
    cout << "---\n";

    myCart.removeFront();
    myCart.removeEnd();
    myCart.displayForward();
    cout << "---\n";

    myCart.searchByCode(2);
    myCart.updateCost(2, 8);
    myCart.displayForward();
    cout << "---\n";

    myCart.displayBackward();
    cout << "---\n";

    myCart.countProducts();
    myCart.mostExpensive();

    return 0;
}
