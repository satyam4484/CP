// problem link --> https://www.hackerrank.com/challenges/dijkstrashortreach/problem?isFullScreen=false
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

void Dijiktra(vector<pair<int,int>>adj[],int n,int &src){
	vector<int>dist(n+1,INT_MAX);
	dist[src] = 0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	pq.push({0,src});
	while(pq.size() > 0) {
		int d = pq.top().first;
		int u = pq.top().second;
		pq.pop();
		if(dist[u] < d) continue;
		for(auto neigh:adj[u]) {
			int v = neigh.first;
			int w = neigh.second;
			if(dist[v] > w+d) {
				dist[v] = w + d;
				pq.push({dist[v],v});
			}
		}
	}

	for(int i=1;i<=n;i++) {
		if(i == src) continue;
		if(dist[i] == INT_MAX) cout<<-1<<" ";
		else cout<<dist[i]<<" ";
	}
	cout<<endl;

}

void Main() {
	int t;
	cin>>t;
	while(t--) {
		int n,m;
		cin>>n>>m;
		vector<pair<int,int>>v[n+1];
		for(int i=0;i<m;i++){
			int a,b,c;
			cin>>a>>b>>c;
			v[a].push_back({b,c});
			v[b].push_back({a,c});
		}
		int src;
		cin>>src;

		Dijiktra(v,n,src);

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