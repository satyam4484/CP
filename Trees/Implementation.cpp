//Binary tree
#include<iostream>
using namespace std;

// structure of tree 
struct Node
{
    int data;
    struct Node*left_node,*right_node;
};

//function that will return the addres of root node 
struct Node *create(){
    int x;
    struct Node*newnode;
    newnode=(struct Node*)malloc(sizeof(struct Node));
    cout<<"Enter -1 for no node else anything for Node : ";
    cin>>x;
    cout<<endl;
    //if dont want to insert more trees then it will stop and return null to that node 
    if(x==-1){
        return 0;
    }

    //else put that data to newnode which will be created 
    newnode->data=x;

    //enter the left child by recusively calling the function 
    cout<<"Enter left child of "<<x<<endl;
    newnode->left_node=create();

    //enter the right child after the left child has been enterd 
    cout<<"Enter right child of "<<x<<endl;
    newnode->right_node=create();

    //return the address of root node to main function 
    return newnode;
}

//traversing the binary tree using inorder traversal 
// Left--Root--Right 
void Inorder(struct Node*root){
    // base condition to stop recusrsion 
    if(root==NULL){
        return ;
    }

    //moving towrds the left most child 
    Inorder(root->left_node);
    // after base conditon return it will print the left child data 
    cout<<root->data<<" ";
    // move to right childe and do the same 
    Inorder(root->right_node);
}

//traversing the binary tree using preorder traversal
// Root--Left--Right
void Preorder(struct Node*root){

    //base condtition to stop recursion 
    if(root==NULL){
        return ;
    }
    //now in preorder print the root first 
    cout<<root->data<<" ";

    //after that moves towrds left child and that will become the root ,so it continues 
    // call again the preorder function
    Preorder(root->left_node);  //provided the left address of root node 

    // after left node we will move towards the right node and will print the data of right node 
    Preorder(root->right_node);
}

// Traversing the binary tree using postorder traversal
// Left--Right--Root 
void Postorder(struct Node*root){
    //base condtition to stop recursion 
    if(root==NULL){
        return ;
    }

    //first we will move toward the left most child 
    Postorder(root->left_node);
    //then we will move towards the right most child
    Postorder(root->right_node);
    //then we will print the data of 
    cout<<root->data<<" ";
}

int main(){
    struct Node*root;
    root=create(); // storing the address return by the create function

    cout<<endl<<"How do you want to traverse the tree "<<endl;
    cout<<"1:Inorder traversal "<<endl;
    cout<<"2:Preorder"<<endl;
    cout<<"3:Postorder"<<endl;
    int c;
    cout<<"Enter your choice : ";
    cin>>c;

    // call one by one all fucntion 
    switch (c)
    {
    case 1:cout<<"Your tree in Inorder is "<<endl;
        Inorder(root);
        break;
    case 2:cout<<"Your tree in  Preorder is "<<endl;
        Preorder(root);
        break;
    case 3:cout<<"Your tree in Postorder is "<<endl;
        Postorder(root);
        break;
    default:
        break;
    }


    /* to print alll the trees create a temp_root variable in each function 
        and then traverse for each function and it will print all the 
        traversal order .
    */
    return 0;
}