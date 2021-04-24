#include <iostream>
using namespace std;

// structrure of node 
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL, *temp, *newnode;

// insert the elements in linked list
void insert()
{
    newnode = (struct Node *)malloc(sizeof(struct Node));
    cout << "Enter the data : ";
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
// display the linked list
void display()
{
    cout << "The linked list is  :  ";
    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Insert a node at beginning of linked list
void Insert_a_beg()
{
    newnode = (struct Node *)malloc(sizeof(struct Node));
    cout << "Enter the data to insert : ";
    cin >> newnode->data;
    newnode->next = head;
    head = newnode;
}
// Insert at the end of linked list
void insert_a_end()
{
    newnode = (struct Node *)malloc(sizeof(struct Node));
    cout << "Enter the element want to insert at end : ";
    cin >> newnode->data;
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = NULL;
}

// insert at a positon
void insert_a_pos()
{
    int pos;
    cout << "Enter the position after which u want to insert : ";
    cin >> pos;

    temp = head;
    newnode = (struct Node *)malloc(sizeof(struct Node));
    cout << "Enter the element to insert : ";
    cin >> newnode->data;
    int i = 1;
    while (i < pos)
    {
        temp = temp->next;
        i++;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

// insert after a given data  
void inser_at_node(){
    int n;
    cout<<"enter the  data after which u want to insert : ";
    cin>>n;
    temp=head;
    newnode = (struct Node *)malloc(sizeof(struct Node));
    cout<<"Enter the data which u want to insert : ";
    cin>>newnode->data;
    while (temp->data!=n)
    {
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}

// main function 
int main()
{
    int ch;
    do
    {
        cout << "\n1:Insert the elements in linked list " << endl;
        cout << "2:Insert at the beginning " << endl;
        cout << "3:Insert at the end " << endl;
        cout << "4:Insert after a given position" << endl;
        cout << "5:insert after a node " << endl;
        cout << "6:Display the linked list " << endl;
        cout << "Enter the choice : ";
        int c;
        cin >> c;
        cout << endl;
        switch (c)
        {
        case 1:
            insert();
            break;
        case 2:
            Insert_a_beg();
            break;
        case 3:
            insert_a_end();
            break;
        case 4:
            insert_a_pos();
            break;
        case 5:
            inser_at_node();
            break;
        case 6:
            display();
        default:
            break;
        }
        cout << "To continue 1 and exit 0  :  ";
        cin >> ch;
    } while (ch);

    return 0;
}