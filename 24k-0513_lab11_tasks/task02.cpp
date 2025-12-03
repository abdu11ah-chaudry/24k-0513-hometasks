#include<iostream>
using namespace std;

const int TABLE_SIZE = 100;

class Node{
public:
    string value;
    Node* next;
    
    Node(string v):value(v),next(nullptr){}
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
    void insert(string value){
        int index=hashFunction(value);

        Node* temp=table[index];
        
        while(temp!=nullptr){
            //keep the value if it already exist
            if(temp->value==value){
                return;
            }
            temp=temp->next;
        }

        Node* newNode= new Node(value);
        newNode->next=table[index];
        table[index]=newNode;
    }

    void search(string value){
        int index=hashFunction(value);

        Node* temp=table[index];

        while(temp!=nullptr){
            if(temp->value==value){
                cout<<"found: "<<temp->value<<endl;
                return;
            }
            temp=temp->next;
        }

        cout<<value<<" Not found in the table!"<<endl;
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
                 cout<<" -> "<<"[String: "<<temp->value<<"]";
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

    h.insert("First");
    h.insert("Second");
    h.insert("Third");
    h.insert("Fourth");

    h.displayTable();

    h.search("Fourth");
    h.search("Last");
}
