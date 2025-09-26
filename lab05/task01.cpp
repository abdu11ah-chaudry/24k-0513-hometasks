#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int play(int secret,int turn){
    int x;
    cout<<"Turn "<<turn<<": ";
    cin>>x;
    if(x==secret){
        cout<<"Player "<<turn<<" guessed correctly!\n";
    return 0;
    }
    if(x<secret){
        cout<<"pljj Guess higher\n";
    }    
    else
    {
        cout<<"Pljj Guess lower\n";
    }    
    return play(secret, turn==1?2:1);
}


int main(){
    
    srand(time(0));
    int n=rand()%100+1;
    
    
    play(n,1);
    
    return 0;
}
