#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll                 long long int
#define pb                 push_back
#define mod             1000000007
#define inf             1e18
#define ump                unordered_map
#define mp                 make_pair

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

bool dfs(int src,int parent,vector<int>&visited,vector<int>adj[]) {
    visited[src] = 1;
    for(auto i:adj[src]) {
        if(not visited[i]) {
            if(dfs(i,src,visited,adj)) return true;
        }else if(i!=parent) return true;
    }
    return false;
}

bool isCycle(int v,vector<int>adj[]) {
    vector<int>visited(v,0);

    for(int i=0;i<v;i++) {
        if(not visited[i]) {
            if(dfs(i,-1,visited,adj)) return true;
        }
    }
    return false;
}

void Main() {
    int n,m;
    cin>>n>>m;
    vector<int>v[n];
    for(int i=0;i<m;i++) {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    cout<<isCycle(n,v)<<endl;
}

int main( ) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    Main();

    // code ends here !!!!!! 
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC<<" seconds";
    #endif 
    return 0;
}