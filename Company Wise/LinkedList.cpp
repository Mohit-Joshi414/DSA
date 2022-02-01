#include <bits/stdc++.h>

using namespace std;

class Node{
  private:
    int Data;
    Node *Next;
  
  public:
    void insertAtBegining(int x);
    void insertAtEnd(int x);
    void print();
};
Node *Head;
void Node::insertAtBegining(int x){
    Node *temp = new Node;
    temp->Data=x;
    temp->Next=Head;
    Head = temp;
}

void Node::insertAtEnd(int x){
    Node *temp = new Node;
    Node *temp1=Head;
    temp->Data = x;
    if(Head == NULL){
        Head=temp;
        temp->Next = NULL;
    }
    else{
        while(temp1->Next!=NULL){
            temp1 = temp1->Next;
        }
        temp1->Next = temp;
        temp->Next = NULL;
    }
    
}

void Node::print(){
    Node *temp1=Head;
    cout<<"The list is : ";
    while(temp1 != NULL){
        cout<<temp1->Data<<" ";
        temp1=temp1->Next;
    }
}

int main()
{
    int size,value;
    Head = NULL;
    Node list;
    cout<<"Enter how many number you insert in linked list : ";
    cin>>size;
     
    for(int i=0;i<size;i++){
        cout<<"Enter the value : ";
        cin>>value;
        list.insertAtBegining(value);
        list.insertAtEnd(value);
        list.print();
        cout<<endl;
    }
    
    return 0;
}
