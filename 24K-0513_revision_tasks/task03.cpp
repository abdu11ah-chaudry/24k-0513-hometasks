// part a:
#include<iostream>
using namespace std;

#define n 4

bool isSafe(int grid[4][4], int r, int c, int solution[4][4]){
    if(r<0 || c<0 || r>=n || c>=n || grid[r][c]==0 || solution[r][c]==1){
        return false;
    }
    return true;
}

bool getRobotPath(int grid[4][4], int r, int c, int solution[4][4]){

    if(r==n-1 && c==n-1){
        solution[r][c]=1;
        return true;
    }

    if(isSafe(grid,r,c,solution)){
        
        solution[r][c]=1;

        //Down:
        if(getRobotPath(grid,r+1,c,solution)){
            return true;
        }
        //Right:
        if(getRobotPath(grid,r,c+1,solution)){
            return true;
        }
        //Up:
        if(getRobotPath(grid,r-1,c,solution)){
            return true;
        }
        //Left:
        if(getRobotPath(grid,r,c-1,solution)){
            return true;
        }

        solution[r][c]=0; //BackTrack
        return false;
    }
    return false;
}

int main(){
    int grid[4][4]={{1,0,1,1},{1,1,0,1},{0,1,1,1},{1,0,1,1}};

    int solution[4][4]={{0}};  

    getRobotPath(grid,0,0,solution);
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cout<<solution[i][j]<<" ";
        }
        cout<<endl;
    }
}

// Part b:

/*
My path came out this due to the nature of recursive calls which goes down in an order of down->right->up->left.
Here at recursive calls at (2,2) I could have gone to (2,3) and then find the path at (3,3) but I got the answer as 
(2,2)->(3,2)->(3,3) because my recursive call is written for down firstly then for right so It would go for the 
right path!
*/
