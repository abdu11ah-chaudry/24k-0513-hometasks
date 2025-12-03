#include<iostream>
using namespace std;

const int table_size=15;

class StudentHashTable{
public:
    int rollnums[table_size];
    string names[table_size];
    bool occupied[table_size];
    
    StudentHashTable(){
        for(int i=0; i<table_size; i++){
            rollnums[i]=0;
            names[i]="";
            occupied[i]=false;
        }   
    }

    int hashFunction(int roll){
        return ((2*roll)+3)%table_size;
    }


    void insertRecords(int roll, string nam){
        int index;
        int hash=hashFunction(roll);
        int i=0;

        while(i<table_size){
            index =(hash+(i*i))%table_size;
            //-1 case for deleted:
            if(!occupied[index] || rollnums[index]==roll ||rollnums[index]==-1){
                rollnums[index]=roll;
                names[index]=nam;
                occupied[index]=true;
                return;
            }

            i++;
        }
        cout<<"Hash table is full, can not insertRecords the roll!"<<endl;
    }

    void searchRecords(int roll){
        int index;
        int hash=hashFunction(roll);
        int i=0;

        while(i<table_size){
            index =(hash+(i*i))%table_size;

            if(!occupied[index]){
                cout<<"Not found!"<<endl;
                return;
            }
            if(rollnums[index]==roll){
                cout<<roll<<" Found and its nam is: "<<names[index]<<endl;
                return;
            }

            i++;
        }
        cout<<"Not Found!"<<endl;
    }

    

    void displayRecords(){
        for(int i=0; i<table_size; i++){
            cout<<"Index "<<i+1<<": ";    
            if(occupied[i] && rollnums[i]!=-1){
                cout<<" Roll no: "<<rollnums[i]<<" Name: "<<names[i]<<endl;
                continue;
            }
            cout<<" Key: -"<<" Value: -"<<endl;
        }
    }
};

int main(){

    StudentHashTable h;

    h.insertRecords(3,"Abdullah");
    h.insertRecords(2,"Ali");
    h.insertRecords(9,"Ahmed");
    h.insertRecords(6,"Qaiser");
    h.insertRecords(11,"Naveed");
    h.insertRecords(13,"Shahid");

    h.displayRecords();
    h.searchRecords(13);

}
