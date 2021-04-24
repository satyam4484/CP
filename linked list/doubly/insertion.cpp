#include<iostream>
using namespace std;

struct Node
{
    int data;   // a data 
    struct Node*next;  //a ptr to next 
    struct Node*prev; // a ptr to previous 
};
struct Node*head=NULL,*tail=NULL,*newnode;
// struct Node*newnode(int data)
// {
//     struct Node*node=(struct Node*)malloc(sizeof(struct Node));
//     node->data=data;
//     node->next=NULL;
//     node->prev=tail;
//     tail=node;
// }
// 1:Insert at beginning 

void insert_a_begin()
{
    newnode = (struct Node *)malloc(sizeof(struct Node));
    cout << "\nEnter the data to be inserted : ";
    cin >> newnode->data;
    newnode->prev = NULL; // initialize the previous to null
    newnode->next = head; // assign newnode next to head value
    head->prev = newnode; //assign head previous to newnode
    head = newnode;       //point head to new node
}


// 2:Insert at end 
void insert_a_end()
{
    newnode = (struct Node *)malloc(sizeof(struct Node));
    cout << "\nEnter the data to be inserted at the end : ";
    cin >> newnode->data;
    newnode->next = NULL; //initialisze next to null
    newnode->prev = tail; // connect previous to previous node
    tail->next = newnode; //connect tail next to newnode
    tail = newnode;       //move tail to new node
}

// 3:Insert after a position 

void insert_a_pos(){
    struct Node *temp=head;
    newnode=(struct Node*)malloc(sizeof(struct Node));
    int p;
    cout<<"\nEnter the position after which u want to insert : ";
    cin>>p;
    cout<<"Enter the data to be inserted : ";
    cin>>newnode->data;
    p=p-1;
    while (p--) //traverse before the positon 
    {
        temp=temp->next; //use temp to traverse 
    }

    newnode->next=temp->next; //connect node next to temp next
    temp->next->prev=newnode; // initialize temp to newnode
    newnode->prev=temp; //connect prev of newnode to temp
    temp->next=newnode;  //connect temp next to newnode 
}
// 4:Insert after a given data 

void insert_a_data(){
    newnode=(struct Node*)malloc(sizeof(struct Node ));
    int da;
    cout<<"\nEnter the data after which u want to insert : ";
    cin>>da;
    cout<<"Enter the data which u want to insert : ";
    cin>>newnode->data;
    struct Node*temp=head;
    while(temp->data==da){
        temp=temp->next;
    }
    temp=temp->next; // when get the move on step again 
    newnode->next=temp->next; //connect node next to temp next
    temp->next->prev=newnode; // initialize temp to newnode
    newnode->prev=temp; //connect prev of newnode to temp
    temp->next=newnode;  //connect temp next to newnode 
    
}

int main()
{
    // struct Node*
}