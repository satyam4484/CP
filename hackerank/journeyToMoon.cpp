// problem link --> https://www.hackerrank.com/challenges/journey-to-the-moon/problem?isFullScreen=true
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

void dfs(int src,vector<int>adj[],vector<bool>&visited,int &count ) {
	count++;
	visited[src] = true;
	for(auto neighbour:adj[src]) {
		if(not visited[neighbour]) {
			dfs(neighbour,adj,visited,count);
		}
	}
}

void Main() {
	int n,m;
	cin>>n>>m;
	vector<int>v[n];
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	vector<bool>visited(n,false);
	vector<int>comp;
	for(int i=0;i<n;i++){
		if(not visited[i]) {
			int count = 0;
			
			dfs(i,v,visited,count);
			comp.push_back(count);
		}
	}
	vector<int>pre(comp.size(),0);
	pre[0] = comp[0];
	for(int i=1;i<comp.size();i++) {
		pre[i]+=pre[i-1]+comp[i];
	}

	long long int ans = 0;
	for(int i=0;i<comp.size();i++) {
		ans+=(pre[comp.size()-1]-pre[i])*comp[i];
	}
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