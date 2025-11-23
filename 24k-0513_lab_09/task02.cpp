#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    int height;
    Node(int d):data(d),height(1),left(nullptr),right(nullptr){}
};

int getHeight(Node* n){
    if(n==nullptr){
        return 0;
    }
    return n->height;
}

int getBalanceFactor(Node* n){
    if(n==nullptr){
        return 0;
    }
    return getHeight(n->left)-getHeight(n->right);
}

Node* rotateRight(Node* y){

    Node* x=y->left;
    Node* T2=x->right;

    //Rotation:
    x->right=y;
    y->left=T2;

    //Updating height:
    x->height=1+max(getHeight(x->left),getHeight(x->right));
    y->height=1+max(getHeight(y->left),getHeight(y->right));

    return x;
}

Node* rotateLeft(Node* x){

    Node* y=x->right;
    Node* T2=y->left;

    //Rotation:
    y->left=x;
    x->right=T2;

    //Updating height:
    x->height=1+max(getHeight(x->left),getHeight(x->right));
    y->height=1+max(getHeight(y->left),getHeight(y->right));

    return y;
}

//Insertion in AVL:
Node* insert(Node* root, int key){

    //Performing normal BST insertion:
    if(root==nullptr){
        return new Node(key);
    }
    else if(key<root->data){
        root->left=insert(root->left,key);
    }
    else if(key>root->data){
        root->right=insert(root->right,key);
    }
    else{
        return root;
    }

    //updating height:
    root->height=1+max(getHeight(root->left),getHeight(root->right));

    int bf=getBalanceFactor(root);

    //checking for unbalancies:
    //LL:
    if(bf>1 && key<root->left->data){
        return rotateRight(root);
    }
    //RR:
    if(bf<-1 && key>root->right->data){
        return rotateLeft(root);
    }
    //LR:
    if(bf>1 && key>root->left->data){
        root->left=rotateLeft(root->left);
        return rotateRight(root);
    }
    //RL:
    if(bf<-1 && key<root->right->data){
        root->right=rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

void InOrderTraversal(Node* root){ //left->Root->Right
    if(root==nullptr){
        return;
    }

    InOrderTraversal(root->left);
    cout<<root->data<<" ";
    InOrderTraversal(root->right);
}

int main(){
    Node* root=nullptr;
    //INSERTING THE ALREADY PRESENT ELEMENTS:   
    int arr[7]={50,30,70,20,40,60,80};
    for(int i=0; i<7; i++){
        root=insert(root,arr[i]);
    }

    //Now inserting 55:
    root=insert(root,55);

    //displaying the AVL tree:
    cout<<"In order traversal of the AVL: "<<endl;
    InOrderTraversal(root);

}
