#include<iostream>
using namespace std;

const int table_size=10;
class HashTable{
public: 
    int keys[table_size];
    bool occupied[table_size];

    HashTable(){
        for(int i=0; i<table_size; i++){
            keys[i]=0;
            occupied[i]=false;
        }
    }

    // taking hash as 2k+3 as question has not mentioned anything!
    int hashFunction(int key){
        return ((2*key)+3)%table_size;
    }

    void insert(int key){
        int hash=hashFunction(key);
        int index;
        int i=0;

        while(i<table_size){
            index=(hash+i)%table_size;

            //-1 case is to re insert the deleted slots also dealing the repeated key case
            if(!occupied[index] || keys[index]==key ||keys[index]==-1){
                keys[index]=key;
                occupied[index]=true;
                return;
            }

            i++;
        }
        cout<<"HashTable is full, can not insert more values!"<<endl;
    }

    void search(int key){
        int hash=hashFunction(key);
        int index;
        int i=0;

        while(i<table_size){
            index=(hash+i)%table_size;

            if(!occupied[index]){
                cout<<"Not found!"<<endl;
                return;
            }
            if(keys[index]==key){
                cout<<key<<" Found"<<endl;
                return;
            }
            i++;
        }
        cout<<"No such key exists!"<<endl;
    }

    void deletion(int key){
        int hash=hashFunction(key);
        int index;
        int i=0;

        while(i<table_size){
            index=(hash+i)%table_size;

            if(!occupied[index]){
                cout<<"no such key exists, can not delete!"<<endl;
                return;
            }

            if(keys[index]==key){
                keys[index]=-1;
                cout<<"Deleted succesfully!"<<endl;
                return;
            }

            i++;
        }
        cout<<"no such key exists, can not delete!"<<endl;
    }

    void displayTable(){
        for(int i=0; i<table_size; i++){
            if(occupied[i] && keys[i]!=-1){
                cout<<keys[i]<<" ";
            }
        }
        cout<<endl;
    }
};

int main(){
     HashTable h;

    h.insert(1);
    h.insert(3);
    h.insert(4);
    h.insert(5);
    h.insert(7);

    h.displayTable();

    h.search(3);
    h.search(13);

    //deleting key=7
    h.deletion(3);

    h.displayTable();
}

