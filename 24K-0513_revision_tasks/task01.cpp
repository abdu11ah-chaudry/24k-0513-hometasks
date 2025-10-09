/*
The shell sort would be more appropiate here instead of insertion sort because the insertion sort will take
too much comparisions as the smallest element is at the last , whereas in shell sort we are using gap of
n/2 after each gap sequence which would lead to less comparisions and shifting and hence more optimal!
*/


#include<iostream>
using namespace std;

void shellSort(int *books, int n, int count){
    for(int gap=n/2; gap>=1; gap/=2){
        count++;
        for(int j=gap; j<n; j++){

            for(int i=j-gap; i>=0; i-=gap){
                if(books[i]>books[i+gap]){
                    swap(books[i],books[i+gap]);
                }
                else{
                    break;
                }
            }
        }

        cout<<"After gap sequence: "<<count<<endl;
        for(int i=0; i<n; i++){
            cout<<books[i]<<" ";
        }
        cout<<endl;
    }
}


int main(){
    int count=0;
    int books[6]={205,102,310,450,120,90};
    shellSort(books,6,count);
    
}
