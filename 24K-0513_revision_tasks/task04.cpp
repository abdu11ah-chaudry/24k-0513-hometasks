// part a:
#include<iostream>
using namespace std;

#define n 4

bool isSafe(int maze[4][4], int r, int c, int solution[4][4]){
    if(r<0 || c<0 || r>=n || c>=n || maze[r][c]==0 || solution[r][c]==1){
        return false;
    }
    return true;
}

bool getEscapePath(int maze[4][4], int r, int c, int solution[4][4]){

    if(r==n-1 && c==n-1){
        solution[r][c]=1;
        return true;
    }

    if(isSafe(maze,r,c,solution)){
        
        solution[r][c]=1;

        //Down:
        if(getEscapePath(maze,r+1,c,solution)){
            return true;
        }
        //Right:
        if(getEscapePath(maze,r,c+1,solution)){
            return true;
        }
        //Up:
        if(getEscapePath(maze,r-1,c,solution)){
            return true;
        }
        //Left:
        if(getEscapePath(maze,r,c-1,solution)){
            return true;
        }

        solution[r][c]=0; //BackTrack
        return false;
    }
    return false;
}

int main(){
    int maze[4][4]={{1,1,0,1},{0,1,1,0},{1,1,0,1},{0,1,1,1}};

    int solution[4][4]={{0}};  

    if(getEscapePath(maze,0,0,solution)){
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                cout<<solution[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else{
        cout<<"No path found!"<<endl;
    }
}    
//Part B:
/*
solution[r][c]=0;
This is the step which is responsible for back Tracking , if there exit no path to the destination
Then we will back track from that cell that is making that cell in solution array as zero and not going to
any of the directions will automatically cause the function to return false, Hence no paths!
*/
