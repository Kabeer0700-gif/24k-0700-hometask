#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* data;
    int size;
  
public:
    DynamicArray() {
        data = nullptr;
        size = 0;
        
    }

    ~DynamicArray() {
        delete[] data;
    }

    void pushBack(int value) {
        
        int* newData = new int[size + 1];
        for (int i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        newData[size] = value;
        delete[] data;
        data = newData;
        size++;
    }

    void print() const {
        for (int i = 0; i < size; ++i) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    DynamicArray Arr;
    Arr.pushBack(1);
    Arr.pushBack(2);
    Arr.pushBack(3);
    Arr.print();
    Arr.pushBack(4);
    Arr.print();
    return 0;
}

