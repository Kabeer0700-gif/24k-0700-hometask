#include<iostream>
#include<vector>
using namespace std;

//path that is called first will be followed first by the robot
void paths(int maze[][4],int sr,int sc,int er,int ec,string mov,vector<string> &ds,int n){
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

    if(maze[sr][sc] == 0) return;

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
    int maze[4][4] = {{1,0,1,1},
                      {1,1,0,1},
                      {0,1,1,1},
                      {1,0,1,1}};
    
 vector<string> ds;
 string mov = "";
 paths(maze,0,0,3,3,mov,ds,4);
   
 for(auto it : ds){
    cout<<it<<endl;
 }
}
