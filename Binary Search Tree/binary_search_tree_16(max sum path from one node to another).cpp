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

int maxPathSumUtil(Node* root, int &ans){
    if(root == NULL){
        return 0;
    }
    
    int left = maxPathSumUtil(root->leftNode,ans);
    int right = maxPathSumUtil(root->rightNode,ans);
    
    int nodeMax = max(max(root->data, root->data+left+right),
                      max(root->data+left, root->data + right));
                      
    ans = max(ans,nodeMax);
    
    int singlePathSUm = max(root->data,max(root->data+left,root->data+right));
    return singlePathSUm;
}

int maxPathSum(Node* root){
    int ans = INT_MIN;
    
    maxPathSumUtil(root, ans);
    return ans;
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
    
    cout<<maxPathSum(root);
    return 0;
}
