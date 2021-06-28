//SATYAM SINGH  

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


// printing a tree in vertical order 

struct node {
    int data;
    node *left,*right ;
};

node *newnode(int data ) {
    node *newdata= new node();
    newdata->data = data;
    newdata->left = nullptr;
    newdata->right = nullptr;
    return newdata;
}

void inorder(node*root) {
    if(root) {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

void solve(node*root,int lv,int axis,map<int,map<int,vector<int>>>&hashmap) {
    if(root) {
        hashmap[axis][lv].push_back(root->data);
        solve(root->left,lv+1,axis-1,hashmap);
        solve(root->right,lv+1,axis+1,hashmap);
    }
}

void print_vertical_view(node*root) {
    map<int,map<int,vector<int>>>hashmap;
    solve(root,0,0,hashmap);

    for(auto i:hashmap) {
        for(auto j:i.second){
            for(auto k:j.second) {
                cout<<k<<" ";
            }
        }
        cout<<endl; 
    }
}


int main( ) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    node *root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);

    root->left->left = newnode(4);
    root->left->right = newnode(5);

    root->right->left = newnode(6);
    root->right->right = newnode(7);

    root->right->right->left = newnode(8);
    root->right->right->right = newnode(9);

    print_vertical_view(root);
     

    // code ends here !!!!!! 
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*100<<" seconds";
    #endif 
    return 0;
}