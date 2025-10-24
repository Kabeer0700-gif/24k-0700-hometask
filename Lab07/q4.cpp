#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void insertEnd(Node*& head, int data) {
    Node* n = new Node(data);
    if (!head) head = n;
    else {
        Node* t = head;
        while (t->next) t = t->next;
        t->next = n;
    }
}

void swapData(Node* a, Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

Node* partition(Node* start, Node* end) {
    int pivot = end->data;
    Node* p = start;
    Node* curr = start;
    while (curr != end) {
        if (curr->data < pivot) {
            swapData(curr, p);
            p = p->next;
        }
        curr = curr->next;
    }
    swapData(p, end);
    return p;
}

void quickSort(Node* start, Node* end) {
    if (!start || start == end || !end) return;
    Node* p = partition(start, end);
    Node* temp = start;
    while (temp->next != p && temp->next) temp = temp->next;
    if (temp != p) quickSort(start, temp);
    quickSort(p->next, end);
}

void display(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
}

Node* getTail(Node* head) {
    while (head && head->next) head = head->next;
    return head;
}

int main() {
    Node* head = nullptr;
    int arr[] = {10, 7, 8, 9, 1, 5, 3};
    for (int x : arr) insertEnd(head, x);

    Node* tail = getTail(head);
    quickSort(head, tail);

    display(head);
    return 0;
}
