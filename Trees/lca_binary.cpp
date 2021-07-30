//SATYAM SINGH  
// problem --> Lowest common ancestor in binary tree    
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

node*lca(node*root,int a,int b,bool &av,bool &bv) {
    if(root == nullptr ) return nullptr;
    if(root->data == a) {
        av = true;
        return root;
    }
    if(root->data == b) {
        bv = true;
        return root;
    }
    node*left = lca(root->left,a,b,av,bv);
    node*right = lca(root->right,a,b,av,bv);

    if(left and right) return root;
    return left ?left:right;
}
bool findv(node*root,int a) {
    if(not root) return false;
    if(root->data == a or findv(root->left,a) or findv(root->right,a)) return true;
    return false;
}
int findLca(node*root,int a,int b) {
    bool  v1=false,v2 = false;
    node*lcad = lca(root,a,b,v1,v2);
    if((v1 and v2) or (v1 and findv(lcad,b) ) or (v2 and findv(lcad,a))) return lcad->data;

    return -1;
}
int main( ) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    node *root = insert(1);
    root->left = insert(2);
    root->left->left= insert(4);
    root->left->right= insert(5);
    root->right = insert(3);
    root->right->left = insert(6);
    root->right->right = insert(7);

    int t;
    cin>>t;
    while(t--) {
        int a,b;
        cin>>a>>b;
        cout<<findLca(root,a,b)<<endl;
    }


    // code ends here !!!!!! 
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*100<<" seconds";
    #endif 
    return 0;
}