//SATYAM SINGH  
// problem link --> https://codeforces.com/problemset/problem/1263/D
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll 				long long int
#define pb 				push_back
#define mod             1000000007
#define inf             1e18
#define ump				unordered_map
#define mp 				make_pair

#define  inpv(v,n)  for(int i=0;i<n;i++) cin>>v[i]
#define  outv(v)    for(auto i:v) cout<<i<<' ' 
#define  loop(i,a,b)  for(int i=(a);i<(b);i++)
#define  looprev(i,a,b)  for(int i=(a);i>=0;i--)

void file_i_o()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}
int Get(vector<int>&parent,int a) {
    return parent[a] = (parent[a] == a ?a:Get(parent,parent[a]));
}
void Union(vector<int>&parent,vector<int>&rank,int a,int b) {
    a = Get(parent,a);
    b = Get(parent,b);
    if(rank[a] == rank[b]) rank[a]++;
    if(rank[a] > rank[b]) parent[b] = a;
    else parent[a] = b;
}

int main( ) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    int n;
    cin>>n;
    vector<int>parent(27);
    loop(i,0,27) parent[i] = i;
    vector<int>rank(26,1);
    vector<bool>total(26,false);
    loop(j,0,n) {
        string s;
        cin>>s;
        vector<bool>curr(26,false);
        loop(i,0,s.size()) {
            curr[s[i]-'a'] = true;
            
        }
        
        loop(i,0,26){
            if(curr[i] == true ) {
                total[i] = true;
                Union(parent,rank,s[0]-'a',i);
            }
        }
    }
    ll count =0;
    loop(i,0,26) {
        if(total[i] and Get(parent,i) == i) count++;
    }
    cout<<count<<endl;

    // code ends here !!!!!! 
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC<<" seconds";
    #endif 
    return 0;
}
