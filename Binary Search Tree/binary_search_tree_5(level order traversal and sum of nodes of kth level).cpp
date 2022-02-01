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

int sumAtK(Node* root, int k){
    if(root == NULL){
        return -1;
    }
    int level = 0;
    int sum =0;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        Node* node = q.front();
        q.pop();
        if(node != NULL){
            if(level == k){
                sum += node->data;
            }
            if(node->leftNode){
                q.push(node->leftNode);
            }
            if(node->rightNode){
                q.push(node->rightNode);
            }
        }
        else if(!q.empty()){
            q.push(NULL);
            level++;
        }
    }
    return sum;
}

void levelorder(Node* root){
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        Node* node = q.front();
        q.pop();
        if(node != NULL){
            cout<<node->data<<" ";
            if(node->leftNode){
                q.push(node->leftNode);
            }
            if(node->rightNode){
                q.push(node->rightNode);
            }
        }
        else if(!q.empty()){
            q.push(NULL);
        }
    }
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
    
    levelorder(root);
    cout<<endl;
    cout<<sumAtK(root, 1);
    return 0;
}
