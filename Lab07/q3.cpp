#include <iostream>
#include <string>
using namespace std;

class Product {
public:
    string name;
    float price;
    string description;
    bool available;
};

void swap(Product& a, Product& b) {
    Product temp = a;
    a = b;
    b = temp;
}

int partition(Product arr[], int low, int high) {
    float pivot = arr[high].price;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j].price < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(Product arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main() {
    Product products[3];
    
    for (int i = 0; i < 3; i++)
        cin >> products[i].name >> products[i].price >> products[i].description >> products[i].available;

    quickSort(products, 0, 2);

    cout << "\nSorted Product List by Price:\n";
    for (int i = 0; i < 3; i++)
        cout << products[i].name << " | " 
             << products[i].price << " | "
             << products[i].description << " | "
             << (products[i].available ? "Available" : "Out of Stock") << endl;
    
    return 0;
}
