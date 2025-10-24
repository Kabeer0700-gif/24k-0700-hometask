#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int score;
    Student* next;
    Student(string n, int s) : name(n), score(s), next(nullptr) {}
};

class StudentList {
private:
    Student* head;

    int getMaxScore() {
        int mx = head->score;
        Student* t = head;
        while (t) {
            if (t->score > mx) mx = t->score;
            t = t->next;
        }
        return mx;
    }

public:
    StudentList() : head(nullptr) {}

    void insert(string name, int score) {
        Student* s = new Student(name, score);
        if (!head) head = s;
        else {
            Student* t = head;
            while (t->next) t = t->next;
            t->next = s;
        }
    }

    void radixSort() {
        if (!head || !head->next) return;
        int mx = getMaxScore();
        for (int exp = 1; mx / exp > 0; exp *= 10) {
            Student* buckets[10] = {nullptr};
            Student* t = head;
            while (t) {
                int digit = (t->score / exp) % 10;
                Student* nxt = t->next;
                t->next = buckets[digit];
                buckets[digit] = t;
                t = nxt;
            }
            head = nullptr;
            Student* tail = nullptr;
            for (int i = 0; i < 10; i++) {
                if (buckets[i]) {
                    if (!head) head = buckets[i];
                    else tail->next = buckets[i];
                    tail = buckets[i];
                    while (tail->next) tail = tail->next;
                }
            }
        }
    }

    void display() {
        Student* t = head;
        while (t) {
            cout << t->name << " - " << t->score << endl;
            t = t->next;
        }
    }
};

int main() {
    StudentList list;
    int n;
    string name;
    int score;

    cout << "Enter number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> name >> score;
        list.insert(name, score);
    }

    list.radixSort();
    list.display();
    return 0;
}
