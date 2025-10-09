#include<iostream>
#include<vector>
using namespace std;

#define n 5

bool isSafe(vector<vector<int>> &maze, int r, int c, vector<vector<int>> &solution){
    if(r<0 || c<0 || r>=n || c>=n || maze[r][c]==0 || solution[r][c]==1){
        return false;
    }
    return true;
}


void AllPossiblePaths(vector<vector<int>> &maze, int r, int c, vector<vector<int>> &solution, vector<vector<vector<int>>> &allSolutions){

    if(r==2 && c==2){
        solution[r][c]=1;
        allSolutions.push_back(solution);
        return;
    }

    if(isSafe(maze,r,c,solution)){

        solution[r][c]=1;

        //Down:
        AllPossiblePaths(maze,r+1,c,solution,allSolutions);
        //Right:
        AllPossiblePaths(maze,r,c+1,solution,allSolutions);
        //Up:
        AllPossiblePaths(maze,r-1,c,solution,allSolutions);
        //Left:
        AllPossiblePaths(maze,r,c-1,solution,allSolutions);

        solution[r][c]=0; //BackTrack
        return;
    }
    
    return;
}

void intersectionPoints(vector<vector<vector<int>>> allSolutionsRabbit,vector<vector<vector<int>>> allSolutionsCat){
    //For each path of rabbit:
    for(int i=0; i<allSolutionsRabbit.size(); i++){
        // we will check each path  of cat
        for(int j=0; j<allSolutionsCat.size(); j++){
            // we will check each cell(r,c) if they intersect or not:
            for(int r=0; r<n; r++){
                for(int c=0; c<n; c++){
                    if(allSolutionsRabbit[i][r][c]==1 && allSolutionsCat[j][r][c]==1){
                        cout<<"("<<r<<","<<c<<")"<<endl;
                    }
                }
            }
        }    
    }
}






int main(){

    vector<vector<int>> maze={{1,1,1,0,1},{0,1,0,1,1},{1,1,1,1,0},{0,1,0,1,1},{1,1,1,0,1}};

    vector<vector<int>> solutionForRabbit(n,vector<int>(n,0));
    vector<vector<int>> solutionForCat(n, vector<int>(n,0));

    vector<vector<vector<int>>> allSolutionsRabbit;
    vector<vector<vector<int>>> allSolutionsCat;

    
    cout<<"For Rabbit: "<<endl;
    AllPossiblePaths(maze,0,0,solutionForRabbit,allSolutionsRabbit);
    for(int i=0; i<allSolutionsRabbit.size(); i++){
        cout<<"solution "<<i+1<<": "<<endl;
        for(int j=0; j<solutionForRabbit.size(); j++){
            for(int k=0; k<solutionForRabbit.size(); k++){
                cout<<allSolutionsRabbit[i][j][k]<<" ";
            }
            cout<<endl;
        }    
    }
    
    
    cout<<"For Cat: "<<endl;
    AllPossiblePaths(maze,4,4,solutionForCat,allSolutionsCat);
    for(int i=0; i<allSolutionsCat.size(); i++){
        cout<<"solution "<<i+1<<": "<<endl;
        for(int j=0; j<solutionForCat.size(); j++){
            for(int k=0; k<solutionForCat.size(); k++){
                cout<<allSolutionsCat[i][j][k]<<" ";
            }
            cout<<endl;
        }    
    }

    cout<<"The intersection points are: "<<endl;
    intersectionPoints(allSolutionsRabbit,allSolutionsCat);

    return 0;
}
