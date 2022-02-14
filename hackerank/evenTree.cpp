// problem link --> https://www.hackerrank.com/challenges/even-tree/problem
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

int dfs(int src,vector<bool>&visited,vector<int>adj[],int &ans){
	visited[src] = true;
	int vertex = 0;
	for(auto neigh:adj[src]){
		if(not visited[neigh]) {
			int currv = dfs(neigh,visited,adj,ans);
			if(currv%2 == 0) ans++;
			else vertex+=currv;
		}
	}
	return vertex + 1;
}

void Main() {
	int n,m;
	cin>>n>>m;
	vector<int>adj[n+1];
	for(int i=0;i<m;i++) {
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<bool>visited(n+1,false);
	int ans = 0;
	dfs(1,visited,adj,ans);
	cout<<ans<<endl;


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