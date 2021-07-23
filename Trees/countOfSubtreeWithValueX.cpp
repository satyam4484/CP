//SATYAM SINGH  
// problem link  -- > https://www.geeksforgeeks.org/count-subtress-sum-given-value-x/
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

int countsubtree(node*root,int target,int &count) {
	// base case
	if(root == nullptr) return 0;
	int left = countsubtree(root->left,target,count);
	int right =countsubtree(root->right,target,count);
	if(left == target) count++;
	if(right == target) count++;
	return root->data+left+right;

}
int main( ) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    node*root = insert(5);
    root->left = insert(-10);
    root->right = insert(3);
    root->right->right = insert(7);
    root->right->left = insert(-4);
    root->left->left = insert(9);
    root->left->right = insert(8);
    // inorder(root);
    int count = 0;
    countsubtree(root,7,count);
    cout<<count<<endl;
     

    // code ends here !!!!!! 
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*100<<" seconds";
    #endif 
    return 0;
}