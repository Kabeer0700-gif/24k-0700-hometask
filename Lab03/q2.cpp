#include<iostream>
using namespace std;

class Node{
    public:
    string data;
    Node* next;

    Node(string data){
        this->data = data;
        next = NULL;
    }
};

class List{
    public:
    Node* head;
    Node* tail;
    List(){
        tail = head = NULL;
    }

    void push_back(const string& d){
        Node* nn = new Node(d);
        Node* temp = head;

        if(head == NULL){
            head = nn;
            tail = nn;
            return;
        }

        while(temp->next != NULL){
            temp = temp->next;
        }
        
        temp->next = nn;
        tail = nn;
    }

    void pop_front(){
        if(head == NULL){
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

     Node* search(const string& data){
        Node* temp = head;
        while(temp != NULL){
            if(temp->data == data){
                return temp;
            }
            temp = temp->next;
        }

        return NULL;
    }

   Node* searchByPos(int pos) {
    if (pos <= 0) return NULL; 

    Node* temp = head;
    int count = 1;

    while (temp != NULL && count < pos) {
        temp = temp->next;
        count++;
    }

    return temp;  
}


};

#include <iostream>
using namespace std;

int main() {
    List catalog;

    catalog.push_back("The Great Gatsby");
    catalog.push_back("1984");
    catalog.push_back("To Kill a Mockingbird");
    catalog.push_back("Hitler The Great");
    catalog.push_back("War and Peace");

    cout << "📚 Book Catalog Created!\n";


    catalog.pop_front();
    cout << "Removed first book from catalog.\n";

    
    string title = "1984";
    Node* found = catalog.search(title);
    if(found != NULL) {
        cout << "Found book: " << found->data << endl;
    } else {
        cout << "Book not found: " << title << endl;
    }

   
    int pos = 2;
    Node* byPos = catalog.searchByPos(pos);
    if(byPos != NULL) {
        cout << "Book at position " << pos << ": " << byPos->data << endl;
    } else {
        cout << "No book at position " << pos << endl;
    }

    
    cout << "\nCurrent Catalog:\n";
    Node* temp = catalog.head;
    int count = 1;
    while(temp != NULL) {
        cout << count++ << ". " << temp->data << endl;
        temp = temp->next;
    }

    return 0;
}
