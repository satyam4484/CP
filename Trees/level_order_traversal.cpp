#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Tree{
    int data;
    Tree*left,*right;
};
Tree*newnode(int data){
    Tree*node=new Tree();
    node->data=data;
    node->left=node->right=NULL;
    return node;
}
void level_order(Tree*root){
    queue<Tree*>Q;
    Q.push(root);
    while(!Q.empty()){
        Tree*current=Q.front();
        cout<<current->data<<" ";
        if(current->left!=NULL) {Q.push(current->left);}
        if(current->right!=NULL){Q.push(current->right);}
        Q.pop();
    }
}

int main(){
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
    level_order(root);
    return 0;
}