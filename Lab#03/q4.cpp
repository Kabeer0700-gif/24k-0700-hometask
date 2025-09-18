#include <iostream>
#include <string>
using namespace std;

class Pass {
public:
    int pid;
    string holder;
    string attraction;
    Pass* next;

    Pass(int i, string h, string a) {
        pid = i;
        holder = h;
        attraction = a;
        next = nullptr;
    }
};

class RideSystem {
private:
    Pass* last;

public:
    RideSystem() {
        last = nullptr;
    }

    void addEnd(int pid, string holder, string attraction) {
        Pass* p = new Pass(pid, holder, attraction);
        if (!last) {
            last = p;
            last->next = last;
            return;
        }
        p->next = last->next;
        last->next = p;
        last = p;
    }

    void addFront(int pid, string holder, string attraction) {
        Pass* p = new Pass(pid, holder, attraction);
        if (!last) {
            last = p;
            last->next = last;
            return;
        }
        p->next = last->next;
        last->next = p;
    }

    void removeFront() {
        if (!last) {
            cout << "No passes\n";
            return;
        }
        Pass* head = last->next;
        if (head == last) {
            delete head;
            last = nullptr;
            return;
        }
        last->next = head->next;
        delete head;
    }

    void removeByID(int pid) {
        if (!last) {
            cout << "No passes\n";
            return;
        }
        Pass* temp = last->next;
        Pass* before = last;
        do {
            if (temp->pid == pid) {
                if (temp == last && temp == last->next) {
                    delete temp;
                    last = nullptr;
                } else {
                    before->next = temp->next;
                    if (temp == last) last = before;
                    delete temp;
                }
                return;
            }
            before = temp;
            temp = temp->next;
        } while (temp != last->next);
        cout << "Pass ID " << pid << " not found\n";
    }

    void searchByID(int pid) {
        if (!last) {
            cout << "No passes\n";
            return;
        }
        Pass* temp = last->next;
        do {
            if (temp->pid == pid) {
                cout << "Found: " << temp->pid << " " << temp->holder << " " << temp->attraction << endl;
                return;
            }
            temp = temp->next;
        } while (temp != last->next);
        cout << "Pass ID " << pid << " not found\n";
    }

    void display() {
        if (!last) {
            cout << "No passes\n";
            return;
        }
        Pass* temp = last->next;
        cout << "Passes (circular order):\n";
        do {
            cout << temp->pid << " " << temp->holder << " " << temp->attraction << endl;
            temp = temp->next;
        } while (temp != last->next);
    }

    void countPasses() {
        if (!last) {
            cout << "Total passes: 0\n";
            return;
        }
        int count = 0;
        Pass* temp = last->next;
        do {
            count++;
            temp = temp->next;
        } while (temp != last->next);
        cout << "Total passes: " << count << endl;
    }

    void nextAfterID(int pid) {
        if (!last) {
            cout << "No passes\n";
            return;
        }
        Pass* temp = last->next;
        do {
            if (temp->pid == pid) {
                cout << "Next Pass: " << temp->next->pid << " " << temp->next->holder << " " << temp->next->attraction << endl;
                return;
            }
            temp = temp->next;
        } while (temp != last->next);
        cout << "Pass ID " << pid << " not found\n";
    }
};

int main() {
    RideSystem sys;
    sys.addEnd(1, "Ali", "PirateShip");
    sys.addEnd(2, "Hammad", "DropTower");
    sys.addEnd(3, "Hamza", "WaterSlide");
    sys.display();
    cout << "---\n";

    sys.addFront(0, "Rafay", "HorrorMaze");
    sys.display();
    cout << "---\n";

    sys.removeByID(2);
    sys.display();
    cout << "---\n";

    sys.searchByID(3);
    sys.removeFront();
    sys.display();
    cout << "---\n";

    sys.countPasses();
    sys.nextAfterID(3);

    return 0;
}
