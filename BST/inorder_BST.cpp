#include<iostream>
#include<vector>
using namespace std;
struct node{
    int data;
    struct node*left,*right;
};
struct node*newnode(int data){
    struct node*newd;
    newd=(struct node*)malloc(sizeof(struct node));
    newd->data=data;
    newd->left=newd->right=NULL;
    return newd;
}


struct node *create_inorder(struct node*root,int val){
    static int i=0;
    if(root==NULL){
        return newnode(val);
    }
    if(root->data <val){
        root->right=create_inorder(root->right,val);
    }
    else
    {
        root->left=create_inorder(root->left,val);
    }
    return root;
}
void inorder(struct node*root){
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    struct node*root=NULL;
    vector<int>v{10,5,1,7,40,50};
    for (int i = 0; i < v.size(); i++)
    {
        root=create_inorder(root,v[i]);
    }
    inorder(root);
    return 0;
}