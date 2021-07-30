//SATYAM SINGH  
// problem --> Lowest common ancestor in binary search tree
// problem link --> https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1# 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll                 long long int
#define pb                 push_back
#define mod                     1000000007
#define inf                     1e18
#define ump                unordered_map
#define mp                 make_pair
#define all(v)                   v.begin(),v.end()

#define  inpv(v,n)  for(int i=0;i<n;i++) cin>>v[i]
#define  outv(v)    for(auto i:v) cout<<i<<' ' 
#define  loop(i,a,b)  for(int i=(a);i<(b);i++)
#define  looprev(i,a,b)  for(int i=(a);i>=0;i--)
#define log(args...)  {string _s = #args ;replace(_s.begin(),_s.end(),',',' ') ; stringstream _ss(_s); istream_iterator<string> _it(_ss) ; err(_it,args);}
void err(istream_iterator<string> it) {}
template<typename T,typename ... Args>
void err(istream_iterator<string> it, T a,Args... args) {
      cout<<*it<<" = "<<a<<endl;
   err(++it,args...);
}

void file_i_o()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

struct node {
	int data;
	node*left,*right;
};


node*insert(int data) {
	node*newnode = new node();
	newnode->data = data;
	newnode->left = newnode->right = nullptr;
	return newnode;
}

void inorder(node*root) {
	if(root) {
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}

// recursive method 


node* findlcaRecursive(node*root,int n1,int n2) {
    if(root == nullptr) return nullptr;
    if(root->data > n1 and root->data > n2) return findlcaRecursive(root->left,n1,n2);
    if(root->data < n1 and root->data < n2 ) return  findlcaRecursive(root->right,n1,n2);
    return root;
}

// iterative method 

node* findLcaIterative(node*root,int a,int b) {
    if(root == nullptr) return nullptr;

    while(root != nullptr) {
        if(root->data > a and root->data > b) root= root->left;
        else if(root->data < a and root->data < b) root = root->right;
        else break;
    }
    return root;
}


int main( ) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    node *root = insert(20);
    root->left=insert(8);
    root->left->right=insert(12);
    root->left->right->left=insert(10);
    root->left->right->right=insert(14);
    root->left->left=insert(4);
    root->right=insert(22);

    int t;
    cin>>t;
    while(t--) {
        int a,b;
        cin>>a>>b;
        cout<<findlcaRecursive(root,a,b)->data<<endl;
    }


    // code ends here !!!!!! 
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*100<<" seconds";
    #endif 
    return 0;
}