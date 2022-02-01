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

//case 1:

void printSubtreeNode(Node* root, int k){
    if(root==NULL || k<0){
        return;
    }
    if(k==0){
        cout<<root->data<<" ";
        return;
    }
    
    printSubtreeNode(root->leftNode,k-1);
    printSubtreeNode(root->rightNode,k-1);
    
}

//case 2:

int printNodeAtK(Node* root, Node* target, int k){
    if(root == NULL){
        return -1;
    }
    if(root == target){
        printSubtreeNode(root,k);
        return 0;
    }
    
    int dl = printNodeAtK(root->leftNode,target,k);
    if(dl != -1){
        if(dl+1 == k){
            cout<<root->data<<" ";
        }else{
            printSubtreeNode(root->rightNode, k-dl-2);
        }
        return 1+dl;
    }
    
    int dr = printNodeAtK(root->rightNode,target,k);
    if(dr != -1){
        if(dr+1 == k){
            cout<<root->data<<" ";
        }else{
            printSubtreeNode(root->leftNode, k-dr-2);
        }
        return 1+dr;
    }
    
    return -1;
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
    printNodeAtK(root, root->leftNode->leftNode, 3);
    return 0;
}
