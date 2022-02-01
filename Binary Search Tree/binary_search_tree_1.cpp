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
    return 0;
}
