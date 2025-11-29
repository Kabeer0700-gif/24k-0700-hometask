#include<iostream>
using namespace std;

int priority(char c){
    if(c == 'A') return 5;
    if(c == 'B') return 3;
    if(c == 'C') return 8;
    if(c == 'D') return 6;

}
class MaxHeap{
public:
    char* ch;
    int size;
    int capacity;

MaxHeap(int cap){
    capacity = cap + 1;
    ch = new char[capacity];
    size = 0;
}

void insert(char c){
    if(size == capacity){
        cout<<"heap Overflow"<<endl;
        return;
    }

    size++;
    ch[size] = c;
    int i = size;

    while(i!=1 && priority(ch[i]) > priority(ch[i/2])){
        swap(ch[i],ch[i/2]);
        i/=2;
    }

    return;
}

char deleteMax(){
    if(size == 0){
        cout<<"Heap is empty"<<endl;
        return -1;
    }

    char root = ch[1];
    ch[1] = ch[size];
    size--;
    heapify(1);
    return root;
}

void heapify(int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if(left <= size && priority(ch[left]) > priority(ch[largest])) largest = left;
    if(right <= size && priority(ch[right]) > priority(ch[largest])) largest = right;

    if(largest != i){
        swap(ch[i],ch[largest]);
        heapify(largest);
    }

    return;
}



void display(){
     if(size == 0){
        cout<<"heap is full"<<endl;
    }

    for(int i=1; i<=size; i++){
        cout<<ch[i]<<" ";
    }
}

~MaxHeap(){
    delete[] ch;
}
};

int main(){
     MaxHeap heap(5);

    heap.insert('A');
    heap.insert('B');
    heap.insert('C');

     cout << "Deleting max: " << heap.deleteMax() << endl;
    cout << "After delete: \n";
    heap.display();

    heap.insert('D');
    cout << "\nAfter insert task D: ";
    heap.display();

  

    return 0;
}
