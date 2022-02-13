// problem link --> https://www.hackerrank.com/challenges/torque-and-development/problem
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

void dfs(int src,vector<bool>&visited,vector<int>adj[],int &city) {
	city++;
	visited[src] = true;
	for(auto neighbour:adj[src]){
		if(not visited[neighbour]) {
			dfs(neighbour,visited,adj,city);
		}
	}
}
void Main() {
	int q;
	cin>>q;
	while(q--) {
		int n,m,lib,road;
		cin>>n>>m>>lib>>road;
		vector<int>v[n+1];
		for(int i=0;i<m;i++) {
			int a,b;
			cin>>a>>b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		long long int ans = 0;
		vector<bool>visited(n+1,false);
		for(int i=1;i<=n;i++) {
			if(not visited[i]) {
				int city = 0;
				dfs(i,visited,v,city);
				if(lib > road) {
					ans+=lib + (city-1)*road;
				}else{
					ans+=lib*city;
				}
			}
		}
		cout<<ans<<endl;
	}
	

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