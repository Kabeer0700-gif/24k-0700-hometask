#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data){
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

class List{
    public:
    Node* head;
    List(){
         head = NULL;
    }

    void push_back(int data){
        Node* nn = new Node(data);
        Node* temp = head;

        if(head == NULL){
            head = nn;
            return;
        }

        while(temp->next != NULL){
            temp = temp->next;
        }

        temp->next = nn;
        nn->prev = temp;
    }

    void pop_front(){
        if(head == NULL){
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void search(int n){
        if(n <= 0){
            cout<<"Invalid compartment"<<endl;
        }
        if(head == NULL){
            return;
        }

        Node* temp = head;
        while(temp != NULL){
            if(temp->data == n){
                cout<<"Compartment found "<<temp->data <<endl;
                return;
            }
            temp = temp->next;
        }

        cout<<"No Comparrtment with this Number found"<<endl;
    }

    
    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<endl;
            temp = temp->next;
        }
    }
};

int main(){
    List trainCompartment;
    int choice, num;

    do{
        cout << "\n--- Train Compartment Menu ---\n";
        cout << "1. Add Compartment (at back)\n";
        cout << "2. Remove Front Compartment\n";
        cout << "3. Search Compartment\n";
        cout << "4. Display Compartments\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                cout << "Enter compartment number to add: ";
                cin >> num;
                trainCompartment.push_back(num);
                cout << "Compartment " << num << " added.\n";
                break;

            case 2:
                trainCompartment.pop_front();
                cout << "Front compartment removed.\n";
                break;

            case 3:
                cout << "Enter compartment number to search: ";
                cin >> num;
                trainCompartment.search(num);
                break;

            case 4:
                cout << "Compartments in Train:\n";
                trainCompartment.display();
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice, try again.\n";
        }

    }while(choice != 5);

    return 0;
}
