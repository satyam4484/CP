// problem link --> https://www.hackerrank.com/challenges/primsmstsub?isFullScreen=true
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

void PrimsAlgo(int &st,vector<pair<int,int>>adj[],int n) {
	vector<bool>visited(n+1,false);
	vector<int>val(n+1,INT_MAX);
	val[st]  = 0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	pq.push({0,st});

	while(pq.size() > 0){
		int u = pq.top().second;
		pq.pop();
		visited[u] = true;
		for(auto neigh:adj[u]) {
			int v = neigh.first;
			int d = neigh.second;
			if(not visited[v] and val[v] > d) {
				val[v] = d;
				
				pq.push({val[v],v});
			}
		}
	}
	int ans = 0;
	for(int i=1;i<=n;i++) {
		ans+=val[i];
	}
	cout<<ans<<endl;
}

void Main() {
	int n,m;
	cin>>n>>m;
	vector<pair<int,int>>adj[n+1];
	for(int i=0;i<m;i++) {
		int a,b,c;
		cin>>a>>b>>c;
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});
	}

	int st;
	cin>>st;
	PrimsAlgo(st,adj,n);
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