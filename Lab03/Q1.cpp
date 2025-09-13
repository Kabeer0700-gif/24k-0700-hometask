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
    
    List(){
        head = NULL;
    }

    void push_back(const string& d){
        Node* temp = head;
        Node* nn = new Node(d);

        if(head == NULL){
            head = nn;
        }else{
            while(temp->next != NULL){
                temp = temp->next;
            }

            temp->next = nn;
        }
    }

    void push_front(const string& d){
        Node* nn  = new Node(d);
           if(head == NULL){
            head = nn;
        }
        else{
            nn->next = head;
            head = nn;
        }
    }

    void insertAfter(const string& d, const string& data){
    Node* temp = head;
    while(temp != NULL){
        if(temp->data == d){
            Node* nn = new Node(data);
            nn->next = temp->next;
            temp->next = nn;
            return;   
        }
        temp = temp->next;
    }
   
}


    bool search(const string& data){
        Node* temp = head;
        while(temp != NULL){
            if(temp->data == data){
                return true;
            }
            temp = temp->next;
        }
        return false;
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
    List books;
    books.push_back("Data Structure");
    books.push_back("Operating System");
    books.push_back("Computer Network");
    books.push_back("Database System");

    books.display();
    cout<<"\nAdding New Book at Front"<<endl;
    books.push_front("Artificial Intelligence");
    cout<<endl;
    books.display();

    cout<<"\nAdding New Book at Back"<<endl;
    books.push_back("Machine Learning");
     cout<<endl;
    books.display();

    cout<<"\nAdding New Book after Operating system"<<endl;
    books.insertAfter("Operating System","Cyber Security");
    bool search = books.search("Database System");
    cout<<(search ? "book found" : "Not found")<<endl;
    cout<<"\n----------Displaying Books--------------"<<endl;
    books.display();

}
