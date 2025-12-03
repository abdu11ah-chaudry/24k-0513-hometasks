#include<iostream>
using namespace std;

const int table_size=50;
class HashTable{
public: 
    string names[table_size];
    bool occupied[table_size];

    HashTable(){
        for(int i=0; i<table_size; i++){
            names[i]="";
            occupied[i]=false;
        }
    }

    //primary hashing:
    int hashFunction1(string name){
        int sum=0;
        for(int i=0; i<name.size(); i++){
           sum+=name[i];     
        }     
        return sum%table_size;
    }


    //secondary hashing(double hashing) taking double hashing function as h(k)=3k+1 mod table size
    int hashFunction2(string name){
        int sum=0;
        for(int i=0; i<name.size(); i++){
           sum+=name[i];     
        }     
        return 7-sum%7;
    }

    void add_Employee(string name){
        int hash1=hashFunction1(name);
        int hash2=hashFunction2(name);
        int index;
        int i=0;

        while(i<table_size){
            index=(hash1+ (hash2*i))%table_size;

            //also dealing repeated insertion
            if(!occupied[index] || names[index]==name){
                occupied[index]=true;
                names[index]=name;
                return;
            }

            i++;
        }
        cout<<"HashTable is full, can not add_Employee more names!"<<endl;
    }

    void search_Employee(string name){
        int hash1=hashFunction1(name);
        int hash2=hashFunction2(name);
        int index;
        int i=0;

        while(i<table_size){
            index=(hash1+ (hash2*i))%table_size;

            if(!occupied[index]){
                cout<<name<<" not found!"<<endl;
                return;
            }
            if(names[index]==name){
                cout<<name<<" Found!"<<endl;
                return;
            }
            i++;
        }
        cout<<"No such employee exists!"<<endl;
    }


    void display_Table(){
        for(int i=0; i<table_size; i++){
            cout<<"Index "<<i+1<<": ";    
            if(occupied[i]){
                cout<<" Name: "<<names[i]<<endl;
                continue;
            }
            cout<<endl;
        }
    }
};

int main(){
     HashTable h;

    h.add_Employee("Abdullah");
    h.add_Employee("Shafique");
    h.add_Employee("Shaheer");
    h.add_Employee("Abbas");
    h.add_Employee("Nasir");

    h.display_Table();

    h.search_Employee("Abdullah");
    h.search_Employee("Rehman");

}
