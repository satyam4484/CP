// if any idea how o solve that problem 
// check binary tree is a heap or not (works for complete binary tree and for max heap )
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Tree
{
    int data;
    Tree *left, *right;
};
Tree *newnode(int data)
{
    Tree *node = new Tree();
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
void level_order(Tree *root)
{
    queue<Tree *> Q;
    Q.push(root);
    while (!Q.empty())
    {
        Tree *current = Q.front();
        cout << current->data << " ";
        if (current->left != NULL)
        {
            Q.push(current->left);
        }
        if (current->right != NULL)
        {
            Q.push(current->right);
        }
        Q.pop();
    }
}
void is_heap(vector<int> &v)
{
    int f = 0;
    for (int i = 0; i < v.size() / 2; i++)
    {
        if (v[i] > v[2 * i + 1] && v[i] > v[2 * i + 2]){f = 1;}
        else
        {
            f = 0;
            break;
        }
    }
    if (f == 1)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}
void getarray(vector<int> &v, Tree *root)
{
    queue<Tree *> qq;
    qq.push(root);
    while (qq.empty() == false)
    {
        int n = qq.size();
        for (int i = 0; i < n; i++)
        {
            Tree *curr = qq.front();
            v.push_back(curr->data);
            if (curr->left != NULL)
            {
                qq.push(curr->left);
            }
            if (curr->right != NULL)
            {
                qq.push(curr->right);
            }
            qq.pop();
        }
    }
}
int main()
{
    Tree *root = NULL;
    root = newnode(97);
    root->left = newnode(46);
    root->left->left = newnode(12);
    root->left->right = newnode(3);
    root->left->left->left = newnode(6);
    root->left->left->right = newnode(9);

    root->right = newnode(37);
    root->right->left = newnode(7);
    root->right->right = newnode(31);
    // level order --> 97 46 37 12 3 7 31 6 9
    vector<int> v;
    getarray(v, root);
    for (auto i : v)
    {
        cout << i << " ";
    }
    is_heap(v);
    return 0;
}