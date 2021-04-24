// Linked list
#include <iostream>
using namespace std;
                          //    head         ______NODE 1______     ______NODE 2_____
// a node of linked list -->   |100| ---->  |_data___|__next__|--->|__Data__|__next__|--->continue  
//  creating a node  adress of nodes                100                     200                     
struct Node
{
    int data;
    struct Node *next; // pointer to addres of next node 
};

// creating a head pointer to the node 
// a head and a temp to traverse the linked list 
struct Node *head = NULL, *temp;
void insert()
{  
    struct Node *newnode;      
    // dynamically alloting the memory using malloc 
    newnode = (struct Node *)malloc(sizeof(struct Node));
    cout << "Enter the Data  : ";
    cin >> newnode->data;
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
        temp = newnode;
    }
    else
    {
        temp->next = newnode;
        temp = newnode;
    }
}
// Display the linked list 
void display()
{
    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    int ch;
    do
    { 
        insert(); //calling the insert function 
        cout<<"Enter 1 to continue and 0 to stop : ";
        cin>>ch;
    } while (ch);
    cout<<"The linked list elements are : ";
    display();
    return 0;
}
