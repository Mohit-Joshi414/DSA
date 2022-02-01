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
    if(root==NULL){
        return 0;
    }
    int lh =heightOfTree(root->left);
    int rh = heightOfTree(root->right);
    
    return max(lh,rh)+1;
}

int calDiameter(Node* root){
    
    if(root == NULL){
        return 0;
    }
    int lh = heightOfTree(root->left);
    int rh = heightOfTree(root->right);
    
    int currDia = lh+rh+1;
    
    int ld = calDiameter(root->left);
    int rd = calDiameter(root->right);
    
    return max(currDia, max(ld,rd));
}

int calcDiameterOptimized(Node* root, int* height){
    
    if(root == NULL){
        *height=0;
        return 0;
    }
    int lh=0,rh=0;
    int ld = calcDiameterOptimized(root->left, &lh);
    int rd = calcDiameterOptimized(root->right, &rh);
    
    int currDiameter = lh+rh+1;
    *height = max(lh,rh)+1;
    
    return max(currDiameter, max(ld,rd));
}

int main()
{
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left->left = new Node(6);
    
    cout<<heightOfTree(root)<<endl;
    cout<<calDiameter(root)<<endl;
    int height=0;
    cout<<calcDiameterOptimized(root,&height);
    return 0;
}
