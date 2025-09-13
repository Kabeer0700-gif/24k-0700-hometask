#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class List
{
public:
    Node *head;

    List()
    {
        head = NULL;
    }

    void push_back(int d)
    {
        Node *temp = head;
        Node *nn = new Node(d);

        if (head == NULL)
        {
            head = nn;
        }
        else
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = nn;
        }
    }

    Node *getHead()
    {
        return head;
    }
    Node *findMiddle()
    {
        if (head == NULL)
        {
            return NULL;
        }
        Node *slow = head;
        Node *fast = head;

        while (fast->next != NULL && fast != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    Node *merge(Node *h1, Node *h2)
    {
        Node *temp1 = h1;
        Node *temp2 = h2;
        Node *dummy = new Node(-1);
        Node *temp = dummy;

        while (temp1 != NULL && temp2 != NULL)
        {
            if (temp1->data < temp2->data)
            {
                temp->next = temp1;
                temp = temp1;
                temp1 = temp1->next;
            }
            else
            {
                temp->next = temp2;
                temp = temp2;
                temp2 = temp2->next;
            }
        }

        if (temp1)
        {
            temp->next = temp1;
        }
        else
        {
            temp->next = temp2;
        }

        return dummy->next;
    }

    Node *concatenate(List l1, List l2)
    {
        Node *t1 = l1.getHead();
        Node *t2 = l2.getHead();

        if (!t1)
            return t2;
        if (!t2)
            return t1;

        Node *temp = t1;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = t2;

        return t1;
    }

    Node *sortList(Node *head)
    {
        Node *temp = head;
        if (temp == NULL)
        {
            return NULL;
        }
        vector<int> arr;

        while (temp != NULL)
        {
            arr.push_back(temp->data);
            temp = temp->next;
        }
        sort(arr.begin(), arr.end());

        Node *t2 = head;
        int count = 0;

        while (t2 != NULL)
        {
            t2->data = arr[count++];
            t2 = t2->next;
        }
        return head;
    }
   Node* removeDuplicates(Node* head) {
    Node* nH = sortList(head);
    Node* curr = nH;
    while (curr != nullptr && curr->next != nullptr) {
        if (curr->data == curr->next->data) {
            Node* dup = curr->next;
            curr->next = curr->next->next;
            delete dup;
        } else {
            curr = curr->next;
        }
    }
    return nH;  
}

    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};

int main(){
    List l1, l2;

    l1.push_back(5);
    l1.push_back(1);
    l1.push_back(3);

    l2.push_back(4);
    l2.push_back(2);
    l2.push_back(3);

    Node* cat = l1.concatenate(l1, l2);
    l1.head = cat;
    l1.display();
    cat = l1.removeDuplicates(cat);
    l1.head = cat;

    l1.display();

    return 0;
}

