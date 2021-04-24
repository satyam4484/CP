#include <iostream>
using namespace std;

// structrure of node
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL, *temp,*newnode;

// insert the elements in linked list
void insert( )
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

//Delete at the beginning 
void delete_a_beg(){
    temp=head;
    head=temp->next;
    free(temp);
}
//Delete at the end 
void delete_a_end(){
    temp=head;
    struct Node *newt;
    while (temp->next!=NULL)
    {
        newt=temp;
        temp=temp->next;
    }
    newt->next=NULL;
    free(temp);
}

// delete after a given position 
void delete_a_pos(){
    struct Node *newt;
    temp=head;
    int pos;
    cout<<"Enter the position  which u want to delete : ";
    cin>>pos;
    int i=1;
    while (i<pos)
    {
        newt=temp;
        temp=temp->next;
        i++;
    }
    newt->next=temp->next;
    free(temp);
}

// delete the given node data 
void delete_a_data(){
    int x;
    cout<<"Enter the data which u want to delete : ";
    cin>>x;
    temp=head;
    struct Node *newt;
    while (temp->data!=x)
    {
        newt=temp;
        temp=temp->next;
    }
    newt->next=temp->next;
     free(temp); 
}

// main function 
int main()
{
    insert();
    insert();
    insert();
    insert();
    insert();
    int ch;
    do
    {
        cout << "1:Delete at the beginning " << endl;
        cout << "2:Delete at the end " << endl;
        cout << "3:Delete the given position" << endl;
        cout << "4:Delete a data  " << endl;
        cout << "5:Display the linked list " << endl;
        cout << "Enter the choice : ";
        int c;
        cin >> c;
        cout << endl;
        switch (c)
        {
        case 1:
            delete_a_beg();
            break;
        case 2:
            delete_a_end();
            break;
        case 3:
            delete_a_pos();
            break;
        case 4:
            delete_a_data();
            break;
        case 5:
            display();
        default:
            break;
        }
        cout << "To continue 1 and exit 0  :  ";
        cin >> ch;
    } while (ch);

    return 0;
}