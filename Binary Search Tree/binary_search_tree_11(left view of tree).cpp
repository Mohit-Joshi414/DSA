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

void leftViewOfTree(Node* root){
    if(root == NULL){
        return;
    }
    
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){
        int n = q.size();
        
        for(int i=0;i<n;i++){
            Node* curr = q.front();
            q.pop();
            if(i==0){
                cout<<curr->data<<" ";
            }
            if(curr->left != NULL){
                q.push(curr->left);
            }
            if(curr->right != NULL){
                q.push(curr->right);
            }
        }
    }
}

int main()
{
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left->left = new Node(6);
    
   
    leftViewOfTree(root);
    return 0;
}