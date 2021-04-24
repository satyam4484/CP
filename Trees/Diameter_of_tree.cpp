#include<iostream>
#include<algorithm>
using namespace std;

// Tree structure
/*              1
               / \
              2   3
            /  \  / \
            4  5  6   7
               /\     / \
              8  9   10  11
                          \
                          12
                          / \
                        13   14
*/
// structure of tree 
struct Tree{
    int data;
    Tree*left,*right;
};
//function to add data to root 
Tree*newnode(int data){
    Tree*node=new Tree();
    node->data=data;
    node->left=node->right=NULL;
    return node;
}

// ****************************************\\
// Brute force approach ( O(n^2))

int height(Tree*root){
    if(root==NULL){return -1;}
    int lh=height(root->left);
    int rh=height(root->right);
    return max(lh,rh)+1;
}
int diameter(Tree*root){
    if(root==NULL){return 0;}
    int ld=diameter(root->left);
    int rd=diameter(root->right);
    int self=height(root->left)+height(root->right)+2;
    return max(ld,max(rd,self));
}

//************ optimized approach ( (O(n)) )
// we create a pair for storing diameter and height of each node 
struct paired{
    int diameter;
    int height;
};

paired Diameter(Tree*root){
    if(root==NULL){
        paired D=paired();
        D.diameter=0;
        D.height=-1;
        return D;
    }
    paired left=Diameter(root->left);
    paired right=Diameter(root->right);
    paired me=paired();
    me.height=max(left.height,right.height)+1;
    int ld=left.diameter;
    int rd=right.diameter;
    int self=left.height+right.height+2;
    me.diameter=max(self,max(ld,rd));
    return me;
}

///*************************///*******//

void inorder_traversal(Tree*root){
    if(root!=NULL){
        inorder_traversal(root->left);
        cout<<root->data<<" ";
        inorder_traversal(root->right);
    }
    // 4 2 8 5 9 1 6 3 10 7 11 13 12 14 
}
int main()
{
    Tree*root=NULL;
    root=newnode(1);
    root->left=newnode(2);
    root->left->left=newnode(4);
    root->left->right=newnode(5);
    root->left->right->left=newnode(8);
    root->left->right->right=newnode(9);

    root->right=newnode(3);
    root->right->left=newnode(6);
    root->right->right=newnode(7);
    root->right->right->left=newnode(10);
    root->right->right->right=newnode(11);
    root->right->right->right->right=newnode(12);
    root->right->right->right->right->left=newnode(13);
    root->right->right->right->right->right=newnode(14);

    // inorder_traversal(root);
    cout<<"Diameter of tree is : ";
    paired p;
    p=Diameter(root);
    cout<<p.diameter; // 8
    // cout<<height(root);
    return 0;
}