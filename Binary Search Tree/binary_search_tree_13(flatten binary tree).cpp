#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* leftNode;
    struct Node* rightNode;
    Node(int val){
        data = val;
        leftNode = NULL;
        rightNode = NULL;
    }
};


void flatten(Node* root){
    if(root ==NULL || (root->leftNode == NULL && root->rightNode == NULL)){
        return;
    }
    if(root->leftNode !=NULL){
        flatten(root->leftNode);
        
        Node* temp = root->rightNode;
        
        root->rightNode = root->leftNode;
        root->leftNode = NULL;
        
        Node* t = root->rightNode;
        while(t->rightNode != NULL){
            t = t->rightNode;
        }
        t->rightNode = temp;
        
    }
    flatten(root->rightNode);
    
}

void inorderPrint(Node* root){
    if(root == NULL){
        return;
    }
    inorderPrint(root->leftNode);
    cout<<root->data<<" ";
    inorderPrint(root->rightNode);
}

int main()
{
    struct Node* root = new Node(1);
    root->leftNode= new Node(2);
    root->rightNode= new Node(3);
    /*
        1
       / \
      2   3
    */
    
    root->leftNode->leftNode = new Node(4);
    root->leftNode->rightNode = new Node(5);
    /*
        1
       / \
      2   3
     / \
    4   5
    */
    inorderPrint(root);
    cout<<endl;
    flatten(root);
    inorderPrint(root);
    return 0;
}
