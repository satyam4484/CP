// problem link -- >https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
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

// =============================================================================================================================================================

class node{
public:
    node*left,*right;
};

// left for zero right for 1
class Trie {
public:
    node*root;
    Trie() {
        root= new node();
    }

    void insert(int data) {
        node*temp = root;
        for(int i=31;i>=0;i--) {
            int bit = (data >>i) &1;
            if(bit == 0) {
                if(not temp->left) {
                    temp->left = new node();
                }
                temp=temp->left;
            } else {
                if(not temp->right) {
                    temp->right = new node();
                }
                temp = temp->right;
            }
        }
    }
    int maxxor(int data) {
        int ans= 0;
        node*temp=root;
        for(int i=31;i>=0;i--) {
            int bit=(data>>i)&1;
            if(bit == 0) {
                if(temp->right) {
                    ans += (1<<i);
                    temp=temp->right;   
                } else {
                    temp =  temp->left;
                }
            } else {
                if(temp->left) {
                    ans+=(1<<i);
                    temp = temp->left;
                } else {
                    temp = temp->right;
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie *trie = new Trie();
        for(auto i:nums) {
            trie->insert(i);
            break;
        }
        int ans = 0;
        for(auto i:nums) {
            int newans = trie->maxxor(i);
            ans = max(ans,newans);
        }
        return ans;
    }
};
void Main() {
    vector<int>v{2,4};
    Solution s;
    cout<<s.findMaximumXOR(v);
    
}


// ============================================================================================================================
int main( ) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    
     Main();

    // code ends here !!!!!! 
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*100<<" seconds";
    #endif 
    return 0;
}