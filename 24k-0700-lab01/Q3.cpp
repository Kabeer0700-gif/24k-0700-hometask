#include <iostream>
using namespace std;

class Exam {
    int* marks;
    int size;
public:
    Exam(int s) {
        size = s;
        marks = new int[size];
        for (int i = 0; i < size; i++) marks[i] = 0;
    }
    ~Exam() {
        delete[] marks;
    }
    void setMark(int i, int m) {
        if (i >= 0 && i < size) marks[i] = m;
    }
    void show() {
        for (int i = 0; i < size; i++) cout << marks[i] << " ";
        cout << endl;
    }
};

int main() {
    Exam e1(3);
    e1.setMark(0, 50);
    e1.setMark(1, 60);
    e1.setMark(2, 70);
    Exam e2 = e1;
    e2.setMark(1, 99);
    e1.show();
    e2.show();
}
