#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    
    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

int heightOfTree(Node* root){
    if(root == NULL){
        return 0;
    }
    
    int lh =heightOfTree(root->left);
    int rh = heightOfTree(root->right);
    
    return max(lh,rh)+1;
}

bool isBalanced(Node* root){
    if(root == NULL){
        return true;
    }
    
    if(isBalanced(root->left)==false){
        return false;
    }
    if(isBalanced(root->right)==false){
        return false;
    }
    
    int lh =heightOfTree(root->left);
    int rh = heightOfTree(root->right);
    
    if(abs(lh-rh)<=1){
        return true;
    }
    else{
        return false;        
    }

}

bool isBalancedOptimized(Node* root, int* height){
    if(root == NULL){
        
        return true;
    }
    int lh=0,rh=0;
    if(isBalancedOptimized(root->left,&lh)==false){
        return false;
    }
    if(isBalancedOptimized(root->right,&rh)==false){
        return false;
    }
    *height = max(lh,rh)+1;
    if(abs(lh-rh)<=1){
        return true;
    }else{
        return false;
    }
}

void preorder(Node* root){
    if(root ==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->left->right = new Node(5);
    // root->right->left->left = new Node(6);
    
   if(isBalanced(root)){
       cout<<"Balanced"<<endl;
   }
   else{
       cout<<"not balanced"<<endl;
   }
   int height=0;
   if(isBalancedOptimized(root,&height)){
       cout<<"Balanced";
   }
   else{
       cout<<"not balanced";
   }
    return 0;
}
