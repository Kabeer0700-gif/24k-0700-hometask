#include <iostream>
using namespace std;

class JaggedArray {
public:
    int** data;
    int* rowSizes;
    int numRows;

    JaggedArray(int r, int* sizes) : numRows(r) {
        rowSizes = new int[numRows];
        data = new int*[numRows];
        for (int i = 0; i < numRows; ++i) {
            rowSizes[i] = sizes[i];
            data[i] = new int[rowSizes[i]];
            for (int j = 0; j < rowSizes[i]; ++j)
                data[i][j] = 0; 
        }
    }

    ~JaggedArray() {
        for (int i = 0; i < numRows; ++i)
            delete[] data[i];
        delete[] data;
        delete[] rowSizes;
    }

    void print() const {
        for (int i = 0; i < numRows; ++i) {
            cout << "Row #" << i << ": ";
            for (int j = 0; j < rowSizes[i]; ++j) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
        cout<<endl;
    }

    int sum(int row) {
        int total = 0;
        for (int j = 0; j < rowSizes[row]; ++j)
            total += data[row][j];
        return total;
    }

    void store(int r, int c, int value) {
        if (r >= 0 && r < numRows && c >= 0 && c < rowSizes[r]) {
            data[r][c] = value;
        }
    }
};

int main() {
    int* arr = new int[4]{1, 2, 3,4};
    JaggedArray Jagged(4, arr);
    Jagged.print();
    cout<<endl;
    Jagged.store(0, 0, 5);
    Jagged.store(0, 1, 10);
    Jagged.store(1, 0, 15);
    Jagged.store(2, 0, 20);
    Jagged.store(3,1,78);
    Jagged.print();
    int n = Jagged.numRows;
    cout<<endl<<n<<endl;
    for(int i=0;i<n;i++)
        cout<<"Sum :- "<<i<<" is "<<Jagged.sum(i)<<endl;
    delete[] arr;
}