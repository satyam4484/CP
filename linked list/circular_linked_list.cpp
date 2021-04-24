// circular linked list 
#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};
//using only one pointer that is tail 
struct Node *tail=NULL,*newnode,*temp;

//function to create a circular linked list 
void create(){
    newnode=(struct Node*)malloc(sizeof(struct Node));
    cout<<"Enter the data : ";
    cin>>newnode->data;
    newnode->next=NULL;
    // if tail is null initially 
    if(tail==NULL){
        //point the tail 
        tail=newnode;
        //point the next to head 
        tail->next=newnode;
    }
    //update the newnode next to head and then move the tail 
    else
    {
        //newnode points to head 
        newnode->next=tail->next;
        // tail pointer points to newnode
        tail->next=newnode;
        //move the tail to newnode 
        tail=newnode;
    }  
}

//display 
void display(){
    // struct Node *temp=tail->next;
    temp=tail->next;
    while (temp!=tail)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data;
}

int main(){
    for (int i = 0; i < 5 ; i++)
    {
        create();
    }
    display();
    
    return 0;
}