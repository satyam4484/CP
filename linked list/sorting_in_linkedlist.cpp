// Sorting of linked list
#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

// create the node 
struct node *newnode(int data)
{
    struct node *c;
    c = (struct node *)malloc(sizeof(struct node));
    c->data = data;
    c->next = NULL;
    return c;
}

// Insertion sort
void selection_sort(struct node *head)
{
    struct node *pre, *m;

    // it will run upto last node
    while (head->next != NULL)
    {
        // store the address of first node
        m = head;
        // move the pre pointer to second node for comparison
        pre = head->next;
        // loop till pre node becomes null that is last element
        while (pre != NULL)
        {
            //compare data of nodes
            if (pre->data < m->data)
            {
                //store the address of that node if condition satisfies
                m = pre;
            }
            // move the pointer
            pre = pre->next;
        }
        // swap the largest element with smallest element if exists
        swap(m->data, head->data);
        // move the head pointer
        head = head->next;
    }
}

// Bubble sort
void Bubble_sort(struct node *head)
{
    struct node *temp,*p,*q;
    for(temp=NULL;temp!=head->next;temp=q){
        for (p=head ; p->next!=temp; p=p->next)
        {
            q=p->next;
            if(p->data > q->data){
                swap(p->data,q->data);
            }
        }
    }
}


// insertion sort
void insertion_sort(struct node*head){
    struct node*temp,*q,*p,*t=head;
    for(p=head->next;p->next!=NULL;p=p->next){
        int k=p->data;
        q=head;
        while (q->data > k )
        {
            // q->next->data=
        }
        
    }
}

// function to display the linked list
void display(struct node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    struct node *head;

    /* 
        manually creation of linked list 
        4 --> 3 --> 2 --> 10 --> 12 --> 1 --> 5 -->NULL

    */
    head = newnode(4);
    head->next = newnode(3);
    head->next->next = newnode(2);
    head->next->next->next = newnode(10);
    head->next->next->next->next = newnode(12);
    head->next->next->next->next->next = newnode(1);
    head->next->next->next->next->next->next = newnode(5);

    // selection_sort(head);
    // Bubble_sort(head);

    display(head);
    return 0;
}