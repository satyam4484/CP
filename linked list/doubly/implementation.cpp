#include<iostream>
using namespace std;

struct Node
{
    int data;   // a data 
    struct Node*next;  //a ptr to next 
    struct Node*prev; // a ptr to previous 
};

// head ptr for first  element ,tail ptr to last element 
struct Node *head=NULL,*tail,*newnode;
void create(){
    newnode=(struct Node*)malloc(sizeof(struct Node));
    cout<<"Enter the data : ";
    cin>>newnode->data;
    newnode->next=NULL;
    newnode->prev;
    if(head==NULL){
        head=newnode;
        tail=newnode;
    }
    else
    {
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }  
}

void display(){
    // a new pointer to traverse the linked list 
    struct Node*temp;
    // method 1 : print from head 
    temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    
    // method 2: print from tail 
    temp=tail;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->prev;
    }  
}

int main(){
    create();
    create();
    create();
    create();
    create();
    display();
    return 0;
}