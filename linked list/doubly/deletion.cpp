#include<iostream>
using namespace std;

struct Node
{
    int data;   // a data 
    struct Node*next;  //a ptr to next 
    struct Node*prev; // a ptr to previous 
};
struct Node*head=NULL,*tail=NULL,*newnode;

// 1:Delete front node 
void delete_a_fr(){
    struct Node*temp=head; //create a ptr to point 
    head=temp->next;  // move head 
    free(temp);  // delete the space taken by first data 
}

// 2:Delete last element 
void delete_a_end(){
    struct Node*temp=tail;
    tail=temp->prev; //move tail to previous node 
    tail->next=NULL; // put previous value of next to null 
    free(temp);// free the memory 
}


// 3:Delete node at position 
void Delete_a_pos(){
    struct Node*nextnode,*temp=head;
    int p;
    cout<<"Enter the position which u want to delete : ";
    cin>>p;
    while (p!=1)
    {
        nextnode=temp; //previous node which of deletion 
        temp=temp->next;
        p--;
    }
    nextnode->next=temp->next; // assign previous node to temp next 
    temp->next->prev=nextnode; //and the temp next prev should store prev node 
    free(temp); // free the memory 
}

// 4:Reverse the doubly linked list 
void reversel(){
    struct Node*temp=head,*prevnode;
    while (temp!=NULL)
    {
        prevnode=temp->next;
        temp->next=temp->prev;
        temp->prev=prevnode;
        temp=prevnode;
    }
    prevnode=head;
    head=tail;
    tail=prevnode;
}
// 5:Delete a given data 
void Delete_a_data(){
    struct Node*temp=head,*prevnode;
    int d;
    cout<<"Enter the data which u want to delete : ";
    cin>>d;
    while (temp->data!=d)
    {
        prevnode=temp;
        temp=temp->next;
    }
    prevnode->next=temp->next; // assign previous node to temp next 
    temp->next->prev=prevnode; //and the temp next prev should store prev node 
    free(temp);  // free the memory 
}