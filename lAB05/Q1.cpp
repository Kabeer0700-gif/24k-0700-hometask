#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

void guess(int n){
    cout<<"Enter guessed Number for (1-100)"<<endl;
    int g;
    cin>>g;

    if(g == n){
        cout<<"number found! "<<n<<endl;
        return;
    }

    if(g < n){
        cout<<"number is less than guess number"<<endl;
    }

    if(g > n){
        cout<<"number is greater than guess number"<<endl;
    }

    guess(n);
}

int main(){
     srand(static_cast<unsigned int>(time(0)));

     int randomNumber = rand() % 100 + 1;

     guess(randomNumber);
}
