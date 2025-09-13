#include <iostream>
#include <string>
using namespace std;

class Track {
public:
    string name;
    Track* link;

    Track(string n) : name(n), link(nullptr) {}
};

class Queue {
public:
    Track* first;

    Queue() : first(nullptr) {}

    void insert(string n) {
        Track* t = new Track(n);
        if (!first) {
            first = t;
            first->link = first;
            return;
        }
        Track* cur = first;
        while (cur->link != first) cur = cur->link;
        cur->link = t;
        t->link = first;
    }

    void display() const {
        if (!first) {
            cout << "No tracks available!" << endl;
            return;
        }
        Track* cur = first;
        do {
            cout << cur->name << " -> ";
            cur = cur->link;
        } while (cur != first);
        cout << "(loop)" << endl;
    }

    void play(int count) const {
        if (!first) {
            cout << "No tracks available!" << endl;
            return;
        }
        Track* cur = first;
        for (int i = 0; i < count; i++) {
            cout << "Now Playing: " << cur->name << endl;
            cur = cur->link;
        }
    }
};

int main() {
    Queue q;
    q.insert("Alpha");
    q.insert("Beta");
    q.insert("Gamma");

    cout << "Queue: ";
    q.display();

    cout << "\nPlayback (7 tracks):" << endl;
    q.play(7);

    return 0;
}
