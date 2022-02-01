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

//code 1: for LCA

bool getPath(Node* root, int key, vector<int> &path){
    if(root == NULL){
        return false;
    }
    path.push_back(root->data);
    if(root->data == key){
        return true;
    }
    
    if(getPath(root->leftNode, key,path) || getPath(root->rightNode,key,path)){
        return true;
    }
    
    path.pop_back();
    return false;
}

int LCA(Node* root, int n1,int n2){
    vector<int> p1,p2;
    if(!getPath(root,n1,p1) || !getPath(root, n2,p2)){
        return -1;
    }
    
    int pc;
    for(pc=0;pc<p1.size() && p2.size();pc++){
        if(p1[pc] != p2[pc]){
            break;
        }
    }
    return p1[pc-1];
}

//code 2 : for LCA optimized

Node* LCA2(Node* root, int n1,int n2){
    
    if(root == NULL){
        return NULL;
    }
    
    if(root->data == n1 || root->data== n2){
        return root;
    }
    
    Node* leftLCA = LCA2(root->leftNode,n1,n2);
    Node* rightLCA = LCA2(root->rightNode,n1,n2);
    
    if(leftLCA && rightLCA){
        return root;
    }
    
    if(leftLCA != NULL){
        return leftLCA;
    }
    return rightLCA;
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
    root->rightNode->leftNode = new Node(6);
    root->rightNode->rightNode = new Node(7);
    root->rightNode->rightNode->leftNode = new Node(8);
    
    
    /*
        1
       / \
      2   3
     / \
    4   5
    */
    //case 1:
    int n1 =6;
    int n2=8;
    int lca = LCA(root,n1,n2);
    if(lca==-1){
        cout << "lca doesn't exist" << endl;
    }
    else{
        cout<<"lca : "<<lca<<endl;
    }
    
    //case 2:
    
    int n3 =6;
    int n4=8;
    Node* lca2 = LCA2(root,n3,n4);
    if(lca2==NULL){
        cout << "lca doesn't exist" << endl;
    }
    else{
        cout<<"lca : "<<lca2->data;
    }
    return 0;
}
