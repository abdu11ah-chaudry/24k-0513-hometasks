#include<iostream>
using namespace std;

const int TABLE_SIZE = 10;

class Node{
public:
    string value;
    int key;
    Node* next;
    
    Node(string v,int k):value(v),key(k),next(nullptr){}
};

class HashTable{
    public:
    Node* table[TABLE_SIZE];
    
    HashTable(){
        for(int i=0; i<TABLE_SIZE; i++){
            table[i]=nullptr;
        }
    }


    int hashFunction(string value){
        int sum=0;
        for(int i=0; i<value.size(); i++){
           sum+=value[i];     
        }     
        return sum%TABLE_SIZE;
    }


    // seperate chaining:
    void insert(int key, string value){
        int index=hashFunction(value);

        Node* temp=table[index];
        //check if key already exist in the table index:
        while(temp!=nullptr){
            //update the value if it already exist
            if(temp->key==key){
                temp->value=value;
                return;
            }
            temp=temp->next;
        }

        Node* newNode= new Node(value,key);
        newNode->next=table[index];
        table[index]=newNode;
    }

    void search(int key, string value){
        int index=hashFunction(value);

        Node* temp=table[index];

        while(temp!=nullptr){
            if(temp->key==key){
                cout<<"key found and its value is: "<<temp->value<<endl;
                return;
            }
            temp=temp->next;
        }

        cout<<key<<" not found in the table!"<<endl;
        return;
    }


    void displayTable(){
        
        for(int i=0; i<TABLE_SIZE; i++){
            Node* temp=table[i];

            cout<<"Index "<<i+1<<": ";
            if(temp==nullptr){
                cout<<"Empty"<<endl;
                continue;
            }

            while(temp!=nullptr){
                 cout<<" -> [Key: "<<temp->key<<", Name: "<<temp->value<<"]";
                 temp=temp->next;
            }
            cout<<endl;
        }
    }

    // ~destructor to clear all:
    ~HashTable(){
        for(int i=0; i<TABLE_SIZE; i++) {
            Node* current=table[i];
            while (current!=nullptr) {
                Node* temp=current;
                current=current->next;
                delete temp;
            }
        }
    }
};    

int main(){
    HashTable h;

    h.insert(1,"apple");
    h.insert(2,"Mango");
    h.insert(3,"apple");
    h.insert(4,"grapes");
    h.insert(5,"peaches");
    h.insert(6,"banana");
    
    h.displayTable();

    h.search(5,"peaches");
    h.search(11,"apple");

}
