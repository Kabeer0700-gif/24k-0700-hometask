#include <iostream>
#include <vector>
#include<cstring>

using namespace std;


int maze[5][5] = {
    {1, 0, 0, 0, 0},
    {1, 1, 0, 1, 0},
    {0, 1, 0, 0, 0},
    {0, 1, 1, 1, 1},
    {0, 0, 0, 0, 1}
};


int solution[5][5];


bool isSafe(int x, int y) {
  
    return (x >= 0 && y >= 0 && x < 5 && y < 5 && maze[x][y] == 1);
}


bool solveMaze(int x, int y) {
    
    if (x == 4 && y == 4) {
        solution[x][y] = 1; 
        return true;
    }

  
    if (isSafe(x, y)) {
       
        solution[x][y] = 1;

       
        if (solveMaze(x, y + 1)) {
            return true;
        }
       
        if (solveMaze(x + 1, y)) {
            return true;
        }
      
        if (solveMaze(x, y - 1)) {
            return true;
        }
       
        if (solveMaze(x - 1, y)) {
            return true;
        }

      
        solution[x][y] = 0;
        return false;
    }

    return false;
}


void printSolution() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << solution[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
  
    memset(solution, 0, sizeof(solution));


    if (solveMaze(0, 0)) {
        cout << "Solution path found!" << endl;
        printSolution();
    } else {
        cout << "No solution exists!" << endl;
    }

    return 0;
}
