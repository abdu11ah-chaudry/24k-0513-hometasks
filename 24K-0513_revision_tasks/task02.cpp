//Part 01:
#include<iostream>
using namespace std;

void shellSort(int *luggage, int n){
    int count=0;

    for(int gap=n/2; gap>=1; gap/=2){
        count++;
        for(int j=gap; j<n; j++){

            for(int i=j-gap; i>=0; i-=gap){
                if(luggage[i]>luggage[i+gap]){
                    int temp=luggage[i];
                    luggage[i]=luggage[i+gap];
                    luggage[i+gap]=temp;
                }
                else{
                    break;
                }
            }
        }

        cout<<"After gap sequence: "<<count<<endl;
        for(int i=0; i<n; i++){
            cout<<luggage[i]<<" ";
        }
        cout<<endl;

    }

}


int main(){
    int luggage[7]={32,25,40,12,18,50,28};
    shellSort(luggage,7);
}

//Part 02:
/*
Comparing this case with bubble sort: here the airport should use shell sort because it will get the work done in
fewer steps because bubble sort requires many comparisions and hence not optimal for this! 
*/

//Part 03:
/*
    if most of luggage array is sorted , the shell sort would likely work as insertion sort!
*/
