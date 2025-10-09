#include<iostream>
#include<vector>
using namespace std;

//path that is called first will be followed first by the robot
void paths(int maze[][5],int sr,int sc,int er,int ec,string mov,vector<string> &ds,int n){
    if(sr == er && sc == ec){
        ds.push_back(mov);
        return;
    }

    if(sr < 0 || sc < 0){
        return;
    }

    if(sr >= n || sc >= n){
        return;
    }

    if(maze[sr][sc] == 0) return;  //this line will be responsible for no escape

    if(maze[sr][sc] == -1) return; 

    maze[sr][sc] = -1;
    //mov down
    paths(maze,sr+1,sc,er,ec,mov+'D',ds,n);
    //mov right
    paths(maze,sr,sc+1,er,ec,mov+'R',ds,n);

     //mov up
    paths(maze,sr - 1,sc,er,ec,mov+'U',ds,n);

     //mov left
    paths(maze,sr,sc-1,er,ec,mov+'L',ds,n);

    maze[sr][sc] = 1;
}

int main(){
    int maze[5][5] = {{1,1,1,0,1},
                      {0,1,0,1,1},
                      {1,1,1,1,0},
                      {0,1,0,1,1},
                      {1,1,1,0,1}};
    
 vector<string> ds1;
 vector<string> ds2;
 string mov1 = "";
 string mov2 = "";
 paths(maze,0,0,2,2,mov1,ds1,5);
   
 cout<<"PATH FOR RABIT"<<endl;
 for(auto it : ds1){
    cout<<it<<endl;
 }

 paths(maze,4,4,2,2,mov2,ds2,5);

 cout<<"PATH FOR CAT"<<endl;
 for(auto it : ds2){
    cout<<it<<endl;
 }
}