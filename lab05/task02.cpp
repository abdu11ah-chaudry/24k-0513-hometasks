//This is 5th task of manual

#include<iostream>
using namespace std;

int sum(int num){
    if(num==0){
        return 0;
    }
    else{
        return num%10 + sum(num/10);
    }
}


int main(){
    int x;
    cout<<"Enter a Number: "<<endl;
    cin>>x;

    cout<<"Sum of digits: "<<sum(x)<<endl;
}
