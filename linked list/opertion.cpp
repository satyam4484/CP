#include <iostream>
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};
// Function to reverse the linked list 
struct Node*head=NULL,*temp;

void Reverse()
{
    //create three nodes to reverse the linked list 
    struct Node *nextnode, *currentnode, *previousnode;
    previousnode = NULL; //first node will point to null 
    nextnode = currentnode = head; //next two nodes will point to head pointer 

    while (nextnode != NULL)
    {
        nextnode = nextnode->next;
        currentnode->next = previousnode;
        previousnode = currentnode;
        currentnode = nextnode;
    }
    head = previousnode; //atlasr put head pointer to last pointer 
}

// Search element in linked list 

void searche()
{
    int x, c = 0;
    cout << "Enter the element to be searched : ";
    cin >> x;
    temp = head;
    while (temp != NULL)
    {
        if (x == temp->data)
        {
            c = 1;
            cout << "Element found " << endl;
            break;
        }
        temp = temp->next;
    }
    if (c == 0)
    {
        cout << "Element not found " << endl;
    }
}
// Getting nth node in a linked list 

void getnode(){
    int x;
    cout<<"Enter the node number which u want to get : ";
    cin>>x;
    temp=head;
    int i=0;
    while (i<x)
    {
        temp=temp->next;
        i++;
    }
    cout<<"The node is : "<<temp->data<<endl;
}
// Getting middle element of linked list 
void middle(){
    temp=head;
    int i=0;
    /*while (i<count/2)
    {
        temp=temp->next;
        i++;
    }
    */
    cout<<"The middle element of linked list is : "<<temp->data<<endl;
}

// Check whether linked list is palindrome or not 
bool checkpalindrome(){
    temp=head;
    stack<char>st;
    while(temp!=NULL){
        st.push(temp->data);
        temp=temp->next;
    }
    while (head!=NULL)
    {
        char i=st.top();
        st.pop();
        if(head->data!=i){
            return false;
        }
        head=head->next;
    }
    return true ;
}
// Count the occurance of given word 
void count_el(){
    int x,c=0;
    cout<<"Enter the element whose occurance you want to count : ";
    cin>>x;
    temp=head;
    while (temp!=NULL)
    {
        if(temp->data==x){
            c++;
        }
        temp=temp->next;
    }
    cout<<"The element ' "<<x<<" ' is repeated "<<c<<" times ."<<endl; 
}
