#include<iostream>
#include<algorithm>
using namespace std;

// Tree structure
/*              1
               / \
              2   3
            /  \  / \
           4   5 6   7
               /\     / \
              8  9   10  11

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
/************ Approach 1 -> O(n^2)  *********/

// function to calculate the height of tree 
int height(Tree*root){
    if(root==NULL){return -1;}
    return max(height(root->left),height(root->right))+1;
}

// function to check whethe tree is balancd or not 
bool isbalanced(Tree*root){

    if(root==NULL){return true;}
    // calculate the height difference of my child 
    int h=abs(height(root->left)-height(root->right));

    // check whether my left child is balanced or not 
    bool left=isbalanced(root->left);

    // check whether my right child is balanced 
    bool right=isbalanced(root->right);

    // if absolute difference of height of child is less than 2 and the child nodes are also balanced then it is balanced 
    if(h<=1 && left && right ){return true;}
    return false;
}

/* Aprroach -2 
    We can optimise the approach by some how getting height its balance */

// these approach takes O(n) time complexicity 

// create a pair to store the height and whether it is balanced or not 
struct Paired{
    int height;
    bool balanced;
};

// now we will return the paired of root 
Paired treebalanced(Tree*root) {
    if(root==NULL) {
        Paired p= Paired();
        p.height=-1;
        p.balanced=true;
        return p;
    }
    // check for left subtree 
    Paired left=treebalanced(root->left);
    // check for right subtree 
    Paired right=treebalanced(root->right);

    // check for me
    Paired me=Paired();
    // height of myself 
    me.height=max(left.height,right.height)+1;
    // absolute difference of height of childrens 
    int h=abs(left.height-right.height);
    if(h<=1 && left.balanced && right.balanced){
        me.balanced=true;
    }
    else{me.balanced=false;}
    return me;
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
    // cout<<isbalanced(root);
    Paired p= Paired();
    p=treebalanced(root);
    cout<<p.balanced;
    return 0;
}