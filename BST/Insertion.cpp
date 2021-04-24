#include<iostream>
using namespace std;

//structure of tree 
struct node{
    int data;
    struct node*left,*right;
};

//creation of tree 
struct node*newnode(int data){
    struct node*root;
    root=(struct node*)malloc(sizeof(struct node));
    root->data=data;
    root->left=root->right=NULL;
    return root;
}

//insertion in BST tree function 
struct node* inser(struct node*root,int val){

    // when we get the first null value enter the data here 
    if(root==NULL){
        return newnode(val);
    }

    // check condtion for greater value 
    if(root->data<val){
        root->right=inser(root->right,val);
    }

    // else move to lower value 
    else
    {
        root->left=inser(root->left,val);
    }

    //return the newnly formed root 
    return root;
}

// Traversal of BSt tree in inorder 
void inorder(struct node*root){
    if(root==NULL){
        return ;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

// main function 
int main(){
    struct node*root;

    // root of tree 
    root=newnode(20);

    //left subtree
    root->left=newnode(16);
    root->left->left=newnode(5);
    root->left->right=newnode(18);
    root->left->right->left=newnode(17);
    root->left->right->right=newnode(19);

    //right subtree
    root->right=newnode(60);
    root->right->right=newnode(85);
    root->right->left=newnode(70);


    /* The inorder traversal would look like : 
            5,16,17,18,19,20,70,60,85
    */

    // element to be inserted in BST 
    cout<<"Enter the value which u want to insert : ";
    int val;
    cin>>val;

    // store the new root value in same root 
    root=inser(root,val);
    inorder(root);

    // suppose inserting 10

    /* The inorder traversal would look like : 
            5, 10 ,16,17,18,19,20,70,60,85
    */

    return 0;
}